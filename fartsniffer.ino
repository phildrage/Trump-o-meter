#include "Adafruit_CCS811.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 32    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
Adafruit_CCS811 ccs;

//personal best setup
uint16_t pb=0;
uint16_t last_fart=0;
int fart_reg = 0;
int remap = 0;
uint16_t fart_now = 0;
void setup() 
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize with the I2C addr 0x3C (128x64)
  delay(500);
  display.clearDisplay();
  display.setCursor(20, 10);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("Fartsniffer 5000");
  display.setCursor(25, 20);
  display.setTextSize(1);
  display.print("Initializing");
  display.display();
 
  Serial.println("CCS811 test");
 
  if (!ccs.begin()) 
  {
    Serial.println("Failed to start sensor! Please check your wiring.");
    while (1);
  }
 
  // Wait for the sensor to be ready
  while (!ccs.available());
}
 
void loop() 
{
  if (ccs.available()) 
  {
    if (!ccs.readData()) 
    {
//      Serial.print("CO2: ");
//      Serial.print(ccs.geteCO2());
      Serial.print("ppm, TVOC: ");
      Serial.println(ccs.getTVOC());

      fart_now = ccs.getTVOC();
      if (fart_now>pb){
        pb = fart_now;
      }


      if (fart_now < 100){
      display.clearDisplay();
      display.setTextSize(1);             // smallest text size
      display.setCursor(0, 0);             // top left corner
      display.print("Fart level:");
      display.print(fart_now);            // immediate value
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);
      display.setCursor(0, 20);
      display.print("Previous best:");
      display.print(pb);
      display.display();
      if (fart_reg >= 0){                 // currently in level 0, so if its higher than 0, it falling.
        fart_reg = 0;
      }
      }


      if ((fart_now >= 100) && (fart_now <= 200)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);
      display.setCursor(0, 20);
      display.print("Fart Detected");
      display.display();
      if (fart_reg >= 1){                 // if the fart register is higher than 1, the level is falling so do nothing
        
      }else{
        last_fart = fart_now;             // if its not, save this one as the last fart
        fart_reg = 1;                     // and reset the register to this level

      }
      }

 if ((fart_now >= 200) && (fart_now <= 400)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("You dirty bastard");
      display.display();
      if (fart_reg >= 2){
        
      }else{
        last_fart = fart_now;
        fart_reg = 2;
      }
      }

 if ((fart_now >= 400) && (fart_now <= 500)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("You dropped one?");
      display.display();
            if (fart_reg > 3){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 3;
      }
      }

 if ((fart_now >= 500) && (fart_now <= 600)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("Oof, honking.");
      display.display();
      if (fart_reg > 4){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 4;
      }
      }

 if ((fart_now >= 600) && (fart_now <= 700)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("Fuck me, man");
      display.display();
      if (fart_reg > 5){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 5;
      }
      }


 if ((fart_now >= 700) && (fart_now <= 800)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("Jesus christ!");
      display.display();
      if (fart_reg > 6){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 6;
      }
      }
 if ((fart_now >= 800) && (fart_now <= 900)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("huuuugh");
      display.display();
      if (fart_reg > 7){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 7;
      }
      }

 if ((fart_now >= 900) && (fart_now <= 1000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("Fuckin dirt bag");
      display.display();
      if (fart_reg > 8){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 8;
      }
      }

 if ((fart_now >= 1000) && (fart_now <= 2000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("open a fucking window");
      display.display();
      if (fart_reg > 9){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 9;
      }
      }
 if ((fart_now >= 2000) && (fart_now <= 3000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("light a match");
      display.display();
      if (fart_reg > 10){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 10;
      }
      }
 if ((fart_now >= 3000) && (fart_now <= 4000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("smells like death");
      display.display();
      if (fart_reg > 11){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 11;
      }
      }
 if ((fart_now >= 4000) && (fart_now <= 5000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("Rank");
      display.display();
      if (fart_reg > 12){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 12;
      }
      }
 if ((fart_now >= 5000) && (fart_now <= 6000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("The fuck have you eaten");
      display.display();
      if (fart_reg > 13){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 13;
      }
      }
 if ((fart_now >= 6000) && (fart_now <= 7000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("Wow.");
      display.display();
      if (fart_reg > 14){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 14;
      }
      }
 if ((fart_now >= 7000) && (fart_now <= 8000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("Nice");
      display.display();
      if (fart_reg > 15){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 15;
      }
      }
 if ((fart_now >= 8000) && (fart_now <= 9000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("Summer meadows");
      display.display();
      if (fart_reg > 16){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 16;
      }
      }
 if ((fart_now >= 9000) && (fart_now <= 10000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("my eyes are bleeding");
      display.display();
      if (fart_reg > 17){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 17;
      }
      }
 if ((fart_now >= 10000) && (fart_now <= 12000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("I can't breathe");
      display.display();
      if (fart_reg > 18){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 18;
      }
      }
 if ((fart_now >= 12000) && (fart_now <= 14000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("you ok mate?");
      display.display();
      if (fart_reg > 19){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 19;
      }
      }
 if ((fart_now >= 14000) && (fart_now <= 16000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("summat wrong with you");
      display.display();
      if (fart_reg > 20){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 20;
      }
      }
 if ((fart_now >= 16000) && (fart_now <= 18000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("open a window quick!");
      display.display();
      if (fart_reg > 21){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 21;
      }
      }
 if ((fart_now >= 18000) && (fart_now <= 20000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("I'm dying!");
      display.display();
      if (fart_reg > 22){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 22;
      }
      }
 if ((fart_now >= 20000) && (fart_now <= 22000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("bit wet");
      display.display();
      if (fart_reg > 23){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 23;
      }
      }
 if ((fart_now >= 22000) && (fart_now <= 24000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("courtesy wipe?");
      display.display();
      if (fart_reg > 24){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 24;
      }
      }
 if ((fart_now >= 24000) && (fart_now <= 29000)){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("speak up Mr Brown");
      display.display();
      if (fart_reg > 25){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 24;
      }
      }
 if (fart_now >= 29000){
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.print("Fart level:");
      display.print(fart_now);
      display.setCursor(0, 10);
      display.print("Last stinker:");
      display.print(last_fart);      
      display.setCursor(0, 20);
      display.print("High score!Rotten cunt!");
      display.display();
      
      if (fart_reg > 25){
        
      }else if (fart_now >= last_fart){
        last_fart = fart_now;
        fart_reg = 25;
      }
      }
 
    }
    else 
    {
      Serial.println("ERROR!");
      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0, 5);
      display.print("ERROR!");
      while (1);
    }
  }
  delay(1000);
}
