#include <AT89S52.h>

void main()

{
 P0=0xFF;
 while(1)
 {
  char a;
  a=P0;
  P0=(a<<4)|0x0F;
 }
}
