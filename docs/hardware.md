# Hardware architecture

## Main controller

Use the Elecrow CrowPanel 1.46-inch HMI ESP32-S3 Rotary Display, model DHR55146D.
It is a complete module. Do not reproduce its internal LCD, touch or ESP32 circuits on
the keypad PCB.

The official Elecrow page identifies ESP32-S3R8, 360x360 display, JD9855 display
controller, CST816T touch controller, 5 V / 1 A input, and a 60 x 60 x 27.5 mm module.

## Display GPIO reservation

| Function | GPIO |
|---|---:|
| LCD SCLK | 10 |
| LCD MOSI | 11 |
| LCD CS | 9 |
| LCD DC | 3 |
| LCD RESET | 14 |
| LCD backlight | 46 |
| Touch SDA / SCL | 6 / 7 |
| Touch INT / RESET | 5 / 13 |
| Encoder A / B / push | 45 / 42 / 41 |
| External I2C SDA / SCL | 38 / 39 |
| RGB LED | 48 |
| Power indicator | 40 |

Do not assign any of these pins to external hardware. The MCP23017 connects through
the exposed external I2C bus at GPIO38/39. The board's exact external connector pin
order must be taken from the official schematic, not inferred from cable colours.

## MCP23017

- U1: MCP23017, address 0x20 (A0=A1=A2=GND).
- GPA0–GPA2: matrix rows R1–R3.
- GPA4–GPA7: matrix columns C1–C4.
- GPA3 and unused port B pins: explicitly documented NC/reserved.
- RESET: 10 kOhm pull-up to 3.3 V.
- VDD: 3.3 V; VSS: GND.
- C1: 100 nF ceramic directly between VDD and VSS, close to U1.
- Place optional 100 nF bulk local bypass only if layout or cable testing shows it is needed.

The MCP23017 package/footprint must be selected to match the purchased part (DIP-28
or SOIC-28). Do not mix package footprints.

## Switches

Exactly 12 switches are used. The supplied switch description says 3-pin red linear
45 gf, but it does not identify the manufacturer or exact model. The PCB footprint
is therefore provisional until the switch dimensions and pin pitch are measured.
Do not order the PCB until that check is complete.
