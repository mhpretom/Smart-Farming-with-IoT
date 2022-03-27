#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);//rs,en,data pins d4 -d7

float TEMP;
int MOISURE;
int HUM;

const int buzzer=6;
const int motor=7;

int led=4;
int temp=0,i=0;

char str[30];

int aa=0;

int dt=0;///temp
int dh=0;///hum

int s1=0;
int s3=0;

void setup()  
{
lcd.begin(16,2);
Serial.begin(9600);

pinMode(buzzer, OUTPUT);
pinMode(motor, OUTPUT);

digitalWrite(buzzer, LOW);
digitalWrite(motor, LOW);
lcd.clear();

lcd.setCursor(0,0);lcd.print("IOT Based ");
lcd.setCursor(0,1);lcd.print("Agriculture Crop");
delay(5000);lcd.clear();
lcd.setCursor(0,0);lcd.print("Field Monitoring");
lcd.setCursor(0,1);lcd.print("Irrigation");
delay(5000);lcd.clear();
lcd.setCursor(0,0);lcd.print(" Automation");
lcd.setCursor(0,1);lcd.print("using GPRS ");
delay(5000);lcd.clear();
gsm_init();lcd.clear();
digitalWrite(buzzer, LOW);
digitalWrite(motor, LOW);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() 
{
  
aa=aa+1;
digitalWrite(buzzer, LOW); 
lcd.clear();  
/////////////////////////////////////////////////////////////////////////////////////////
TEMP = analogRead(0);
TEMP=(TEMP*500)/1023;
lcd.setCursor(0,0);lcd.print("T:");lcd.setCursor(3,0);lcd.print(TEMP);delay(200);if(TEMP<50){dt=0;delay(100);}
if(TEMP>50)
{
dt=dt+1;
if(dt==2)
{
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);lcd.clear();send_gprs();delay(500);
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);
lcd.clear();lcd.setCursor(0,0);lcd.print("SENDING SMS");lcd.setCursor(0,1);lcd.print("TEMP ALERT");
Serial.println("AT+CMGF=1");delay(400);
Serial.println("AT+CMGS=\"9354632116\"");delay(400);
Serial.println("Over Temperature\n");delay(100);
Serial.print("Temp=");delay(100);Serial.print(TEMP);delay(500);Serial.write(26);delay(500);
Serial.print("AT\r\n");delay(1000);Serial.print("AT\r\n");delay(1000);Serial.println("AT+CMGF=1");delay(1000);
}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
HUM= analogRead(1);HUM =HUM/2;
HUM=HUM+12;
lcd.setCursor(0,1);lcd.print("H:");lcd.setCursor(3,1);lcd.print(HUM);delay(2500);if(HUM<30){dh=0;delay(100);}
if(HUM>45)
{
dh=dh+1;
if(dh==2)
{
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);lcd.clear();send_gprs();delay(500);
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);
lcd.clear();lcd.setCursor(0,0);lcd.print("SENDING SMS");lcd.setCursor(0,1);lcd.print("HUMIDITY ALERT");
Serial.println("AT+CMGF=1");delay(400);
Serial.println("AT+CMGS=\"9354632116\"");delay(400);
Serial.println("HUMIDITY ALERT\n");delay(100);
Serial.print("HUM=");delay(100);Serial.print(HUM);delay(500);Serial.write(26);delay(500);
Serial.print("AT\r\n");delay(1000);Serial.print("AT\r\n");delay(1000);Serial.println("AT+CMGF=1");delay(1000);
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MOISURE = analogRead(2); MOISURE= MOISURE/4;MOISURE=256-MOISURE;
lcd.setCursor(9,0);
lcd.print("M: ");
lcd.setCursor(11,0);
lcd.print(MOISURE);
delay(500);
if(MOISURE<100)
{
s1=s1+1;
if(s1==5)
{
s3=0;
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);lcd.clear();send_gprs();delay(500);
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);
lcd.clear();lcd.setCursor(0,0);lcd.print("SENDING SMS");delay(2000);
lcd.clear();
lcd.setCursor(0,0);lcd.print("FEILD AT DRY");
lcd.setCursor(0,1);lcd.print("MOTOR ON");delay(2000);digitalWrite(motor, HIGH);
Serial.print("AT\r\n");delay(2000);Serial.print("AT\r\n");delay(2000);
Serial.println("AT+CMGF=1");delay(400);Serial.println("AT+CMGS=\"9354632116\"");delay(400);   // use your 10 digit cell no. here
Serial.println("FEILD AT DRY\n");delay(100);
Serial.println("MOTOR ON\n");delay(100);
Serial.write(26);delay(100);
Serial.print("AT\r\n");delay(1000);Serial.print("AT\r\n");delay(1000);Serial.println("AT+CMGF=1");delay(1000); 
motor_gprs();
delay(2000);
pump_gprs();
delay(2000);
}
delay(100);
}

if(MOISURE>200)
{
s3=s3+1;
if(s3==5)
{
s1=0;
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);lcd.clear();send_gprs();delay(500);
delay(200);digitalWrite(buzzer, HIGH);delay(200);digitalWrite(buzzer, LOW);
lcd.clear();lcd.setCursor(0,0);lcd.print("SENDING SMS");delay(2000);
lcd.clear();
lcd.setCursor(0,0);lcd.print("FEILD AT WET");
lcd.setCursor(0,1);lcd.print("MOTOR OFF");delay(2000);digitalWrite(motor, LOW);
Serial.print("AT\r\n");delay(2000);Serial.print("AT\r\n");delay(2000);
Serial.println("AT+CMGF=1");delay(400);Serial.println("AT+CMGS=\"9354632116\"");delay(400);   // use your 10 digit cell no. here
Serial.println("FEILD AT WET\n");delay(100);
Serial.println("MOTOR OFF\n");delay(100);
Serial.write(26);delay(100);
Serial.print("AT\r\n");delay(1000);Serial.print("AT\r\n");delay(1000);Serial.println("AT+CMGF=1");delay(1000); 
motor_gprs();
delay(2000);
pump_gprs();
delay(2000);
}
delay(100);
}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(aa==10)
{
lcd.clear();
send_gprs();
delay(2000);
pump_gprs();
delay(2000);
aa=0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}




void motor_gprs()
{
lcd.clear();lcd.print("GPRS SENDING");
boolean test47_flag=1;
while(test47_flag){Serial.print("AT+HTTPPARA=\"URL\",\"http://iotbabycare.com/iot_green_agrimnr/put_motor.php?mot=motor");
Serial.print("\"");Serial.print("\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test47_flag=0;}delay(1000);}
lcd.clear();lcd.print("SENT COMPLETED");delay(10000);lcd.clear();
///////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("ACTION");
boolean test48_flag=1;while(test48_flag){Serial.print("AT+HTTPACTION=0\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test48_flag=0;}delay(1000);}
lcd.clear();lcd.print("SEND  OK");delay(2000); delay(2000);delay(2000);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
boolean at_flagd=1;while(at_flagd){Serial.println("AT");while(Serial.available()>0){if(Serial.find("OK"))at_flagd=0;}delay(1000);}
}





void send_gprs()
{
lcd.clear();lcd.print("GPRS SENDING");
boolean test7_flag=1;
while(test7_flag){Serial.print("AT+HTTPPARA=\"URL\",\"http://iotbabycare.com/iot_green_agrimnr/put_data.php");
////////////////////////////////////////////////////////////////////////////////
Serial.print("?temp=");Serial.print(TEMP);
Serial.print("&hum=");Serial.print(HUM);
Serial.print("&mos=");Serial.print(MOISURE);
Serial.print("\"");Serial.print("\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test7_flag=0;}delay(1000);}
lcd.clear();lcd.print("SENT COMPLETED");delay(10000);lcd.clear();
///////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("ACTION");
boolean test8_flag=1;while(test8_flag){Serial.print("AT+HTTPACTION=0\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test8_flag=0;}delay(1000);}
lcd.clear();lcd.print("SEND  OK");delay(2000); delay(2000);delay(2000);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
///////////////////////////////////////////////////////////////////

void pump_gprs()
{
boolean at_flagd=1;while(at_flagd){Serial.println("AT");while(Serial.available()>0){if(Serial.find("OK"))at_flagd=0;}delay(1000);}
lcd.clear();lcd.print("PING TO WEBSITE");
boolean test17_flag=1;while(test17_flag){Serial.print("AT+HTTPPARA=\"URL\",\"http://iotbabycare.com/iot_green_agrimnr/get_data.php");Serial.print("\"");Serial.print("\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test17_flag=0;}delay(1000);}
lcd.clear();lcd.print("WEBLINK SUCESS");delay(1000);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("HTTP ACTION");
boolean test18_flag=1;while(test18_flag){Serial.print("AT+HTTPACTION=0\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test18_flag=0;}delay(1000);}
lcd.clear();lcd.print("ACTION COMPLETED");delay(5000);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("GET THE DATA");
boolean test19_flag=1;while(test19_flag){Serial.print("AT+HTTPREAD\r\n");
SeriallEvent();
while(Serial.available()>0){if(Serial.find("OK"))test19_flag=0;}delay(1000);}
lcd.clear();lcd.print("DATA OK");delay(5000);
//////////////////////////////////////////////////////////
if(temp==1)
{
check();
temp=0;
i=0;
delay(100);
}
}


void SeriallEvent() 
{
while(Serial.available()) 
{
if(Serial.find("?ID="))
{
digitalWrite(led, HIGH);
delay(100);
digitalWrite(led, LOW);
while (Serial.available()) 
{
char inChar=Serial.read();
str[i++]=inChar;
if(inChar=='$')
{
temp=1;
return;
} 
} 
}
}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void check()
{
if(!(strncmp(str,"ON",2))){lcd.setCursor(1,1);lcd.print("MOTOR  ON");delay(500);digitalWrite(motor,HIGH);}
else if(!(strncmp(str,"OFF",3))){lcd.setCursor(1,1);lcd.print("MOTOR OFF");digitalWrite(motor,LOW);}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void gsm_init()
{
lcd.clear();lcd.print("GSM TESTING..");
boolean at_flag=1;while(at_flag){Serial.println("AT");while(Serial.available()>0){if(Serial.find("OK"))at_flag=0;}delay(1000);}
lcd.clear();lcd.print("GSM CONNECTED");delay(1000);lcd.clear();
///////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.print("ECHO");
boolean echo_flag=1;
while(echo_flag)
{Serial.println("ATE0"); while(Serial.available()>0){if(Serial.find("OK"))echo_flag=0;}delay(1000);}
lcd.clear();  lcd.print("Echo OFF");delay(1000);lcd.clear();
/////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.print("Finding Network..");
boolean net_flag=1;while(net_flag){Serial.println("AT+CPIN?");
while(Serial.available()>0){if(Serial.find("+CPIN: READY"))net_flag=0;}delay(1000);}
lcd.clear();lcd.print("Network Found..");
/////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.setCursor(0,1);lcd.print("GSM NETWORK OK");delay(2000);lcd.clear();
//////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("TEST MESS");
boolean test_flag=1;while(test_flag){Serial.println("AT+CMGF=1");
while(Serial.available()>0){if(Serial.find("OK"))test_flag=0;}delay(1000);}
lcd.clear();lcd.print("TEST MESSAGE");delay(1000);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("AT+CGATT");
boolean test1_flag=1;while(test1_flag){Serial.println("AT+CGATT=1");
while(Serial.available()>0){if(Serial.find("OK"))test1_flag=0;}delay(1000);}
lcd.clear();lcd.print("AT+CGATT=1");delay(1000);
//////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("GPRS START");
boolean test2_flag=1;while(test2_flag){Serial.print("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test2_flag=0;}delay(1000);}
lcd.clear();lcd.print("GPRS START1");delay(1000);
//////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("GPRS START");
boolean test3_flag=1;while(test3_flag){Serial.print("AT+SAPBR=3,1,\"APN\",\"internet\"\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test3_flag=0;}delay(1000);}
lcd.clear();lcd.print("GPRS START2");delay(1000);
//////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("GPRS MAIN");
boolean test4_flag=1;while(test4_flag){Serial.print("AT+SAPBR=1,1\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test4_flag=0;}delay(1000);}
lcd.clear();lcd.print("GPRS FIND");delay(1000);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("HTTP STARTS");
boolean test5_flag=1;while(test5_flag){Serial.print("AT+HTTPINIT\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test5_flag=0;}delay(1000);}
lcd.clear();lcd.print("HTTP STARTS1");delay(1000);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
lcd.clear();lcd.print("HTTP STARTS");
boolean test6_flag=1;while(test6_flag){Serial.print("AT+HTTPPARA=\"CID\",1\r\n");
while(Serial.available()>0){if(Serial.find("OK"))test6_flag=0;}delay(1000);}
lcd.clear();lcd.print("HTTP STARTS2");delay(1000);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
}
