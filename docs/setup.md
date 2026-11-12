# Setup

## Firmware

1. Install VS Code and PlatformIO.
2. Open the `firmware` directory.
3. Confirm the ESP32-S3 board variant matches the Elecrow module.
4. Connect the MCP23017 at 0x20 and run the serial matrix test.
5. Only after the matrix test passes, integrate Elecrow's display example and LVGL 8.3.11.

## PC companion

1. Install Python 3.10 or later.
2. Run `python -m pip install -r pc-companion/requirements.txt`.
3. Start the companion with `python pc-companion/src/server.py`.
4. Bind it to the local network only after configuring a firewall rule and authentication.
The current starter binds to localhost by default.
