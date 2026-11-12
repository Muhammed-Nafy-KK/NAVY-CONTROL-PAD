# Wiring

## I2C

CrowPanel external I2C:
- SDA: GPIO38
- SCL: GPIO39
- 3V3: 3.3 V rail, only if confirmed present on the actual connector.
- GND: common ground.

Connect MCP23017 SDA/SCL to the same bus. Use address straps A0/A1/A2 to GND for
address 0x20. Check that the board already has suitable I2C pull-ups before adding
another pair; parallel pull-ups change the effective resistance.

## Key matrix orientation

For every key, wire the switch in series with its diode between one column and one row:

`Column -> diode ANODE -> diode CATHODE/stripe -> switch -> Row`

The switch and diode may be placed in either physical order in the series path, but the
diode polarity must remain column-anode to row-cathode.

| Key | Row | Column | Diode |
|---|---|---|---|
| K1 | R1 / GPA0 | C1 / GPA4 | D1 |
| K2 | R1 / GPA0 | C2 / GPA5 | D2 |
| K3 | R1 / GPA0 | C3 / GPA6 | D3 |
| K4 | R1 / GPA0 | C4 / GPA7 | D4 |
| K5 | R2 / GPA1 | C1 / GPA4 | D5 |
| K6 | R2 / GPA1 | C2 / GPA5 | D6 |
| K7 | R2 / GPA1 | C3 / GPA6 | D7 |
| K8 | R2 / GPA1 | C4 / GPA7 | D8 |
| K9 | R3 / GPA2 | C1 / GPA4 | D9 |
| K10 | R3 / GPA2 | C2 / GPA5 | D10 |
| K11 | R3 / GPA2 | C3 / GPA6 | D11 |
| K12 | R3 / GPA2 | C4 / GPA7 | D12 |

## Scan method

1. Configure GPA4–GPA7 as inputs with pull-ups enabled.
2. Configure GPA0–GPA2 as inputs/high impedance.
3. For each row in turn, configure only that row as output LOW.
4. Read GPA4–GPA7. LOW means the corresponding key in the active row is pressed.
5. Return the active row to input/high impedance before selecting the next row.
6. Debounce in software (initial 15–25 ms; tune by testing).

The scan is deliberately compatible with the specified diode direction. Driving columns
LOW and expecting row pull-ups to detect a key would be incorrect for this polarity.
