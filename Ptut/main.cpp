////////////////////////////////////////////////////////////   INCLUDES 

#include "Periph.hpp"

using namespace std ;

///////////////////////////////////////////////////////////   VARIABLES GLOBALES

int pin_led = 2 ;
int pin_boutton = 6 ;
int pin_potentiometre = 1 ;
int pin_switch = 4 ;
int pin_reflecteur_sdb = 3 ;
int pin_reflecteur_chambre = 7 ;
int pin_reflecteur_entrance = 8 ;

ofstream out("out.txt");
extern uint32_t compteur;
extern int heure ;
bool boutton_appuye ;
bool temp_30 ;
bool temp_15 ;
bool heure_22 ;
bool switch_state ;
bool reflecteur_chambre_int ;
bool reflecteur_entrance_int ;
bool reflecteur_sdb_int ;
int date_evt = 0;
int date_entree = 0 ;

int main (void) {
  
double valeur_potentiometre ;
int valeur_boutton ;
 int reflecteur_sdb;
 int reflecteur_entrance;
 int reflecteur_chambre;
 int etat_switch ;
  
  mraa_init();
  init_LCD();
  init_boutton(pin_boutton);
  init_potentiometre(pin_potentiometre);
  init_led(pin_led) ;
  init_switch(pin_switch) ;
  init_reflecteur();
  
  cout << "InitOK\n";
  
  // simulation entree personne
  out << "(" << "Badge_Personne" << ";" << date_evt << ")" <<endl;
  //  out << "(" << "FranchissementAppt" << ";" << date_evt << ")" <<endl;
  
  while(1){

    valeur_potentiometre = get_potentiometre(pin_potentiometre) ;
    valeur_boutton = get_boutton(pin_boutton) ;
    etat_switch = get_switch(pin_switch) ;
    reflecteur_entrance = get_reflecteur(m_gpio_reflecteur_entrance);
    reflecteur_chambre = get_reflecteur(m_gpio_reflecteur_chambre);
    reflecteur_sdb = get_reflecteur(m_gpio_reflecteur_sdb);

    if(!reflecteur_sdb){
      if (reflecteur_sdb_int == 0 ){
	out << "(" << "FranchissementSDB" << ";" << date_evt << ")" <<endl;
	reflecteur_sdb_int =1;
	date_entree= compteur;}
      
    }else if (reflecteur_sdb_int == 1 && (compteur-date_entree > 1500)){
      reflecteur_sdb_int = 0 ;
    }

    if(!reflecteur_chambre){
      if (reflecteur_chambre_int == 0 ){
	out << "(" << "FranchissementChb" << ";" << date_evt << ")" <<endl;
	reflecteur_chambre_int =1;
      	date_entree= compteur;}

    }else if (reflecteur_chambre_int == 1 && (compteur-date_entree > 1500)) {
      reflecteur_chambre_int = 0 ;
    }
    
    if(!reflecteur_entrance){
      if (reflecteur_entrance_int == 0 ){
	out << "(" << "FranchissementAppt" << ";" << date_evt << ")" <<endl;
	reflecteur_entrance_int =1;
      	date_entree= compteur;}

    }else if  (reflecteur_entrance_int == 1 && (compteur-date_entree > 1500)) {
      reflecteur_entrance_int = 0 ;
    }
    
    if(valeur_boutton){
      if (boutton_appuye == 0 ){
	out << "(" << "Appui" << ";" << date_evt << ")" <<endl;
	boutton_appuye =1;}
    }else {
      boutton_appuye = 0 ;
    }

	  //On peut aussi rajouter un switch si le besoin s'en fait sentir
    /* if(etat_switch){
      if (switch_state == 0 ){
	out << "(" << "Switch" << ";" << date_evt << ")" <<endl;
	switch_state =1;}
    }else {
      switch_state = 0 ;

      }*/

    if (heure >= 22){
      if (heure_22 == 0 ){
	out << "(" << "Apres22_heures" << ";" << date_evt << ")" <<endl;
	heure_22 = 1; }
    }else {
      heure_22  = 0 ;
    }

    if ((valeur_potentiometre) < 15.0){
      if (temp_15 == 0 ){

	out << "(" << "Temp_15" << ";" << date_evt << ")" <<endl;
	temp_15 =1;}
    }else if (temp_15 && valeur_potentiometre > 15.5)  {
      temp_15 = 0 ;
    }

    if (valeur_potentiometre >30.0){
      if (temp_30 == 0 ){

	out << "(" << "Temp_30" << ";" << date_evt << ")" <<endl;
	temp_30 =1;}
    }else if (temp_30 && valeur_potentiometre < 29.5){
      temp_30 = 0 ;
    }
   
    sleep(0.1);
 
      compteur ++; // compteur en *10 ms reel
    if ((compteur%4000) == 0){
      date ++;// date en s reel , utilisé comme minute maquette
      date_evt ++ ;
     i2Cmd(m_i2c_lcd_control, LCD_CLEARDISPLAY);
     afficher_LCD();
     cout<< "potentiometre = " << valeur_potentiometre<<endl ;
	    
      if (date ==60) {
	heure ++; // heure en m reelle, utilise comme heure maquette 
        date = 0 ;
	if (heure ==24) {
	  heure = 0 ;
	}	
      }      
      }
  }
  // fin
  sleep(3);
}

