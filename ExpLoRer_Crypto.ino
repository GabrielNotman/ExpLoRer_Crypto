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
  debugSerial.println();
  
  //debugSerial.println("Test Config:");
  //printHex(config_data, sizeof(config_data), 4);

  //Init chip
  debugSerial.print("Initialising ATECC508A:...");
  showResult(atcab_init(gCfg));
  debugSerial.println();

  //Read serial number
  uint8_t serial_num[ATCA_SERIAL_NUM_SIZE];
  debugSerial.print("Reading serial number:...");
  showResult(atcab_read_serial_number(serial_num));
  printHex(serial_num, sizeof(serial_num), sizeof(serial_num));
  debugSerial.println();

  //Read revision information
  uint8_t rev_info[4];
  debugSerial.print("Reading revision info:...");
  showResult(atcab_info(serial_num));
  printHex(rev_info, sizeof(rev_info), sizeof(rev_info));
  debugSerial.println();

  //Read configuration lock status
  bool isLocked = false;
  debugSerial.print("Reading configuration lock status:...");
  showResult(atcab_is_locked(LOCK_ZONE_CONFIG, &isLocked));
  debugSerial.print("The configuration zone is ");
  debugSerial.println((isLocked ? "locked" : "unlocked"));
  debugSerial.println();
  
  //Write config if unlocked
  if (!isLocked) {
    debugSerial.print("Writing configuration zone:...");
    showResult(atcab_write_ecc_config_zone(config_data));
  }
  else {
    debugSerial.println("Writing configuration zone:...SKIPPED");
  }
  debugSerial.println();

  //Read back configuration
  uint8_t read_data[ATCA_CONFIG_SIZE];
  debugSerial.print("Reading configuration zone:...");
  showResult(atcab_read_ecc_config_zone(read_data));
  debugSerial.println();

  //Compare the configuration data, skip first 16 bytes
  debugSerial.print("Comparing configuration data (expect 0..14, 87 not to match):...");
  compareArrays(config_data, read_data, ATCA_CONFIG_SIZE);
  debugSerial.println();

  //Lock the configuration zone, if unlocked (can only be done once)
  if (!isLocked) {
    uint8_t lockResponse = 0;
    debugSerial.print("Locking configuration zone:...");
    showResult(atcab_lock_config_zone(&lockResponse));
  }
  else {
    debugSerial.println("Locking configuration zone:...SKIPPED");
  }
  debugSerial.println();

  //Read data zone lock status
  isLocked = false;
  debugSerial.print("Reading data zone lock status:...");
  showResult(atcab_is_locked(LOCK_ZONE_DATA, &isLocked));
  debugSerial.print("The data zone is ");
  debugSerial.println((isLocked ? "locked" : "unlocked"));
  debugSerial.println();
  
  //Lock data zone if unlocked
  if (!isLocked) {
    uint8_t lockResponse = 0;
    debugSerial.print("Locking data zone:...");
    showResult(atcab_lock_data_zone(&lockResponse));
  }
  else {
    debugSerial.println("Locking data zone:...SKIPPED");
  }
  debugSerial.println();

  //TRNG test
  uint8_t random_num[32];
  debugSerial.print("Requesting TRNG:...");
  showResult(atcab_random(random_num));
  printHex(random_num, sizeof(random_num), 16);
  debugSerial.println();
  
  //Generate private key in slot 0
  uint8_t pub_key_slot0[ATCA_PUB_KEY_SIZE];
  debugSerial.print("Generating private key in slot0:...");
  showResult(atcab_genkey(0, pub_key_slot0));
  debugSerial.println("Responded with public key:");
  printHex(pub_key_slot0, sizeof(pub_key_slot0), 16);
  debugSerial.println();

  //Query public key from slot 0
  debugSerial.print("Querying public key from secret key in slot 0:...");
  showResult(atcab_get_pubkey(0, pub_key_slot0));
  printHex(pub_key_slot0, sizeof(pub_key_slot0), 16);
  debugSerial.println();
    
  
  //Query Public Key
  //Print Public Key

  //Request Other Public Key
  //Convert from Base64 and then back to test

  //Skip Lock Datazones

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

void compareArrays(uint8_t* array1, uint8_t* array2, uint8_t len)
{
  bool equal = true;
  for (uint8_t i = 0; i < len; i++) {
    if (array1[i] != array2[i]) {
      equal = false;
      debugSerial.print(String(i, DEC) + String(", "));
    }
  }
  if (equal) {
    debugSerial.println("EQUAL");
  }
  else {
    debugSerial.println("SHOWN INDICIES ARE NOT EQUAL");
  }
}

void printHex(const uint8_t* array, uint8_t len, uint8_t width)
{
    char strA[3];
    for (uint8_t i = 0; i < len; i++)
    {
        if (i % width == 0)
        {
            sprintf(strA,"%03d",i);
            debugSerial.print(String((i == 0 ? "" : "\r\n")) + String(strA) + ": ");
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

