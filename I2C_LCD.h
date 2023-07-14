#ifndef I2C_LCD_H
#define I2C_LCD_H

#include <I2C.h>

char BLED;

void i2c_port_write(char i2c_lcd_v)
{
  i2c_start();
  i2c_write(SID);
  i2c_write(i2c_lcd_v);
  i2c_stop();
}

void i2c_lcd_on()
{
 BLED=0x08;
 i2c_port_write(BLED);
}

void i2c_lcd_off()
{
 BLED=0x00;
 i2c_port_write(BLED);
}

char i2c_lcd_status_read()
{
 char i2c_lcd_r;
 i2c_port_write(0xF6|BLED);
 i2c_start();
 i2c_write(SID|0x01);
 i2c_lcd_r=i2c_read()&0xF0;
 i2c_nack();
 i2c_stop();
 i2c_port_write(0xF2|BLED);
 i2c_port_write(0xF6|BLED);
 i2c_port_write(0xF2|BLED);
 return i2c_lcd_r;
}

void i2c_lcd_busy()
{
 char i2c_lcd_b=0x80;
 i2c_port_write(0xF2|BLED);
 while(i2c_lcd_b==0x80)
 {
  i2c_lcd_b=i2c_lcd_status_read()&0x80;
 }
}

void i2c_lcd_cmd(char i2c_lcd_c)
{
 i2c_port_write((i2c_lcd_c&0xF0)|0x04|BLED);
 i2c_port_write((i2c_lcd_c&0xF0)|BLED);
 i2c_port_write((i2c_lcd_c<<4)|0x04|BLED);
 i2c_port_write((i2c_lcd_c<<4)|BLED);
 i2c_lcd_busy();
}

void i2c_lcd_data(char i2c_lcd_dat)
{
 i2c_port_write((i2c_lcd_dat&0xF0)|0x05|BLED);
 i2c_port_write((i2c_lcd_dat&0xF0)|0x01|BLED);
 i2c_port_write((i2c_lcd_dat<<4)|0x05|BLED);
 i2c_port_write((i2c_lcd_dat<<4)|0x01|BLED);
 i2c_lcd_busy();
}

void i2c_lcd_start()
{
 i2c_init();
 i2c_lcd_off();
 delay(1);
 i2c_port_write(0x24|BLED);
 i2c_port_write(0x20|BLED);
 i2c_lcd_busy();
 i2c_lcd_cmd(0x28);
}

void i2c_lcd_init()
{
 i2c_lcd_cmd(0x01);
 i2c_lcd_cmd(0x0C);
 i2c_lcd_cmd(0x06);
 i2c_lcd_cmd(0x80);
 i2c_lcd_on();
}

void i2c_lcd_print(char *i2c_lcd_pt)
{
 while(*i2c_lcd_pt!=0x00)
 {
  i2c_lcd_data(*i2c_lcd_pt);
  *i2c_lcd_pt++;
 }
}

void i2c_lcd_line(char i2c_lcd_line)
{
 i2c_lcd_cmd(0x80|((i2c_lcd_line-1)*0x40));
}

void i2c_lcd_pos(char i2c_lcd_x,char i2c_lcd_y)
{
 i2c_lcd_cmd(((i2c_lcd_x-1)*0x40)|0x80|(i2c_lcd_y-1));
}

#endif