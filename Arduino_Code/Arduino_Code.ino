

#define thumb A0
#define index A1
#define middle A2
#define ring A3
#define pinky 10


byte current_fingers [5];
byte previous_fingers [5];

void setup() {
	Serial.begin(9600);
	pinMode(thumb, INPUT);
	pinMode(index, INPUT);
	pinMode(middle, INPUT);
	pinMode(ring, INPUT);
	pinMode(pinky, INPUT);
}

void loop() {
	current_fingers[0] = analogRead(thumb);
	current_fingers[1] = analogRead(index);
	current_fingers[2] = analogRead(middle);
	current_fingers[3] = analogRead(ring);
	current_fingers[4] = analogRead(pinky);

	Serial.write(previous_fingers,5);
	Serial.write(previous_fingers,5);
}
