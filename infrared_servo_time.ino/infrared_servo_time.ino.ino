#include <Servo.h>

int sensorPin = 8;  // Pin sensor
int servoPin = 9;   // Pin servo
int sensorValue;    // Nilai sensor
int pos = 0;        // Posisi awal servo
Servo myservo;      // Inisialisasi objek servo

void setup() {
  myservo.attach(servoPin); // Menghubungkan servo ke pin
}

void loop() {
  sensorValue = digitalRead(sensorPin); // Membaca nilai sensor

  if (sensorValue == HIGH) {  // Jika sensor mendeteksi benda
    delay(17000);             // Tunggu 17 detik
    myservo.write(50);        // Menggerakkan servo ke 50 derajat
  }
  else {                      // Jika sensor tidak mendeteksi benda
    myservo.write(150); delay(10);       // Menggerakkan servo ke 150 derajat
  }
}
