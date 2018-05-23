#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/* CLASSES */

// Event unitaire
class event {

private:

  /* ATTRIBUTS */

  string label; //initialis� par le fichier de d�finition des events
  bool occured; // initialis� � false, indique si l��v�nement est arriv� au moins une fois
  int nb_occurence; // initialis� � 0, indique le nombre d�apparition de l��v�nement dans la s�quence
  std::vector<int> date; // tableau des heures d'apparition de l'�v�nement

  /* ASSESSEURS  */

  // Mutateur, change la valeur du nombre de validation de la chronique
  void set_occurence(int nb){
    nb_occurence = nb;
  }

  // Mutateur, ajoute une valeur dans les heures d'apparition de l'event
  void set_h_event(int heure){
    date.push_back(heure);
  }

  // Reinitialisateur, remet � 0 le tableau des heures de validation
  void reset_h_event(){
    date.clear();
  }

  // Reinitialisateur, r�initialise tous les attributs
  void reinit_event_all(){
    label="";
    occured=false;
    nb_occurence=0;
    date.clear();
  }

public:

  /* CONSTRUCTEURS */

  // Constructeur simple
  event(){
    label="";
    occured=false;
    nb_occurence=0;
    date.clear();
  }

  // Constructeur �volu�, cr�� l'event � partir des donn�es
  event(string nom){
    label=nom;
    occured=false;
    nb_occurence=0;
    date.clear();
  }

  /* OPERATEURS */

  event operator =(const event &e){
    label =e.label;
    occured=e.occured;
    nb_occurence=e.nb_occurence;
    date=date;
    return *this;
  }

  /* ASSESSEURS */

  // Assesseur, ressort le nom de l'event
  string get_label(){
	return label;
  }

  // Assesseur, ressort l'�tat de l'event (occured ou non)
  bool get_occured(){
	return occured;
  }

  // Assesseur, ressort le nombre d'occurence
  int get_nb_occurence(){
	return nb_occurence;
  }

  // Assesseur, ressort le tableau des heures d'occurence
  std::vector<int> get_h_occur(){
	return date;
  }

  // Assesseur, ressort l'heure de la derni�re occurence
  int get_last_h_occur(){
	return (*date.end());
  }

  // Mutateur, change le label de l'�l�ment
  void set_label(string name){
    label = name;
  }

  /* METHODES */

  // Affiche certains �l�ments dans la console
  void afficher(){
    cout<<"nom = "<<label<<endl;
    cout<<"event occured = "<<occured<<endl;
    if (occured) {
        cout<<"nombre d'occurence = "<<nb_occurence<<endl;
        cout<<"derniere validation = "<<date.back()<<endl;
    }
  }

  // Affiche les heures d'occurence de l'event dans le terminal
  void afficher_heures_occur(){
    vector<int>::iterator it; // iterateur
    for (it = date.begin(); it != date.end() ; it++)
    {
        cout<<"occurence � "<<(*it)<<endl;
    }
  }

  // Affiche le nombre de fois o� l'event est arriv�
  void afficher_nb_occurence(){
    cout<<"nombre d'occurence = "<<nb_occurence<<endl;
  }


};

/* FUNCTIONS */


#endif // EVENT_H_INCLUDED
