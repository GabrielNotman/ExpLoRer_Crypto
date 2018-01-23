#ifndef TEST_CONFIG_H
#define TEST_CONFIG_H

uint8_t config_data[ATCA_CONFIG_SIZE] = {
  // First 16 bytes cannot be changed
  0x00, 0x00, 0x00, 0x00,       // Bytes 0..3:      Serial Number, 0..3
  0x00, 0x00, 0x00, 0x00,       // Bytes 4..7:      Revision Number
  0x00, 0x00, 0x00, 0x00, 0x00, // Bytes 8..12:     Serial Number, 4..12
  0x00,                         // Byte  13:        Reserved
  0x00,                         // Byte  14:        i2c or SWI mode
  0x00,                         // Byte  15:        Reserved, 
  
  0xC0,                         // Byte  16:        i2c address (when in i2c mode)
  0x00,                         // Byte  17:        Must be 0
  0xAA,                         // Byte  18:        OTP mode, 0xAA = read only, 0x55 consumption mode
  0x00,                         // Byte  19:        Chip mode, Bit[7..3] = 0, Bit[2] = WDT period, Bit[1] = TTL enabled, Bit[0] = selector mode

  // Slot Configs
  // Bit[15]..Bit[12]:          Write Config
  // Bit[11]..Bit[8]            Write Key
  // Bit[7]:                    Is Secret
  // Bit[6]                     Encrypt Read
  // Bit[5]                     Limited Use
  // Bit[4]                     No Mac
  // Bit[3]..Bit[0]             Read Key

  //Slot 0 Secret ECC:      0010-0000-1-0-0-0-0100
  //Slots 1-3 Private ECC:  0110-0000-1-0-0-0-0100
  //Slots 4-7 Public ECC:   0000-0000-0-0-0-0-0000
  //Slots 8-15 Non-ECC:     0000-0000-0-0-0-0-0000
    
  0x84, 0x20,                   // Bytes 20..21:  Slot 0 Config
  0x84, 0x60,                   // Bytes 22..23:  Slot 1 Config
  0x84, 0x60,                   // Bytes 24..25:  Slot 2 Config
  0x84, 0x60,                   // Bytes 26..27:  Slot 3 Config
  0x00, 0x00,                   // Bytes 28..29:  Slot 4 Config
  0x00, 0x00,                   // Bytes 30..31:  Slot 5 Config
  0x00, 0x00,                   // Bytes 32..33:  Slot 6 Config
  0x00, 0x00,                   // Bytes 34..35:  Slot 7 Config
  0x00, 0x00,                   // Bytes 36..37:  Slot 8 Config
  0x00, 0x00,                   // Bytes 38..39:  Slot 9 Config
  0x00, 0x00,                   // Bytes 40..41:  Slot 10 Config
  0x00, 0x00,                   // Bytes 42..43:  Slot 11 Config
  0x00, 0x00,                   // Bytes 44..45:  Slot 12 Config
  0x00, 0x00,                   // Bytes 46..47:  Slot 13 Config
  0x00, 0x00,                   // Bytes 48..49:  Slot 14 Config
  0x00, 0x00,                   // Bytes 50..51:  Slot 15 Config

  // Counters
  0xFF, 0x00, 0xFF, 0x00,
  0xFF, 0x00, 0xFF, 0x00,       // Bytes 52..59:  Counter 1
  0xFF, 0x00, 0xFF, 0x00,
  0xFF, 0x00, 0xFF, 0x00,       // Bytes 60..67:  Counter 2

  // Other
  0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF,       // Bytes 68..83:  Last key use

  0x00,                         // Byte 84:         User Extra
  0x00,                         // Byte 85:         Pause Selector
  0x55,                         // Byte 86:         OTP LockValue, 0x55 = unlocked, 0x00 = locked
  0x55,                         // Byte 87:         Config LockValue, 0x55 = unlocked, 0x00 = locked
  0xFF, 0xFF,                   // Bytes 88..89:    Slot Locked (one bit per slot)
  0x00, 0x00,                   // Bytes 90..91:    RFU, must be 0
  0x00, 0x00, 0x00, 0x00,       // Bytes 92..95:    X509 Format
  
  // Key Configs
  // Bit{15]..Bit[14]:          X509id
  // Bit[13]:                   RFU must be 0
  // Bit[12]:                   Disable on intrusion
  // Bit[11]..Bit[8]:           The key slot to use for authorisation if required
  // Bit[7]:                    Requestion Authorisation before use
  // Bit[6]:                    Request random nonce
  // Bit[5]:                    Slot a can be individually locked
  // Bit[4]..Bit[2]:            KeyType: 100 = ECC, 111 = Not ECC
  // Bit[1]                     If 'Private' 0/1 public key can be generated, if not 'Private' 0/1 require validation for verification
  // Bit[0]:                    Private 

  //All 0b00-0-0-0000-0-0-1-XXX-X-X (Big Endian)
  //Slots 0-3 Private ECC:  XXX-X-X=100-1-1
  //Slots 4-7 Public ECC:   XXX-X-X=100-0-0
  //Slots 8-15 Non-ECC:     XXX-X-X=111-0-0

  0x33, 0x00,                   // Bytes 96..97:    Slot 0 Key Config
  0x33, 0x00,                   // Bytes 98..99:    Slot 1 Key Config
  0x33, 0x00,                   // Bytes 100..101:  Slot 2 Key Config
  0x33, 0x00,                   // Bytes 102..103:  Slot 3 Key Config
  0x30, 0x00,                   // Bytes 104..105:  Slot 4 Key Config
  0x30, 0x00,                   // Bytes 106..107:  Slot 5 Key Config
  0x30, 0x00,                   // Bytes 108..109:  Slot 6 Key Config
  0x30, 0x00,                   // Bytes 110..111:  Slot 7 Key Config
  0x3C, 0x00,                   // Bytes 112..113:  Slot 8 Key Config
  0x3C, 0x00,                   // Bytes 114..115:  Slot 9 Key Config
  0x3C, 0x00,                   // Bytes 116..117:  Slot 10 Key Config
  0x3C, 0x00,                   // Bytes 118..119:  Slot 11 Key Config
  0x3C, 0x00,                   // Bytes 120..121:  Slot 12 Key Config
  0x3C, 0x00,                   // Bytes 122..123:  Slot 13 Key Config
  0x3C, 0x00,                   // Bytes 124..125:  Slot 14 Key Config
  0x3C, 0x00                    // Bytes 126..127:  Slot 15 Key Config
};

#endif
