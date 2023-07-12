#include <AT89S52.h>
#define DATA P0
#define DIGIT P1
const char code[11]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void wait(int);
void display(int);

void main()
{
 DATA=0xFF;
 DIGIT=0x0F;
 while(1)
 {
  display(5279);
 }
}

void wait(int c)
{
 int i;
 for(i=0;i<c;i++)
 {
 }
}

void display(int val)
{
 char th,h,t,o;
 th=(val/1000);
 h=(val%1000)/100;
 t=(val%100)/10;
 o=val%10;
 DATA=code[th];
  DIGIT=0x07;
  DIGIT=0x0F;

  DATA=code[h];
  DIGIT=0x0B;
  DIGIT=0x0F;

  DATA=code[t];
  DIGIT=0x0D;
  DIGIT=0x0F;

  DATA=code[o];
  DIGIT=0x0E;
  DIGIT=0x0F;
}
