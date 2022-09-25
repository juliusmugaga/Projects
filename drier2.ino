
//Drier project
//The goal was to design a 5 ton food/briquettes drier for medium scale production.
//To automate the system, the machine was fitted with heaters, fans, and temperature and humidity sensors
//At the start of the operation, a dry run would be triggered to ensure that the heat blowing fan and the exhaust fan and window are working after loading
//The system can be time for the operation time and the access door is tightly locked 
//Throughout the operation, the system would automatically open and close the exhaust window to prevent, pressure, temperature and humidity build-up

#include "DHT.h"
#include <EEPROM.h>
#include <LiquidCrystal.h>

int address=0;
int countx=0;
int lock1=1;
int lock2=1;
int loook=0;
int lock3=1;
int lock4=1;
int timer;
int h1=0;
int h2=0;
int h3=0;
int h4=0;
int h5=0;
int h6=0;
int dminu3;
int go_fan=0;
int exhaust=0;
int mm_r;
int k10=0;
int trigger3;
int power_r;
int gate3_open=0;
int gates_open=0;
int gate2_open=0;
int p_stat=0;
int dhr3=0;
int k7=0;
int m_r;
int change_r;
int l_r;
int buzy=0;
int dms;
int dhrs;
int lck6=0;
int lck9=0;
int lck8=0;
int lck7=0;
int count_en=0;
int count=0;
int dhr4=0;
int wasclosed=0;
int cool_en=0;
int trigger2=0;
int gate_count=0;
int fan_count1=0;
int wascooling=0;
int k=0;
int gate_en=0;
int k2=0;
int k3=0;
int lck5=0;
int led1=50;
int led2=48;
int led3=46;
int led4=44;
int led5=42;
int led6=40;
int l_no=0;
int trigger;
int temp_set;
int change=0;
int lck1=0;
int go1=0;
int power=0;
int ran=0;
int rst=0;
int sound=34;
int gate1_o=10;
int gate1_c=14;
int me11=15;
int me21=16;
int gate2_c=24;
int gate2_o=26;
int me12=18;
int me22=17;
int gate3_c=22;
int gate3_o=21;
int me13=19;
int me23=20;
int fan1=28;
int fan2=30;
int fan3=32;
int heater1=31;
int heater2=33;
int heater3=35;
int heater4=37;
int heater5=39;
int heater6=41;
int light=43;
int door=45;
int clk=47;
int av_temp;
int av_humi;
int m=0;
int killd=0;
int count1=0;
int count2=0;
int go=0;
int val=25;
int set_no=1;
int sec=0;
int minu=0;
int hr=12;
int kill=0;
float sum=0;
int av_no=0;
int lck4=0;
int stat=0;
int hr2=12;
int hr3;
int hr4;
int minu3;
int pressed=0;
int dhr=0;
int dm=0;
int ds=0;
int count3=0;
int led1_en=0;
int led2_en=0;
int led3_en=1;
int led4_en=1;
int led5_en=1;
int led6_en=1;
int humi_set;
int go_count=0;

#define DHTTYPE DHT22 
DHT  a (A1, DHTTYPE);
DHT  b (A2, DHTTYPE);
DHT  c (A3, DHTTYPE);
DHT  d (A4, DHTTYPE);
DHT  e (A5, DHTTYPE);
DHT  f (A6, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() {

lcd.begin(20, 4);
 
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);  
pinMode(sound,OUTPUT);
pinMode(gate1_c,OUTPUT);
pinMode(gate1_o,OUTPUT);
pinMode(me11,INPUT);     
pinMode(me21,INPUT);
pinMode(gate3_c,OUTPUT);
pinMode(gate3_o,OUTPUT);
pinMode(me12,INPUT);     
pinMode(me22,INPUT);
pinMode(gate2_c,OUTPUT);
pinMode(gate2_o,OUTPUT); 
pinMode(fan1,OUTPUT);
pinMode(fan2,OUTPUT);
pinMode(fan3,OUTPUT); 
pinMode(heater1,OUTPUT);   
pinMode(heater2,OUTPUT); 
pinMode(heater3,OUTPUT); 
pinMode(heater4,OUTPUT); 
pinMode(heater5,OUTPUT); 
pinMode(heater6,OUTPUT);
pinMode(light,OUTPUT); 
pinMode(clk,INPUT);
pinMode(door,INPUT);

digitalWrite(sound,1);
delay(50);
digitalWrite(sound,0);
delay(50);
digitalWrite(sound,1);
delay(50);
digitalWrite(sound,0);
delay(50);
digitalWrite(sound,1);
delay(50);
digitalWrite(sound,0);
        
a.begin();         
b.begin(); 
c.begin();
d.begin(); 
e.begin(); 
f.begin();  
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Badaye Technologies"); 
lcd.setCursor(0, 1);
lcd.print("                   ");  
lcd.setCursor(0, 2);
lcd.print("  Checking System  "); 
lcd.setCursor(0, 3);
lcd.print("                   "); 
delay(2000);
ben:
if(digitalRead(clk)==1 and kill==0){
kill=1;
sec++;
}
if(digitalRead(clk)==0 and kill==1){
kill=0;
sec++;
}
go_count++;

if(go_count < 50000 and sec > 2){
go_count=0;
sec=0;
goto ben2;
} 
if(go_count > 30000 and sec < 1){

digitalWrite(sound,1);  
lcd.setCursor(0, 0);
lcd.print("  Clock is faulty   "); 
 
lcd.setCursor(0, 2);
lcd.print("  Check Clock Cell  ");  
delay(500);
digitalWrite(sound,0); 
delay(500);
lcd.clear();
go_count=0;
sec=0;
}

goto ben;

ben2:
lcd.clear();

digitalWrite(gate2_o,1);
delay(1000);
digitalWrite(gate2_o,0);
digitalWrite(gate3_o,1);
delay(1000);
digitalWrite(gate3_o,0);
digitalWrite(fan3,1);
delay(4000); 
digitalWrite(fan3,0);
digitalWrite(gate3_o,1);
delay(1000);
digitalWrite(gate3_o,0); 
digitalWrite(gate2_c,1);
delay(1000);       
digitalWrite(gate2_c,0); 
digitalWrite(gate3_c,1);
delay(1000);
digitalWrite(gate3_c,0); 
digitalWrite(gate2_o,0); 
digitalWrite(gate3_o,0); 
digitalWrite(gate2_c,0); 
digitalWrite(gate3_c,0); 
/*
 * 
 */
  
address=0;
temp_set=EEPROM.read(address);
address=1;
humi_set=EEPROM.read(address);
address=2;
dms=EEPROM.read(address);
address=3;
dhrs=EEPROM.read(address);

lcd.clear();
}

void loop() {




if(digitalRead(clk)==1 and kill==0){
kill=1;
sec++;
go=1;
}

if(digitalRead(clk)==0 and kill==1){
kill=0;
sec++;
go=0;
}



if(go==1){
float temp1 = a.readTemperature();
float humi1 = a.readHumidity(); 
float temp2 = b.readTemperature();
float humi2 = b.readHumidity();
float temp3 = c.readTemperature();
float humi3 = c.readHumidity();
float temp4 = d.readTemperature();
float humi4 = d.readHumidity();
float temp5 = e.readTemperature();
float humi5 = e.readHumidity();
float temp6 = f.readTemperature();
float humi6 = f.readHumidity();
sum=0;
av_no=0;
lck4=0;
if(isnan(temp1)){
lck4=1;
}
if(lck4==0){
sum=temp1;
av_no++;
}
lck4=0;
if(isnan(temp2)){
lck4=1;
}
if(lck4==0){
sum=temp2+sum;
av_no++;
}  
lck4=0;
if (isnan(temp3)){
lck4=1;
}
if(lck4==0){
sum=temp3+sum;
av_no++;
}
lck4=0;
if(isnan(temp4)){
lck4=1;
}
if(lck4==0){
sum=temp4+sum;
av_no++;
}
lck4=0;
if(isnan(temp5)){
lck4=1;
}
if(lck4==0){
sum=temp5+sum;
av_no++;
}
lck4=0;
if(isnan(temp6)){
lck4=1;
}
if(lck4==0){
sum=temp6+sum;
av_no++;
}
if(sum>0){
av_temp=sum/av_no; 
}

sum=0;
av_no=0;
lck4=0;
if(isnan(humi1)){
lck4=1;
}
if(lck4==0){
sum=humi1;
av_no++;
}
lck4=0;
if(isnan(humi2)){
lck4=1;
}
if(lck4==0){
sum=humi2+sum;
av_no++;
}
lck4=0;
if(isnan(humi3)){
lck4=1;
}
if(lck4==0){
sum=humi3+sum;
av_no++;
}
lck4=0;
if(isnan(humi4)){
lck4=1;
}
if(lck4==0){
sum=humi4+sum;
av_no++;
}
lck4=0;
if(isnan(humi5)){
lck4=1;
}
if(lck4==0){
sum=humi5+sum;
av_no++;
}
lck4=0;
if(isnan(humi6)){
lck4=1;
}
if(lck4==0){
sum=humi6+sum;
av_no++;
}
if(sum>0){
av_humi=sum/av_no; 
}
 }




if(go==0 and k7==0){
k7=1;
lcd.clear(); 
killd=0;
}
if(go==1 and k7==1){
k7=0;
lcd.clear(); 
killd=0;
}

if(sec==60){
minu++;
sec=0; 
}
if(minu==60){
minu=0;
hr++;
}
if(hr==24){
hr=0; 
}

if(hr==0){
hr2=12;  
stat=0;
}
if(hr==1){
hr2=1;  
stat=0;
}
if(hr==2){
hr2=2;  
stat=0;
}
if(hr==3){
hr2=3;  
stat=0;
}
if(hr==4){
hr2=4;  
stat=0;
}
if(hr==5){
hr2=5;  
stat=0;
}
if(hr==6){
hr2=6;  
stat=0;
}
if(hr==7){
hr2=7;  
stat=0;
}
if(hr==8){
hr2=8;  
stat=0;
}
if(hr==9){
hr2=9;  
stat=0;
}
if(hr==10){
hr2=10;  
stat=0;
}
if(hr==11){
hr2=11;  
stat=0;
}
if(hr==12){
hr2=12;  
stat=1;
}
if(hr==13){
hr2=1;  
stat=1;
}
if(hr==14){
hr2=2;  
stat=1;
}
if(hr==15){
hr2=3; 
stat=1;
}
if(hr==16){
hr2=4;  
stat=1;
}
if(hr==17){
hr2=5;  
stat=1;
}
if(hr==18){
hr2=6;  
stat=1;
}
if(hr==19){
hr2=7;  
stat=1;
}
if(hr==20){
hr2=8;  
stat=1;
}
if(hr==21){
hr2=9;  
stat=1;
}
if(hr==22){
hr2=10;  
stat=1;
}
if(hr==23){
hr2=11;  
stat=1;
}


if(power==0 and m==0){

if(killd==0){
lcd.setCursor(0, 0);
lcd.print("Temperature :"); 
lcd.setCursor(19, 0);
lcd.print("C"); 
lcd.setCursor(0, 1);
lcd.print("Humidity    :");
lcd.setCursor(19, 1);
lcd.print("%"); 
lcd.setCursor(0, 2);
lcd.print("  ");
lcd.setCursor(14,2);
lcd.print(":"); 
lcd.setCursor(0, 3);
lcd.print("Run              Set");
digitalWrite(led1,0);
if(stat==0){  
lcd.setCursor(18,2);
lcd.print("A");
lcd.setCursor(19,2);
lcd.print("M");
}
if(stat==1){ 
lcd.setCursor(18,2);
lcd.print("P");
lcd.setCursor(19,2);
lcd.print("M");  
}
if(minu<10){
lcd.setCursor(15,2);
lcd.print("0");
lcd.setCursor(16,2);
lcd.print(minu);
}
if(minu>=10){
lcd.setCursor(15,2);
lcd.print(minu);  
}
if(hr2 >=10){
lcd.setCursor(12,2);
lcd.print(hr2);
}
if(hr2 < 10){
lcd.setCursor(12,2);
lcd.print("0");  
lcd.setCursor(13,2);
lcd.print(hr2);
}
lcd.setCursor(13,0);
lcd.print(av_temp); 
lcd.setCursor(13,1);
lcd.print(av_humi);
killd=1;  
}

if(digitalRead(6)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150); 
mm_r=m;
count=0;
k10=0;
power=1;
lcd.clear();
}

if(digitalRead(7)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
mm_r=m; 
m=1; 
power_r=power;
change=0;
l_no=0;
lcd.clear();
}  
}


if(power==1 and m==0){
if(killd==0){
lcd.setCursor(0, 0);
lcd.print("Temp_"); 
lcd.setCursor(8, 0);
lcd.print("C"); 
lcd.setCursor(11, 0);
lcd.print("Humi_");
lcd.setCursor(18, 0);
lcd.print(" "); 
lcd.setCursor(19, 0);
lcd.print("%"); 
lcd.setCursor(2,1);
lcd.print(":");
lcd.setCursor(5,1);
lcd.print(":");
lcd.setCursor(14,2);
lcd.print(":"); 
lcd.setCursor(0, 3);
lcd.print("Stop                ");
if(dhr<10){
lcd.setCursor(0,1);
lcd.print("0");
lcd.setCursor(1,1);
lcd.print(dhr);
}
if(dhr>=10){
lcd.setCursor(0,1);
lcd.print(dhr);  
}
if(dm<10){
lcd.setCursor(3,1);
lcd.print("0");
lcd.setCursor(4,1);
lcd.print(dm);
}
if(dm>=10){
lcd.setCursor(3,1);
lcd.print(dm);  
}
if(ds >=10){
lcd.setCursor(6,1);
lcd.print(ds);
}
if(ds < 10){
lcd.setCursor(6,1);
lcd.print("0");  
lcd.setCursor(7,1);
lcd.print(ds);
}
if(stat==0){  
lcd.setCursor(18,2);
lcd.print("A");
lcd.setCursor(19,2);
lcd.print("M");
}
if(stat==1){ 
lcd.setCursor(18,2);
lcd.print("P");
lcd.setCursor(19,2);
lcd.print("M");  
}
if(minu<10){
lcd.setCursor(15,2);
lcd.print("0");
lcd.setCursor(16,2);
lcd.print(minu);
}
if(minu>=10){
lcd.setCursor(15,2);
lcd.print(minu);  
}
if(hr2 >=10){
lcd.setCursor(12,2);
lcd.print(hr2);
}
if(hr2 < 10){
lcd.setCursor(12,2);
lcd.print("0");  
lcd.setCursor(13,2);
lcd.print(hr2);
}
lcd.setCursor(5,0);
lcd.print(av_temp); 
lcd.setCursor(16,0);
lcd.print(av_humi); 
killd=1;  
}


if(digitalRead(6)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150); 
m=0; 
power=0;
lck9=0;
cool_en=0;
count_en=0;
count=0; 
lcd.clear();
killd=0;
digitalWrite(gate1_o,0); 
digitalWrite(gate2_o,0); 
digitalWrite(gate2_o,0); 
digitalWrite(gate1_c,0); 
digitalWrite(gate2_c,0); 
digitalWrite(gate2_c,0); 
digitalWrite(fan1,0); 
digitalWrite(fan2,0);
digitalWrite(fan3,0);
digitalWrite(heater1,0); 
digitalWrite(heater2,0); 
digitalWrite(heater3,0); 
digitalWrite(heater4,0);
digitalWrite(heater5,0); 
digitalWrite(heater6,0); 
}

  
}







if(power==1){

trigger=temp_set-5;
trigger3=temp_set-10;

if(digitalRead(door)==1){
digitalWrite(sound,0);
m=mm_r;
  
if(digitalRead(clk)==1 and k10==0){  
  if(lock1==0){
count++;
  }
countx++;
ds++;
k10=1;
}
if(digitalRead(clk)==0 and k10==1){  
  if(lock1==0){
count++;
  }
countx++;
ds++;
k10=0;
}

if(ds==60){
ds=0;
dm++; 
}

if(dm==60){
dm=0;
dhr++; 
}


if(countx==1){
digitalWrite(gate2_o,1);
}
if(countx==2){
digitalWrite(gate3_o,1);  
}

if(countx==3){
digitalWrite(gate3_o,0);
digitalWrite(gate2_o,0);
}
if(countx==4){
digitalWrite(fan1,1);
}
if(countx==8){
  digitalWrite(fan1,1);
digitalWrite(fan2,1);
}
if(countx==12){
    digitalWrite(fan1,1);
digitalWrite(fan2,1);
digitalWrite(fan3,1);
}


if(countx==121){ 
digitalWrite(heater1,1);
}
if(countx==121){ 
digitalWrite(heater1,1);
digitalWrite(heater2,1);

}
if(countx==141){ 
digitalWrite(heater1,1);
digitalWrite(heater2,1);
digitalWrite(heater3,1);
}
if(countx==151){ 
digitalWrite(heater1,1);
digitalWrite(heater2,1);
digitalWrite(heater3,1);
digitalWrite(heater4,1);
}
if(countx==161){ 
digitalWrite(heater1,1);
digitalWrite(heater2,1);
digitalWrite(heater3,1);
digitalWrite(heater4,1);
digitalWrite(heater5,1);
}
if(countx==171){ 
digitalWrite(heater1,1);
digitalWrite(heater2,1);
digitalWrite(heater3,1);
digitalWrite(heater4,1);
digitalWrite(heater5,1);
digitalWrite(heater6,1); 
}

if(countx==420){ 
digitalWrite(fan3,0); 
digitalWrite(gate2_c,1);   
}
if(countx==421){ 
digitalWrite(gate2_c,0);    
}
if(countx==422){
digitalWrite(gate3_c,1);  
}
if(countx==423){ 
digitalWrite(gate3_c,0); 
lock1=0;
lock2=0; 
count=0;
}


if(lock2==0){

if(av_temp <= trigger and loook==0){
loook=1;
timer=countx;
h1=timer;
h2=timer+10;
h3=timer+20;
h4=timer+30;
h5=timer+40;
h6=timer+50;
if(countx=h1){
digitalWrite(heater1,1);  
}
if(countx=h2){
digitalWrite(heater1,2);  
}

if(countx=h3){
digitalWrite(heater1,3);  
}
if(countx=h4){
digitalWrite(heater1,4);  
}
if(countx=h5){
digitalWrite(heater1,5);  
}
if(countx=h6){
digitalWrite(heater1,6);  
}

}

if(av_temp >= temp_set){ 
digitalWrite(heater1,0); 
digitalWrite(heater2,0); 
digitalWrite(heater3,0); 
digitalWrite(heater4,0);
digitalWrite(heater5,0); 
digitalWrite(heater6,0);
timer=0;
h1=0;
h2=0;
h3=0;
h4=0;
h5=0;
h6=0;
loook=0;
}


digitalWrite(fan2,1); 
digitalWrite(fan1,1); 

}


if(countx==2700){ 
lock1=0;
lock2=1; 
lock3=0; 
count=0;
}

if(lock3==0){
if(count==59){
digitalWrite(fan1,0);
digitalWrite(fan2,0);     
}

if(count==60){
exhaust=1;
digitalWrite(gate2_o,1);  
gates_open=1;
}
if(count==61){
digitalWrite(gate2_o,0);
digitalWrite(gate3_o,1);  
}
if(count==62){
digitalWrite(gate3_o,0);
digitalWrite(fan3,1);
}
if(count==72){
digitalWrite(fan3,0);
digitalWrite(gate2_c,1); 
}
if(count==73){
digitalWrite(gate2_c,0); 
}
if(count==74){
digitalWrite(gate3_c,1);   
}
if(count==75){
digitalWrite(gate3_c,0);   
}
if(count==76){
digitalWrite(fan1,1); 
}
if(count==79){
digitalWrite(fan2,1);  
}
if(count==80){
count=0;
gates_open=0;
exhaust=0;
}

if(av_temp <= trigger){
timer=countx;
h1=timer;
h2=timer+10;
h3=timer+20;
h4=timer+30;
h5=timer+40;
h6=timer+50;
if(countx=h1){
digitalWrite(heater1,1);  
}
if(countx=h2){
digitalWrite(heater1,2);  
}

if(countx=h3){
digitalWrite(heater1,3);  
}
if(countx=h4){
digitalWrite(heater1,4);  
}
if(countx=h5){
digitalWrite(heater1,5);  
}
if(countx=h6){
digitalWrite(heater1,6);  
}

}

if(av_temp >= temp_set){ 
digitalWrite(heater1,0); 
digitalWrite(heater2,0); 
digitalWrite(heater3,0); 
digitalWrite(heater4,0);
digitalWrite(heater5,0); 
digitalWrite(heater6,0);
timer=0;
h1=0;
h2=0;
h3=0;
h4=0;
h5=0;
h6=0;
}

digitalWrite(fan2,1); 
digitalWrite(fan1,1); 
}

if(countx==22500){ 
lock1=0;
lock2=1;
lock3=1; 
lock4=0;
count=0;
}

if(lock4==0){
digitalWrite(heater1,0);
digitalWrite(heater2,0);
digitalWrite(heater3,0);
digitalWrite(heater4,0);
digitalWrite(heater5,0);
digitalWrite(heater6,0);

if(count==60){
exhaust=1;
digitalWrite(gate2_o,1);  
gates_open=1;
}
if(count==61){
digitalWrite(gate2_o,0);
digitalWrite(gate3_o,1);  
}
if(count==62){
digitalWrite(gate3_o,0);
digitalWrite(fan3,1);
lock1=1;
count=0;
}

}



if(countx==23700){
lock1=0;
digitalWrite(fan1,0);
digitalWrite(fan2,0); 
digitalWrite(fan3,0); 
digitalWrite(gate2_c,1);  
if(count==61){
digitalWrite(gate2_c,0);
digitalWrite(gate3_c,1);  
}
if(count==62){
digitalWrite(gate3_c,0);
power=0;
m=0;
p_stat=0;
killd=0;
dhr=0;
dm=0;
ds=0;
dhr=0;
k7=0;
digitalWrite(fan1,0); 
digitalWrite(fan2,0); 
digitalWrite(fan3,0); 
digitalWrite(heater1,0); 
digitalWrite(heater2,0); 
digitalWrite(heater3,0); 
digitalWrite(heater4,0); 
digitalWrite(heater5,0); 
digitalWrite(heater6,0); 
digitalWrite(led2,0);
digitalWrite(led3,0);
digitalWrite(led4,0);
digitalWrite(led5,0);
digitalWrite(led6,0);
digitalWrite(gate2_o,0);
digitalWrite(gate3_o,0);
digitalWrite(gate2_c,0);
digitalWrite(gate3_c,0);
lcd.clear(); 
countx=0;
}


}


/*
if(dhrs==dhr and dms==dm){
power=0;
m=0;
p_stat=0;
killd=0;
dhr=0;
dm=0;
ds=0;
dhr=0;
k7=0;

digitalWrite(fan1,0); 
digitalWrite(fan2,0); 
digitalWrite(fan3,0); 
digitalWrite(heater1,0); 
digitalWrite(heater2,0); 
digitalWrite(heater3,0); 
digitalWrite(heater4,0); 
digitalWrite(heater5,0); 
digitalWrite(heater6,0); 
digitalWrite(led2,0);
digitalWrite(led3,0);
digitalWrite(led4,0);
digitalWrite(led5,0);
digitalWrite(led6,0);
digitalWrite(gate2_o,0);
digitalWrite(gate3_o,0);
digitalWrite(gate2_c,0);
digitalWrite(gate3_c,0);
lcd.clear(); 
}
/*
/*
 * 
 */
if(av_humi <= humi_set){
power=0;
m=0;
p_stat=0;
killd=0;
dhr=0;
dm=0;
ds=0;
dhr=0;
k7=0;

digitalWrite(fan1,0); 
digitalWrite(fan2,0); 
digitalWrite(fan3,0); 
digitalWrite(heater1,0); 
digitalWrite(heater2,0); 
digitalWrite(heater3,0); 
digitalWrite(heater4,0); 
digitalWrite(heater5,0); 
digitalWrite(heater6,0); 
digitalWrite(led2,0);
digitalWrite(led3,0);
digitalWrite(led4,0);
digitalWrite(led5,0);
digitalWrite(led6,0);
digitalWrite(gate2_o,0);
digitalWrite(gate3_o,0);
digitalWrite(gate2_c,0);
digitalWrite(gate3_c,0);
lcd.clear(); 
}
  
}


if(digitalRead(door)==0){
m=70;
digitalWrite(led2,0);
digitalWrite(led3,0);
digitalWrite(led4,0);
digitalWrite(led5,0);
digitalWrite(led6,0);
digitalWrite(fan1,0);
digitalWrite(fan2,0);
digitalWrite(fan3,0);
digitalWrite(heater1,0);
digitalWrite(heater2,0);
digitalWrite(heater3,0);
digitalWrite(heater4,0);
digitalWrite(heater5,0);
digitalWrite(heater6,0);


if(wasclosed==0){

lcd.setCursor(0, 2);
lcd.print("                    ");   
lcd.setCursor(0, 0);
lcd.print("   Close the Door   "); 

lcd.setCursor(0, 1);
lcd.print("      To Start      "); 
}

if(go==1){
lcd.setCursor(0, 3);
lcd.print("Abort               "); 
}
if(go==0){
lcd.setCursor(0, 3);
lcd.print("                    "); 
}


if(wasclosed==1){
lcd.setCursor(0, 2);
lcd.print("                    "); 
lcd.setCursor(0, 0);
lcd.print("   Close the Door   "); 

lcd.setCursor(0, 1);
lcd.print("     To Continue    "); 
}



if(go==1){
digitalWrite(sound,1); 
}
if(go==0){
digitalWrite(sound,0); 
}

if(digitalRead(6)==1){
m=0; 
power=0;
p_stat=0;
digitalWrite(fan2,0); 
digitalWrite(1,0);

digitalWrite(heater1,0);
digitalWrite(heater2,0);
digitalWrite(heater3,0);
digitalWrite(heater4,0);
digitalWrite(heater5,0);
digitalWrite(heater6,0);
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
killd=0;
l_no=0;
ran=0;
change=0;
lcd.clear();
}
 

}

}






//.........settings........................................................

if(m==1){

if(killd==0){  
lcd.setCursor(0, 3);  
lcd.print("               Enter"); 
if(l_no==0 and change==0){
lcd.setCursor(0, 0);
lcd.print("> Set Temperature    ");  
lcd.setCursor(0, 1);
lcd.print("  Set Timer           ");  
lcd.setCursor(0, 2);
lcd.print("  Set Clock         ");  
}

if(l_no==1 and change==0){
lcd.setCursor(0, 0);
lcd.print("  Set Temperature    ");  
lcd.setCursor(0, 1);
lcd.print("> Set Timer           ");  
lcd.setCursor(0, 2);
lcd.print("  Set Clock         ");   
}
if(l_no==2 and change==0){
lcd.setCursor(0, 0);
lcd.print("  Set Temperature    ");  
lcd.setCursor(0, 1);
lcd.print("  Set Timer           ");  
lcd.setCursor(0, 2);
lcd.print("> Set Clock         ");   
}

if(l_no==0 and change==1){
lcd.setCursor(0, 0);
lcd.print("> Set Timer           ");  
lcd.setCursor(0, 1);
lcd.print("  Set Clock         "); 
lcd.setCursor(0, 2);
lcd.print("  Set Humidity Level");   
}

if(l_no==1 and change==1){
lcd.setCursor(0, 0);
lcd.print("  Set Timer           ");  
lcd.setCursor(0, 1);
lcd.print("> Set Clock         "); 
lcd.setCursor(0, 2);
lcd.print("  Set Humidity Level");   
}

if(l_no==2 and change==1){
lcd.setCursor(0, 0);
lcd.print("  Set Timer           ");  
lcd.setCursor(0, 1);
lcd.print("  Set Clock         "); 
lcd.setCursor(0, 2);
lcd.print("> Set Humidity Level");   
}
killd=1; 
}

if(digitalRead(6)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m=0; 
killd=0;
l_no=0;
change=0;
lcd.clear();
}

if(digitalRead(9)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
l_no++; 
}
if(digitalRead(8)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
l_no--; 
}

if(l_no==3){
l_no=2;  
change=1; 
}



if(change==1 and l_no==-1){
change=0;
killd=0;
lck1=0;
}
if(l_no==-1){
l_no=0;
}




if((digitalRead(7)==1 and l_no==0) and change==0){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m_r=m;
change_r=change;
l_r=l_no;
m=2; 
killd=0;
lcd.clear();
lck1=0;
address=0;
val=EEPROM.read(address); 
kill=0;
pressed=0;
}

if((digitalRead(7)==1 and l_no==1) and change==0){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m_r=m;
change_r=change;
l_r=l_no;
address=2;
dminu3=EEPROM.read(address); 
address=3;
dhr3=EEPROM.read(address); 
m=3; 
killd=0;
lcd.clear();
lck1=0;
kill=0;
pressed=0;
}

if((digitalRead(7)==1 and l_no==0) and change==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m_r=m;
change_r=change;
l_r=l_no;
address=2;
dminu3=EEPROM.read(address); 
address=3;
dhr3=EEPROM.read(address); 
m=3; 
killd=0;
lcd.clear();
lck1=0;
kill=0;
pressed=0;
}


if((digitalRead(7)==1 and l_no==2) and change==0){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m_r=m;
change_r=change;
l_r=l_no;
minu3=minu;
hr4=hr;
m=4; 
killd=0;
lcd.clear();
lck1=0;
kill=0;
pressed=0;
}

if((digitalRead(7)==1 and l_no==1) and change==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m_r=m;
change_r=change;
l_r=l_no;
minu3=minu;
hr4=hr;
m=4; 
killd=0;
lcd.clear();
lck1=0;
kill=0;
pressed=0;
}

if((digitalRead(7)==1 and l_no==2) and change==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m_r=m;
change_r=change;
l_r=l_no;
m=5; 
killd=0;
lcd.clear();
address=1;
val=EEPROM.read(address); 
lck1=0;
pressed=0;
}
  
}


if(m==2){
if(killd==0){  
lcd.setCursor(0, 0);
lcd.print("Set Temperature     ");  
lcd.setCursor(0, 1);
lcd.print("   ");   
lcd.setCursor(0, 3);
lcd.print("                  Ok");  
killd=1;
}
lcd.setCursor(0, 2);
lcd.print(val); 

if(digitalRead(8)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
val++;  
}
if(digitalRead(9)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
val--;  
}

if(val==29){
val=30;  
}
if(val==76){
val=75;  
}

if(digitalRead(6)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
m=m_r;
change=change_r;
power=power_r;
l_no=l_r;
address=0;
EEPROM.update(address, val);   
temp_set=val;
killd=0;
lcd.clear();
}

if(digitalRead(7)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m=m_r;
change=change_r;
power=power_r;
l_no=l_r;
killd=0;
address=0;
EEPROM.update(address, val);   
temp_set=val;
lcd.clear();  
}
}

if(m==3){
if(killd==0){  
lcd.setCursor(0, 0);
lcd.print("Set Timer          ");  
lcd.setCursor(0, 1);
lcd.print("   ");
lcd.setCursor(2,2);
lcd.print(":");  
killd=1;   
}

if(pressed==0){
  lcd.setCursor(0, 3);
lcd.print("Back               >"); 
}

if(pressed==1){ 
  lcd.setCursor(0, 3);
lcd.print("Ok                 >"); 
}

if(set_no==2){

if(digitalRead(8)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
pressed=1;
dminu3++;  
}
if(digitalRead(9)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
 pressed=1;
dminu3--; 
}
if(dminu3==60){
dminu3=59;  
}
if(dminu3==-1){
dminu3=0;  
}  
if(go1==1){
if(dminu3<10){
lcd.setCursor(3,2);
lcd.print("0");
lcd.setCursor(4,2);
lcd.print(dminu3);
}
if(dminu3>=10){
lcd.setCursor(3,2);
lcd.print(dminu3);  
}
}
if(go1==0){
lcd.setCursor(3,2);
lcd.print(" ");
lcd.setCursor(4,2);
lcd.print(" ");  
}
if(dhr3 >=10){
lcd.setCursor(0,2);
lcd.print(dhr3);
}
if(dhr3 < 10){
lcd.setCursor(0,2);
lcd.print("0");  
lcd.setCursor(1,2);
lcd.print(dhr3);
}
}

if(set_no==1){

if(digitalRead(8)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
pressed=1;
dhr3++;
}
if(digitalRead(9)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
pressed=1;
dhr3--; 
}

if(dhr3==-1){
dhr3=0;  
}

if(dhr3==13){
dhr3=12;  
}
  
if(go1==1){
if(dhr3 >=10){
lcd.setCursor(0,2);
lcd.print(dhr3);
}
if(dhr3 < 10){
lcd.setCursor(0,2);
lcd.print("0");  
lcd.setCursor(1,2);
lcd.print(dhr3);
}  
}
if(go1==0){
lcd.setCursor(0,2);
lcd.print(" ");  
lcd.setCursor(1,2);
lcd.print(" ");  
}
if(dminu3<10){
lcd.setCursor(3,2);
lcd.print("0");
lcd.setCursor(4,2);
lcd.print(dminu3);
}
if(dminu3>=10){
lcd.setCursor(3,2);
lcd.print(dminu3);  
}

}




if(digitalRead(6)==1 and pressed==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m=m_r;
change=change_r;
l_no=l_r;
address=3;
EEPROM.update(address, dhr3); 
address=2;
EEPROM.update(address, dminu3); 
 ds=0;
 dm=0;
 dhr=0;
 dhrs=dhr3;
 dms=dminu3;
 killd=0;
 lcd.clear();
 set_no=1;
}

if(digitalRead(6)==1 and pressed==0){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m=m_r;
change=change_r;
l_no=l_r;
 killd=0;
 lcd.clear();
 set_no=1;
}

if(digitalRead(7)==1){
 digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
 set_no++; 
}

if(set_no==0){
 set_no=2; 
}

if(set_no==3){
 set_no=1; 
}




count2++;

if(count2==1){
  go1=1;
}

if(count2==140){
  go1=0;
}
if(count2==160){
  count2=0;
}  
}

if(m==4){
if(killd==0){  
lcd.setCursor(0, 0);
lcd.print("Set Clock           ");  
lcd.setCursor(0, 1);
lcd.print("   ");
lcd.setCursor(2,2);
lcd.print(":");  
killd=1;   
}

if(pressed==0){
  lcd.setCursor(0, 3);
lcd.print("Back               >"); 
}

if(pressed==1){ 
  lcd.setCursor(0, 3);
lcd.print("Ok                 >"); 
}


if(set_no==2){

if(digitalRead(8)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
pressed=1;
minu3++; 
}
if(digitalRead(9)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
 pressed=1;
minu3--;  
}
if(minu3==60){
minu3=0;  
}
if(minu3==-1){
minu3=59;  
}  
if(go1==1){
if(minu3<10){
lcd.setCursor(3,2);
lcd.print("0");
lcd.setCursor(4,2);
lcd.print(minu3);
}
if(minu3>=10){
lcd.setCursor(3,2);
lcd.print(minu3);  
}
}
if(go1==0){
lcd.setCursor(3,2);
lcd.print(" ");
lcd.setCursor(4,2);
lcd.print(" ");  
}
if(hr3 >=10){
lcd.setCursor(0,2);
lcd.print(hr3);
}
if(hr3 < 10){
lcd.setCursor(0,2);
lcd.print("0");  
lcd.setCursor(1,2);
lcd.print(hr3);
}
if(stat==0){  
lcd.setCursor(6,2);
lcd.print("A");
lcd.setCursor(7,2);
lcd.print("M");
}
if(stat==1){ 
lcd.setCursor(6,2);
lcd.print("P");
lcd.setCursor(7,2);
lcd.print("M");  
}  
}


if(set_no==1){

if(digitalRead(8)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
pressed=1;
hr4++;  
}
if(digitalRead(9)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
pressed=1;
hr4--;  
}


if(hr4==-1){
hr4=23;  
}

if(hr4==24){
hr4=0;  
}
//.....................
//------------extractor section(time)----------------
if(hr4==0){
 hr3=12;  
 stat=0;
}
if(hr4==1){
 hr3=1;  
 stat=0;
}
if(hr4==2){
 hr3=2;  
 stat=0;
}
if(hr4==3){
 hr3=3;  
 stat=0;
}
if(hr4==4){
 hr3=4;  
 stat=0;
}
if(hr4==5){
 hr3=5;  
 stat=0;
}
if(hr4==6){
 hr3=6;  
 stat=0;
}
if(hr4==7){
 hr3=7;  
 stat=0;
}
if(hr4==8){
 hr3=8;  
 stat=0;
}
if(hr4==9){
 hr3=9;  
 stat=0;
}

if(hr4==10){
 hr3=10;  
 stat=0;
}
if(hr4==11){
 hr3=11;  
 stat=0;
}
if(hr4==12){
 hr3=12;  
 stat=1;
}
if(hr4==13){
 hr3=1;  
 stat=1;
}
if(hr4==14){
 hr3=2;  
 stat=1;
}
if(hr4==15){
 hr3=3; 
 stat=1;
}
if(hr4==16){
 hr3=4;  
 stat=1;
}
if(hr4==17){
 hr3=5;  
 stat=1;
}
if(hr4==18){
 hr3=6;  
 stat=1;
}
if(hr4==19){
 hr3=7;  
 stat=1;
}
if(hr4==20){
 hr3=8;  
 stat=1;
}
if(hr4==21){
 hr3=9;  
 stat=1;
}
if(hr4==22){
 hr3=10;  
 stat=1;
}
if(hr4==23){
 hr3=11;  
 stat=1;
}


//.....................

  
if(go1==1){
if(hr3 >=10){
lcd.setCursor(0,2);
lcd.print(hr3);
}
if(hr3 < 10){
lcd.setCursor(0,2);
lcd.print("0");  
lcd.setCursor(1,2);
lcd.print(hr3);
}  
}
if(go1==0){
lcd.setCursor(0,2);
lcd.print(" ");  
lcd.setCursor(1,2);
lcd.print(" ");  
}
if(minu3<10){
lcd.setCursor(3,2);
lcd.print("0");
lcd.setCursor(4,2);
lcd.print(minu3);
}
if(minu3>=10){
lcd.setCursor(3,2);
lcd.print(minu3);  
}

}

if(digitalRead(6)==1 and pressed==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
m=m_r;
change=change_r;
l_no=l_r;
hr2=hr4;
minu=minu3;
sec=0;
 killd=0;
 lcd.clear();
 set_no=1;
}

if(digitalRead(6)==1 and pressed==0){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
 m=m_r;
 change=change_r;
 l_no=l_r;
 killd=0;
 lcd.clear();
 set_no=1;
}

if(digitalRead(7)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(150);
 set_no++;  
}

if(set_no==0){
 set_no=2; 
}

if(set_no==3){
 set_no=1; 
}

count2++;

if(count2==1){
go1=1;
}

if(count2==140){
go1=0;
}
if(count2==160){
  count2=0;
}

}


if(m==5){
if(killd==0){  
lcd.setCursor(0, 0);
lcd.print("Set Humidity        ");  
lcd.setCursor(0, 1);
lcd.print("   ");   
lcd.setCursor(0, 3);
lcd.print("                  Ok");
killd=1;   
}

lcd.setCursor(0, 2);
lcd.print(val); 

if(digitalRead(6)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
m=m_r;
change=change_r;
l_no=l_r;
address=1;
EEPROM.update(address, val);
humi_set=val;
killd=0;
lcd.clear();
}

if(digitalRead(8)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
val++;  
}
if(digitalRead(9)==1){
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
val--; 
}

if(val<20){
val=20;  
}
if(val==100){
val=99;  
}
//.....................

if(digitalRead(7)==1){  
digitalWrite(sound,1); 
delay(50);
digitalWrite(sound,0);
delay(50);
m=m_r;
change=change_r;
l_no=l_r;
killd=0;
lcd.clear(); 
address=1;
EEPROM.update(address, val);
humi_set=val; 
}
} 

if(digitalRead(door)==1){
digitalWrite(light,0);
}
if(digitalRead(door)==0){
digitalWrite(light,1);
}

}
