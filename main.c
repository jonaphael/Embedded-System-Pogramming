#include "lm4f120h5qr.h"

/*************************************************************************************
// Run-Mode Clock Gating Regsiter
#define RCGCGPIO (*((unsigned int *) 0x400FE608U))

#define GPIOF_BASE 0x40025000U // GPIOF BASE_ADDRESS
#define GPIOF_DIR  (*((unsigned int *) (GPIOF_BASE + 0x400U))) // GPIOF_PIN_DIRECTION
#define GPIOF_DEN  (*((unsigned int *) (GPIOF_BASE + 0x51CU))) // GPIOF DIGITAL_ENABLE
#define GPIOF_DATA (*((unsigned int *) (GPIOF_BASE + 0x3FCU))) // GPIOF DATA REGISTER
**************************************************************************************/
int main()
{  
  SYSCTL_RCGCGPIO_R = 0x20U; /* Set Clock for GPIOF */
  GPIO_PORTF_DIR_R = 0xEU; /* Set pins 1,2 and 3 as outputs */
  GPIO_PORTF_DEN_R= 0xEU;  /* Enable Digital*/

  /* LED_R (RED)*/
  while(1){
    GPIO_PORTF_DATA_R = 0x2U;
    
    int counter = 0;
    while(counter < 1000000)
        ++counter;
    
    GPIO_PORTF_DATA_R = 0x0U;
    counter = 0;
    while(counter < 1000000)
        ++counter;
  }
  
  return 0;   
}
