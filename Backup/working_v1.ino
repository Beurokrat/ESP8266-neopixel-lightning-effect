#include <FastLED.h>
#define LED_PIN  D4
#define NUM_LEDS 50

CRGB leds[NUM_LEDS];

int randomNumber;
// ( RED, BLUE, GREEN)


void yellow(int i)
{
  leds[i].setRGB(253, 35, 208);
  FastLED.show();
}

void blue(int i)
{
  leds[i].setRGB(0, 255, 56);
  FastLED.show();
}

void clearLight() {
  fill_solid( leds, NUM_LEDS, CRGB(0,0,0));
  FastLED.show();
}

void flashLight() {
  fill_solid( leds, NUM_LEDS, CRGB(255,255,255));
  FastLED.show();
}

void lightning() {
  Serial.println("Lightning");
  fill_solid( leds, NUM_LEDS, CRGB(0,0,0));
  FastLED.show();
  delay(2000);
  fill_solid( leds, NUM_LEDS, CRGB(255,255,255));
  FastLED.show();
  delay(100);
  fill_solid( leds, NUM_LEDS, CRGB(0,255,0));
  FastLED.show();
  delay(300);
  fill_solid( leds, NUM_LEDS, CRGB(0,0,0));
  FastLED.show();
  delay(400);
  fill_solid( leds, NUM_LEDS, CRGB(255,255,255));
  FastLED.show();
  delay(300);
  fill_solid( leds, NUM_LEDS, CRGB(0,0,0));
  FastLED.show();
  delay(7000);
}
void setup()
{
  Serial.begin(9600);
  delay(10000);
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop()
{
  randomNumber=random(10);
  Serial.println(randomNumber);

  int temp = 0;

  for (int i = 0; i < NUM_LEDS; i += 3)
  {
    for (int j = temp; j < i; j++)
      blue(j);
    temp = i;
    delay(150);
  }
  lightning();

  for (int i = NUM_LEDS - 1; i >= 0; i--)
  {
    yellow(i);
    delay(30);
  }
  delay(100);
  clearLight();
  delay(7000);
  lightning();
}