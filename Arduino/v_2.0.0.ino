#include <Servo.h>
#include <LiquidCrystal.h>

//define the two servo motors
Servo n;
Servo rwdservo;
const int servo_delay = 350;

//setup display
int Contrast = 20;
LiquidCrystal lcd(11, 12, 10, 9, 8, 7);

int is_done = 0;
int na = 0;

void setup()
{
  Serial.begin(9600);

  //initialize servos
  n.attach(3);
  rwdservo.attach(52);
  rwdservo.write(180);

  //setup contrast
  analogWrite(6, Contrast);

  //initialize lcd
  lcd.begin(16, 2);
  welcome();
}

void loop()
{

  lcd.clear();
  selection();

  n.write(90);

  //wait for new input
  Serial.println("please select the type of waste");
  int selected_waste = 0;

  while (Serial.available() == 0)
    ;
  selected_waste = Serial.parseInt();

  lcd.clear();



  switch (selected_waste)
  {
    case 1:
      choice("Plastic");
      Serial.println("waste bin 1");
      lcd.clear();

      dump();
      delay(4000);

      lcd.clear();
      areyoudone();
      rewardq();

      break;

    case 2:
      choice("Glass");
      Serial.println("waste bin 2");
      lcd.clear();

      wait();
      Serial.println("you chose bin 2");
      for (int i = 0; i < 1; i++)
      {
        n.write(70);
        delay(servo_delay);
        n.write(89);
      }

      finalize(3);

      break;

    case 3:
      lcd.clear();
      choice("Paper");
      Serial.println("waste bin 3");

      lcd.clear();
      wait();

      Serial.println("you chose bin 2");
      for (int i = 0; i < 2; i++)
      {
        n.write(30);
        delay(servo_delay);
        n.write(89);
      }

      finalize(2);

      break;

    case 4:
      lcd.clear();
      choice("organic");
      Serial.println("waste bin 4");
      int z = 1;

      lcd.clear();
      wait();

      Serial.println("you chose bin 2");
      for (int i = 0; i < 3; i++)
      {
        n.write(30);
        delay(servo_delay);
        n.write(89);
      }

      finalize(1);

      break;

    default:
      Serial.println("invalid input");
      break;
  }
}

void welcome()
{
  lcd.print("WELCOME TO Z.W.I.T");
  Serial.println("wlcometo zwit");
  lcd.setCursor(0, 1);
  lcd.print(" SMART BIN");
  delay(1000);
}

void selection()
{
  lcd.print("PLEASE SELECT");
  lcd.setCursor(0, 1);
  Serial.println("please solect the typeof waste");
  lcd.print("TYPE OF WASTE ");
}

void choice(String type)
{
  lcd.print("YOU HAVE CHOSEN");
  Serial.print("you have chosen ");
  Serial.println(type);
  lcd.setCursor(0, 1);
  lcd.print(type);
}

int servobin1default(int na)
{
  int j = 450;
  for (int i = 0; i < na; i++)
  {
    Serial.println(na);
    n.write(30);
    Serial.println(na);
    delay(j);
  }
  n.write(89);
  Serial.println("A!");
}

void finalize(int na)
{
  lcd.clear();
  dump();
  delay(4000);

  areyoudone();
  reward();

  rewardq();

  servobin1default(na);

}

void dump()
{
  lcd.print("YOU MAY DUMP ");
  lcd.setCursor(0, 1);
  Serial.println("you may dump the waste now");
  lcd.print("THE WASTE NOW!");
}
void wait()
{
  lcd.print("PLEASE");
  Serial.println("Please Wait");
  lcd.setCursor(0, 1);
  lcd.print("WAIT");
}

int rewardq()
{
  int j, k;
  j = k = 0;
  lcd.clear();
  Serial.println("do you want reward");
  while (1)
  {

    reward();
    if (Serial.available() > 0)
    {
      int butt = Serial.parseInt();
      if (butt == 1)
      {
        Serial.println("gjghjhgjgj");
        for (int pos = 180; pos >= 0; pos -= 1)
        { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          rwdservo.write(pos); // tell servo to go to position in variable 'pos'
          delay(15);           // waits 15ms for the servo to reach the position
        }
        for (int pos = 0; pos <= 0; pos += 1)
        { // goes from 180 degrees to 0 degrees
          rwdservo.write(pos); // tell servo to go to position in variable 'pos'
          delay(15);           // waits 15ms for the servo to reach the position
        }

        break;
      }
      if (butt == 2)
      {
        break;
      }
    }
  }
}

void reward()
{
  lcd.print("DO YOU WANT ");
  lcd.setCursor(0, 1);
  Serial.println("do you want a reward");
  lcd.print("A REWARD ?");
}

void done()
{
  lcd.print("ARE YOU DONE ?");
  Serial.println("are you done");
  lcd.setCursor(0, 1);
  lcd.print("");
}

int areyoudone()
{
  int k = 1;
  lcd.clear();
  done();
  delay(200);
  while (1)
  {

    Serial.println("{=ssfsf");
    if (Serial.available() > 0)
    {
      k = Serial.parseInt();
      Serial.println("hi");
      Serial.println(k);
      if (k == 1)
      {
        Serial.println("you are in are you done");

        Serial.println("yes you are done");

        is_done = 1;

        lcd.clear();
        break;
      }
      if (k == 2)
      {
        break;
      }
    }
  }
}
