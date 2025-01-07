# Sistem Pendeteksi Cuaca Berbasis IoT

## Deskripsi Proyek
Proyek ini bertujuan untuk mengembangkan sistem IoT yang mampu memantau cuaca di lingkungan rumah secara otomatis dan real-time. Sistem menggunakan perangkat berbasis **ESP8266**, sensor **DHT11**, **modul hujan**, dan **sensor LDR** untuk mengukur berbagai parameter lingkungan. Data dari sensor dikirim ke platform **Blynk**, memungkinkan pengguna memantau kondisi cuaca melalui aplikasi.

## Fitur Utama
1. **Pemantauan Real-Time**: Suhu, kelembapan, intensitas hujan, dan kondisi cahaya.
2. **Klasifikasi Kondisi Cahaya**: Menentukan apakah cuaca **Cerah**, **Berawan**, atau **Gelap**.
3. **Visualisasi Data**: Data cuaca divisualisasikan melalui aplikasi **Blynk**.
4. **Notifikasi Otomatis**: Memberikan peringatan untuk kondisi cuaca tertentu.

## Anggota Kelompok
| Nama                        | NIM        |
|-----------------------------|------------|
| Deril Wijdan Falih          | 1303223047 |
| Giovanni Nadika             | 1303223169 |
| Retsi Andari Rusli          | 1303223043 |
| Muhammad Ghafarel Faikhar Rahman | 1303223049 |
| Bima Aditya Ramadhan        | 1303223173 |

## Komponen Utama
- **ESP8266**: Mikrokontroler untuk mengumpulkan dan mengirim data sensor.
- **DHT11**: Sensor untuk mengukur suhu dan kelembapan.
- **Modul Hujan**: Sensor untuk mendeteksi intensitas hujan.
- **Sensor LDR**: Sensor untuk mengukur intensitas cahaya.

## Cara Kerja Sistem
1. Data cuaca diambil oleh sensor (**DHT11**, **Modul Hujan**, **Sensor LDR**).
2. Mikrokontroler **ESP8266** memproses data dan mengirimkannya ke platform **Blynk** melalui koneksi Wi-Fi.
3. Pengguna dapat memantau data cuaca secara real-time melalui aplikasi Blynk.
4. Sistem memberikan notifikasi otomatis jika kondisi cuaca memenuhi kriteria tertentu.

## Teknologi yang Digunakan
- **Platform IoT**: [Blynk](https://blynk.io/)
- **Mikrokontroler**: ESP8266
- **Sensor**: DHT11, Modul Hujan, LDR

## Instalasi
1. **Persiapan Hardware**:
   - Rakit perangkat keras sesuai dengan diagram.
   - Pastikan sensor terhubung dengan benar ke ESP8266.
2. **Persiapan Software**:
   - Unduh dan instal aplikasi **Blynk** di perangkat seluler.
   - Tambahkan proyek baru di aplikasi Blynk dan catat token autentikasi.
3. **Kode dan Upload**:
   - Gunakan [Arduino IDE](https://www.arduino.cc/en/software/) untuk menulis dan mengunggah kode ke ESP8266.
   - Tambahkan token autentikasi Blynk, SSID Wi-Fi, dan kata sandi di kode.
4. **Monitoring**:
   - Buka aplikasi **Blynk** untuk memantau data secara real-time.



