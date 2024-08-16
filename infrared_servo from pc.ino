#include <Servo.h>

// Initialize the servo motor and infrared sensor pins
Servo myservo;
int irSensor = 8;

// Initialize the servo positions
int servoPos = 150;  // default servo position
int servoDetectPos = 50;  // servo position when object is detected

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attach the servo to pin 9
  pinMode(irSensor, INPUT);  // set the infrared sensor as an input
  myservo.write(servoPos);  // move the servo to the default position
}

void loop() {
  int irReading = digitalRead(irSensor);

  if (irReading == HIGH) {  // if object is detected by the infrared sensor
    delay(100);  // wait for a moment to debounce the sensor
    irReading = digitalRead(irSensor);  // take another reading

    if (irReading == HIGH) {  // if object is detected 2x
      myservo.write(servoDetectPos);  // move the servo to the detect position
      Serial.println("No Object detected!");
      delay(500);  // wait for half a second
    }
  } else {  // if no object is detected by the infrared sensor
    myservo.write(servoPos);  // move the servo to the default position
    Serial.println("Object detected.");
    delay(500);  // wait for half a second
  }
}
