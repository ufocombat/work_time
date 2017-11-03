#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL, 8);

//extern uint8_t SmallFont[];
extern uint8_t BigNumbers[];

bool flag = false;
int incomingByte = 0;
  char x;
  String s;

void setup()
{
  myOLED.begin();
  myOLED.setFont(BigNumbers);
//  myOLED.setFont(SmallFont);  

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0) {  
    s  = "";
    while (Serial.available()>0)
    {
      incomingByte = Serial.read();
      //Serial.print("I received: ");
      //Serial.println(incomingByte, DEC);      

      if (incomingByte==41){s  = "";}
      else
      {  
        x = incomingByte;
        s += String(x);
      }
    }
  }
  
  myOLED.clrScr();
  myOLED.print(s.substring(0,4),10,10);  
  myOLED.update();
  delay(1000);
}


        


