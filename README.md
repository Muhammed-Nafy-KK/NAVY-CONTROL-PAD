# NAVY CONTROL PAD

A 12-key macro and home-control keypad built around the Elecrow CrowPanel 1.46-inch HMI ESP32-S3 rotary display (DHR55146D).

## Current build status

This repository is an engineering starter pack, not a claim that a finished PCB or tested appliance controller already exists.

- Stage 1: official 1.46-inch display pinout checked against Elecrow documentation.
- Stage 2: architecture and keypad electrical topology documented.
- Stage 3–5: KiCad schematic/PCB implementation and verification remain pending.
- Stage 6–9: firmware, PC companion and integrations are starter implementations and require hardware testing.
- No ERC, DRC, 3D-view, firmware compile or physical test is claimed.

## Hardware

- Elecrow DHR55146D, ESP32-S3R8, 360x360 JD9855 display.
- MCP23017 at I2C address 0x20.
- 12 x 3-pin mechanical switches, arranged 3 rows x 4 columns.
- 12 x 1N4148 diodes, anode toward columns and cathode (stripe) toward rows.
- 100 nF MCP23017 decoupling capacitor.
- 10 kOhm RESET pull-up to 3.3 V.

## Important electrical detail

With the specified diode direction (column anode -> row cathode), scan one row at a time:
drive the selected row LOW, leave the other rows as inputs/high impedance, and enable
pull-ups on the four column inputs. A pressed key pulls its column LOW through its diode.
Do not use the opposite scan polarity.

## Start here

1. Read `docs/hardware.md` and `docs/wiring.md`.
2. Confirm the exact switch manufacturer/part number and inspect its pin spacing before PCB footprint release.
3. Inspect the Elecrow connector pin order in the supplied manufacturer drawing before making a cable.
4. Build and test the MCP23017 matrix on a breadboard before committing the PCB.
5. Firmware currently provides a serial matrix test foundation only; display UI and integrations are not complete.

## Build environment

Firmware uses PlatformIO + Arduino framework. Dependencies are listed in `firmware/platformio.ini`.
The Windows companion is a Python starter using a local HTTP API; authentication and packaging are not yet implemented.

## Safety and scope

IR transmitters need a transistor driver and current-limiting resistor. Do not drive an IR LED directly from an ESP32 GPIO.
Mains appliances must be controlled through certified smart plugs/controllers or properly isolated commercial hardware.
Never connect mains voltage to this PCB.

## License

MIT. See `LICENSE`.
