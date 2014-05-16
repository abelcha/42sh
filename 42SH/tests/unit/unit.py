#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

from os import *
from sys import *
from   UnitClass import *
from   getopt import *
import commands

def     usage():
    print("Usage : " +
          argv[0] + " <file_test> <file_to_test> ...\n"
          "file_test and file_to_test can be repeat")

try:
    opt, av = getopt(argv[1:], "festvl", ["file", "extention", "suffixe", "testing", "verbose", "link"])
except GetoptError:
    usage()
    print("Error")
    exit(1)

a = 0
link_test = "./"
total = 0
verb = 0
link = "."

i = 0
for o, a in opt:
    if o in ("-f", "--file"):
        link_test = av[i]
        a = 1
        i += 1
    if o in ("-e", "--extention"):
        ext = av[i]
        i += 1
    if o in ("-s", "--suffixe"):
        suf = av[i]
        i += 1
    if o in ("-v", "--v"):
        verb = 1
    if o in ("-l", "--link"):
        link = av[i]

stat,fin = commands.getstatusoutput('find ' + link + '  -name "unit_*.c"')
i = 0

list_file = str(fin).split("\n")

while i < len(list_file):
    unit_file = list_file[i].split("unit_")
    status,aff = commands.getstatusoutput("find " + link + " -name " + unit_file[1])
    test_file = aff
    test = Unit(list_file[i], test_file, verb)
    stdout.write("\033[37mTesting : [" + test_file + "] ...\t\033[37m")
    ret = test.launch()
    if (ret == 0):
        print ("\t{\033[35mOK\033[37m}\n")
    else:
        print ("{\033[31mFALSE\033[37m}\n")
        total += 1
    i += 1

for o, a in opt:
    if o in ("-t", "--testing"):
        status,aff = commands.getstatusoutput("find . -name 'Makefile'")
        i = 0
        print aff
        make_list = aff.split('\n')
        if (status != 0):
            print ("Error find Makefile")
        while i < len(make_list):
            status,aff = commands.getstatusoutput("make -C " + make_list[i])
            if (status != 0):
                print ("Error in make : " + make_list[i])
            else:
                b = make_list[i].split("Makefile")
                bi = b[0] + "test"
                status,aff = commands.getstatusoutput(bi)
                if (status != 0):
                    print ("Error :" + bi)
            i += 1

print ("\nYou have " + str(total) + " Error " + "on " + str(test.totTest()) + " test")
