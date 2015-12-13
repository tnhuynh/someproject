



unsigned long pingTimer;      // Holds the times when the next ping should happen for each sensor.
unsigned long cm;             // Where the ping distances are stored.

void pingInit() {
  pingTimer = millis() + 75;  // First ping starts at 75ms, gives time for the Arduino to chill before starting.
}

void echoCheck() {            // If ping received, set the sensor distance to array.
  if (sonarFront.check_timer()) {
    cm = sonarFront.ping_result / US_ROUNDTRIP_CM;
  }
}

void sonarScan() {       // Sensor ping cycle complete, do something with the results.
  if (millis() >= pingTimer) {
    pingTimer += PING_INTERVAL;
    sonarFront.timer_stop();
    cm = 0;
    sonarFront.ping_timer(echoCheck);
  }
}

boolean checkFront() {
  if (cm < FRONT_CLOSE) {
    if (!fiiireee) switchState(RED_MOTOR);
    else return true;
  }
  return false;
}

void sonarReadingInit() {
  long time_init = millis();
  while (millis() - time_init < 3000) {
    sonarScan();
  }
}
