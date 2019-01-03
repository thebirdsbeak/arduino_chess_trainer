/* 
 * Chess openings played on 8x8 RGB display 
 * (c) Craig McIntyre 2018
 * Licensed under the Unlicense (see LICENCE.TXT) 
 */


// Set up using FastLED library (thanks!)
#include <FastLED.h>
#define NUM_LEDS 64
#define DATA_PIN 3
#define BRIGHTNESS 24
CRGB leds[NUM_LEDS];

// Board names (could use just the number, but easier to type out coords)
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

// Piece colours
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

// Piece position variables
  long white[16][2] = {
  {R, A1}, {N, B1}, {B, C1}, {Q, D1}, {K, E1}, {B, F1}, {N, G1}, {R, H1},
  {P, A2}, {P, B2}, {P, C2}, {P, D2}, {P, E2}, {P, F2}, {P, G2}, {P, H2}
  };
  
  long black[16][2] = {
  {R, A8}, {N, B8}, {B, C8}, {Q, D8}, {K, E8}, {B, F8}, {N, G8}, {R, H8},
  {P, A7}, {P, B7}, {P, C7}, {P, D7}, {P, E7}, {P, F7}, {P, G7}, {P, H7}
  };


// Sets the board back to original position
void originalPos() {
  white[0][1] = A1;
  white[1][1] = B1;
  white[2][1] = C1;
  white[3][1] = D1;
  white[4][1] = E1;
  white[5][1] = F1;
  white[6][1] = G1;
  white[7][1] = H1;
  white[8][1] = A2;
  white[9][1] = B2;
  white[10][1] = C2;
  white[11][1] = D2;
  white[12][1] = E2;
  white[13][1] = F2;
  white[14][1] = G2;
  white[15][1] = H2;
  black[0][1] = A8;
  black[1][1] = B8;
  black[2][1] = C8;
  black[3][1] = D8;
  black[4][1] = E8;
  black[5][1] = F8;
  black[6][1] = G8;
  black[7][1] = H8;
  black[8][1] = A7;
  black[9][1] = B7;
  black[10][1] = C7;
  black[11][1] = D7;
  black[12][1] = E7;
  black[13][1] = F7;
  black[14][1] = G7;
  black[15][1] = H7;
  updateBoard();
  delay(2000);  
}


void setup() { 
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness( BRIGHTNESS );
  Serial.begin(9600);

  for(int i = 0; i < 16; i++) { 
      long piece = white[i][0];
      int square = white[i][1];
      setSquare(square, piece);
  }

  for(int i = 0; i < 16; i++) { 
      long piece = black[i][0];
      int square = black[i][1];
      setSquare(square, piece);
  }
}


void setSquare(int square, long piece) {
  leds[square] = piece;
  FastLED.show();
}

void flashBlack() {

for(int x = 0; x < 4; x++) {
  for(int i = 0; i < 16; i++) {
    int var = black[i][1];
    leds[var] = CRGB::Black;
    FastLED.show();
  }  

  delay(500);
  
  for(int i = 0; i < 16; i++) {
      long piece = black[i][0];
      int square = black[i][1];
      setSquare(square, piece);
  }

  delay(500);
}
}

void updateBoard() {
  for(int i = 0; i < 64; i++) {
    leds[i] = CRGB::Black;;
  }

  delay(250);
  
  for(int i = 0; i < 16; i++) { 
    long piece = white[i][0];
    int square = white[i][1];
    setSquare(square, piece);
  }

  for(int i = 0; i < 16; i++) { 
    long piece = black[i][0];
    int square = black[i][1];
    setSquare(square, piece);
  }

  delay(1000);
  flashBlack();
}


void ruyLopez() {
  
  white[12][1] = E4;
  updateBoard();
  black[12][1] = E5;
  updateBoard();

  white[6][1] = F3;
  updateBoard();
  black[1][1] = C6;
  updateBoard();

  white[5][1] = B5;
  updateBoard();
  black[8][1] = A6;
  updateBoard();
}


void giuocoPiano() {

  white[12][1] = E4;
  updateBoard();
  black[12][1] = E5;
  updateBoard();

  white[6][1] = F3;
  updateBoard();
  black[1][1] = C6;
  updateBoard();

  white[5][1] = C4;
  updateBoard();
  black[5][1] = C5;
  updateBoard();

  white[9][1] = B4;
  updateBoard();  
}


void sicilianDragon() {

  white[12][1] = E4;
  updateBoard();
  black[10][1] = C5;
  updateBoard();

  white[6][1] = F3;
  updateBoard();
  black[11][1] = D6;
  updateBoard();

  white[11][1] = D4;
  updateBoard();
  black[10][1] = D4;
  white[11][1] = 0;
  updateBoard();

  white[6][1] = D4;
  black[10][1] = 0;
  updateBoard();
  black[6][1] = F6;
  updateBoard();
  
  white[1][1] = C3;
  updateBoard;
  black[14][1] = G6;
  updateBoard;
}


void loop() {
  ruyLopez();
  originalPos();
  giuocoPiano();
  originalPos();
  sicilianDragon();
  originalPos();
}
   
