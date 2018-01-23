#include "atca_basic.h"
#include "test_config.h"

ATCAIfaceCfg *gCfg = &cfg_ateccx08a_i2c_default;

#define debugSerial SerialUSB
#define debugBaud 57600
#define debugDelay 10000

void setup() 
{
  while ((!debugSerial) && (millis() < debugDelay)){
    // Wait debugDelay milliseconds for debugSerial to open
  }

  // Start debug stream
  debugSerial.begin(debugBaud);
  debugSerial.println("Starting...");
  
  debugSerial.println("Test Config:");
  printHex(config_data, sizeof(config_data), 4);

  //Init chip
  //Write config
  //Read back config
  //Test config

  //Lock config
  //Lock Datazones

  //Generate Private Key
  //Query Public Key
  //Print Public Key

  //Request Other Public Key
  //Convert from Base64 and then back to test

  //Generate Shared Secret
  //Run AES on test Message
  //Output AES encrypted Message as base64
  
  //Ask for encrypted input
  //Decrypt input
  //Display encrypted and decrypted version
}

void loop() 
{
}

void printHex(const uint8_t* array, uint8_t len, uint8_t width)
{
    debugSerial.print(String("Length = ") + String(len,DEC));
    char strA[3];
    for (byte i = 0; i < len; i++)
    {
        if (i % width == 0)
        {
            sprintf(strA,"%03d",i);
            debugSerial.println();
            debugSerial.print(String(strA) + ": ");
        }
        sprintf(strA,"%02X ",array[i]);
        debugSerial.print(strA);
        
    }
    debugSerial.println();
}
