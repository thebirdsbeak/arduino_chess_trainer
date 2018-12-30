#include <FastLED.h>
#define NUM_LEDS 64
#define DATA_PIN 3
#define BRIGHTNESS 32
CRGB leds[NUM_LEDS];

#define A1 0
#define B1 1
#define C1 2
#define D1 3
#define E1 4
#define F1 5
#define G1 6
#define H1 7
#define H2 8
#define G2 9
#define F2 10
#define E2 11
#define D2 12
#define C2 13
#define B2 14
#define A2 15
#define A3 16
#define B3 17
#define C3 18
#define D3 19
#define E3 20
#define F3 21
#define G3 22
#define H3 23
#define H4 24
#define G4 25
#define F4 26
#define E4 27
#define D4 28
#define C4 29
#define B4 30
#define A4 31
#define A5 32
#define B5 33
#define C5 34
#define D5 35
#define E5 36
#define F5 37
#define G5 38
#define H5 39
#define H6 40
#define G6 41
#define F6 42
#define E6 43
#define D6 44
#define C6 45
#define B6 46
#define A6 47
#define A7 48
#define B7 49
#define C7 50
#define D7 51
#define E7 52
#define F7 53
#define G7 54
#define H7 55
#define H8 56
#define G8 57
#define F8 58
#define E8 59
#define D8 60
#define C8 61
#define B8 62
#define A8 63

#define K 0xFF0000
#define Q 0xFF44DD
#define N 0x00FF00
#define B 0xFFFF00
#define R 0x0000FF
#define P 0xFFFFFF
#define k 0xFF0000
#define q 0xFF44DD
#define n 0x00FF00
#define b 0xFFFF00
#define r 0x0000FF
#define p 0xFFFFFF

  int startpieces[16] = {A1, B1, C1, D1, E1, F1, G1, H1, A8, B8, C8, D8, E8, F8, G8, H8};
  long pieces[16] = {R, N, B, Q, K, B, N, R, r, n, b, q, k, b, n, r};
  
  int startpawns [16] = {A2, B2, C2, D2, E2, F2, G2, H2, A7, B7, C7, D7, E7, F7, G7, H8};
  long pawns[16] = {P, P, P, P, P, P, P, P, p, p, p, p, p, p, p, p};

void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS );
  Serial.begin(9600);

  for(int i = 0; i < 16; i++) { 
      int square = startpawns[i];
      long piece = pawns[i];
      setSquare(square, piece);
  }
  for(int i = 0; i < 16; i++) { 
      int square = startpieces[i];
      long piece = pieces[i];
      setSquare(square, piece);
  }
}

void setSquare(int square, long piece) {
leds[square] = piece;
      FastLED.show();
}


void loop() {
    }
   
