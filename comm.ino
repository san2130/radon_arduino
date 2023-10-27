#include "SerialTransfer.h"


SerialTransfer myTransfer;

char arr[12];
char success[]="OK";
char failure[]="ER";

// A pair of varibles to help parse serial commands (thanks Fergs)
int arg = 0;
int index = 0;

// Variable to hold an input character
char chr;

// Variable to hold the current single-character command
char cmd;

// Character arrays to hold the first and second arguments
char argv1[16];
char argv2[16];

// The arguments converted to integers
long arg1;
long arg2;

void setup()
{
  Serial.begin(57600);
  myTransfer.begin(Serial);
}

int runCommand(){
    uint16_t sendSize = 0;
    if(cmd == 'm')
    {
      sendSize = myTransfer.txObj(success, sendSize);
    }
    else
    {
      sendSize = myTransfer.txObj(failure, sendSize);
    }
    myTransfer.sendData(sendSize);
}


/* Clear the current command parameters */
void resetCommand() {
  cmd = NULL;
  memset(argv1, 0, sizeof(argv1));
  memset(argv2, 0, sizeof(argv2));
  arg1 = 0;
  arg2 = 0;
  arg = 0;
  index = 0;
}

void loop()
{
  if(myTransfer.available())
  {
    uint16_t recSize = 0;
    uint16_t sendSize = 0;
    
    recSize = myTransfer.rxObj(arr, recSize);
    for(int i=0;i < 12; i++)
    {
       char chr = arr[i];
       if (chr == 13) {
        if (arg == 1) argv1[index] = NULL;
        else if (arg == 2) argv2[index] = NULL;
          runCommand();
          resetCommand();
       }
      // Use spaces to delimit parts of the command
      else if (chr == ' ') {
        // Step through the arguments
        if (arg == 0) arg = 1;
        else if (arg == 1)  {
          argv1[index] = NULL;
          arg = 2;
          index = 0;
        }
        continue;
      }
      else {
        if (arg == 0) {
          // The first arg is the single-letter command
          cmd = chr;
        }
        else if (arg == 1) {
          // Subsequent arguments can be more than one character
          argv1[index] = chr;
          index++;
        }
        else if (arg == 2) {
          argv2[index] = chr;
          index++;
        }
      }
    }
  }
    
  
  delay(1000/30);
}
