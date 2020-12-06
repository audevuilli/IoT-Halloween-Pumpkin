/*** Color LEDs -- Define Function previously use by Blynk ***/

/* Wheel - Rainbow Color */
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

/* Rainbow Color around the wheel */ 
void rainbow(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256; j++) {
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}
/* Harlequin - Green */ 
void Harlequin(){
  uint16_t i;
  for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i,  pixels.Color(63,255,0));
    }
    pixels.show();
}
/* Razzle Dazzzle - Pink */ 
void RazzleDazzleRose(){
  uint16_t i;
  for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i,  pixels.Color(255,51,205));
    }
    pixels.show();
}
/* Pumpkin - Orange */
void Pumpkin(){
  uint16_t i;
  for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i,  pixels.Color(255,117,24));
    }
    pixels.show();
}
/* Vivid Sky - Blue */
void VividSky(){
  uint16_t i;
  for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i,  pixels.Color(0,204,255));
    }
    pixels.show();
}
/* Twinkle - Random Colors */
void TwinkleRandom(int Count, int SpeedDelay){
  for (int j=0; j<Count; j++) {
    uint16_t i;
    for (int i=0; i<pixels.numPixels(); i++) {
    pixels.setPixelColor(i,random(0,255),random(0,255),random(0,255));
    pixels.show();
    delay(SpeedDelay);
    }
  }
  delay(SpeedDelay);
}
