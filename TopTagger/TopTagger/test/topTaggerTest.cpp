#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

#include "TFile.h"
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
     
     
    TFile *tf = TFile::Open(inputFile.c_str()); //2 is LH mt_had_2tev_rh_miniaod.root mt_had_2tev_lh_miniaod.root
    TFile* hadMonoTopLoopHists  = new TFile(outputFile.c_str(), "RECREATE");
    //TFile *tf = TFile::Open("exampleInputs.root");

    //Get tree from file
    TTree *tree = (TTree*)tf->Get("ana/TreeHad");
    printf("Event #: %i\n", tree->GetEntries());

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
    std::vector<double>** AK8JetLV_pt = new std::vector<double>*();
    std::vector<double>** AK8JetLV_eta = new std::vector<double>*();
    std::vector<double>** AK8JetLV_phi = new std::vector<double>*();
    std::vector<double>** AK8JetLV_mass = new std::vector<double>*();
    
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


    std::vector<float>** MuPt = new std::vector<float>*();
    tree->SetBranchStatus("MuPt", 1);
    tree->SetBranchAddress("MuPt", MuPt);

    std::vector<float>** MuPhi = new std::vector<float>*();
    tree->SetBranchStatus("MuPhi", 1);
    tree->SetBranchAddress("MuPhi", MuPhi);

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

    Float_t had_ratio; 
    Float_t gen_ratio; 

    Int_t nBins = 50;

    Float_t maxPt = 1000;
    Float_t bTagMax = 0;

    TH1F* TH1F_cutflow = new TH1F("TH1F_cutflow", "Cutflow ;  Cuts ; count", 10, -.5, 9.5);

    TCanvas c1;
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

 

    Int_t nConstituents;

    //try-catch on TTException which are thrown by the top tagger
   try
   {
       
       //Set top tagger cfg file
       tt.setCfgFile("TopTagger.cfg");

     //Loop over events
     int Nevt = 0;
      printf("test 1");
      printf("tree entries: %i\n",  tree->GetEntries());
     while(tree->GetEntry(Nevt))
     {
         
             TL_Gen_Top.SetPtEtaPhiM(Gen_array_t_p4[0], Gen_array_t_p4[1], Gen_array_t_p4[2], Gen_array_t_p4[3]);
             TL_Gen_b.SetPtEtaPhiM(Gen_array_b_p4[0], Gen_array_b_p4[1],Gen_array_b_p4[2],Gen_array_b_p4[3]);
             TL_Gen_W.SetPtEtaPhiM(Gen_array_W_p4[0], Gen_array_W_p4[1],Gen_array_W_p4[2],Gen_array_W_p4[3]);
             //had_ratio = TL_AK4_B_subJetPt.E()/TL_AK4.E();
             gen_ratio = TL_Gen_b.E()/TL_Gen_Top.E();
             TH1F_gen_Ratio->Fill(gen_ratio);

         //increment event number
         ++Nevt;
         AK8JetLV_p->clear();
         AK4JetLV_p->clear();
         AK8SubjetLV_p->clear();
         AK4JetBtagBinary_p->clear();
         if (verbose) printf("ak8 jets size: %i\n",  (*AK8JetLV_pt)->size());


         for(unsigned int i=0; i<(*AK8JetLV_pt)->size() ;i++){
           //printf("ak8 jets: %i\n", i);
           temp.SetPtEtaPhiM( (*AK8JetLV_pt)->at(i),(*AK8JetLV_eta)->at(i),(*AK8JetLV_phi)->at(i),(*AK8JetLV_mass)->at(i));
          // printf("ak8 jets: %4.2f \n", (*AK8JetLV_pt)->at(i));
           (*AK8JetLV)->push_back(temp);
         }


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
         for(unsigned int i=0; i<(*AK4JetLV_pt)->size() ;i++){
           //cout << AK4JetLV_pt->at(i) << endl;
          //printf("ak4 jets: %i\n", i);
           //if ((*AK4JetLV_pt)->at(i) < 30) break;



           BtagBinary = 0.0;
           if ((*AK4JetBtag)->at(i) > .62 ) BtagBinary = 1.0;

           (*AK4JetBtagBinary)->push_back(BtagBinary);
           temp.SetPtEtaPhiM((*AK4JetLV_pt)->at(i),(*AK4JetLV_eta)->at(i),(*AK4JetLV_phi)->at(i),(*AK4JetLV_mass)->at(i));
           (*AK4JetLV)->push_back(temp);

            if ( (*AK4JetLV_pt)->at(i) > 70 && abs((*AK4JetLV_eta)->at(i)) < 2.5 && BtagBinary){
                nBjets++;
            } else if ( (*AK4JetLV_pt)->at(i) > 30 && abs((*AK4JetLV_eta)->at(i)) < 2.5 ){
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
        int nMu = 0;
        for(unsigned int i=0; i<(*MuPt)->size() ;i++){
            if (verbose) printf("muon #: %f\n", (*MuPt)->at(i));
            if( (*MuPt)->at(i) > 30 and (*MuPhi)->at(i) < 2.1){
                nMu++;
            }
        }
        int nEl = 0;
        for(unsigned int i=0; i<(*Electron_Pt)->size() ;i++){
            if (verbose) printf("muon #: %f\n", (*Electron_Pt)->at(i));
            if( (*Electron_Pt)->at(i) > 30 and (*Electron_Phi)->at(i) < 2.1){
                nEl++;
            }
        }
        int nLep = nMu + nEl;
   //
         for(unsigned int i=0; i<(*AK8SubjetLV_pt)->size() ;i++){
           //cout << AK8SubjetLV_pt->at(i) << endl;
           //if ((*AK8JetLV_pt)->at(i) < 200) break;
           temp.SetPtEtaPhiM((*AK8SubjetLV_pt)->at(i),(*AK8SubjetLV_eta)->at(i),(*AK8SubjetLV_phi)->at(i),(*AK8SubjetLV_mass)->at(i));
           (*AK8SubjetLV)->push_back(temp);
           
         }
   

         //Print event number 
         if (verbose) printf("Event #: %i %i %i\n", Nevt, (*AK4JetLV)->size(), (*AK4JetBtagBinary)->size());

         //Use helper function to create input list 
         //Create AK4 inputs object
         ttUtility::ConstAK4Inputs AK4Inputs = ttUtility::ConstAK4Inputs(**AK4JetLV, **AK4JetBtagBinary);

         //Create AK8 inputs object
         ttUtility::ConstAK8Inputs AK8Inputs = ttUtility::ConstAK8Inputs(
             **AK8JetLV,
             **AK8JetTau1,
             **AK8JetTau2,
             **AK8JetTau3,
             **AK8JetSoftdropMass,
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

//  88888888888                         
//      888                             
//      888                             
//      888   .d88b.  88888b.  .d8888b  
//      888  d88""88b 888 "88b 88K      
//      888  888  888 888  888 "Y8888b. 
//      888  Y88..88P 888 d88P      X88 
//      888   "Y88P"  88888P"   88888P' 
//                    888               
//                    888               
//                    888               

         TLorentzVector TL_top;
         int topCount = 0;
         int nTopConstuents = 0;
         int jetsNotAroundTop = 0;
         //print top properties
         for(const TopObject* top : tops)
         {
             //print basic top properties (top->p() gives a TLorentzVector)
             //N constituents refers to the number of jets included in the top
             //3 for resolved tops 
             //2 for W+jet tops
             //1 for fully merged AK8 tops
             if (verbose) printf("\tTop properties: N constituents: %3d,   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", top->getNConstituents(), top->p().Pt(), top->p().Eta(), top->p().Phi());
             if (verbose) printf("\tGen Top properties: Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf\n", TL_Gen_Top.Pt(),TL_Gen_Top.Eta(), TL_Gen_Top.Phi());
             //get vector of top constituents 
             const std::vector<Constituent const *>& constituents = top->getConstituents();


             if (topCount ==0) {

                TH1F_gen_E_ratio_SUSY_top->Fill( top->p().E()/TL_Gen_Top.E());
                TH1F_gen_deltaR_SUSY_top->Fill( top->p().DeltaR(TL_Gen_Top));
                TH1F_had_SUSY_pt->Fill( top->p().Pt());
    
                nConstituents = 0;
                //Print properties of individual top constituent jets 
                for(const Constituent* constituent : constituents)
                {
                    nConstituents++;
                    if (verbose) printf("\t\tConstituent properties: Constituent type: %3d,   Pt: %6.1lf,   Eta: %7.3lf,   Phi: %7.3lf, nConstituents: %3i \n", constituent->getType(), constituent->p().Pt(), constituent->p().Eta(), constituent->p().Phi(), nConstituents);
                }    
    
                nTopConstuents = nConstituents;

                if(nConstituents ==1){
                    TH1F_one_gen_Ratio_After_Tag->Fill(gen_ratio);
                    TH1F_one_had_Ratio->Fill(TL_AK4_B_subJetPt.E()/top->p().E());
    
                    TH1F_one_gen_pT_After_Tag->Fill(TL_Gen_Top.Pt());
                    TH1F_one_had_pT->Fill(top->p().Pt());
                }
                if(nConstituents ==2){
                    TH1F_two_gen_Ratio_After_Tag->Fill(gen_ratio);
                    TH1F_two_had_Ratio->Fill(TL_AK4_B_subJetPt.E()/top->p().E());
    
                    TH1F_two_gen_pT_After_Tag->Fill(TL_Gen_Top.Pt());
                    TH1F_two_had_pT->Fill(top->p().Pt());
                }
                if(nConstituents ==3){
                    TH1F_three_gen_Ratio_After_Tag->Fill(gen_ratio);
                    TH1F_three_had_Ratio->Fill(TL_AK4_B_subJetPt.E()/top->p().E());
    
                    TH1F_three_gen_pT_After_Tag->Fill(TL_Gen_Top.Pt());
                    TH1F_three_had_pT->Fill(top->p().Pt());
                }

               TL_top.SetPtEtaPhiM(top->p().Pt(), top->p().Eta(), top->p().Phi(), top->p().M() );
              bTagMax = 0;
                for (uint i = 0; i < (*AK4JetLV)->size(); i++){
                    if( (*AK4JetLV)->at(i).DeltaR(top->p()) < 2*172/top->p().Pt() ){
                        if ((*AK4JetBtag)->at(i) > bTagMax){
                            TL_AK4_B_subJetPt.SetPtEtaPhiM((*AK4JetLV)->at(i).Pt(),(*AK4JetLV)->at(i).Eta(),(*AK4JetLV)->at(i).Phi(),(*AK4JetLV)->at(i).M());
                            bTagMax = (*AK4JetBtag)->at(i);
                        }
                        if (verbose) printf("\t\tAK4 properties: Pt: %6.1lf  BTag: %7.3lf\n" ,(*AK4JetLV)->at(i).Pt(),  (*AK4JetBtag)->at(i));
                    } else if ( (*AK4JetLV)->at(i).Pt() > 30  and abs((*AK4JetLV)->at(i).Eta()) < 2.5 ){
                      jetsNotAroundTop++;

                    }
                }
                if (verbose) printf("\t\t\t Gen b properties: Pt: %6.1lf  BTag: %7.3lf\n" ,TL_Gen_b.Pt(),  bTagMax);
                if (verbose) printf("\t\t\t AK4 b properties: Pt: %6.1lf  BTag: %7.3lf\n" ,TL_AK4_B_subJetPt.Pt(),  bTagMax);
             }

             
             topCount++;



         }

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




            int cutflowCount = 0;                                 
             TH1F_cutflow->Fill(cutflowCount);
             cutflowCount++;

            float matchedRatio = TL_AK4_B_subJetPt.E()/TL_top.E();

            TH1F_topCount_0->Fill(topCount);
            TH1F_jetsNotAroundTop_0->Fill(jetsNotAroundTop);
            TH1F_nBjets_0->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_0->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_0->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_0->Fill(nLep);
            TH1F_HadMETpt_0->Fill(HadMETpt);
            TH1F_TL_top_Mass_0->Fill(TL_top.M());
            TH1F_TL_top_Pt_0->Fill(TL_top.Pt());
            TH1F_ratio_0->Fill(matchedRatio);



             if (verbose) printf("\tjetsNotAroundTop vs top constituents vs n tops: %3d, %3d, %3d \n",jetsNotAroundTop, nTopConstuents, topCount);
             if (topCount != 1) continue;
             TH1F_cutflow->Fill(cutflowCount);
             cutflowCount++;

            
             if (jetsNotAroundTop > 1 ) continue;
             TH1F_cutflow->Fill(cutflowCount);
             cutflowCount++;

            TH1F_topCount_1->Fill(topCount);
            TH1F_jetsNotAroundTop_1->Fill(jetsNotAroundTop);
            TH1F_nBjets_1->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_1->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_1->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_1->Fill(nLep);
            TH1F_HadMETpt_1->Fill(HadMETpt);
            TH1F_TL_top_Mass_1->Fill(TL_top.M());
            TH1F_TL_top_Pt_1->Fill(TL_top.Pt());
            TH1F_ratio_1->Fill(matchedRatio);


      
             if (nBjets != 1) continue;
             if (TL_AK4_B_subJetPt.Pt() < 70) continue;
             if ( abs(TL_AK4_B_subJetPt.Eta()) > 2.5) continue;
             TH1F_cutflow->Fill(cutflowCount);
             cutflowCount++;

            TH1F_topCount_2->Fill(topCount);
            TH1F_jetsNotAroundTop_2->Fill(jetsNotAroundTop);
            TH1F_nBjets_2->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_2->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_2->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_2->Fill(nLep);
            TH1F_HadMETpt_2->Fill(HadMETpt);
            TH1F_TL_top_Mass_2->Fill(TL_top.M());
            TH1F_TL_top_Pt_2->Fill(TL_top.Pt());
            TH1F_ratio_2->Fill(matchedRatio);
      
             if (nLep > 0) continue;
             TH1F_cutflow->Fill(cutflowCount);
             cutflowCount++;


            TH1F_topCount_3->Fill(topCount);
            TH1F_jetsNotAroundTop_3->Fill(jetsNotAroundTop);
            TH1F_nBjets_3->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_3->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_3->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_3->Fill(nLep);
            TH1F_HadMETpt_3->Fill(HadMETpt);
            TH1F_TL_top_Mass_3->Fill(TL_top.M());
            TH1F_TL_top_Pt_3->Fill(TL_top.Pt());
            TH1F_ratio_3->Fill(matchedRatio);
                  
             if ( HadMETpt < 350) continue;
             TH1F_cutflow->Fill(cutflowCount);
             cutflowCount++;

            TH1F_topCount_4->Fill(topCount);
            TH1F_jetsNotAroundTop_4->Fill(jetsNotAroundTop);
            TH1F_nBjets_4->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_4->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_4->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_4->Fill(nLep);
            TH1F_HadMETpt_4->Fill(HadMETpt);
            TH1F_TL_top_Mass_4->Fill(TL_top.M());
            TH1F_TL_top_Pt_4->Fill(TL_top.Pt());
            TH1F_ratio_4->Fill(matchedRatio);
      
             if ( TL_top.M() > 450) continue;
             TH1F_cutflow->Fill(cutflowCount);
             cutflowCount++;


            TH1F_topCount_5->Fill(topCount);
            TH1F_jetsNotAroundTop_5->Fill(jetsNotAroundTop);
            TH1F_nBjets_5->Fill(nBjets);
            TH1F_TL_AK4_B_subJetPt_5->Fill(TL_AK4_B_subJetPt.Pt());
            TH1F_TL_AK4_B_subJetEta_5->Fill(TL_AK4_B_subJetPt.Eta());
            TH1F_nLep_5->Fill(nLep);
            TH1F_HadMETpt_5->Fill(HadMETpt);
            TH1F_TL_top_Mass_5->Fill(TL_top.M());
            TH1F_TL_top_Pt_5->Fill(TL_top.Pt());
            TH1F_ratio_5->Fill(matchedRatio);
      
          
             TH1F_had_AK4b_pt->Fill(TL_AK4_B_subJetPt.Pt());
             TH1F_gen_Ratio_After_Tag->Fill(gen_ratio);
             TH1F_had_Ratio->Fill(TL_AK4_B_subJetPt.E()/TL_top.E());


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
   
   
   TH1F_gen_E_ratio_SUSY_top->Draw();
   c1.SaveAs("TH1F_gen_E_ratio_SUSY_top_LH.png");
   TH1F_gen_deltaR_SUSY_top->Draw();
   c1.SaveAs("TH1F_gen_deltaR_SUSY_top_LH.png");
   TH1F_had_SUSY_pt->Draw();
   c1.SaveAs("TH1F_had_SUSY_pt_LH.png");
   TH1F_had_AK4b_pt->Draw();
   c1.SaveAs("TH1F_had_AK4b_pt_LH.png");
   TH1F_gen_Ratio->Draw();
   c1.SaveAs("TH1F_gen_Ratio_LH.png");
   TH1F_gen_Ratio_After_Tag->Draw();
   c1.SaveAs("TH1F_gen_Ratio_After_Tag_LH.png");
   TH1F_had_Ratio->Draw();
   c1.SaveAs("TH1F_had_Ratio_LH.png");

   TH1F_one_gen_Ratio_After_Tag->Draw();
   c1.SaveAs("TH1F_one_gen_Ratio_After_Tag_LH.png");
   TH1F_one_had_Ratio->Draw();
   c1.SaveAs("TH1F_one_had_Ratio_LH.png");

   TH1F_two_gen_Ratio_After_Tag->Draw();
   c1.SaveAs("TH1F_two_gen_Ratio_After_Tag_LH.png");
   TH1F_two_had_Ratio->Draw();
   c1.SaveAs("TH1F_two_had_Ratio_LH.png");

   TH1F_three_gen_Ratio_After_Tag->Draw();
   c1.SaveAs("TH1F_three_gen_Ratio_After_Tag_LH.png");
   TH1F_three_had_Ratio->Draw();
   c1.SaveAs("TH1F_three_had_Ratio_LH.png");

  hadMonoTopLoopHists->Write();
  hadMonoTopLoopHists->Close();

    //clean up pointers 
   delete AK4JetLV;
   delete AK4JetBtag;
   delete AK8JetLV;
   delete AK8SubjetLV;
   delete AK8JetTau1;
   delete AK8JetTau2;
   delete AK8JetTau3;
   delete AK8JetSoftdropMass;
   delete AK4JetBtagBinary;
}
