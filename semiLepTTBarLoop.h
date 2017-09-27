//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Sep 19 13:53:44 2017 by ROOT version 6.08/07
// from TTree TreeSemiLept/TreeSemiLept
// found on file: b2gtreeV5_MC_ttbar.root
//////////////////////////////////////////////////////////

#ifndef semiLepTTBarLoop_h
#define semiLepTTBarLoop_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "string"

class semiLepTTBarLoop {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<int>     *SemiLeptTrigPrescales;
   vector<bool>    *SemiLeptTrigPass;
   string          *SemiLeptTrigAcceptBits;
   Int_t           JetNsubjetsSD;
   Int_t           JetNsubjetsSDPuppi;
   Float_t         JetPtRaw;
   Float_t         JetEtaRaw;
   Float_t         JetPhiRaw;
   Float_t         JetMassRaw;
   Float_t         Jet2PtRaw;
   Float_t         Jet2EtaRaw;
   Float_t         Jet2PhiRaw;
   Float_t         Jet2MassRaw;
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
   Float_t         SemiLeptMETpx;
   Float_t         SemiLeptMETpy;
   Float_t         SemiLeptMETpt;
   Float_t         SemiLeptMETphi;
   Float_t         SemiLeptMETsumET;
   Float_t         SemiLeptMETgenMET;
   Float_t         SemiLeptMETuncorPt;
   Float_t         SemiLeptMETshiftedPtJetEnUp;
   Float_t         SemiLeptMETshiftedPtJetEnDn;
   Float_t         SemiLeptMETshiftedPtElEnUp;
   Float_t         SemiLeptMETshiftedPtElEnDn;
   Float_t         SemiLeptMETshiftedPtMuEnUp;
   Float_t         SemiLeptMETshiftedPtMuEnDn;
   Float_t         SemiLeptMETshiftedPtJetResUp;
   Float_t         SemiLeptMETshiftedPtJetResDn;
   Float_t         SemiLeptMETshiftedPtUnclEnUp;
   Float_t         SemiLeptMETshiftedPtUnclEnDn;
   Float_t         SemiLeptNvtx;
   Float_t         SemiLeptNvtxGood;
   Float_t         SemiLeptRho;
   Float_t         SemiLeptEventWeight;
   Float_t         SemiLeptPUweight;
   Float_t         SemiLeptPUweight_MBup;
   Float_t         SemiLeptPUweight_MBdn;
   Float_t         SemiLeptGenTTmass;
   Int_t           SemiLeptGenCountHadTop;
   Float_t         HTlep;
   Float_t         ST;
   Float_t         ST_CorrDn;
   Float_t         ST_CorrUp;
   Float_t         ST_PtSmearNom;
   Float_t         ST_PtSmearUp;
   Float_t         ST_PtSmearDn;
   Float_t         SemiLeptQ2weight_CorrDn;
   Float_t         SemiLeptQ2weight_CorrUp;
   Float_t         SemiLeptNNPDF3weight_CorrDn;
   Float_t         SemiLeptNNPDF3weight_CorrUp;
   Int_t           SemiLeptRunNum;
   Int_t           SemiLeptLumiBlock;
   Int_t           SemiLeptEventNum;
   Int_t           SemiLeptPassMETFilters;
   Float_t         AK4_dRminLep_Pt;
   Float_t         AK4_dRminLep_Eta;
   Float_t         AK4_dRminLep_Phi;
   Float_t         AK4_dRminLep_Mass;
   Float_t         AK4_dRminLep_Bdisc;
   Float_t         AK4_dRminLep_dRlep;
   Float_t         AK4_dRminLep_dRak8;
   Float_t         AK4_dRminLep_PtSmear;
   Float_t         AK4_dRminLep_PtSmearUp;
   Float_t         AK4_dRminLep_PtSmearDn;
   Float_t         AK4_dRminLep_PtUncorr;
   Float_t         AK4_dRminLep_Corr;
   Float_t         AK4_dRminLep_CorrUp;
   Float_t         AK4_dRminLep_CorrDn;

   Float_t         AK4_hadTop_jet0_Pt;
   Float_t         AK4_hadTop_jet0_Eta;
   Float_t         AK4_hadTop_jet0_Phi;
   Float_t         AK4_hadTop_jet0_Mass;
   Float_t         AK4_hadTop_jet0_Bdisc;
   Float_t         AK4_hadTop_jet0_dRlep;
   Float_t         AK4_hadTop_jet0_PtSmear;
   Float_t         AK4_hadTop_jet0_PtSmearUp;
   Float_t         AK4_hadTop_jet0_PtSmearDn;
   Float_t         AK4_hadTop_jet0_PtUncorr;
   Float_t         AK4_hadTop_jet0_Corr;
   Float_t         AK4_hadTop_jet0_CorrUp;
   Float_t         AK4_hadTop_jet0_CorrDn;


   Float_t         AK4_hadTop_jet1_Pt;
   Float_t         AK4_hadTop_jet1_Eta;
   Float_t         AK4_hadTop_jet1_Phi;
   Float_t         AK4_hadTop_jet1_Mass;
   Float_t         AK4_hadTop_jet1_Bdisc;
   Float_t         AK4_hadTop_jet1_dRlep;
   Float_t         AK4_hadTop_jet1_PtSmear;
   Float_t         AK4_hadTop_jet1_PtSmearUp;
   Float_t         AK4_hadTop_jet1_PtSmearDn;
   Float_t         AK4_hadTop_jet1_PtUncorr;
   Float_t         AK4_hadTop_jet1_Corr;
   Float_t         AK4_hadTop_jet1_CorrUp;
   Float_t         AK4_hadTop_jet1_CorrDn;

   Int_t           LepHemiContainsAK4BtagLoose;
   Int_t           LepHemiContainsAK4BtagMedium;
   Int_t           LepHemiContainsAK4BtagTight;
   Float_t         LeptonPhi;
   Float_t         LeptonPt;
   Float_t         LeptonEta;
   Float_t         LeptonMass;
   Float_t         PtRel;
   Int_t           LeptonIsMu;
   Int_t           MuMedium;
   Int_t           MuTight;
   Int_t           MuHighPt;
   Float_t         DeltaRJetLep;
   Float_t         DeltaPhiJetLep;
   Float_t         MuIso;
   Float_t         Elecron_absiso;
   Float_t         Elecron_relIsoWithDBeta;
   Float_t         Elecron_absiso_EA;
   Float_t         Elecron_relIsoWithEA;
   Int_t           Electron_iso_passHLTpre;
   Int_t           Electron_iso_passLoose;
   Int_t           Electron_iso_passMedium;
   Int_t           Electron_iso_passTight;
   Int_t           Electron_iso_passHEEP;
   Int_t           Electron_noiso_passLoose;
   Int_t           Electron_noiso_passMedium;
   Int_t           Electron_noiso_passTight;
   Int_t           Electron_noiso_passHEEP;

   // List of branches
   TBranch        *b_SemiLeptTrigPrescales;   //!
   TBranch        *b_SemiLeptTrigPass;   //!
   TBranch        *b_SemiLeptTrigAcceptBits;   //!
   TBranch        *b_JetNsubjetsSD;   //!
   TBranch        *b_JetNsubjetsSDPuppi;   //!
   TBranch        *b_JetPtRaw;   //!
   TBranch        *b_JetEtaRaw;   //!
   TBranch        *b_JetPhiRaw;   //!
   TBranch        *b_JetMassRaw;   //!
   TBranch        *b_Jet2PtRaw;   //!
   TBranch        *b_Jet2EtaRaw;   //!
   TBranch        *b_Jet2PhiRaw;   //!
   TBranch        *b_Jet2MassRaw;   //!
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
   TBranch        *b_SemiLeptMETpx;   //!
   TBranch        *b_SemiLeptMETpy;   //!
   TBranch        *b_SemiLeptMETpt;   //!
   TBranch        *b_SemiLeptMETphi;   //!
   TBranch        *b_SemiLeptMETsumET;   //!
   TBranch        *b_SemiLeptMETgenMET;   //!
   TBranch        *b_SemiLeptMETuncorPt;   //!
   TBranch        *b_SemiLeptMETshiftedPtJetEnUp;   //!
   TBranch        *b_SemiLeptMETshiftedPtJetEnDn;   //!
   TBranch        *b_SemiLeptMETshiftedPtElEnUp;   //!
   TBranch        *b_SemiLeptMETshiftedPtElEnDn;   //!
   TBranch        *b_SemiLeptMETshiftedPtMuEnUp;   //!
   TBranch        *b_SemiLeptMETshiftedPtMuEnDn;   //!
   TBranch        *b_SemiLeptMETshiftedPtJetResUp;   //!
   TBranch        *b_SemiLeptMETshiftedPtJetResDn;   //!
   TBranch        *b_SemiLeptMETshiftedPtUnclEnUp;   //!
   TBranch        *b_SemiLeptMETshiftedPtUnclEnDn;   //!
   TBranch        *b_SemiLeptNvtx;   //!
   TBranch        *b_SemiLeptNvtxGood;   //!
   TBranch        *b_SemiLeptRho;   //!
   TBranch        *b_SemiLeptEventWeight;   //!
   TBranch        *b_SemiLeptPUweight;   //!
   TBranch        *b_SemiLeptPUweight_MBup;   //!
   TBranch        *b_SemiLeptPUweight_MBdn;   //!
   TBranch        *b_SemiLeptGenTTmass;   //!
   TBranch        *b_SemiLeptGenCountHadTop;   //!
   TBranch        *b_HTlep;   //!
   TBranch        *b_ST;   //!
   TBranch        *b_ST_CorrDn;   //!
   TBranch        *b_ST_CorrUp;   //!
   TBranch        *b_ST_PtSmearNom;   //!
   TBranch        *b_ST_PtSmearUp;   //!
   TBranch        *b_ST_PtSmearDn;   //!
   TBranch        *b_SemiLeptQ2weight_CorrDn;   //!
   TBranch        *b_SemiLeptQ2weight_CorrUp;   //!
   TBranch        *b_SemiLeptNNPDF3weight_CorrDn;   //!
   TBranch        *b_SemiLeptNNPDF3weight_CorrUp;   //!
   TBranch        *b_SemiLeptRunNum;   //!
   TBranch        *b_SemiLeptLumiBlock;   //!
   TBranch        *b_SemiLeptEventNum;   //!
   TBranch        *b_SemiLeptPassMETFilters;   //!
   TBranch        *b_AK4_dRminLep_Pt;   //!
   TBranch        *b_AK4_dRminLep_Eta;   //!
   TBranch        *b_AK4_dRminLep_Phi;   //!
   TBranch        *b_AK4_dRminLep_Mass;   //!
   TBranch        *b_AK4_dRminLep_Bdisc;   //!
   TBranch        *b_AK4_dRminLep_dRlep;   //!
   TBranch        *b_AK4_dRminLep_dRak8;   //!
   TBranch        *b_AK4_dRminLep_PtSmear;   //!
   TBranch        *b_AK4_dRminLep_PtSmearUp;   //!
   TBranch        *b_AK4_dRminLep_PtSmearDn;   //!
   TBranch        *b_AK4_dRminLep_PtUncorr;   //!
   TBranch        *b_AK4_dRminLep_Corr;   //!
   TBranch        *b_AK4_dRminLep_CorrUp;   //!
   TBranch        *b_AK4_dRminLep_CorrDn;   //!

   TBranch        *b_AK4_hadTop_jet0_Pt;   //!
   TBranch        *b_AK4_hadTop_jet0_Eta;   //!
   TBranch        *b_AK4_hadTop_jet0_Phi;   //!
   TBranch        *b_AK4_hadTop_jet0_Mass;   //!
   TBranch        *b_AK4_hadTop_jet0_Bdisc;   //!
   TBranch        *b_AK4_hadTop_jet0_dRlep;   //!
   TBranch        *b_AK4_hadTop_jet0_PtSmear;   //!
   TBranch        *b_AK4_hadTop_jet0_PtSmearUp;   //!
   TBranch        *b_AK4_hadTop_jet0_PtSmearDn;   //!
   TBranch        *b_AK4_hadTop_jet0_PtUncorr;   //!
   TBranch        *b_AK4_hadTop_jet0_Corr;   //!
   TBranch        *b_AK4_hadTop_jet0_CorrUp;   //!
   TBranch        *b_AK4_hadTop_jet0_CorrDn;   //!

   TBranch        *b_AK4_hadTop_jet1_Pt;   //!
   TBranch        *b_AK4_hadTop_jet1_Eta;   //!
   TBranch        *b_AK4_hadTop_jet1_Phi;   //!
   TBranch        *b_AK4_hadTop_jet1_Mass;   //!
   TBranch        *b_AK4_hadTop_jet1_Bdisc;   //!
   TBranch        *b_AK4_hadTop_jet1_dRlep;   //!
   TBranch        *b_AK4_hadTop_jet1_PtSmear;   //!
   TBranch        *b_AK4_hadTop_jet1_PtSmearUp;   //!
   TBranch        *b_AK4_hadTop_jet1_PtSmearDn;   //!
   TBranch        *b_AK4_hadTop_jet1_PtUncorr;   //!
   TBranch        *b_AK4_hadTop_jet1_Corr;   //!
   TBranch        *b_AK4_hadTop_jet1_CorrUp;   //!
   TBranch        *b_AK4_hadTop_jet1_CorrDn;   //!

   TBranch        *b_LepHemiContainsAK4BtagLoose;   //!
   TBranch        *b_LepHemiContainsAK4BtagMedium;   //!
   TBranch        *b_LepHemiContainsAK4BtagTight;   //!
   TBranch        *b_LeptonPhi;   //!
   TBranch        *b_LeptonPt;   //!
   TBranch        *b_LeptonEta;   //!
   TBranch        *b_LeptonMass;   //!
   TBranch        *b_PtRel;   //!
   TBranch        *b_LeptonIsMu;   //!
   TBranch        *b_MuMedium;   //!
   TBranch        *b_MuTight;   //!
   TBranch        *b_MuHighPt;   //!
   TBranch        *b_DeltaRJetLep;   //!
   TBranch        *b_DeltaPhiJetLep;   //!
   TBranch        *b_MuIso;   //!
   TBranch        *b_Elecron_absiso;   //!
   TBranch        *b_Elecron_relIsoWithDBeta;   //!
   TBranch        *b_Elecron_absiso_EA;   //!
   TBranch        *b_Elecron_relIsoWithEA;   //!
   TBranch        *b_Electron_iso_passHLTpre;   //!
   TBranch        *b_Electron_iso_passLoose;   //!
   TBranch        *b_Electron_iso_passMedium;   //!
   TBranch        *b_Electron_iso_passTight;   //!
   TBranch        *b_Electron_iso_passHEEP;   //!
   TBranch        *b_Electron_noiso_passLoose;   //!
   TBranch        *b_Electron_noiso_passMedium;   //!
   TBranch        *b_Electron_noiso_passTight;   //!
   TBranch        *b_Electron_noiso_passHEEP;   //!

   semiLepTTBarLoop(TTree *tree=0);
   virtual ~semiLepTTBarLoop();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(std::string outFileName, Bool_t gen);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef semiLepTTBarLoop_cxx
semiLepTTBarLoop::semiLepTTBarLoop(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("b2gtreeV5_MC_ttbar.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("b2gtreeV5_MC_ttbar.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("b2gtreeV5_MC_ttbar.root:/ana");
      dir->GetObject("TreeSemiLept",tree);

   }
   Init(tree);
}

semiLepTTBarLoop::~semiLepTTBarLoop()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t semiLepTTBarLoop::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t semiLepTTBarLoop::LoadTree(Long64_t entry)
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

void semiLepTTBarLoop::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   SemiLeptTrigPrescales = 0;
   SemiLeptTrigPass = 0;
   SemiLeptTrigAcceptBits = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("SemiLeptTrigPrescales", &SemiLeptTrigPrescales, &b_SemiLeptTrigPrescales);
   fChain->SetBranchAddress("SemiLeptTrigPass", &SemiLeptTrigPass, &b_SemiLeptTrigPass);
   fChain->SetBranchAddress("SemiLeptTrigAcceptBits", &SemiLeptTrigAcceptBits, &b_SemiLeptTrigAcceptBits);
   fChain->SetBranchAddress("JetNsubjetsSD", &JetNsubjetsSD, &b_JetNsubjetsSD);
   fChain->SetBranchAddress("JetNsubjetsSDPuppi", &JetNsubjetsSDPuppi, &b_JetNsubjetsSDPuppi);
   fChain->SetBranchAddress("JetPtRaw", &JetPtRaw, &b_JetPtRaw);
   fChain->SetBranchAddress("JetEtaRaw", &JetEtaRaw, &b_JetEtaRaw);
   fChain->SetBranchAddress("JetPhiRaw", &JetPhiRaw, &b_JetPhiRaw);
   fChain->SetBranchAddress("JetMassRaw", &JetMassRaw, &b_JetMassRaw);
   fChain->SetBranchAddress("Jet2PtRaw", &Jet2PtRaw, &b_Jet2PtRaw);
   fChain->SetBranchAddress("Jet2EtaRaw", &Jet2EtaRaw, &b_Jet2EtaRaw);
   fChain->SetBranchAddress("Jet2PhiRaw", &Jet2PhiRaw, &b_Jet2PhiRaw);
   fChain->SetBranchAddress("Jet2MassRaw", &Jet2MassRaw, &b_Jet2MassRaw);
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
   fChain->SetBranchAddress("SemiLeptMETpx", &SemiLeptMETpx, &b_SemiLeptMETpx);
   fChain->SetBranchAddress("SemiLeptMETpy", &SemiLeptMETpy, &b_SemiLeptMETpy);
   fChain->SetBranchAddress("SemiLeptMETpt", &SemiLeptMETpt, &b_SemiLeptMETpt);
   fChain->SetBranchAddress("SemiLeptMETphi", &SemiLeptMETphi, &b_SemiLeptMETphi);
   fChain->SetBranchAddress("SemiLeptMETsumET", &SemiLeptMETsumET, &b_SemiLeptMETsumET);
   fChain->SetBranchAddress("SemiLeptMETgenMET", &SemiLeptMETgenMET, &b_SemiLeptMETgenMET);
   fChain->SetBranchAddress("SemiLeptMETuncorPt", &SemiLeptMETuncorPt, &b_SemiLeptMETuncorPt);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtJetEnUp", &SemiLeptMETshiftedPtJetEnUp, &b_SemiLeptMETshiftedPtJetEnUp);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtJetEnDn", &SemiLeptMETshiftedPtJetEnDn, &b_SemiLeptMETshiftedPtJetEnDn);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtElEnUp", &SemiLeptMETshiftedPtElEnUp, &b_SemiLeptMETshiftedPtElEnUp);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtElEnDn", &SemiLeptMETshiftedPtElEnDn, &b_SemiLeptMETshiftedPtElEnDn);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtMuEnUp", &SemiLeptMETshiftedPtMuEnUp, &b_SemiLeptMETshiftedPtMuEnUp);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtMuEnDn", &SemiLeptMETshiftedPtMuEnDn, &b_SemiLeptMETshiftedPtMuEnDn);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtJetResUp", &SemiLeptMETshiftedPtJetResUp, &b_SemiLeptMETshiftedPtJetResUp);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtJetResDn", &SemiLeptMETshiftedPtJetResDn, &b_SemiLeptMETshiftedPtJetResDn);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtUnclEnUp", &SemiLeptMETshiftedPtUnclEnUp, &b_SemiLeptMETshiftedPtUnclEnUp);
   fChain->SetBranchAddress("SemiLeptMETshiftedPtUnclEnDn", &SemiLeptMETshiftedPtUnclEnDn, &b_SemiLeptMETshiftedPtUnclEnDn);
   fChain->SetBranchAddress("SemiLeptNvtx", &SemiLeptNvtx, &b_SemiLeptNvtx);
   fChain->SetBranchAddress("SemiLeptNvtxGood", &SemiLeptNvtxGood, &b_SemiLeptNvtxGood);
   fChain->SetBranchAddress("SemiLeptRho", &SemiLeptRho, &b_SemiLeptRho);
   fChain->SetBranchAddress("SemiLeptEventWeight", &SemiLeptEventWeight, &b_SemiLeptEventWeight);
   fChain->SetBranchAddress("SemiLeptPUweight", &SemiLeptPUweight, &b_SemiLeptPUweight);
   fChain->SetBranchAddress("SemiLeptPUweight_MBup", &SemiLeptPUweight_MBup, &b_SemiLeptPUweight_MBup);
   fChain->SetBranchAddress("SemiLeptPUweight_MBdn", &SemiLeptPUweight_MBdn, &b_SemiLeptPUweight_MBdn);
   fChain->SetBranchAddress("SemiLeptGenTTmass", &SemiLeptGenTTmass, &b_SemiLeptGenTTmass);
   fChain->SetBranchAddress("SemiLeptGenCountHadTop", &SemiLeptGenCountHadTop, &b_SemiLeptGenCountHadTop);
   fChain->SetBranchAddress("HTlep", &HTlep, &b_HTlep);
   fChain->SetBranchAddress("ST", &ST, &b_ST);
   fChain->SetBranchAddress("ST_CorrDn", &ST_CorrDn, &b_ST_CorrDn);
   fChain->SetBranchAddress("ST_CorrUp", &ST_CorrUp, &b_ST_CorrUp);
   fChain->SetBranchAddress("ST_PtSmearNom", &ST_PtSmearNom, &b_ST_PtSmearNom);
   fChain->SetBranchAddress("ST_PtSmearUp", &ST_PtSmearUp, &b_ST_PtSmearUp);
   fChain->SetBranchAddress("ST_PtSmearDn", &ST_PtSmearDn, &b_ST_PtSmearDn);
   fChain->SetBranchAddress("SemiLeptQ2weight_CorrDn", &SemiLeptQ2weight_CorrDn, &b_SemiLeptQ2weight_CorrDn);
   fChain->SetBranchAddress("SemiLeptQ2weight_CorrUp", &SemiLeptQ2weight_CorrUp, &b_SemiLeptQ2weight_CorrUp);
   fChain->SetBranchAddress("SemiLeptNNPDF3weight_CorrDn", &SemiLeptNNPDF3weight_CorrDn, &b_SemiLeptNNPDF3weight_CorrDn);
   fChain->SetBranchAddress("SemiLeptNNPDF3weight_CorrUp", &SemiLeptNNPDF3weight_CorrUp, &b_SemiLeptNNPDF3weight_CorrUp);
   fChain->SetBranchAddress("SemiLeptRunNum", &SemiLeptRunNum, &b_SemiLeptRunNum);
   fChain->SetBranchAddress("SemiLeptLumiBlock", &SemiLeptLumiBlock, &b_SemiLeptLumiBlock);
   fChain->SetBranchAddress("SemiLeptEventNum", &SemiLeptEventNum, &b_SemiLeptEventNum);
   fChain->SetBranchAddress("SemiLeptPassMETFilters", &SemiLeptPassMETFilters, &b_SemiLeptPassMETFilters);
   fChain->SetBranchAddress("AK4_dRminLep_Pt", &AK4_dRminLep_Pt, &b_AK4_dRminLep_Pt);
   fChain->SetBranchAddress("AK4_dRminLep_Eta", &AK4_dRminLep_Eta, &b_AK4_dRminLep_Eta);
   fChain->SetBranchAddress("AK4_dRminLep_Phi", &AK4_dRminLep_Phi, &b_AK4_dRminLep_Phi);
   fChain->SetBranchAddress("AK4_dRminLep_Mass", &AK4_dRminLep_Mass, &b_AK4_dRminLep_Mass);
   fChain->SetBranchAddress("AK4_dRminLep_Bdisc", &AK4_dRminLep_Bdisc, &b_AK4_dRminLep_Bdisc);
   fChain->SetBranchAddress("AK4_dRminLep_dRlep", &AK4_dRminLep_dRlep, &b_AK4_dRminLep_dRlep);
   fChain->SetBranchAddress("AK4_dRminLep_dRak8", &AK4_dRminLep_dRak8, &b_AK4_dRminLep_dRak8);
   fChain->SetBranchAddress("AK4_dRminLep_PtSmear", &AK4_dRminLep_PtSmear, &b_AK4_dRminLep_PtSmear);
   fChain->SetBranchAddress("AK4_dRminLep_PtSmearUp", &AK4_dRminLep_PtSmearUp, &b_AK4_dRminLep_PtSmearUp);
   fChain->SetBranchAddress("AK4_dRminLep_PtSmearDn", &AK4_dRminLep_PtSmearDn, &b_AK4_dRminLep_PtSmearDn);
   fChain->SetBranchAddress("AK4_dRminLep_PtUncorr", &AK4_dRminLep_PtUncorr, &b_AK4_dRminLep_PtUncorr);
   fChain->SetBranchAddress("AK4_dRminLep_Corr", &AK4_dRminLep_Corr, &b_AK4_dRminLep_Corr);
   fChain->SetBranchAddress("AK4_dRminLep_CorrUp", &AK4_dRminLep_CorrUp, &b_AK4_dRminLep_CorrUp);
   fChain->SetBranchAddress("AK4_dRminLep_CorrDn", &AK4_dRminLep_CorrDn, &b_AK4_dRminLep_CorrDn);

   fChain->SetBranchAddress("AK4_hadTop_jet0_Pt", &AK4_hadTop_jet0_Pt, &b_AK4_hadTop_jet0_Pt);
   fChain->SetBranchAddress("AK4_hadTop_jet0_Eta", &AK4_hadTop_jet0_Eta, &b_AK4_hadTop_jet0_Eta);
   fChain->SetBranchAddress("AK4_hadTop_jet0_Phi", &AK4_hadTop_jet0_Phi, &b_AK4_hadTop_jet0_Phi);
   fChain->SetBranchAddress("AK4_hadTop_jet0_Mass", &AK4_hadTop_jet0_Mass, &b_AK4_hadTop_jet0_Mass);
   fChain->SetBranchAddress("AK4_hadTop_jet0_Bdisc", &AK4_hadTop_jet0_Bdisc, &b_AK4_hadTop_jet0_Bdisc);
   fChain->SetBranchAddress("AK4_hadTop_jet0_dRlep", &AK4_hadTop_jet0_dRlep, &b_AK4_hadTop_jet0_dRlep);
   fChain->SetBranchAddress("AK4_hadTop_jet0_PtSmear", &AK4_hadTop_jet0_PtSmear, &b_AK4_hadTop_jet0_PtSmear);
   fChain->SetBranchAddress("AK4_hadTop_jet0_PtSmearUp", &AK4_hadTop_jet0_PtSmearUp, &b_AK4_hadTop_jet0_PtSmearUp);
   fChain->SetBranchAddress("AK4_hadTop_jet0_PtSmearDn", &AK4_hadTop_jet0_PtSmearDn, &b_AK4_hadTop_jet0_PtSmearDn);
   fChain->SetBranchAddress("AK4_hadTop_jet0_PtUncorr", &AK4_hadTop_jet0_PtUncorr, &b_AK4_hadTop_jet0_PtUncorr);
   fChain->SetBranchAddress("AK4_hadTop_jet0_Corr", &AK4_hadTop_jet0_Corr, &b_AK4_hadTop_jet0_Corr);
   fChain->SetBranchAddress("AK4_hadTop_jet0_CorrUp", &AK4_hadTop_jet0_CorrUp, &b_AK4_hadTop_jet0_CorrUp);
   fChain->SetBranchAddress("AK4_hadTop_jet0_CorrDn", &AK4_hadTop_jet0_CorrDn, &b_AK4_hadTop_jet0_CorrDn);

   fChain->SetBranchAddress("AK4_hadTop_jet1_Pt", &AK4_hadTop_jet1_Pt, &b_AK4_hadTop_jet1_Pt);
   fChain->SetBranchAddress("AK4_hadTop_jet1_Eta", &AK4_hadTop_jet1_Eta, &b_AK4_hadTop_jet1_Eta);
   fChain->SetBranchAddress("AK4_hadTop_jet1_Phi", &AK4_hadTop_jet1_Phi, &b_AK4_hadTop_jet1_Phi);
   fChain->SetBranchAddress("AK4_hadTop_jet1_Mass", &AK4_hadTop_jet1_Mass, &b_AK4_hadTop_jet1_Mass);
   fChain->SetBranchAddress("AK4_hadTop_jet1_Bdisc", &AK4_hadTop_jet1_Bdisc, &b_AK4_hadTop_jet1_Bdisc);
   fChain->SetBranchAddress("AK4_hadTop_jet1_dRlep", &AK4_hadTop_jet1_dRlep, &b_AK4_hadTop_jet1_dRlep);
   fChain->SetBranchAddress("AK4_hadTop_jet1_PtSmear", &AK4_hadTop_jet1_PtSmear, &b_AK4_hadTop_jet1_PtSmear);
   fChain->SetBranchAddress("AK4_hadTop_jet1_PtSmearUp", &AK4_hadTop_jet1_PtSmearUp, &b_AK4_hadTop_jet1_PtSmearUp);
   fChain->SetBranchAddress("AK4_hadTop_jet1_PtSmearDn", &AK4_hadTop_jet1_PtSmearDn, &b_AK4_hadTop_jet1_PtSmearDn);
   fChain->SetBranchAddress("AK4_hadTop_jet1_PtUncorr", &AK4_hadTop_jet1_PtUncorr, &b_AK4_hadTop_jet1_PtUncorr);
   fChain->SetBranchAddress("AK4_hadTop_jet1_Corr", &AK4_hadTop_jet1_Corr, &b_AK4_hadTop_jet1_Corr);
   fChain->SetBranchAddress("AK4_hadTop_jet1_CorrUp", &AK4_hadTop_jet1_CorrUp, &b_AK4_hadTop_jet1_CorrUp);
   fChain->SetBranchAddress("AK4_hadTop_jet1_CorrDn", &AK4_hadTop_jet1_CorrDn, &b_AK4_hadTop_jet1_CorrDn);

   fChain->SetBranchAddress("LepHemiContainsAK4BtagLoose", &LepHemiContainsAK4BtagLoose, &b_LepHemiContainsAK4BtagLoose);
   fChain->SetBranchAddress("LepHemiContainsAK4BtagMedium", &LepHemiContainsAK4BtagMedium, &b_LepHemiContainsAK4BtagMedium);
   fChain->SetBranchAddress("LepHemiContainsAK4BtagTight", &LepHemiContainsAK4BtagTight, &b_LepHemiContainsAK4BtagTight);
   fChain->SetBranchAddress("LeptonPhi", &LeptonPhi, &b_LeptonPhi);
   fChain->SetBranchAddress("LeptonPt", &LeptonPt, &b_LeptonPt);
   fChain->SetBranchAddress("LeptonEta", &LeptonEta, &b_LeptonEta);
   fChain->SetBranchAddress("LeptonMass", &LeptonMass, &b_LeptonMass);
   fChain->SetBranchAddress("PtRel", &PtRel, &b_PtRel);
   fChain->SetBranchAddress("LeptonIsMu", &LeptonIsMu, &b_LeptonIsMu);
   fChain->SetBranchAddress("MuMedium", &MuMedium, &b_MuMedium);
   fChain->SetBranchAddress("MuTight", &MuTight, &b_MuTight);
   fChain->SetBranchAddress("MuHighPt", &MuHighPt, &b_MuHighPt);
   fChain->SetBranchAddress("DeltaRJetLep", &DeltaRJetLep, &b_DeltaRJetLep);
   fChain->SetBranchAddress("DeltaPhiJetLep", &DeltaPhiJetLep, &b_DeltaPhiJetLep);
   fChain->SetBranchAddress("MuIso", &MuIso, &b_MuIso);
   fChain->SetBranchAddress("Elecron_absiso", &Elecron_absiso, &b_Elecron_absiso);
   fChain->SetBranchAddress("Elecron_relIsoWithDBeta", &Elecron_relIsoWithDBeta, &b_Elecron_relIsoWithDBeta);
   fChain->SetBranchAddress("Elecron_absiso_EA", &Elecron_absiso_EA, &b_Elecron_absiso_EA);
   fChain->SetBranchAddress("Elecron_relIsoWithEA", &Elecron_relIsoWithEA, &b_Elecron_relIsoWithEA);
   fChain->SetBranchAddress("Electron_iso_passHLTpre", &Electron_iso_passHLTpre, &b_Electron_iso_passHLTpre);
   fChain->SetBranchAddress("Electron_iso_passLoose", &Electron_iso_passLoose, &b_Electron_iso_passLoose);
   fChain->SetBranchAddress("Electron_iso_passMedium", &Electron_iso_passMedium, &b_Electron_iso_passMedium);
   fChain->SetBranchAddress("Electron_iso_passTight", &Electron_iso_passTight, &b_Electron_iso_passTight);
   fChain->SetBranchAddress("Electron_iso_passHEEP", &Electron_iso_passHEEP, &b_Electron_iso_passHEEP);
   fChain->SetBranchAddress("Electron_noiso_passLoose", &Electron_noiso_passLoose, &b_Electron_noiso_passLoose);
   fChain->SetBranchAddress("Electron_noiso_passMedium", &Electron_noiso_passMedium, &b_Electron_noiso_passMedium);
   fChain->SetBranchAddress("Electron_noiso_passTight", &Electron_noiso_passTight, &b_Electron_noiso_passTight);
   fChain->SetBranchAddress("Electron_noiso_passHEEP", &Electron_noiso_passHEEP, &b_Electron_noiso_passHEEP);
   Notify();
}

Bool_t semiLepTTBarLoop::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void semiLepTTBarLoop::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t semiLepTTBarLoop::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef semiLepTTBarLoop_cxx
