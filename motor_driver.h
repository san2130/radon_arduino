/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#define RIGHT_MOTOR_BACKWARD 6
#define LEFT_MOTOR_BACKWARD  12
#define RIGHT_MOTOR_FORWARD  7
#define LEFT_MOTOR_FORWARD   13
#define RIGHT_MOTOR_PWM 9
#define LEFT_MOTOR_PWM 10

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);