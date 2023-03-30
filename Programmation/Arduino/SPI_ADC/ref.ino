//int transistor = 5;      // Transistor connected to digital pin 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  //pinMode(transistor, OUTPUT);  // sets the pin as output

}

void loop() {
  // put your main code here, to run repeatedly:
  float in = analogRead(A0);        // analogRead values go from 0 to 1023
  //analogWrite(transistor, 255);         // analogWrite values from 0 to 255
  Serial.println((in/1023)*5000);   // Output en mV
  delay(10);

}
