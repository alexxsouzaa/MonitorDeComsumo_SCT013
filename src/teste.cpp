/*#include <Arduino.h>
#include <U8g2lib.h>

// Defina o tipo de display e os pinos de conexão
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE); // Driver do display OLED DE 1.3 Polegadas
int x = 0;
int y = 0;

int valorMinimo = 0;
int valorMaximo = 4095;

const int pinSensor = 34;

void setup()
{
  Serial.begin(9600);
  // Inicialize o display
  u8g2.begin();
  u8g2.setBusClock(400000);
  pinMode(pinSensor, INPUT);
}

void loop()
{
  // Limpe o display
  u8g2.firstPage();
  do
  {
    // u8g2.drawFrame(0, 0, 128, 64);
    // u8g2.setFontMode(2);
    // u8g2.setDrawColor(2);
    u8g2.setFont(u8g2_font_logisoso30_tr);
    u8g2.setCursor(0, 30);
    u8g2.print("1.03");
    u8g2.setFont(u8g2_font_logisoso16_tr);
    u8g2.print("A");

    u8g2.setFont(u8g2_font_5x8_tf);
    u8g2.setCursor(104, 8);
    u8g2.print("127 V");
    u8g2.setCursor(104, 18);
    u8g2.print("130 W");
    u8g2.setCursor(109, 28);
    u8g2.print("33 C");

    int xAxe = 1;
    u8g2.setContrast(1);
    u8g2.drawFrame(0, 40, 128, 23);
    u8g2.drawBox(xAxe, 42, 2, 1);
    u8g2.drawBox(xAxe, 44, 2, 1);
    u8g2.drawBox(xAxe, 46, 2, 1);
    u8g2.drawBox(xAxe, 48, 2, 1);
    u8g2.drawBox(xAxe, 50, 2, 1);
    u8g2.drawBox(xAxe, 52, 2, 1);
    u8g2.drawBox(xAxe, 54, 2, 1);
    u8g2.drawBox(xAxe, 56, 2, 1);
    u8g2.drawBox(xAxe, 58, 2, 1);
    u8g2.drawBox(xAxe, 60, 2, 1);

    u8g2.setContrast(128);
    for (x = 5; x < 126; x++)
    {
      int sensor = map(analogRead(pinSensor), 0, 4095, 60, 42);

      u8g2.drawPixel(x, sensor);
      delayMicroseconds(25);
    }

    x = 5;

  } while (u8g2.nextPage());
}
*/