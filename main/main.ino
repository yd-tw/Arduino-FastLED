// 2018/04/15
// Faya-Nugget 範例程式 (Color_Sticker_3.ino)
// 單元: 模組介紹:faya串列全彩LED模組 (使用fastLED函式庫)
// 網址: https://fayalab.blogspot.com/2018/04/colorstickerfastLED.html
// 目標: (1) 使用fastLED的CRGB函式，讓跑馬燈依序顯示16種顏色
// 接線: Arduino ==> faya模組
//            D2 ==> 串列全彩LED_Din

#include "FastLED.h"  //引入FastLED標頭黨
#define NUM_LEDS 16  //定義全彩LED數量
#define DATA_PIN 2  //定義全彩LED訊號腳位
#define BRIGHTNESS 32 //定義亮度
CRGB faya_colorSticker[NUM_LEDS];  //定義FastLED類別

int rainbow16[16][3]={{255,   0,   0},    //紅
                      {255,  85,   0},    //橙
                      {255, 170,   0},    //
                      {255, 255,   0},    //黃
                      {127, 255,   0},    //
                      {  0, 255,   0},    //綠
                      {  0, 255,  85},    //
                      {  0, 255, 170},    //
                      {  0, 255, 255},    //青
                      {  0, 127, 255},    //
                      {  0,   0, 255},    //藍
                      { 85,   0, 255},    //紫
                      {170,   0, 255},    //
                      {255,   0, 255},    //洋紅
                      {255,   0, 127},    //
                      {255, 255, 255}};   //白

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(faya_colorSticker, NUM_LEDS);  //設定串列全彩LED參數
  FastLED.setBrightness(BRIGHTNESS);
}

void loop()
{
   showRainbow();
   delay(500);   
}

void showRainbow()
{
   for(int i=0;i<NUM_LEDS;i++)  //輪流讀表設定LED顏色
  {
    faya_colorSticker[i] = CRGB::Blue;
    FastLED.show(); 
    delay(20);
  }
  FastLED.clear();
}