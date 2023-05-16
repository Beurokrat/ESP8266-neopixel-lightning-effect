#include <FastLED.h>
#define LED_PIN D4
#define NUM_LEDS 100

CRGB leds[NUM_LEDS];

int randomNumber;
int sectionStart, sectionEnd;
int speed;
int numLed = 50;
char printBuffer[30];

// ( RED, BLUE, GREEN)

void yellow()
{
  FastLED.delay(100);
  for (int i = 30; i > 0; i--)
  {
    leds[i].setRGB(253, 35, 208);
    FastLED.show();
    FastLED.delay(30);
  }
  FastLED.delay(400);
  FastLED.delay(100);
  for (int i = 30; i > 0; i--)
  {
    leds[i].setRGB(0, 0, 0);
    FastLED.show();
    FastLED.delay(13);
  }
}

void blue()
{
  sprintf(printBuffer, "%d blue", randomNumber);
  Serial.println(printBuffer);
  for (int i = 8; i < 25; i++)
  {
    leds[i].setRGB(253, 35, 208);
    FastLED.show();
    FastLED.delay(30);
  }
  for (int i = 8; i < 25; i++)
  {
    for(int j= 0 ; j<11;j++)
      leds[i+j].setRGB(0, 0, 0);
    leds[i].setRGB(0, 223, 0);
    FastLED.show();
    FastLED.delay(30);
  }
  FastLED.delay(300);
  clearLight();
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
  for (int i = 0; i > numLed; i++)
    leds[i].setRGB(255, 255, 255);
  FastLED.show();
  FastLED.delay(500);
}

void lightning()
{
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  FastLED.delay(2000);
  fill_solid(leds, NUM_LEDS, CRGB(130, 130, 130));
  FastLED.delay(120);
  fill_solid(leds, NUM_LEDS, CRGB(70, 70, 70));
  FastLED.show();
  FastLED.delay(80);
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  FastLED.delay(200);
  fill_solid(leds, NUM_LEDS, CRGB(130, 130, 130));
  FastLED.show();
  FastLED.delay(130);
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
}


int t = 0;
void randomSectionBlue()
{
  for (int i = 0; i < 6; i++)
  {
    int rnd = random(4);
    sprintf(printBuffer, "%d randomSectionBlue", rnd);
    Serial.println(printBuffer);
    if (rnd != t)
    {
      switch (rnd)
      {
      case 0:
        FastLED.delay(1000);
        for (int i = 8; i >= 0; i--)
        {
          leds[i].setRGB(0, 223, 252);
          FastLED.show();
          FastLED.delay(20);
        }
        FastLED.delay(300);
        clearLight();
        FastLED.delay(70);
        for (int i = 8; i >= 0; i--)
          leds[i].setRGB(0, 223, 252);
        FastLED.show();
        FastLED.delay(50);
        clearLight();
        FastLED.delay(40);
        for (int i = 8; i >= 0; i--)
          leds[i].setRGB(0, 223, 252);
        FastLED.show();
        FastLED.delay(50);
        clearLight();
        break;
      case 1:
        FastLED.delay(1000);
        for (int i = 0; i < 6; i++)
        {
          leds[25 + i].setRGB(0, 123, 152);
          leds[25 - i].setRGB(0, 123, 152);
        }
        FastLED.show();
        FastLED.delay(500);
        clearLight();
        FastLED.delay(70);
        for (int i = 0; i < 6; i++)
        {
          leds[25 + i].setRGB(125, 123, 152);
          leds[25 - i].setRGB(125, 123, 152);
        }
        FastLED.show();
        FastLED.delay(50);
        clearLight();
        FastLED.delay(30);
        for (int i = 0; i < 6; i++)
        {
          leds[25 + i].setRGB(0, 123, 152);
          leds[25 - i].setRGB(0, 123, 152);
        }
        FastLED.show();
        FastLED.delay(50);
        clearLight();
        break;
      case 2:
        FastLED.delay(2000);
        for (int i = 0; i < 8; i++)
        {
          leds[i].setRGB(253, 35, 208);
          leds[40 + i].setRGB(253, 35, 208);
          leds[40 - i].setRGB(253, 35, 208);
          FastLED.show();
          FastLED.delay(35);
        }
        FastLED.delay(600);
        clearLight();
        FastLED.delay(80);
        for (int i = 0; i < 8; i++)
        {
          leds[i].setRGB(253, 35, 208);
          leds[40 + i].setRGB(253, 200, 208);
          leds[40 - i].setRGB(253, 200, 208);
        }
        FastLED.show();
        FastLED.delay(130);
        clearLight();
        break;
      case 3:
        FastLED.delay(2000);
        for (int i = 13; i < 24; i++)
        {
          leds[i].setRGB(255, 223, 252);
          FastLED.show();
          FastLED.delay(30);
        }
        FastLED.delay(500);
        clearLight();
        FastLED.delay(70);
        for (int i = 13; i < 24; i++)
          leds[i].setRGB(255, 223, 252);
        FastLED.show();
        FastLED.delay(130);
        clearLight();
        break;
      default:
        break;
      }
      t = rnd;
    }
    else
    {
      i = i - 1;
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
  switch (4)
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
    blue();
    FastLED.delay(3500);
    yellow();
    FastLED.delay(3500);
    randomSectionBlue();
    FastLED.delay(3500);
    lightning();
    FastLED.delay(3000);
    break;
  case 5:
    randomSectionBlue();
    FastLED.delay(1500);
    break;
  default:
    break;
  }
}