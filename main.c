#include <stdint.h>
#include "tm4c_cmsis.h"
#include "delay.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)
#define DELAY_VALUE (1000000)

/*************************************************************************************
// Run-Mode Clock Gating Register
#define RCGCGPIO (*((unsigned int *) 0x400FE608U))

#define GPIOF_BASE 0x40025000U // GPIOF BASE_ADDRESS
#define GPIOF_DIR  (*((unsigned int *) (GPIOF_BASE + 0x400U))) // GPIOF_PIN_DIRECTION
#define GPIOF_DEN  (*((unsigned int *) (GPIOF_BASE + 0x51CU))) // GPIOF DIGITAL_ENABLE
#define GPIOF_DATA (*((unsigned int *) (GPIOF_BASE + 0x3FCU))) // GPIOF DATA REGISTER
**************************************************************************************/


int main()
{     
  SYSCTL->RCGC2 |= (1U << 5); /* Set Clock for GPIOF */
  SYSCTL->GPIOHSCTL |= (1U << 5); /* Enable AHB for GPIOF */
  GPIOF_HS->DIR |= (LED_RED | LED_BLUE | LED_GREEN); /* Set pins 1,2 and 3 as outputs 0xEU*/
  GPIOF_HS->DEN |= (LED_RED | LED_BLUE | LED_GREEN);  /* Enable Digital 0xEU*/
  
  while(1){
    
    uint32_t x = 500000;
    
    GPIOF_HS->DATA_Bits[LED_BLUE] = LED_BLUE; 
    delay(x);
    
    GPIOF_HS->DATA_Bits[LED_BLUE] =  0; 
    delay(x);
    
    GPIOF_HS->DATA_Bits[LED_RED] = LED_RED; 
    delay(x);
    
    GPIOF_HS->DATA_Bits[LED_RED]= 0;
    delay(x);
    
    GPIOF_HS->DATA_Bits[LED_GREEN]= LED_GREEN;
    delay(x);
    
    GPIOF_HS->DATA_Bits[LED_GREEN]= 0;
    delay(x);
  }
  
 // return 0;   
}