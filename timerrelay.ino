#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int worktime = 900 ;
int startdelaytime = 0 ;
int SwitchButton = 4;
int Relay = 5;
int change =0;
void lcdupdate(){
   lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Time: ");
    lcd.print(worktime/60);
  lcd.print(":");
  lcd.print(worktime%60);
  lcd.setCursor(0,1);
  lcd.print("Delay: 0:");
  lcd.print(startdelaytime);
}
void lcdupdateW(){
   lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Time: ");
    lcd.print(worktime/60);
  lcd.print(":");
  lcd.print(worktime%60);
  lcd.setCursor(0,1);
  lcd.print("Working");
}
void interruptwork() 
{

if (worktime<3600){

  worktime=worktime+900;
}
else{

  worktime=900;
}
change=1;
  }
void interruptstartdelay() 
{

if (startdelaytime<60){

  startdelaytime=startdelaytime+30;
}
else{

  startdelaytime=0;
}

 change=1;
  }
void setup() {
  attachInterrupt(0,interruptwork,RISING);
  attachInterrupt(1,interruptstartdelay,RISING);
  pinMode(SwitchButton, INPUT_PULLUP);
  pinMode(Relay, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Time: ");
  lcd.print(worktime/60);
  lcd.print(":");
  lcd.print(worktime%60);
  lcd.setCursor(0,1);
  lcd.print("Delay: 0:");
  lcd.print(startdelaytime);
  Serial.begin(9600);


}

void loop() {
  while((digitalRead(SwitchButton)==0)){
    if ((startdelaytime==0)&&(worktime>0)){
      digitalWrite(Relay, HIGH);
      worktime=worktime-1;
      lcdupdateW();
    }
    else{
      digitalWrite(Relay, LOW);
      if (worktime==0){
        lcd.clear();
        lcd.setCursor(0,1);
        lcd.print("Finished");
      }
      if (worktime!=0){
      startdelaytime=startdelaytime-1;
      lcdupdate();
      }
    }
    delay(1000);
  }
     digitalWrite(Relay, LOW);
     if (change==1){
     lcdupdate();
     change=0;
     }
    }
