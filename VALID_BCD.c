#include <At89S52.h>
#define SW P0
#define LED P1_0
void main()
{
  char status,h,l;
  SW=0xFF;
  LED=1;
  while(1)
  {
   status=~SW;
   l=status&0x0F;
   h=status>>4;
   if(l<=9 && h<=9)
   {
    LED=0;
   }
   else
   {
    LED=1;
   }
  }
}
