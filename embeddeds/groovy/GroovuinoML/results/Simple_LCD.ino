// Wiring code generated from an ArduinoML model
// Application name: Very simple LCD 

long debounce = 200;

enum STATE {on, off};
STATE currentState = off;

boolean button1BounceGuard = false;
long button1LastDebounceTime = 0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7,8); // screen [LCD Actuator]

void setup(){
  pinMode(9, INPUT);  // button1 [Sensor]
  lcd.begin(16,2); // screen [Actuator]
}

void loop() {
	switch(currentState){
		case on:
			lcd.setCursor(0,0);
			lcd.print("Mouradox UwU");
			button1BounceGuard = millis() - button1LastDebounceTime > debounce;
			if (digitalRead(9) == LOW && button1BounceGuard) {
				button1LastDebounceTime = millis();
				currentState = off;
			}
		break;
		case off:
			lcd.clear();
			button1BounceGuard = millis() - button1LastDebounceTime > debounce;
			if (digitalRead(9) == HIGH && button1BounceGuard) {
				button1LastDebounceTime = millis();
				currentState = on;
			}
		break;
	}
}
