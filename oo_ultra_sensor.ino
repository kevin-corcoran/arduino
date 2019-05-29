class UltraSensor {
public:
  /* Constructor */
  UltraSensor(int trig, int echo) {
    trig_pin_ = trig; echo_pin_ = echo;
    tol_ = 2;
  }

  void setup() {
    pinMode(trig_pin_, OUTPUT);
    pinMode(echo_pin_, INPUT);

    Serial.begin(9600);
    int dis = getDistance();
    dis = getDistance();
    setTripDistance(dis);
  }

  void loop() {

    current_distance_ = getDistance();

    if (abs(current_distance_ - trip_distance_) > tol_) {
      Serial.println("detection!");
      detected_ = true;
    } else {
      detected_ = false;
    }

    delay(10);
    // printValues();

  }

  // Setter
  void setTripDistance(int dis) {
    trip_distance_ = dis;
  }

  // Getter
  int getTripDistance() {
    return trip_distance_;
  }

  // Getter
  int getCurrentDistance() {
    return current_distance_;
  }

  // Getter
  int getTol() {
    // TODO
  }

  // Setter
  int setTol(int tol) {
    // TODO
  }

  //
  bool isDetected() {
    return detected_;
  }

  void printValues() {
    Serial.println("Trip Distance: ");
    Serial.println(trip_distance_);
    Serial.println("Current Distance: ");
    Serial.println(current_distance_);
    Serial.println("Detected?: ");
    Serial.println(detected_);
    delay(1000);
  }

private:
  int trig_pin_;
  int echo_pin_;
  int led_pin_;

  long duration_;
  int current_distance_;
  int trip_distance_;
  int tol_;
  bool detected_;

  // Private, since only this class needs it
  int getDistance() {
    // Clears the trigPin
    digitalWrite(trig_pin_, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trig_pin_, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin_, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration_ = pulseIn(echo_pin_, HIGH);
    // Prints the distance on the Serial Monitor
    // Serial.print("Distance: ");
    int distance = duration_*0.034/2;
    // Serial.println(distance);
    // Calculating the distance
    return distance;
  }

};

class Button {
public:
  // TODO
  /* Constructor - sets button pin number, default values for private class variables (is_pressed_) */

  //TODO
  // add setup and loop

  // TODO
  // make setters, and getters. Will we actually need any setters?

private:
  int is_pressed_;
};



// initialize UltraSensor class with trig pin 9 and echo pin 10
UltraSensor ultra_sensor(8, 12);

// TODO - initialize button class and use it to set trip distance.

 void setup() {
  // put your setup code here, to run once:
  ultra_sensor.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  ultra_sensor.loop();
  if (ultra_sensor.isDetected()) {
    /* code */
    // blinkLight?
  }
  if (false/* button is pressed */) {
    /* set trip distance */
  }
}

int builtinLED = 13;
void blinkLight() {
  digitalWrite(builtinLED, HIGH);
  delay(1000);
  digitalWrite(builtinLED, LOW);
  delay(1000);
}
