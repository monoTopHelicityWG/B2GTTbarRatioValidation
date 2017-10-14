#define HadTree_Oct_12_17_cxx
#include "HadTree_Oct_12_17.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <iostream>

void HadTree_Oct_12_17::Loop(std::string outFileName, Bool_t gen)
{
//   In a ROOT session, you can do:
//      root> .L HadTree_Oct_12_17.C
//      root> HadTree_Oct_12_17 t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   TFile* hadMonoTopLoopHists  = new TFile(outFileName.c_str(), "RECREATE");

   const int nBins = 100;
   const int entry_count_constant = 1000;

   TH1F* TH1F_had_AK8Puppi_SD_pt = new TH1F("TH1F_had_AK8Puppi_SD_pt", "AK8 Puppi SD p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_AK8Puppi_SD_mass = new TH1F("TH1F_had_AK8Puppi_SD_mass", "AK8 Puppi SD Mass; Mass [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_AK8Puppi_pt = new TH1F("TH1F_had_AK8Puppi_pt", "AK8 Puppi p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_AK8Puppi_mass = new TH1F("TH1F_had_AK8Puppi_mass", "AK8 Puppi Mass; Mass [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_LF_subJetPt = new TH1F("TH1F_had_LF_subJetPt", "Light Flavor Subjet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_B_subJetPt = new TH1F("TH1F_had_B_subJetPt", "Heavy (b) Flavor Subjet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_Ratio = new TH1F("TH1F_had_Ratio", "Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
   TH1F* TH1F_had_deltaR = new TH1F("TH1F_had_deltaR", "#delta R BJet and Top; #theta_{Tb}; count", nBins, 0, 1.5 );

   TH1F* TH1F_had_difference = new TH1F("TH1F_had_difference", "(E(b)-E(W))/E(T);  (E(b)-E(W))/E(T); count", nBins, -1, 1 );
   TH2F* TH2F_bTau21_ratio = new TH2F("TH2F_bTau21_ratio", "Subjet b #Tau_{2}/#Tau_{1}vs. Ratio: E(b)/E(t); Subjet b #Tau_{2}/#Tau_{1};  E(b)/E(t)", nBins, 0, 1, nBins, 0, 1 );
   TH2F* TH2F_bTau21_WTau21 = new TH2F("TH2F_bTau21_WTau21", "Subjet b #Tau_{2}/#Tau_{1} vs.Subjet W #Tau_{2}/#Tau_{1}; Subjet b #Tau_{2}/#Tau_{1};  Subjet W #Tau_{2}/#Tau_{1}", nBins, 0, 1, nBins, 0, 1 );

   TH1F* TH1F_had_difference_WTau21_btau21 = new TH1F("TH1F_had_difference_WTau21_btau21", "(W #Tau_{2}/#Tau_{1}-b #Tau_{2}/#Tau_{1});  (W #Tau_{2}/#Tau_{1}-b #Tau_{2}/#Tau_{1}); count", nBins, -1, 1 );

   TH1F* TH1F_had_difference_ratio_btau21 = new TH1F("TH1F_had_difference_ratio_btau21", "(E(b)/E(T)-#Tau_{2}/#Tau_{1});  (E(b)/E(T)-#Tau_{2}/#Tau_{1}); count", nBins, -1, 1 );
   TH1F* TH1F_had_sum_ratio_btau21 = new TH1F("TH1F_had_sum_ratio_btau21", "(E(b)/E(T)+#Tau_{2}/#Tau_{1});  (E(b)/E(T)+#Tau_{2}/#Tau_{1}); count", nBins, 0, 2 );
   

    TH2F* TH2F_leading_tau21_ratio = new TH2F("TH2F_leading_tau21_ratio", "Leading Subjet #Tau_{2}/#Tau_{1}vs. Ratio: E(b)/E(t); Leading Subjet  #Tau_{2}/#Tau_{1};  E(b)/E(t)", nBins, 0, 1, nBins, 0, 1 );


   TH2F* TH2F_bTau21_ratio_rotated = new TH2F("TH2F_bTau21_ratio_rotated", "Subjet b #Tau_{2}/#Tau_{1}vs. Ratio: E(b)/E(t) rotated; Subjet b #Tau_{2}/#Tau_{1};  E(b)/E(t)", nBins, -1, 1, nBins, 0, 1 );

   TH1F* TH1F_had_ratio_deltaR_ratio = new TH1F("TH1F_had_ratio_deltaR_ratio", "E(b)/(E(t)) -delta R BJet and Top; E(b)/E(t) -#theta_{Tb}; count", nBins, -.4, 1.4 );


   TH1F* TH1F_puppi_ECF1 = new TH1F("TH1F_puppi_ECF1", "ECF1 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 1000 );
   TH1F* TH1F_puppi_ECF2 = new TH1F("TH1F_puppi_ECF2", "ECF2 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 100000 );
   TH1F* TH1F_puppi_ECF3 = new TH1F("TH1F_puppi_ECF3", "ECF3 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 3000000 );
   TH1F* TH1F_puppi_ECF4 = new TH1F("TH1F_puppi_ECF4", "ECF4 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 20000000 );
   TH1F* TH1F_puppi_ECF5 = new TH1F("TH1F_puppi_ECF5", "ECF5 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 200000000 );

   TH1F* TH1F_puppi_ECF_C2 = new TH1F("TH1F_puppi_ECF_C2", "ECF C_{2} #beta = 1 of Puppi SD jet; C_{2}; count", nBins, 0, .002 );
   TH1F* TH1F_puppi_ECF_D2 = new TH1F("TH1F_puppi_ECF_D2", "ECF D_{2} #beta = 1 of Puppi SD jet; D_{2}; count", nBins, 0, .0000001 );
   TH1F* TH1F_puppi_ECF_C3 = new TH1F("TH1F_puppi_ECF_C3", "ECF C_{3} #beta = 1 of Puppi SD jet; C_{3}; count", nBins, 0, .00003 );
   TH1F* TH1F_puppi_ECF_D3 = new TH1F("TH1F_puppi_ECF_D3", "ECF D_{3} #beta = 1 of Puppi SD jet; D_{3}; count", nBins, 0, .00000000006 );

   TH1F* TH1F_puppi_subb_tau32 = new TH1F("TH1F_puppi_sub0_tau32", "Subjet b #Tau_{3}/#Tau_{2};#Tau_{3}/#Tau_{2}", nBins, 0, 1 );
   TH1F* TH1F_puppi_subb_tau21 = new TH1F("TH1F_puppi_sub0_tau21", "Subjet b #Tau_{2}/#Tau_{1};#Tau_{2}/#Tau_{1} ; count", nBins, 0, 1 );
   TH1F* TH1F_puppi_subLF_tau32 = new TH1F("TH1F_puppi_sub1_tau32", "Subjet W #Tau_{3}/#Tau_{2};#Tau_{3}/#Tau_{2}", nBins, 0, 1 );
   TH1F* TH1F_puppi_subLF_tau21 = new TH1F("TH1F_puppi_sub1_tau21", "Subjet W #Tau_{2}/#Tau_{1};#Tau_{2}/#Tau_{1} ; count", nBins, 0, 1 );




   TH1F* TH1F_puppi_Tau32 = new TH1F("TH1F_puppi_Tau32", "#Tau_{3}/#Tau_{2};#Tau_{3}/#Tau_{2} ; count", nBins, 0, 1 );
   TH1F* TH1F_puppi_Tau21 = new TH1F("TH1F_puppi_Tau21", "#Tau_{2}/#Tau_{1};#Tau_{2}/#Tau_{1} ; count", nBins, 0, 1 );

   TH2F* TH2F_deltaR_ratio = new TH2F("TH2F_deltaR_ratio", "#delta R BJet and Top vs. Ratio: E(b)/E(t); #theta_{Tb};  E(b)/E(t)", nBins, 0, 1, nBins, 0, 1.6 );

   TH1F* TH1F_maxbdisc_Puppi_SD = new TH1F("TH1F_maxbdisc_Puppi_SD", "Max bDisc SD; bdisc; count", nBins, 0, 1.1 );
   TH1F* TH1F_maxbdisc_SD = new TH1F("TH1F_maxbdisc_SD", "Max bDisc; bdisc; count", nBins, 0, 1.1 );

   TH1F* TH1F_gen_had_AK8Puppi_SD_pt = new TH1F("TH1F_gen_had_AK8Puppi_pt", "Gen AK8 Puppi SD p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_gen_had_AK8Puppi_SD_mass = new TH1F("TH1F_gen_had_AK8Puppi_mass", "Gen AK8 Puppi SD Mass; Mass [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_gen_had_LF_subJetPt = new TH1F("TH1F_gen_had_LF_subJetPt", "Gen Light Flavor Subjet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_gen_had_B_subJetPt = new TH1F("TH1F_gen_had_B_subJetPt", "Gen Heavy (b) Flavor Subjet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_gen_had_Ratio = new TH1F("TH1F_gen_had_Ratio", "Gen Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
   TH1F* TH1F_gen_had_deltaR = new TH1F("TH1F_gen_had_deltaR", "Gen #delta R BJet and Top; #theta_{Tb}; count", nBins, 0, 1.5 );

  
   TH2F* TH2F_pt_SD_mass = new TH2F("TH2F_pt_SD_mass", "SD p_{T} vs SD AK8 Jet Mass; Gen p_{T}; Raw Mass [GeV]", nBins, 0, 1500, nBins, 0, 500 );
   //gen level plots
   TH2F* TH2F_gen_pt_raw_mass = new TH2F("TH2F_gen_pt_raw_mass", "Gen p_{T} vs Raw AK8 Jet Mass; Gen p_{T}; Raw Mass [GeV]", nBins, 0, 1000, nBins, 0, 500 );
   TH2F* TH2F_gen_mass_raw_mass = new TH2F("TH2F_gen_mass_raw_mass", "Gen Mass vs Raw AK8 Jet Mass; Gen Mass; Raw Mass [GeV]", nBins, 0, 1000, nBins, 0, 500 );
   TH2F* TH2F_gen_pt_raw_pt = new TH2F("TH2F_gen_pt_raw_pt", "Gen p_{T} vs Raw AK8 Jet p_{T}; Gen p_{T}; Raw p_{T} [GeV]", nBins, 0, 1000, nBins, 0, 1000 );
   TH2F* TH2F_gen_pt_top_matched = new TH2F("TH2F_gen_pt_top_matched", "Gen p_{T} vs Top Matched; Gen p_{T}; Top Matched", nBins, 0, 1000, 2, 0, 1 );
   TH2F* TH2F_gen_ratio_puppi_ratio = new TH2F("TH2F_gen_ratio_puppi_ratio", "Gen Ratio = E(b)/E(t) vs Puppi Subjets; Gen; MC", nBins, 0, 1.5, nBins, 0, 1.5 );
   TH2F* TH2F_gen_deltaR_puppi_deltaR = new TH2F("TH2F_gen_deltaR_puppi_deltaR", "Gen Delta R between b and Top vs puppi; Gen; MC", nBins, 0, 1.5, nBins, 0, 1.5 );

   TH2F* TH2F_b_deltaR_gen_AK4_top_pt = new TH2F("TH2F_b_deltaR_gen_AK4", " Delta R between Gen b and AK4 b vs Top p_{T}; #delta_{R}(Gen, AK4); Gen Top p_{T}", nBins, 0, 1.5, nBins, 0, 700 );
   TH2F* TH2F_b_ratio_gen_AK4_top_pt = new TH2F("TH2F_b_ratio_gen_AK4_top_pt", "E(b_{gen})/E(b_{AK4}) vs Top p_{T}; #E(b_{gen})/E(b_{AK4}); Gen Top p_{T}", nBins, 0, 5, nBins, 0, 700 );
   TH2F* TH2F_Top_ratio_gen_AK4_top_pt = new TH2F("TH2F_Top_ratio_gen_AK4_top_pt", "E(t_{gen})/E(t_{AK4}) vs Top p_{T}; #E(t_{gen})/E(t_{AK4}); Gen Top p_{T}", nBins, 0, 2, nBins, 0, 700 );
   TH2F* TH2F_Top_deltaR_gen_AK4_top_pt = new TH2F("TH2F_Top_deltaR_gen_AK4_top_pt", " Delta R between Gen t and AK4 t vs Top p_{T}; #delta_{R}(Gen, AK4); Gen Top p_{T}", nBins, 0, 1.5, nBins, 0, 700 );
   TH2F* TH2F_Top_gen_ratio_AK4_ratio = new TH2F("TH2F_Top_gen_ratio_AK4_ratio", "E(b})/E(t) Gen vs AK4 ; Gen; Ak4", nBins, 0, 1.2, nBins, 0, 1.2 );
   TH2F* TH2F_Top_gen_deltaR_AK4_ratio = new TH2F("TH2F_Top_gen_deltaR_AK4_ratio", "#delta_{R} Gen vs AK4 ; Gen; Ak4", nBins, 0, 1.2, nBins, 0, 1.2 );


   TH2F* TH2F_b_deltaR_gen_CA12_top_pt = new TH2F("TH2F_b_deltaR_gen_CA12", " Delta R between Gen b and CA12 b vs Top p_{T}; #delta_{R}(Gen, CA12); Gen Top p_{T}", nBins, 0, 1.5, nBins, 0, 700 );
   TH2F* TH2F_b_ratio_gen_CA12_top_pt = new TH2F("TH2F_b_ratio_gen_CA12_top_pt", "E(b_{gen})/E(b_{CA12}) vs Top p_{T}; #E(b_{gen})/E(b_{CA12}); Gen Top p_{T}", nBins, 0, 5, nBins, 0, 700 );
   TH2F* TH2F_Top_ratio_gen_CA12_top_pt = new TH2F("TH2F_Top_ratio_gen_CA12_top_pt", "E(t_{gen})/E(t_{CA12}) vs Top p_{T}; #E(t_{gen})/E(t_{CA12}); Gen Top p_{T}", nBins, 0, 2, nBins, 0, 700 );
   TH2F* TH2F_Top_deltaR_gen_CA12_top_pt = new TH2F("TH2F_Top_deltaR_gen_CA12_top_pt", " Delta R between Gen t and CA12 t vs Top p_{T}; #delta_{R}(Gen, CA12); Gen Top p_{T}", nBins, 0, 1.5, nBins, 0, 700 );
   TH2F* TH2F_Top_gen_ratio_CA12_ratio = new TH2F("TH2F_Top_gen_ratio_CA12_ratio", "E(b})/E(t) Gen vs CA12 ; Gen; CA12", nBins, 0, 1.2, nBins, 0, 1.2 );
   TH2F* TH2F_Top_gen_deltaR_CA12_ratio = new TH2F("TH2F_Top_gen_deltaR_CA12_ratio", "#delta_{R} Gen vs CA12 ; Gen; CA12", nBins, 0, 1.2, nBins, 0, 1.2 );



   TH2F* TH2F_b_deltaR_gen_AK8_top_pt = new TH2F("TH2F_b_deltaR_gen_AK8", " Delta R between Gen b and AK8 b vs Top p_{T}; #delta_{R}(Gen, AK8); Gen Top p_{T}", nBins, 0, 1.5, nBins, 0, 700 );
   TH2F* TH2F_b_ratio_gen_AK8_top_pt = new TH2F("TH2F_b_ratio_gen_AK8_top_pt", "E(b_{gen})/E(b_{AK8}) vs Top p_{T}; #E(b_{gen})/E(b_{AK8}); Gen Top p_{T}", nBins, 0, 5, nBins, 0, 700 );
   TH2F* TH2F_Top_ratio_gen_AK8_top_pt = new TH2F("TH2F_Top_ratio_gen_AK8_top_pt", "E(t_{gen})/E(t_{AK8}) vs Top p_{T}; #E(t_{gen})/E(t_{AK8}); Gen Top p_{T}", nBins, 0, 2, nBins, 0, 700 );
   TH2F* TH2F_Top_deltaR_gen_AK8_top_pt = new TH2F("TH2F_Top_deltaR_gen_AK8_top_pt", " Delta R between Gen t and AK8 t vs Top p_{T}; #delta_{R}(Gen, AK8); Gen Top p_{T}", nBins, 0, 1.5, nBins, 0, 700 );
   TH2F* TH2F_Top_gen_ratio_AK8_ratio = new TH2F("TH2F_Top_gen_ratio_AK8_ratio", "E(b})/E(t) Gen vs AK8 ; Gen; AK8", nBins, 0, 1.2, nBins, 0, 1.2 );
   TH2F* TH2F_Top_gen_deltaR_AK8_ratio = new TH2F("TH2F_Top_gen_deltaR_AK8_ratio", "#delta_{R} Gen vs AK8 ; Gen; AK8", nBins, 0, 1.2, nBins, 0, 1.2 );


   Int_t total = 0;
   Int_t mass_cut = 0;
   Int_t tau_cut = 0;
   Int_t b_cut = 0;
   Int_t delta_r_matched_no_cut = 0;
   Int_t B2G_matched_no_cut = 0;
   Int_t top_tag_cut = 0;
   Int_t top_tag_match_cut = 0;
   Float_t had_ratio;
   Float_t had_deltaR;
   Float_t gen_ratio;
   Float_t gen_deltaR;
   TLorentzVector TL_AK8_LF_subJetPt;
   TLorentzVector TL_AK8_B_subJetPt;
   TLorentzVector TL_AK8;
   TLorentzVector TL_Gen_Top;
   TLorentzVector TL_Gen_b;
   TLorentzVector TL_Gen_W;
   TLorentzVector TL_AK4_LF_subJetPt0;
   TLorentzVector TL_AK4_LF_subJetPt1;
   TLorentzVector TL_AK4_B_subJetPt;
   TLorentzVector TL_AK4;
   TLorentzVector TL_CA12_LF_subJetPt;
   TLorentzVector TL_CA12_B_subJetPt;
   TLorentzVector TL_CA12;


   Float_t b_Tau21 = 0;
   Float_t W_Tau21 = 0;
   Float_t b_Tau32 = 0;
   Float_t W_Tau32 = 0;

   Bool_t had_cut = false;


   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;



      if (JetPuppiSDsubjet0bdisc > JetPuppiSDsubjet1bdisc){
         TL_AK8_LF_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet1pt, JetPuppiSDsubjet1eta, JetPuppiSDsubjet1phi, JetPuppiSDsubjet1mass);
         TL_AK8_B_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet0pt, JetPuppiSDsubjet0eta, JetPuppiSDsubjet0phi, JetPuppiSDsubjet0mass);
         b_Tau21 = JetPuppiSDsubjet0tau2/JetPuppiSDsubjet0tau1;
         W_Tau21 = JetPuppiSDsubjet1tau2/JetPuppiSDsubjet1tau1;
         b_Tau32 = JetPuppiSDsubjet0tau3/JetPuppiSDsubjet0tau2;
         W_Tau32 = JetPuppiSDsubjet1tau3/JetPuppiSDsubjet1tau2;

      } else {
         TL_AK8_LF_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet0pt, JetPuppiSDsubjet0eta, JetPuppiSDsubjet0phi, JetPuppiSDsubjet0mass);
         TL_AK8_B_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet1pt, JetPuppiSDsubjet1eta, JetPuppiSDsubjet1phi, JetPuppiSDsubjet1mass);
         b_Tau21 = JetPuppiSDsubjet1tau2/JetPuppiSDsubjet1tau1;
         W_Tau21 = JetPuppiSDsubjet0tau2/JetPuppiSDsubjet0tau1;
         b_Tau32 = JetPuppiSDsubjet1tau3/JetPuppiSDsubjet1tau2;
         W_Tau32 = JetPuppiSDsubjet0tau3/JetPuppiSDsubjet0tau2;         
      }
      //std::cout

      had_cut = false;
      TL_AK8.SetPtEtaPhiM(JetPuppiPtRaw, JetPuppiEtaRaw,JetPuppiPhiRaw,JetPuppiSDmassSubjetCorr);

      if(AK4ReconstructedJetPt > 0){
         TL_AK4_LF_subJetPt0.SetPtEtaPhiM(AK4WJetPtRaw, AK4WJetEtaRaw, AK4WJetPhiRaw, AK4WJetMassRaw);
         TL_AK4_LF_subJetPt1.SetPtEtaPhiM(AK4W2JetPtRaw, AK4W2JetEtaRaw, AK4W2JetPhiRaw, AK4W2JetMassRaw);
         TL_AK4_B_subJetPt.SetPtEtaPhiM(AK4bJetPtRaw, AK4bJetEtaRaw, AK4bJetPhiRaw, AK4bJetMassRaw);
         TL_AK4.SetPtEtaPhiM(AK4ReconstructedJetPt, AK4ReconstructedJetEta, AK4ReconstructedJetPhi, AK4ReconstructedJetMass);
      }

     
      if(CA12JetPtRaw > 0){

         if (CA12Jetsubjet0bdisc > CA12Jetsubjet1bdisc){
            TL_CA12_LF_subJetPt.SetPtEtaPhiM(CA12Jetsubjet1pt, CA12Jetsubjet1eta, CA12Jetsubjet1phi, CA12Jetsubjet1mass);
            TL_CA12_B_subJetPt.SetPtEtaPhiM(CA12Jetsubjet0pt, CA12Jetsubjet0eta, CA12Jetsubjet0phi, CA12Jetsubjet0mass);

         } else {
            TL_CA12_LF_subJetPt.SetPtEtaPhiM(CA12Jetsubjet0pt, CA12Jetsubjet0eta, CA12Jetsubjet0phi, CA12Jetsubjet0mass);
            TL_CA12_B_subJetPt.SetPtEtaPhiM(CA12Jetsubjet1pt, CA12Jetsubjet1eta, CA12Jetsubjet1phi, CA12Jetsubjet1mass);      
         }

         TL_CA12.SetPtEtaPhiM(CA12JetPtRaw, CA12JetEtaRaw,CA12JetPhiRaw,CA12JetMassRaw);
       }

      if (gen ==true){

         TL_Gen_Top.SetPtEtaPhiM(JetGenMatched_TopPt, JetGenMatched_TopEta,JetGenMatched_TopPhi,JetGenMatched_TopMass);
         TL_Gen_b.SetPtEtaPhiM(Gen_array_b_p4[0], Gen_array_b_p4[1],Gen_array_b_p4[2],Gen_array_b_p4[3]);
         TL_Gen_W.SetPtEtaPhiM(Gen_array_W_p4[0], Gen_array_W_p4[1],Gen_array_W_p4[2],Gen_array_W_p4[3]);
         had_ratio = TL_AK4_B_subJetPt.E()/TL_AK4.E();
         gen_ratio = TL_Gen_b.E()/TL_Gen_Top.E();
         //if (had_ratio < gen_ratio*1.2) continue;
         //if (had_ratio > gen_ratio*1.2) continue; == good
      }


      TH1F_maxbdisc_SD->Fill(JetSDmaxbdisc);
      TH1F_maxbdisc_Puppi_SD->Fill(JetPuppiSDsubjet0bdisc); 


      TH1F_puppi_Tau32->Fill(JetPuppiTau32);
      TH1F_puppi_Tau21->Fill(JetPuppiTau21);

      if (JetPuppiPtRaw > 90 && JetPuppiSDmassSubjetCorr < 250 && JetPuppiSDmassSubjetCorr > 140 ){
         mass_cut++;
         if(JetPuppiTau32 <.65 ){
            tau_cut++;
            if (JetPuppiSDmaxbdisc > 0.679){
                //std::cout << JetPuppiSDsubjet0bdisc<<" "<<JetPuppiSDsubjet1bdisc<<std::endl;





                TH2F_pt_SD_mass->Fill(JetPuppiPtRaw, JetPuppiSDmassSubjetCorr);
                TH1F_had_AK8Puppi_pt->Fill(JetPuppiPtRaw);
                TH1F_had_AK8Puppi_mass->Fill(JetSDmassRaw);

               // if (JetPuppiSDsubjet0bdisc > JetPuppiSDsubjet1bdisc){
               //    TH1F_puppi_subb_tau32->Fill(JetPuppiSDsubjet0tau3/JetPuppiSDsubjet0tau2);
               //    TH1F_puppi_subb_tau21->Fill(JetPuppiSDsubjet0tau2/JetPuppiSDsubjet0tau1);
               //    TH1F_puppi_subLF_tau32->Fill(JetPuppiSDsubjet1tau3/JetPuppiSDsubjet1tau2);
               //    TH1F_puppi_subLF_tau21->Fill(JetPuppiSDsubjet1tau2/JetPuppiSDsubjet1tau1);
               //} else {
               //    TH1F_puppi_subb_tau32->Fill(JetPuppiSDsubjet1tau3/JetPuppiSDsubjet1tau2);
               //    TH1F_puppi_subb_tau21->Fill(JetPuppiSDsubjet1tau2/JetPuppiSDsubjet1tau1);
               //    TH1F_puppi_subLF_tau32->Fill(JetPuppiSDsubjet0tau3/JetPuppiSDsubjet0tau2);
               //    TH1F_puppi_subLF_tau21->Fill(JetPuppiSDsubjet0tau2/JetPuppiSDsubjet0tau1);  
               //}

               TH1F_puppi_subb_tau32->Fill(b_Tau32);
               TH1F_puppi_subb_tau21->Fill(b_Tau21);
               TH1F_puppi_subLF_tau32->Fill(W_Tau32);
               TH1F_puppi_subLF_tau21->Fill(W_Tau21);



               TH2F_bTau21_WTau21->Fill(b_Tau21,W_Tau21);

               had_ratio = TL_AK4_B_subJetPt.E()/TL_CA12.E();
               had_deltaR = TL_AK4_B_subJetPt.DeltaR(TL_CA12);

               TH1F_had_difference_ratio_btau21->Fill(had_ratio-b_Tau21);
               TH1F_had_difference_WTau21_btau21->Fill(W_Tau21-b_Tau21);
               TH1F_had_sum_ratio_btau21->Fill(had_ratio+b_Tau21);

               TH1F_had_difference->Fill((TL_AK8_B_subJetPt.E() - TL_AK8_LF_subJetPt.E())/TL_AK8.E());
               TH2F_bTau21_ratio->Fill(b_Tau21, had_ratio);
               TH2F_bTau21_ratio_rotated->Fill((b_Tau21-had_ratio)*0.7071, (b_Tau21+had_ratio)*0.7071 );


               TH2F_leading_tau21_ratio->Fill(JetPuppiSDsubjet0tau2/JetPuppiSDsubjet0tau1,had_ratio);
               TH1F_had_ratio_deltaR_ratio->Fill(had_ratio-had_deltaR);
      
               TH2F_deltaR_ratio->Fill(had_deltaR,had_ratio);

               TH1F_had_AK8Puppi_SD_pt->Fill(JetPuppiPtRaw);
               TH1F_had_AK8Puppi_SD_mass->Fill(JetPuppiMassRaw);
               TH1F_had_LF_subJetPt->Fill(TL_AK8_LF_subJetPt.Pt());
               TH1F_had_B_subJetPt->Fill(TL_AK8_B_subJetPt.Pt());

               TH1F_had_Ratio->Fill(had_ratio);
               
         
               TH1F_had_deltaR->Fill(had_deltaR);

               TH1F_puppi_ECF1->Fill(JetPuppiSDECF1);
               TH1F_puppi_ECF2->Fill(JetPuppiSDECF2);
               TH1F_puppi_ECF3->Fill(JetPuppiSDECF3);
               TH1F_puppi_ECF4->Fill(JetPuppiSDECF4);
               TH1F_puppi_ECF5->Fill(JetPuppiSDECF5);

               TH1F_puppi_ECF_C2->Fill(JetPuppiSDC_2);
               TH1F_puppi_ECF_D2->Fill(JetPuppiSDD_2);
               TH1F_puppi_ECF_C3->Fill(JetPuppiSDC_3);
               TH1F_puppi_ECF_D3->Fill(JetPuppiSDD_3);

               had_cut = true;
            }
         }
      }



      if(gen == true){


         TH2F_b_deltaR_gen_AK4_top_pt->Fill(TL_AK4_B_subJetPt.DeltaR(TL_Gen_b),TL_Gen_Top.Pt());
         TH2F_b_ratio_gen_AK4_top_pt->Fill(TL_AK4_B_subJetPt.E()/TL_Gen_b.E(), TL_Gen_Top.Pt());
         TH2F_Top_ratio_gen_AK4_top_pt->Fill(TL_AK4.E()/TL_Gen_Top.E(), TL_Gen_Top.Pt());
         TH2F_Top_deltaR_gen_AK4_top_pt->Fill(TL_AK4.DeltaR(TL_Gen_Top),TL_Gen_Top.Pt());
         TH2F_Top_gen_ratio_AK4_ratio->Fill(TL_Gen_b.E()/TL_Gen_Top.E(), TL_AK4_B_subJetPt.E()/TL_AK4.E());
         TH2F_Top_gen_deltaR_AK4_ratio->Fill(TL_Gen_b.DeltaR(TL_Gen_Top), TL_AK4_B_subJetPt.DeltaR(TL_AK4));
   
         TH2F_b_deltaR_gen_AK8_top_pt->Fill(TL_AK8_B_subJetPt.DeltaR(TL_Gen_b),TL_Gen_Top.Pt());
         TH2F_b_ratio_gen_AK8_top_pt->Fill(TL_AK8_B_subJetPt.E()/TL_Gen_b.E(), TL_Gen_Top.Pt());
         TH2F_Top_ratio_gen_AK8_top_pt->Fill(TL_AK8.E()/TL_Gen_Top.E(), TL_Gen_Top.Pt());
         TH2F_Top_deltaR_gen_AK8_top_pt->Fill(TL_AK8.DeltaR(TL_Gen_Top),TL_Gen_Top.Pt());
         TH2F_Top_gen_ratio_AK8_ratio->Fill(TL_Gen_b.E()/TL_Gen_Top.E(), TL_AK8_B_subJetPt.E()/TL_AK8.E());
         TH2F_Top_gen_deltaR_AK8_ratio->Fill(TL_Gen_b.DeltaR(TL_Gen_Top), TL_AK8_B_subJetPt.DeltaR(TL_AK8));

         TH2F_b_deltaR_gen_CA12_top_pt->Fill(TL_CA12_B_subJetPt.DeltaR(TL_Gen_b),TL_Gen_Top.Pt());
         TH2F_b_ratio_gen_CA12_top_pt->Fill(TL_CA12_B_subJetPt.E()/TL_Gen_b.E(), TL_Gen_Top.Pt());
         TH2F_Top_ratio_gen_CA12_top_pt->Fill(TL_CA12.E()/TL_Gen_Top.E(), TL_Gen_Top.Pt());
         TH2F_Top_deltaR_gen_CA12_top_pt->Fill(TL_CA12.DeltaR(TL_Gen_Top),TL_Gen_Top.Pt());
         TH2F_Top_gen_ratio_CA12_ratio->Fill(TL_Gen_b.E()/TL_Gen_Top.E(), TL_CA12_B_subJetPt.E()/TL_CA12.E());
         TH2F_Top_gen_deltaR_CA12_ratio->Fill(TL_Gen_b.DeltaR(TL_Gen_Top), TL_CA12_B_subJetPt.DeltaR(TL_CA12));
      }

      if(gen == true && had_cut==true){

         TL_Gen_Top.SetPtEtaPhiM(JetGenMatched_TopPt, JetGenMatched_TopEta,JetGenMatched_TopPhi,JetGenMatched_TopMass);
         TL_Gen_b.SetPtEtaPhiM(Gen_array_b_p4[0], Gen_array_b_p4[1],Gen_array_b_p4[2],Gen_array_b_p4[3]);
         TL_Gen_W.SetPtEtaPhiM(Gen_array_W_p4[0], Gen_array_W_p4[1],Gen_array_W_p4[2],Gen_array_W_p4[3]);

         TH1F_gen_had_AK8Puppi_SD_pt->Fill(JetGenMatched_TopPt);
         TH1F_gen_had_AK8Puppi_SD_mass->Fill(JetGenMatched_TopMass);
         TH1F_gen_had_LF_subJetPt->Fill(JetGenMatched_WPt);
         TH1F_gen_had_B_subJetPt->Fill(JetGenMatched_bPt);
         TH1F_gen_had_Ratio->Fill(TL_Gen_b.E()/TL_Gen_Top.E());
         TH1F_gen_had_deltaR->Fill(TL_Gen_b.DeltaR(TL_Gen_Top));

         TH2F_gen_pt_raw_mass->Fill(JetGenMatched_TopPt,JetPuppiSDmassSubjetCorr);
         TH2F_gen_mass_raw_mass->Fill(JetGenMatched_TopMass,JetPuppiSDmassSubjetCorr);
         TH2F_gen_pt_raw_pt->Fill(JetGenMatched_TopPt,JetPuppiPtRaw);
         TH2F_gen_ratio_puppi_ratio->Fill(TL_Gen_b.E()/TL_Gen_Top.E(), had_ratio);
         TH2F_gen_deltaR_puppi_deltaR->Fill(TL_Gen_b.DeltaR(TL_Gen_Top), had_deltaR);

        
      }
  

      total++;



   }

   std::cout << "mass cut: " << mass_cut  << "percent total " << mass_cut/(double)total << std::endl;
   std::cout << "tau cut: " << tau_cut  << "percent total " << tau_cut/(double)total << std::endl;
   std::cout << "b cut: " << b_cut  << "percent total " << b_cut/(double)total << std::endl;

   std::cout << "top_tag_cut: " << top_tag_cut  << "percent total " << top_tag_cut/(double)total << std::endl;
   std::cout << "top_tag_match_cut: " << top_tag_match_cut  << "percent total " << top_tag_match_cut/(double)total << std::endl;
   std::cout << "B2G_matched_no_cut: " << B2G_matched_no_cut  << "percent total " << B2G_matched_no_cut/(double)total << std::endl;
   std::cout << "delta_r_matched_no_cut: " << delta_r_matched_no_cut  << "percent total " << delta_r_matched_no_cut/(double)total << std::endl;
   hadMonoTopLoopHists->Write();
   hadMonoTopLoopHists->Close();
}
