#include <Servo.h>
#include <LiquidCrystal.h>
Servo n;
Servo rwdservo;
void selection();
void choice1();
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
int areyoudonestatus=0;
int full =10;
int agri=0;
int servopos=0;//default =0;
int areyoudone();
int rewardq();
int butt;  
int Contrast=20;
LiquidCrystal lcd(11, 12, 10, 9, 8, 7);
void setup() 
{n.attach(3);
  rwdservo.attach(52);
  rwdservo.write(180);
  Serial.begin (9600);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
      int mno;
}  
void loop()
{
  
  int b=0;
  Serial.println("loop running");
lcd.clear();
  selection();
 Serial.println("please select the type of waste") ;
int butt=0;
n.write(90);
while(Serial.available()==0);
 butt=Serial.parseInt();

if(butt==1)
{
  //plastic
    lcd.clear();
    choice1();
    Serial.println("waste bin 1");
    int z=1;
   
    lcd.clear();
    dump();
    delay(4000);
    lcd.clear();
    areyoudone();
   // reward();
    rewardq();
  
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
    reward();
    rewardq();
    
    na=3;
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
 
    areyoudone();
    reward();
    rewardq();
    
    na=2;
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
     
    areyoudone();
    reward();
    
   
    rewardq();
    
    na=1;
    servobin1default(na);
  
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
        /* void Thank()
         {lcd.print("THANK YOU FOR KEEPING OUR CITY CLEAN!");
         Serial.println("thank you for keeping your city clean");
          for (int positionCounter = 0; positionCounter < 38; positionCounter++) {
    // scroll one position left:;=
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(350);
         }
         }*/
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
   Serial.println("A!");
}




int rewardq()
{ int j,k;j=k=0;
lcd.clear();
  Serial.println("do you want reward");
 while(1){
  
  reward();
  if(Serial.available()>0){
  int butt=Serial.parseInt();
  if (butt==1)
  {
    Serial.println("gjghjhgjgj");for (int pos = 180; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rwdservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 0; pos <= 0; pos += 1) { // goes from 180 degrees to 0 degrees
    rwdservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
    
  break;}
  if(butt==2){break;}
 }}
}

         
         
int areyoudone()
{int k=1;
lcd.clear();
 done();
 delay(200);
while(1){
  
  Serial.println("{=ssfsf");
  if(Serial.available()>0){
  k=Serial.parseInt();
  Serial.println("hi");
  Serial.println(k);
  if(k==1)
  {
  Serial.println("you are in are you done");
  
    Serial.println("yes you are done");

    areyoudonestatus=1;// means you are done
     
    lcd.clear();
    break;
  }
  if(k==2)
  {
    break;
  }

  
  
  }
}}
