#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define NUM_LEDS 28
#define DATA_PIN 2

Adafruit_NeoPixel MY_WS2812B(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

// put function declarations here:
int myFunction(int, int);

void setup() {
  MY_WS2812B.begin();
  MY_WS2812B.setBrightness(30);
}

void loop() {
  MY_WS2812B.clear();

  for (int pixel = 0; pixel < NUM_LEDS; pixel++) {
    MY_WS2812B.setPixelColor(pixel, MY_WS2812B.Color(0, 255, 0));
    MY_WS2812B.show();

    delay(500);
  }

  MY_WS2812B.clear();
  MY_WS2812B.show();
  delay(2000);

  for (int pixel = 0; pixel < NUM_LEDS; pixel++) {
    MY_WS2812B.setPixelColor(pixel, MY_WS2812B.Color(255, 0, 0));
  }

  MY_WS2812B.show();
  delay(1000);

  MY_WS2812B.clear();
  MY_WS2812B.show();
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}