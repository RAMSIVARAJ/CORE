#include <AT89S52.h>	/* include header for AT89S52 */ 
#define LED P2_4		/* LED connected at port pin P2.4*/
#define ON 0
#define OFF 1

void wait(int);

void main()
{
  char n;
  LED=OFF;  /* Turn OFF the LED */
  for(n=0;n<10;n++)
  {
   LED=ON;
   wait(1);
   LED=OFF;
   wait(1);
  }
  while(1)  /* Execute below lines in super loop */
  {
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
