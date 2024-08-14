#include <Servo.h>

int proximitySensorPin = 8; // Pin untuk sensor proximity
int proximitySensorValue = 0; // Variabel untuk menyimpan nilai sensor proximity
Servo servo; // Membuat objek servo

void setup() {
  servo.attach(9); // Pin servo
  pinMode(proximitySensorPin, INPUT); // Mengatur pin sensor proximity sebagai input
}

void loop() {
  proximitySensorValue = digitalRead(proximitySensorPin); // Membaca nilai sensor proximity

  if (proximitySensorValue == 1) { // Jika sensor proximity mendeteksi adanya besi
    servo.write(50); // Servo bergerak ke posisi 50 derajat
  } else { // Jika sensor proximity tidak mendeteksi adanya besi
    servo.write(150); // Servo bergerak ke posisi 150 derajat
  }

  delay(100); // Jeda waktu 100 milidetik sebelum membaca nilai sensor proximity lagi
}
