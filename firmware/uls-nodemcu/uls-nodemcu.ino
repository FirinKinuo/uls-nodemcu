// ---- PINS CONTS ----
#define BOARD_LED_PIN       2
#define T_LED_RED_PIN       5
#define T_LED_GREEN_PIN     12
#define T_LED_BLUE_PIN      15
#define SINGLE_LED_PIN      13
#define ALED_PIN            4
#define POWER_SWITCH_BTN    14
#define IR_PIN              0
// ---- ---- ----

// ---- CONFIG CONSTS ----
#define NUM_ALED 29
#define BRIGHTNESS 200
const char* ssid          = "f.wi-fi";
const char* wifi_password = "f.wifi-pass";
const uint32_t utc_offset = 3 * 60 * 60;
// When to automatically turn on the backlight
const uint8_t morning_hour = 7; 
const uint8_t morning_min = 30;
// ---- ---- ----

// ---- SYSTEM DEFINE ----
#define True 1
#define False 0
#define FASTLED_ESP8266_RAW_PIN_ORDER
// ---- ---- ----

// ---- SYSTEM VARS ----
bool power_state = True;
// ---- ---- ----

// ---- LIBS ----
#include <FastLED.h>
#include "GyverButton.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
// ---- ---- ----

// ---- INITS CLASS ----
CRGB aled[NUM_ALED];
GButton btn(POWER_SWITCH_BTN);
ESP8266WebServer server(80);
WiFiUDP ntpUDP;
NTPClient time_client(ntpUDP, "pool.ntp.org", utc_offset);

// ---- ---- ----

void setup(){
    Serial.begin(115200);
    pinMode(BOARD_LED_PIN, OUTPUT);
    pinMode(T_LED_RED_PIN, OUTPUT);
    pinMode(T_LED_GREEN_PIN, OUTPUT);
    pinMode(T_LED_BLUE_PIN, OUTPUT);
    pinMode(SINGLE_LED_PIN, OUTPUT);
    pinMode(POWER_SWITCH_BTN, INPUT_PULLUP);
    btn.setDebounce(5);
    FastLED.addLeds<WS2812B, ALED_PIN, GRB>(aled, NUM_ALED);
    

    start_server();
    led_power_on();
    digitalWrite(BOARD_LED_PIN, LOW);
}

void loop(){
    modules_handler();  // Handlers of all modules

    if(btn.isClick()){
        if(power_state){
            led_power_off();
        } else {
            led_power_on();
        }
    }

    if(time_client.getHours() == morning_hour && 
        time_client.getMinutes() == morning_min){
            led_power_on();
    }
    

    delay(100);
}


// ----- FUNCTIONS -----

// ---- ---- ----