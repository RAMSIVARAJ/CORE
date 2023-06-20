#include <AT89S52.h>
#define SW1 P3_0
#define SW2 P3_1
#define LED P2_0
#define ON 0
#define OFF 1
#define INPUT 1

void main()
{
 SW1=INPUT;
 SW2=INPUT;
 LED=OFF;
 while(1)
 {
  __bit a,b;
  a=SW1;
  b=SW2;
  if(a==ON && b==ON)
  {
   LED=ON;
  }
  else
  {
   LED=OFF;
  }
 }
}
