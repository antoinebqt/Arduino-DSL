// Wiring code generated from an ArduinoML model
// Application name: Very simple LCD 

long debounce = 200;

enum STATE {both, led, snooze, none};
STATE currentState = none;

boolean button1BounceGuard = false;
long button1LastDebounceTime = 0;

boolean button2BounceGuard = false;
long button2LastDebounceTime = 0;

void setup(){
  pinMode(9, INPUT);  // button1 [Sensor]
  pinMode(10, INPUT);  // button2 [Sensor]
  pinMode(11, OUTPUT); // snooze1 [Actuator]
  pinMode(12, OUTPUT); // led1 [Actuator]
}

void loop() {
	switch(currentState){
		case both:
			digitalWrite(12,HIGH);
			digitalWrite(11,HIGH);
			button2BounceGuard = millis() - button2LastDebounceTime > debounce;
			if (digitalRead(10) == LOW && button2BounceGuard) {
				button2LastDebounceTime = millis();
				currentState = snooze;
			}
			button2BounceGuard = millis() - button2LastDebounceTime > debounce;
			if (digitalRead(10) == LOW && button2BounceGuard) {
				button2LastDebounceTime = millis();
				currentState = led;
			}
		break;
		case led:
			digitalWrite(12,HIGH);
			digitalWrite(11,LOW);
			button1BounceGuard = millis() - button1LastDebounceTime > debounce;
			if (digitalRead(9) == LOW && button1BounceGuard) {
				button1LastDebounceTime = millis();
				currentState = none;
			}
			button2BounceGuard = millis() - button2LastDebounceTime > debounce;
			if (digitalRead(10) == HIGH && button2BounceGuard) {
				button2LastDebounceTime = millis();
				currentState = both;
			}
		break;
		case snooze:
			digitalWrite(12,LOW);
			digitalWrite(11,HIGH);
			button2BounceGuard = millis() - button2LastDebounceTime > debounce;
			if (digitalRead(10) == LOW && button2BounceGuard) {
				button2LastDebounceTime = millis();
				currentState = none;
			}
			button1BounceGuard = millis() - button1LastDebounceTime > debounce;
			if (digitalRead(9) == HIGH && button1BounceGuard) {
				button1LastDebounceTime = millis();
				currentState = both;
			}
		break;
		case none:
			digitalWrite(12,LOW);
			digitalWrite(11,LOW);
			button1BounceGuard = millis() - button1LastDebounceTime > debounce;
			if (digitalRead(9) == HIGH && button1BounceGuard) {
				button1LastDebounceTime = millis();
				currentState = led;
			}
			button2BounceGuard = millis() - button2LastDebounceTime > debounce;
			if (digitalRead(10) == HIGH && button2BounceGuard) {
				button2LastDebounceTime = millis();
				currentState = snooze;
			}
		break;
	}
}
