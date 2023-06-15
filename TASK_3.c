#include <AT89S52.h>	/* include header for AT89S52 */ 
#define LED1 P2_4	
#define LED2 P2_5
#define ON 0
#define OFF 1

void wait(int);

void main()
{
  LED1=OFF;
  LED2=OFF;
  while(1)  /* Execute below lines in super loop */
  {
   LED1=ON;
   LED2=OFF;
   wait(1);
   LED1=OFF;
   LED2=ON;
   wait(1);
  }
}

void wait(int del)  /* this program generate delay in multiples of 100us */
{
 int c1,c2;  /* Inner and outer loop Count variables */
 for(c1=0; c1<del; c1++)	/* Outer loop runs for "del" times */
 {
  for(c2=0; c2<15; c2++)  /* Inner loop runs for 15 times */
  {
  }
 }
}
