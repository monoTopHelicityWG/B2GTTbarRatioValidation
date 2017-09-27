#define semiLepTTBarLoop_cxx
#include "semiLepTTBarLoop.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream> 
#include <TLorentzVector.h>



void semiLepTTBarLoop::Loop(std::string outFileName, Bool_t gen)
{
//   In a ROOT session, you can do:
//      root> .L semiLepTTBarLoop.C
//      root> semiLepTTBarLoop t
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
   const int nBins = 100;
   const int entry_count_constant = 1000;

   TFile* semiLepTTBarLoopHists  = new TFile(outFileName.c_str(), "RECREATE");
   
   TH1F* TH1F_lep_LeptonPt = new TH1F("TH1F_lep_LeptonPt", "Lepton p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_lep_BJetPt = new TH1F("TH1F_lep_BJetPt", "BJet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_lep_Ratio = new TH1F("TH1F_lep_Ratio", "Ratio: p_{T}(b)/(p_{T}(b) + p_{T}(l));  p_{T}(b)/(p_{T}(b) + p_{T}(l)); count", nBins, 0, 1.5 );
   TH1F* TH1F_lep_deltaR = new TH1F("TH1F_lep_deltaR", "#delta R BJet and Lepton; #theta_{lb}; count", nBins, 0, 1.5 );

   TH1F* TH1F_had_AK8Puppi_SD_pt = new TH1F("TH1F_had_AK8Puppi_pt", "AK8 Puppi SD p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_AK8Puppi_SD_mass = new TH1F("TH1F_had_AK8Puppi_mass", "AK8 Puppi SD Mass; Mass [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_LF_subJetPt = new TH1F("TH1F_had_LF_subJetPt", "Light Flavor Subjet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_B_subJetPt = new TH1F("TH1F_had_B_subJetPt", "Heavy (b) Flavor Subjet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_had_Ratio = new TH1F("TH1F_had_Ratio", "Ratio: E(b)/E(t);  E(b)/E(t); count", nBins, 0, 1.5 );
   TH1F* TH1F_had_deltaR = new TH1F("TH1F_had_deltaR", "#delta R BJet and Other Subjet; #theta_{jb}; count", nBins, 0, 1.5 );

   TH1F* TH1F_had_AK4_mass = new TH1F("TH1F_had_AK4_mass", "AK4 Mass; Mass [GeV]; count", nBins, 0, 1000 );

   //gen level plots
   TH2F* TH2F_gen_pt_raw_mass = new TH2F("TH2F_gen_pt_raw_mass", "Gen p_{T} vs Raw AK8 Jet Mass; Gen p_{T}; Raw Mass [GeV]", nBins, 0, 1000, nBins, 0, 500 );
   TH2F* TH2F_gen_mass_raw_mass = new TH2F("TH2F_gen_mass_raw_mass", "Gen Mass vs Raw AK8 Jet Mass; Gen Mass; Raw Mass [GeV]", nBins, 0, 1000, nBins, 0, 500 );
   TH2F* TH2F_gen_pt_raw_pt = new TH2F("TH2F_gen_pt_raw_pt", "Gen p_{T} vs Raw AK8 Jet p_{T}; Gen p_{T}; Raw p_{T} [GeV]", nBins, 0, 1000, nBins, 0, 1000 );
   
   //lept had plots:
   TH2F* TH2F_lept_b_pt_raw_mass = new TH2F("TH2F_lept_b_pt_raw_mass", "Lepton + B p_{T} vs Raw AK8 Jet Mass; Gen p_{T}; Raw Mass [GeV]", nBins, 0, 1000, nBins, 0, 500 );
   TH2F* TH2F_lept_b_pt_raw_pt = new TH2F("TH2F_lept_b_pt_raw_pt", "Lepton + B p_{T} vs Raw AK8 Jet p_{T}; p_{T}(l) + p_{T}(b) [GeV]; Raw p_{T} [GeV]", nBins, 0, 1000, nBins, 0, 1000 );
   TH2F* TH2F_lept_R_had_R = new TH2F("TH2F_lept_R_had_R", "Leptonic Ratio vs Hadronic Ratio; Leptonic Ratio; Hadronic Ratio", nBins, 0, 1.5, nBins, 0, 1.5 );


   Float_t lept_ratio;
   Float_t lept_deltaR;
   TLorentzVector TL_lepton;
   TLorentzVector TL_leptonic_BJet;


   Int_t total = 0;
   Int_t mass_cut = 0;
   Int_t tau_cut = 0;
   Int_t b_cut = 0;
   Float_t had_ratio;
   Float_t had_deltaR;
   TLorentzVector TL_LF_subJetPt;
   TLorentzVector TL_B_subJetPt;
   TLorentzVector TL_AK8;
   TLorentzVector TL_AK8_2;
   TLorentzVector TL_AK4;
   TLorentzVector TL_AK4_1;

   Bool_t lept_cut = false;
   Bool_t had_cut = false;



   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry % entry_count_constant == 0) std::cout << "Event: " << jentry << " of " << nentries << " " << jentry/nentries*100 << "%" << std::endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;


      lept_cut = false;
      had_cut = false;
      //leptonic R:

      if (LepHemiContainsAK4BtagMedium == 1){
        if(LeptonIsMu == 1 && MuTight == 1){
            TL_lepton.SetPtEtaPhiM(LeptonPt, LeptonEta, LeptonPhi, LeptonMass);
            TL_leptonic_BJet.SetPtEtaPhiM(AK4_dRminLep_Pt, AK4_dRminLep_Eta, AK4_dRminLep_Phi, AK4_dRminLep_Mass);

            lept_deltaR = TL_lepton.DeltaR(TL_leptonic_BJet);

            lept_ratio = AK4_dRminLep_Pt/(AK4_dRminLep_Pt+ LeptonPt);

            TH1F_lep_LeptonPt->Fill(LeptonPt);
            TH1F_lep_BJetPt->Fill(AK4_dRminLep_Pt);
            TH1F_lep_Ratio->Fill(lept_ratio);
            TH1F_lep_deltaR->Fill(lept_deltaR);

            lept_cut = true;
        }
      }
    
      if (JetPuppiSDsubjet0bdisc > JetPuppiSDsubjet1bdisc){
         TL_LF_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet1pt, JetPuppiSDsubjet1eta, JetPuppiSDsubjet1phi, JetPuppiSDsubjet1mass);
         TL_B_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet0pt, JetPuppiSDsubjet0eta, JetPuppiSDsubjet0phi, JetPuppiSDsubjet0mass);
      } else {
         TL_LF_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet0pt, JetPuppiSDsubjet0eta, JetPuppiSDsubjet0phi, JetPuppiSDsubjet0mass);
         TL_B_subJetPt.SetPtEtaPhiM(JetPuppiSDsubjet1pt, JetPuppiSDsubjet1eta, JetPuppiSDsubjet1phi, JetPuppiSDsubjet1mass);           
      }
	TL_AK8.SetPtEtaPhiM(JetPtRaw,JetEtaRaw,JetPhiRaw,JetMassRaw);
	TL_AK8_2.SetPtEtaPhiM(Jet2PtRaw,Jet2EtaRaw,Jet2PhiRaw,Jet2MassRaw);

   TL_AK4.SetPtEtaPhiM(AK4_hadTop_jet0_Pt,AK4_hadTop_jet0_Eta,AK4_hadTop_jet0_Phi,AK4_hadTop_jet0_Mass);
   TL_AK4_1.SetPtEtaPhiM(AK4_hadTop_jet1_Pt,AK4_hadTop_jet1_Eta,AK4_hadTop_jet1_Phi,AK4_hadTop_jet1_Mass);


   std::cout << "ak8 " <<  JetPtRaw << " " << JetEtaRaw << " " << JetPhiRaw << " " << JetMassRaw << std::endl;
   //std::cout << Jet2PtRaw << " " << Jet2EtaRaw << " " << Jet2PhiRaw << " " << Jet2MassRaw << std::endl;
  
   std::cout << "gen top " << JetGenMatched_TopPt << " " << JetGenMatched_TopEta << " " << JetGenMatched_TopPhi << " " << JetGenMatched_TopMass << std::endl;
   std::cout << "gen b " << JetGenMatched_bPt << std::endl;
   std::cout << "gen w " << JetGenMatched_WPt << std::endl;
   std::cout << "jet 0 " << AK4_hadTop_jet0_Pt << " " << AK4_hadTop_jet0_Eta << " " << AK4_hadTop_jet0_Phi << " " << AK4_hadTop_jet0_Mass << std::endl;
   std::cout << "jet 1 " << AK4_hadTop_jet1_Pt << " " << AK4_hadTop_jet1_Eta << " " << AK4_hadTop_jet1_Phi << " " << AK4_hadTop_jet1_Mass << std::endl;
   std::cout << "jet 1 + 0 " << (TL_AK4+TL_AK4_1).Pt() << " " << (TL_AK4+TL_AK4_1).Eta() << " " << (TL_AK4+TL_AK4_1).Phi() << " " << (TL_AK4+TL_AK4_1).M() << std::endl;

    


	if(JetPtRaw*Jet2PtRaw > 0) std::cout << "mass of 2 jets " <<  (TL_AK8+ TL_AK8_2).M() << std::endl;
   if(AK4_hadTop_jet1_Pt*AK4_hadTop_jet0_Pt > 0){
      TH1F_had_AK4_mass->Fill( (TL_AK4+ TL_AK4_1).M() );
      std::cout << "mass of 2 jets " <<  (TL_AK4+ TL_AK4_1).M() << std::endl;;
   } 

	//std::cout << "deltaR" << TL_AK8.DeltaR(TL_AK8_2) << std::endl; 
      //std::cout << JetPuppiSDmassRaw  << " gen " << JetMatchedGenJetMass << std::endl;
      total++;
      if (JetMassRaw*JetMassCorrFactor < 250 && JetMassRaw*JetMassCorrFactor > 140){
         mass_cut++;
         if(JetPuppiTau32 > .55 && JetPuppiTau21 > .1){
            tau_cut++;
            if (JetPuppiSDmaxbdisc > 0.679){
               b_cut++;

               TL_AK8.SetPtEtaPhiM(JetPuppiSDptRaw, JetPuppiSDetaRaw,JetPuppiSDphiRaw,JetPuppiSDmassRaw);
      
               had_ratio = TL_B_subJetPt.E()/TL_AK8.E();
      
               had_deltaR = TL_B_subJetPt.DeltaR(TL_AK8);
      
               TH1F_had_AK8Puppi_SD_pt->Fill(JetPuppiSDptRaw);
               TH1F_had_AK8Puppi_SD_mass->Fill(JetPuppiSDmassRaw);
               TH1F_had_LF_subJetPt->Fill(TL_LF_subJetPt.Pt());
               TH1F_had_B_subJetPt->Fill(TL_B_subJetPt.Pt());
               TH1F_had_Ratio->Fill(had_ratio);
               TH1F_had_deltaR->Fill(had_deltaR);

               had_cut = true;

 
            }
         }
      }
  
              if(gen==true && JetGenMatched_TopHadronic == 1){
                  TH2F_gen_pt_raw_mass->Fill(JetMatchedGenJetPt ,JetMassRaw);
                  TH2F_gen_mass_raw_mass->Fill(JetMatchedGenJetMass ,JetMassRaw);
                  TH2F_gen_pt_raw_pt->Fill(JetMatchedGenJetPt, JetPtRaw);
               }

               if(had_cut == true && lept_cut == true ){
                  TH2F_lept_b_pt_raw_mass->Fill(LeptonPt + AK4_dRminLep_Pt, JetMassRaw);
                  TH2F_lept_R_had_R->Fill(lept_ratio,had_ratio);
                  TH2F_lept_b_pt_raw_pt->Fill(LeptonPt + AK4_dRminLep_Pt, JetPtRaw);
               }

   }

   semiLepTTBarLoopHists->Write();
   semiLepTTBarLoopHists->Close();

   std::cout << "mass cut: " << mass_cut  << "percent total " << mass_cut/(double)total << std::endl;
   std::cout << "tau cut: " << tau_cut  << "percent total " << tau_cut/(double)total << std::endl;
   std::cout << "b cut: " << b_cut  << "percent total " << b_cut/(double)total << std::endl;

}
