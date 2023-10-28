/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
   

#ifdef L298_MOTOR_DRIVER
  void initMotorController() {
    digitalWrite(RIGHT_MOTOR_ENABLE, HIGH);
    digitalWrite(LEFT_MOTOR_ENABLE, HIGH);
    digitalWrite(BACK_MOTOR_ENABLE, HIGH);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    
    if (i == LEFT) { 
      if      (reverse == 0) { analogWrite(LEFT_MOTOR_FORWARD, spd); analogWrite(LEFT_MOTOR_BACKWARD, 0); }
      else if (reverse == 1) { analogWrite(LEFT_MOTOR_BACKWARD, spd); analogWrite(LEFT_MOTOR_FORWARD, 0); }
    }
    else if(i == RIGHT) {
      if      (reverse == 0) { analogWrite(RIGHT_MOTOR_FORWARD, spd); analogWrite(RIGHT_MOTOR_BACKWARD, 0); }
      else if (reverse == 1) { analogWrite(RIGHT_MOTOR_BACKWARD, spd); analogWrite(RIGHT_MOTOR_FORWARD, 0); }
    }
    else {
      if      (reverse == 0) { analogWrite(BACK_MOTOR_FORWARD, spd); analogWrite(BACK_MOTOR_BACKWARD, 0); }
      else if (reverse == 1) { analogWrite(BACK_MOTOR_BACKWARD, spd); analogWrite(BACK_MOTOR_FORWARD, 0); }
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