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

void showResult(ATCA_STATUS result)
{
  String message;
  
  switch(result) {
    case ATCA_SUCCESS                 :message = "SUCCESS"; break;
    case ATCA_CONFIG_ZONE_LOCKED      :message = "CONFIG_ZONE_LOCKED"; break;
    case ATCA_DATA_ZONE_LOCKED        :message = "DATA_ZONE_LOCKED"; break;
    case ATCA_WAKE_FAILED             :message = "WAKE_FAILED"; break;
    case ATCA_CHECKMAC_VERIFY_FAILED  :message = "CHECKMAC_VERIFY_FAILED"; break;
    case ATCA_PARSE_ERROR             :message = "PARSE_ERROR"; break;
    case ATCA_STATUS_CRC              :message = "STATUS_CRC"; break;
    case ATCA_STATUS_UNKNOWN          :message = "STATUS_UNKNOWN"; break;
    case ATCA_STATUS_ECC              :message = "STATUS_ECC"; break;
    case ATCA_FUNC_FAIL               :message = "FUNC_FAIL"; break;
    case ATCA_GEN_FAIL                :message = "GEN_FAIL"; break;
    case ATCA_BAD_PARAM               :message = "BAD_PARAM"; break;
    case ATCA_INVALID_ID              :message = "INVALID_ID"; break;
    case ATCA_INVALID_SIZE            :message = "INVALID_SIZE"; break;
    case ATCA_BAD_CRC                 :message = "BAD_CRC"; break;
    case ATCA_RX_FAIL                 :message = "RX_FAIL"; break;
    case ATCA_RX_NO_RESPONSE          :message = "RX_NO_RESPONSE"; break;
    case ATCA_RESYNC_WITH_WAKEUP      :message = "RESYNC_WITH_WAKEUP"; break;
    case ATCA_PARITY_ERROR            :message = "PARITY_ERROR"; break;
    case ATCA_TX_TIMEOUT              :message = "TX_TIMEOUT"; break;
    case ATCA_RX_TIMEOUT              :message = "RX_TIMEOUT"; break;
    case ATCA_COMM_FAIL               :message = "COMM_FAIL"; break;
    case ATCA_TIMEOUT                 :message = "TIMEOUT"; break;
    case ATCA_BAD_OPCODE              :message = "BAD_OPCODE"; break;
    case ATCA_WAKE_SUCCESS            :message = "WAKE_SUCCESS"; break;
    case ATCA_EXECUTION_ERROR         :message = "EXECUTION_ERROR"; break;
    case ATCA_UNIMPLEMENTED           :message = "UNIMPLEMENTED"; break;
    case ATCA_ASSERT_FAILURE          :message = "ASSERT_FAILURE"; break;
    case ATCA_TX_FAIL                 :message = "TX_FAIL"; break;
    case ATCA_NOT_LOCKED              :message = "NOT_LOCKED"; break;
    case ATCA_NO_DEVICES              :message = "NO_DEVICES"; break;
  }

  debugSerial.println(message);
  
  // Hang on error
  if (result != ATCA_SUCCESS) {
    while(1);
  }
}

