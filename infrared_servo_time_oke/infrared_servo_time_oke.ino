#include <Servo.h>

int irSensorPin = 8;
int servoPin = 9;
Servo myServo;

void setup() {
pinMode(irSensorPin, INPUT);
myServo.attach(servoPin);
myServo.write(0); // posisi awal servo
Serial.begin(9600); // memulai komunikasi serial pada kecepatan 9600 bps
}

void loop() {
int irSensorVal = digitalRead(irSensorPin);
Serial.print("Sensor: ");
Serial.println(irSensorVal); // menampilkan nilai sensor pada serial monitor

if (irSensorVal == LOW) {
myServo.write(50);
delay(8000); // delay 7 detik jika sensor mendeteksi benda pertama
myServo.write(150); // gerakan servo ke posisi 50 jika sensor mendeteksi benda kedua
delay(1000); // delay 1 detik
} else {
myServo.write(0); // gerakan servo ke posisi 150 jika tidak ada benda yang terdeteksi
}
}
