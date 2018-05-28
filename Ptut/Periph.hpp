#ifndef PERIPH_H
#define PERIPH_H

#include <mraa.hpp>
#include <mraa/aio.h>
#include <mraa/gpio.h>
#include <mraa/i2c.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std ;
///////////////////////////////////////////////////////////    DEFINES

#define LCD_CLEARDISPLAY 0x01
#define LCD_ENTRYMODESET 0x04
#define LCD_FUNCTIONSET 0x20
#define LCD_DATA 0x40
#define LCD_CMD 0x80
#define LCD_DISPLAYCONTROL 0x08
#define LCD_DISPLAYON 0x04

// flags for display entry mode
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_2LINE 0x08

extern int date;
extern int heure ;
extern char buffer[50];
extern int m_bus;
extern int m_lcd_control_address;
extern int m_rgb_control_address;
extern mraa_gpio_context m_gpio_led;   
extern uint32_t compteur;

// positionnement ligne 1 colonne 2
extern int row, column;
extern int row_addr[];
extern uint8_t offset;

extern mraa_i2c_context m_i2c_lcd_control, m_i2c_lcd_rgb;
extern mraa_gpio_context m_gpio_boutton;
extern mraa_aio_context m_aio_potentiometre ;
extern mraa_gpio_context m_gpio_switch ;
extern mraa_gpio_context m_gpio_reflecteur_sdb ;
extern mraa_gpio_context m_gpio_reflecteur_chambre ;
extern mraa_gpio_context m_gpio_reflecteur_entrance ;





mraa_result_t i2cData (mraa_i2c_context ctx, uint8_t value);

mraa_result_t i2Cmd (mraa_i2c_context ctx, uint8_t value)  ;

mraa_result_t i2cReg (mraa_i2c_context ctx, int deviceAdress, int addr, uint8_t value) ;

void init_LCD();

void afficher_LCD();

void init_led (int pin);
void allumer_led (int pin);
void eteindre_led (int pin);
int get_boutton (int pin);
double get_potentiometre(int pin);
void init_boutton(int pin);
void init_potentiometre(int pin);
void init_switch(int pin);
int get_switch (int pin);
void init_reflecteur();
int get_reflecteur (mraa_gpio_context lieu);


#endif
