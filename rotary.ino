#include <LiquidCrystal.h>

/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 #define outputA 7
 #define outputB 6
 double FRS;
 int counter; 
 int aState;
 int lstCounter;
 int aLastState;
 unsigned long lstMillisec; 
 boolean ifTrue = true;
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA);   
   lcd.begin(16, 2);
 } 
 void loop() { 
   
   aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
     
     
     
     
     
     }
     if (ifTrue){
      lstMillisec = millis();
      lstCounter = counter;
      ifTrue = false;
     }
     if (millis() - lstMillisec >= 200)
     {
      lcd.clear();
      FRS = (abs(counter - lstCounter) / 40)*5;
      lcd.print(String("R/S: ") + FRS); 
      ifTrue = true;
      
     }
     aLastState = aState; // Updates the previous state of the outputA with the current state
     
 
   } 
   
 
