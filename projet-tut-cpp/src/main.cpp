/*

--SYSTEME DE RECONNAISSANCE DE CHRONIQUES--

Code developpe pour le projet tuteur� "SURVEILLANCE DES PERSONNES DANS L'HABITAT INTELLIGENT" (2018)
par Valentine Bellet, Benjamin Blum, Am�lie Meyer, Ninni Stenkula et Amaury Vignolles

Compilation : g++.exe -Wall -fexceptions -g -std=c++14  -c C:\Users\acer\Desktop\projet-tut-cpp\main.cpp -o obj\Debug\main.o
IDE : Code::Blocks 16.01

*/

#include <iostream>
#include <string>
#include "chronique.h"
#include "event.h"
#include "contrainte.h"
#include "parser.h"
#include "parser_chr.h"
#include "parser_event.h"
#include <vector>
using namespace std;


/* VARIABLES GLOBALES */

int HEURE_COURANTE = 0;
std::list<event> MES_EVENTS ;
std::list<chronique> MES_CHRONIQUES ;
std::vector<elmt_sequence> MA_SEQUENCE ;

/* MAIN */

int main(){

    // recuperation des �venements
	MES_EVENTS = parser_evenements();

    // recuperation des chroniques
	MES_CHRONIQUES = parser_chroniques();

    // recuperation de la sequence
	MA_SEQUENCE = parser();

    /*
    // TEST DE FONCTIONNEMENT  : AFFICHAGE DE LA SEQUENCE LUE

    vector<elmt_sequence>::iterator it;
	for(it=MA_SEQUENCE.begin(); it!=MA_SEQUENCE.end(); it++) {
		(*it).afficher();
	}
    */


    /*
    // TEST DE FONCTIONNEMENT  : AFFICHAGE DES EVENEMENTS LUS

    list<event>::iterator it;
	for(it=MES_EVENTS.begin(); it!=MES_EVENTS.end(); it++) {
		(*it).afficher();
	}
    */

	return 0;
}
