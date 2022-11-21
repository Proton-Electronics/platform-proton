#include <Arduino.h>

#include <GyverOLED.h>
// GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;

void printScale(byte x);
void party();
void overlapTest();
void printTest();
void showText();
void scrollText();
void scaleText();
void welcome();
void display_status();

char Lorem_ipsum[] = "Lorem ipsum dolor sit amet, лорем ипсум долор сит амет привет народ ё, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip...";
void setup()
{
  Serial.begin(9600);
  oled.init(); // инициализация
  welcome();
}

void loop()
{
  // printScale(1);
  // printScale(2);
  // printScale(3);
  // printScale(4);
  // overlapTest();
  // printTest();
  // party();
  // showText();
  // scrollText();
  // scaleText();
  display_status();
}

void printScale(byte x)
{
  oled.clear();
  oled.setScale(x);
  for (byte i = 0; i < 8; i += x)
  {
    oled.setCursor(0, i);
    oled.print("Hello!");
  }
  oled.update();
  delay(1000);
}

void party()
{
  oled.clear();
  uint32_t tmr = millis();
  oled.setScale(3);
  oled.setCursor(10, 2);
  oled.print("PLC A5");
  oled.setScale(2);
  oled.setCursor(6, 5);
  oled.print(" Arduino!");
  oled.update();
  for (;;)
  {
    oled.invertDisplay(true);
    delay(200);
    oled.invertDisplay(false);
    delay(200);
    if (millis() - tmr > 5000)
      return;
  }
}

void overlapTest()
{
  oled.clear();
  oled.setScale(1);
  oled.setCursorXY(0, 0);
  oled.print("LOL");
  oled.update();
  delay(500);
  oled.setCursorXY(0, 8);
  oled.print("KEK!");
  oled.update();
  delay(500);

  oled.setCursorXY(40, 4);
  oled.print("LOL");
  oled.update();
  delay(500);
  oled.setCursorXY(40, 12);
  oled.print("KEK!");
  oled.update();
  delay(500);

  oled.setScale(2);
  oled.setCursorXY(0, 24);
  oled.print("LOL");
  oled.update();
  delay(500);
  oled.setCursorXY(0, 40);
  oled.print("KEK!");
  oled.update();
  delay(500);

  oled.setCursorXY(60, 28);
  oled.print("LOL");
  oled.update();
  delay(500);
  oled.setCursorXY(60, 44);
  oled.print("KEK!");
  oled.update();
  delay(5000);
}

void printTest()
{
  oled.clear();
  char data0[] = "Привет!";
  char data1 = 'b';
  int data2 = -50;
  float data3 = 1.25;
  oled.home();
  oled.setScale(1);
  oled.println(data0);
  oled.println(data1);
  oled.invertText(true);
  oled.println(data2);
  oled.println(data3);
  oled.invertText(false);
  oled.update();
  delay(5000);
}

void showText()
{
  oled.clear();
  oled.home();
  oled.autoPrintln(true);
  oled.setScale(1);
  oled.print(Lorem_ipsum);
  oled.update();
  delay(5000);
}

void scrollText()
{
  oled.clear();
  uint32_t tmr = millis();
  oled.autoPrintln(false);
  int val = 128;
  for (;;)
  {
    oled.clear(); // ЗАКОММЕНТИРУЙ, ЕСЛИ ВКЛЮЧЕН БУФЕР
    oled.setScale(1);
    oled.setCursor(val, 0);
    oled.print(Lorem_ipsum);

    oled.setScale(2);
    oled.setCursor(val, 1);
    oled.print(Lorem_ipsum);

    oled.setScale(3);
    oled.setCursor(val, 4);
    oled.print(Lorem_ipsum);
    oled.update();
    val--;
    if (millis() - tmr > 5000)
      return;
  }
}

void scaleText()
{
  uint32_t tmr = millis();
  byte scale = 1;
  oled.autoPrintln(true);
  for (;;)
  {
    oled.clear();
    oled.setScale(scale);
    oled.home();
    oled.print("Привет!");
    oled.update();
    delay(1000);
    oled.clear();
    scale++;
    if (scale > 4)
      scale = 1;
    if (millis() - tmr > 5000)
      return;
  }
}

void welcome()
{
  oled.clear();
  uint32_t tmr = millis();
  oled.setScale(3);
  oled.setCursor(10, 2);
  oled.print("PLC A5");
  oled.setScale(1);
  oled.setCursor(18, 6);
  oled.print("Proton Arduino!");
  oled.update();
  for (;;)
  {
    oled.invertDisplay(true);
    delay(200);
    oled.invertDisplay(false);
    delay(200);
    if (millis() - tmr > 3000)
      break;
  }
  oled.clear();
}

void display_status()
{
  oled.clear();
  oled.setScale(1);

  /* Analog in */
  oled.setCursor(0, 1);
  oled.invertText(true);
  oled.print("      Analog in       ");
  oled.invertText(false);
  oled.setCursor(0, 0);
  float in1 = 1.63;
  float in2 = 4.22;
  float in3 = 3.95;
  float in4 = 6.75;
  oled.print(in1);
  oled.print(" | ");
  oled.print(in2);
  oled.print(" | ");
  oled.print(in3);
  oled.print(" | ");
  oled.print(in4);

  /* Analog out */
  oled.setCursor(0, 6);
  oled.invertText(true);
  oled.print("      Analog out      ");
  oled.invertText(false);
  oled.setCursor(0, 7);
  float data1 = 1.25;
  float data2 = 1.25;
  oled.print(data1);
  oled.print(" | ");
  oled.print(data2);

  /* Message */
  oled.setScale(2);
  oled.setCursor(0, 3);
  oled.print(" Arduino");

  oled.update();
}
