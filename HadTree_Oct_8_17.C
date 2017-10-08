#define HadTree_Oct_8_17_cxx
#include "HadTree_Oct_8_17.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void HadTree_Oct_8_17::Loop(std::string outFileName, Bool_t gen)
{
//   In a ROOT session, you can do:
//      root> .L HadTree_Oct_8_17.C
//      root> HadTree_Oct_8_17 t
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

   TH1F* TH1F_had_AK8Puppi_SD_pt = new TH1F("TH1F_had_AK8Puppi_pt", "AK8 Puppi SD p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_AK8Puppi_SD_mass = new TH1F("TH1F_had_AK8Puppi_mass", "AK8 Puppi SD Mass; Mass [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_AK8Puppi_pt = new TH1F("TH1F_had_AK8Puppi_pt", "AK8 Puppi p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_AK8Puppi_mass = new TH1F("TH1F_had_AK8Puppi_mass", "AK8 Puppi Mass; Mass [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_LF_subJetPt = new TH1F("TH1F_had_LF_subJetPt", "Light Flavor Subjet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_B_subJetPt = new TH1F("TH1F_had_B_subJetPt", "Heavy (b) Flavor Subjet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_Ratio = new TH1F("TH1F_had_Ratio", "Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
   TH1F* TH1F_had_deltaR = new TH1F("TH1F_had_deltaR", "#delta R BJet and Top; #theta_{Tb}; count", nBins, 0, 1.5 );

   TH1F* TH1F_puppi_ECF1 = new TH1F("TH1F_puppi_ECF1", "ECF1 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 1400 );
   TH1F* TH1F_puppi_ECF2 = new TH1F("TH1F_puppi_ECF2", "ECF2 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 150000 );
   TH1F* TH1F_puppi_ECF3 = new TH1F("TH1F_puppi_ECF3", "ECF3 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 5000000 );
   TH1F* TH1F_puppi_ECF4 = new TH1F("TH1F_puppi_ECF4", "ECF4 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 100000000 );
   TH1F* TH1F_puppi_ECF5 = new TH1F("TH1F_puppi_ECF5", "ECF5 #beta = 1 of Puppi SD jet; ECF1; count", nBins, 0, 500000000 );

   TH1F* TH1F_puppi_ECF_C2 = new TH1F("TH1F_puppi_ECF_C2", "ECF C_{2} #beta = 1 of Puppi SD jet; C_{2}; count", nBins, 0, .005 );
   TH1F* TH1F_puppi_ECF_D2 = new TH1F("TH1F_puppi_ECF_D2", "ECF D_{2} #beta = 1 of Puppi SD jet; D_{2}; count", nBins, 0, .000001 );
   TH1F* TH1F_puppi_ECF_C3 = new TH1F("TH1F_puppi_ECF_C3", "ECF C_{3} #beta = 1 of Puppi SD jet; C_{3}; count", nBins, 0, .0001 );
   TH1F* TH1F_puppi_ECF_D3 = new TH1F("TH1F_puppi_ECF_D3", "ECF D_{3} #beta = 1 of Puppi SD jet; D_{3}; count", nBins, 0, .000001 );




   TH1F* TH1F_maxbdisc_Puppi_SD = new TH1F("TH1F_maxbdisc_Puppi_SD", "Max bDisc SD; bdisc; count", nBins, 0, 1 );
   TH1F* TH1F_maxbdisc_SD = new TH1F("TH1F_maxbdisc_SD", "Max bDisc; bdisc; count", nBins, 0, 1 );

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
   TLorentzVector TL_LF_subJetPt;
   TLorentzVector TL_B_subJetPt;
   TLorentzVector TL_AK8;
   TLorentzVector TL_Gen_Top;
   TLorentzVector TL_Gen_b;
   TLorentzVector TL_Gen_W;

   Bool_t had_cut = false;


   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;


	  TH1F_maxbdisc_SD->Fill(JetSDmaxbdisc);
      TH1F_maxbdisc_Puppi_SD->Fill(JetPuppiSDsubjet0bdisc); 

      if (JetPuppiSDsubjet0bdisc > JetPuppiSDsubjet1bdisc){
         TL_LF_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet1pt, JetPuppiSDsubjet0eta, JetPuppiSDsubjet0phi, JetPuppiSDsubjet0mass);
         TL_B_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet0pt, JetPuppiSDsubjet0eta, JetPuppiSDsubjet0phi, JetPuppiSDsubjet0mass);
      } else {
         TL_LF_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet0pt, JetPuppiSDsubjet0eta, JetPuppiSDsubjet0phi, JetPuppiSDsubjet0mass);
         TL_B_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet0pt, JetPuppiSDsubjet0eta, JetPuppiSDsubjet0phi, JetPuppiSDsubjet0mass);           
      }
      //std::cout

      had_cut = false;
      TL_AK8.SetPtEtaPhiM(JetPuppiPtRaw, JetPuppiEtaRaw,JetPuppiPhiRaw,JetPuppiSDmassSubjetCorr);

      TH2F_pt_SD_mass->Fill(JetPuppiPtRaw, JetPuppiSDmassSubjetCorr);
      TH1F_had_AK8Puppi_pt->Fill(JetPuppiPtRaw);
      TH1F_had_AK8Puppi_mass->Fill(JetSDmassRaw);


      if (JetPuppiPtRaw > 300 && JetPuppiSDmassSubjetCorr < 250 && JetPuppiSDmassSubjetCorr > 140){
         mass_cut++;
         if(JetPuppiTau32 <.65 ){
            tau_cut++;
            if (JetPuppiSDmaxbdisc > 0.679){
            	//std::cout << JetPuppiSDsubjet0bdisc<<" "<<JetPuppiSDsubjet1bdisc<<std::endl;


               had_ratio = TL_B_subJetPt.E()/TL_AK8.E();
               had_deltaR = TL_B_subJetPt.DeltaR(TL_AK8);
      
               TH1F_had_AK8Puppi_SD_pt->Fill(JetPuppiPtRaw);
               TH1F_had_AK8Puppi_SD_mass->Fill(JetPuppiMassRaw);
               TH1F_had_LF_subJetPt->Fill(TL_LF_subJetPt.Pt());
               TH1F_had_B_subJetPt->Fill(TL_B_subJetPt.Pt());
               TH1F_had_Ratio->Fill(had_ratio);
               TH1F_had_deltaR->Fill(had_deltaR);

               TH1F_puppi_ECF1->Fill(JetPuppiSDECF1);
               TH1F_puppi_ECF2->Fill(JetPuppiSDECF2);
               TH1F_puppi_ECF3->Fill(JetPuppiSDECF3);
               TH1F_puppi_ECF4->Fill(JetPuppiSDECF4);
               TH1F_puppi_ECF5->Fill(JetPuppiSDECF5);

               TH1F_puppi_ECF_C2->Fill(JetPuppiSDC_2);
               TH1F_puppi_ECF_D2->Fill(JetPuppiSDD_3);
               TH1F_puppi_ECF_C3->Fill(JetPuppiSDC_2);
               TH1F_puppi_ECF_D3->Fill(JetPuppiSDD_3);

               had_cut = true;
            }
         }
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
