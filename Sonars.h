


#define MAX_DISTANCE    200   // Maximum distance (in cm) to ping.
#define PING_INTERVAL   33    // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).
#define FRONT_CLOSE 15

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

void oneSensorCycle() {       // Sensor ping cycle complete, do something with the results.
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


