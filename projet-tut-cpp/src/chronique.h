#ifndef CHRONIQUE_H_INCLUDED
#define CHRONIQUE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "contrainte.h"
using namespace std;


/* CLASSES */

// Chronique unitaire
class chronique {

private:

  /* ATTRIBUTS */

  string nom; //initialis� par le fichier de d�finition des chroniques
  bool event_verify; // initialis� � false, utile pour les chroniques de chroniques
  int nb_validation; // initialis� � 0, indique le nombre de validation de la chronique
  std::vector<int> heure_validation; // tableau des heures de validation
  int nb_contraintes_restantes; // initialis� � nb_contraintes_total
  int nb_contraintes_total; // initialis� par le fichier de d�finition des chroniques
  // TYPE contraintes; // tableau de contraintes, initialis� par le fichier de d�finition des chroniques


  /* ASSESSEURS  */

  // Mutateur, change la valeur d'�v�nement de la chronique
  void set_event(bool event){
    event_verify = event;
  }

  // Reinitialisateur, remet � 0 la valeur du nombre de validation
  void reset_valid(){
    event_verify = 0;
  }

  // Reinitialisateur, remet � 0 le tableau des heures de validation
  void reset_h_valid(){
    heure_validation.clear();
  }

  // Reinitialisateur, remet au maximum la valeur des contraintes restantes � valider
  void reset_nb_contraintes(){
    nb_contraintes_restantes=nb_contraintes_total;
  }

public:

  /* CONSTRUCTEURS */

  // Constructeur �volu�, cr�� la chronique � partir des donn�es
  chronique(string label, int nb_contraintes){
    nom=label;
    event_verify=false;
    nb_validation=0;
    heure_validation.clear();
    nb_contraintes_restantes = nb_contraintes;
    nb_contraintes_total = nb_contraintes;
  // TYPE contraintes;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de la chronique
  string get_nom(){
	return nom;
  }

  // Assesseur, ressort l'�tat de la chronique (pour les chroniques de chroniques)
  bool get_event(){
	return event_verify;
  }

  // Assesseur, ressort le nombre de validation
  int get_nb_valid(){
	return nb_validation;
  }

  // Assesseur, ressort le nombre de validation
  std::vector<int> get_h_valid(){
	return heure_validation;
  }

  // Mutateur, change le label de l'�l�ment
  void set_nom(string name){
    nom = name;
  }

  /* METHODES */

  // Affiche certains �l�ments dans la console
  void afficher(){
    cout<<"nom = "<<nom<<endl;
    cout<<"nombre de validation = "<<nb_validation<<endl;
    cout<<"derniere validation = "<<heure_validation.back()<<endl;
    cout<<"evenement detectable = "<<event_verify<<endl;
    cout<<"nombre de contraintes total = "<<nb_contraintes_total<<endl;
    cout<<"nombre de contraintes restantes = "<<nb_contraintes_restantes<<endl;
  }


};

/* FUNCTIONS */



#endif
