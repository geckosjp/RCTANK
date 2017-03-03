
const int LED     = 13;
const int motorR1 =  8;
const int motorR2 =  6;
const int motorL1 = 10;
const int motorL2 =  5;
const int PWM_R   =  9;
const int PWM_L   = 11;
String row;

void setup()
{
  digitalWrite(LED,LOW);
  pinMode(LED,OUTPUT);

  analogWrite(PWM_R,0);
  analogWrite(PWM_L,0);
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,LOW);
  
  pinMode(motorR1,OUTPUT);
  pinMode(motorR2,OUTPUT);
  pinMode(motorL1,OUTPUT);
  pinMode(motorL2,OUTPUT);
  MotorRight(0);
  MotorLeft(0);
  // start serial port at 9600 bps:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.print("AT\r\n");
  while (Serial.available() > 0) {
    char c = Serial.read();
    row+=c;
    if (c == '\n') {
      //TODO ここで何かの処理をする
      if(row = "OK"){
        digitalWrite(LED,HIGH);
        Serial.println(row);
        row = "";
      }
    }
  }

}

void MotorRight(int Speed)
{
  if( 0 == Speed ){
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,LOW);
    analogWrite(PWM_R,Speed);
  } else if( 0 < Speed ){
    digitalWrite(motorR1,HIGH);
    digitalWrite(motorR2,LOW);
    analogWrite(PWM_R,Speed);
  } else if( 0 > Speed ){
    digitalWrite(motorR1,LOW);
    digitalWrite(motorR2,HIGH);
    analogWrite(PWM_R,abs(Speed));
  } else {}
}
    
void MotorLeft(int Speed)
{
  if( 0 == Speed ){
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,LOW);
    analogWrite(PWM_L,Speed);
  } else if( 0 < Speed ){
    digitalWrite(motorL1,LOW);
    digitalWrite(motorL2,HIGH);
    analogWrite(PWM_L,Speed);
  } else if( 0 > Speed ){
    digitalWrite(motorL1,HIGH);
    digitalWrite(motorL2,LOW);
    analogWrite(PWM_L,abs(Speed));
  } else {}
}

void loop()
{
// Serial.println("Start.");
//  delay(1000);
//  MotorRight(128);
//  MotorLeft(128);
//  delay(1000);
//  MotorRight(0);
//  MotorLeft(0);
//  delay(1000);
//  MotorRight(-128);
//  MotorLeft(-128);
}
