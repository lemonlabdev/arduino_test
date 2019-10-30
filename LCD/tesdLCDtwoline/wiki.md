# LCD(I2C) 사용법

## 선 연결법
GND -- GND
VCC -- 5V
SDA -- A4
SCL -- A5

## LiquidCrystal_I2C.h API

lcd.begin(); // lcd를 사용을 시작합니다.

lcd.backlight(); // backlight를 On 시킵니다.

lcd.setCursor(0,1); // LCD커서위치를 변경시킵니다(첫번째 인자가 row, 두번째인자가 column)
-> 2줄짜리 LCD는 0~1, 4줄짜리 LCD는 0~3

lcd.print("Hello, world!"); // 화면에 Hello, world!를 출력합니다.
-> "문자열" 대신 변수값도 가능