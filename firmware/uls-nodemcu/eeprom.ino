// --- Custom function EEPROM read for different types
uint32_t EEPROM_unsigned_long_read(uint16_t addr) {    
    Serial.println("---- READ ----");
    uint8_t raw[4];
  
    for(size_t i = 0; i < 4; i++){
        raw[i] = EEPROM.read(addr + i);
        Serial.print("Read ");
        Serial.print(addr + i);
        Serial.print(" -  ");
        Serial.println(raw[i]);
      } 

    uint32_t &num = (uint32_t&)raw;

    return num;
}
// --- --- ---

// --- Custom function EEPROM read for different types
void EEPROM_unsigned_long_put(uint16_t addr, uint32_t num) {
    Serial.println("---- WRITE ----");
    uint8_t raw[4];

    (uint32_t&)raw = num;

    for(size_t i = 0; i < 4; i++){
        EEPROM.put(addr + i, raw[i]);
        Serial.print("Write ");
        Serial.print(addr + i);
        Serial.print(" -  ");
        Serial.println(raw[i]);
    }
    EEPROM.commit();
}