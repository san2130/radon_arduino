/* *************************************************************
   Encoder definitions
   
   Add an "#ifdef" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */
   
#ifdef USE_BASE

#ifdef ARDUINO_ENC_COUNTER
  volatile int left_enc_pos = 0;
  volatile int right_enc_pos = 0;
  volatile int back_enc_pos = 0;
  static const int8_t ENC_STATES [] = {0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0};  //encoder lookup table
  
  /* Wrap the encoder reading function */
  int readEncoder(int i) {
    int left_pos=0;
    int right_pos=0;
    int back_pos=0;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE){
    left_pos = left_enc_pos;
    right_pos = right_enc_pos;
    back_pos = back_enc_pos;
  }

    if (i == LEFT) return left_pos;
    else if(i == RIGHT) return right_pos;
    else return back_pos;
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT){
      left_enc_pos=0;
      return;
    } else if(i == RIGHT){ 
      right_enc_pos=0;
      return;
    }
    else{
      back_enc_pos=0;
      return;
    }
  }
#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
  resetEncoder(BACK);
}

void interruptLeftEncoder(){
 // Read encoder B when ENCA rises
 int b = digitalRead(LEFT_ENC_PIN_B);
 int increment = 0;
 if(b>0){
   // If B is high, increment forward
   increment = 1;
 }
 else{
   // Otherwise, increment backward
   increment = -1;
 }
 left_enc_pos = left_enc_pos + increment;

 // Compute velocity with method 2
//  long currT = micros();
//  float deltaT = ((float) (currT - prevT_i))/1.0e6;
//  velocity_i = increment/deltaT;
//  prevT_i = currT;
}

void interruptRightEncoder(){
 // Read encoder B when ENCA rises
 int b = digitalRead(RIGHT_ENC_PIN_B);
 int increment = 0;
 if(b>0){
   // If B is high, increment forward
   increment = 1;
 }
 else{
   // Otherwise, increment backward
   increment = -1;
 }
 right_enc_pos = right_enc_pos + increment;

 // Compute velocity with method 2
//  long currT = micros();
//  float deltaT = ((float) (currT - prevT_i))/1.0e6;
//  velocity_i = increment/deltaT;
//  prevT_i = currT;
}

void interruptBackEncoder(){
 // Read encoder B when ENCA rises
 int b = digitalRead(BACK_ENC_PIN_B);
 int increment = 0;
 if(b>0){
   // If B is high, increment forward
   increment = 1;
 }
 else{
   // Otherwise, increment backward
   increment = -1;
 }
 back_enc_pos = back_enc_pos + increment;

 // Compute velocity with method 2
//  long currT = micros();
//  float deltaT = ((float) (currT - prevT_i))/1.0e6;
//  velocity_i = increment/deltaT;
//  prevT_i = currT;
}


#endif