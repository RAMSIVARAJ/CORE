#include <AT89S52.h>

void wait(int);

void main()
{
 char data=0xAA;
 while(1)
 {
  P0=data;
  wait(1);
  P0=(data<<1)|(data>>7);
  wait(1);
 }
}


void wait(int del)  /* this program generate delay in multiples of 100us */
{
 int c1,c2;  /* Inner and outer loop Count variables */
 for(c1=0; c1<del; c1++)	/* Outer loop runs for "del" times */
 {
  for(c2=0; c2<50; c2++)  /* Inner loop runs for 15 times */
  {
  }
 }
}
