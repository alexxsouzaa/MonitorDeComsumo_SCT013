#include <Arduino.h>
#include <U8g2lib.h>

// Defina o tipo de display e os pinos de conexão
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE); // Driver do display OLED DE 1.3 Polegadas
int x = 0;
int y = 0;
int periodo = 80;
long int timeAtual = 0;
long int timePosterior = 0;

int valorMinimo = 0;
int valorMaximo = 4095;

const int pinSensor = 34;

void setup()
{
  Serial.begin(9600);
  // Inicialize o display
  u8g2.begin();
  u8g2.setBusClock(400000);
  u8g2.setContrast(1);
  pinMode(pinSensor, INPUT);
}

void loop()
{
  timeAtual = millis();

  // Limpe o display
  u8g2.firstPage();
  do
  {
    u8g2.drawBox(0, 0, 128, 10);

    u8g2.setFontMode(2);
    u8g2.setDrawColor(0);
    u8g2.setFont(u8g2_font_open_iconic_embedded_1x_t);
    u8g2.drawGlyph(119, 9, 0x0047);

    u8g2.setFont(u8g2_font_spleen5x8_mf);
    u8g2.setCursor(1, 8);
    u8g2.print("14:29");

    u8g2.setFont(u8g2_font_spleen5x8_mf);
    u8g2.setCursor((u8g2.getWidth() - 9) / 2, 8);
    u8g2.print("31 'C");

    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_spleen16x32_me);
    u8g2.setCursor(0, 35);
    u8g2.print("1.03");
    u8g2.setFont(u8g2_font_spleen6x12_mf);
    u8g2.print(" A");

    u8g2.setFont(u8g2_font_spleen6x12_mf);
    u8g2.setCursor(97, 23);
    u8g2.print("127 V");
    u8g2.setCursor(97, 35);
    u8g2.print("130 W");

    int xAxe = 1;
    //u8g2.drawFrame(0, 40, 128, 23);
    u8g2.drawLine(0, 42, 0, 63);
    u8g2.drawLine(0, 63, 128, 63);

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

    if (timeAtual - timePosterior >= periodo)
    {
      timePosterior = timeAtual;

      for (x = 5; x < 128; x++)
      {
        int sensor = map(analogRead(pinSensor), 0, 4095, 60, 42);
        u8g2.drawPixel(x, sensor);
      }
    }
    x = 5;
  } while (u8g2.nextPage());
}