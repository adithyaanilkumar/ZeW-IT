#include <Servo.h>
Servo servolo;
int b1,b2,b3,b4=2,b5,b6,b7,b8,b9,b10,b11,b12;
int t=52,e=53,t1=50,e1=51,t2=48,e2=49,t3=46,e3=47,t4=44,e4=45,t5=42,e5=43;
int led1,led2,ledre;
int dcspin=10;
int motorPin1  = 5;  
int motorPin2  = 6;  
int full =10;
int agri=0;
int steprpos=0;//default =0;
int dc=0;
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
int reward();
int stprbin1();
int stprbin2();
int stprbin3();
int stprbin4();
int stprbin5();
int stprbin6();
int angle = 10;
void setup() 
{
  Serial.begin (9600);
  pinMode(b11,INPUT);
  pinMode(b12,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(ledre,OUTPUT);
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
    Serial.println("waste bin 1");
    int z=0;
    z=stprbin1();
    lidopen();
    if(z==1)
    {
    areyoudone();
    }
  }

  if(w2==1)
  {
    Serial.println("waste bin 2");
    int z=0;
    z=stprbin2();
    lidopen();
    //after exe
    areyoudone();
  }
  if(w3==1)
  {
    Serial.println("waste bin 3");
    int z=0;
    z=stprbin3();
    lidopen();
    //after exe 
    areyoudone();

  }
 
  if(w4==1)
  {
    Serial.println("waste bin 4");
    int z=0;
    z=stprbin4();
    agri=1;
    lidopen();
    //after exe 
    areyoudone();
    
  }
  
  if(w5==1)
  {
    Serial.println("waste bin 5");
    int z=0;
    z=stprbin5();
    lidopen();
    //aftr exe
    areyoudone();
  }
  if(w6==1)
  {
    Serial.println("waste bin 6");
    int z=0;
    z=stprbin6();
    lidopen();
    //after exe 
    areyoudone();
   
  }
  

  if(steprpos==0&&agri==1)
  {
    dc =dcmix();
    
  }
  if (steprpos==0)
  {  
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
  }
}
 
int stprbin1()
{
  //code for stpr
  //after exe
  lidopen();
  return 1;
}
int stprbin2()
{
  //code for stpr
  //after exe
  lidopen();
  return 1;
}
int stprbin3()
{
  //code for stpr
  //after exe
  lidopen();
  return 1;
}
int stprbin4()
{
  //code for stpr
  //after exe
  lidopen();
  return 1;
}
int stprbin5()
{
  //code for stpr
  //after exe
  lidopen();
  return 1;
}
int stprbin6()
{
  //code for stpr
  //after exe
  lidopen();
  return 1;
}
int stprdefault()
{
  //code for stpr to go to default
  steprpos=0;
}
int areyoudone()
{ int j,k;
  Serial.println("you are in are you done");
  digitalWrite(led1,HIGH);
  j=digitalRead(b11);//b11 is yes
  k=digitalRead(b12);//b12is no
  if(j==1)
  {
    Serial.println("yes you are done");

    digitalWrite(led1,LOW);
    lidclose();
    stprdefault();
    rewardq();
    
  }
  if(k==1)
  {
    Serial.println("you are not done");

    digitalWrite(led1,LOW);
    
   
  }
}

int lidopen()
{   Serial.println("lid opening");
    for(angle = 10; angle < 180; angle++)  
  {                                  
    servolo.write(angle);               
    delay(15);                   
  } 
  //code for servo lid
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
  digitalWrite(ledre,HIGH);
  j=digitalRead(b7);//here b7 is yes
  k=digitalRead(b8);//here b8 is no
  if (j==1)
  {
    //code for reward out
  }
  else 
  {
  if(k==1)
  {
    stprdefault();

}
  }
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
