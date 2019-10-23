///////////// code for checking the basic things works in ALICE and also in PANDA of particles by shyam kumar

#include "TGraphErrors.h"
#include "TF1.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TMath.h"

void check()
   {

////////////////////////////////////////////////////// style of the plot
   gStyle->SetPalette(1);
   gStyle->SetOptTitle(0);
   gStyle->SetTitleOffset(.85,"X");gStyle->SetTitleOffset(.85,"Y");
   gStyle->SetTitleSize(.05,"X");gStyle->SetTitleSize(.05,"Y");
   gStyle->SetLabelSize(.05,"X");gStyle->SetLabelSize(.05,"Y");
   gStyle->SetHistLineWidth(2);
   gStyle->SetOptFit(1);
     
///////////////////////////////////////////////Reading the root file
 TFile *f = TFile::Open("test.root");
 TTree *sim = (TTree*)f->Get("cbmsim"); 
  
TCanvas* c1 = new TCanvas("Simple plot", "Simulation", 100, 100, 800, 800);
c1->Divide(2,2);
TH1D *Pdg = new TH1D("Pdg","Pdg code of Particles",100,0,2300);
TH2D *Points= new TH2D("Points","MC Points",100,-50,50,100,-50,50);
TH1D *Zpoints = new TH1D("Zpoints","Z Points on TPC",100,0,2300);
TH1D *Eloss = new TH1D("Eloss","Energy loss for each MC Point",100,0,20);

//////////////////////////////////////////////////////////////
c1->cd(1);
sim->Draw("MCTrack.fPdgCode>> Pdg");
Pdg->GetXaxis()->SetTitle("MCTrack.Pdgcode");
//////////////////////////////////////////////////////////////////////
c1->cd(2);
sim->Draw("CeeTpcPoint.fX:CeeTpcPoint.fY>> Points","","colz");
Points->GetXaxis()->SetTitle("X Points");
Points->GetYaxis()->SetTitle("Y Points");
/////////////////////////////////////////////////////////////////////
c1->cd(3);
sim->Draw("CeeTpcPoint.fZ>> Zpoints");
Zpoints->GetXaxis()->SetTitle("Z Points");
///////////////////////////////////////////////////////////////////////////////////
c1->cd(4);
sim->Draw("CeeTpcPoint.fELoss*1000000 >> Eloss");
Eloss->GetXaxis()->SetTitle("Energy Loss (KeV)");

}
