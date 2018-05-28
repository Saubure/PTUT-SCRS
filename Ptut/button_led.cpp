#include <mraa.hpp>
#include <mraa/aio.h>
#include <mraa/gpio.h>

 mraa_gpio_context m_gpio_led;
 mraa_gpio_context m_gpio_boutton; 
int button_state;

void init_led(void){
  m_gpio_led = mraa_gpio_init(2);
  mraa_gpio_dir(m_gpio_led, MRAA_GPIO_OUT);

}

void* allumer_led(void){

  mraa_gpio_write(m_gpio_led,1);
return NULL;
}

void* eteindre_led(void){

  mraa_gpio_write(m_gpio_led,0);
	return NULL;
}

int main(){
 
 
  mraa_init();
  init_led();
  m_gpio_led = mraa_gpio_init(2);
  mraa_gpio_dir(m_gpio_led, MRAA_GPIO_OUT);
  m_gpio_boutton = mraa_gpio_init(6);
  mraa_gpio_dir(m_gpio_boutton, MRAA_GPIO_IN);
  mraa_gpio_isr(m_gpio_boutton,MRAA_GPIO_EDGE_RISING,allumer_led(),NULL);
  mraa_gpio_isr(m_gpio_boutton,MRAA_GPIO_EDGE_FALLING,eteindre_led(),NULL);

  while(1){
  

  }
}
