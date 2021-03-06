#include <LiquidCrystal_I2C.h>

#include <Wire.h>
// 設定 LCD I2C 位址
// Set the pins on the I2C chip used for LCD connections:
// addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光
  lcd.begin(16, 2);

  // 閃爍三次
  for (int i = 0; i < 3; i++) {
    lcd.backlight(); // 開啟背光
    delay(250);
    lcd.noBacklight(); // 關閉背光
    delay(250);
  }
  lcd.backlight();

  // 輸出初始化文字
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("ICshop&MakerPRO");
  delay(1000);
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print("Hello, Maker!");
  delay(8000);
  lcd.clear(); //顯示清除
}
void loop() {
  lcd.setCursor(0, 0); // 設定游標位置在第一行行首
  lcd.print("ICshop&MakerPRO");
  lcd.setCursor(0, 1); // 設定游標位置在第二行行首
  lcd.print(millis() / 1000);
}
