/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
   
#ifdef ARDUINO_ENC_COUNTER
  //below can be changed, but should be PORTD pins; 
  //otherwise additional changes in the code are required
  #define LEFT_ENC_PIN_A A2  //pin 2
  #define LEFT_ENC_PIN_B A1  //pin 3
  
  //below can be changed, but should be PORTC pins
  #define RIGHT_ENC_PIN_A 2  //pin A4
  #define RIGHT_ENC_PIN_B 3   //pin A5

  #define BACK_ENC_PIN_A 4
  #define BACK_ENC_PIN_B 5
#endif
   
int readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

