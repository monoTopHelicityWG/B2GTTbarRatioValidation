from os import listdir, mkdir, popen
from os.path import isfile, join, exists

###
#    HATS comment: 
# Now we want to create an interface for our class in python
# Since we have a lot of data, we will write this so that it loops over a directory
# filled with our input files, and spits out a one output file 
# corresponding to the entire directory.
#python runTree.py -i /store/user/rymuelle/MonoTop/B2GTTBar/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8/crab_b2gtreeV5_TT_TuneCUETP8M2T4_13TeV-powheg-pythia8_RunIISummer16MiniAODv2/170914_223209/0000 -o test.root -t ana/TreeSemiLept -m
#python runTree.py -i /store/user/rymuelle/MonoTop/B2GTTBar/JetHT/crab_b2gtreeV5_JetHT_Run2016F-23Sep2016-v1_JSONfinal_dryRun/170919_162328/0000  -o data.root -t ana/TreeSemiLept

###
usage = """%prog [options]
This script takes as input a directory of input .root files, and runs the semiLepTTBarLoop.C macro on them."""

###
#    HATS comment: 
#  Let's not hardcode anything, instead let's run our class's Loop method by
#  passing our python interface some options
#  In case we forget how to use our python interface, we'll write help comments too :-)
###
from optparse import OptionParser
parser = OptionParser(usage)

parser.add_option("-l", "--load", dest = "load",
                  action = "store_true", default = False,
                  help = "do not recompile the class, instead load it from a compiled library" )
parser.add_option("-i", "--inDir", dest = "inDir",
                  help = "the input directory of root files" )
parser.add_option("-t", "--inTreeName", dest = "inTreeName",
                  help = "the name of the input tree inside the input file" )
parser.add_option("-o", "--outFileName", dest = "outFileName",
                  help = "the output root file name. It will be located within the 'output' directory" )
parser.add_option("-m", "--MC", dest = "mc",
                  action = "store_true", default = False,
                  help = "generate MC plots using gen information")
(options, args) = parser.parse_args()

###
#    HATS comment: 
# Here is a pyROOT gotcha: once you import anything from ROOT, the ROOT command line options 
# will override anything you've defined with your OptionParser. So if you define something
# in your options like -l, that will conflict with the ROOT option to disable the ROOT 
# splash logo. So we only import ROOT once we've already parsed our options.
###

from ROOT import *

###   HATS comment:
# let's combine all the input trees into one TChain 
# Then we can pass that to our ROOT class to crunch
###
chain = TChain(options.inTreeName)
inFiles = []
count = 0
#for inFile in filter(None,popen("xrdfs root://cmseos.fnal.gov/ ls -u "+options.inDir).read().split('\n')):
for inFile in filter(None,popen("xrdfs root://cmseos.fnal.gov/ ls -u "+options.inDir).read().split('\n')):
  print inFile
  count = count+ 1
  if ".root" in inFile:
    inFiles.append(inFile)
    if count > 1: break
for sample in inFiles:
  chain.Add(sample)

#inFiles = []
#inFiles.append("/uscms_data/d3/rmueller/MonoTop/B2GAnaFW_ttbar/custom_B2GTTbar/CMSSW_8_0_26/src/Analysis/B2GMonoTop/test/mt_mu_2tev_2h_miniaod.root")
###   HATS comment:
# By default, gSystem.CompileMacro will compile your ROOT class, load it on its own, and then delete it
# once your pyROOT script is closed. Instead, we want to be able to just compile it once, keep the
# compiled library, and then we can reuse it again without recompiling it
# This is important if you're going to run this script e.g. in a cluster submission
# because if two parallel processes try to compile the macro simultaneously,
# one process might try overwriting the library while another is trying to load it.
#
# The options we use are:
# g --> compile with debug symbols. This is nice if you have a bug in your macro
# O --> optimize the code. This does something behind the scenes, so why not
# c --> compile the macro only and don't load it. We do this so that if we only want to load it, we can, but if we want to do both, we won't try twice
# k --> keep the compiled library and don't delete it when the pyroot script ends.
###
if not options.load:
  gSystem.CompileMacro("semiLepTTBarLoop.C", "gOck")

### Now we can load our class into our pyROOT session:
gSystem.Load("semiLepTTBarLoop_C")

### HATS comment:
# now we create an instance of our class
###
instance = semiLepTTBarLoop(chain)

### HATS comment:
# and now we call our class's 'Loop' method
###
if not exists("output"):
  mkdir("output")
instance.Loop("output/%s" % options.outFileName, options.mc)
