#include <AT89S52.h>
#define SCL P0_0
#define SDA P0_1

void i2c_init(void);
void i2c_clk(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(char);
char i2c_read(void);
void i2c_ack(void);
void i2c_nack(void);

void main()
{
 i2c_init();
 i2c_start();
 i2c_write(0xD0);
 i2c_write(0x00);
 i2c_write(0x55);
 i2c_stop();
 while(1)
 {
  char d;
  i2c_start();
  i2c_write(0xD0);
  i2c_write(0x00);
  i2c_start();
  i2c_write(0xD1);
  d=i2c_read();
  i2c_nack();
  i2c_stop();
  P2=d;
 }
}

void i2c_init()
{
 SCL=0;
 SDA=0;
}

void i2c_clk()
{
 SCL=1;
 SCL=0;
}

void i2c_ack()
{
 SDA=0;
 i2c_clk();
}

void i2c_nack()
{
 SDA=1;
 i2c_clk();
 SDA=0;
}

void i2c_start()
{
 SDA=1;
 SCL=1;
 SDA=0;
 SCL=0;
}

void i2c_stop()
{
 SCL=1;
 SDA=1;
 SCL=0;
 SDA=0;
}

void i2c_write(char i2c_b)
{
 char i2c_c;
 __bit i2c_chk=1;
 while(i2c_chk==1)
 {
  for(i2c_c=0;i2c_c<8;i2c_c++)
  {
   if(((i2c_b<<i2c_c)&(0x80))!=0x00)
   {
    SDA=1;
   }
   else
   {
    SDA=0;
   }
   i2c_clk();
  }
  SDA=1;
  SCL=1;
  i2c_chk=SDA;
  SCL=0;
  SDA=0;
 }
}

char i2c_read(void)
{
 char i2c_r=0x00;
 char i2c_n;
 SDA=1;
 for(i2c_n=0;i2c_n<8;i2c_n++)
 {
  SCL=1;
  if(SDA==1)
  {
   i2c_r=i2c_r|(0x01<<(7-i2c_n));
  }
  else
  {
  }
  SCL=0;
 }
 SDA=0;
 return i2c_r;
}
