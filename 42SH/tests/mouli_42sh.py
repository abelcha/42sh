#!/usr/bin/python2.7

#By Vink


from sys import *
from getopt import *
import  commands
from test import *

version = " 1.5"

######################
####### COLOR ########
######################

red = "\033[31m"
green = "\033[32m"
yellow = "\033[33m"
blue = "\033[34m"
white = "\033[37m"

######################

#######################
###### Test Class #####
#######################

class   Testing:
    """
    Class permettant de gerer les different test.

    Elle contient les attributs suivants :
        - shell_ref : le lien du shell de reference a utiliser
        - use_ref : booleen definissant si on veut comparer avec un autre shell
        - path : le lien vers le shell de test
        - test : le test a faire
        - verb : Detail des tests
    """

    NbTotTest = 0
    NbTestFail = 0
    NbTestSuccess = 0
    NbTestListFail = list()
    NbTestListSuccess = list()

    def __init__(self,
                 shell_ref = "tcsh",
                 use_ref = False,
                 path = "./42sh",
                 test = "",
                 verb = True,
                 rapp = None
                 ):
        
        Testing.NbTotTest   += 1

        self.Shell_ref      = shell_ref
        self.Use_ref        = use_ref
        self.Path           = path
        self.Try            = test
        self.Verb           = verb
        self.Rapp           = rapp

    def totTest(self):
        return (Test.NbTotTest)

    def addTestListFail(self, nb):
        Testing.NbTestListFail.append(nb)

    def addTestListSuccess(self, nb):
        Testing.NbTestListSuccess.append(nb)

    def TestListFail(self):
        return (Testing.NbTestListFail)

    def TestListSuccess(self):
        return (Testing.NbTestListSuccess)

    def PrintTesting(self, test, nb):
        s = str(str(nb) + " : Testing [" + str(yellow) + str(test) + str(white) + "] ...\t")
        return (s)
    
    def runTest(self, nb):
        stdout.write(self.PrintTesting(self.Try, nb))

        ret,aff = launch_test(self.Path, self.Try)
        r,a = launch_test(self.Shell_ref, self.Try)

        stdout.write(str("\n => your shell have return : "))
        s = (self.PrintTesting(self.Try, nb) + " Your shell have return : ")
        if (ret != 0):
            color(red)
            stdout.write(str("Error "))
            s += red + "Error " + white
            color(white)
        else:
            color(green)
            stdout.write(str("Ok "))
            s += green + "Ok " + white
            color(white)
        if (self.Verb == True):
            print ("\n#############")
            print ("#### YOU ####")
            print ("#############")
            self.verbTest(ret, aff)
        if (self.Use_ref == True):
            stdout.write(str("{" + self.Shell_ref + "} : "))
            if (self.Verb == True):
                print ("\n############")
                print ("### " + self.Shell_ref + " ###")
                print ("############")
                self.verbTest(r, a)
            if (a != aff):
                color(red)
                stdout.write(str("You have difference in display "))
                color(white)
            else:
                color(green)
                stdout.write(str("You have same display "))
                color(white)
        if (r == ret):
            color(green)
            print (" : (same return that references shell)")
            s += green + (" : (same return that references shell)") + white
            Testing.NbTestSuccess += 1
            self.addTestListSuccess(nb)
            color(white)
        else:
            color(red)
            print (" : (diffirence return that references shell)")
            s += red + (" : (difference return that references shell)") + white
            Testing.NbTestFail += 1
            self.addTestListFail(nb)
            color(white)
        if (self.Rapp != None):
            write_in_file(s, self.Rapp)
        return (0)

    def verbTest(self, ret, aff):
        color(blue)
        print str("\n:::: Result of test ::::\n")
        color(white)
        print str("---------------")
        print str(aff)
        print str("---------------")
        color(blue)
        print str(":::: Return of shell test ::::\n")
        color(white)
        print str("________________________\n")
        color(blue)
        print str(ret)
        color(white)
        print str("________________________\n")
        return (0)

    def writeFile(self, ret, aff):
        return (0)
#######################

########################
###### Utils Func ######
########################

def color(col):
    stdout.write(col)

def launch_test(shell, test):
    ret,aff = commands.getstatusoutput("echo '" + test + "' | " + shell)
    return ([ret,aff])

def usage(): 
    print str("Mouli 42sh version " + version)
    print "usage : ./42sh_test.py [option]"
    print "-u : print usage"
    print "-s=NB : start in cmd num NB in list of test"
    print "-e=NB : finish in cmd num NB in list of test"
    print "-m : you need to give one touch to go on next test"
    print "-t=SHELL : exec also the test with a over shell and test if is same"
    print "-v : print all information"
    print "-l=LIST : choose beetwen differences list of test"
    print "-r : to have a rapport of test you have fail and test you have success"
    print "-f=FILE : make a rapport of testing an put this result in specified file"
    print "-a : test with all list in test.py"
    print "-i : make test with env -i"
    print "-b : specifie bin to use"
    print "-c : make a test only with test that return a error"

def check_arg(start, use, test):
    if (use == True):
        usage()
        exit(0)
    if (start < 1 or start > len(test)):
        print str("Error : " + str(start) + " is not in range list of test")
        exit(0)

def write_in_file(string, dest_file):
    commands.getstatusoutput("echo '" + string + "' >> " + dest_file)

def launch_one_test(start, end, manuel, unit, verb, test):
    if (verb == True):
        print str("\n////////////////////")
    print("")
    unit.Try = test[start]
    unit.runTest(start)
    if (verb == True):
        print str("////////////////////\n")
    if (manuel == True):
        r = raw_input("Enter...")
    print("")    

def launching_test(start, end, manuel, unit, verb, test):
    while (start <= end):
        launch_one_test(start, end, manuel, unit, verb, test)
        start += 1
########################


########################
#######  MAIN   ########
########################

try:
        opts, args = getopt(argv[1:], "us:mt:vl:e:rf:aib:c:", ["usage", "start=", "manuel", "test=",
        "verb", "list=", "end=", "recap", "file=", "all", "i", "bin=", "check="])
except  GetoptError, err:
        print str(err)
        usage()
        exit(1)

############

recap = False
start = 1
manuel = False
use = False
shell_ref = "tcsh"
use_ref = False
verb = False
nb = 1
end = -1
rapp_file = None
al = False
shell="./42sh"
check = 0

for o, a in opts:
    if o in ("-u", "--usage"):
        use = True
    elif o in ("-s", "--start"):
        try:
            start = int(a)
        except:
            print str("Error " + str(a) + " is not a number")
            exit(1)
    elif o in ("-m", "--manuel"):
        manuel = True
    elif o in ("-t", "--test"):
        shell_ref = a
        use_ref = True
    elif o in ("-v", "--verb"):
        verb = True
    elif o in ("-l", "--list"):
        try:
            nb = int(a)
        except:
            print str("Error " + str(a) + " is not a number")
            exit(1)
    elif o in ("-e", "--end"):
        try:
            end = int(a)
        except:
            print str("Error " + str(a) + " is not a number")
            exit(1)
    elif o in ("-r", "--recap"):
        recap = True
    elif o in ("-f", "--file"):
        rapp_file = a
    elif o in ("-a", "--all"):
        al = True
    elif o in ("-i", "--i"):
        shell = "env -i " + shell
    elif o in ("-b", "--bin"):
        shell = str(a)
    elif o in ("-c", "--check"):
        try:
            check = int(a)
        except:
            print str("Error " + str(a) + " is not a number")
            exit(1)

#############

if (rapp_file != None):
    write_in_file("\n###############\n", rapp_file)
    write_in_file("_______________\n", rapp_file)
    commands.getstatusoutput("echo `date` >> " + rapp_file)
    write_in_file("_______________\n", rapp_file)

if (al == False):
    test = list_of_test(nb)
    if (end < 0):
        end = len(test)
    check_arg(start, use, test)
    if (end > len(test) or end < 0 or end < start):
        print ("Error : value of end is unvable")
        exit(1)
    unit = Testing(shell_ref, use_ref, shell, "", verb, rapp_file)
    launching_test(start, end, manuel, unit, verb, test)
else:
    test = list_of_test(nb)
    while (test != None):
        unit = Testing(shell_ref, use_ref, shell, "", verb, rapp_file)  
        check_arg(start, use, test)
        launching_test(start, len(test), manuel, unit, verb, test)
        nb += 1
        test = list_of_test(nb)

if (recap == True):
    print ("List of result with [OK] return :")
    color(green)
    print unit.TestListSuccess()
    color(white)
    print ("List of result with [Error] return :")
    color(red)
    print unit.TestListFail()
    color(white)

if (rapp_file != None):
    write_in_file("\n###############", rapp_file)

i = 0
u = 0
error = unit.TestListFail()
test = list_of_test(nb)

if (check > 0):
    print ("##################################")
    print ("##################################")
    print ("###### TEST WITH ERROR ! #########")
    print ("##################################")
    print ("##################################")
    while (i < len(test)):
        if (i == int(error[u])):
            launch_one_test(i, end, manuel, unit, verb, test)
            u += 1
        i += 1
