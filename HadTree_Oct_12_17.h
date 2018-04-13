//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 12 16:42:14 2017 by ROOT version 6.06/01
// from TTree TreeHad/TreeHad
// found on file: /uscms_data/d3/rmueller/MonoTop/B2GAnaFW_ttbar/custom_B2GTTbar/CMSSW_8_0_26/src/Analysis/B2GMonoTop/test/b2gtreeV5_MC_MonoTop_lh.root
//////////////////////////////////////////////////////////

#ifndef HadTree_Oct_12_17_h
#define HadTree_Oct_12_17_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "string"

class HadTree_Oct_12_17 {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<int>     *HadTrigPrescales;
   vector<bool>    *HadTrigPass;
   string          *HadTrigAcceptBits;
   Float_t         Gen_array_t_p4[4];
   Float_t         Gen_array_final_t_p4[4];
   Float_t         Gen_array_b_p4[4];
   Float_t         Gen_array_W_p4[4];
   Float_t         Gen_array_Wd1_p4[4];
   Float_t         Gen_array_Wd2_p4[4];
   Float_t         Gen_array_hardest_parton_hardScatterOutgoing_p4[4];
   Float_t         Gen_array_second_hardest_parton_hardScatterOutgoing_p4[4];
   Bool_t          tophadronic;
   Bool_t          topleptonic;
   Int_t           parton1id;
   Int_t           parton2id;
   Int_t           Wd1_id;
   Int_t           Wd2_id;
   Float_t         JetPtRaw;
   Float_t         JetEtaRaw;
   Float_t         JetPhiRaw;
   Float_t         JetMassRaw;
   Float_t         JetArea;
   Float_t         JetSDmassRaw;
   Float_t         JetSDmassSubjetCorrL23;
   Float_t         JetSDmassSubjetCorrL123;
   Float_t         JetSDptRaw;
   Float_t         JetSDetaRaw;
   Float_t         JetSDphiRaw;
   Float_t         JetMassPruned;
   Float_t         JetMassTrimmed;
   Float_t         JetTau1;
   Float_t         JetTau2;
   Float_t         JetTau3;
   Float_t         JetTau4;
   Float_t         JetTau32;
   Float_t         JetTau21;
   Float_t         JetSDmaxbdisc;
   Float_t         JetSDmaxbdiscflavHadron;
   Float_t         JetSDmaxbdiscflavParton;
   Float_t         JetSDsubjet0pt;
   Float_t         JetSDsubjet0mass;
   Float_t         JetSDsubjet0eta;
   Float_t         JetSDsubjet0phi;
   Float_t         JetSDsubjet0area;
   Float_t         JetSDsubjet0flavHadron;
   Float_t         JetSDsubjet0flavParton;
   Float_t         JetSDsubjet0matchedgenjetpt;
   Float_t         JetSDsubjet0tau1;
   Float_t         JetSDsubjet0tau2;
   Float_t         JetSDsubjet0tau3;
   Float_t         JetSDsubjet0bdisc;
   Float_t         JetSDsubjet1pt;
   Float_t         JetSDsubjet1mass;
   Float_t         JetSDsubjet1eta;
   Float_t         JetSDsubjet1phi;
   Float_t         JetSDsubjet1area;
   Float_t         JetSDsubjet1flavHadron;
   Float_t         JetSDsubjet1flavParton;
   Float_t         JetSDsubjet1matchedgenjetpt;
   Float_t         JetSDsubjet1tau1;
   Float_t         JetSDsubjet1tau2;
   Float_t         JetSDsubjet1tau3;
   Float_t         JetSDsubjet1bdisc;
   Float_t         JetPuppiPtRaw;
   Float_t         JetPuppiEtaRaw;
   Float_t         JetPuppiPhiRaw;
   Float_t         JetPuppiMassRaw;
   Float_t         JetPuppiArea;
   Float_t         JetPuppiMassPruned;
   Float_t         JetPuppiMassTrimmed;
   Float_t         JetPuppiSDmassRaw;
   Float_t         JetPuppiSDmassSubjetCorr;
   Float_t         JetPuppiSDptRaw;
   Float_t         JetPuppiSDetaRaw;
   Float_t         JetPuppiSDphiRaw;
   Float_t         JetPuppiTau1;
   Float_t         JetPuppiTau2;
   Float_t         JetPuppiTau3;
   Float_t         JetPuppiTau4;
   Float_t         JetPuppiTau32;
   Float_t         JetPuppiTau21;
   Float_t         JetPuppiSDmaxbdisc;
   Float_t         JetPuppiSDmaxbdiscflavHadron;
   Float_t         JetPuppiSDmaxbdiscflavParton;
   Float_t         JetPuppiSDsubjet0pt;
   Float_t         JetPuppiSDsubjet0mass;
   Float_t         JetPuppiSDsubjet0eta;
   Float_t         JetPuppiSDsubjet0phi;
   Float_t         JetPuppiSDsubjet0area;
   Float_t         JetPuppiSDsubjet0flavHadron;
   Float_t         JetPuppiSDsubjet0flavParton;
   Float_t         JetPuppiSDsubjet0matchedgenjetpt;
   Float_t         JetPuppiSDsubjet0tau1;
   Float_t         JetPuppiSDsubjet0tau2;
   Float_t         JetPuppiSDsubjet0tau3;
   Float_t         JetPuppiSDsubjet0bdisc;
   Float_t         JetPuppiSDsubjet1pt;
   Float_t         JetPuppiSDsubjet1mass;
   Float_t         JetPuppiSDsubjet1eta;
   Float_t         JetPuppiSDsubjet1phi;
   Float_t         JetPuppiSDsubjet1area;
   Float_t         JetPuppiSDsubjet1flavHadron;
   Float_t         JetPuppiSDsubjet1flavParton;
   Float_t         JetPuppiSDsubjet1matchedgenjetpt;
   Float_t         JetPuppiSDsubjet1tau1;
   Float_t         JetPuppiSDsubjet1tau2;
   Float_t         JetPuppiSDsubjet1tau3;
   Float_t         JetPuppiSDECF1;
   Float_t         JetPuppiSDECF2;
   Float_t         JetPuppiSDECF3;
   Float_t         JetPuppiSDECF4;
   Float_t         JetPuppiSDECF5;
   Float_t         JetPuppiSDC_2;
   Float_t         JetPuppiSDD_2;
   Float_t         JetPuppiSDC_3;
   Float_t         JetPuppiSDD_3;
   Float_t         JetPuppiSDsubjet1bdisc;
   Float_t         JetCHF;
   Float_t         JetNHF;
   Float_t         JetCM;
   Float_t         JetNM;
   Float_t         JetNEF;
   Float_t         JetCEF;
   Float_t         JetMF;
   Float_t         JetMult;
   Float_t         JetPuppiCHF;
   Float_t         JetPuppiNHF;
   Float_t         JetPuppiCM;
   Float_t         JetPuppiNM;
   Float_t         JetPuppiNEF;
   Float_t         JetPuppiCEF;
   Float_t         JetPuppiMF;
   Float_t         JetPuppiMult;
   Float_t         JetMassCorrFactor;
   Float_t         JetMassCorrFactorUp;
   Float_t         JetMassCorrFactorDn;
   Float_t         JetCorrFactor;
   Float_t         JetCorrFactorUp;
   Float_t         JetCorrFactorDn;
   Float_t         JetPtSmearFactor;
   Float_t         JetPtSmearFactorUp;
   Float_t         JetPtSmearFactorDn;
   Float_t         JetPuppiMassCorrFactor;
   Float_t         JetPuppiMassCorrFactorUp;
   Float_t         JetPuppiMassCorrFactorDn;
   Float_t         JetPuppiCorrFactor;
   Float_t         JetPuppiCorrFactorUp;
   Float_t         JetPuppiCorrFactorDn;
   Float_t         JetPuppiPtSmearFactor;
   Float_t         JetPuppiPtSmearFactorUp;
   Float_t         JetPuppiPtSmearFactorDn;
   Float_t         JetMatchedGenJetPt;
   Float_t         JetMatchedGenJetMass;
   Float_t         JetPuppiMatchedGenJetPt;
   Float_t         JetPuppiMatchedGenJetMass;
   Int_t           JetGenMatched_TopHadronic;
   Float_t         JetGenMatched_TopPt;
   Float_t         JetGenMatched_TopEta;
   Float_t         JetGenMatched_TopPhi;
   Float_t         JetGenMatched_TopMass;
   Float_t         JetGenMatched_bPt;
   Float_t         JetGenMatched_WPt;
   Float_t         JetGenMatched_Wd1Pt;
   Float_t         JetGenMatched_Wd2Pt;
   Float_t         JetGenMatched_Wd1ID;
   Float_t         JetGenMatched_Wd2ID;
   Float_t         JetGenMatched_MaxDeltaRPartonTop;
   Float_t         JetGenMatched_MaxDeltaRWPartonTop;
   Float_t         JetGenMatched_MaxDeltaRWPartonW;
   Float_t         JetGenMatched_DeltaR_t_b;
   Float_t         JetGenMatched_DeltaR_t_W;
   Float_t         JetGenMatched_DeltaR_t_Wd1;
   Float_t         JetGenMatched_DeltaR_t_Wd2;
   Float_t         JetGenMatched_DeltaR_W_b1;
   Float_t         JetGenMatched_DeltaR_W_Wd1;
   Float_t         JetGenMatched_DeltaR_W_Wd2;
   Float_t         JetGenMatched_DeltaR_Wd1_Wd2;
   Float_t         JetGenMatched_DeltaR_Wd1_b;
   Float_t         JetGenMatched_DeltaR_Wd2_b;
   Float_t         JetGenMatched_DeltaR_jet_t;
   Float_t         JetGenMatched_DeltaR_jet_W;
   Float_t         JetGenMatched_DeltaR_jet_b;
   Float_t         JetGenMatched_DeltaR_jet_Wd1;
   Float_t         JetGenMatched_DeltaR_jet_Wd2;
   Float_t         JetGenMatched_DeltaR_pup0_b;
   Float_t         JetGenMatched_DeltaR_pup0_Wd1;
   Float_t         JetGenMatched_DeltaR_pup0_Wd2;
   Float_t         JetGenMatched_DeltaR_pup1_b;
   Float_t         JetGenMatched_DeltaR_pup1_Wd1;
   Float_t         JetGenMatched_DeltaR_pup1_Wd2;
   Float_t         JetGenMatched_partonPt;
   Float_t         JetGenMatched_partonEta;
   Float_t         JetGenMatched_partonPhi;
   Float_t         JetGenMatched_partonMass;
   Float_t         JetGenMatched_partonID;
   Float_t         JetGenMatched_DeltaRjetParton;
   Float_t         HadMETpx;
   Float_t         HadMETpy;
   Float_t         HadMETpt;
   Float_t         HadMETphi;
   Float_t         HadMETsumET;
   Float_t         HadMETgenMET;
   Float_t         HadMETuncorPt;
   Float_t         HadMETshiftedPtJetEnUp;
   Float_t         HadMETshiftedPtJetEnDn;
   Float_t         HadMETshiftedPtElEnUp;
   Float_t         HadMETshiftedPtElEnDn;
   Float_t         HadMETshiftedPtMuEnUp;
   Float_t         HadMETshiftedPtMuEnDn;
   Float_t         HadMETshiftedPtJetResUp;
   Float_t         HadMETshiftedPtJetResDn;
   Float_t         HadMETshiftedPtUnclEnUp;
   Float_t         HadMETshiftedPtUnclEnDn;
   Float_t         HadNvtx;
   Float_t         HadNvtxGood;
   Float_t         HadRho;
   Float_t         HadEventWeight;
   Float_t         HadPUweight;
   Float_t         HadPUweight_MBup;
   Float_t         HadPUweight_MBdn;
   Float_t         HadGenTTmass;
   Int_t           HadGenCountHadTop;
   Float_t         HTlep;
   Float_t         ST;
   Float_t         ST_CorrDn;
   Float_t         ST_CorrUp;
   Float_t         ST_PtSmearNom;
   Float_t         ST_PtSmearUp;
   Float_t         ST_PtSmearDn;
   Float_t         HadQ2weight_CorrDn;
   Float_t         HadQ2weight_CorrUp;
   Float_t         HadNNPDF3weight_CorrDn;
   Float_t         HadNNPDF3weight_CorrUp;
   Int_t           HadRunNum;
   Int_t           HadLumiBlock;
   Int_t           HadEventNum;
   Int_t           HadPassMETFilters;
   Float_t         CA12JetPtRaw;
   Float_t         CA12JetEtaRaw;
   Float_t         CA12JetPhiRaw;
   Float_t         CA12JetMassRaw;
   Float_t         CA12JetTau1;
   Float_t         CA12JetTau2;
   Float_t         CA12JetTau3;
   Float_t         CA12JetTau4;
   Float_t         CA12JetTau32;
   Float_t         CA12JetTau21;
   Float_t         CA12Jetsubjet0bdisc;
   Float_t         CA12Jetsubjet1bdisc;
   Float_t         CA12Jetmaxbdisc;
   Float_t         CA12Jetsubjet0pt;
   Float_t         CA12Jetsubjet0mass;
   Float_t         CA12Jetsubjet0eta;
   Float_t         CA12Jetsubjet0phi;
   Float_t         CA12Jetsubjet0area;
   Float_t         CA12Jetsubjet1pt;
   Float_t         CA12Jetsubjet1mass;
   Float_t         CA12Jetsubjet1eta;
   Float_t         CA12Jetsubjet1phi;
   Float_t         CA12Jetsubjet1area;
   Float_t         AK4ReconstructedJetPt;
   Float_t         AK4ReconstructedJetEta;
   Float_t         AK4ReconstructedJetPhi;
   Float_t         AK4ReconstructedJetMass;
   Float_t         AK4bJetPtRaw;
   Float_t         AK4bJetEtaRaw;
   Float_t         AK4bJetPhiRaw;
   Float_t         AK4bJetMassRaw;
   Float_t         AK4bJet_PtSmear;
   Float_t         AK4bJet_PtSmearUp;
   Float_t         AK4bJet_PtSmearDn;
   Float_t         AK4bJet_PtUncorr;
   Float_t         AK4bJet_Corr;
   Float_t         AK4bJet_CorrUp;
   Float_t         AK4bJet_CorrDn;
   Float_t         AK4bJet_bDisc;
   Float_t         AK4WJetPtRaw;
   Float_t         AK4WJetEtaRaw;
   Float_t         AK4WJetPhiRaw;
   Float_t         AK4WJetMassRaw;
   Float_t         AK4WJet_PtSmear;
   Float_t         AK4WJet_PtSmearUp;
   Float_t         AK4WJet_PtSmearDn;
   Float_t         AK4WJet_PtUncorr;
   Float_t         AK4WJet_Corr;
   Float_t         AK4WJet_CorrUp;
   Float_t         AK4WJet_CorrDn;
   Float_t         AK4WJet_bDisc;
   Float_t         AK4W2JetPtRaw;
   Float_t         AK4W2JetEtaRaw;
   Float_t         AK4W2JetPhiRaw;
   Float_t         AK4W2JetMassRaw;
   Float_t         AK4W2Jet_PtSmear;
   Float_t         AK4W2Jet_PtSmearUp;
   Float_t         AK4W2Jet_PtSmearDn;
   Float_t         AK4W2Jet_PtUncorr;
   Float_t         AK4W2Jet_Corr;
   Float_t         AK4W2Jet_CorrUp;
   Float_t         AK4W2Jet_CorrDn;
   Float_t         AK4W2Jet_bDisc;
   Float_t         MuPhi;
   Float_t         MuPt;
   Float_t         MuEta;
   Float_t         MuMass;
   Int_t           MuMedium;
   Int_t           MuTight;
   Float_t         MuIso;

   // List of branches
   TBranch        *b_HadTrigPrescales;   //!
   TBranch        *b_HadTrigPass;   //!
   TBranch        *b_HadTrigAcceptBits;   //!
   TBranch        *b_Gen_array_t_p4;   //!
   TBranch        *b_Gen_array_final_t_p4;   //!
   TBranch        *b_Gen_array_b_p4;   //!
   TBranch        *b_Gen_array_W_p4;   //!
   TBranch        *b_Gen_array_Wd1_p4;   //!
   TBranch        *b_Gen_array_Wd2_p4;   //!
   TBranch        *b_Gen_array_hardest_parton_hardScatterOutgoing_p4;   //!
   TBranch        *b_Gen_array_second_hardest_parton_hardScatterOutgoing_p4;   //!
   TBranch        *b_tophadronic;   //!
   TBranch        *b_topleptonic;   //!
   TBranch        *b_parton1id;   //!
   TBranch        *b_parton2id;   //!
   TBranch        *b_Wd1_id;   //!
   TBranch        *b_Wd2_id;   //!
   TBranch        *b_JetPtRaw;   //!
   TBranch        *b_JetEtaRaw;   //!
   TBranch        *b_JetPhiRaw;   //!
   TBranch        *b_JetMassRaw;   //!
   TBranch        *b_JetArea;   //!
   TBranch        *b_JetSDmassRaw;   //!
   TBranch        *b_JetSDmassSubjetCorrL23;   //!
   TBranch        *b_JetSDmassSubjetCorrL123;   //!
   TBranch        *b_JetSDptRaw;   //!
   TBranch        *b_JetSDetaRaw;   //!
   TBranch        *b_JetSDphiRaw;   //!
   TBranch        *b_JetMassPruned;   //!
   TBranch        *b_JetMassTrimmed;   //!
   TBranch        *b_JetTau1;   //!
   TBranch        *b_JetTau2;   //!
   TBranch        *b_JetTau3;   //!
   TBranch        *b_JetTau4;   //!
   TBranch        *b_JetTau32;   //!
   TBranch        *b_JetTau21;   //!
   TBranch        *b_JetSDmaxbdisc;   //!
   TBranch        *b_JetSDmaxbdiscflavHadron;   //!
   TBranch        *b_JetSDmaxbdiscflavParton;   //!
   TBranch        *b_JetSDsubjet0pt;   //!
   TBranch        *b_JetSDsubjet0mass;   //!
   TBranch        *b_JetSDsubjet0eta;   //!
   TBranch        *b_JetSDsubjet0phi;   //!
   TBranch        *b_JetSDsubjet0area;   //!
   TBranch        *b_JetSDsubjet0flavHadron;   //!
   TBranch        *b_JetSDsubjet0flavParton;   //!
   TBranch        *b_JetSDsubjet0matchedgenjetpt;   //!
   TBranch        *b_JetSDsubjet0tau1;   //!
   TBranch        *b_JetSDsubjet0tau2;   //!
   TBranch        *b_JetSDsubjet0tau3;   //!
   TBranch        *b_JetSDsubjet0bdisc;   //!
   TBranch        *b_JetSDsubjet1pt;   //!
   TBranch        *b_JetSDsubjet1mass;   //!
   TBranch        *b_JetSDsubjet1eta;   //!
   TBranch        *b_JetSDsubjet1phi;   //!
   TBranch        *b_JetSDsubjet1area;   //!
   TBranch        *b_JetSDsubjet1flavHadron;   //!
   TBranch        *b_JetSDsubjet1flavParton;   //!
   TBranch        *b_JetSDsubjet1matchedgenjetpt;   //!
   TBranch        *b_JetSDsubjet1tau1;   //!
   TBranch        *b_JetSDsubjet1tau2;   //!
   TBranch        *b_JetSDsubjet1tau3;   //!
   TBranch        *b_JetSDsubjet1bdisc;   //!
   TBranch        *b_JetPuppiPtRaw;   //!
   TBranch        *b_JetPuppiEtaRaw;   //!
   TBranch        *b_JetPuppiPhiRaw;   //!
   TBranch        *b_JetPuppiMassRaw;   //!
   TBranch        *b_JetPuppiArea;   //!
   TBranch        *b_JetPuppiMassPruned;   //!
   TBranch        *b_JetPuppiMassTrimmed;   //!
   TBranch        *b_JetPuppiSDmassRaw;   //!
   TBranch        *b_JetPuppiSDmassSubjetCorr;   //!
   TBranch        *b_JetPuppiSDptRaw;   //!
   TBranch        *b_JetPuppiSDetaRaw;   //!
   TBranch        *b_JetPuppiSDphiRaw;   //!
   TBranch        *b_JetPuppiTau1;   //!
   TBranch        *b_JetPuppiTau2;   //!
   TBranch        *b_JetPuppiTau3;   //!
   TBranch        *b_JetPuppiTau4;   //!
   TBranch        *b_JetPuppiTau32;   //!
   TBranch        *b_JetPuppiTau21;   //!
   TBranch        *b_JetPuppiSDmaxbdisc;   //!
   TBranch        *b_JetPuppiSDmaxbdiscflavHadron;   //!
   TBranch        *b_JetPuppiSDmaxbdiscflavParton;   //!
   TBranch        *b_JetPuppiSDsubjet0pt;   //!
   TBranch        *b_JetPuppiSDsubjet0mass;   //!
   TBranch        *b_JetPuppiSDsubjet0eta;   //!
   TBranch        *b_JetPuppiSDsubjet0phi;   //!
   TBranch        *b_JetPuppiSDsubjet0area;   //!
   TBranch        *b_JetPuppiSDsubjet0flavHadron;   //!
   TBranch        *b_JetPuppiSDsubjet0flavParton;   //!
   TBranch        *b_JetPuppiSDsubjet0matchedgenjetpt;   //!
   TBranch        *b_JetPuppiSDsubjet0tau1;   //!
   TBranch        *b_JetPuppiSDsubjet0tau2;   //!
   TBranch        *b_JetPuppiSDsubjet0tau3;   //!
   TBranch        *b_JetPuppiSDsubjet0bdisc;   //!
   TBranch        *b_JetPuppiSDsubjet1pt;   //!
   TBranch        *b_JetPuppiSDsubjet1mass;   //!
   TBranch        *b_JetPuppiSDsubjet1eta;   //!
   TBranch        *b_JetPuppiSDsubjet1phi;   //!
   TBranch        *b_JetPuppiSDsubjet1area;   //!
   TBranch        *b_JetPuppiSDsubjet1flavHadron;   //!
   TBranch        *b_JetPuppiSDsubjet1flavParton;   //!
   TBranch        *b_JetPuppiSDsubjet1matchedgenjetpt;   //!
   TBranch        *b_JetPuppiSDsubjet1tau1;   //!
   TBranch        *b_JetPuppiSDsubjet1tau2;   //!
   TBranch        *b_JetPuppiSDsubjet1tau3;   //!
   TBranch        *b_JetPuppiSDECF1;   //!
   TBranch        *b_JetPuppiSDECF2;   //!
   TBranch        *b_JetPuppiSDECF3;   //!
   TBranch        *b_JetPuppiSDECF4;   //!
   TBranch        *b_JetPuppiSDECF5;   //!
   TBranch        *b_JetPuppiSDC_2;   //!
   TBranch        *b_JetPuppiSDD_2;   //!
   TBranch        *b_JetPuppiSDC_3;   //!
   TBranch        *b_JetPuppiSDD_3;   //!
   TBranch        *b_JetPuppiSDsubjet1bdisc;   //!
   TBranch        *b_JetCHF;   //!
   TBranch        *b_JetNHF;   //!
   TBranch        *b_JetCM;   //!
   TBranch        *b_JetNM;   //!
   TBranch        *b_JetNEF;   //!
   TBranch        *b_JetCEF;   //!
   TBranch        *b_JetMF;   //!
   TBranch        *b_JetMult;   //!
   TBranch        *b_JetPuppiCHF;   //!
   TBranch        *b_JetPuppiNHF;   //!
   TBranch        *b_JetPuppiCM;   //!
   TBranch        *b_JetPuppiNM;   //!
   TBranch        *b_JetPuppiNEF;   //!
   TBranch        *b_JetPuppiCEF;   //!
   TBranch        *b_JetPuppiMF;   //!
   TBranch        *b_JetPuppiMult;   //!
   TBranch        *b_JetMassCorrFactor;   //!
   TBranch        *b_JetMassCorrFactorUp;   //!
   TBranch        *b_JetMassCorrFactorDn;   //!
   TBranch        *b_JetCorrFactor;   //!
   TBranch        *b_JetCorrFactorUp;   //!
   TBranch        *b_JetCorrFactorDn;   //!
   TBranch        *b_JetPtSmearFactor;   //!
   TBranch        *b_JetPtSmearFactorUp;   //!
   TBranch        *b_JetPtSmearFactorDn;   //!
   TBranch        *b_JetPuppiMassCorrFactor;   //!
   TBranch        *b_JetPuppiMassCorrFactorUp;   //!
   TBranch        *b_JetPuppiMassCorrFactorDn;   //!
   TBranch        *b_JetPuppiCorrFactor;   //!
   TBranch        *b_JetPuppiCorrFactorUp;   //!
   TBranch        *b_JetPuppiCorrFactorDn;   //!
   TBranch        *b_JetPuppiPtSmearFactor;   //!
   TBranch        *b_JetPuppiPtSmearFactorUp;   //!
   TBranch        *b_JetPuppiPtSmearFactorDn;   //!
   TBranch        *b_JetMatchedGenJetPt;   //!
   TBranch        *b_JetMatchedGenJetMass;   //!
   TBranch        *b_JetPuppiMatchedGenJetPt;   //!
   TBranch        *b_JetPuppiMatchedGenJetMass;   //!
   TBranch        *b_JetGenMatched_TopHadronic;   //!
   TBranch        *b_JetGenMatched_TopPt;   //!
   TBranch        *b_JetGenMatched_TopEta;   //!
   TBranch        *b_JetGenMatched_TopPhi;   //!
   TBranch        *b_JetGenMatched_TopMass;   //!
   TBranch        *b_JetGenMatched_bPt;   //!
   TBranch        *b_JetGenMatched_WPt;   //!
   TBranch        *b_JetGenMatched_Wd1Pt;   //!
   TBranch        *b_JetGenMatched_Wd2Pt;   //!
   TBranch        *b_JetGenMatched_Wd1ID;   //!
   TBranch        *b_JetGenMatched_Wd2ID;   //!
   TBranch        *b_JetGenMatched_MaxDeltaRPartonTop;   //!
   TBranch        *b_JetGenMatched_MaxDeltaRWPartonTop;   //!
   TBranch        *b_JetGenMatched_MaxDeltaRWPartonW;   //!
   TBranch        *b_JetGenMatched_DeltaR_t_b;   //!
   TBranch        *b_JetGenMatched_DeltaR_t_W;   //!
   TBranch        *b_JetGenMatched_DeltaR_t_Wd1;   //!
   TBranch        *b_JetGenMatched_DeltaR_t_Wd2;   //!
   TBranch        *b_JetGenMatched_DeltaR_W_b1;   //!
   TBranch        *b_JetGenMatched_DeltaR_W_Wd1;   //!
   TBranch        *b_JetGenMatched_DeltaR_W_Wd2;   //!
   TBranch        *b_JetGenMatched_DeltaR_Wd1_Wd2;   //!
   TBranch        *b_JetGenMatched_DeltaR_Wd1_b;   //!
   TBranch        *b_JetGenMatched_DeltaR_Wd2_b;   //!
   TBranch        *b_JetGenMatched_DeltaR_jet_t;   //!
   TBranch        *b_JetGenMatched_DeltaR_jet_W;   //!
   TBranch        *b_JetGenMatched_DeltaR_jet_b;   //!
   TBranch        *b_JetGenMatched_DeltaR_jet_Wd1;   //!
   TBranch        *b_JetGenMatched_DeltaR_jet_Wd2;   //!
   TBranch        *b_JetGenMatched_DeltaR_pup0_b;   //!
   TBranch        *b_JetGenMatched_DeltaR_pup0_Wd1;   //!
   TBranch        *b_JetGenMatched_DeltaR_pup0_Wd2;   //!
   TBranch        *b_JetGenMatched_DeltaR_pup1_b;   //!
   TBranch        *b_JetGenMatched_DeltaR_pup1_Wd1;   //!
   TBranch        *b_JetGenMatched_DeltaR_pup1_Wd2;   //!
   TBranch        *b_JetGenMatched_partonPt;   //!
   TBranch        *b_JetGenMatched_partonEta;   //!
   TBranch        *b_JetGenMatched_partonPhi;   //!
   TBranch        *b_JetGenMatched_partonMass;   //!
   TBranch        *b_JetGenMatched_partonID;   //!
   TBranch        *b_JetGenMatched_DeltaRjetParton;   //!
   TBranch        *b_HadMETpx;   //!
   TBranch        *b_HadMETpy;   //!
   TBranch        *b_HadMETpt;   //!
   TBranch        *b_HadMETphi;   //!
   TBranch        *b_HadMETsumET;   //!
   TBranch        *b_HadMETgenMET;   //!
   TBranch        *b_HadMETuncorPt;   //!
   TBranch        *b_HadMETshiftedPtJetEnUp;   //!
   TBranch        *b_HadMETshiftedPtJetEnDn;   //!
   TBranch        *b_HadMETshiftedPtElEnUp;   //!
   TBranch        *b_HadMETshiftedPtElEnDn;   //!
   TBranch        *b_HadMETshiftedPtMuEnUp;   //!
   TBranch        *b_HadMETshiftedPtMuEnDn;   //!
   TBranch        *b_HadMETshiftedPtJetResUp;   //!
   TBranch        *b_HadMETshiftedPtJetResDn;   //!
   TBranch        *b_HadMETshiftedPtUnclEnUp;   //!
   TBranch        *b_HadMETshiftedPtUnclEnDn;   //!
   TBranch        *b_HadNvtx;   //!
   TBranch        *b_HadNvtxGood;   //!
   TBranch        *b_HadRho;   //!
   TBranch        *b_HadEventWeight;   //!
   TBranch        *b_HadPUweight;   //!
   TBranch        *b_HadPUweight_MBup;   //!
   TBranch        *b_HadPUweight_MBdn;   //!
   TBranch        *b_HadGenTTmass;   //!
   TBranch        *b_HadGenCountHadTop;   //!
   TBranch        *b_HTlep;   //!
   TBranch        *b_ST;   //!
   TBranch        *b_ST_CorrDn;   //!
   TBranch        *b_ST_CorrUp;   //!
   TBranch        *b_ST_PtSmearNom;   //!
   TBranch        *b_ST_PtSmearUp;   //!
   TBranch        *b_ST_PtSmearDn;   //!
   TBranch        *b_HadQ2weight_CorrDn;   //!
   TBranch        *b_HadQ2weight_CorrUp;   //!
   TBranch        *b_HadNNPDF3weight_CorrDn;   //!
   TBranch        *b_HadNNPDF3weight_CorrUp;   //!
   TBranch        *b_HadRunNum;   //!
   TBranch        *b_HadLumiBlock;   //!
   TBranch        *b_HadEventNum;   //!
   TBranch        *b_HadPassMETFilters;   //!
   TBranch        *b_CA12JetPtRaw;   //!
   TBranch        *b_CA12JetEtaRaw;   //!
   TBranch        *b_CA12JetPhiRaw;   //!
   TBranch        *b_CA12JetMassRaw;   //!
   TBranch        *b_CA12JetTau1;   //!
   TBranch        *b_CA12JetTau2;   //!
   TBranch        *b_CA12JetTau3;   //!
   TBranch        *b_CA12JetTau4;   //!
   TBranch        *b_CA12JetTau32;   //!
   TBranch        *b_CA12JetTau21;   //!
   TBranch        *b_CA12Jetsubjet0bdisc;   //!
   TBranch        *b_CA12Jetsubjet1bdisc;   //!
   TBranch        *b_CA12Jetmaxbdisc;   //!
   TBranch        *b_CA12Jetsubjet0pt;   //!
   TBranch        *b_CA12Jetsubjet0mass;   //!
   TBranch        *b_CA12Jetsubjet0eta;   //!
   TBranch        *b_CA12Jetsubjet0phi;   //!
   TBranch        *b_CA12Jetsubjet0area;   //!
   TBranch        *b_CA12Jetsubjet1pt;   //!
   TBranch        *b_CA12Jetsubjet1mass;   //!
   TBranch        *b_CA12Jetsubjet1eta;   //!
   TBranch        *b_CA12Jetsubjet1phi;   //!
   TBranch        *b_CA12Jetsubjet1area;   //!
   TBranch        *b_AK4ReconstructedJetPt;   //!
   TBranch        *b_AK4ReconstructedJetEta;   //!
   TBranch        *b_AK4ReconstructedJetPhi;   //!
   TBranch        *b_AK4ReconstructedJetMass;   //!
   TBranch        *b_AK4bJetPtRaw;   //!
   TBranch        *b_AK4bJetEtaRaw;   //!
   TBranch        *b_AK4bJetPhiRaw;   //!
   TBranch        *b_AK4bJetMassRaw;   //!
   TBranch        *b_AK4bJet_PtSmear;   //!
   TBranch        *b_AK4bJet_PtSmearUp;   //!
   TBranch        *b_AK4bJet_PtSmearDn;   //!
   TBranch        *b_AK4bJet_PtUncorr;   //!
   TBranch        *b_AK4bJet_Corr;   //!
   TBranch        *b_AK4bJet_CorrUp;   //!
   TBranch        *b_AK4bJet_CorrDn;   //!
   TBranch        *b_AK4bJet_bDisc;   //!
   TBranch        *b_AK4WJetPtRaw;   //!
   TBranch        *b_AK4WJetEtaRaw;   //!
   TBranch        *b_AK4WJetPhiRaw;   //!
   TBranch        *b_AK4WJetMassRaw;   //!
   TBranch        *b_AK4WJet_PtSmear;   //!
   TBranch        *b_AK4WJet_PtSmearUp;   //!
   TBranch        *b_AK4WJet_PtSmearDn;   //!
   TBranch        *b_AK4WJet_PtUncorr;   //!
   TBranch        *b_AK4WJet_Corr;   //!
   TBranch        *b_AK4WJet_CorrUp;   //!
   TBranch        *b_AK4WJet_CorrDn;   //!
   TBranch        *b_AK4WJet_bDisc;   //!
   TBranch        *b_AK4W2JetPtRaw;   //!
   TBranch        *b_AK4W2JetEtaRaw;   //!
   TBranch        *b_AK4W2JetPhiRaw;   //!
   TBranch        *b_AK4W2JetMassRaw;   //!
   TBranch        *b_AK4W2Jet_PtSmear;   //!
   TBranch        *b_AK4W2Jet_PtSmearUp;   //!
   TBranch        *b_AK4W2Jet_PtSmearDn;   //!
   TBranch        *b_AK4W2Jet_PtUncorr;   //!
   TBranch        *b_AK4W2Jet_Corr;   //!
   TBranch        *b_AK4W2Jet_CorrUp;   //!
   TBranch        *b_AK4W2Jet_CorrDn;   //!
   TBranch        *b_AK4W2Jet_bDisc;   //!
   TBranch        *b_MuPhi;   //!
   TBranch        *b_MuPt;   //!
   TBranch        *b_MuEta;   //!
   TBranch        *b_MuMass;   //!
   TBranch        *b_MuMedium;   //!
   TBranch        *b_MuTight;   //!
   TBranch        *b_MuIso;   //!


   HadTree_Oct_12_17(TTree *tree=0);
   virtual ~HadTree_Oct_12_17();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(std::string outFileName, Bool_t gen);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HadTree_Oct_12_17_cxx
HadTree_Oct_12_17::HadTree_Oct_12_17(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/uscms_data/d3/rmueller/MonoTop/B2GAnaFW_ttbar/custom_B2GTTbar/CMSSW_8_0_26/src/Analysis/B2GMonoTop/test/b2gtreeV5_MC_MonoTop_lh.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/uscms_data/d3/rmueller/MonoTop/B2GAnaFW_ttbar/custom_B2GTTbar/CMSSW_8_0_26/src/Analysis/B2GMonoTop/test/b2gtreeV5_MC_MonoTop_lh.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/uscms_data/d3/rmueller/MonoTop/B2GAnaFW_ttbar/custom_B2GTTbar/CMSSW_8_0_26/src/Analysis/B2GMonoTop/test/b2gtreeV5_MC_MonoTop_lh.root:/ana");
      dir->GetObject("TreeHad",tree);

   }
   Init(tree);
}

HadTree_Oct_12_17::~HadTree_Oct_12_17()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HadTree_Oct_12_17::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HadTree_Oct_12_17::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HadTree_Oct_12_17::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   HadTrigPrescales = 0;
   HadTrigPass = 0;
   HadTrigAcceptBits = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("HadTrigPrescales", &HadTrigPrescales, &b_HadTrigPrescales);
   fChain->SetBranchAddress("HadTrigPass", &HadTrigPass, &b_HadTrigPass);
   fChain->SetBranchAddress("HadTrigAcceptBits", &HadTrigAcceptBits, &b_HadTrigAcceptBits);
   fChain->SetBranchAddress("Gen_array_t_p4", Gen_array_t_p4, &b_Gen_array_t_p4);
   fChain->SetBranchAddress("Gen_array_final_t_p4", Gen_array_final_t_p4, &b_Gen_array_final_t_p4);
   fChain->SetBranchAddress("Gen_array_b_p4", Gen_array_b_p4, &b_Gen_array_b_p4);
   fChain->SetBranchAddress("Gen_array_W_p4", Gen_array_W_p4, &b_Gen_array_W_p4);
   fChain->SetBranchAddress("Gen_array_Wd1_p4", Gen_array_Wd1_p4, &b_Gen_array_Wd1_p4);
   fChain->SetBranchAddress("Gen_array_Wd2_p4", Gen_array_Wd2_p4, &b_Gen_array_Wd2_p4);
   fChain->SetBranchAddress("Gen_array_hardest_parton_hardScatterOutgoing_p4", Gen_array_hardest_parton_hardScatterOutgoing_p4, &b_Gen_array_hardest_parton_hardScatterOutgoing_p4);
   fChain->SetBranchAddress("Gen_array_second_hardest_parton_hardScatterOutgoing_p4", Gen_array_second_hardest_parton_hardScatterOutgoing_p4, &b_Gen_array_second_hardest_parton_hardScatterOutgoing_p4);
   fChain->SetBranchAddress("tophadronic", &tophadronic, &b_tophadronic);
   fChain->SetBranchAddress("topleptonic", &topleptonic, &b_topleptonic);
   fChain->SetBranchAddress("parton1id", &parton1id, &b_parton1id);
   fChain->SetBranchAddress("parton2id", &parton2id, &b_parton2id);
   fChain->SetBranchAddress("Wd1_id", &Wd1_id, &b_Wd1_id);
   fChain->SetBranchAddress("Wd2_id", &Wd2_id, &b_Wd2_id);
   fChain->SetBranchAddress("JetPtRaw", &JetPtRaw, &b_JetPtRaw);
   fChain->SetBranchAddress("JetEtaRaw", &JetEtaRaw, &b_JetEtaRaw);
   fChain->SetBranchAddress("JetPhiRaw", &JetPhiRaw, &b_JetPhiRaw);
   fChain->SetBranchAddress("JetMassRaw", &JetMassRaw, &b_JetMassRaw);
   fChain->SetBranchAddress("JetArea", &JetArea, &b_JetArea);
   fChain->SetBranchAddress("JetSDmassRaw", &JetSDmassRaw, &b_JetSDmassRaw);
   fChain->SetBranchAddress("JetSDmassSubjetCorrL23", &JetSDmassSubjetCorrL23, &b_JetSDmassSubjetCorrL23);
   fChain->SetBranchAddress("JetSDmassSubjetCorrL123", &JetSDmassSubjetCorrL123, &b_JetSDmassSubjetCorrL123);
   fChain->SetBranchAddress("JetSDptRaw", &JetSDptRaw, &b_JetSDptRaw);
   fChain->SetBranchAddress("JetSDetaRaw", &JetSDetaRaw, &b_JetSDetaRaw);
   fChain->SetBranchAddress("JetSDphiRaw", &JetSDphiRaw, &b_JetSDphiRaw);
   fChain->SetBranchAddress("JetMassPruned", &JetMassPruned, &b_JetMassPruned);
   fChain->SetBranchAddress("JetMassTrimmed", &JetMassTrimmed, &b_JetMassTrimmed);
   fChain->SetBranchAddress("JetTau1", &JetTau1, &b_JetTau1);
   fChain->SetBranchAddress("JetTau2", &JetTau2, &b_JetTau2);
   fChain->SetBranchAddress("JetTau3", &JetTau3, &b_JetTau3);
   fChain->SetBranchAddress("JetTau4", &JetTau4, &b_JetTau4);
   fChain->SetBranchAddress("JetTau32", &JetTau32, &b_JetTau32);
   fChain->SetBranchAddress("JetTau21", &JetTau21, &b_JetTau21);
   fChain->SetBranchAddress("JetSDmaxbdisc", &JetSDmaxbdisc, &b_JetSDmaxbdisc);
   fChain->SetBranchAddress("JetSDmaxbdiscflavHadron", &JetSDmaxbdiscflavHadron, &b_JetSDmaxbdiscflavHadron);
   fChain->SetBranchAddress("JetSDmaxbdiscflavParton", &JetSDmaxbdiscflavParton, &b_JetSDmaxbdiscflavParton);
   fChain->SetBranchAddress("JetSDsubjet0pt", &JetSDsubjet0pt, &b_JetSDsubjet0pt);
   fChain->SetBranchAddress("JetSDsubjet0mass", &JetSDsubjet0mass, &b_JetSDsubjet0mass);
   fChain->SetBranchAddress("JetSDsubjet0eta", &JetSDsubjet0eta, &b_JetSDsubjet0eta);
   fChain->SetBranchAddress("JetSDsubjet0phi", &JetSDsubjet0phi, &b_JetSDsubjet0phi);
   fChain->SetBranchAddress("JetSDsubjet0area", &JetSDsubjet0area, &b_JetSDsubjet0area);
   fChain->SetBranchAddress("JetSDsubjet0flavHadron", &JetSDsubjet0flavHadron, &b_JetSDsubjet0flavHadron);
   fChain->SetBranchAddress("JetSDsubjet0flavParton", &JetSDsubjet0flavParton, &b_JetSDsubjet0flavParton);
   fChain->SetBranchAddress("JetSDsubjet0matchedgenjetpt", &JetSDsubjet0matchedgenjetpt, &b_JetSDsubjet0matchedgenjetpt);
   fChain->SetBranchAddress("JetSDsubjet0tau1", &JetSDsubjet0tau1, &b_JetSDsubjet0tau1);
   fChain->SetBranchAddress("JetSDsubjet0tau2", &JetSDsubjet0tau2, &b_JetSDsubjet0tau2);
   fChain->SetBranchAddress("JetSDsubjet0tau3", &JetSDsubjet0tau3, &b_JetSDsubjet0tau3);
   fChain->SetBranchAddress("JetSDsubjet0bdisc", &JetSDsubjet0bdisc, &b_JetSDsubjet0bdisc);
   fChain->SetBranchAddress("JetSDsubjet1pt", &JetSDsubjet1pt, &b_JetSDsubjet1pt);
   fChain->SetBranchAddress("JetSDsubjet1mass", &JetSDsubjet1mass, &b_JetSDsubjet1mass);
   fChain->SetBranchAddress("JetSDsubjet1eta", &JetSDsubjet1eta, &b_JetSDsubjet1eta);
   fChain->SetBranchAddress("JetSDsubjet1phi", &JetSDsubjet1phi, &b_JetSDsubjet1phi);
   fChain->SetBranchAddress("JetSDsubjet1area", &JetSDsubjet1area, &b_JetSDsubjet1area);
   fChain->SetBranchAddress("JetSDsubjet1flavHadron", &JetSDsubjet1flavHadron, &b_JetSDsubjet1flavHadron);
   fChain->SetBranchAddress("JetSDsubjet1flavParton", &JetSDsubjet1flavParton, &b_JetSDsubjet1flavParton);
   fChain->SetBranchAddress("JetSDsubjet1matchedgenjetpt", &JetSDsubjet1matchedgenjetpt, &b_JetSDsubjet1matchedgenjetpt);
   fChain->SetBranchAddress("JetSDsubjet1tau1", &JetSDsubjet1tau1, &b_JetSDsubjet1tau1);
   fChain->SetBranchAddress("JetSDsubjet1tau2", &JetSDsubjet1tau2, &b_JetSDsubjet1tau2);
   fChain->SetBranchAddress("JetSDsubjet1tau3", &JetSDsubjet1tau3, &b_JetSDsubjet1tau3);
   fChain->SetBranchAddress("JetSDsubjet1bdisc", &JetSDsubjet1bdisc, &b_JetSDsubjet1bdisc);
   fChain->SetBranchAddress("JetPuppiPtRaw", &JetPuppiPtRaw, &b_JetPuppiPtRaw);
   fChain->SetBranchAddress("JetPuppiEtaRaw", &JetPuppiEtaRaw, &b_JetPuppiEtaRaw);
   fChain->SetBranchAddress("JetPuppiPhiRaw", &JetPuppiPhiRaw, &b_JetPuppiPhiRaw);
   fChain->SetBranchAddress("JetPuppiMassRaw", &JetPuppiMassRaw, &b_JetPuppiMassRaw);
   fChain->SetBranchAddress("JetPuppiArea", &JetPuppiArea, &b_JetPuppiArea);
   fChain->SetBranchAddress("JetPuppiMassPruned", &JetPuppiMassPruned, &b_JetPuppiMassPruned);
   fChain->SetBranchAddress("JetPuppiMassTrimmed", &JetPuppiMassTrimmed, &b_JetPuppiMassTrimmed);
   fChain->SetBranchAddress("JetPuppiSDmassRaw", &JetPuppiSDmassRaw, &b_JetPuppiSDmassRaw);
   fChain->SetBranchAddress("JetPuppiSDmassSubjetCorr", &JetPuppiSDmassSubjetCorr, &b_JetPuppiSDmassSubjetCorr);
   fChain->SetBranchAddress("JetPuppiSDptRaw", &JetPuppiSDptRaw, &b_JetPuppiSDptRaw);
   fChain->SetBranchAddress("JetPuppiSDetaRaw", &JetPuppiSDetaRaw, &b_JetPuppiSDetaRaw);
   fChain->SetBranchAddress("JetPuppiSDphiRaw", &JetPuppiSDphiRaw, &b_JetPuppiSDphiRaw);
   fChain->SetBranchAddress("JetPuppiTau1", &JetPuppiTau1, &b_JetPuppiTau1);
   fChain->SetBranchAddress("JetPuppiTau2", &JetPuppiTau2, &b_JetPuppiTau2);
   fChain->SetBranchAddress("JetPuppiTau3", &JetPuppiTau3, &b_JetPuppiTau3);
   fChain->SetBranchAddress("JetPuppiTau4", &JetPuppiTau4, &b_JetPuppiTau4);
   fChain->SetBranchAddress("JetPuppiTau32", &JetPuppiTau32, &b_JetPuppiTau32);
   fChain->SetBranchAddress("JetPuppiTau21", &JetPuppiTau21, &b_JetPuppiTau21);
   fChain->SetBranchAddress("JetPuppiSDmaxbdisc", &JetPuppiSDmaxbdisc, &b_JetPuppiSDmaxbdisc);
   fChain->SetBranchAddress("JetPuppiSDmaxbdiscflavHadron", &JetPuppiSDmaxbdiscflavHadron, &b_JetPuppiSDmaxbdiscflavHadron);
   fChain->SetBranchAddress("JetPuppiSDmaxbdiscflavParton", &JetPuppiSDmaxbdiscflavParton, &b_JetPuppiSDmaxbdiscflavParton);
   fChain->SetBranchAddress("JetPuppiSDsubjet0pt", &JetPuppiSDsubjet0pt, &b_JetPuppiSDsubjet0pt);
   fChain->SetBranchAddress("JetPuppiSDsubjet0mass", &JetPuppiSDsubjet0mass, &b_JetPuppiSDsubjet0mass);
   fChain->SetBranchAddress("JetPuppiSDsubjet0eta", &JetPuppiSDsubjet0eta, &b_JetPuppiSDsubjet0eta);
   fChain->SetBranchAddress("JetPuppiSDsubjet0phi", &JetPuppiSDsubjet0phi, &b_JetPuppiSDsubjet0phi);
   fChain->SetBranchAddress("JetPuppiSDsubjet0area", &JetPuppiSDsubjet0area, &b_JetPuppiSDsubjet0area);
   fChain->SetBranchAddress("JetPuppiSDsubjet0flavHadron", &JetPuppiSDsubjet0flavHadron, &b_JetPuppiSDsubjet0flavHadron);
   fChain->SetBranchAddress("JetPuppiSDsubjet0flavParton", &JetPuppiSDsubjet0flavParton, &b_JetPuppiSDsubjet0flavParton);
   fChain->SetBranchAddress("JetPuppiSDsubjet0matchedgenjetpt", &JetPuppiSDsubjet0matchedgenjetpt, &b_JetPuppiSDsubjet0matchedgenjetpt);
   fChain->SetBranchAddress("JetPuppiSDsubjet0tau1", &JetPuppiSDsubjet0tau1, &b_JetPuppiSDsubjet0tau1);
   fChain->SetBranchAddress("JetPuppiSDsubjet0tau2", &JetPuppiSDsubjet0tau2, &b_JetPuppiSDsubjet0tau2);
   fChain->SetBranchAddress("JetPuppiSDsubjet0tau3", &JetPuppiSDsubjet0tau3, &b_JetPuppiSDsubjet0tau3);
   fChain->SetBranchAddress("JetPuppiSDsubjet0bdisc", &JetPuppiSDsubjet0bdisc, &b_JetPuppiSDsubjet0bdisc);
   fChain->SetBranchAddress("JetPuppiSDsubjet1pt", &JetPuppiSDsubjet1pt, &b_JetPuppiSDsubjet1pt);
   fChain->SetBranchAddress("JetPuppiSDsubjet1mass", &JetPuppiSDsubjet1mass, &b_JetPuppiSDsubjet1mass);
   fChain->SetBranchAddress("JetPuppiSDsubjet1eta", &JetPuppiSDsubjet1eta, &b_JetPuppiSDsubjet1eta);
   fChain->SetBranchAddress("JetPuppiSDsubjet1phi", &JetPuppiSDsubjet1phi, &b_JetPuppiSDsubjet1phi);
   fChain->SetBranchAddress("JetPuppiSDsubjet1area", &JetPuppiSDsubjet1area, &b_JetPuppiSDsubjet1area);
   fChain->SetBranchAddress("JetPuppiSDsubjet1flavHadron", &JetPuppiSDsubjet1flavHadron, &b_JetPuppiSDsubjet1flavHadron);
   fChain->SetBranchAddress("JetPuppiSDsubjet1flavParton", &JetPuppiSDsubjet1flavParton, &b_JetPuppiSDsubjet1flavParton);
   fChain->SetBranchAddress("JetPuppiSDsubjet1matchedgenjetpt", &JetPuppiSDsubjet1matchedgenjetpt, &b_JetPuppiSDsubjet1matchedgenjetpt);
   fChain->SetBranchAddress("JetPuppiSDsubjet1tau1", &JetPuppiSDsubjet1tau1, &b_JetPuppiSDsubjet1tau1);
   fChain->SetBranchAddress("JetPuppiSDsubjet1tau2", &JetPuppiSDsubjet1tau2, &b_JetPuppiSDsubjet1tau2);
   fChain->SetBranchAddress("JetPuppiSDsubjet1tau3", &JetPuppiSDsubjet1tau3, &b_JetPuppiSDsubjet1tau3);
   fChain->SetBranchAddress("JetPuppiSDECF1", &JetPuppiSDECF1, &b_JetPuppiSDECF1);
   fChain->SetBranchAddress("JetPuppiSDECF2", &JetPuppiSDECF2, &b_JetPuppiSDECF2);
   fChain->SetBranchAddress("JetPuppiSDECF3", &JetPuppiSDECF3, &b_JetPuppiSDECF3);
   fChain->SetBranchAddress("JetPuppiSDECF4", &JetPuppiSDECF4, &b_JetPuppiSDECF4);
   fChain->SetBranchAddress("JetPuppiSDECF5", &JetPuppiSDECF5, &b_JetPuppiSDECF5);
   fChain->SetBranchAddress("JetPuppiSDC_2", &JetPuppiSDC_2, &b_JetPuppiSDC_2);
   fChain->SetBranchAddress("JetPuppiSDD_2", &JetPuppiSDD_2, &b_JetPuppiSDD_2);
   fChain->SetBranchAddress("JetPuppiSDC_3", &JetPuppiSDC_3, &b_JetPuppiSDC_3);
   fChain->SetBranchAddress("JetPuppiSDD_3", &JetPuppiSDD_3, &b_JetPuppiSDD_3);
   fChain->SetBranchAddress("JetPuppiSDsubjet1bdisc", &JetPuppiSDsubjet1bdisc, &b_JetPuppiSDsubjet1bdisc);
   fChain->SetBranchAddress("JetCHF", &JetCHF, &b_JetCHF);
   fChain->SetBranchAddress("JetNHF", &JetNHF, &b_JetNHF);
   fChain->SetBranchAddress("JetCM", &JetCM, &b_JetCM);
   fChain->SetBranchAddress("JetNM", &JetNM, &b_JetNM);
   fChain->SetBranchAddress("JetNEF", &JetNEF, &b_JetNEF);
   fChain->SetBranchAddress("JetCEF", &JetCEF, &b_JetCEF);
   fChain->SetBranchAddress("JetMF", &JetMF, &b_JetMF);
   fChain->SetBranchAddress("JetMult", &JetMult, &b_JetMult);
   fChain->SetBranchAddress("JetPuppiCHF", &JetPuppiCHF, &b_JetPuppiCHF);
   fChain->SetBranchAddress("JetPuppiNHF", &JetPuppiNHF, &b_JetPuppiNHF);
   fChain->SetBranchAddress("JetPuppiCM", &JetPuppiCM, &b_JetPuppiCM);
   fChain->SetBranchAddress("JetPuppiNM", &JetPuppiNM, &b_JetPuppiNM);
   fChain->SetBranchAddress("JetPuppiNEF", &JetPuppiNEF, &b_JetPuppiNEF);
   fChain->SetBranchAddress("JetPuppiCEF", &JetPuppiCEF, &b_JetPuppiCEF);
   fChain->SetBranchAddress("JetPuppiMF", &JetPuppiMF, &b_JetPuppiMF);
   fChain->SetBranchAddress("JetPuppiMult", &JetPuppiMult, &b_JetPuppiMult);
   fChain->SetBranchAddress("JetMassCorrFactor", &JetMassCorrFactor, &b_JetMassCorrFactor);
   fChain->SetBranchAddress("JetMassCorrFactorUp", &JetMassCorrFactorUp, &b_JetMassCorrFactorUp);
   fChain->SetBranchAddress("JetMassCorrFactorDn", &JetMassCorrFactorDn, &b_JetMassCorrFactorDn);
   fChain->SetBranchAddress("JetCorrFactor", &JetCorrFactor, &b_JetCorrFactor);
   fChain->SetBranchAddress("JetCorrFactorUp", &JetCorrFactorUp, &b_JetCorrFactorUp);
   fChain->SetBranchAddress("JetCorrFactorDn", &JetCorrFactorDn, &b_JetCorrFactorDn);
   fChain->SetBranchAddress("JetPtSmearFactor", &JetPtSmearFactor, &b_JetPtSmearFactor);
   fChain->SetBranchAddress("JetPtSmearFactorUp", &JetPtSmearFactorUp, &b_JetPtSmearFactorUp);
   fChain->SetBranchAddress("JetPtSmearFactorDn", &JetPtSmearFactorDn, &b_JetPtSmearFactorDn);
   fChain->SetBranchAddress("JetPuppiMassCorrFactor", &JetPuppiMassCorrFactor, &b_JetPuppiMassCorrFactor);
   fChain->SetBranchAddress("JetPuppiMassCorrFactorUp", &JetPuppiMassCorrFactorUp, &b_JetPuppiMassCorrFactorUp);
   fChain->SetBranchAddress("JetPuppiMassCorrFactorDn", &JetPuppiMassCorrFactorDn, &b_JetPuppiMassCorrFactorDn);
   fChain->SetBranchAddress("JetPuppiCorrFactor", &JetPuppiCorrFactor, &b_JetPuppiCorrFactor);
   fChain->SetBranchAddress("JetPuppiCorrFactorUp", &JetPuppiCorrFactorUp, &b_JetPuppiCorrFactorUp);
   fChain->SetBranchAddress("JetPuppiCorrFactorDn", &JetPuppiCorrFactorDn, &b_JetPuppiCorrFactorDn);
   fChain->SetBranchAddress("JetPuppiPtSmearFactor", &JetPuppiPtSmearFactor, &b_JetPuppiPtSmearFactor);
   fChain->SetBranchAddress("JetPuppiPtSmearFactorUp", &JetPuppiPtSmearFactorUp, &b_JetPuppiPtSmearFactorUp);
   fChain->SetBranchAddress("JetPuppiPtSmearFactorDn", &JetPuppiPtSmearFactorDn, &b_JetPuppiPtSmearFactorDn);
   fChain->SetBranchAddress("JetMatchedGenJetPt", &JetMatchedGenJetPt, &b_JetMatchedGenJetPt);
   fChain->SetBranchAddress("JetMatchedGenJetMass", &JetMatchedGenJetMass, &b_JetMatchedGenJetMass);
   fChain->SetBranchAddress("JetPuppiMatchedGenJetPt", &JetPuppiMatchedGenJetPt, &b_JetPuppiMatchedGenJetPt);
   fChain->SetBranchAddress("JetPuppiMatchedGenJetMass", &JetPuppiMatchedGenJetMass, &b_JetPuppiMatchedGenJetMass);
   fChain->SetBranchAddress("JetGenMatched_TopHadronic", &JetGenMatched_TopHadronic, &b_JetGenMatched_TopHadronic);
   fChain->SetBranchAddress("JetGenMatched_TopPt", &JetGenMatched_TopPt, &b_JetGenMatched_TopPt);
   fChain->SetBranchAddress("JetGenMatched_TopEta", &JetGenMatched_TopEta, &b_JetGenMatched_TopEta);
   fChain->SetBranchAddress("JetGenMatched_TopPhi", &JetGenMatched_TopPhi, &b_JetGenMatched_TopPhi);
   fChain->SetBranchAddress("JetGenMatched_TopMass", &JetGenMatched_TopMass, &b_JetGenMatched_TopMass);
   fChain->SetBranchAddress("JetGenMatched_bPt", &JetGenMatched_bPt, &b_JetGenMatched_bPt);
   fChain->SetBranchAddress("JetGenMatched_WPt", &JetGenMatched_WPt, &b_JetGenMatched_WPt);
   fChain->SetBranchAddress("JetGenMatched_Wd1Pt", &JetGenMatched_Wd1Pt, &b_JetGenMatched_Wd1Pt);
   fChain->SetBranchAddress("JetGenMatched_Wd2Pt", &JetGenMatched_Wd2Pt, &b_JetGenMatched_Wd2Pt);
   fChain->SetBranchAddress("JetGenMatched_Wd1ID", &JetGenMatched_Wd1ID, &b_JetGenMatched_Wd1ID);
   fChain->SetBranchAddress("JetGenMatched_Wd2ID", &JetGenMatched_Wd2ID, &b_JetGenMatched_Wd2ID);
   fChain->SetBranchAddress("JetGenMatched_MaxDeltaRPartonTop", &JetGenMatched_MaxDeltaRPartonTop, &b_JetGenMatched_MaxDeltaRPartonTop);
   fChain->SetBranchAddress("JetGenMatched_MaxDeltaRWPartonTop", &JetGenMatched_MaxDeltaRWPartonTop, &b_JetGenMatched_MaxDeltaRWPartonTop);
   fChain->SetBranchAddress("JetGenMatched_MaxDeltaRWPartonW", &JetGenMatched_MaxDeltaRWPartonW, &b_JetGenMatched_MaxDeltaRWPartonW);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_t_b", &JetGenMatched_DeltaR_t_b, &b_JetGenMatched_DeltaR_t_b);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_t_W", &JetGenMatched_DeltaR_t_W, &b_JetGenMatched_DeltaR_t_W);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_t_Wd1", &JetGenMatched_DeltaR_t_Wd1, &b_JetGenMatched_DeltaR_t_Wd1);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_t_Wd2", &JetGenMatched_DeltaR_t_Wd2, &b_JetGenMatched_DeltaR_t_Wd2);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_W_b1", &JetGenMatched_DeltaR_W_b1, &b_JetGenMatched_DeltaR_W_b1);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_W_Wd1", &JetGenMatched_DeltaR_W_Wd1, &b_JetGenMatched_DeltaR_W_Wd1);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_W_Wd2", &JetGenMatched_DeltaR_W_Wd2, &b_JetGenMatched_DeltaR_W_Wd2);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_Wd1_Wd2", &JetGenMatched_DeltaR_Wd1_Wd2, &b_JetGenMatched_DeltaR_Wd1_Wd2);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_Wd1_b", &JetGenMatched_DeltaR_Wd1_b, &b_JetGenMatched_DeltaR_Wd1_b);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_Wd2_b", &JetGenMatched_DeltaR_Wd2_b, &b_JetGenMatched_DeltaR_Wd2_b);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_jet_t", &JetGenMatched_DeltaR_jet_t, &b_JetGenMatched_DeltaR_jet_t);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_jet_W", &JetGenMatched_DeltaR_jet_W, &b_JetGenMatched_DeltaR_jet_W);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_jet_b", &JetGenMatched_DeltaR_jet_b, &b_JetGenMatched_DeltaR_jet_b);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_jet_Wd1", &JetGenMatched_DeltaR_jet_Wd1, &b_JetGenMatched_DeltaR_jet_Wd1);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_jet_Wd2", &JetGenMatched_DeltaR_jet_Wd2, &b_JetGenMatched_DeltaR_jet_Wd2);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_pup0_b", &JetGenMatched_DeltaR_pup0_b, &b_JetGenMatched_DeltaR_pup0_b);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_pup0_Wd1", &JetGenMatched_DeltaR_pup0_Wd1, &b_JetGenMatched_DeltaR_pup0_Wd1);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_pup0_Wd2", &JetGenMatched_DeltaR_pup0_Wd2, &b_JetGenMatched_DeltaR_pup0_Wd2);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_pup1_b", &JetGenMatched_DeltaR_pup1_b, &b_JetGenMatched_DeltaR_pup1_b);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_pup1_Wd1", &JetGenMatched_DeltaR_pup1_Wd1, &b_JetGenMatched_DeltaR_pup1_Wd1);
   fChain->SetBranchAddress("JetGenMatched_DeltaR_pup1_Wd2", &JetGenMatched_DeltaR_pup1_Wd2, &b_JetGenMatched_DeltaR_pup1_Wd2);
   fChain->SetBranchAddress("JetGenMatched_partonPt", &JetGenMatched_partonPt, &b_JetGenMatched_partonPt);
   fChain->SetBranchAddress("JetGenMatched_partonEta", &JetGenMatched_partonEta, &b_JetGenMatched_partonEta);
   fChain->SetBranchAddress("JetGenMatched_partonPhi", &JetGenMatched_partonPhi, &b_JetGenMatched_partonPhi);
   fChain->SetBranchAddress("JetGenMatched_partonMass", &JetGenMatched_partonMass, &b_JetGenMatched_partonMass);
   fChain->SetBranchAddress("JetGenMatched_partonID", &JetGenMatched_partonID, &b_JetGenMatched_partonID);
   fChain->SetBranchAddress("JetGenMatched_DeltaRjetParton", &JetGenMatched_DeltaRjetParton, &b_JetGenMatched_DeltaRjetParton);
   fChain->SetBranchAddress("HadMETpx", &HadMETpx, &b_HadMETpx);
   fChain->SetBranchAddress("HadMETpy", &HadMETpy, &b_HadMETpy);
   fChain->SetBranchAddress("HadMETpt", &HadMETpt, &b_HadMETpt);
   fChain->SetBranchAddress("HadMETphi", &HadMETphi, &b_HadMETphi);
   fChain->SetBranchAddress("HadMETsumET", &HadMETsumET, &b_HadMETsumET);
   fChain->SetBranchAddress("HadMETgenMET", &HadMETgenMET, &b_HadMETgenMET);
   fChain->SetBranchAddress("HadMETuncorPt", &HadMETuncorPt, &b_HadMETuncorPt);
   fChain->SetBranchAddress("HadMETshiftedPtJetEnUp", &HadMETshiftedPtJetEnUp, &b_HadMETshiftedPtJetEnUp);
   fChain->SetBranchAddress("HadMETshiftedPtJetEnDn", &HadMETshiftedPtJetEnDn, &b_HadMETshiftedPtJetEnDn);
   fChain->SetBranchAddress("HadMETshiftedPtElEnUp", &HadMETshiftedPtElEnUp, &b_HadMETshiftedPtElEnUp);
   fChain->SetBranchAddress("HadMETshiftedPtElEnDn", &HadMETshiftedPtElEnDn, &b_HadMETshiftedPtElEnDn);
   fChain->SetBranchAddress("HadMETshiftedPtMuEnUp", &HadMETshiftedPtMuEnUp, &b_HadMETshiftedPtMuEnUp);
   fChain->SetBranchAddress("HadMETshiftedPtMuEnDn", &HadMETshiftedPtMuEnDn, &b_HadMETshiftedPtMuEnDn);
   fChain->SetBranchAddress("HadMETshiftedPtJetResUp", &HadMETshiftedPtJetResUp, &b_HadMETshiftedPtJetResUp);
   fChain->SetBranchAddress("HadMETshiftedPtJetResDn", &HadMETshiftedPtJetResDn, &b_HadMETshiftedPtJetResDn);
   fChain->SetBranchAddress("HadMETshiftedPtUnclEnUp", &HadMETshiftedPtUnclEnUp, &b_HadMETshiftedPtUnclEnUp);
   fChain->SetBranchAddress("HadMETshiftedPtUnclEnDn", &HadMETshiftedPtUnclEnDn, &b_HadMETshiftedPtUnclEnDn);
   fChain->SetBranchAddress("HadNvtx", &HadNvtx, &b_HadNvtx);
   fChain->SetBranchAddress("HadNvtxGood", &HadNvtxGood, &b_HadNvtxGood);
   fChain->SetBranchAddress("HadRho", &HadRho, &b_HadRho);
   fChain->SetBranchAddress("HadEventWeight", &HadEventWeight, &b_HadEventWeight);
   fChain->SetBranchAddress("HadPUweight", &HadPUweight, &b_HadPUweight);
   fChain->SetBranchAddress("HadPUweight_MBup", &HadPUweight_MBup, &b_HadPUweight_MBup);
   fChain->SetBranchAddress("HadPUweight_MBdn", &HadPUweight_MBdn, &b_HadPUweight_MBdn);
   fChain->SetBranchAddress("HadGenTTmass", &HadGenTTmass, &b_HadGenTTmass);
   fChain->SetBranchAddress("HadGenCountHadTop", &HadGenCountHadTop, &b_HadGenCountHadTop);
   fChain->SetBranchAddress("HTlep", &HTlep, &b_HTlep);
   fChain->SetBranchAddress("ST", &ST, &b_ST);
   fChain->SetBranchAddress("ST_CorrDn", &ST_CorrDn, &b_ST_CorrDn);
   fChain->SetBranchAddress("ST_CorrUp", &ST_CorrUp, &b_ST_CorrUp);
   fChain->SetBranchAddress("ST_PtSmearNom", &ST_PtSmearNom, &b_ST_PtSmearNom);
   fChain->SetBranchAddress("ST_PtSmearUp", &ST_PtSmearUp, &b_ST_PtSmearUp);
   fChain->SetBranchAddress("ST_PtSmearDn", &ST_PtSmearDn, &b_ST_PtSmearDn);
   fChain->SetBranchAddress("HadQ2weight_CorrDn", &HadQ2weight_CorrDn, &b_HadQ2weight_CorrDn);
   fChain->SetBranchAddress("HadQ2weight_CorrUp", &HadQ2weight_CorrUp, &b_HadQ2weight_CorrUp);
   fChain->SetBranchAddress("HadNNPDF3weight_CorrDn", &HadNNPDF3weight_CorrDn, &b_HadNNPDF3weight_CorrDn);
   fChain->SetBranchAddress("HadNNPDF3weight_CorrUp", &HadNNPDF3weight_CorrUp, &b_HadNNPDF3weight_CorrUp);
   fChain->SetBranchAddress("HadRunNum", &HadRunNum, &b_HadRunNum);
   fChain->SetBranchAddress("HadLumiBlock", &HadLumiBlock, &b_HadLumiBlock);
   fChain->SetBranchAddress("HadEventNum", &HadEventNum, &b_HadEventNum);
   fChain->SetBranchAddress("HadPassMETFilters", &HadPassMETFilters, &b_HadPassMETFilters);
   fChain->SetBranchAddress("CA12JetPtRaw", &CA12JetPtRaw, &b_CA12JetPtRaw);
   fChain->SetBranchAddress("CA12JetEtaRaw", &CA12JetEtaRaw, &b_CA12JetEtaRaw);
   fChain->SetBranchAddress("CA12JetPhiRaw", &CA12JetPhiRaw, &b_CA12JetPhiRaw);
   fChain->SetBranchAddress("CA12JetMassRaw", &CA12JetMassRaw, &b_CA12JetMassRaw);
   fChain->SetBranchAddress("CA12JetTau1", &CA12JetTau1, &b_CA12JetTau1);
   fChain->SetBranchAddress("CA12JetTau2", &CA12JetTau2, &b_CA12JetTau2);
   fChain->SetBranchAddress("CA12JetTau3", &CA12JetTau3, &b_CA12JetTau3);
   fChain->SetBranchAddress("CA12JetTau4", &CA12JetTau4, &b_CA12JetTau4);
   fChain->SetBranchAddress("CA12JetTau32", &CA12JetTau32, &b_CA12JetTau32);
   fChain->SetBranchAddress("CA12JetTau21", &CA12JetTau21, &b_CA12JetTau21);
   fChain->SetBranchAddress("CA12Jetsubjet0bdisc", &CA12Jetsubjet0bdisc, &b_CA12Jetsubjet0bdisc);
   fChain->SetBranchAddress("CA12Jetsubjet1bdisc", &CA12Jetsubjet1bdisc, &b_CA12Jetsubjet1bdisc);
   fChain->SetBranchAddress("CA12Jetmaxbdisc", &CA12Jetmaxbdisc, &b_CA12Jetmaxbdisc);
   fChain->SetBranchAddress("CA12Jetsubjet0pt", &CA12Jetsubjet0pt, &b_CA12Jetsubjet0pt);
   fChain->SetBranchAddress("CA12Jetsubjet0mass", &CA12Jetsubjet0mass, &b_CA12Jetsubjet0mass);
   fChain->SetBranchAddress("CA12Jetsubjet0eta", &CA12Jetsubjet0eta, &b_CA12Jetsubjet0eta);
   fChain->SetBranchAddress("CA12Jetsubjet0phi", &CA12Jetsubjet0phi, &b_CA12Jetsubjet0phi);
   fChain->SetBranchAddress("CA12Jetsubjet0area", &CA12Jetsubjet0area, &b_CA12Jetsubjet0area);
   fChain->SetBranchAddress("CA12Jetsubjet1pt", &CA12Jetsubjet1pt, &b_CA12Jetsubjet1pt);
   fChain->SetBranchAddress("CA12Jetsubjet1mass", &CA12Jetsubjet1mass, &b_CA12Jetsubjet1mass);
   fChain->SetBranchAddress("CA12Jetsubjet1eta", &CA12Jetsubjet1eta, &b_CA12Jetsubjet1eta);
   fChain->SetBranchAddress("CA12Jetsubjet1phi", &CA12Jetsubjet1phi, &b_CA12Jetsubjet1phi);
   fChain->SetBranchAddress("CA12Jetsubjet1area", &CA12Jetsubjet1area, &b_CA12Jetsubjet1area);
   fChain->SetBranchAddress("AK4ReconstructedJetPt", &AK4ReconstructedJetPt, &b_AK4ReconstructedJetPt);
   fChain->SetBranchAddress("AK4ReconstructedJetEta", &AK4ReconstructedJetEta, &b_AK4ReconstructedJetEta);
   fChain->SetBranchAddress("AK4ReconstructedJetPhi", &AK4ReconstructedJetPhi, &b_AK4ReconstructedJetPhi);
   fChain->SetBranchAddress("AK4ReconstructedJetMass", &AK4ReconstructedJetMass, &b_AK4ReconstructedJetMass);
   fChain->SetBranchAddress("AK4bJetPtRaw", &AK4bJetPtRaw, &b_AK4bJetPtRaw);
   fChain->SetBranchAddress("AK4bJetEtaRaw", &AK4bJetEtaRaw, &b_AK4bJetEtaRaw);
   fChain->SetBranchAddress("AK4bJetPhiRaw", &AK4bJetPhiRaw, &b_AK4bJetPhiRaw);
   fChain->SetBranchAddress("AK4bJetMassRaw", &AK4bJetMassRaw, &b_AK4bJetMassRaw);
   fChain->SetBranchAddress("AK4bJet_PtSmear", &AK4bJet_PtSmear, &b_AK4bJet_PtSmear);
   fChain->SetBranchAddress("AK4bJet_PtSmearUp", &AK4bJet_PtSmearUp, &b_AK4bJet_PtSmearUp);
   fChain->SetBranchAddress("AK4bJet_PtSmearDn", &AK4bJet_PtSmearDn, &b_AK4bJet_PtSmearDn);
   fChain->SetBranchAddress("AK4bJet_PtUncorr", &AK4bJet_PtUncorr, &b_AK4bJet_PtUncorr);
   fChain->SetBranchAddress("AK4bJet_Corr", &AK4bJet_Corr, &b_AK4bJet_Corr);
   fChain->SetBranchAddress("AK4bJet_CorrUp", &AK4bJet_CorrUp, &b_AK4bJet_CorrUp);
   fChain->SetBranchAddress("AK4bJet_CorrDn", &AK4bJet_CorrDn, &b_AK4bJet_CorrDn);
   fChain->SetBranchAddress("AK4bJet_bDisc", &AK4bJet_bDisc, &b_AK4bJet_bDisc);
   fChain->SetBranchAddress("AK4WJetPtRaw", &AK4WJetPtRaw, &b_AK4WJetPtRaw);
   fChain->SetBranchAddress("AK4WJetEtaRaw", &AK4WJetEtaRaw, &b_AK4WJetEtaRaw);
   fChain->SetBranchAddress("AK4WJetPhiRaw", &AK4WJetPhiRaw, &b_AK4WJetPhiRaw);
   fChain->SetBranchAddress("AK4WJetMassRaw", &AK4WJetMassRaw, &b_AK4WJetMassRaw);
   fChain->SetBranchAddress("AK4WJet_PtSmear", &AK4WJet_PtSmear, &b_AK4WJet_PtSmear);
   fChain->SetBranchAddress("AK4WJet_PtSmearUp", &AK4WJet_PtSmearUp, &b_AK4WJet_PtSmearUp);
   fChain->SetBranchAddress("AK4WJet_PtSmearDn", &AK4WJet_PtSmearDn, &b_AK4WJet_PtSmearDn);
   fChain->SetBranchAddress("AK4WJet_PtUncorr", &AK4WJet_PtUncorr, &b_AK4WJet_PtUncorr);
   fChain->SetBranchAddress("AK4WJet_Corr", &AK4WJet_Corr, &b_AK4WJet_Corr);
   fChain->SetBranchAddress("AK4WJet_CorrUp", &AK4WJet_CorrUp, &b_AK4WJet_CorrUp);
   fChain->SetBranchAddress("AK4WJet_CorrDn", &AK4WJet_CorrDn, &b_AK4WJet_CorrDn);
   fChain->SetBranchAddress("AK4WJet_bDisc", &AK4WJet_bDisc, &b_AK4WJet_bDisc);
   fChain->SetBranchAddress("AK4W2JetPtRaw", &AK4W2JetPtRaw, &b_AK4W2JetPtRaw);
   fChain->SetBranchAddress("AK4W2JetEtaRaw", &AK4W2JetEtaRaw, &b_AK4W2JetEtaRaw);
   fChain->SetBranchAddress("AK4W2JetPhiRaw", &AK4W2JetPhiRaw, &b_AK4W2JetPhiRaw);
   fChain->SetBranchAddress("AK4W2JetMassRaw", &AK4W2JetMassRaw, &b_AK4W2JetMassRaw);
   fChain->SetBranchAddress("AK4W2Jet_PtSmear", &AK4W2Jet_PtSmear, &b_AK4W2Jet_PtSmear);
   fChain->SetBranchAddress("AK4W2Jet_PtSmearUp", &AK4W2Jet_PtSmearUp, &b_AK4W2Jet_PtSmearUp);
   fChain->SetBranchAddress("AK4W2Jet_PtSmearDn", &AK4W2Jet_PtSmearDn, &b_AK4W2Jet_PtSmearDn);
   fChain->SetBranchAddress("AK4W2Jet_PtUncorr", &AK4W2Jet_PtUncorr, &b_AK4W2Jet_PtUncorr);
   fChain->SetBranchAddress("AK4W2Jet_Corr", &AK4W2Jet_Corr, &b_AK4W2Jet_Corr);
   fChain->SetBranchAddress("AK4W2Jet_CorrUp", &AK4W2Jet_CorrUp, &b_AK4W2Jet_CorrUp);
   fChain->SetBranchAddress("AK4W2Jet_CorrDn", &AK4W2Jet_CorrDn, &b_AK4W2Jet_CorrDn);
   fChain->SetBranchAddress("AK4W2Jet_bDisc", &AK4W2Jet_bDisc, &b_AK4W2Jet_bDisc);
   fChain->SetBranchAddress("MuPhi", &MuPhi, &b_MuPhi);
   fChain->SetBranchAddress("MuPt", &MuPt, &b_MuPt);
   fChain->SetBranchAddress("MuEta", &MuEta, &b_MuEta);
   fChain->SetBranchAddress("MuMass", &MuMass, &b_MuMass);
   fChain->SetBranchAddress("MuMedium", &MuMedium, &b_MuMedium);
   fChain->SetBranchAddress("MuTight", &MuTight, &b_MuTight);
   fChain->SetBranchAddress("MuIso", &MuIso, &b_MuIso);
   Notify();
}

Bool_t HadTree_Oct_12_17::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HadTree_Oct_12_17::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HadTree_Oct_12_17::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HadTree_Oct_12_17_cxx
