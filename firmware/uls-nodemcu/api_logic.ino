// address or transistors
void api_post_led_color(char* led_type){
    if (server.arg("hex").toInt()){
        uint32_t hex_value = server.arg("hex").toInt();
        
        if (led_type == "address"){
            aled_set_color(hex_value);
            EEPROM_unsigned_long_put(EEPROM_ALED_COLOR_BYTE, hex_value);
        } else if (led_type == "transistors") {
            tled_set_color(hex_value);   
            EEPROM_unsigned_long_put(EEPROM_TLED_COLOR_BYTE, hex_value);
        }
    
        Serial.print("HTTP// ");
        Serial.print(led_type);
        Serial.print(" led-string color switch to #");
        Serial.println(hex_value, HEX);

        server.send(200);
    } else {
        server.send(400, "wrong value");
    } 
}

void api_post_change_power_state(){
    if (server.arg("switch").toInt() == true){
            led_power_on();
            Serial.println("HTTP// power on");
            server.send(200);
        } else if (server.arg("switch").toInt() == false) {
            led_power_off();
            Serial.println("HTTP// power off");
            server.send(200);
        } else {
            server.send(400);
        } 
}
