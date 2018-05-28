#include <mraa/i2c.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

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


using namespace std;

int m_bus=0;
int m_lcd_control_address=0x3E;
int m_rgb_control_address=0x62;

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


int main(){
  int date = 0 ;
    int heure=7 ;
    char buffer[50];
  
    mraa_i2c_context m_i2c_lcd_control, m_i2c_lcd_rgb;
    
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


    // positionnement ligne 1 colonne 2
      int row=0, column=5;
      int row_addr[] = { 0x80, 0xc0, 0x14, 0x54};
      uint8_t offset = ((column) + row_addr[row]);
      i2Cmd(m_i2c_lcd_control, offset);
      

    while (1) {
      // écriture d'un texte

      date ++;
      if (date==60) {
	heure ++;
	date = 0;
	if (heure ==24) {
	  heure = 0 ;
	}
      }
           
      sprintf(buffer,"%d : %d",heure,date);
      string msg = buffer ;
      usleep(1000);
      i2Cmd(m_i2c_lcd_control, offset);
      for (std::string::size_type i = 0; i < msg.size(); ++i) {
        i2cData (m_i2c_lcd_control, msg[i]);
      }
      sleep(1);
      i2Cmd(m_i2c_lcd_control, LCD_CLEARDISPLAY);
    
   

    }
    // fin
    sleep(3);
    mraa_i2c_stop(m_i2c_lcd_control);
    return 0;
}
