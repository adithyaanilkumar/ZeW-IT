#include <Servo.h>
#include <LiquidCrystal.h>
Servo n;
Servo rwdservo;
void selection();
void choice1();
int buttons();
void choice2();
void choice3();
int na=0;
void choice4();
void choice5();
void choice6();
void done();
int servobin1default(int na);
void Thank();
void reward();
void welcome();
void dump();
void wait();
const int t=31,e=32,t1=33,e1=34,t2=35,e2=40,t3=39,e3=38,t4=37,e4=36,t5=21,e5=20;
int areyoudonestatus=0;
int full =10;
int agri=0;
int servopos=0;//default =0;
int sensor();
int sensor2();
int sensor1();
int sensor3();
int sensor4();
int sensor5();
int dcmix();
int areyoudone();
int rewardq();
int servobin1();
int servobin2();
int butt;
int servobin3();
int servobin4();
int servobin5();
int servobin6();
#include <LiquidCrystal.h>  3

int Contrast=20;
LiquidCrystal lcd(11, 12, 10, 9, 8, 7);

void setup() 
{
 
  n.attach(6);
  rwdservo.attach(53);
  rwdservo.write(180);
  Serial.begin (9600);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  pinMode(t1, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(t2, OUTPUT);
  pinMode(e2, INPUT);
  pinMode(t3, OUTPUT);
  pinMode(e3, INPUT);  
  pinMode(t4, OUTPUT);
  pinMode(e4, INPUT); 
  pinMode(t5, OUTPUT);
  pinMode(e5, INPUT); 
  n.write(89);
    int mno;
}
void loop()
{ int b=0;
  n.write(90);Serial.println("loop running");
lcd.clear();
  selection();
 Serial.println("please select the type of waste") ;
int butt=0;
 butt=buttons();
 
 // here let butt be the agricultural waste
  if(butt==1)
  {
    //plastic
    lcd.clear();
    choice1();
    Serial.println("waste bin 1");
    int z=0;
    z=servobin1();
    lcd.clear();
    dump();
    delay(4000);
    if(z==1)
    {
      lcd.clear();
      done();
    areyoudone();
    }
  }

  if(butt==2)
  {
   
    //glass
    lcd.clear();
    choice2();
    Serial.println("waste bin 2");
    int z=0;

  int j=350;
  lcd.clear();
    wait();
    
  Serial.println("you chose bin 2");
  for(int i=0;i<1;i++)
  {
    n.write(70);
    delay(j);
     
    n.write(89);
    j=j-5;
  }   lcd.clear();
    dump();
    delay(4000);
    //after exe

    
      lcd.clear();
      done();
    areyoudone();
    
    na=5;
    servobin1default(na);
  
  }
  if(butt==3)
  {
    //paper
    lcd.clear();
    choice3();
    Serial.println("waste bin 3");
    int z=1;
    
  int j=350;
  lcd.clear();
    wait();
    
  Serial.println("you chose bin 2");
  for(int i=0;i<2;i++)
  {
    n.write(30);
    delay(j);
     
    n.write(89);
    j=j-5;
  }
    lcd.clear();
    dump();
    delay(4000);
    //after exe 
    if(z==1)
    {
      lcd.clear();
      done();
    areyoudone();
    }
    na=4;
    servobin1default(na);
  }

  
 
  if(butt==4)
  {
    //bio
    lcd.clear();
    choice4();
    Serial.println("waste bin 4");
    int z=1;
    
  int j=350;
  lcd.clear();
    wait();
    
  Serial.println("you chose bin 2");
  for(int i=0;i<3;i++)
  {
    n.write(30);
    delay(j);
     
    n.write(89);
    j=j-5;
  }
    agri=1;
    lcd.clear();
    dump();
    delay(4000);
    //after exe 
    if(z==1)
    {
      lcd.clear();
      done();
    areyoudone();
    }
    na=3;
    servobin1default(na);
  }
    
  
  
  if(butt==5)
  {
   //metal 
   lcd.clear();
    choice5();
    Serial.println("waste bin 5");
    int z=1;
    
  int j=350;
  lcd.clear();
    wait();
    
  Serial.println("you chose bin 2");
  for(int i=0;i<4;i++)
  {
    n.write(30);
    delay(j);
     
    n.write(89);
    j=j-5;
  }
    lcd.clear();
    dump();
    delay(4000);
    //aftr exe
    if(z==1)
    {
      lcd.clear();
      done();
    areyoudone();
    }
    na=2;
    servobin1default(na);
  }
  
  if(butt==6)
  {
    //ewaste
    lcd.clear();
    choice6();
    Serial.println("waste bin 6");
    int z=0;
   
    int j=350;
  lcd.clear();
    wait();
for(int i=0;i<5;i++)
  {
    n.write(30);
    delay(350);
     
    n.write(89);
    j=j-5;
  }
    lcd.clear();
    dump();
    delay(4000);
    //after exe 
   
   
      lcd.clear();
      done();
    areyoudone();
   
    na=1;
    servobin1default(na);
  }
  if (servopos==0&&areyoudonestatus==1)
  { 
    /*lcd.clear();
    wait();
    int a=sensor();
    Serial.print("SENSOR 1 = ");
    Serial.println(a);
    int b=sensor1();
    Serial.print("SENSOR 2 = ");
    Serial.println(b);

    int c=sensor2();
    Serial.print("SENSOR 3 = ");
    Serial.println(c);

     int d=sensor3();
     Serial.print("SENSOR 4 = ");
     Serial.println(d);

     int e=sensor4();
     Serial.print("SENSOR 5 = ");
     Serial.println(e);
*/   lcd.clear();

Thank();
     int f=sensor5();
     Serial.print("SENSOR 6 = ");
     Serial.println(f);
  }
  
  
}
void welcome()
     {delay(1000);
     lcd.print("WELCOME TO Z.W.I.T");
     Serial.println("wlcometo zwit");
    lcd.setCursor(0,1);
 
    lcd.print(" SMART BIN");
    
     }
     void selection()
     {
    lcd.print("PLEASE SELECT");
    lcd.setCursor(0,1);
    Serial.println("please solect the typeof waste");
  lcd.print("TYPE OF WASTE "); 
  
   
     
     }
     void choice1()
         {
         lcd.print("YOU HAVE CHOSEN");
         Serial.println("you have chosen plastic");
         lcd.setCursor(0,1);
    lcd.print(" PLASTIC");
   
         }
           void choice2()
         {
         lcd.print("YOU HAVE CHOSEN");
         Serial.println("you have chosen glass");
         lcd.setCursor(0,1);
    lcd.print(" Glass");
         }
           void choice3()
         {
         lcd.print("YOU HAVE CHOSEN");
         Serial.println("you have chosen paper");
         lcd.setCursor(0,1);
    lcd.print(" PAPER");
         }
           void choice4()
         {
         lcd.print("YOU HAVE CHOSEN");
         lcd.setCursor(0,1);
         Serial.println("you have chosen organic");
    lcd.print(" Organic");
         }
           void choice5()
         {
         lcd.print("YOU HAVE CHOSEN");
         lcd.setCursor(0,1);
         Serial.println("youhave chosen Metal");
    lcd.print(" METAL");
         }
           void choice6()
         {
         lcd.print("YOU HAVE CHOSEN");
         lcd.setCursor(0,1);
         Serial.println("you have chosen e waste");
    lcd.print("E-WASTE");
         }
         void reward()
         {
         lcd.print("DO YOU WANT ");
         lcd.setCursor(0,1);
         Serial.println("do you want a reward");
    lcd.print("A REWARD ?");
     
     
         }
         void done()
         {
         lcd.print("ARE YOU DONE ?");
         Serial.println("are you done");
         lcd.setCursor(0,1);
    lcd.print("");
         }
         void Thank()
         {lcd.print("THANK YOU FOR KEEPING OUR CITY CLEAN!");
         Serial.println("thank you for keeping your city clean");
          for (int positionCounter = 0; positionCounter < 38; positionCounter++) {
    // scroll one position left:;=
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(350);
         }
         }
         void dump()
         {
         lcd.print("YOU MAY DUMP ");
         lcd.setCursor(0,1);
         Serial.println("you may dump the waste now");
    lcd.print("THE WASTE NOW!");
         }
        int buttons()
        {int q=0;
         do{ int b=analogRead(A15);Serial.println(b);
          if(b>50)
         {
          for(int i=0;i<10;i++)
          {Serial.println("inside for");
            b=0;
            b=analogRead(A15);
            Serial.println(b);
            q=b+q;
          }
         }
         b=q/10;
        
  if(b>60&&b<75)
  {Serial.println("bin 1");return 1;
  }
  else if(b>230&&b<250)
  {
   Serial.println("bin 2"); return 2;
  }
  else if(b>500&&b<520)
  {
   Serial.println("bin 3"); return 3;
  }
  else if(b>300&&b<330)
  {
   Serial.println("bin 4");return 4;
  }
  else if(b>175&&b<190)
  {
   Serial.println("bin 5");return 5;
  }
  else if(b>90&&b<100)
  {
   Serial.println("bin 6");return 6;
  }
  else if(b>1000&&b<1022)
  {
   Serial.println("yes"); return 7;
  }
  else if(b>20&&b<39)
  {
   Serial.println("NO"); 
  } 
        }while(1);}
          void wait()
         {
         lcd.print("PLEASE");
         Serial.println("Please Wait");
         lcd.setCursor(0,1);
    lcd.print("WAIT");
         }

int servobin1()
{
  lcd.clear();
    wait();
  return 1;
}
int servobin1default(int na)
{
  int j=450;
  for(int i=0;i<na;i++)
  {
    Serial.println(na);
    n.write(30);
    Serial.println(na);
    delay(j);
    
    
  }
   n.write(89);
}
int servobin2()
{
  int j=350;
  lcd.clear();
    wait();
    
  Serial.println("you chose bin 2");
  for(int i=0;i<1;i++)
  {
    n.write(30);
    delay(j);
     
    n.write(89);
    j=j-5;
  }
    
  return 1;
}
int servobin3()
{
  int j=350;
  lcd.clear();
    wait();
  for(int i=0;i<2;i++)
  {
    n.write(30);
    delay(j);
     
    n.write(89);
    j=j-5;
  }
  return 1;
}
int servobin4()
{
  int j=350;
  lcd.clear();
    wait();
    for(int i=0;i<3;i++)
  {
    n.write(30);
    delay(j);
     
    n.write(89);
    j=j-5;
  }
  return 1;
}
int servobin5()
{ int j;
  lcd.clear();
    wait();
  for(int i=0;i<4;i++)
  {
    n.write(30);
    delay(j);
     
    n.write(89);
    j=j-5;
  }
  return 1;
}
int servobin6()
{
  int j=350;
  lcd.clear();
    wait();
for(int i=0;i<5;i++)
  {
    n.write(30);
    delay(j);
     
    n.write(89);
    j=j-5;
  }
  return 1;
}
int servodefault()
{
  lcd.clear();
    wait();
  //code for servo to go to default
  servopos=0;
}
int areyoudone()
{ int j,k;
  Serial.println("you are in are you done");
  int butt=buttons();
  if(butt==7)
  {
    Serial.println("yes you are done");

    areyoudonestatus=1;// means you are done
     
    lcd.clear();
    reward();
    rewardq();
    
  }
  if(k==1)
  {
    Serial.println("you are not done");
        
   
  }
}



int rewardq()
{ int j,k;j=k=0;
  Serial.println("do you want reward");
  
  reward();
  int butt=buttons();
  if (butt==7)
  {for (int pos = 180; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rwdservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 0; pos <= 0; pos += 1) { // goes from 180 degrees to 0 degrees
    rwdservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
    
  }
 
}



int sensor()
{
int x,y;
  float duration, distance,j;
 for(int i=1;i<=10;i++)
  { Serial.println(i);
    
    
    digitalWrite(t, LOW); 
    delayMicroseconds(2);
    digitalWrite(t, HIGH);
    delayMicroseconds(10);
    digitalWrite(t, LOW);
    duration = pulseIn(e, HIGH);
    distance = (duration / 2) * 0.0344-1;
   Serial.println(distance);
  
        if(distance<=full)
         {
          x=1;
          
         }
         else x=0;
        j=j+x;
        delay(500);
    }

  if(j>=4)
   y=1;
 else y=0;
    
  return y;

}


int sensor1()
{
int x,y;
  float duration, distance,j=0;
 for(int i=1;i<=10;i++)
  {
    digitalWrite(t1, LOW); 
    delayMicroseconds(2);
    digitalWrite(t1, HIGH);
    delayMicroseconds(10);
    digitalWrite(t1, LOW);
    duration = pulseIn(e1, HIGH);
    distance = (duration / 2) * 0.0344-1;
    Serial.println(distance);
  
        if(distance<=full)
         {
          x=1;
          
         }
         else x=0;
        j=j+x;
        delay(500);
    }

  if(j>=4)
   y=1;
 else y=0;
    
  return y;

}
int sensor2()
{
int x,y;
  float duration, distance,j;
 for(int i=1;i<=10;i++)
  {
    digitalWrite(t2, LOW); 
    delayMicroseconds(2);
    digitalWrite(t2, HIGH);
    delayMicroseconds(10);
    digitalWrite(t2, LOW);
    duration = pulseIn(e2, HIGH);
    distance = (duration / 2) * 0.0344-1;
   Serial.println(distance);
  
        if(distance<=full)
         {
          x=1;
          
         }
         else x=0;
        j=j+x;
        delay(500);
    }

  if(j>=4)
   y=1;
 else y=0;
    
  return y;

}


int sensor3()
{
int x,y;
  float duration, distance,j;
 for(int i=1;i<=10;i++)
  {
    digitalWrite(t3, LOW); 
    delayMicroseconds(2);
    digitalWrite(t3, HIGH);
    delayMicroseconds(10);
    digitalWrite(t3, LOW);
    duration = pulseIn(e3, HIGH);
    distance = (duration / 2) * 0.0344-1;
   Serial.println(distance);
    
        if(distance<=full)
         {
          x=1;

         }
         else x=0;
        j=j+x;
        delay(500);
    }

  if(j>=4)
   y=1;
 else y=0;
    
  return y;

}


int sensor4()
{
int x,y;
  float duration, distance,j;
 for(int i=1;i<=10;i++)
  {
    digitalWrite(t4, LOW); 
    delayMicroseconds(2);
    digitalWrite(t4, HIGH);
    delayMicroseconds(10);
    digitalWrite(t4, LOW);
    duration = pulseIn(e4, HIGH);
    distance = (duration / 2) * 0.0344-1;
   Serial.println(distance);
    
        if(distance<=full)
         {
          x=1;

         }
         else x=0;
        j=j+x;
        delay(500);
    }

  if(j>=4)
   y=1;
 else y=0;
    
  return y;

}


int sensor5()
{
int x,y;
  float duration, distance,j;
 for(int i=1;i<=10;i++)
  {
    digitalWrite(t5, LOW); 
    delayMicroseconds(2);
    digitalWrite(t5, HIGH);
    delayMicroseconds(10);
    digitalWrite(t5, LOW);
    duration = pulseIn(e5, HIGH);
    distance = (duration / 2) * 0.0344-1;
   Serial.println(distance);
  
        if(distance<=full)
         {
          x=1;

         }
         else x=0;
        j=j+x;
        
    }

  if(j>=4)
   y=1;
 else y=0;
    delay(500);
  return y;

}
//this code was written by NARAYAN AND ADITHYA
//we are the studenst of bvmgf
//we are just writing this for making the number of lines
/*#include <ESP8266WiFi.h>
 
// replace with your channel's thingspeak API key, 
String apiKey = "4KX9X1IE5AVXHZQF";
const char* ssid = "ATAL Lab Wifi";
const char* password = "atladmin@21";
 
const char* server = "api.thingspeak.com";

const int pin_Out_S0 = 8;
const int pin_Out_S1 = 9;
const int pin_Out_S2 = 10;
const int pin_In_Mux1 = A0;
 int Mux1_State[8] = {0};
 String bin[100]={"ad"};
void updateMux1();

 
WiFiClient client;
   
 
void setup() {                
  Serial.begin(115200);
  delay(10);
  pinMode(pin_Out_S0, OUTPUT);
  pinMode(pin_Out_S1, OUTPUT);
  pinMode(pin_Out_S2, OUTPUT);
  pinMode(pin_In_Mux1, INPUT);
  
  WiFi.begin(ssid, password);
 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
}
 
 
void loop() {
    updateMux1();
  for(int i = 0; i < 8; i ++) 
  {
    if(i == 7) 
    {
      Serial.println(Mux1_State[i]);
    }
    else 
    {
      Serial.print(Mux1_State[i]);
      Serial.print(",");
    }
  }

   if(Mux1_State[0]>800)   //checks 1st element as trigger
   {
    for(int i = 1; i < 8; i ++) 
  {if(Mux1_State[i]>1000)
  bin[i]={"Full"}; //assigns nins to full or empty
  else
  bin[i]={"Empty"};
   }
  /*char s1[] ="full";
  char s2[] ="full";
  char s3[] ="full";
  char s4[] ="full";
  char s5[] ="full";
  char s6[] ="full";
  char s7[] ="full";*///}
