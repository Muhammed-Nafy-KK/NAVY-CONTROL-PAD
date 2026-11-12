# Firmware notes

The current source contains an MCP23017 matrix scanner foundation. It does not yet
initialize the CrowPanel display, LVGL, touch controller, encoder, Wi-Fi, Bluetooth,
MQTT or IR.

Display startup must be ported from Elecrow's official DHR55146D examples. The official
documentation's display configuration is SPI with JD9855 and the GPIO map in
`docs/hardware.md`. Keep LVGL pinned to 8.3.11 as requested.

Before enabling network features, add credentials through a local secrets header or
PlatformIO build flags. Do not commit Wi-Fi passwords, MQTT credentials or tokens.
