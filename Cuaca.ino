#define BLYNK_TEMPLATE_ID "TMPL6MVW6Ea2P"
#define BLYNK_TEMPLATE_NAME "Tugas Besar IOT"
#define BLYNK_AUTH_TOKEN "uYCndgkL6pl5ZjosVJxn-wPf0uL3YPdw"

#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <WiFiClientSecure.h>

// Informasi WiFi
char ssid[] = "Tes";        
char pass[] = "12345678";    

// Pin untuk DHT11, Rain Module, dan LDR
#define DHTPIN D4
#define DHTTYPE DHT11
#define RAINPIN D0
#define LDRPIN A0

DHT dht(DHTPIN, DHTTYPE);

// Variabel
BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); 
  dht.begin();                              
  pinMode(RAINPIN, INPUT);                  
  pinMode(LDRPIN, INPUT);
  Serial.println("Weather Monitoring with Blynk");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Gagal terhubung ke WiFi!");
  } else {
    Serial.println("Berhasil terhubung ke WiFi!");
  }
  
  timer.setInterval(3000L, sendSensorData);
}

void sendSensorData() {
  // Membaca data sensor
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();
  int rainValue = digitalRead(RAINPIN);
  int ldrValue = analogRead(LDRPIN);

  if (isnan(suhu) || isnan(kelembapan)) {
    Serial.println("Gagal membaca sensor DHT11!");
    return;
  }

String hujan = (rainValue == HIGH) ? "Tidak Ada Hujan" : "Hujan";

 String kondisiCahaya;
if (ldrValue < 500) {
  kondisiCahaya = "Cerah"; 
} else if (ldrValue >= 500 && ldrValue <= 700) {
  kondisiCahaya = "Berawan"; // Nilai menengah, cahaya sedang
} else {
  kondisiCahaya = "Gelap"; // Nilai tinggi, cahaya rendah
}


  // Kirim data ke Blynk
  Blynk.virtualWrite(V0, suhu);         
  Blynk.virtualWrite(V1, kelembapan);   
  Blynk.virtualWrite(V2, hujan);        
  Blynk.virtualWrite(V3, kondisiCahaya); // Kondisi cahaya

  // Tampilkan data di Serial Monitor
  Serial.println("========== Weather Monitoring ==========");
  Serial.print("Suhu       : "); Serial.print(suhu); Serial.println(" °C");
  Serial.print("Kelembapan : "); Serial.print(kelembapan); Serial.println(" %");
  Serial.print("Intensitas Hujan : "); Serial.println(hujan);
  Serial.print("Nilai Sensor Hujan : "); Serial.println(rainValue);
  Serial.print("Kondisi Cahaya : "); Serial.println(kondisiCahaya);
  Serial.print("Nilai LDR (Cahaya) : "); Serial.println(ldrValue);
  Serial.println("========================================");
}

void loop() {
  Blynk.run();   
  timer.run();    
}