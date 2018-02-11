int main()
{  
  /* Clock Gating offset 0x608U
   * Set bit-5 
   * 0010 0000  = 0x20
   */
  *((unsigned int *) 0x400FE608U) = 0x20U;
  
  
  /* Pin Direcrion Register (Digital Output) 
   * offset 0x400U
   * Set bit-1, bit-2 and bit-3
   */
  *((unsigned int *) 0x40025400U) = 0xEU;
  
  /* Digital Enabled
   * offset 0x51CU
   * Set bit-1, bit-2 and bit-3
   */
  *((unsigned int *) 0x4002551CU) = 0xEU;
  
  /* Blink */
  
  /* LED_R (RED)*/
  while(1){
    *((unsigned int *) 0x400253FCU) = 0x2U;
    
    /* DELAY */
    int counter = 0;
    while(counter < 1000000)
        ++counter;
    
    *((unsigned int *) 0x400253FCU) = 0x0U;
    counter = 0;
    while(counter < 1000000)
        ++counter;
  }
  
  return 0;   
}
