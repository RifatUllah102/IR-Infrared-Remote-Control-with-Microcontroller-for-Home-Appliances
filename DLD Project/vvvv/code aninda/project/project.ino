#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>
Servo servo1;

int pos1=0;
String pass = "1234";
String userPass = "";
const byte ROWS = 4; //four rows
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
LiquidCrystal lcd(13,12,11,10,9,8);
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5,4}; //connect to the column pinouts of the keypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
pinMode(A0, OUTPUT);
pinMode(A1, OUTPUT);
servo1.write(pos1);
servo1.attach(A2);
lcd.begin(16,2);
lcd.print("Enter password");
lcd.setCursor(0,1);
}

void loop() {
  // put your main code here, to run repeatedly:

  char customKey = customKeypad.getKey();
  if (customKey){
    if(customKey =='#')
  {
    lcd.clear();
    lcd.setCursor(0,0);
    if(userPass == pass){
      digitalWrite(A1, HIGH);
      digitalWrite(A0, LOW);
      userPass ="";
      lcd.print(".....welcome....");
      for(pos1 = 0;pos1<=95;pos1++)
      {
        servo1.write(pos1);
       delay(10);
       
        }
      }
      else if(userPass != pass){
         digitalWrite(A0, HIGH);
        digitalWrite(A1, LOW);
      lcd.print("Wrong Password ");
      lcd.setCursor(0,1);
      lcd.print("Try again");
      userPass ="";
      delay(3000);
      lcd.clear();
      lcd.print("Enter password");
      lcd.setCursor(0,1);
      }
    //lcd.print(userPass);
  }else{
    //Serial.println(customKey);
    userPass += customKey;
    //lcd.print(customKey);
    lcd.print("*");
  }
  }
}
