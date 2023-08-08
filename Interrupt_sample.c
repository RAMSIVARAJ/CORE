#include <AT89S52.h>

#define LED1 P0_0 /* main LED to blink*/
#define LED2 P0_1 /* Interrupt LED toggle */

void wait(int);

void main()
{
 IT1=1;
 IE1=0;
 EX1=1;
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

void service(void) __interrupt(2)
{
 LED2=!LED2;
}
