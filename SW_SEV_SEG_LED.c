#include <AT89S52.h>
#define SEV_SEG P0
#define SW P1
const char code[11]={0xC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92, 0X82, 0XF8, 0X80, 0X90}; 
const char read_sw[9]={0xFE, 0XFD, 0XFB, 0XF7, 0XEF, 0XDF, 0XBF, 0X7F};
void main()
{
 SW=0xFF;
 SEV_SEG=0xFF;
 while(1)
 {
  char s,c;
  s=SW;
  for(c=0;c<8;c++)
  {
   if(s==read_sw[c])
   {
    break;
   }
   else
   {
   }
  }
  if(c!=8)
  {
   SEV_SEG=code[c];
  }
  else
  {
   SEV_SEG=0xFF;
  } 
 }
}
