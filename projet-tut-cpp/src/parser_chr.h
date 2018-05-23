/*

UTILISATION DU PARSEUR-CHRONIQUE

- Le fichier des chroniques doit s'appeler "chroniques.txt et se trouver à l'adresse "./txt/".
- La syntaxe pour chaque chronique est exactement : nom;nb_contraintes:(nom1,temps1,type1)(nom2,temps2,type2)...(nomi,tempsi,typei)
- Chaque chronique est séparée par un retour à la ligne

*/

#ifndef PARSER_CHR_H_INCLUDED
#define PARSER_CHR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "chronique.h"
using namespace std;

/* FUNCTIONS */

std::list<chronique> parser_chroniques(); // Parseur : traduit chroniques.txt en chroniques

#endif
