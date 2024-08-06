const int soilSensor = A0;
const int motor = 7;
const int red = 8;
const int green = 9;
const int blue = 10;

void setup() {
  pinMode(soilSensor, INPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);

  // Motor off by default
  digitalWrite(motor, LOW);
}

void offLEDs() {
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}

void loop() {
  int soilSensorVal = analogRead(soilSensor);
  
  if (Serial.available() > 0) {
    char winforms = Serial.read();
    if (winforms == 'A') {
      digitalWrite(motor, HIGH);
    }   
    else if (winforms == 'B') {
      digitalWrite(motor, LOW);
    }
  }

  Serial.println(soilSensorVal);

  if (soilSensorVal < 370) {
    offLEDs();
    digitalWrite(green, HIGH);
  } 
  else if (soilSensorVal >= 370 && soilSensorVal <= 600) {
    offLEDs();
    digitalWrite(blue, HIGH);
  }
  else if (soilSensorVal > 600 && soilSensorVal < 1000) {
    offLEDs();
    digitalWrite(red, HIGH);
  }
  else {
    offLEDs();
  }

  delay(500);
}