#include "lm4f120h5qr.h"

#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

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
  SYSCTL_RCGCGPIO_R |= (1U << 5); /* Set Clock for GPIOF */
  SYSCTL_GPIOHBCTL_R |= (1U << 5); /* Enable AHB for GPIOF */
  GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN); /* Set pins 1,2 and 3 as outputs 0xEU*/
  GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);  /* Enable Digital 0xEU*/

  GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE; 
  
  while(1){
    // GPIO_PORTF_DATA_R |= LED_RED; /* GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R | LED_RED; -- read-modify-write sequence */
    // *((unsigned long volatile *)(0x40025000U + (LED_RED << 2))) = LED_RED; 
    //  *(GPIO_PORTF_DATA_BITS_R + LED_RED) = LED_RED;
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED; 
    
    int counter = 0;
    while(counter < 1000000)
        ++counter;
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED]= 0; /* GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R & ~LED_RED; */
    counter = 0;
    while(counter < 1000000)
        ++counter;
  }
  
  return 0;   
}
