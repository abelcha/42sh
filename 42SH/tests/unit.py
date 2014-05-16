#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

from os import *
from sys import *
from unit.UnitClass import *
from   getopt import *
import commands

def     usage():
    print("Usage : " +
          argv[0] + " <file_test> <file_to_test> ...\n"
          "file_test and file_to_test can be repeat")

try:
    opt, av = getopt(argv[1:], "festvli", ["file", "extention", "suffixe", "testing", "verbose", "link", "include"])
except GetoptError:
    usage()
    print("Error")
    exit(1)


## Definition des lib ##
lib =  "-L ./lib/ -lmy "
lib += "-L ./lib/ -lenv " 
lib += "-L ./lib/globing/ -lglobing "
lib += "-L ./src/parsing -lpars "
#lib += "-L ./src/history -lhist "
#lib += "-L ./src/statck_exec -lexec "
lib += "-L ./src/builtin -lbuilt "
##

a = 0
link_test = "./"
total = 0
verb = 0
link = "."
include = "./include "
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
        i += 1
    if o in ("-i", "--include"):
        include = av[i]
        i += 1

stat,fin = commands.getstatusoutput('find ' + link + '  -name "unit_*.c"')
i = 0

list_file = str(fin).split("\n")

while i < len(list_file):
    unit_file = list_file[i].split("unit_")
    status,aff = commands.getstatusoutput("find " + link + " -name " + unit_file[1])
    test_file = aff
    test = Unit(list_file[i], test_file, verb, lib, " -I " + include)
    stdout.write("\033[37mTesting : [" + test_file + "] ...\t\033[37m")
    ret = test.launch()
    if (ret == 0):
        print ("\t{\033[35mOK\033[37m}\n")
    else:
        print ("{\033[31mFALSE\033[37m}\n")
        total += 1
    i += 1

m = 0
m_total = 0
for o, a in opt:
    if o in ("-t", "--testing"):
        status,aff = commands.getstatusoutput("find ./src -name 'Makefile'")
        i = 0
        make_list = ("".join((aff.split('Makefile')))).split('\n')
        if (status != 0):
            print ("Error find Makefile")
        while i < len(make_list):
            stdout.write("Qualification : " + make_list[i] + " ...\t")
            status,aff = commands.getstatusoutput("make -C " + make_list[i])
            if (status != 0):
                print ("\033[33mError in make\033[37m : " + make_list[i])
                m += 1
                for o, a in opt:
                    if o in ("-v", "--verbose"):
                        print ("\033[34m" + aff + "\033[37m")
            else:
                status,aff = commands.getstatusoutput("make test -C " + make_list[i])
                bi = make_list[i] + "test"
                status,aff = commands.getstatusoutput(bi)
                if (status != 0):
                    print ("\033[31mError in bin\033[37m :" + bi)
                    m += 1
                    for o, a in opt:
                        if o in ("-v", "--verbose"):
                            print ("\033[34m" + aff + "\033[37m")
                else:
                    print ("\033[32m\t\tOK! \033[37m")

            i += 1
            m_total += 1

print ("\nYou have " + str(total) + " Error " + "on " + str(test.totTest()) + " test")
print ("\nYou have " + str(m) + " Error " + "on " + str(m_total) + " Qualification")
