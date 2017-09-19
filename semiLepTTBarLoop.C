#define semiLepTTBarLoop_cxx
#include "semiLepTTBarLoop.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream> 
#include <TLorentzVector.h>

void semiLepTTBarLoop::Loop(std::string outFileName)
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
   TH1F* TH1F_LeptonPt = new TH1F("TH1F_LeptonPt", "Lepton p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_BJetPt = new TH1F("TH1F_BJetPt", "BJet p_{T}; p_{T} [GeV]; count", nBins, 0, 1000 );
   TH1F* TH1F_Ratio = new TH1F("TH1F_Ratio", "Ratio: p_{T}(b)/(p_{T}(b) + p_{T}(l));  p_{T}(b)/(p_{T}(b) + p_{T}(l)); count", nBins, 0, 1 );
   TH1F* TH1F_deltaR = new TH1F("TH1F_deltaR", "#delta R BJet and Lepton; #theta_{lb} [Radians]; count", nBins, 0, 1 );

   Double_t lept_ratio;
   Double_t deltaR;
   TLorentzVector lepton;
   TLorentzVector leptonic_BJet;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if (jentry % entry_count_constant == 0) std::cout << "Event: " << jentry << " of " << nentries << " " << jentry/nentries*100 << "%" << std::endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //leptonic R:

      if (LepHemiContainsAK4BtagMedium == 1){
      	if(LeptonIsMu == 1 && MuTight == 1){
      		lepton.SetPtEtaPhiM(LeptonPt, LeptonEta, LeptonPhi, LeptonMass);
      		leptonic_BJet.SetPtEtaPhiM(AK4_dRminLep_Pt, AK4_dRminLep_Eta, AK4_dRminLep_Phi, AK4_dRminLep_Mass);

      		deltaR = lepton.DeltaR(leptonic_BJet);

      		lept_ratio = AK4_dRminLep_Pt/(AK4_dRminLep_Pt+ LeptonPt);

      		TH1F_LeptonPt->Fill(LeptonPt);
      		TH1F_BJetPt->Fill(AK4_dRminLep_Pt);
      		TH1F_Ratio->Fill(lept_ratio);
      		TH1F_deltaR->Fill(deltaR);

      	}
      }
    
    	
     
      
   }
   semiLepTTBarLoopHists->Write();
   semiLepTTBarLoopHists->Close();


}
