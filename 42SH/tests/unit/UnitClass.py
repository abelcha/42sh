#!/usr/bin/python2.7

#-*- encodage:Latin1 -*

from os import *
from sys import *

import  commands

class Unit:

    """
    Class permettant de gerer chaque test unitaire.

    Elle se definie par:
        - un LinkUnit == Lien vers le test unitaire
        - un LinkFct  == Lien vers la fonction a tester
        - un Mode     == Mode de test -> arret en cas d'erreur
                                      -> test memoire
                                      -> etc...
        - un Compil   == choix du compilateur
        - des Flag    == Les flags utiliser pour la compilation
        - un Err      == Valeur de retour pour le quelle on considere une erreur
        - un Mode Verbose == Affiche ou pas les resultat des different appelle systeme
        - un Mode red == Redirige le resultat des fonctions systeme 
                        dans un fichier si verbose desactive
    """

    NbTotTest = 0 #Nombre total d'instance de la class Unit

    def __init__(self,
                 link_unit=".",
                 link_fct=".",
                 verb=0,
                 lib=" -L ./src/env/ -lenv " +
                        "-L ./src/globing -lglobing " +
                        "-L ./src/parsing -lparser " +
                        "-L ./src/history -lhist " +
                        "-L ./src/statck_exec -lexec " +
                        "-L ./src/builtin -lbuilt ",
                 inc=" -I ./include/ ",
                 compil="gcc",
                 flag=" -Wall -Wextra -Werror ",
                 err=1,
                 mode=0,
                 red = " >> rapport_comp.txt"): # Constructeur

        Unit.NbTotTest       += 1

        self.LinkUnit   = link_unit
        self.LinkFct    = link_fct
        self.Mode       = mode
        self.Compil     = compil
        self.Flag       = flag
        self.Err        = err
        self.Verb       = verb
        self.Lib        = lib
        self.Inc        = inc
        if (verb == 0):
            self.Red        = red
        else:
            self.Red        = ""

    def totTest(self):
        return (Unit.NbTotTest) #return le nombre total d'instance

    def compilation(self):
        stdout.write("\033[34m")
        ret,aff = commands.getstatusoutput(self.Compil + " " + 
                        self.LinkUnit + " " + 
                        self.Inc + " " +
                        self.Flag + " " +
                        self.Lib + " " +
                        self.Red)
        stdout.write("\033[37m")
        if (ret > 0):
            if (self.Verb == 1):
                print("\n\033[31mError\033[34m in compilation beetween \033[31m" + 
                      self.LinkUnit +
                      "\033[34m and \033[31m" + 
                      self.LinkFct + "\033[37m")
            if (self.Verb == 1):
                print("\033[34m" + aff + "\033[37m")
            if (self.Mode == 1):
                exit (1)
            return (1)
        return (0)

    def testing(self):
        stdout.write("\033[34m")
        ret,aff = commands.getstatusoutput('./a.out')
        stdout.write ("\033[37m")
        if (ret != 0):
            if (self.Verb == 1):
                print("\n\033[31mError\033[34m in launch \033[31m" + 
                      "\033[31m" + 
                      self.LinkFct + "\033[37m")
            if (self.Verb == 1):
                print("\033[34m" + aff + "\033[37m")
            if (self.Mode == 1):
                exit (1)
            return (1)
        return (0)

    def norme(self):
        return (0)

    def launch(self):
        if (self.compilation() == 1):
            return (1)
        if (self.testing() == 1):
            return (1)
        self.delete()
        return (0)

    def delete(self):
        system("rm -f ./a.out")

if __name__ == "__main__":
    test = Unit("test/test_unit.c", "test/test_fct.c")
    print("\n------------\nDebut du test :\n\n")
    
    print("Valeur de LinkUnit = " + str(test.LinkUnit))
    print("Valeur de LinkFct = " + str(test.LinkFct))
    print("Valeur de Mode = " + str(test.Mode))
    print("Valeur de Compil = " + str(test.Compil))
    print("Valeur de Flag = " + str(test.Flag))
    print("Valeur de Err = " + str(test.Err))
    print("Valeur de Verb = " + str(test.Verb))
    print("Valeur de Red = " + str(test.Red))

    print("Total d'instance = " + str(test.totTest()))
    print("\nResult de compilation = " + str(test.compilation()))

    print("\n------------\n")
