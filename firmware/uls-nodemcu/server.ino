// for API methods go to README.md

void start_server(){
    wifi_connect();
    time_client.begin();
    urls();
    server.begin();
    Serial.print("Server start at ");
    Serial.print(WiFi.localIP());
    Serial.println(":80");
}

void wifi_connect(){
    WiFi.begin(ssid, wifi_password);

    while (WiFi.status() != WL_CONNECTED){
        delay(1000);
    }
    digitalWrite(BOARD_LED_PIN, HIGH);
    Serial.println("\nWiFi connected.");
    Serial.print("Ip: ");
    Serial.println(WiFi.localIP());
}

void api_power(){
    Serial.println(server.arg("switch").toInt());
    if (server.method() == HTTP_POST){
        
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

    } else {
        server.send(405, "wrong method, expected POST" );
    }
}

void api_aled(){
    if (server.method() == HTTP_POST){
        if (server.arg("hex").toInt()){
            uint32_t hex_value = server.arg("hex").toInt();

            aled_color(hex_value);

            Serial.print("HTTP// aled to ");
            Serial.println(hex_value, HEX);

            server.send(200);
        } else {
            server.send(400, "wrong value");
        } 

    } else {
        server.send(405, "wrong method, expected POST" );
    }
}


void api_tled(){
    if (server.method() == HTTP_POST){
        if (server.arg("hex").toInt()){
            uint32_t hex_value = server.arg("hex").toInt();
            
            tled_color(hex_value);

            Serial.print("HTTP// tled to ");
            Serial.println(hex_value, HEX);

            server.send(200);
        } else {
            server.send(400, "wrong value");
        } 

    } else {
        server.send(405, "wrong method, expected POST" );
    }
}

void urls(){
    server.on("/api/aled/", api_aled);
    server.on("/api/tled/", api_tled);
    server.on("/api/power/", api_power);
}
