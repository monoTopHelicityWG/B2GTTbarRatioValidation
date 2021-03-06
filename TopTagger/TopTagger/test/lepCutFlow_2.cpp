#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "TFile.h"
#include "TChain.h"

#include "TTree.h"
#include "TLorentzVector.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "optionparser.h"


// ./topTaggerTest --input=b2gtreeV5_MC_MonoTop_rh_5.root --output=test.root -v

//manditory includes to use top tagger
#include "TopTagger/TopTagger/include/TopTagger.h"
#include "TopTagger/TopTagger/include/TopTaggerResults.h"
//this include is useful to get the helper function to make the vector of constituents
#include "TopTagger/TopTagger/include/TopTaggerUtilities.h"

//this include is necessary to handle exceptions thrown by the top tagger code
#include "TopTagger/CfgParser/include/TTException.h"

#include "rootdict.h"

struct Arg: public option::Arg
{
  static void printError(const char* msg1, const option::Option& opt, const char* msg2)
  {
    fprintf(stderr, "%s", msg1);
    fwrite(opt.name, opt.namelen, 1, stderr);
    fprintf(stderr, "%s", msg2);
  }

  static option::ArgStatus Unknown(const option::Option& option, bool msg)
  {
    if (msg) printError("Unknown option '", option, "'\n");
    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus Required(const option::Option& option, bool msg)
  {
    if (option.arg != 0)
      return option::ARG_OK;

    if (msg) printError("Option '", option, "' requires an argument\n");
    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus NonEmpty(const option::Option& option, bool msg)
  {
    if (option.arg != 0 && option.arg[0] != 0)
      return option::ARG_OK;

    if (msg) printError("Option '", option, "' requires a non-empty argument\n");
    return option::ARG_ILLEGAL;
  }

  static option::ArgStatus Numeric(const option::Option& option, bool msg)
  {
    char* endptr = 0;
    if (option.arg != 0 && strtol(option.arg, &endptr, 10)){};
    if (endptr != option.arg && *endptr == 0)
      return option::ARG_OK;

    if (msg) printError("Option '", option, "' requires a numeric argument\n");
    return option::ARG_ILLEGAL;
  }
};

enum  optionIndex { UNKNOWN, HELP, INPUT, OUTPUT, VERBOSE };
const option::Descriptor usage[] =
{
 {UNKNOWN, 0,"" , ""    ,option::Arg::None, "USAGE: example [options]\n\n"
                                            "Options:" },
 {HELP,    0,"" , "help",option::Arg::None, "  --help  \tPrint usage and exit." },
 {INPUT,    0,"i", "input",Arg::Required, "  --input, -i  \tInput file" },
 {OUTPUT,    0,"o", "output",Arg::Required, "  --output, -i  \tOutput file" },
 {VERBOSE,    0,"v", "verbose",Arg::None, "  --verbose, -v  \tVerbose output" },
 {UNKNOWN, 0,"" ,  ""   ,option::Arg::None, "\nExamples:\n"
                                            "  example --unknown -- --this_is_no_option\n"
                                            "  example -unk --plus -ppp file1 file2\n" },
 {0,0,0,0,0,0}
};



int main(int argc, char* argv[])
{

  argc-=(argc>0); argv+=(argc>0); // skip program name argv[0] if present
  option::Stats  stats(usage, argc, argv);
  option::Option options[stats.options_max], buffer[stats.buffer_max];
  option::Parser parse(usage, argc, argv, options, buffer);
  if (parse.error())
    return 1;
  if (options[HELP] || argc == 0) {
    option::printUsage(std::cout, usage);
    return 0;
  }

std::string inputFile = "b2gtreeV5_MC_MonoTop_RH_2TeV_had.root";
std::string outputFile;

bool verbose = false;

for (int i = 0; i < parse.optionsCount(); ++i)
  {
    option::Option& opt = buffer[i];
    fprintf(stdout, "Argument #%d is ", i);
    switch (opt.index())
    {
      case HELP:
        // not possible, because handled further above and exits the program
      case INPUT:
        if (opt.arg)
          fprintf(stdout, "--input '%s'\n", opt.arg);
          inputFile = opt.arg;
        break;
      case OUTPUT:
        fprintf(stdout, "--output '%s'\n", opt.arg);
        outputFile = opt.arg;
        break;
      case VERBOSE:
        verbose = true;
        fprintf(stdout, "Verbose output\n");
        break;
    }
  }






 //std::cout << "--plus count: " <<
 //  options[PLUS].count() << "\n";
 //for (option::Option* opt = options[UNKNOWN]; opt; opt = opt->next())
 //  std::cout << "Unknown option: " << opt->name << "\n";
 //for (int i = 0; i < parse.nonOptionsCount(); ++i)
 //  std::cout << "Non-option #" << i << ": " << parse.nonOption(i) << "\n";
    //Open input ntuple file 
    //TFile *tf = TFile::Open("exampleInputs.root");
     
     
    //std::ifstream ifs(inputFile.c_str());

    //std::string line;


    //TChain ch("ana/TreeHad");

    //while(std::getline(ifs, line))
    //{
    //    if (verbose)printf(line.c_str());
    //    if (verbose)printf("\n");
    //    ch.Add(line.c_str());
    //}

    
    TFile *tf = TFile::Open(inputFile.c_str()); //2 is LH mt_had_2tev_rh_miniaod.root mt_had_2tev_lh_miniaod.root
    TFile* hadMonoTopLoopHists  = new TFile(outputFile.c_str(), "RECREATE");
    //TFile *tf = TFile::Open("exampleInputs.root");

    //Get tree from file

     
    //TTree *tree = (TTree*) ch.GetTree();
    //if (verbose) ch.ls();
    //if (verbose) printf("Entries: %i\n", ch.GetEntries());
    //int nEntries = ch.GetEntries();
    int nEntries = 1275000;
    tf->ls();
    TTree *tree = (TTree*)tf->Get("ana/TreeHad");
    TH1D* cutflow = (TH1D*)tf->Get("ana/h_cutflow_had");

    TCanvas c1;

   // printf("Event #: %i\n", tree->GetEntries());

    

    //Deactivate all branches, then activate the branches of interest
    tree->SetBranchStatus("*", 0);

    //Variables to hold inputs
    //AK4 jet variables
    //Each entry in these vectors refers to information for 1 AK4 jet
    std::vector<TLorentzVector>* AK4JetLV_p = new std::vector<TLorentzVector>;
    std::vector<TLorentzVector>** AK4JetLV = &AK4JetLV_p;
    //std::vector<TLorentzVector>** AK4JetLV = new std::vector<TLorentzVector>*();
    std::vector<double>** AK4JetBtag = new std::vector<double>*();

    std::vector<double>* AK4JetBtagBinary_p = new std::vector<double>;
    std::vector<double>** AK4JetBtagBinary = &AK4JetBtagBinary_p;


    std::vector<TLorentzVector>* AK8JetLV_p = new std::vector<TLorentzVector>;
    std::vector<TLorentzVector>** AK8JetLV = &AK8JetLV_p;

    std::vector<TLorentzVector>* tempAK8SubjetLV_p = new std::vector<TLorentzVector>;
    std::vector<TLorentzVector>** tempAK8SubjetLV = &tempAK8SubjetLV_p;

    std::vector<double>* tempAK8JetTau1_p = new std::vector<double>;
    std::vector<double>** tempAK8JetTau1 = &tempAK8JetTau1_p;

    std::vector<double>* tempAK8JetTau2_p = new std::vector<double>;
    std::vector<double>** tempAK8JetTau2 = &tempAK8JetTau2_p;

    std::vector<double>* tempAK8JetTau3_p = new std::vector<double>;
    std::vector<double>** tempAK8JetTau3 = &tempAK8JetTau3_p;

    std::vector<double>* tempAK8JetSoftdropMass_p = new std::vector<double>;
    std::vector<double>** tempAK8JetSoftdropMass = &tempAK8JetSoftdropMass_p;


    //AK8 jet varaibles

    //The elements of each vector refer to one AK8 jet
   // std::vector<TLorentzVector>** AK8JetLV = new std::vector<TLorentzVector>*();
    std::vector<TLorentzVector>*AK8SubjetLV_p = new std::vector<TLorentzVector>;
    std::vector<TLorentzVector>** AK8SubjetLV = &AK8SubjetLV_p;
    std::vector<double>** AK8JetTau1 = new std::vector<double>*();
    std::vector<double>** AK8JetTau2 = new std::vector<double>*();
    std::vector<double>** AK8JetTau3 = new std::vector<double>*();
    std::vector<double>** AK8JetSoftdropMass = new std::vector<double>*();
    TLorentzVector temp;

 

    //Activate branches of interest
    //AK4 jet lorentz vectors
    //tree->SetBranchStatus( "jetsLVec_forTagger", 1);
    //tree->SetBranchAddress("jetsLVec_forTagger", AK4JetLV);
    
    //AK4 jet b-tag values (0 not a b, 1 is a b)
    tree->SetBranchStatus( "AK4JetBtag_p", 1);
    tree->SetBranchAddress("AK4JetBtag_p", AK4JetBtag);
    
    //AK8 jet lorentz vectors
    //tree->SetBranchStatus( "puppiJetsLVec", 1);
    //tree->SetBranchAddress("puppiJetsLVec", AK8JetLV);
    
    //AK8 subjet lorentz vectors (soft drop algo produces 2 subjets for each AK8 jet)
    //All are present in this list and dR matching associates them to the approperiate AK8 jet
    //tree->SetBranchStatus( "puppiSubJetsLVec", 1);
    //tree->SetBranchAddress("puppiSubJetsLVec", AK8SubjetLV);
 
    Float_t         HadMETpt;
    TBranch        *b_HadMETpt;   //!
    tree->SetBranchStatus("HadMETpt", 1);
    tree->SetBranchAddress("HadMETpt", &HadMETpt, &b_HadMETpt);


    Float_t         Gen_array_t_p4[4];
    Float_t         Gen_array_final_t_p4[4];
    Float_t         Gen_array_b_p4[4];
    Float_t         Gen_array_W_p4[4];
    Float_t         Gen_array_Wd1_p4[4];
    Float_t         Gen_array_Wd2_p4[4];

    tree->SetBranchStatus("Gen_array_t_p4", 1);
    tree->SetBranchAddress("Gen_array_t_p4", Gen_array_t_p4);
    tree->SetBranchStatus("Gen_array_final_t_p4", 1);
    tree->SetBranchAddress("Gen_array_final_t_p4", Gen_array_final_t_p4);
    tree->SetBranchStatus("Gen_array_b_p4", 1);
    tree->SetBranchAddress("Gen_array_b_p4", Gen_array_b_p4);
    tree->SetBranchStatus("Gen_array_W_p4", 1);
    tree->SetBranchAddress("Gen_array_W_p4", Gen_array_W_p4);
    tree->SetBranchStatus("Gen_array_Wd1_p4", 1);
    tree->SetBranchAddress("Gen_array_Wd1_p4", Gen_array_Wd1_p4);
    tree->SetBranchStatus("Gen_array_Wd2_p4", 1);
    tree->SetBranchAddress("Gen_array_Wd2_p4", Gen_array_Wd2_p4);
    
    std::vector<double>** AK4JetLV_pt = new std::vector<double>*();
    std::vector<double>** AK4JetLV_eta = new std::vector<double>*();
    std::vector<double>** AK4JetLV_phi = new std::vector<double>*();
    std::vector<double>** AK4JetLV_mass = new std::vector<double>*();

    std::vector<double>** AK4JetLV_corr = new std::vector<double>*();
    std::vector<double>** AK4JetLV_corrUp = new std::vector<double>*();
    std::vector<double>** AK4JetLV_corrDn = new std::vector<double>*();
    std::vector<double>** AK4JetLV_SF = new std::vector<double>*();
    std::vector<double>** AK4JetLV_SFUp = new std::vector<double>*();
    std::vector<double>** AK4JetLV_SFDn = new std::vector<double>*();
    std::vector<double>** AK4JetLV_ptsmear = new std::vector<double>*();
    std::vector<double>** AK4JetLV_ptsmearUp = new std::vector<double>*();
    std::vector<double>** AK4JetLV_ptsmearDn = new std::vector<double>*();

    std::vector<double>** AK8JetLV_pt = new std::vector<double>*();
    std::vector<double>** AK8JetLV_eta = new std::vector<double>*();
    std::vector<double>** AK8JetLV_phi = new std::vector<double>*();
    std::vector<double>** AK8JetLV_mass = new std::vector<double>*();

    std::vector<double>** AK8JetLV_corr = new std::vector<double>*();
    std::vector<double>** AK8JetLV_corrUp = new std::vector<double>*();
    std::vector<double>** AK8JetLV_corrDn = new std::vector<double>*();
    std::vector<double>** AK8JetLV_SF = new std::vector<double>*();
    std::vector<double>** AK8JetLV_SFUp = new std::vector<double>*();
    std::vector<double>** AK8JetLV_SFDn = new std::vector<double>*();
    std::vector<double>** AK8JetLV_ptsmear = new std::vector<double>*();
    std::vector<double>** AK8JetLV_ptsmearUp = new std::vector<double>*();
    std::vector<double>** AK8JetLV_ptsmearDn = new std::vector<double>*();
    
    std::vector<double>** AK8SubjetLV_pt = new std::vector<double>*();
    std::vector<double>** AK8SubjetLV_eta = new std::vector<double>*();
    std::vector<double>** AK8SubjetLV_phi = new std::vector<double>*();
    std::vector<double>** AK8SubjetLV_mass = new std::vector<double>*();





    
    tree->SetBranchStatus("AK4JetLV_pt", 1);
    tree->SetBranchAddress("AK4JetLV_pt", AK4JetLV_pt);
    tree->SetBranchStatus("AK4JetLV_eta", 1);
    tree->SetBranchAddress("AK4JetLV_eta", AK4JetLV_eta);
    tree->SetBranchStatus("AK4JetLV_phi", 1);
    tree->SetBranchAddress("AK4JetLV_phi", AK4JetLV_phi);
    tree->SetBranchStatus("AK4JetLV_mass", 1);
    tree->SetBranchAddress("AK4JetLV_mass", AK4JetLV_mass);

    tree->SetBranchStatus("AK4JetLV_corr", 1);
    tree->SetBranchAddress("AK4JetLV_corr", AK4JetLV_corr);
    tree->SetBranchStatus("AK4JetLV_corrUp", 1);
    tree->SetBranchAddress("AK4JetLV_corrUp", AK4JetLV_corrUp);
    tree->SetBranchStatus("AK4JetLV_corrDn", 1);
    tree->SetBranchAddress("AK4JetLV_corrDn", AK4JetLV_corrDn);
    tree->SetBranchStatus("AK4JetLV_SF", 1);
    tree->SetBranchAddress("AK4JetLV_SF", AK4JetLV_SF);
    tree->SetBranchStatus("AK4JetLV_SFUp", 1);
    tree->SetBranchAddress("AK4JetLV_SFUp", AK4JetLV_SFUp);
    tree->SetBranchStatus("AK4JetLV_SFDn", 1);
    tree->SetBranchAddress("AK4JetLV_SFDn", AK4JetLV_SFDn);
    tree->SetBranchStatus("AK4JetLV_ptsmear", 1);
    tree->SetBranchAddress("AK4JetLV_ptsmear", AK4JetLV_ptsmear);
    tree->SetBranchStatus("AK4JetLV_ptsmearUp", 1);
    tree->SetBranchAddress("AK4JetLV_ptsmearUp", AK4JetLV_ptsmearUp);
    tree->SetBranchStatus("AK4JetLV_ptsmearDn", 1);
    tree->SetBranchAddress("AK4JetLV_ptsmearDn", AK4JetLV_ptsmearDn);


    tree->SetBranchStatus("AK8JetLV_pt", 1);
    tree->SetBranchAddress("AK8JetLV_pt", AK8JetLV_pt);
    tree->SetBranchStatus("AK8JetLV_eta", 1);
    tree->SetBranchAddress("AK8JetLV_eta", AK8JetLV_eta);
    tree->SetBranchStatus("AK8JetLV_phi", 1);
    tree->SetBranchAddress("AK8JetLV_phi", AK8JetLV_phi);
    tree->SetBranchStatus("AK8JetLV_mass", 1);
    tree->SetBranchAddress("AK8JetLV_mass", AK8JetLV_mass);
    tree->SetBranchStatus("AK8SubjetLV_pt", 1);
    tree->SetBranchAddress("AK8SubjetLV_pt", AK8SubjetLV_pt);
    tree->SetBranchStatus("AK8SubjetLV_eta", 1);
    tree->SetBranchAddress("AK8SubjetLV_eta", AK8SubjetLV_eta);
    tree->SetBranchStatus("AK8SubjetLV_phi", 1);
    tree->SetBranchAddress("AK8SubjetLV_phi", AK8SubjetLV_phi);
    tree->SetBranchStatus("AK8SubjetLV_mass", 1);
    tree->SetBranchAddress("AK8SubjetLV_mass", AK8SubjetLV_mass);

    tree->SetBranchStatus("AK8JetLV_corr", 1);
    tree->SetBranchAddress("AK8JetLV_corr", AK8JetLV_corr);
    tree->SetBranchStatus("AK8JetLV_corrUp", 1);
    tree->SetBranchAddress("AK8JetLV_corrUp", AK8JetLV_corrUp);
    tree->SetBranchStatus("AK8JetLV_corrDn", 1);
    tree->SetBranchAddress("AK8JetLV_corrDn", AK8JetLV_corrDn);
    tree->SetBranchStatus("AK8JetLV_SF", 1);
    tree->SetBranchAddress("AK8JetLV_SF", AK8JetLV_SF);
    tree->SetBranchStatus("AK8JetLV_SFUp", 1);
    tree->SetBranchAddress("AK8JetLV_SFUp", AK8JetLV_SFUp);
    tree->SetBranchStatus("AK8JetLV_SFDn", 1);
    tree->SetBranchAddress("AK8JetLV_SFDn", AK8JetLV_SFDn);
    tree->SetBranchStatus("AK8JetLV_ptsmear", 1);
    tree->SetBranchAddress("AK8JetLV_ptsmear", AK8JetLV_ptsmear);
    tree->SetBranchStatus("AK8JetLV_ptsmearUp", 1);
    tree->SetBranchAddress("AK8JetLV_ptsmearUp", AK8JetLV_ptsmearUp);
    tree->SetBranchStatus("AK8JetLV_ptsmearDn", 1);
    tree->SetBranchAddress("AK8JetLV_ptsmearDn", AK8JetLV_ptsmearDn);


    std::vector<std::string> *HLTtriggers      = new std::vector<std::string> ;
    tree->SetBranchStatus("HLTtriggers", 1);
    tree->SetBranchAddress("HLTtriggers", &HLTtriggers);


    std::vector<bool> *HLTtriggersPass      = new std::vector<bool> ;
    tree->SetBranchStatus("HLTtriggersPass", 1);
    tree->SetBranchAddress("HLTtriggersPass", &HLTtriggersPass);


    std::vector<int> *HLTtriggersPrescales      = new std::vector<int> ;
    tree->SetBranchStatus("HLTtriggersPrescales", 1);
    tree->SetBranchAddress("HLTtriggersPrescales", &HLTtriggersPrescales);



    std::vector<bool> *HadTrigPass      = new std::vector<bool> ;
    tree->SetBranchStatus("HadTrigPass", 1);
    tree->SetBranchAddress("HadTrigPass", &HadTrigPass);




    std::vector<float>** MuIso = new std::vector<float>*();
    tree->SetBranchStatus("MuIso", 1);
    tree->SetBranchAddress("MuIso", MuIso);

//if V10 https://twiki.cern.ch/twiki/bin/viewauth/CMS/SWGuideMuonIdRun2
    /*std::vector<float>** MuIsoTrk = new std::vector<float>*();
    tree->SetBranchStatus("MuIsoTrk", 1);
    tree->SetBranchAddress("MuIsoTrk", MuIsoTrk);
    */
    

    std::vector<float>** MuPt = new std::vector<float>*();
    tree->SetBranchStatus("MuPt", 1);
    tree->SetBranchAddress("MuPt", MuPt);

    std::vector<float>** MuPhi = new std::vector<float>*();
    tree->SetBranchStatus("MuPhi", 1);
    tree->SetBranchAddress("MuPhi", MuPhi);

    std::vector<float>** MuEta = new std::vector<float>*();
    tree->SetBranchStatus("MuEta", 1);
    tree->SetBranchAddress("MuEta", MuEta);

    std::vector<float>** Electron_Pt = new std::vector<float>*();
    tree->SetBranchStatus("Electron_Pt", 1);
    tree->SetBranchAddress("Electron_Pt", Electron_Pt);

    std::vector<float>** Electron_Phi = new std::vector<float>*();
    tree->SetBranchStatus("Electron_Phi", 1);
    tree->SetBranchAddress("Electron_Phi", Electron_Phi);




    //AK8 jet tau1 variable
    tree->SetBranchStatus( "AK8JetTau1_p", 1);
    tree->SetBranchAddress("AK8JetTau1_p", AK8JetTau1);
    
    //AK8 jet tau2 variable
    tree->SetBranchStatus( "AK8JetTau2_p", 1);
    tree->SetBranchAddress("AK8JetTau2_p", AK8JetTau2);
    
    //AK8 jet tau3 variable
    tree->SetBranchStatus( "AK8JetTau3_p", 1);
    tree->SetBranchAddress("AK8JetTau3_p", AK8JetTau3);
    
    //AK8 jet softdrop mass
    tree->SetBranchStatus( "AK8JetSoftdropMass_p", 1);
    tree->SetBranchAddress("AK8JetSoftdropMass_p", AK8JetSoftdropMass);

    //Create top tagger object
    TopTagger tt;

    TLorentzVector TL_Gen_Top;
    TLorentzVector TL_Gen_b;
    TLorentzVector TL_Gen_W;

    TLorentzVector TL_AK4_B_subJetPt;
    TLorentzVector TL_Mu;

    Float_t had_ratio; 
    Float_t gen_ratio; 

    Int_t nBins = 50;

    Float_t maxPt = 1000;
    Float_t bTagMax = 0;

    TH1F* TH1F_cutflow = new TH1F("TH1F_cutflow", "Cutflow ;  Cuts ; count", 20, -.5, 19.5);

    std::vector <std::string> cutName;

 int cutflowCount = 0;      
 //cutflow->Draw();
 //c1.SaveAs("test.png"); 
    for(int i=2; i< 8; i++ ){
       
        printf("cutflow: %d %f\n",   cutflow->GetBin(i), cutflow->GetBinContent(i));
        if (cutflow->GetBinContent(i) ==0) break;
        //cutflow->GetBinContent(i);
        TH1F_cutflow->SetBinContent(i-1,cutflow->GetBinContent(i));
        cutName.push_back("preselection");
        cutflowCount++;
    }                     

   
    TH1F* TH1F_gen_E_ratio_SUSY_top = new TH1F("TH1F_gen_E_ratio_SUSY_top", "Gen Top to SUSY energy ;  E(SUSY)/E(gen) ; count", nBins, .5,1.5 );
    TH1F* TH1F_gen_deltaR_SUSY_top = new TH1F("TH1F_gen_deltaR_SUSY_top", "Gen SUSY #delta R Top ;  #delta_{R} ; count", nBins, 0, .5 );
    TH1F* TH1F_had_SUSY_pt = new TH1F("TH1F_had_SUSY_pt", "SUSY p_{T}; p_{T} [GeV]; count", nBins, 0, maxPt );
    TH1F* TH1F_had_AK4b_pt = new TH1F("TH1F_had_AK4b_pt", "AK4 b p_{T}; p_{T} [GeV]; count", nBins, 0, maxPt );

    TH1F* TH1F_gen_Ratio = new TH1F("TH1F_gen_Ratio", "Gen Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_gen_Ratio_After_Tag = new TH1F("TH1F_gen_Ratio_After_Tag", "Gen Ratio After Tagging: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_had_Ratio = new TH1F("TH1F_had_Ratio", "Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );

   // TH1F* TH1F_one_gen_Ratio = new TH1F("TH1F_one_gen_Ratio", "One Jet(s) Gen Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_one_gen_Ratio_After_Tag = new TH1F("TH1F_one_gen_Ratio_After_Tag", "One Jet(s) Gen Ratio After Tagging: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_one_had_Ratio = new TH1F("TH1F_one_had_Ratio", "One Jet(s) Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );

    //TH1F* TH1F_two_gen_Ratio = new TH1F("TH1F_two_gen_Ratio", "Two Jet(s) Gen Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_two_gen_Ratio_After_Tag = new TH1F("TH1F_two_gen_Ratio_After_Tag", "Two Jet(s) Gen Ratio After Tagging: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_two_had_Ratio = new TH1F("TH1F_two_had_Ratio", "Two Jet(s) Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );

   // TH1F* TH1F_three_gen_Ratio = new TH1F("TH1F_three_gen_Ratio", "Three Jet(s) Gen Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_three_gen_Ratio_After_Tag = new TH1F("TH1F_three_gen_Ratio_After_Tag", "Three Jet(s) Gen Ratio After Tagging: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_three_had_Ratio = new TH1F("TH1F_three_had_Ratio", "Three Jet(s) Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );


       // TH1F* TH1F_one_gen_Ratio = new TH1F("TH1F_one_gen_Ratio", "One Jet(s) Gen Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
    TH1F* TH1F_one_gen_pT_After_Tag = new TH1F("TH1F_one_gen_pT_After_Tag", "One Jet(s) Gen p_{T} After Tagging: p_{T} [GeV];  E(b)/E(t); count", nBins, 0, 2000 );
    TH1F* TH1F_one_had_pT = new TH1F("TH1F_one_had_pT", "One Jet(s) p_{T}; p_{T} [GeV]; count", nBins, 0, 2000 );

    //TH1F* TH1F_two_gen_pT = new TH1F("TH1F_two_gen_pT", "Two Jet(s) Gen pT: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 2000 );
    TH1F* TH1F_two_gen_pT_After_Tag = new TH1F("TH1F_two_gen_pT_After_Tag", "Two Jet(s) Gen p_{T} After Tagging: p_{T} [GeV];  E(b)/E(t); count", nBins, 0, 2000 );
    TH1F* TH1F_two_had_pT = new TH1F("TH1F_two_had_pT", "Two Jet(s) p_{T}; p_{T} [GeV]; count", nBins, 0, 2000 );

   // TH1F* TH1F_three_gen_pT = new TH1F("TH1F_three_gen_pT", "Three Jet(s) Gen pT: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 2000 );
    TH1F* TH1F_three_gen_pT_After_Tag = new TH1F("TH1F_three_gen_pT_After_Tag", "Three Jet(s) Gen p_{T} After Tagging: p_{T} [GeV];  E(b)/E(t); count", nBins, 0, 2000 );
    TH1F* TH1F_three_had_pT = new TH1F("TH1F_three_had_pT", "Three Jet(s) p_{T}; p_{T} [GeV]; count", nBins, 0, 2000 );


   
    TH1F* TH1F_TL_AK4_B_subJetPt_zoomed_0 = new TH1F("TH1F_TL_AK4_B_subJetPt_zoomed_0", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins*2, 30, 150);
    TH1F* TH1F_HadMETpt_zoomed_0 = new TH1F("TH1F_HadMETpt_zoomed_0", "MET; MET ; count", nBins*2, 0, 300);
    TH1F* TH1F_TL_top_Mass_zoomed_0 = new TH1F("TH1F_TL_top_Mass_zoomed_0", "Top Mass; Mass [GEV] ; count", nBins*2, 100, 300);
    TH1F* TH1F_MuPt_zoomed_0 = new TH1F("TH1F_MuPt_zoomed_0", "Muon p_{T}; p_{T} [GEV] ; count", nBins*2, 0, 100);
    TH1F* TH1F_Mt_zoomed_0 = new TH1F("TH1F_Mt_zoomed_0", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins*2, 0, 400);
    TH1F* TH1F_deltaR_zoomed_0 = new TH1F("TH1F_deltaR_zoomed_0", "Muon Bjet #delta R; #delta R ; count", nBins*2, 0, .1);
    TH1F* TH1F_MuISO_zoomed_0 = new TH1F("TH1F_MuISO_zoomed_0", "Muon Isolation; MuISO ; count", nBins*2, 0, .1);
    TH1F* TH1F_MuISOTrk_zoomed_0 = new TH1F("TH1F_MuISOTrk_zoomed_0", "Muon Isolation Track; MuISO ; count", nBins*2, 0, .1);



    TH1F* TH1F_topCount_0 = new TH1F("TH1F_topCount_0", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_0 = new TH1F("TH1F_jetsNotAroundTop_0", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_0 = new TH1F("TH1F_nBjets_0", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_0 = new TH1F("TH1F_TL_AK4_B_subJetPt_0", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_0 = new TH1F("TH1F_TL_AK4_B_subJetEta_0", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_0 = new TH1F("TH1F_nLep_0", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_0 = new TH1F("TH1F_HadMETpt_0", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_0 = new TH1F("TH1F_TL_top_Mass_0", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_0 = new TH1F("TH1F_TL_top_Pt_0", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_0 = new TH1F("TH1F_ratio_0", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);

    TH1F* TH1F_nMu_0 = new TH1F("TH1F_nMu_0", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_0 = new TH1F("TH1F_MuPt_0", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_0 = new TH1F("TH1F_deltaPhi_0", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_0 = new TH1F("TH1F_Mt_0", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_0 = new TH1F("TH1F_MuISO_0", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_0 = new TH1F("TH1F_MuISOTrk_0", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);


    TH1F* TH1F_topCount_1 = new TH1F("TH1F_topCount_1", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_1 = new TH1F("TH1F_jetsNotAroundTop_1", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_1 = new TH1F("TH1F_nBjets_1", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_1 = new TH1F("TH1F_TL_AK4_B_subJetPt_1", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_1 = new TH1F("TH1F_TL_AK4_B_subJetEta_1", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_1 = new TH1F("TH1F_nLep_1", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_1 = new TH1F("TH1F_HadMETpt_1", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_1 = new TH1F("TH1F_TL_top_Mass_1", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_1 = new TH1F("TH1F_TL_top_Pt_1", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_1 = new TH1F("TH1F_ratio_1", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);



    TH1F* TH1F_nMu_1 = new TH1F("TH1F_nMu_1", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_1 = new TH1F("TH1F_MuPt_1", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_1 = new TH1F("TH1F_deltaPhi_1", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_1 = new TH1F("TH1F_Mt_1", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_1 = new TH1F("TH1F_MuISO_1", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_1 = new TH1F("TH1F_MuISOTrk_1", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);


    TH1F* TH1F_topCount_2 = new TH1F("TH1F_topCount_2", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_2 = new TH1F("TH1F_jetsNotAroundTop_2", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_2 = new TH1F("TH1F_nBjets_2", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_2 = new TH1F("TH1F_TL_AK4_B_subJetPt_2", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_2 = new TH1F("TH1F_TL_AK4_B_subJetEta_2", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_2 = new TH1F("TH1F_nLep_2", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_2 = new TH1F("TH1F_HadMETpt_2", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_2 = new TH1F("TH1F_TL_top_Mass_2", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_2 = new TH1F("TH1F_TL_top_Pt_2", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_2 = new TH1F("TH1F_ratio_2", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);


    TH1F* TH1F_nMu_2 = new TH1F("TH1F_nMu_2", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_2 = new TH1F("TH1F_MuPt_2", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_2 = new TH1F("TH1F_deltaPhi_2", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_2 = new TH1F("TH1F_Mt_2", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_2 = new TH1F("TH1F_MuISO_2", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_2 = new TH1F("TH1F_MuISOTrk_2", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);
    

    TH1F* TH1F_topCount_3 = new TH1F("TH1F_topCount_3", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_3 = new TH1F("TH1F_jetsNotAroundTop_3", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_3 = new TH1F("TH1F_nBjets_3", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_3 = new TH1F("TH1F_TL_AK4_B_subJetPt_3", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_3 = new TH1F("TH1F_TL_AK4_B_subJetEta_3", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_3 = new TH1F("TH1F_nLep_3", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_3 = new TH1F("TH1F_HadMETpt_3", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_3 = new TH1F("TH1F_TL_top_Mass_3", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_3 = new TH1F("TH1F_TL_top_Pt_3", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_3 = new TH1F("TH1F_ratio_3", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);


    TH1F* TH1F_nMu_3 = new TH1F("TH1F_nMu_3", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_3 = new TH1F("TH1F_MuPt_3", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_3 = new TH1F("TH1F_deltaPhi_3", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_3 = new TH1F("TH1F_Mt_3", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_3 = new TH1F("TH1F_MuISO_3", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_3 = new TH1F("TH1F_MuISOTrk_3", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);


    TH1F* TH1F_topCount_4 = new TH1F("TH1F_topCount_4", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_4 = new TH1F("TH1F_jetsNotAroundTop_4", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_4 = new TH1F("TH1F_nBjets_4", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_4 = new TH1F("TH1F_TL_AK4_B_subJetPt_4", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_4 = new TH1F("TH1F_TL_AK4_B_subJetEta_4", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_4 = new TH1F("TH1F_nLep_4", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_4 = new TH1F("TH1F_HadMETpt_4", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_4 = new TH1F("TH1F_TL_top_Mass_4", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_4 = new TH1F("TH1F_TL_top_Pt_4", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_4 = new TH1F("TH1F_ratio_4", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);


    TH1F* TH1F_nMu_4 = new TH1F("TH1F_nMu_4", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_4 = new TH1F("TH1F_MuPt_4", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_4 = new TH1F("TH1F_deltaPhi_4", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_4 = new TH1F("TH1F_Mt_4", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_4 = new TH1F("TH1F_MuISO_4", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_4 = new TH1F("TH1F_MuISOTrk_4", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);


    TH1F* TH1F_topCount_5 = new TH1F("TH1F_topCount_5", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_5 = new TH1F("TH1F_jetsNotAroundTop_5", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_5 = new TH1F("TH1F_nBjets_5", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_5 = new TH1F("TH1F_TL_AK4_B_subJetPt_5", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_5 = new TH1F("TH1F_TL_AK4_B_subJetEta_5", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_5 = new TH1F("TH1F_nLep_5", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_5 = new TH1F("TH1F_HadMETpt_5", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_5 = new TH1F("TH1F_TL_top_Mass_5", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_5 = new TH1F("TH1F_TL_top_Pt_5", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_5 = new TH1F("TH1F_ratio_5", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);


    TH1F* TH1F_nMu_5 = new TH1F("TH1F_nMu_5", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_5 = new TH1F("TH1F_MuPt_5", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_5 = new TH1F("TH1F_deltaPhi_5", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_5 = new TH1F("TH1F_Mt_5", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_5 = new TH1F("TH1F_MuISO_5", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_5 = new TH1F("TH1F_MuISOTrk_5", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);

    TH1F* TH1F_topCount_6 = new TH1F("TH1F_topCount_6", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_6 = new TH1F("TH1F_jetsNotAroundTop_6", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_6 = new TH1F("TH1F_nBjets_6", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_6 = new TH1F("TH1F_TL_AK4_B_subJetPt_6", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_6 = new TH1F("TH1F_TL_AK4_B_subJetEta_6", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_6 = new TH1F("TH1F_nLep_6", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_6 = new TH1F("TH1F_HadMETpt_6", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_6 = new TH1F("TH1F_TL_top_Mass_6", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_6 = new TH1F("TH1F_TL_top_Pt_6", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_6 = new TH1F("TH1F_ratio_6", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);



    TH1F* TH1F_nMu_6 = new TH1F("TH1F_nMu_6", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_6 = new TH1F("TH1F_MuPt_6", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_6 = new TH1F("TH1F_deltaPhi_6", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_6 = new TH1F("TH1F_Mt_6", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_6 = new TH1F("TH1F_MuISO_6", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_6 = new TH1F("TH1F_MuISOTrk_6", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);

    TH1F* TH1F_topCount_7 = new TH1F("TH1F_topCount_7", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_7 = new TH1F("TH1F_jetsNotAroundTop_7", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_7 = new TH1F("TH1F_nBjets_7", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_7 = new TH1F("TH1F_TL_AK4_B_subJetPt_7", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_7 = new TH1F("TH1F_TL_AK4_B_subJetEta_7", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_7 = new TH1F("TH1F_nLep_7", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_7 = new TH1F("TH1F_HadMETpt_7", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_7 = new TH1F("TH1F_TL_top_Mass_7", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_7 = new TH1F("TH1F_TL_top_Pt_7", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_7 = new TH1F("TH1F_ratio_7", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);


    TH1F* TH1F_nMu_7 = new TH1F("TH1F_nMu_7", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_7 = new TH1F("TH1F_MuPt_7", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_7 = new TH1F("TH1F_deltaPhi_7", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_7 = new TH1F("TH1F_Mt_7", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_7 = new TH1F("TH1F_MuISO_7", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_7 = new TH1F("TH1F_MuISOTrk_7", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);

    TH1F* TH1F_topCount_8 = new TH1F("TH1F_topCount_8", "n Tops; n Tops ; count", 5, -0.5, 4.5);
    TH1F* TH1F_jetsNotAroundTop_8 = new TH1F("TH1F_jetsNotAroundTop_8", "n Jets not near Top; n Jets ; count", 10, -0.5, 9.5);
    TH1F* TH1F_nBjets_8 = new TH1F("TH1F_nBjets_8", "n Bjets; n Bjets ; count", 5, -0.5, 4.5);
    TH1F* TH1F_TL_AK4_B_subJetPt_8 = new TH1F("TH1F_TL_AK4_B_subJetPt_8", "Top AK4 Bjet p_{T}; p_{T} [GEV]; count", nBins, 0, 1500);
    TH1F* TH1F_TL_AK4_B_subJetEta_8 = new TH1F("TH1F_TL_AK4_B_subJetEta_8", "Top AK4 Bjet #eta; #eta ; count", nBins, -2.6, 2.6);
    TH1F* TH1F_nLep_8 = new TH1F("TH1F_nLep_8", "nLep; n Electrons or Muons ; count", 5, -0.5, 4.5);
    TH1F* TH1F_HadMETpt_8 = new TH1F("TH1F_HadMETpt_8", "MET; MET ; count", nBins, 0, 1500);
    TH1F* TH1F_TL_top_Mass_8 = new TH1F("TH1F_TL_top_Mass_8", "Top Mass; Mass [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_TL_top_Pt_8 = new TH1F("TH1F_TL_top_Pt_8", "Top p_{T}; p_{T} [GEV] ; count", nBins, 0, 2000);
    TH1F* TH1F_ratio_8 = new TH1F("TH1F_ratio_8", "Ratio E(b)/E(t); E(b)/E(t) ; count", nBins, 0, 1.2);


    TH1F* TH1F_nMu_8 = new TH1F("TH1F_nMu_8", "n #mu; #mu count",  5, -0.5, 4.5);
    TH1F* TH1F_MuPt_8 = new TH1F("TH1F_MuPt_8", "Muon p_{T}; p_{T} [GEV] ; count", nBins, 0, 1000);
    TH1F* TH1F_deltaPhi_8 = new TH1F("TH1F_deltaPhi_8", "#delta(#mu_{#phi} - b_{#phi}); Radians ; count", nBins, -3.1415, 3.1415);
    TH1F* TH1F_Mt_8 = new TH1F("TH1F_Mt_8", "Transverse Mass between Muon, B jet ; [GeV]; count", nBins, 0, 700);
    TH1F* TH1F_MuISO_8 = new TH1F("TH1F_MuISO_8", "Muon Isolation; MuISO ; count", nBins, 0, 1.2);
    TH1F* TH1F_MuISOTrk_8 = new TH1F("TH1F_MuISOTrk_8", "Muon Isolation Track; MuISO ; count", nBins, 0, 1.2);

 

    Int_t nConstituents;

    std::vector<std::string> trigsToRun;
    //trigsToRun.push_back("HLT_PFMET120_NoiseCleaned_BTagCSV07_v");
    //trigsToRun.push_back("HLT_PFMET120_BTagCSV_p067_v");
    //trigsToRun.push_back("HLT_PFMET120_BTagCSV_p067_v");


  //trigsToRunHad.push_back("HLT_PFMET120_NoiseCleaned_BTagCSV07_v");
  //trigsToRunHad.push_back("HLT_PFMET300_v");
  //trigsToRunHad.push_back("HLT_PFMET400_v");
  //trigsToRunHad.push_back("HLT_PFMET500_v");
  //trigsToRunHad.push_back("HLT_PFMET600_v");


   // trigsToRun.push_back("HLT_PFMET300_v");

    //trigsToRun.push_back("HLT_PFMET170_NoiseCleaned");
    //trigsToRun.push_back("HLT_PFMET170_JetIdCleaned");
    //trigsToRun.push_back("HLT_PFMET170_HBHECleaned");

    trigsToRun.push_back("HLT_PFMET120_BTagCSV_p067_v2");
    trigsToRun.push_back("HLT_PFMET120_Mu5_v2");
    //trigsToRun.push_back("HLT_PFMET120_NoiseCleaned_BTagCSV07_v");
    //trigsToRun.push_back("HLT_PFMET120_BTagCSV_p067_v");
    //trigsToRun.push_back("HLT_PFMET120_BTagCSV_p067_v");
    //trigsToRun.push_back("HLT_PFMET120_Mu5_v");
    //trigsToRun.push_back("HLT_PFHT300_v");
    //trigsToRun.push_back("HLT_PFHT350_v");
    //trigsToRun.push_back("HLT_PFHT400_v");
    //trigsToRun.push_back("HLT_PFHT475_v");
    //trigsToRun.push_back("HLT_PFHT600_v");
    //trigsToRun.push_back("HLT_PFHT650_v");
    //trigsToRun.push_back("HLT_PFHT800_v");
    //trigsToRun.push_back("HLT_PFHT900_v");

 std::vector<std::string> trigsRun;
// trigsRun.push_back("HLT_PFMET120_NoiseCleaned_BTagCSV07_v");
// trigsRun.push_back("HLT_PFMET120_BTagCSV_p067_v");
// trigsRun.push_back("HLT_PFMET120_Mu5_v");
// trigsRun.push_back("HLT_Ele10_CaloIdM_TrackIdM_CentralPFJet30_BTagCSV_p13_v");
// trigsRun.push_back("HLT_PFHT300_v");
// trigsRun.push_back("HLT_PFHT350_v");
// trigsRun.push_back("HLT_PFHT400_v");
// trigsRun.push_back("HLT_PFHT475_v");
// trigsRun.push_back("HLT_PFHT600_v");
// trigsRun.push_back("HLT_PFHT650_v");
// trigsRun.push_back("HLT_PFHT800_v");
// trigsRun.push_back("HLT_PFHT900_v");
// trigsRun.push_back("HLT_PFHT650_WideJetMJJ900"); //HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v6
// trigsRun.push_back("HLT_PFHT650_WideJetMJJ950"); //HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v6
// 
// //// Single jet
// trigsRun.push_back("HLT_CaloJet500_NoJetID_v");
// trigsRun.push_back("HLT_PFJet320_v");
// trigsRun.push_back("HLT_PFJet400_v");
// trigsRun.push_back("HLT_PFJet450_v");
// trigsRun.push_back("HLT_PFJet500_v");
// trigsRun.push_back("HLT_AK8PFJet450_v");
// trigsRun.push_back("HLT_AK8PFJet500_v");
// 
// //// Substructure
// trigsRun.push_back("HLT_AK8PFJet360_TrimMass30_v");
// trigsRun.push_back("HLT_AK8PFHT650_TrimR0p1PT0p03Mass50_v");
// trigsRun.push_back("HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v");
// 
// //// Substructure + b-tag
// trigsRun.push_back("HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV_p20_v");
// trigsRun.push_back("HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV_p20_v");
// 
// //// Muon
// trigsRun.push_back("HLT_Mu45_eta2p1_v");
// trigsRun.push_back("HLT_Mu50_v");
// trigsRun.push_back("HLT_Mu55_v");
// trigsRun.push_back("HLT_TkMu50_v");
// trigsRun.push_back("HLT_IsoMu22_eta2p1_v");
// trigsRun.push_back("HLT_IsoMu24_v");
// trigsRun.push_back("HLT_IsoMu27_v");
// 
// //// Muon + jet
// trigsRun.push_back("HLT_Mu30_eta2p1_PFJet150_PFJet50_v");
// trigsRun.push_back("HLT_Mu40_eta2p1_PFJet200_PFJet50_v");
// 
// //// Electron
// trigsRun.push_back("HLT_Ele32_eta2p1_WPTight_Gsf_v");
// trigsRun.push_back("HLT_Ele35_WPLoose_Gsf_v");
// trigsRun.push_back("HLT_Ele105_CaloIdVT_GsfTrkIdT_v");
// trigsRun.push_back("HLT_Ele115_CaloIdVT_GsfTrkIdT_v");
// 
// // Electron + jet
// trigsRun.push_back("HLT_Ele45_CaloIdVT_GsfTrkIdT_PFJet200_PFJet50_v");
// trigsRun.push_back("HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet140_v");
// trigsRun.push_back("HLT_Ele50_CaloIdVT_GsfTrkIdT_PFJet165_v");

    //try-catch on TTException which are thrown by the top tagger
   try
   {
       
       //Set top tagger cfg file
       tt.setCfgFile("TopTagger.cfg");

     //Loop over events
     int Nevt = 0;
     //if (verbose) printf("tree entries: %i\n",  tree->GetEntries());
     
     while(tree->GetEntry(Nevt)){

        //if (Nevt%1000 ==0) printf("Nevt: %i,  %d%\n", Nevt, (double)nEntries/(double)Nevt);
        if (Nevt > 1275000) break;
       // if (verbose) printf("------------------------------------ %i \n",  HadTrigPass->size());

        //std::cout << *HadTrigAcceptBits << std::endl;
         
             TL_Gen_Top.SetPtEtaPhiM(Gen_array_t_p4[0], Gen_array_t_p4[1], Gen_array_t_p4[2], Gen_array_t_p4[3]);
             TL_Gen_b.SetPtEtaPhiM(Gen_array_b_p4[0], Gen_array_b_p4[1],Gen_array_b_p4[2],Gen_array_b_p4[3]);
             TL_Gen_W.SetPtEtaPhiM(Gen_array_W_p4[0], Gen_array_W_p4[1],Gen_array_W_p4[2],Gen_array_W_p4[3]);
             //had_ratio = TL_AK4_B_subJetPt.E()/TL_AK4.E();
             gen_ratio = TL_Gen_b.E()/TL_Gen_Top.E();
             TH1F_gen_Ratio->Fill(gen_ratio);

         //increment event number
         ++Nevt;
         AK8JetLV_p->clear();
         tempAK8SubjetLV_p->clear();
         tempAK8JetTau1_p->clear();
         tempAK8JetTau2_p->clear();
         tempAK8JetTau3_p->clear();
         tempAK8JetSoftdropMass_p->clear();
         AK4JetLV_p->clear();
         AK8SubjetLV_p->clear();
         AK4JetBtagBinary_p->clear();
         //if (verbose) printf("ak8 jets size: %i\n",  (*AK8JetLV_pt)->size());
         


         //printf("Event #: %i %i %i %i %i %i\n", (*AK8JetLV_pt)->size(),(*AK8SubjetLV_eta)->size(), (*tempAK8JetTau1)->size(),(*tempAK8JetTau2)->size(),(*tempAK8JetTau3)->size(),(*tempAK8JetSoftdropMass)->size());

       // for(unsigned int i=0; i<(*AK8JetLV_pt)->size() ;i++){

       //    for (unsigned int j=0; j<(*AK8SubjetLV)->size() ;j++){
       //        if   ((*AK8SubjetLV)->at(j).Pt() == (*AK8SubjetLV_pt)->at(i) ) break;
       //    }

       //    temp.SetPtEtaPhiM((*AK8SubjetLV_pt)->at(i),(*AK8SubjetLV_eta)->at(i),(*AK8SubjetLV_phi)->at(i),(*AK8SubjetLV_mass)->at(i));
       //    (*AK8SubjetLV)->push_back(temp);
       //    if (verbose) printf("\tAK8 Subjets   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", (*AK8SubjetLV)->at(i).Pt(),(*AK8SubjetLV_eta)->at(i),(*AK8SubjetLV_phi)->at(i));
       //    
       //    }


//  888    888 888    88888888888 
//  888    888 888        888     
//  888    888 888        888     
//  8888888888 888        888     
//  888    888 888        888     
//  888    888 888        888     
//  888    888 888        888     
//  888    888 88888888   888     
//                                
//                                
//           
        bool passTrig = false;
        std::string passedTrigger;
        for(int j =0; j<trigsToRun.size(); j++){
          passedTrigger = trigsToRun[j];


          for(int i=0; i< HLTtriggers->size(); i++){
   
            std::size_t found = HLTtriggers->at(i).find(passedTrigger);
            if(found !=std::string::npos && HLTtriggersPass->at(i) == 1){
              if(verbose) std::cout <<  passedTrigger << std::endl;
              passTrig =  true;
              passedTrigger = passedTrigger;

              break;
            }
          }
          if (passTrig) break;
        }
        if (verbose and passTrig) std::cout << "Passed Trig: " << passedTrigger << std::endl;
        if (verbose and not passTrig){
          std::cout << "Failed Trig" << std::endl;
          //continue;
        } 

        /*for(int i=0; i< HLTtriggers->size(); i++){
          //if(verbose) std::cout << "Trigger and Pass "<<  HLTtriggers->at(i) <<  " " << HLTtriggersPass->at(i) << std::endl;
   
          }
          if(passTrig) break;
        }

        if (verbose and passTrig) std::cout << "Passed Trig: " << passedTrigger << std::endl;
        if (verbose and not passTrig){
          std::cout << "Failed Trig" << std::endl;
          continue;
        } */


       /* bool passTrig = false;
        passTrig = true;
        for(int i=0; i< HadTrigPass->size(); i++){
           
           if (verbose) std::cout << "Trigger: " << trigsRun[i] << " pass: " <<  HadTrigPass->at(i) << std::endl;

           if (HadTrigPass->at(i)==1){
                for(int j=0; j< trigsToRun.size(); j++){
                    if(trigsToRun[j] == trigsRun[i]){
                         passTrig = true;
                         break;
                    }
                }
           }
           if (passTrig) break;
        }

        if (not passTrig) {
            if (verbose) std::cout << "Failed Trigger" << std::endl;
            continue;
        }
        if (verbose && passTrig) std::cout << "Passed Trigger!" << std::endl; */


/* //         d8888 888    d8P   .d8888b.        .d8888b.           888   888888          888             
//        d88888 888   d8P   d88P  Y88b      d88P  Y88b          888     "88b          888             
//       d88P888 888  d8P    Y88b. d88P      Y88b.               888      888          888             
//      d88P 888 888d88K      "Y88888"        "Y888b.   888  888 88888b.  888  .d88b.  888888 .d8888b  
//     d88P  888 8888888b    .d8P""Y8b.          "Y88b. 888  888 888 "88b 888 d8P  Y8b 888    88K      
//    d88P   888 888  Y88b   888    888            "888 888  888 888  888 888 88888888 888    "Y8888b. 
//   d8888888888 888   Y88b  Y88b  d88P      Y88b  d88P Y88b 888 888 d88P 88P Y8b.     Y88b.       X88 
//  d88P     888 888    Y88b  "Y8888P"        "Y8888P"   "Y88888 88888P"  888  "Y8888   "Y888  88888P' 
//                                                                      .d88P                          
//                                                                    .d88P"                           
//                                                                   888P"                                                                                    


        for(unsigned int i=0; i<(*AK8SubjetLV_pt)->size() ;i++){
           //cout << AK8SubjetLV_pt->at(i) << endl;
           //if ((*AK8JetLV_pt)->at(i) < 200) break;
            //bool breakVar =  false;
            temp.SetPtEtaPhiM((*AK8SubjetLV_pt)->at(i),(*AK8SubjetLV_eta)->at(i),(*AK8SubjetLV_phi)->at(i),(*AK8SubjetLV_mass)->at(i));
            //for (unsigned int j=0; j<(*AK8SubjetLV)->size() ;j++){
            //    if   ((*AK8SubjetLV)->at(j).Pt() == (*AK8SubjetLV_pt)->at(i) ) breakVar=true;
            //    if   ((*AK8SubjetLV)->at(j).DeltaR(temp) < .001 ) breakVar=true;
//
            //}
            //if (breakVar) break;

          
           (*AK8SubjetLV)->push_back(temp);
           if (verbose) printf("\tAK8 Subjets   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", (*AK8SubjetLV)->at(i).Pt(),(*AK8SubjetLV_eta)->at(i),(*AK8SubjetLV_phi)->at(i));
           
         }

//         d8888 888    d8P   .d8888b.         888888          888             
//        d88888 888   d8P   d88P  Y88b          "88b          888             
//       d88P888 888  d8P    Y88b. d88P           888          888             
//      d88P 888 888d88K      "Y88888"            888  .d88b.  888888 .d8888b  
//     d88P  888 8888888b    .d8P""Y8b.           888 d8P  Y8b 888    88K      
//    d88P   888 888  Y88b   888    888           888 88888888 888    "Y8888b. 
//   d8888888888 888   Y88b  Y88b  d88P           88P Y8b.     Y88b.       X88 
//  d88P     888 888    Y88b  "Y8888P"            888  "Y8888   "Y888  88888P' 
//                                              .d88P                          
//                                            .d88P"                           
//                                           888P"                                         
               
         int ak8count = 0;
         int ak8Subcount = 0;
         double AK8JetPt = 0;
         for(unsigned int i=0; i<(*AK8JetLV_pt)->size() ;i++){
           //printf("ak8 jets: %i\n", i);
            AK8JetPt = (*AK8JetLV_ptsmear)->at(i)*(*AK8JetLV_corr)->at(i)*(*AK8JetLV_pt)->at(i);
            temp.SetPtEtaPhiM( AK8JetPt,(*AK8JetLV_eta)->at(i),(*AK8JetLV_phi)->at(i),(*AK8JetLV_mass)->at(i));

            //bool breakVar =  false;
            //for (unsigned int j=0; j<(*AK8JetLV)->size() ;j++){
            //    if   ((*AK8JetLV)->at(j).Pt() == AK8JetPt ) breakVar=true;
            //    if   ((*AK8JetLV)->at(j).DeltaR(temp) < .001 ) breakVar=true;
            //}
            //if (breakVar) break;

            if (verbose) printf("\tAK8   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", AK8JetPt,(*AK8JetLV_eta)->at(i),(*AK8JetLV_phi)->at(i));
            //(*AK8JetLV)->push_back(temp);

            (*AK8JetLV)->push_back(temp);
            

            (*tempAK8JetTau1)->push_back((*AK8JetTau1)->at(i));
            (*tempAK8JetTau2)->push_back((*AK8JetTau2)->at(i));
            (*tempAK8JetTau3)->push_back((*AK8JetTau3)->at(i));
            (*tempAK8JetSoftdropMass)->push_back((*AK8JetSoftdropMass)->at(i));

            //ak8Subcount++;
            //temp.SetPtEtaPhiM((*AK8SubjetLV_pt)->at(i),(*AK8SubjetLV_eta)->at(i),(*AK8SubjetLV_phi)->at(i),(*AK8SubjetLV_mass)->at(i));
            //(*tempAK8SubjetLV)->push_back(temp);
            ////ak8Subcount++;
            //temp.SetPtEtaPhiM((*AK8SubjetLV_pt)->at(i),(*AK8SubjetLV_eta)->at(i),(*AK8SubjetLV_phi)->at(i),(*AK8SubjetLV_mass)->at(i));
            //(*tempAK8SubjetLV)->push_back(temp);
            ////ak8Subcount++;



            //break;
       
         //  bool match = false;
         //  for (unsigned int j=0; j<(*AK8JetLV_pt)->size() ;j++){
         //  

    
         //   }
         //  
         //  if (match == false){
         //       if (verbose) printf("\tAK8   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", (*AK8JetLV_pt)->at(i),(*AK8JetLV_eta)->at(i),(*AK8JetLV_phi)->at(i));
         //  }
            //if (match == false){
            //    if (verbose) printf("\tAK8   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", (*AK8JetLV_pt)->at(i),(*AK8JetLV_eta)->at(i),(*AK8JetLV_phi)->at(i));
            //    (*AK8JetLV)->push_back(temp);
            //    temp.SetPtEtaPhiM((*AK8SubjetLV_pt)->at(i),(*AK8SubjetLV_eta)->at(i),(*AK8SubjetLV_phi)->at(i),(*AK8SubjetLV_mass)->at(i));
            //    (*tempAK8SubjetLV)->push_back(temp);
            //    (*tempAK8JetTau1)->push_back((*AK8JetTau1)->at(i));
            //    (*tempAK8JetTau2)->push_back((*AK8JetTau2)->at(i));
            //    (*tempAK8JetTau3)->push_back((*AK8JetTau3)->at(i));
            //    (*tempAK8JetSoftdropMass)->push_back((*AK8JetSoftdropMass)->at(i));
            //}

          // printf("ak8 jets: %4.2f \n", (*AK8JetLV_pt)->at(i));
         } */


//         d8888 888    d8P     d8888         888888          888             
//        d88888 888   d8P     d8P888           "88b          888             
//       d88P888 888  d8P     d8P 888            888          888             
//      d88P 888 888d88K     d8P  888            888  .d88b.  888888 .d8888b  
//     d88P  888 8888888b   d88   888            888 d8P  Y8b 888    88K      
//    d88P   888 888  Y88b  8888888888           888 88888888 888    "Y8888b. 
//   d8888888888 888   Y88b       888            88P Y8b.     Y88b.       X88 
//  d88P     888 888    Y88b      888            888  "Y8888   "Y888  88888P' 
//                                             .d88P                          
//                                           .d88P"                           
//                                          888P"                             
        double BtagBinary = 0.0;
        int nNotBjets = 0;
        int nBjets = 0;
        double AK4Pt = 0;
         for(unsigned int i=0; i<(*AK4JetLV_pt)->size() ;i++){
           //cout << AK4JetLV_pt->at(i) << endl;
          //printf("ak4 jets: %i\n", i);
           //if ((*AK4JetLV_pt)->at(i) < 30) break;



           BtagBinary = 0.0;
           if ((*AK4JetBtag)->at(i) > .62 ) BtagBinary = 1.0;

           (*AK4JetBtagBinary)->push_back(BtagBinary);

           AK4Pt = (*AK4JetLV_ptsmear)->at(i)*(*AK4JetLV_corr)->at(i)*(*AK4JetLV_pt)->at(i);

           temp.SetPtEtaPhiM(AK4Pt,(*AK4JetLV_eta)->at(i),(*AK4JetLV_phi)->at(i),(*AK4JetLV_mass)->at(i));
           (*AK4JetLV)->push_back(temp);

            if (verbose) printf("\tAK4   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", AK4Pt,(*AK4JetLV_eta)->at(i),(*AK4JetLV_phi)->at(i));
            if ( AK4Pt > 30 /*70*/ && abs((*AK4JetLV_eta)->at(i)) < 2.5 && BtagBinary){
                if(nBjets == 0){
                    TL_AK4_B_subJetPt.SetPtEtaPhiM(AK4Pt,(*AK4JetLV_eta)->at(i),(*AK4JetLV_phi)->at(i),(*AK4JetLV_mass)->at(i));
                }
                nBjets++;
            } else if ( AK4Pt > 30 && abs((*AK4JetLV_eta)->at(i)) < 2.5 ){
                nNotBjets++;
            }
          // printf("btag #: %f\n", (*AK4JetBtagBinary)->at(i));



   //
         }


//  888                       888                              
//  888                       888                              
//  888                       888                              
//  888      .d88b.  88888b.  888888 .d88b.  88888b.  .d8888b  
//  888     d8P  Y8b 888 "88b 888   d88""88b 888 "88b 88K      
//  888     88888888 888  888 888   888  888 888  888 "Y8888b. 
//  888     Y8b.     888 d88P Y88b. Y88..88P 888  888      X88 
//  88888888 "Y8888  88888P"   "Y888 "Y88P"  888  888  88888P' 
//                   888                                       
//                   888                                       
//                   888  

        double d_MuIso = -1;
        double d_MuIsoTrk = -1;                                                             
        int nMu = 0;

        //std::cout << "muon size " << (*MuPt)->size() << std::endl;
        for(unsigned int i=0; i<(*MuPt)->size() ;i++){
            if (verbose) printf("muon #: %f\n", (*MuPt)->at(i));
            if( (*MuPt)->at(i) > 1/*30*/ and (*MuPhi)->at(i) < 2.1){
                if(nMu ==0 ){
                    TL_Mu.SetPtEtaPhiM((*MuPt)->at(i), (*MuEta)->at(i), (*MuPhi)->at(i), 0.0);
                    d_MuIso = (*MuIso)->at(i);
                    //d_MuIsoTrk = (*MuIsoTrk)->at(i);

                }
                nMu++;
            }
        }
        int nEl = 0;
        for(unsigned int i=0; i<(*Electron_Pt)->size() ;i++){
            if (verbose) printf("muon #: %f\n", (*Electron_Pt)->at(i));
            if( (*Electron_Pt)->at(i) >  30 and (*Electron_Phi)->at(i) < 2.1){
                nEl++;
            }
        }
        int nLep = nMu + nEl;
   //

   

         //Print event number 
         //if (verbose) printf("Event #: %i %i %i\n", Nevt, (*AK4JetLV)->size(), (*AK4JetBtagBinary)->size());
         

         //Use helper function to create input list 
         //Create AK4 inputs object
         ttUtility::ConstAK4Inputs AK4Inputs = ttUtility::ConstAK4Inputs(**AK4JetLV, **AK4JetBtagBinary);

         //printf("Event #: %i %i %i %i %i %i\n", (*AK8JetLV)->size(),(*AK8SubjetLV_eta)->size(), (*tempAK8JetTau1)->size(),(*tempAK8JetTau2)->size(),(*tempAK8JetTau3)->size(),(*tempAK8JetSoftdropMass)->size());
         //Create AK8 inputs object
         ttUtility::ConstAK8Inputs AK8Inputs = ttUtility::ConstAK8Inputs(
             **AK8JetLV,
             **tempAK8JetTau1,
             **tempAK8JetTau2,
             **tempAK8JetTau3,
             **tempAK8JetSoftdropMass,
             **AK8SubjetLV
             );

         //Create jets constituents list combining AK4 and AK8 jets, these are used to construct top candiates
         //The vector of input constituents can also be constructed "by hand"
         std::vector<Constituent> constituents = ttUtility::packageConstituents(AK4Inputs, AK8Inputs);

         //run the top tagger
         tt.runTagger(constituents);

         //retrieve the top tagger results object
         const TopTaggerResults& ttr = tt.getResults();

         //get reconstructed top
         const std::vector<TopObject*>& tops = ttr.getTops();

         //print the number of tops found in the event 
         if (verbose) printf("\tN tops: %ld\n", tops.size());



      // Bjets:
       //    n = 1
       //    pt > 70
       //    eta bjet < 2.5
       // non bjet 
       //    n = 0
       //    pt > 30
       //    wta < 2.5
       //N(l) = 0
       //MET > 350
       //m(j,j,b) < 450



//   .d8888b.           888     .d888 888                        
//  d88P  Y88b          888    d88P"  888                        
//  888    888          888    888    888                        
//  888        888  888 888888 888888 888  .d88b.  888  888  888 
//  888        888  888 888    888    888 d88""88b 888  888  888 
//  888    888 888  888 888    888    888 888  888 888  888  888 
//  Y88b  d88P Y88b 888 Y88b.  888    888 Y88..88P Y88b 888 d88P 
//   "Y8888P"   "Y88888  "Y888 888    888  "Y88P"   "Y8888888P"  
//                                                               
//                                                               
//           





            int newCutFlowCount = cutflowCount;

            
            //TH1F_cutflow->Fill(newCutFlowCount);
            //newCutFlowCount++;


            float matchedRatio = TL_AK4_B_subJetPt.Pt()/(TL_Mu.Pt()+TL_AK4_B_subJetPt.Pt());

            float lep_b_Mt = (TL_Mu+TL_AK4_B_subJetPt).Mt();
            float lep_b_Pt = (TL_Mu+TL_AK4_B_subJetPt).Pt();

            float deltaPhi = (TL_Mu.DeltaPhi(TL_AK4_B_subJetPt));
            float transverseMass =  (TL_Mu+TL_AK4_B_subJetPt).Mt();

            TH1F_TL_AK4_B_subJetPt_zoomed_0->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_HadMETpt_zoomed_0->Fill(HadMETpt);
            TH1F_TL_top_Mass_zoomed_0->Fill(lep_b_Mt);
            TH1F_MuPt_zoomed_0->Fill(TL_Mu.Pt());
            TH1F_Mt_zoomed_0->Fill(transverseMass);
            TH1F_deltaR_zoomed_0->Fill(TL_Mu.DeltaR(TL_AK4_B_subJetPt));
            TH1F_MuISO_zoomed_0->Fill(d_MuIso);
            TH1F_MuISOTrk_zoomed_0->Fill(d_MuIsoTrk);

            TH1F_jetsNotAroundTop_0->Fill(nNotBjets);
            TH1F_nBjets_0->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_0->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_0->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_0->Fill(nLep);
            TH1F_HadMETpt_0->Fill(HadMETpt);
            TH1F_TL_top_Mass_0->Fill(lep_b_Mt);
            TH1F_TL_top_Pt_0->Fill(lep_b_Pt);
            TH1F_ratio_0->Fill(matchedRatio);

            TH1F_nMu_0->Fill(nMu);
            TH1F_MuPt_0->Fill(TL_Mu.Pt());
            TH1F_deltaPhi_0->Fill(deltaPhi);
            TH1F_Mt_0->Fill(transverseMass);
            TH1F_MuISO_0->Fill(d_MuIso);
            TH1F_MuISOTrk_0->Fill(d_MuIsoTrk);



            //std::cout << "==----=--=--" << std::endl;
            //for trigger (see above)
            if (not passTrig) continue;
            TH1F_cutflow->Fill(newCutFlowCount);
            newCutFlowCount++;
            if(verbose) std:: cout << "HLT" << std::endl;


            cutName.push_back("HLT");

            if (nBjets != 1) continue;
            if (TL_AK4_B_subJetPt.Pt() < 70) continue;
            if ( abs(TL_AK4_B_subJetPt.Eta()) > 2.5) continue;
            cutName.push_back("BJet");

            if(verbose) std:: cout << "BJet" << std::endl;

            TH1F_cutflow->Fill(newCutFlowCount);
            newCutFlowCount++;



            TH1F_jetsNotAroundTop_1->Fill(nNotBjets);
            TH1F_nBjets_1->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_1->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_1->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_1->Fill(nLep);
            TH1F_HadMETpt_1->Fill(HadMETpt);
            TH1F_TL_top_Mass_1->Fill(lep_b_Mt);
            TH1F_TL_top_Pt_1->Fill(lep_b_Pt);
            TH1F_ratio_1->Fill(matchedRatio);

            TH1F_nMu_1->Fill(nMu);
            TH1F_MuPt_1->Fill(TL_Mu.Pt());
            TH1F_deltaPhi_1->Fill(deltaPhi);
            TH1F_Mt_1->Fill(transverseMass);
            TH1F_MuISO_1->Fill(d_MuIso);
            TH1F_MuISOTrk_1->Fill(d_MuIsoTrk);



      
            if (nNotBjets > 2) continue;
            TH1F_cutflow->Fill(newCutFlowCount);
            cutName.push_back("non BJet");
            newCutFlowCount++;

            if(verbose) std:: cout << "non BJet" << std::endl;

            TH1F_jetsNotAroundTop_2->Fill(nNotBjets);
            TH1F_nBjets_2->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_2->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_2->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_2->Fill(nLep);
            TH1F_HadMETpt_2->Fill(HadMETpt);
            TH1F_TL_top_Mass_2->Fill(lep_b_Mt);
            TH1F_TL_top_Pt_2->Fill(lep_b_Pt);
            TH1F_ratio_2->Fill(matchedRatio);

            TH1F_nMu_2->Fill(nMu);
            TH1F_MuPt_2->Fill(TL_Mu.Pt());
            TH1F_deltaPhi_2->Fill(deltaPhi);
            TH1F_Mt_2->Fill(transverseMass);
            TH1F_MuISO_2->Fill(d_MuIso);
            TH1F_MuISOTrk_2->Fill(d_MuIsoTrk);

      

            if (nMu != 1) continue;
            TH1F_cutflow->Fill(newCutFlowCount);
            cutName.push_back("nMu != 1");
            newCutFlowCount++;

            if(verbose) std::cout << "nMu != 1" << std::endl;


            TH1F_jetsNotAroundTop_3->Fill(nNotBjets);
            TH1F_nBjets_3->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_3->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_3->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_3->Fill(nLep);
            TH1F_HadMETpt_3->Fill(HadMETpt);
            TH1F_TL_top_Mass_3->Fill(lep_b_Mt);
            TH1F_TL_top_Pt_3->Fill(lep_b_Pt);
            TH1F_ratio_3->Fill(matchedRatio);

            TH1F_nMu_3->Fill(nMu);
            TH1F_MuPt_3->Fill(TL_Mu.Pt());
            TH1F_deltaPhi_3->Fill(deltaPhi);
            TH1F_Mt_3->Fill(transverseMass);
            TH1F_MuISO_3->Fill(d_MuIso);
            TH1F_MuISOTrk_3->Fill(d_MuIsoTrk);


            if (abs(deltaPhi) > 1.7) continue;
            cutName.push_back("deltaPhi > 1.7");
            TH1F_cutflow->Fill(newCutFlowCount);
            newCutFlowCount++;

            if(verbose) std:: cout << "deltaPhi > 1.7" << std::endl;

            TH1F_jetsNotAroundTop_4->Fill(nNotBjets);
            TH1F_nBjets_4->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_4->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_4->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_4->Fill(nLep);
            TH1F_HadMETpt_4->Fill(HadMETpt);
            TH1F_TL_top_Mass_4->Fill(lep_b_Mt);
            TH1F_TL_top_Pt_4->Fill(lep_b_Pt);
            TH1F_ratio_4->Fill(matchedRatio);

            TH1F_nMu_4->Fill(nMu);
            TH1F_MuPt_4->Fill(TL_Mu.Pt());
            TH1F_deltaPhi_4->Fill(deltaPhi);
            TH1F_Mt_4->Fill(transverseMass);
            TH1F_MuISO_4->Fill(d_MuIso);
            TH1F_MuISOTrk_4->Fill(d_MuIsoTrk);


            if (d_MuIso > .15) continue;
            //if (TL_Mu.DeltaR(TL_AK4_B_subJetPt) < .3) continue;
            //if (d_MuIsoTrk > .05) continue; 
            cutName.push_back("muISO");
            TH1F_cutflow->Fill(newCutFlowCount);
            newCutFlowCount++;

            if(verbose) std:: cout << "muISO" << std::endl;

            TH1F_jetsNotAroundTop_5->Fill(nNotBjets);
            TH1F_nBjets_5->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_5->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_5->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_5->Fill(nLep);
            TH1F_HadMETpt_5->Fill(HadMETpt);
            TH1F_TL_top_Mass_5->Fill(lep_b_Mt);
            TH1F_TL_top_Pt_5->Fill(lep_b_Pt);
            TH1F_ratio_5->Fill(matchedRatio);

            TH1F_nMu_5->Fill(nMu);
            TH1F_MuPt_5->Fill(TL_Mu.Pt());
            TH1F_deltaPhi_5->Fill(deltaPhi);
            TH1F_Mt_5->Fill(transverseMass);
            TH1F_MuISO_5->Fill(d_MuIso);
            TH1F_MuISOTrk_5->Fill(d_MuIsoTrk);


                 
            if ( HadMETpt < 100) continue;
            cutName.push_back("met");
            TH1F_cutflow->Fill(newCutFlowCount);
            newCutFlowCount++;

            if(verbose) std:: cout << "met" << std::endl;

            TH1F_jetsNotAroundTop_6->Fill(nNotBjets);
            TH1F_nBjets_6->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_6->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_6->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_6->Fill(nLep);
            TH1F_HadMETpt_6->Fill(HadMETpt);
            TH1F_TL_top_Mass_6->Fill(lep_b_Mt);
            TH1F_TL_top_Pt_6->Fill(lep_b_Pt);
            TH1F_ratio_6->Fill(matchedRatio);

            TH1F_nMu_6->Fill(nMu);
            TH1F_MuPt_6->Fill(TL_Mu.Pt());
            TH1F_deltaPhi_6->Fill(deltaPhi);
            TH1F_Mt_6->Fill(transverseMass);
            TH1F_MuISO_6->Fill(d_MuIso);
            TH1F_MuISOTrk_6->Fill(d_MuIsoTrk);


            
            if ( transverseMass < 400) continue;
            cutName.push_back("transverseMass");
            TH1F_cutflow->Fill(newCutFlowCount);
            newCutFlowCount++;

            if(verbose) std:: cout << "transverseMass" << std::endl;


            TH1F_jetsNotAroundTop_7->Fill(nNotBjets);
            TH1F_nBjets_7->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_7->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_7->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_7->Fill(nLep);
            TH1F_HadMETpt_7->Fill(HadMETpt);
            TH1F_TL_top_Mass_7->Fill(lep_b_Mt);
            TH1F_TL_top_Pt_7->Fill(lep_b_Pt);
            TH1F_ratio_7->Fill(matchedRatio);

            TH1F_nMu_7->Fill(nMu);
            TH1F_MuPt_7->Fill(TL_Mu.Pt());
            TH1F_deltaPhi_7->Fill(deltaPhi);
            TH1F_Mt_7->Fill(transverseMass);
            TH1F_MuISO_7->Fill(d_MuIso);
            TH1F_MuISOTrk_7->Fill(d_MuIsoTrk);


      
          
             TH1F_had_AK4b_pt->Fill(TL_AK4_B_subJetPt.Pt());
             TH1F_gen_Ratio_After_Tag->Fill(gen_ratio);
             TH1F_had_Ratio->Fill(matchedRatio);


         //Print properties of the remaining system
         //the remaining system is used as the second portion of the visible system to calculate MT2 in the NT = 1 bin
         const TopObject& rsys = ttr.getRsys();
         if (verbose) printf("\tRsys properties: N constituents: %3d,   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", rsys.getNConstituents(), rsys.p().Pt(), rsys.p().Eta(), rsys.p().Phi());
     //
         if (verbose) printf("\n");

     }

   }
   catch(const TTException& e)
   {
       //Print exception message
       e.print();
       printf("Terminating run\n");
       fflush(stdout);
   }
   
   
   //TH1F_gen_E_ratio_SUSY_top->Draw();
   //c1.SaveAs("TH1F_gen_E_ratio_SUSY_top_LH.png");
   //TH1F_gen_deltaR_SUSY_top->Draw();
   //c1.SaveAs("TH1F_gen_deltaR_SUSY_top_LH.png");
   //TH1F_had_SUSY_pt->Draw();
   //c1.SaveAs("TH1F_had_SUSY_pt_LH.png");
   //TH1F_had_AK4b_pt->Draw();
   //c1.SaveAs("TH1F_had_AK4b_pt_LH.png");
   //TH1F_gen_Ratio->Draw();
   //c1.SaveAs("TH1F_gen_Ratio_LH.png");
   //TH1F_gen_Ratio_After_Tag->Draw();
   //c1.SaveAs("TH1F_gen_Ratio_After_Tag_LH.png");
   //TH1F_had_Ratio->Draw();
   //c1.SaveAs("TH1F_had_Ratio_LH.png");
//
   //TH1F_one_gen_Ratio_After_Tag->Draw();
   //c1.SaveAs("TH1F_one_gen_Ratio_After_Tag_LH.png");
   //TH1F_one_had_Ratio->Draw();
   //c1.SaveAs("TH1F_one_had_Ratio_LH.png");
//
   //TH1F_two_gen_Ratio_After_Tag->Draw();
   //c1.SaveAs("TH1F_two_gen_Ratio_After_Tag_LH.png");
   //TH1F_two_had_Ratio->Draw();
   //c1.SaveAs("TH1F_two_had_Ratio_LH.png");
//
   //TH1F_three_gen_Ratio_After_Tag->Draw();
   //c1.SaveAs("TH1F_three_gen_Ratio_After_Tag_LH.png");
   //TH1F_three_had_Ratio->Draw();
   //c1.SaveAs("TH1F_three_had_Ratio_LH.png");

  hadMonoTopLoopHists->Write();
  hadMonoTopLoopHists->Close();

  /*for(int i =1; i <= cutName.size();i++){
    std::cout << cutName[i] << " " << TH1F_cutflow->GetBinContent(i) << std::endl;
  }*/

    //clean up pointers 
 //  delete AK4JetLV;
 //  delete AK4JetBtag;
 //  delete AK8JetLV;
 //  delete AK8SubjetLV;
 //  delete AK8JetTau1;
 //  delete AK8JetTau2;
 //  delete AK8JetTau3;
 //  delete AK8JetSoftdropMass;
 //  delete AK4JetBtagBinary;
}
