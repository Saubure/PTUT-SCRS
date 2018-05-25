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

public:

 /* CONSTRUCTEURS */

  // Constructeur simple
  event();

  // Constructeur �volu�, cr�� l'event � partir des donn�es
  event(string nom);

  /* OPERATEURS */

  event operator =(const event &e);

  /* ASSESSEURS */

  // Assesseur, ressort le nom de l'event
  string get_label();

  // Assesseur, ressort l'�tat de l'event (occured ou non)
  bool get_occured();

  // Assesseur, ressort le nombre d'occurence
  int get_nb_occurence();

  // Assesseur, ressort le tableau des heures d'occurence
  std::vector<int> get_h_occur();

  // Assesseur, ressort l'heure de la derni�re occurence
  int get_last_h_occur();

  // Mutateur, change le label de l'�l�ment
  void set_label(string name);

  // Mutateur, change la valeur du nombre de validation de la chronique
  void set_occurence(int nb);

  // Mutateur, change la valeur du booleen occured
  void set_occured(bool occur);

  // Mutateur, ajoute une valeur dans les heures d'apparition de l'event
  void set_h_event(int heure);

    // Reinitialisateur, remet � 0 le tableau des heures de validation
  void reset_h_event();

  // Reinitialisateur, r�initialise tous les attributs
  void reinit_event_all();

  /* METHODES */

  // Affiche certains �l�ments dans la console
  void afficher();

  // Affiche les heures d'occurence de l'event dans le terminal
  void afficher_heures_occur();

  // Affiche le nombre de fois o� l'event est arriv�
  void afficher_nb_occurence();


};

/* FUNCTIONS */


#endif // EVENT_H_INCLUDED
