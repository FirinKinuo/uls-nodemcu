void led_power_off(){
    tled_color(0x0);
    aled_color(0x0);

    power_state = !power_state;
}

void led_power_on(){
    // TODO: read values from eeprom
    aled_color(0xb82858);
    tled_color(0xb82858);

    power_state = !power_state;
}

// RGB 0-255
void tled_color(uint32_t hex_color){ 
    analogWrite(T_LED_RED_PIN, (hex_color >> 16 & 0xFF) * 4);
    analogWrite(T_LED_GREEN_PIN, (hex_color >> 8 & 0xFF) * 4);
    analogWrite(T_LED_BLUE_PIN, (hex_color & 0xFF) * 4);
}


// color in HEX format
void aled_color(uint32_t hex_color){
    for(size_t tled_i = 0; tled_i < NUM_ALED; tled_i++){
        aled[tled_i] = hex_color;
    }

    FastLED.show();
}
