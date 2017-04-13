int inpin =A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int val=(analogRead(inpin));
  delay(100);
  Serial.println(val);

}
int conv(int a){
  if(a>1000){
    return 1000;
  }
  else if(a>750){
    return 750;
  }
  else if(a>500){
    return 500;
  }
  else if (a>250){
    return 250;
  }
  else return 0;
}

