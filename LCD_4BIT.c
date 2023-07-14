#include <AT89S52.h>
#define DATA P2
#define RS P0_7
#define RW P0_6
#define EN P0_5

void lcd_start(void);
void lcd_init(void);
void lcd_busy(void);
void lcd_data(char);
void lcd_cmd(char);
void lcd_display(char*);


void main()
{
 lcd_init();
 lcd_display("Good Night");
 /*lcd_display("LCD Working");*/
 while(1)
 {
 }
}

void lcd_init(void)
{
 EN=0;
 lcd_start();
 lcd_cmd(0x01);
 lcd_cmd(0x0C);
 lcd_cmd(0x06);
 lcd_cmd(0x80);
}

void lcd_busy(void)
{
 char b=0x80;
 DATA=0xF0;
 RS=0;
 RW=1;
 while(b!=0x00)
 {
  EN=1;
  b=DATA;
  EN=0;
  EN=1;
  EN=0;
  b=b&0x80;
 }
}

void lcd_data(char d)
{
 char d1,d0;
 RS=1;
 RW=0;
 DATA=(d&0xF0);
 EN=1;
 EN=0;
 DATA=(d<<4);
 EN=1;
 EN=0;
 lcd_busy();
}


void lcd_cmd(char c)
{
 RS=0;
 RW=0;
 DATA=(c&0xF0);
 EN=1;
 EN=0;
 DATA=(c<<4);
 EN=1;
 EN=0;
 lcd_busy();
}

void lcd_display(char*b)
{
 while(*b!=0x00)
 {
  lcd_data(*b);
  *b++;
 }
}

void lcd_start(void)
{
 EN=0;
 lcd_busy();
 RS=0;
 RW=0;
 DATA=0x30;
 EN=1;
 EN=0;
 lcd_busy();
 DATA=0x20;
 EN=1;
 EN=0;
 lcd_busy();
 lcd_cmd(0x28);
 P1_0=0;
}
