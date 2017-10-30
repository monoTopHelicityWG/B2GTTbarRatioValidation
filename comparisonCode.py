import ROOT as r
import math

c1 = r.TCanvas("c1", "c1",500, 600)

#LH = r.TFile("./output/MT_1TeV_LH_gen_cut.root", "read")
#RH = r.TFile("./output/MT_1TeV_LH_gen_cut_bad.root", "read")
LH = r.TFile("./output/MT_1TeV_LH.root", "read")
RH = r.TFile("./output/MT_1TeV_RH.root", "read")

#r.gStyle.SetOptStat(0)


#r.gPad.SetLogy()

LH.cd()
dirList = r.gDirectory.GetListOfKeys()
leg = r.TLegend(.5, .7, .9, .9)
for k1 in dirList: 
  LH_h = k1.ReadObj()
  name =  LH_h.GetName()
  RH_h = RH.Get(name)
  if("TH1" in name and LH_h.GetEntries() > 0):
    #print name, type(RH_h)
    LH_h.SetLineColor(2)
    RH_h.SetLineColor(4)
    LH_h.Scale(1.0/LH_h.GetEntries())
    RH_h.Scale(1.0/RH_h.GetEntries())
    leg.AddEntry(LH_h,"MonoTop gen RH (MC)", "l")
    leg.AddEntry(RH_h,"MonoTop gen LH (MC)", "l")
    #leg.AddEntry(LH_h,"MonoTop gen good (MC)", "l")
    #leg.AddEntry(RH_h,"MonoTop gen bad (MC)", "l")

    #LH_h.Rebin(4)
    #RH_h.Rebin(4)
    if LH_h.GetMaximum() > RH_h.GetMaximum():
      RH_h.GetYaxis().SetRangeUser(0, LH_h.GetMaximum()*1.15)
    RH_h.Draw()
    LH_h.Draw("same")
    #leg.Draw()
    #c1.SaveAs("output/GB_{}.png".format( LH_h.GetName() ))
    c1.SaveAs("output/1_tev_no_cut_RVL_{}.png".format( LH_h.GetName() ))
    leg.Clear()
  if("TH2" in name):
    LH_h.Draw("colz")
    c1.SaveAs("output/1_tev_no_cut_LH_{}.png".format( LH_h.GetName() ))
    #c1.SaveAs("output/good_{}.png".format( LH_h.GetName() ))
    RH_h.Draw("colz")
    c1.SaveAs("output/1_tev_no_cut_RH_{}.png".format( LH_h.GetName() ))
    #c1.SaveAs("output/bad_{}.png".format( LH_h.GetName() ))
    LH_h.Rebin2D(4,4)
    RH_h.Rebin2D(4,4)
    RH_h.Divide(LH_h)
    RH_h.Draw("colz")
    c1.SaveAs("output/1_tev_no_cut_RH_divided_{}.png".format( LH_h.GetName() ))