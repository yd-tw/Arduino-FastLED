#include "FastLED.h"               //引入FastLED標頭黨
#define NUM_LEDS 16                //定義全彩LED數量
#define DATA_PIN 2                 //定義全彩LED訊號腳位
#define BRIGHTNESS 32              //定義亮度
CRGB faya_colorSticker[NUM_LEDS];  //定義FastLED類別
CRGB color = CRGB::Orange;

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(faya_colorSticker, NUM_LEDS);  //設定串列全彩LED參數
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  showRainbow();
  delay(500);
}

void showRainbow() {
  if (digitalRead(7)) {
    color = CRGB::Red;
  }
  if (digitalRead(8)) {
    color = CRGB::Yellow;
  }
  if (digitalRead(9)) {
    color = CRGB::White;
  }

  for (int i = 0; i < NUM_LEDS; i++)  //輪流讀表設定LED顏色
  {
    faya_colorSticker[i] = color;
    FastLED.show();
    delay(20);
  }
  FastLED.clear();
}