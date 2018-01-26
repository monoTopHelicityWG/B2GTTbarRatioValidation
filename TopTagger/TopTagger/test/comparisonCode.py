import ROOT as r
import math

c1 = r.TCanvas("c1", "c1",500, 600)


#LH = r.TFile("./output/MT_1TeV_lep_LH.root", "read")
RH_2 = r.TFile("./hists/MT_RH_2TeV.root", "read")
LH_2 = r.TFile("./hists/MC_MT_2TeV_LH.root", "read")

DY_100_250 = r.TFile("./hists/DYJetsTLL_Pt-100To250.root", "read")
DY_250_400 = r.TFile("./hists/DY-250to400.root", "read")
DY_400_650 = r.TFile("./hists/DY-400to650.root", "read")
DY_650_Inf = r.TFile("./hists/DY-650toInf.root", "read")


ST_t_anti = r.TFile("./hists/ST-t-anti.root", "read")
ST_t_top = r.TFile("./hists/ST-t-top.root", "read")
ST_tw_anti = r.TFile("./hists/ST_tw_anti.root", "read")
ST_tw_top = r.TFile("./hists/ST_tw_top.root", "read")

r.gStyle.SetOptStat(0)

Lumi = 35900

output_text = "THStack"

no_xsection = False

if no_xsection: output_text = output_text+"_no_xsection"

log = True
if log: 
    r.gPad.SetLogy()
    output_text = output_text+"_log"


RH_2_h = RH_2.Get("TH1F_cutflow")
RH_2_xsection = 0.01564
if no_xsection: RH_2_xsection = 1
RH_2_events = RH_2_xsection*Lumi
RH_2_Entries = RH_2_h.GetBinContent(1)
RH_2_norm = RH_2_events/RH_2_Entries
print "RH_2 norm, entries, expected events", RH_2_norm , RH_2_Entries, RH_2_events

LH_2_h = LH_2.Get("TH1F_cutflow")
LH_2_xsection = 0.01564
if no_xsection: LH_2_xsection = 1
LH_2_events = LH_2_xsection*Lumi
LH_2_Entries = LH_2_h.GetBinContent(1)
LH_2_norm = LH_2_events/LH_2_Entries
print "LH_2 norm, entries, expected events", LH_2_norm , LH_2_Entries, LH_2_events

DY_100_250_h = DY_100_250.Get("TH1F_cutflow")
DY_100_250_xsection = 83.12
if no_xsection: DY_100_250_xsection = 1
DY_100_250_events = DY_100_250_xsection*Lumi
DY_100_250_Entries = DY_100_250_h.GetBinContent(1)
DY_100_250_norm = DY_100_250_events/DY_100_250_Entries
print "DY_100_250 norm, entries, expected events", DY_100_250_norm , DY_100_250_Entries, DY_100_250_events

DY_250_400_h = DY_250_400.Get("TH1F_cutflow")
DY_250_400_xsection =  3.047
if no_xsection: DY_250_400_xsection =  1
DY_250_400_events = DY_250_400_xsection*Lumi
DY_250_400_Entries = DY_250_400_h.GetBinContent(1)
DY_250_400_norm = DY_250_400_events/DY_250_400_Entries
print "DY_250_400 norm, entries, expected events", DY_250_400_norm , DY_250_400_Entries, DY_250_400_events

DY_400_650_h = DY_400_650.Get("TH1F_cutflow")
DY_400_650_xsection = 0.3921
if no_xsection: DY_400_650_xsection = 1
DY_400_650_events = DY_400_650_xsection*Lumi
DY_400_650_Entries = DY_400_650_h.GetBinContent(1)
DY_400_650_norm = DY_400_650_events/DY_400_650_Entries
print "DY_400_650 norm, entries, expected events", DY_400_650_norm , DY_400_650_Entries, DY_400_650_events

DY_650_Inf_h = DY_650_Inf.Get("TH1F_cutflow")
DY_650_Inf_xsection = 0.03636
if no_xsection: DY_650_Inf_xsection = 1
DY_650_Inf_events = DY_650_Inf_xsection*Lumi
DY_650_Inf_Entries = DY_650_Inf_h.GetBinContent(1)
DY_650_Inf_norm = DY_650_Inf_events/DY_650_Inf_Entries
print "DY_650_Inf norm, entries, expected events", DY_650_Inf_norm , DY_650_Inf_Entries, DY_650_Inf_events

ST_t_anti_h = ST_t_anti.Get("TH1F_cutflow")
ST_t_anti_xsection = 80.95
if no_xsection: ST_t_anti_xsection = 1
ST_t_anti_events = ST_t_anti_xsection*Lumi
ST_t_anti_Entries = ST_t_anti_h.GetBinContent(1)
ST_t_anti_norm = ST_t_anti_events/ST_t_anti_Entries
print "ST_t_anti norm, entries, expected events", ST_t_anti_norm , ST_t_anti_Entries, ST_t_anti_events

ST_t_top_h = ST_t_top.Get("TH1F_cutflow")
ST_t_top_xsection = 136.02
if no_xsection: ST_t_top_xsection = 1
ST_t_top_events = ST_t_top_xsection*Lumi
ST_t_top_Entries = ST_t_top_h.GetBinContent(1)
ST_t_top_norm = ST_t_top_events/ST_t_top_Entries
print "ST_t_top norm, entries, expected events", ST_t_top_norm , ST_t_top_Entries, ST_t_top_events

ST_tw_anti_h = ST_tw_anti.Get("TH1F_cutflow")
ST_tw_anti_xsection =35.85
if no_xsection: ST_tw_anti_xsection =1
ST_tw_anti_events = ST_tw_anti_xsection*Lumi
ST_tw_anti_Entries = ST_tw_anti_h.GetBinContent(1)
ST_tw_anti_norm = ST_tw_anti_events/ST_tw_anti_Entries
print "ST_tw_anti norm, entries, expected events", ST_tw_anti_norm , ST_tw_anti_Entries, ST_tw_anti_events

ST_tw_top_h = ST_tw_top.Get("TH1F_cutflow")
ST_tw_top_xsection = 35.85
if no_xsection: ST_tw_top_xsection = 1
ST_tw_top_events = ST_tw_top_xsection*Lumi
ST_tw_top_Entries = ST_tw_top_h.GetBinContent(1)
ST_tw_top_norm = ST_tw_top_events/ST_tw_top_Entries
print "ST_tw_top norm, entries, expected events", ST_tw_top_norm , ST_tw_top_Entries, ST_tw_top_events



RH_2.cd()
dirList = r.gDirectory.GetListOfKeys()
leg = r.TLegend(.6, .5, .89, .89)
for k1 in dirList: 
    RH_h = k1.ReadObj()
    name =  RH_h.GetName()
    LH_h = LH_2.Get(name)
    DY_100_250_h = DY_100_250.Get(name)
    DY_250_400_h = DY_250_400.Get(name)
    DY_400_650_h = DY_400_650.Get(name)
    DY_650_Inf_h = DY_650_Inf.Get(name)
    ST_t_anti_h = ST_t_anti.Get(name)
    ST_t_top_h = ST_t_top.Get(name)
    ST_tw_anti_h = ST_tw_anti.Get(name)
    ST_tw_top_h = ST_tw_top.Get(name)

    hs = r.THStack("hs",name)
    if(RH_h.GetEntries() > 0):



        RH_h.Scale(RH_2_norm)
        LH_h.Scale(LH_2_norm)
        DY_100_250_h.Scale(DY_100_250_norm)
        DY_250_400_h.Scale(DY_250_400_norm)
        DY_400_650_h.Scale(DY_400_650_norm)
        DY_650_Inf_h.Scale(DY_650_Inf_norm)
        ST_t_anti_h.Scale(ST_t_anti_norm)
        ST_t_top_h.Scale(ST_t_top_norm)
        ST_tw_anti_h.Scale(ST_tw_anti_norm)
        ST_tw_top_h.Scale(ST_tw_top_norm)

        DY_100_250_h.SetLineColor(91)
        DY_100_250_h.SetFillColor(91)
        DY_250_400_h.SetLineColor(93)
        DY_250_400_h.SetFillColor(93)
        DY_400_650_h.SetLineColor(95)
        DY_400_650_h.SetFillColor(95)
        DY_650_Inf_h.SetLineColor(97)
        DY_650_Inf_h.SetFillColor(97)
        ST_t_anti_h.SetLineColor(52)
        ST_t_anti_h.SetFillColor(52)
        ST_t_top_h.SetLineColor(54)
        ST_t_top_h.SetFillColor(54)
        ST_tw_anti_h.SetLineColor(56)
        ST_tw_anti_h.SetFillColor(56)
        ST_tw_top_h.SetLineColor(58)
        ST_tw_top_h.SetFillColor(58)
        RH_h.SetLineColor(3)
        RH_h.SetMarkerStyle(8)
        RH_h.SetMarkerColor(3)
        RH_h.SetMarkerSize(1)

        LH_h.SetLineColor(6)
        LH_h.SetMarkerStyle(8)
        LH_h.SetMarkerColor(6)
        LH_h.SetMarkerSize(1)

        leg.Clear()
        leg.AddEntry(RH_h, "RH_h", "l")
        leg.AddEntry(LH_h, "LH_h", "l")
        leg.AddEntry(DY_100_250_h, "DY_100_250_h", "f")
        leg.AddEntry(DY_250_400_h, "DY_250_400_h", "f")
        leg.AddEntry(DY_400_650_h, "DY_400_650_h", "f")
        leg.AddEntry(DY_650_Inf_h, "DY_650_Inf_h", "f")
        leg.AddEntry(ST_t_anti_h, "ST_t_anti_h", "f")
        leg.AddEntry(ST_t_top_h, "ST_t_top_h", "f")
        leg.AddEntry(ST_tw_anti_h, "ST_tw_anti_h", "f")
        leg.AddEntry(ST_tw_top_h, "ST_tw_top_h", "f")
        leg.SetBorderSize(0);




        hs.Add(DY_100_250_h)
        hs.Add(DY_250_400_h)
        hs.Add(DY_400_650_h)
        hs.Add(DY_650_Inf_h)
        hs.Add(ST_t_anti_h)
        hs.Add(ST_t_top_h)
        hs.Add(ST_tw_anti_h)
        hs.Add(ST_tw_top_h)

        hs.Draw("HIST")
        hs.SetMinimum(.1)
        RH_h.Draw("same")
        LH_h.Draw("same")
        leg.Draw()
        c1.SaveAs("hists/output/{}_{}.png".format(output_text, name ))
        


#  LH_h = k1.ReadObj()
#  name =  LH_h.GetName()
#  RH_h = RH.Get(name)
#  if("TH1" in name and LH_h.GetEntries() > 0):
#    #print name, type(RH_h)
#    LH_h.SetLineColor(2)
#    RH_h.SetLineColor(4)
#    LH_h.Scale(1.0/LH_h.GetEntries())
#    RH_h.Scale(1.0/RH_h.GetEntries())
#    leg.AddEntry(LH_h,"MonoTop LH 1TeV Muon Channel", "l")
#    leg.AddEntry(RH_h,"MonoTop RH 1TeV Muon Channel", "l")
#    #leg.AddEntry(LH_h,"MonoTop gen good (MC)", "l")
#    #leg.AddEntry(RH_h,"MonoTop gen bad (MC)", "l")
#    #leg.AddEntry(LH_h,"LH SUSY top tagger", "l")
#    #leg.AddEntry(RH_h,"RH SUSY top tagger", "l")
#
#    #LH_h.Rebin(4)
#    #RH_h.Rebin(4)
#    if LH_h.GetMaximum() > RH_h.GetMaximum():
#      RH_h.GetYaxis().SetRangeUser(0, LH_h.GetMaximum()*1.15)
#    RH_h.Draw()
#    LH_h.Draw("same")
#    leg.Draw()
#    #c1.SaveAs("output/GB_{}.png".format( LH_h.GetName() ))
#    c1.SaveAs("output/1TeV_Mu_{}.png".format( LH_h.GetName() ))
#    leg.Clear()
#  if("TH2" in name):
#    LH_h.Draw("colz")
#    c1.SaveAs("output/1TeV_Mu{}.png".format( LH_h.GetName() ))
#    #c1.SaveAs("output/good_{}.png".format( LH_h.GetName() ))
#    RH_h.Draw("colz")
#    c1.SaveAs("output/1TeV_Mu{}.png".format( LH_h.GetName() ))
#    #c1.SaveAs("output/bad_{}.png".format( LH_h.GetName() ))
#    LH_h.Rebin2D(4,4)
#    RH_h.Rebin2D(4,4)
#    RH_h.Divide(LH_h)
#    RH_h.Draw("colz")
#    c1.SaveAs("output/1TeV_Mudivide_{}.png".format( LH_h.GetName() ))
#