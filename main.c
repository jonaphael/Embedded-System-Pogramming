#include "lm4f120h5qr.h"
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
unsigned fact(unsigned n);


int main()
{  
  unsigned volatile x;
  
  x = fact(0U);
  x = 2U + 3U * fact(1U);
  (void)fact(5U);
    
  SYSCTL_RCGCGPIO_R |= (1U << 5); /* Set Clock for GPIOF */
  SYSCTL_GPIOHBCTL_R |= (1U << 5); /* Enable AHB for GPIOF */
  GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN); /* Set pins 1,2 and 3 as outputs 0xEU*/
  GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);  /* Enable Digital 0xEU*/
  
    while(1){
    GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = LED_BLUE; 
    delay(DELAY_VALUE);
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = 0; 
    delay(DELAY_VALUE);
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = LED_RED; 
    delay(DELAY_VALUE);
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED]= 0;
    delay(DELAY_VALUE);
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN]= LED_GREEN;
    delay(DELAY_VALUE);
    
    GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN]= 0;
    delay(DELAY_VALUE);
  }
  
  return 0;   
}

/*!
 * @brief Calculate factorial of n
 * 
 * @param n The number that the fatorial
 *          will be calculated
 *
 * @ return the n! (fatorial)
 */
unsigned fact(unsigned n)
{
    if(n == 0U)
      return 1U;
    
    return n * fact(n - 1U);
}