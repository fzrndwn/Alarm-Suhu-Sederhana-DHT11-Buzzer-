#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define BUZZER 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();

  if (isnan(suhu)) {
    Serial.println("Gagal membaca sensor!");
    return;
  }

  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.println(" °C");

  if (suhu > 30) {   // batas suhu panas
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}
