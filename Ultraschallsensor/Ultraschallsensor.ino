/*
 Name:		Ultraschallsensor.ino
 Created:	01.12.2018 11:17:19
 Author:	Johannes
*/

int inputPin = 11, triggerPin = 13;

//Schallgeschwindigkeit beträgt circa 343,3 m/s
float schallgeschwindigkeit = 343.3;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	pinMode(triggerPin, OUTPUT);
	pinMode(inputPin, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (Serial.available()) {
		String in = Serial.readString();
		if (in == "trigger") {
			digitalWrite(triggerPin, HIGH);
			delay(10);
			digitalWrite(triggerPin, LOW);

			//Gibt die Dauer des Highsignals in MIKROsekunden zurück.
			float inputDuration = pulseIn(inputPin, HIGH);
			float abstand = abstandBerechnung(inputDuration);
			Serial.println();
			Serial.print("Der Gegenstand ist ");
			Serial.print(abstand);
			Serial.print(" Meter entfernt.");

		}
	}

}
float abstandBerechnung(float wert) {
	//Diese Variable dient der Übersichtlichkeit. :)
	float zahl = wert;

	//Schritt 1: Multiplikation mit der Schallgeschwindigkeit (m/s) geteilt durch 1 000 000, da wird m/mikrosekunde brauchen. (1m/s = 1 * 10^-6 m/mikrosekunde)
	zahl *= (schallgeschwindigkeit / 1000000);

	//Schritt 2: Die Zahl mit 2 dividieren, da der Wert doppelt so hoch ist, als die Entfernung zwischen Ultraschallsensor und Gegenstand, da der Schall hin und zurück muss.
	zahl /= 2;

	//Schritt 3: Zurückgeben des Abstands (Einheit: Meter)
	return zahl; 
}