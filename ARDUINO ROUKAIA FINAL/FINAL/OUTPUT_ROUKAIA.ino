#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS =4;
const byte COLS=3;
char keys[ROWS][COLS] = {

  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 4, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 const int buzzer = 9;


String password = "8888";
String mypassword;
int redled = 12;
int lock = 13;
int counter = 0;
int attempts = 0;

int max_attempts = 3;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(redled, OUTPUT);
  
  digitalWrite(redled, LOW);
  pinMode(buzzer, OUTPUT);
  lcd.begin();
  lcd.backlight();
  
}

void loop() {
  // put your main code here, to run repeatedly:
 keypadfunction();
  lcd.clear();
  lcd.print("Inserer Votre ID");
 lcd.setCursor (0,1); // go to start of 2nd line
 lcd.print(mypassword);
  //lcd.print(millis() / 1000);
  delay(500);
}
void keypadfunction()
{
   char key = keypad.getKey();
    if (key){
    Serial.println(key);
    counter = counter + 1; 
    }
      if (key == '1')
  {
 
    mypassword = mypassword + 1;   
  }
  
    if (key == '2')
  {
 
    mypassword = mypassword + 2;  
  }
  
  if (key == '3')
  {
 
    mypassword = mypassword + 3; 
  }
  
   if (key == '4')
  {
  
    mypassword = mypassword + 4;  
  }
  
  if (key == '5')
  {
  
    mypassword = mypassword + 5;
  }
  
   if (key == '6')
  {
   
    mypassword = mypassword + 6; 
  }
  
   if (key == '7')
  {
 
    mypassword = mypassword + 7; 
  }
 
   if (key == '8')
  {
 
    mypassword = mypassword + 8; 
  }
  
  if (key == '9')
  {
 
    mypassword = mypassword + 9;
  }
             
                 if (key == '0')
  {
 
    mypassword = mypassword + 0; 
  }
  
  
        if (key == '*')
  {
    Serial.println(mypassword); 
lcd.print(mypassword);
    if ( password != mypassword )
    
{
   lcd.clear();
  lcd.print("WRONG !");
 lcd.setCursor (0,1); // go to start of 2nd line
 lcd.print("Check ID !!");
  //lcd.print(millis() / 1000);
  delay(500);
  digitalWrite(lock, LOW);
  digitalWrite(redled, HIGH);
delay(10);
tone(buzzer, 500);
  delay(1000);
  noTone(buzzer);
  delay(100);
  attempts = attempts + 1; 
if (attempts >= max_attempts )
{
  digitalWrite(redled, HIGH);
delay(100); 
digitalWrite(redled, LOW); 
attempts = 0; 
}
mypassword = ""; 
counter = 0; 
}
else{ 
  lcd.clear();
  lcd.print("Welcome");
  lcd.setCursor (0,1);
  lcd.print("ENJOY !");
 delay(500);
  digitalWrite(redled,LOW);

digitalWrite(lock, HIGH);
delay(5000); 
digitalWrite(lock,LOW);

}
  }
}



   
