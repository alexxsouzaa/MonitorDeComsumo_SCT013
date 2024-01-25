#include <Arduino.h>
#include <U8g2lib.h>
#include "xbm.cpp"

// Definição do pino do sensor
const int pinSensor = 34;

// Driver do display OLED DE 1.3 Polegadas
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

int x = 0;
int y = 0;

int periodo = 25;
long int timeAtual = 0;
long int timePosterior = 0;

void setup()
{
  // Inicializa o serial monitor
  Serial.begin(9600);

  // Inicializa o display
  u8g2.begin();
  // Define o contraste do display
  u8g2.setContrast(128);
  // Define o pino do sensor como entrada
  pinMode(pinSensor, INPUT);
}

void loop()
{
  timeAtual = millis();

  u8g2.firstPage();
  do
  {
    // Status Bar
    u8g2.drawBox(0, 0, 128, 10);
    // Ícone de atenção
    u8g2.setFontMode(2);
    u8g2.setDrawColor(0);
    u8g2.setFont(u8g2_font_open_iconic_embedded_1x_t);
    u8g2.drawGlyph(119, 9, 0x0047);
    // Hora
    u8g2.setFont(u8g2_font_spleen5x8_mf);
    u8g2.setCursor(1, 8);
    u8g2.print("14:29");
    // Temperatura
    u8g2.setFont(u8g2_font_spleen5x8_mf);
    u8g2.setCursor((u8g2.getWidth() - 11) / 2, 8);
    u8g2.print("31 'C");
    // Indicador de Corrente
    u8g2.setDrawColor(1);
    u8g2.setFont(u8g2_font_spleen16x32_me);
    u8g2.setCursor(0, 35);
    u8g2.print("1.03");
    u8g2.setFont(u8g2_font_spleen6x12_mf);
    u8g2.print(" A");
    // Indicador de Tensão e potencia
    u8g2.setFont(u8g2_font_spleen6x12_mf);
    u8g2.setCursor(97, 23);
    u8g2.print("127 V");
    u8g2.setCursor(97, 35);
    u8g2.print("130 W");
    // Gráfico
    u8g2.drawXBM(0, 42, grafico_width, grafico_height, grafico);
    if (timeAtual - timePosterior >= periodo)
    {
      timePosterior = timeAtual;

      for (x = 4; x < 126; x++)
      {
        int sensor = map(analogRead(pinSensor), 0, 4095, 60, 44);
        u8g2.drawPixel(x, sensor);
      }
    }

    if (x == 126)
    {
      x = 4;
    }

  } while (u8g2.nextPage());
}