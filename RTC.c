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
 i2c_write(0x50);
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

void i2c_init(void)
{
 SCL=0;
 SDA=0;
}

void i2c_clk(void)
{
 SCL=1;
 SCL=0;
}

void i2c_ack(void)
{
 SDA=0;
 i2c_clk();
}

void i2c_nack(void)
{
 SDA=1;
 i2c_clk();
 SDA=0;
}

void i2c_start(void)
{
 SDA=1;
 SCL=1;
 SDA=0;
 SCL=0;
}

void i2c_stop(void)
{
 SCL=1;
 SDA=1;
 SCL=0;
 SDA=0;
}

void i2c_write(char data)
{
 char i;
 __bit v=1;
 while(v==1)
 {
  for(i=0;i<8;i++)
  {
   if(((data<<i)&(0x80))!=0x00)
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
  v=SDA;
  SCL=0;
  SDA=0;
 }
}

char i2c_read(void)
{
 char i;
 char data=0x00;
 SDA=1;
 for(i=0;i<8;i++)
 {
  SCL=1;
  if(SDA==1)
  {
   data=data|(0x01<<(7-i));
  }
  else
  {
  }
  SCL=0;
 }
 SDA=0;
 return data;
}
