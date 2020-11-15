# Система управления светом на NodeMCU v3

# Intro

## Methods
All methods are sent to http://{ip}/api/{method}/

| Type | Method | Params | Description | Example |
| ----- | ------ | ------ | ----- | ---- |
| POST | aled | hex | Sets the color of the address led in hex format | /api/aled/?hex={value} |
| POST | tled | hex | Sets the color of the led in hex format | /api/tled/?hex={value} |
| POST | power | switch | Turns the light on and off, accepts 0 or 1 | /api/power/?switch={value} |

