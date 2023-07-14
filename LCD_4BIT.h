#ifndef LCD_4BIT_H
#define LCD_4BIT_H

void port_write(char lcd_b)
{
 DATABUS=DATABUS|0x0F;
 DATABUS=(DATABUS&0xF0)|lcd_b;
 EN=1;
 EN=0;
}

char port_read()
{
 char lcd_r;
 EN=1;
 DATABUS=DATABUS|0x0F;
 lcd_r=(DATABUS&0x0F);
 EN=0;
 return lcd_r;
}

void lcd_busy()
{
 char lcd_b;
 lcd_b=0x80;
 RS=0;
 RW=1;
 while(lcd_b==0x80)
 {
  lcd_b=(port_read()<<4);
  lcd_b=(lcd_b|port_read())&0x80;
 }
 RW=0;
}

void lcd_cmd(char lcd_c)
{
 RS=0;
 RW=0;
 port_write(lcd_c>>4);
 port_write(lcd_c&0x0F);
 lcd_busy();
}

void lcd_start()
{
 EN=0;
 delay(1);
 RS=0;
 RW=0;
 port_write(0x03);
 delay(1);
 port_write(0x02);
 lcd_busy();
 lcd_cmd(0x28);
}

void lcd_init()
{
 lcd_cmd(0x01);
 lcd_cmd(0x0C);
 lcd_cmd(0x06);
 lcd_cmd(0x80);
}

void lcd_data(char lcd_d)
{
 RS=1;
 RW=0;
 port_write(lcd_d>>4);
 port_write(lcd_d&0x0F);
 lcd_busy();
}

void lcd_print(char *lcd_p)
{
 while(*lcd_p!=0x00)
 {
  lcd_data(*lcd_p);
  *lcd_p++;
 }
}

void lcd_line(char lcd_l)
{
 lcd_cmd((lcd_l-1)*0x40|0x80);
}

void lcd_pos(char lcd_x,char lcd_y)
{
 lcd_cmd((lcd_x-1)*0x40|0x80|(lcd_y-1));
}

#endif