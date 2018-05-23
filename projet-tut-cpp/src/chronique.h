#ifndef CHRONIQUE_H_INCLUDED
#define CHRONIQUE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "contrainte.h"
using namespace std;


/* VARIABLES GLOBALES APPELEES */

extern int HEURE_COURANTE; // Variable du temps, mise � jour tout au long de la lecture de la s�quence


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
  std::vector<contrainte> contraintes; // tableau de contraintes, initialis� par le fichier de d�finition des chroniques


  /* ASSESSEURS  */

  // Mutateur, change la valeur d'�v�nement de la chronique
  void set_event(bool event){
    event_verify = event;
  }

  // Mutateur, change la valeur du nombre de validation de la chronique
  void set_valid(int nb){
    nb_validation = nb;
  }

  // Mutateur, ajoute une valeur dans les heures de validation de la chronique
  void set_h_valid(int heure){
    heure_validation.push_back(heure);
  }

  // Reinitialisateur, remet � 0 la valeur du nombre de validation
  void reset_valid(){
    nb_validation = 0;
  }

  // Reinitialisateur, remet � 0 le tableau des heures de validation
  void reset_h_valid(){
    heure_validation.clear();
  }

  // Reinitialisateur, remet au maximum la valeur des contraintes restantes � valider
  void reset_nb_contraintes(){
    nb_contraintes_restantes=nb_contraintes_total;
  }

  // Reinitialisateur, r�initialise tous les attributs
  void reinit_chronique_all(){
    nom="";
    event_verify=false;
    nb_validation=0;
    heure_validation.clear();
    nb_contraintes_restantes = nb_contraintes_total;
    contraintes.clear();
  }

public:

  /* CONSTRUCTEURS */

  // Constructeur simple
  chronique(){
    nom="";
    event_verify=false;
    nb_validation=0;
    heure_validation.clear();
    nb_contraintes_restantes = 0;
    nb_contraintes_total = 0;
    contraintes.clear();
  }

  // Constructeur �volu�, cr�� la chronique � partir des donn�es
  chronique(string label, int nb_contraintes, vector<contrainte> vect_contraintes){
    nom=label;
    event_verify=false;
    nb_validation=0;
    heure_validation.clear();
    nb_contraintes_restantes = nb_contraintes;
    nb_contraintes_total = nb_contraintes;
    contraintes = vect_contraintes;
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

  // Assesseur, ressort le tableau des heures de validation
  std::vector<int> get_h_valid(){
	return heure_validation;
  }

  // Assesseur, ressort l'heure de la derni�re validation
  int get_last_h_valid(){
	return (*heure_validation.end());
  }

  // Assesseur, ressort le tableau des contraintes
  std::vector<contrainte> get_contraintes(){
	return contraintes;
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
    if (nb_validation != 0) {
        cout<<"derniere validation = "<<heure_validation.back()<<endl;
    }
    cout<<"evenement detectable = "<<event_verify<<endl;
    cout<<"nombre de contraintes total = "<<nb_contraintes_total<<endl;
    cout<<"nombre de contraintes restantes = "<<nb_contraintes_restantes<<endl;
  }

  // Affiche les heures de validation de la chronique dans le terminal
  void afficher_heures_validation(){
    vector<int>::iterator it; // iterateur
    for (it = heure_validation.begin(); it != heure_validation.end() ; it++)
    {
        cout<<"validation � "<<(*it)<<endl;
    }
  }

  // Affiche le nombre de fois o� la chronique a �t� termin�e
  void afficher_nb_validation(){
    cout<<"nombre de validation = "<<nb_validation<<endl;
  }

  // Valide la chronique (affiche un message dans le terminal pour annoncer la validation de la chronique,
  // incr�mente nb_validation, met � jour heure_validation et passe nb_contraintes_restantes � nb_contraintes_total)
  void validation_chronique(){
    cout<<"la chronique "<<nom<<" a �t� valid�e"<<endl;
    set_valid(nb_validation+1);
    set_h_valid(HEURE_COURANTE);
    reset_nb_contraintes();
  }

};

/* FUNCTIONS */



#endif
