#include "Periph.hpp"

int date = 0 ;
int heure = 7 ;
char buffer[50];
int m_bus=0;
int m_lcd_control_address=0x3E;
int m_rgb_control_address=0x62;
mraa_gpio_context m_gpio_led;   
uint32_t compteur=0;
mraa_gpio_context m_gpio_boutton;
mraa_aio_context m_aio_potentiometre ;
mraa_gpio_context m_gpio_switch ;
mraa_gpio_context m_gpio_reflecteur_sdb ;
mraa_gpio_context m_gpio_reflecteur_chambre ;
mraa_gpio_context m_gpio_reflecteur_entrance ;
extern int pin_reflecteur_sdb  ;
extern int pin_reflecteur_chambre  ;
extern int pin_reflecteur_entrance ;

// positionnement ligne 1 colonne 2
int row=0, column=5;
int row_addr[] = { 0x80, 0xc0, 0x14, 0x54};
uint8_t offset = ((column) + row_addr[row]);

mraa_i2c_context m_i2c_lcd_control, m_i2c_lcd_rgb;

mraa_result_t i2cData (mraa_i2c_context ctx, uint8_t value) {
  mraa_result_t error = MRAA_SUCCESS;
    
  uint8_t data[2] = { LCD_DATA, value };
  error = mraa_i2c_address (ctx, m_lcd_control_address);
  error = mraa_i2c_write (ctx, data, 2);
    
  return error;
}

mraa_result_t i2Cmd (mraa_i2c_context ctx, uint8_t value) {
  
  mraa_result_t error = MRAA_SUCCESS;
    
  uint8_t data[2] = { LCD_CMD, value };
  error = mraa_i2c_address (ctx, m_lcd_control_address);
  error = mraa_i2c_write (ctx, data, 2);
    
  return error;
}

mraa_result_t i2cReg (mraa_i2c_context ctx, int deviceAdress, int addr, uint8_t value) {
  mraa_result_t error = MRAA_SUCCESS;
    
  uint8_t data[2] = { addr, (uint8_t)value };
  error = mraa_i2c_address (ctx, deviceAdress);
  error = mraa_i2c_write (ctx, data, 2);
    
  return error;
}

void init_LCD(){
    
  // initialisation
  m_i2c_lcd_control = mraa_i2c_init(m_bus);
  mraa_i2c_address(m_i2c_lcd_control, m_lcd_control_address);
    
  m_i2c_lcd_rgb = mraa_i2c_init(m_bus);
  mraa_i2c_address(m_i2c_lcd_rgb, m_rgb_control_address);
  usleep(50000);
  i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
  usleep(4500);
  i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
  usleep(4500);
  i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
  usleep(4500);
  i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
  i2Cmd (m_i2c_lcd_control, LCD_DISPLAYCONTROL | LCD_DISPLAYON);
  i2Cmd (m_i2c_lcd_control, LCD_CLEARDISPLAY);
  usleep(4500);
  i2Cmd (m_i2c_lcd_control, LCD_ENTRYMODESET |
	 LCD_ENTRYLEFT |
	 LCD_ENTRYSHIFTDECREMENT);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0, 0);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 1, 0);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x08, 0xAA);
    
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x04, 255);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x03, 255);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x02, 255);

  i2Cmd(m_i2c_lcd_control, offset);
}

void afficher_LCD(){  
           
  sprintf(buffer,"%d : %d",heure,date);
  string msg = buffer ;
 
  usleep(1000);
  i2Cmd(m_i2c_lcd_control, offset);
  for (std::string::size_type i = 0; i < msg.size(); ++i) {
    i2cData (m_i2c_lcd_control, msg[i]);
  }
}

void init_led (int pin) {
 m_gpio_led = mraa_gpio_init(pin);
 mraa_gpio_dir(m_gpio_led, MRAA_GPIO_OUT);

}

void allumer_led (int pin){

  // alummage 
  mraa_gpio_write(m_gpio_led, 1);

}

void eteindre_led (int pin){

  mraa_gpio_write(m_gpio_led, 0);

}

void init_boutton(int pin) {

  m_gpio_boutton = mraa_gpio_init(pin) ;
  mraa_gpio_dir(m_gpio_boutton,MRAA_GPIO_IN);

}

int get_boutton (int pin){
    int button_state ;

  button_state = mraa_gpio_read(m_gpio_boutton);

  return button_state ;
}

void init_potentiometre(int pin){

  m_aio_potentiometre = mraa_aio_init(pin) ;

}

double get_potentiometre(int pin){
  double potentiometre ;
  int int_potentiometre ;

  int_potentiometre = mraa_aio_read(m_aio_potentiometre) ;
  potentiometre = (double) (int_potentiometre) / 1024.0 * 50.0 ;

  return potentiometre ;

}

void init_switch(int pin){

  m_gpio_switch = mraa_gpio_init(pin) ;
  mraa_gpio_dir(m_gpio_switch,MRAA_GPIO_IN);

}

int get_switch (int pin){
    int switch_state ;

  switch_state = mraa_gpio_read(m_gpio_switch);

  return switch_state ;
}

void init_reflecteur(){

  m_gpio_reflecteur_sdb = mraa_gpio_init(pin_reflecteur_sdb) ;
  m_gpio_reflecteur_entrance = mraa_gpio_init(pin_reflecteur_entrance);
  m_gpio_reflecteur_chambre = mraa_gpio_init(pin_reflecteur_chambre);
  mraa_gpio_dir(m_gpio_reflecteur_entrance,MRAA_GPIO_IN);
  mraa_gpio_dir(m_gpio_reflecteur_sdb,MRAA_GPIO_IN);
  mraa_gpio_dir(m_gpio_reflecteur_chambre,MRAA_GPIO_IN);
  

}

int get_reflecteur (mraa_gpio_context lieu){
    int reflecteur_state ;

  reflecteur_state = mraa_gpio_read(lieu);

  return reflecteur_state ;
}




