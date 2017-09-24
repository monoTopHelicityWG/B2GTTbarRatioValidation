import ROOT as r
import math

c1 = r.TCanvas("c1", "c1",500, 600)

fmc = r.TFile("./output/test.root", "read")
fdata = r.TFile("./output/data.root", "read")

fmc.cd()
dirList = r.gDirectory.GetListOfKeys()
leg = r.TLegend(.1, .6, .4, .8)
for k1 in dirList: 
  h1 = k1.ReadObj()
  name =  h1.GetName()
  dataHist = fdata.Get(name)
  if("TH1" in name):
 	h1.SetLineColor(2)
 	dataHist.SetLineColor(4)
  	h1.Scale(1.0/h1.GetEntries())
  	dataHist.Scale(1.0/dataHist.GetEntries())
  	leg.AddEntry(h1,"MC (TT)", "l")
  	leg.AddEntry(dataHist,"Data/2016H", "l")


  	h1.Draw()
  	dataHist.Draw("same")
  	leg.Draw()
  	c1.SaveAs("output/{}.png".format( h1.GetName() ))
  	leg.Clear()
  if("TH2" in name):
  	h1.Draw("colz")
  	c1.SaveAs("output/MC_{}.png".format( h1.GetName() ))
  	dataHist.Draw("colz")
  	c1.SaveAs("output/DATA_{}.png".format( h1.GetName() ))
  