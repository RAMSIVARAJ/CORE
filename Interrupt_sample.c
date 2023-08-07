#include <AT89S52.h>

#define LED1 P0_0 /* main LED to blink*/
#define LED2 P0_1 /* Interrupt LED toggle */

void wait(int);

void main()
{
 IT0=1;
 IE0=0;
 EX0=1;
 EA=1;
 while(1)
 {
  LED1=!LED1;
  wait(5);
 }
}

void wait(int d)
{
 int i;
 for(i=0;i<d;i++)
 {}
}

void service(void) __interrupt(0)
{
 IE0=0;
 LED2=!LED2;
}
