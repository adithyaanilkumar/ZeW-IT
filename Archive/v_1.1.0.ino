void setup() {
Serial.begin(9600);

}

void loop() {
  int b=analogRead(A7);
  if(b>59&&b<62)
  {Serial.println("bin 1");}
  else if(b>235&&b<238)
  {
   Serial.println("bin 2"); 
  }
  else if(b>506&&b<509)
  {
   Serial.println("bin 3"); 
  }
  else if(b>316&&b<319)
  {
   Serial.println("bin 4"); 
  }
  else if(b>40&&b<43)
  {
   Serial.println("bin 5"); 
  }
  else if(b>89&&b<92)
  {
   Serial.println("bin 6"); 
  }
  else if(b>1020&&b<1022)
  {
   Serial.println("yes"); 
  }
  else if(b>17&&b<19)
  {
   Serial.println("NO"); 
  }
}
