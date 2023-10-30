/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  #define RIGHT_MOTOR_BACKWARD 6
  #define LEFT_MOTOR_BACKWARD  7
  #define BACK_MOTOR_BACKWARD 8
  #define RIGHT_MOTOR_FORWARD  9
  #define LEFT_MOTOR_FORWARD   10
  #define BACK_MOTOR_FORWARD  A0
  #define RIGHT_MOTOR_PWM 11
  #define LEFT_MOTOR_PWM 12
  #define BACK_MOTOR_PWM 13
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed, int backSpeed);
