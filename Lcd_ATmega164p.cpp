/*
LA LIBRERÍA lcd.h NO es mia
no recuerdo de donde la descargue, pero funciona

*/
#include <avr/io.h>
#include <stdio.h>   // para sprintf
#include "lcd.h"
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
    lcd_init(LCD_DISP_ON);  // inicia el lcd
	lcd_clrscr();       
	
	lcd_gotoxy(0,0); lcd_puts("Hola Mundo");
	_delay_ms(700);
	lcd_clrscr();       
	lcd_gotoxy(5,0); lcd_puts("Manejo");
	lcd_gotoxy(7,1); lcd_puts("LCD");
	_delay_ms(700);
	lcd_clrscr();
	
	lcd_gotoxy(0,0); lcd_puts("Unsigned int:");
	
	for (int i=0; i<13; i++)
	{
		lcd_gotoxy(1,1);
		lcd_write_value(i,2);  //  funcion solo para indicar valores tipo unsigned int;
		_delay_ms(250);
	}
	
	char numChar[5];
	lcd_clrscr();
	lcd_gotoxy(0,0); lcd_puts("Signed int:");
	for (int i=-5; i<12; i++)
	{
		sprintf(numChar,"%3d",i);
		lcd_gotoxy(1,1);
		lcd_puts(numChar);
		_delay_ms(250);
	}
	
	lcd_clrscr();
	lcd_gotoxy(0,0); lcd_puts("Numero real:");
	double real=-2;
	while(real < 2.5){
		sprintf(numChar,"%.2f",real);    //convertir en numero en un string.
		lcd_gotoxy(1,1);
		lcd_puts(numChar);
		_delay_ms(280);	
		real = real + 0.5;
	}
	
    while (1) 
    {
    }
}
