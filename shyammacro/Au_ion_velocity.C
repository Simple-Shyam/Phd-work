/* Macro for checking the decay length of D-meson at different momentum by putting its mean decay time from Pdg Booklet*/
// shyam Kumar

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::sqrt;
using std::pow;
void Au_ion_velocity()
{

     
   //gStyle->SetOptStat("nemruoi");
   gStyle->SetOptTitle(0);
   gStyle->SetTitleOffset(.85,"X");gStyle->SetTitleOffset(.85,"Y");
   gStyle->SetTitleSize(.05,"X");gStyle->SetTitleSize(.05,"Y");
   gStyle->SetLabelSize(.05,"X");gStyle->SetLabelSize(.05,"Y");
   gStyle->SetHistLineWidth(2);
   gStyle->SetOptFit(1);

// -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  // ------------------------------------------------------------------------
 double c= 3* std::pow(10.,8.);
 double mass= 183.4343; // mass of Au in GeV
//TCanvas* can = new TCanvas("can","Radiation Length for start detector",0,0,100,100);
TCanvas *c1 = new TCanvas("c1", "c1",0,52,1191,692);
TH2D* h = new TH2D("hist","D-meson, D-meson decay length",2000,0,2000.,1000,1.0e+6,3.0e+8);
h->SetTitle("Velocity of Au-ion vs Energy;Energy (GeV); velocity (m/sec)");
 Int_t ci;   // for color index setting
   ci = TColor::GetColor("#000099");
 for (int p=1; p<=2000; p=p+10)
    {
 double E = p*p + mass*mass;
 E= std:: sqrt(E);

 double gamma = E/mass;
 double velocity = (c/gamma)* std::sqrt(gamma*gamma -1);
 if(E>1360 && E<1370) std:: cout<<" Velocity (m/sec) =" <<velocity<<std::endl;
   h->SetLineColor(ci);
   h->SetMarkerColor(2);
   h->SetMarkerStyle(20);
  h->Fill(E,velocity);
  h-> DrawCopy();
    }   
// -----  Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  cout << endl << endl;
  cout << "Macro finished succesfully." << endl;
  cout << "Real time " << rtime << " s, CPU time " << ctime << " s" << endl;
  cout << endl;
  // ------------------------------------------------------------------------

}

