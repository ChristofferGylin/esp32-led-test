#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define NUM_LEDS_PER_GATE 4
#define NUM_GATES 7
#define DATA_PIN 2

const int NUM_LEDS = NUM_LEDS_PER_GATE * NUM_GATES;

class LedColor {
  public:
    int red;
    int green;
    int blue;
};

const int NUM_COLORS = 7;
int count = 0;

LedColor gateColors[NUM_COLORS] = { {red: 255, green: 0, blue: 0}, {red: 0, green: 255, blue: 0}, {red: 0, green: 0, blue: 255}, {red: 127, green: 0, blue: 128}, {red: 128, green: 127, blue: 0}, {red: 0, green: 127, blue: 128}, {red: 85, green: 85, blue: 85}};

Adafruit_NeoPixel pixels(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

// put function declarations here:
int selectColor(int, int);

void setup() {
  pixels.begin();
  pixels.setBrightness(30);
  
}

void loop() {
  pixels.clear();
  
  for (int gate = 0; gate < NUM_GATES; gate++) {
    const int firstPixel = gate * NUM_LEDS_PER_GATE;
    const int color = selectColor(gate, count);

    for (int pixel = firstPixel; pixel < firstPixel + NUM_LEDS_PER_GATE; pixel++) {
      pixels.setPixelColor(pixel, pixels.Color(gateColors[color].red, gateColors[color].green, gateColors[color].blue));
    }
  }

  pixels.show();

  if (count < NUM_COLORS - 1) {
    count++;
  } else {
    count = 0;
  }
  delay(2000);
}

// put function definitions here:
int selectColor(int gate, int count) {
  
  if (gate + count >= NUM_COLORS) {
    return gate + count - NUM_COLORS;
  } else {
    return gate + count;
  }
}