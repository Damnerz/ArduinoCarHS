//todo 
//
//faire le mix appinventor laision input
//



#include "AFMotor.h"

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int val;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);   // LEDs
 
  motor1.setSpeed(250); // vitesse maximum
  motor1.run(RELEASE);  // arrêter le moteur
  motor2.setSpeed(250); // vitesse maximum
  motor2.run(RELEASE);  // arrêter le moteur
}

void loop() {
if (Serial.available() ) {
    val = Serial.read();
    // avant
    if (val == 'f') {
       motor1.run(FORWARD);
       motor1.setSpeed(250); 
       motor2.run(FORWARD);
       motor2.setSpeed(250);
    }
    //arrière
    if (val == 'b') {
       motor1.run(BACKWARD);
       motor1.setSpeed(200); 
       motor2.run(BACKWARD);
       motor2.setSpeed(200);
    }
    // arrêter les moteurs
    if (val == 's') {
       motor1.run(RELEASE);
       motor2.run(RELEASE);
    }
    // gauche
    if (val == 'l') {
       motor1.run(FORWARD);
       motor1.setSpeed(100); 
       motor2.run(BACKWARD);
       motor2.setSpeed(250);
    }
    // droite
    if (val == 'r') {
       motor1.run(BACKWARD);
       motor1.setSpeed(250); 
       motor2.run(FORWARD);
       motor2.setSpeed(100);
    }
    if (val == '1') { digitalWrite(8, HIGH); }
    if (val == '0') { digitalWrite(8, LOW); }
  }
}