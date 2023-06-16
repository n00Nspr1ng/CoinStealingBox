// Motor Pin Number
#define A1 5  // Yello (A-1B)
#define A2 6  // Green (A-1A)

int incomingByte = 0; // serial data

void setup() {

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);

  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  
  Serial.begin(9600);

  Serial.println("select mode");
  Serial.println("1.move CCW");
  Serial.println("2.move CW");
  Serial.println("3.stop");

}
int  input = 0;
void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    input = incomingByte - 48; //convert ASCII code

  switch (input) { 
    case 1:         // if input=1 ....... motor turn counter-clockwise
      forward();
      break;
    case 2:         // if input=2 ....... motor turn clockwise
      backward();
      break;
    case 3:         // if input=1 ....... motor turn stop
      Stop();
      break;
  }
  delay(200);
  input=0;
}
}
void forward() {          //counter-clockwise
  analogWrite(A1, 255);
  analogWrite(A2, 0);
  delay(600);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
}

void backward() {         //clockwise
  analogWrite(A1, 0);
  analogWrite(A2, 210);
  delay(600);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
}

void Stop() {              //function of stop
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
}
