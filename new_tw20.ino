//Low Cost Touchless Handwashing Technology (TW-20 Kit)
//Working with partners at Makerere University and Funding from Mak-RIF
//Badaye Technologies, introduced the Green Low Cost Touchless Handwashing Technology (TW-20 Kit) for Publicly Shared Spaces
//This is the first of its kind mobile smart handwashing technology which uses a hybrid energy source of solar power, battery, and mains AC supply to automate the process of providing precise soap and rinsing water to the user from usually jerry cans. 
//The audio user interface is incorporated to improve on usability with audio language tailored to the commonly spoken languages in the communities where we install the kits. 
//To facilitate point-of-use user data mining, we connected TW-20 Kit to the TW-20 View; a custom made data repository, curation and analytics platform that receives handwashing user data remotely and reports it to the public. 
//With TW-20 View, we are able to stream and interface user data from the handwashing kits in realtime. 
//Collected data is further analyzed automatically using back-end analytics algorithms to support public health programs in the individual beneficiary organizations. 
//Specifically, different sites are able to know the coping levels as regards hand washing on a daily and be able to introduce feasible handwashing interventions in their organizations.

int sound=9;
int pump1=6;
int pump2=5;

int count=0;
int count2=0;
int en_c5=0;
int c_en=0;
int s_en1=0;
int distance;
long duration;
int s_en2=0;
int charge_stat=0;
int power_stat=0;
int battery_stat=1;
int lock2=0;
int sense=0;
int lock=0;
int addr=0;
int power=2;
int count3=0;
int lock3=0;

int ac_r=4;
int solar_r=3;

float battery_volt;
float solar_volt;
float ac_volt;

int led=7;

const int trigPin = 10;
const int echoPin = 11;

void setup() {

pinMode(9,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);

pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 

digitalWrite(sound,1);
digitalWrite(led,1);
delay(100);
digitalWrite(sound,0);
digitalWrite(led,0);
delay(100);
digitalWrite(sound,1);
digitalWrite(led,1);
delay(100);
digitalWrite(sound,0);
digitalWrite(led,0);
delay(200);

digitalWrite(pause, HIGH);   
delay(600);                       
digitalWrite(pause, LOW);
lock = 0;
charge_stat=1; 

}

void loop() {


ac_volt=analogRead(A0)*0.05;
solar_volt=analogRead(A1)*0.05;
battery_volt=analogRead(A2)*0.05;


if(ac_volt > 10){
  count3++;
}
if(count3==5000){
 digitalWrite(led,1); 
}
if(count3==7500){
 digitalWrite(led,0); 
 count3=0;
}


if(ac_volt<=12){
s_en1=1;
}
if(s_en1==1 and ac_volt > 14){
digitalWrite(sound,HIGH);
delay(50);
digitalWrite(sound,LOW);
delay(50);
s_en1=0;
delay(100);
}


if(solar_volt <= 12){
s_en2=1;
}
if(s_en2==1 and solar_volt > 12){
digitalWrite(sound,HIGH);
delay(50);
digitalWrite(sound,LOW);
delay(50);
s_en2=0;
delay(100);
}



if(battery_volt <=11 and count==0){
  en_c5=1;
digitalWrite(sound,HIGH);
delay(50);
digitalWrite(sound,LOW); 
delay(50);
}

if(en_c5==1){
 count++; 
}
if(count==7000){
  count=0;
  en_c5=0;
}
if(battery_volt < 10){
digitalWrite(solar_r,LOW);
digitalWrite(ac_r,LOW);
}


if(battery_volt > 14){
digitalWrite(solar_r,HIGH);
digitalWrite(ac_r,HIGH);
}

 




 
if(battery_volt > 11){
if(sense==0){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;

if(distance <= 28 ){
c_en=1;
}
}


if(c_en==1){
count2++;
}


if(distance <=28 and count2==3){
sense=1;
count2=0;
}

if(distance > 28 and count2 < 3 ){
sense=0;
count2=0;
c_en=0;
delay(500);
}



if(count2==5){
 count2=0; 
   c_en=0;
}




if(sense==1){
delay(50); 
digitalWrite(sound,HIGH);
delay(50);
digitalWrite(sound,LOW);
delay(50);
digitalWrite(sound,HIGH);
delay(50);
digitalWrite(sound,LOW);
delay(50);

//soap
digitalWrite(pump1,HIGH);
delay(500);
digitalWrite(pump1,LOW); 


digitalWrite(power, HIGH);                       


delay(8500);
digitalWrite(power, LOW);
digitalWrite(pump2,HIGH);

delay(2000);

//water
delay(4000);
digitalWrite(pump2,LOW);
sense=0;
digitalWrite(8, 1);
delay(500);
digitalWrite(8, 0);
delay(2000);
distance=100;
}
}










}
