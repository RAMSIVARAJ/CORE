#include <AT89S52.h>	/* include header for AT89S52 */ 
#define LED P2_4		/* LED connected at port pin P2.4*/
#define ON 0			/* logic 0 active */
#define OFF 1		/* logic 1 inactive */
#define SW P3_3  	/* Switch connected at port pin P3.3 */
#define INPUT 1	/* To configure port pin as Input "1" logic must be written on port pin */

void wait(int);

void main()
{
  __bit status;  /*initialize a bit variable */
  LED=OFF;  /* Turn OFF the LED */
  SW=INPUT;  /* Configure port pin connected to switch as Input */
  while(1)  /* Execute below lines in super loop */
  {
   status=SW;
   if(status==0)
   {
    LED=!LED;
    wait(1);
   }
   else
   {
    LED=OFF;
   }
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
