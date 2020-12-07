# Система управления светом на NodeMCU v3

# Intro

## Methods
All methods are sent to http://{ip}/api/{method}/

| Type | Method | Params | Description |
| ----- | ------ | ------ | ----- |
| POST | aled/changecolor | hex | Sets the color of the address led in hex format |
| POST | tled/changecolor | hex | Sets the color of the led in hex format |
| POST | power/changestate | switch | Turns the light on and off, accepts 0 or 1 |

