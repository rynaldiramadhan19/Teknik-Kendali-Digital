//Jam digital dengan LCD By Rynaldi Ramadhan Mustakin
#include <virtuabotixRTC.h>
irtuabotixRTC myRTC(6, 7, 8); //CLK, DAT, RST
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
 
void setup() {
lcd.begin();
myRTC.setDS1302Time(00, 41, 20, 5, 25, 06, 2020); // sesuaikan dengan waktu terkini
// posisi seting (detik, menit, jam, hari, tanggal, bulan, tahun)


//tampilan awal mula
lcd.setCursor(0, 0);
lcd.print("Jam Digital LCD!");
lcd.setCursor(0, 1);
lcd.print("   BY Rynaldi Ramadhan   ");
delay (3000);
lcd.clear ();

}
 
void loop() {
 
myRTC.updateTime();
lcd.setCursor(0, 0);
lcd.print("Tgl: ");
lcd.print(myRTC.dayofmonth);
lcd.print("/");
lcd.print(myRTC.month);
lcd.print("/");
lcd.print(myRTC.year);
lcd.print(" ");
lcd.setCursor(0, 1);
lcd.print("Jam: ");
lcd.print(myRTC.hours);
lcd.print(":");
lcd.print(myRTC.minutes);
lcd.print(":");
lcd.print(myRTC.seconds);
lcd.print("    ");
 
}
