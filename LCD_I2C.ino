#include "LCD_I2C.h"
#include <Arduino_DebugUtils.h>

const uint8_t rows = 4;
const uint8_t cols = 20;

LCD_I2C lcd = LCD_I2C(0x27, rows, cols);

String full_screen = "Testing the LCD_I2C |===================ABCDEFGHIJKLMNOPQRST0123456789+_/*()[]{}";
String part_screen = "1.                  2.                  3.                  4.                  ";
String empty_screen = "                                                                                ";

long start = millis();

void setup() 
{
	// put your setup code here, to run once:
	Serial.begin(9600);
	lcd.init();
	lcd.setScreen(full_screen);
	lcd.switchBacklight(true);
	lcd.switchDisplay(true);
	lcd.switchCursor(false);
	lcd.switchBlink(false);
	lcd.bufferToScreen();	
}

void loop() 
{
	// reply only when you receive data:
	if (millis() - start > 3000)
	{
		start = millis();
		lcd.scrollScreenUp(true);
	}
}