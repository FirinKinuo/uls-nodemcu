void api_power_change_state(){
    if (server.method() == HTTP_POST){
        api_post_change_power_state();
    } else {
        server.send(405, "wrong method, expected POST" );
    }
}

void api_aled_change_color(){
    if (server.method() == HTTP_POST){
        api_post_led_color("address");
    } else {
        server.send(405, "wrong method, expected POST" );
    }
}


void api_tled_change_color(){
    if (server.method() == HTTP_POST){
        api_post_led_color("transistors");
    } else {
        server.send(405, "wrong method, expected POST" );
    }
}