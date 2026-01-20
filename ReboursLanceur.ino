/* 
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /        __________   _________   ___________   __________    _________                             /
   /       /___   ___/  /   _____/  /  _____   /  /  _____   \  /  ______/       \\          //        /
   /          /  /     /  /        /  /    /  /  /  /    /  /  /  /_____        \\            //       /
   /         /  /     /  /        /  /____/  /  /  /___/  /   /  ______/   \\\   \\    []    //   ///  /
   /     ___/  /__   /  /_____   /   ____   /  /   ___   \   /  /_____        \\\\--]]]/\[[[--////     /
   /    /________/  /________/  /__/    /__/  /__/    \__/  /________/         /////--][][--\\\\\      /
   /                                                                         //   //--][][--\\   \\    /
   /   ______________________________________________________________           //    ][][    \\       /
   /                                                                                                   /
   /                                                                                                   /
   /  This program is free software for arduino; you can redistribute it and/or modify.                /
   /  Ce programme pour Arduino est libre et gratuit; vous pouvez le distribuez et/ou le modifier.     /
   /                                                                                                   /
   / Auteurs:                                                                                          /
   / -Nicolas Colin                                                                                    /
   / -Zacharie Beaumont                                                                                /
   / Another codes / Autres codes:                                                                     /
   / https://www.icaremaker.com                                                                        /
   / Mail: ionocraft@hotmail.fr                                                                        /
   /////////////////////////////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////////////////////////////
*/

#include"LedControl.h"

LedControl lc=LedControl(13,12,11,1);  // Pins: DIN,CLK,CS, # of Display connected

// constantes
const int buttonPin = 2;
unsigned long delayTime=1000;

// variables
int buttonState = 1; 
int score;
int Result=9;
bool verrou = LOW;

    
void setup() {
  //Setup du bouton poussoir
  
  pinMode(buttonPin, INPUT_PULLUP);
  //Setup de l'afficheur 8x8
  lc.shutdown(0,false);  // Affichage de réveil
  lc.setIntensity(0,1);  // Niveau d'intensité lumineuse
  lc.clearDisplay(0);    // Affichage clair

  NEUF();
  score = 9;
  

  Serial.begin(9600);
}

void loop() {
  
  // Lire l'etat du bouton poussoir
  buttonState = digitalRead(buttonPin);

  // Selon l'etat du bouton, j'active qqchose
    if ((buttonState == LOW) and (verrou == LOW)){
    verrou = HIGH;
    } 
  
  
  if (verrou == HIGH){
 NEUF();
score = 9;
delay(delayTime);
HUIT();
score = 8;
delay(delayTime);
SEPT();
score = 7;
delay(delayTime);
SIX();
score = 6;
delay(delayTime);
CINQ();
score = 5;
delay(delayTime);
QUATRE();
score = 4;
delay(delayTime);
TROIS();
score = 3;
delay(delayTime);
DEUX();
score = 2;
delay(delayTime);
UN();
score = 1;
delay(delayTime);
ZERO();
score = 0;
verrou = LOW;
delay(delayTime);
}
}

void NEUF()
{
	byte image9[] =
{
  B00000000,   
   B01000110,
   B11001111,
   B10001001,
   B10001001,
   B11111111,
   B01111110,
   B00000000
};

  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,image9[i]);
  }
}
 
void HUIT()
{
  byte image8[] =
{
   B00000000,  
   B01100110,
   B11111111,
   B10001001,
   B10010001,
   B11111111,
   B01100110,
   B0000000
};
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image8[i]);
  }
}
 
void SEPT()
{
  byte image7[] =
{
   B00000000,  
   B00000001,
   B00000001,
   B11100001,
   B11111001,
   B00011111,
   B00000111,
   B00000000
};
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image7[i]);
  }
}

void SIX()
{
  byte image6[] =
{
   B00000000,   
   B01111110,
   B11111111,
   B10010001,
   B10010001,
   B11110011,
   B01100010,
   B00000000
};
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image6[i]);
  }
}

void CINQ()
{
  byte image5[] =
{
   B00000000,  
   B01001111,
   B11001111,
   B10001001,
   B10001001,
   B11111001,
   B01110001,
   B00000000
};
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image5[i]);
  }
}

void QUATRE()
{
	byte image4[] =
{
   B00000000,  
   B00011110,
   B00011111,
   B00010000,
   B11111100,
   B11111100,
   B00010000,
   B00000000
};

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image4[i]);
  }
}

void TROIS()
{
	byte image3[] =
{
  B00000000,   
   B01000010,
   B11000011,
   B10000001,
   B10001001,
   B11111111,
   B01110110,
   B00000000
};

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image3[i]);
  }
}

void DEUX()
{
	byte image2[] =
{
  B00000000,   
   B10000010,
   B11000011,
   B11110001,
   B10111001,
   B10011111,
   B10001110,
   B00000000
};

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image2[i]);
  }
}

void UN()
{
	byte image1[] =
{
   B00000000,  
   B00000000,
   B10000100,
   B11111110,
   B11111111,
   B10000000,
   B00000000,
   B00000000
};

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image1[i]);
  }
}

void ZERO()
{
	byte image0[] =
{
   B00000000,  
   B01111110,
   B11111111,
   B10110001,
   B10011001,
   B11111111,
   B01111110,
   B00000000
};

  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,image0[i]);
  }
  {

  }
}

