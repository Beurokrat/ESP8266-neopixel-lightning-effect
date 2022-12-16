#include <FastLED.h>
#define LED_PIN D4
#define NUM_LEDS 50

CRGB leds[NUM_LEDS];

int randomNumber;
int sectionStart, sectionEnd;
int speed;
int numLed = 50;
char printBuffer[30];

// ( RED, BLUE, GREEN)

void yellow()
{
  for (int i = numLed; i > 0; i--)
  {
    leds[i].setRGB(253, 35, 208);
    FastLED.show();
    FastLED.delay(30);
  }
}

void blue()
{
  sprintf(printBuffer, "%d blue", randomNumber);
  Serial.println(printBuffer);
  for (int i = 0; i < numLed; i++)
  {
    leds[i].setRGB(0, 223, 252);
    FastLED.show();
    FastLED.delay(70);
  }
}

void clearLight()
{
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
}

void flashLight()
{
  sprintf(printBuffer, "%d flashLight", randomNumber);
  Serial.println(printBuffer);
  fill_solid(leds, NUM_LEDS, CRGB(255, 255, 255));
  FastLED.show();
}

void lightning()
{
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  FastLED.delay(2000);
  fill_solid(leds, NUM_LEDS, CRGB(255, 255, 255));
  FastLED.show();
  FastLED.delay(100);
  fill_solid(leds, NUM_LEDS, CRGB(0, 223, 252));
  FastLED.show();
  FastLED.delay(300);
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  FastLED.delay(400);
  fill_solid(leds, NUM_LEDS, CRGB(255, 255, 255));
  FastLED.show();
  FastLED.delay(300);
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
}

void randomSectionBlue__test()
{
  int i = sectionStart = random(18);
  sectionEnd = random(16);
  speed = random(5) + 1;
  sprintf(printBuffer, "%d randomSectionBlue --st = %d --end = %d : speed = %d", randomNumber, sectionStart, sectionEnd, speed * 15);
  Serial.println(printBuffer);
  int end = sectionStart + sectionEnd;
  FastLED.delay(2000);

  while (i < sectionStart + sectionEnd)
  {
    leds[i].setRGB(0, 223, 252);
    FastLED.show();
    FastLED.delay(15 * speed);
    sprintf(printBuffer, "%d", i);
    Serial.println(printBuffer);
    i++;
  }
  FastLED.delay(1800);
  clearLight();
}

void randomSectionBlue()
{
  for (int i = 0; i < 5; i++){
    int rnd = random(3);
    switch (rnd)
    {
    case 0:
      FastLED.delay(1000);
      for (int i = 3; i < 15; i++)
      {
        leds[i].setRGB(0, 223, 252);
        FastLED.show();
        FastLED.delay(50);
      }
      FastLED.delay(1500);
      clearLight();
      break;
    case 1:
      FastLED.delay(2000);
      for (int i = 15; i < 25; i++)
      {
        leds[i].setRGB(0, 223, 252);
        FastLED.show();
        FastLED.delay(60);
      }
      FastLED.delay(1500);
      clearLight();
      break;
    case 2:
      FastLED.delay(2000);
      for (int i = 7; i < 25; i++)
      {
        leds[i].setRGB(0, 123, 152);
        FastLED.show();
        FastLED.delay(100);
      }
      FastLED.delay(1500);
      clearLight();
      break;
    case 3:
      FastLED.delay(2000);
      for (int i = 10; i < 27; i++)
      {
        leds[i].setRGB(255, 223, 252);
        FastLED.show();
        FastLED.delay(50);
      }
      FastLED.delay(1500);
      clearLight();
      break;
    default:
      break;
    }
  }
}

void setup()
{
  Serial.begin(9600);
  delay(10000);
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop()
{
  randomNumber = random(5);
  switch (randomNumber)
  {
  case 0:
    sprintf(printBuffer, "%d case 0 lightning", randomNumber);
    Serial.println(printBuffer);
    lightning();
    FastLED.delay(4000);
    blue();
    clearLight();
    FastLED.delay(2000);
    break;
  case 1:
    sprintf(printBuffer, "%d Lightning", randomNumber);
    Serial.println(printBuffer);
    lightning();
    FastLED.delay(4000);
    blue();
    clearLight();
    FastLED.delay(2000);
    break;
  case 2:
    flashLight();
    FastLED.delay(2000);
    clearLight();
    FastLED.delay(2000);
    randomSectionBlue();
    FastLED.delay(3300);
    clearLight();
    break;
  case 3:
    blue();
    break;
  case 4:
    yellow();
    clearLight();
    FastLED.delay(1000);
    randomSectionBlue();
    FastLED.delay(1500);
    break;
  case 5:
    randomSectionBlue();
    FastLED.delay(1500);
    break;
  default:
    break;
  }
}