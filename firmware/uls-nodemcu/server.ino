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

void urls(){
    server.on("/api/aled/changecolor", api_aled_change_color);
    server.on("/api/tled/changecolor", api_tled_change_color);
    server.on("/api/power/changestate", api_power_change_state);
}
