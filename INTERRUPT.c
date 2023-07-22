#include <AT89S52.h>
#define LED1 P0_0
#define LED2 P0_1
#define SW P3_2
#define SEG P1
const char code[11]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void wait(char);
char count=0;

void main()
{
 SEG=0xFF;
 IT0=1;
 EX0=1;
 EA=1;
 while(1)
 {
  LED1=0;
  wait(10);
  LED1=1;
  wait(10); 
 }
}

void wait(char c)
{
 char i;
 for(i=0;i<c;i++)
 {
 }
}

void led_toggle(void) __interrupt (0)
{
  IE0=0;
  LED2=!LED2;
  SEG=code[count];
  count++;
  if(count>9)
  {
   count=0;
  }
  else
  {}
}
