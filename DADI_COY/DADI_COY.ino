#include <Servo.h>

int irSensorPin = 8; // pin sensor infrared
int servoPin = 9; // pin servo
int pos = 0; // posisi awal servo
int delayTime = 500; // waktu delay untuk servo

Servo myservo; // membuat objek servo

void setup() {
  myservo.attach(servoPin); // menghubungkan pin servo
  pinMode(irSensorPin, INPUT); // menghubungkan pin sensor infrared
}

void loop() {
  int irSensorState = digitalRead(irSensorPin); // membaca status sensor infrared

  if (irSensorState == LOW) { // jika sensor infrared mendeteksi benda
    myservo.write(50); // servo bergerak ke posisi 50
    delay(delayTime); // tunggu sampai servo mencapai posisi 50
    int count = 0; // inisialisasi hitungan waktu
    
    // tunggu selama 8 detik
    while (irSensorState == LOW && count < 8) {
      delay(500); // tunggu 1 detik
      count++; // hitung waktu
      irSensorState = digitalRead(irSensorPin); // baca status sensor infrared
    }
    
    if (count == 8) { // jika masih terdeteksi benda selama 8 detik
      myservo.write(150); // servo bergerak ke posisi 150
      delay(3000); // tunggu sampai servo mencapai posisi 150
    }
  } else { // jika tidak ada benda yang dideteksi oleh sensor infrared
    myservo.write(0); // servo kembali ke posisi awal (0)
  }
}
