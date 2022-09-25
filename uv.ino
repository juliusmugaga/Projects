//UV Project 
//UV stands for Ultraviolent light, and in this project we are using UV C to prevent infection spread in hospital wards and theatre rooms. 
//This project was funded by the Government of Uganda through the Ministry of Science Technology and Innovations with a bid to reduce the spread of hospital acquired infections, antimicrobial resistance and COVID-19. 
//This being an embedded systems project, I used C++ to develop a code that would manage all process
//First, we needed the system to be able to have a timely before turning on the UV  C bulbs when switched on to allow the operate exit the room since UV C light is hazardous and that is why it can kill microbes. 
//A beeping alarm was included to provide notice to the operator 
//We also needed the system to detect motions using motion sensors and turn off the lights instantly if in case someone entered the room unknowingly 
//There was need for the system to operate both on battery and AC electricity supply. For this the system needed to charge the battery using AC and then the system draws power from the battery through the DC to DC converter. 

#include <LiquidCrystal.h>
#include <EEPROM.h>
const int rs = 11, en = 12, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int power =6;
// A5  left button
// A4 middle button
// A3 right button
// A2 power button

int m=1;
int k=0;
int t_go=0;
int display_once=1;
int sec=0;
int x=0;
int y=0;
int n=2;
int charge=13;
int inverter_relay=8;
int ac_relay=7;
int uv_status=0;
int hr_d1=0;
int hr_d2=0;
int min_d1=0;
int min_d2=0;
int go=0;
int uv_go =0;
int sec_d1=0;
int sec_d2=0;
int count1=0;
int d_1=0;
int d_2=0;
int d_3=0;
int d_4=0;
int d_5=0;
int d_6=0;
int d_7=0;
int d_8=0;
int dm2=0;
int dm1=0;
int sensor=0;
int clk;
float battery_volt=0;
float ac_volt=0;
int kill=0;
int timer=0;
 

void setup() {
pinMode(power,OUTPUT);
pinMode(inverter_relay,OUTPUT);
pinMode(ac_relay,OUTPUT);
pinMode(sensor,INPUT);
pinMode(clk,INPUT);

digitalWrite(power,1);



delay(2000);
lcd.begin(20, 4);
lcd.print("  UV SYS. STARTING  "); 
delay(1000);
lcd.clear();
dm1=EEPROM.read(1);
dm2=EEPROM.read(2);
d_1=EEPROM.read(3);
d_2=EEPROM.read(4);
d_3=EEPROM.read(5);
d_4=EEPROM.read(6);
d_5=EEPROM.read(7);
d_6=EEPROM.read(8);
d_7=EEPROM.read(9);
d_8=EEPROM.read(10);
  
}

void loop() {
  
battery_volt=analogRead(A0)*0.0123;
ac_volt=analogRead(A1)*0.0123;


if(digitalRead(clk)==1 and kill==0){
kill=1;
sec++;
lcd.begin(20, 4);

if(t_go==1){
 timer++; 
}
if(uv_go==1){
 sec_d1++; 
}
}

if(digitalRead(clk)==0 and kill==1){
kill=0;
sec++;
lcd.begin(20, 4);

if(t_go==1){
 timer++; 
}

if(uv_go==1){
 sec_d1++; 
}
}


if(sec_d1==10){
  sec_d1=0;
  sec_d2++;
}
if(sec_d2==6){
  sec_d2=0;
  min_d1++;
}
if(min_d1==10){
  min_d1=0;
  min_d2++;
}

if(min_d2==6){
  min_d2=0;
  hr_d1++;
}
if(hr_d1==10){
  hr_d1=0;
  hr_d2++;
  d_1++;
}
if(hr_d2==10){
  sec_d1=0;
  sec_d2=0;
  min_d1=0;
  min_d2=0;  
  hr_d1=0;
  hr_d2=0;
  
}

if(d_1==10){
d_1=0;
d_2++; 
}
if(d_2==10){
d_2=0;
d_3++; 
}
if(d_3==10){
d_3=0;
d_4++; 
}
if(d_4==10){
d_4=0;
d_5++; 
}
if(d_5==10){
d_5=0;
d_6++; 
}
if(d_6==10){
d_6=0;
d_6++; 
}
if(d_8==10){
d_1=0;
d_2=0; 
d_3=0;
d_4=0;
d_5=0;
d_6=0;
d_7=0;
d_8=0;
}




count1++;
if(count1==60){
 go=1; 
}
if(count1==120){
 go=0; 
 count1=0;
}





if(analogRead(A2)>100){ 
delay(200);
lcd.clear();
display_once=1;
m=2;
} 
 



  
if(m==1){

if(analogRead(A5)>100){ 
delay(200);  
n--;
lcd.clear();
}

if(analogRead(A3)>100){ 
delay(200); 
n++;
lcd.clear(); 
}

if(n==1){
n=6; 
}

if(n==7){
n=2; 
}


if(n==2){ 
if(k==0){
lcd.setCursor(0, 0);
lcd.print("      TURN UV      "); 
lcd.setCursor(0, 3);
} 

if(go==1 and k==0){
lcd.setCursor(0, 3);
lcd.print("<        ON        >"); 
}
if(go==0 and k==0){
lcd.setCursor(0, 3);
lcd.print("                    "); 
}          

if(analogRead(A4)>100){
delay(200);
lcd.clear();
k=1;
}

if(k==1){
lcd.setCursor(0, 2);
lcd.print("UV IS ABOUT TO START"); 
 
t_go=1;

if(timer==10){
k=0;
timer=0;
t_go=0;
lcd.clear();
m=3;
uv_go=1;
lcd.clear();
}

}
}
    



if(n==3){ 
lcd.setCursor(0, 0);
lcd.print("UP TIMER OF UV TUBES");  


if(go==1){
lcd.setCursor(0, 3);
lcd.print("<       ENTER      >"); 
}
if(go==0){
lcd.setCursor(0, 3);
lcd.print("                    "); 
}

if(analogRead(A4)>100){
delay(200);
m=4;
display_once=1;
lcd.clear();
}
} 

if(n==4){ 
lcd.setCursor(0, 0);
lcd.print("     HELP TIPS     "); 


if(go==1){
lcd.setCursor(0, 3);
lcd.print("<       SHOW       >"); 
}
if(go==0){
lcd.setCursor(0, 3);
lcd.print("                    "); 
}


if(analogRead(A4)>100){
delay(200);
lcd.clear();
lcd.setCursor(0, 2);
lcd.print(" NOT CONFIGURED YET ");   
delay(2000); 
lcd.clear();
}
}


if(n==5){ 
lcd.setCursor(0, 0);
lcd.print("   ABOUT SYSTEM     "); 

if(go==1){
lcd.setCursor(0, 3);
lcd.print("<       SHOW       >"); 
}
if(go==0){
lcd.setCursor(0, 3);
lcd.print("                    "); 
}

if(analogRead(A4)>100){
delay(200);
lcd.clear();
lcd.setCursor(0, 2);
m=6;
lcd.clear();
}

}

if(n==6){ 
lcd.setCursor(0, 0);
lcd.print("   BATTERY STATUS   "); 
if(battery_volt > 2){
lcd.setCursor(6, 2);
lcd.print("Volts"); 
}

if(battery_volt > 2){
lcd.setCursor(0, 2);
lcd.print(battery_volt); 
}else {
lcd.setCursor(0, 2);
lcd.print(" BATTERY IS MISSING ");  
}

if(go==1){
lcd.setCursor(0, 3);
lcd.print("<                  >"); 
}
if(go==0){
lcd.setCursor(0, 3);
lcd.print("                    "); 
}

}


}



if(m==2){
lcd.setCursor(0, 0);
lcd.print("  ARE YOU SURE YOU  ");
   
lcd.setCursor(0, 1);
lcd.print(" WANT TO POWER OFF? ");

if(go==1){
lcd.setCursor(0, 3);
lcd.print(" NO             YES ");
}
if(go==0){
lcd.setCursor(0, 3);
lcd.print("                    ");
}
 
if(analogRead(A3)>100){ 
lcd.clear();
lcd.setCursor(0, 1);
lcd.print("POWERING OFF SYSTEM"); 
EEPROM.update(1,dm1);
EEPROM.update(2,dm2);
EEPROM.update(3,d_1);
EEPROM.update(4,d_2);
EEPROM.update(5,d_3);
EEPROM.update(6,d_4);
EEPROM.update(7,d_5);
EEPROM.update(8,d_6);
EEPROM.update(9,d_7);
EEPROM.update(10,d_8);
delay(1000); 
digitalWrite(power,LOW);
}

if(analogRead(A5)>100){ 
m=1;
lcd.clear();
delay(200);
}
} 

if(m==3){
lcd.setCursor(0, 2);
lcd.print("UV TIMER "); 
lcd.setCursor(14,2 );
lcd.print(":"); 

lcd.setCursor(17,2 );
lcd.print(":"); 

if(go==1){ 
lcd.setCursor(0, 3);
lcd.print("                STOP"); 
}
if(go==0){ 
lcd.setCursor(0, 3);
lcd.print("                    "); 
}

lcd.setCursor(12,2);
lcd.print(hr_d2); 
lcd.setCursor(13, 2);
lcd.print(hr_d1); 

lcd.setCursor(15,2);
lcd.print(min_d2); 
lcd.setCursor(16, 2);
lcd.print(min_d1); 

lcd.setCursor(18, 2);
lcd.print(sec_d2); 
lcd.setCursor(19, 2);
lcd.print(sec_d1);




if(digitalRead(1)==HIGH){
 uv_go=0;
 digitalWrite(ac_relay,LOW);
 digitalWrite(inverter_relay,LOW);
}

if(digitalRead(1)==LOW){

  uv_go=1;

if(ac_volt > 6){
digitalWrite(ac_relay,HIGH);
digitalWrite(inverter_relay,LOW); 
}

if(ac_volt < 2 and battery_volt > 11){
digitalWrite(ac_relay,LOW);
digitalWrite(inverter_relay,HIGH); 
}
}

if(analogRead(A3)>100){
delay(200); 
digitalWrite(ac_relay,LOW);
digitalWrite(inverter_relay,LOW); 
uv_go=0;
sec_d1=0;
sec_d2=0;
dm1=min_d1;
dm2=min_d2;
min_d1=0;
min_d2=0;  
hr_d1=0;
hr_d2=0;
EEPROM.update(1,dm1);
EEPROM.update(2,dm2);
EEPROM.update(3,d_1);
EEPROM.update(4,d_2);
EEPROM.update(5,d_3);
EEPROM.update(6,d_4);
EEPROM.update(7,d_5);
EEPROM.update(8,d_6);
EEPROM.update(9,d_7);
EEPROM.update(10,d_8);
m=1;
n=2;
lcd.clear();
}

}

if(m==4){
lcd.setCursor(0, 0);
lcd.print("    UV UP TIME     ");

lcd.setCursor(8, 2);
lcd.print("Hrs. ");

lcd.setCursor(15, 2);
lcd.print("min.");

if(go==1){
lcd.setCursor(0, 3);
lcd.print("BACK          RESET"); 
}
if(go==0){
lcd.setCursor(0, 3);
lcd.print("                   "); 
}



lcd.setCursor(0, 2);
lcd.print(d_8);
lcd.setCursor(1, 2);
lcd.print(d_7);
lcd.setCursor(2, 2);
lcd.print(d_6);
lcd.setCursor(3, 2);
lcd.print(d_5);
lcd.setCursor(4, 2);
lcd.print(d_4);
lcd.setCursor(5, 2);
lcd.print(d_3);
lcd.setCursor(6, 2);
lcd.print(d_2);
lcd.setCursor(7, 2);
lcd.print(d_1); 
lcd.setCursor(13, 2);
lcd.print(dm2); 
lcd.setCursor(14, 2);
lcd.print(dm1);  

if(analogRead(A5)>100){
delay(200); 
m=1;
n=2;
lcd.clear();
display_once=1;
}

if(analogRead(A3)>100){
delay(200); 
m=5;
lcd.clear();
}

  
}


if(m==5){

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("  ARE YOU SURE YOU  ");
   
lcd.setCursor(0, 1);
lcd.print("WANT TO RESET TIMER?");


lcd.setCursor(0, 3);
lcd.print(" YES             NO ");

  
if(analogRead(A5)>100){
EEPROM.update(1,0);
EEPROM.update(2,0);
EEPROM.update(3,0);
EEPROM.update(4,0);
EEPROM.update(5,0);
EEPROM.update(6,0);
EEPROM.update(7,0);
EEPROM.update(8,0);
EEPROM.update(9,0);
EEPROM.update(10,0);
d_1=0;
d_2=0;
d_3=0;
d_4=0;
d_5=0;
d_6=0;
d_7=0;
d_8=0;
dm1=0;
dm2=0;
lcd.clear();
m=1;
n=2;
}

if(analogRead(A3)>100){
lcd.clear();
m=1;
n=2;  
}
  
}


if(m==6){
lcd.setCursor(0, 0);
lcd.print("RUN BY_ATMEGA328p  "); 
lcd.setCursor(0, 1);
lcd.print("CLOCKED AT 16MHertz");
lcd.setCursor(0, 2);
lcd.print("OS. _ MYMO.V.1.0   ");



if(go==1){
lcd.setCursor(0, 3);
lcd.print("                BACK"); 
}
if(go==0){
lcd.setCursor(0, 3);
lcd.print("                    "); 
}
if(analogRead(A3)>100){
delay(200);
m=1;
lcd.clear();
n=5;  
}

  
}


 
}
