#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  
Servo servolo;
void selection();
void choice1();
void choice2();
void choice3();
void choice4();
void choice5();
void choice6();
void done();
void Thank();
void reward();
void welcome();
void dump();
void wait();
const int b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12;
const int t,e,t1,e1,t2,e2,t3,e3,t4,e4,t5,e5;
int areyoudonestatus=0;
int dcspin=10;
const int motorPin1;  
const int motorPin2;  
int full =10;
int agri=0;
int servopos=1;//default =0;
int dc=0;
int statusupdate();
int sensor();
int sensor2();
int sensor1();
int sensor3();
int sensor4();
int sensor5();
int dcmix();
int lidopen();
int lidclose();
int areyoudone();
int rewardq();
int servobin1();
int servobin2();
int servobin3();
int servobin4();
int servobin5();
int servobin6();
int zwitpoints();
void points();
int angle = 10;
#include <LiquidCrystal.h>  
int Contrast=20;
LiquidCrystal lcd(12, 11, 8, 6, 4, 2);   
void setup() 
{
  SPI.begin();
  Serial.begin (9600);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);
  pinMode(b4,INPUT);
  pinMode(b5,INPUT);
  pinMode(b6,INPUT);
  pinMode(b7,INPUT);
  pinMode(b8,INPUT);
  pinMode(b9,INPUT);
  pinMode(b10,INPUT);
  pinMode(b11,INPUT);
  pinMode(b12,INPUT);
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
  pinMode(motorPin1, OUTPUT);
  
  pinMode(motorPin2, OUTPUT);
  servolo.attach(8);
  servolo.write(angle);

}
void loop()
{ Serial.println("loop running");
lcd.clear();
  selection();
  int slid=0;
  int w1,w2,w3,w4,w5,w6;
  w1=w2=w3=w4=w5=w6=0;
  w1=digitalRead(b1);
  w2=digitalRead(b2);
  w3=digitalRead(b3);
  w4=digitalRead(b4);
  w5=digitalRead(b5);
  w6=digitalRead(b6);
   
 // here let w4 be the agricultural waste
  if(w1==1)
  {
    //plastic
    lcd.clear();
    choice1();
    Serial.println("waste bin 1");
    int z=0;
    z=servobin1();
    lidopen();
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

  if(w2==1)
  {
    //glass
    lcd.clear();
    choice2();
    Serial.println("waste bin 2");
    int z=0;
    z=servobin2();
    lidopen();
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
  
  }
  if(w3==1)
  {
    //paper
    lcd.clear();
    choice3();
    Serial.println("waste bin 3");
    int z=0;
    z=servobin3();
    lidopen();
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
  }

  
 
  if(w4==1)
  {
    //bio
    lcd.clear();
    choice4();
    Serial.println("waste bin 4");
    int z=0;
    z=servobin4();
    agri=1;
    lidopen();
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
  }
    
  
  
  if(w5==1)
  {
   //metal 
   lcd.clear();
    choice5();
    Serial.println("waste bin 5");
    int z=0;
    z=servobin5();
    lidopen();
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
  }
  
  if(w6==1)
  {
    //ewaste
    lcd.clear();
    choice6();
    Serial.println("waste bin 6");
    int z=0;
    z=servobin6();
    lidopen();
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
  }
   
  
  

  if(servopos==0&&agri==1&&areyoudonestatus==1)
  {
    lcd.clear();
    wait();
    //pls wait
    dc =dcmix();
   
  }
  if (servopos==0&&areyoudonestatus==1)
  { 
    lcd.clear();
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

     int f=sensor5();
     Serial.print("SENSOR 6 = ");
     Serial.println(f);
     statusupdate();
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
     
     lcd.clear();
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
         
          void wait()
         {
         lcd.print("PLEASE");
         Serial.println("Please Wait");
         lcd.setCursor(0,1);
    lcd.print("WAIT");
         }

int statusupdate()
{
  lcd.clear();
    wait();
  //code for sending the status of the bin to wifimodule
}
 
int servobin1()
{
  lcd.clear();
    wait();
  //code for servo
  //after exe
  return 1;
}
int servobin1default()
{
  //code for returning servo from bin one position
}
int servobin2()
{
  lcd.clear();
    wait();
  //code for servo
  //after exe
  return 1;
}
int servobin3()
{
  lcd.clear();
    wait();
  //code for servo
  //after exe
  return 1;
}
int servobin4()
{
  lcd.clear();
    wait();
  //code for servo
  //after exe
  return 1;
}
int servobin5()
{
  lcd.clear();
    wait();
  //code for servo
  //after exe
  return 1;
}
int servobin6()
{
  lcd.clear();
    wait();
  //code for servo
  //after exe
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
  j=digitalRead(b11);//b11 is yes
  k=digitalRead(b12);//b12is no
  if(j==1)
  {
    Serial.println("yes you are done");

    areyoudonestatus=1;// means you are done
    lidclose();
    lcd.clear();
    reward();
    rewardq();
    
  }
  if(k==1)
  {
    Serial.println("you are not done");
        
   
  }
}

int lidopen()
{   Serial.println("lid opening");
    for(angle = 10; angle < 180; angle++)  
  {                                  
    servolo.write(angle);               
    delay(15);                   
  } 
  return 1;//1 for open
}
int lidclose()
{
  Serial.println("lid closing");
    for(angle; angle!=0; angle--)  
  {                                  
    servolo.write(angle);               
    delay(15);                   
  } 
  
}
int rewardq()
{ int j,k;j=k=0;
  Serial.println("do you want reward");
  reward();
  j=digitalRead(b11);//here b7 is yes
  k=digitalRead(b12);//here b8 is no
  if (j==1)
  {
    //code for zwit points
  }
  else if(j==0)
  {
    zwitpoints();
  }
 
}
int zwitpoints()
{
  points();
  int j,k;j=k=0;
  j=digitalRead(b11);//yes
  k=digitalRead(b12);//no
  if(j==1)
  {
    //code for crediting the points
  }
  else if(k==1)
  {
    lcd.clear();
    Thank();
  }
}
void points()
{lcd.clear();

  lcd.print("do you want");
   lcd.setCursor(0, 1);
   lcd.print("Z.W.I.T POINTS ?");
   
}

int dcmix()
{  for(int i=1;i<=dcspin;i++)
   {
    Serial.println("dc");
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(5000); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(1000);
    return 1;
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
