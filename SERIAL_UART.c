#include <AT89S52.h>

char msg[20];

void read_serial();
void print_serial(char*);
  
void main()
{
 TR1=0;
 TMOD=(TMOD&0x0F)|0x20;
 TH1=0xFD;
 TL1=0xFD;
 SCON=0x50;
 PCON=(PCON&0x7F);
 TR1=1;
 while(1)
 {
  read_serial();
  print_serial("Message Received: \r\n");
  print_serial(msg);
  print_serial("\r\n");
   }
}

void print_serial(char* m)
{
 while(*m!='\0')
 {
  SBUF=*m;
  *m++;
  while(TI==0)
  {}
  TI=0;
 }
}

void read_serial(void)
{
 char i=0;
 RI=0;
 while(RI==0)
 {}
 RI=0;
 while(SBUF!='$')
 {
  msg[i]=SBUF;
  i++;
  while(RI==0)
  {}
  RI=0;
 }
 msg[i]='\0';
}
