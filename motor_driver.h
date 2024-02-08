/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  #define RIGHT_MOTOR_BACKWARD 6
  #define LEFT_MOTOR_BACKWARD  12
  #define BACK_MOTOR_BACKWARD 8
  #define RIGHT_MOTOR_FORWARD  7
  #define LEFT_MOTOR_FORWARD   13
  #define BACK_MOTOR_FORWARD  A0
  #define RIGHT_MOTOR_PWM 9
  #define LEFT_MOTOR_PWM 10
  #define BACK_MOTOR_PWM 11
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed, int backSpeed);