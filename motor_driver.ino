/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   

#ifdef L298_MOTOR_DRIVER
  void initMotorController() {
    // digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
    // digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
    // digitalWrite(BACK_MOTOR_ENABLE, HIGH);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned int reverse = 0;
  
//    if (spd < 256)
//    {
//      reverse = 1;
//    }
//    else if (spd >= 256 && spd < 512)
//    {
//      spd = spd-256;
//    }
//    else
//    {
//      spd = 0;
//    }
    if(spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    else if(spd>255)
    {
      spd = 0;
    }
    if (i == LEFT) { 
      analogWrite(LEFT_MOTOR_PWM, spd);
      if      (reverse == 0) { digitalWrite(LEFT_MOTOR_FORWARD, HIGH); digitalWrite(LEFT_MOTOR_BACKWARD, LOW); }
      else if (reverse == 1) { digitalWrite(LEFT_MOTOR_BACKWARD, HIGH); digitalWrite(LEFT_MOTOR_FORWARD, LOW); }
    }
    else if(i == RIGHT) {
      analogWrite(RIGHT_MOTOR_PWM, spd);
      if      (reverse == 0) { digitalWrite(RIGHT_MOTOR_FORWARD, HIGH); digitalWrite(RIGHT_MOTOR_BACKWARD, LOW); }
      else if (reverse == 1) { digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH); digitalWrite(RIGHT_MOTOR_FORWARD, LOW); }
    }
    else {
      analogWrite(BACK_MOTOR_PWM, spd);
      if      (reverse == 0) { digitalWrite(BACK_MOTOR_FORWARD, HIGH); digitalWrite(BACK_MOTOR_BACKWARD, LOW); }
      else if (reverse == 1) { digitalWrite(BACK_MOTOR_BACKWARD, HIGH); digitalWrite(BACK_MOTOR_FORWARD, LOW); }
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed, int backSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
    setMotorSpeed(BACK, backSpeed);
  }
#else
  #error A motor driver must be selected!
#endif

#endif