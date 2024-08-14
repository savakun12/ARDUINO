#include <Servo.h>

Servo myservo;

int irPin1 = 8; // pin sensor infrared 1
int irPin2 = 9; // pin sensor infrared 2
int pos = 0; // variabel untuk menyimpan posisi servo
long startTime = 0; // variabel untuk menyimpan waktu mulai

void setup() {
  myservo.attach(10); // servo dihubungkan ke pin 9
  pinMode(irPin1, INPUT); // sensor infrared 1 sebagai input
  pinMode(irPin2, INPUT); // sensor infrared 2 sebagai input
}

void loop() {
  int irValue1 = digitalRead(irPin1); // membaca sensor infrared 1
  int irValue2 = digitalRead(irPin2); // membaca sensor infrared 2

  if (irValue1 == HIGH) { // jika sensor infrared 1 mendeteksi benda
    startTime = millis(); // simpan waktu mulai
    while ((millis() - startTime) > 4000) { // selama delay > 4 detik
      if (irValue2 == HIGH) { // jika sensor infrared 2 mendeteksi benda
        myservo.write(50); // servo bergerak ke 50
        delay(15); // tunggu 15 milidetik
        irValue2 = digitalRead(irPin2); // baca ulang sensor infrared 2
      }
      else { // jika sensor infrared 2 tidak mendeteksi benda
        myservo.write(0); // servo kembali ke 0
      }
    }
  }

  if (irValue1 == HIGH) { // jika sensor infrared 1 mendeteksi benda
    startTime = millis(); // simpan waktu mulai
    while ((millis() - startTime) < 2000) { // selama delay < 2 detik
      if (irValue2 == HIGH) { // jika sensor infrared 2 mendeteksi benda
        myservo.write(150); // servo bergerak ke 150
        delay(15); // tunggu 15 milidetik
        irValue2 = digitalRead(irPin2); // baca ulang sensor infrared 2
      }
      else { // jika sensor infrared 2 tidak mendeteksi benda
        myservo.write(0); // servo kembali ke 0
      }
    }
  }
}