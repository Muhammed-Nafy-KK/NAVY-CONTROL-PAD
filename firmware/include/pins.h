#pragma once
// DHR55146D official pin map. These pins are reserved for onboard hardware.
constexpr int PIN_LCD_SCLK = 10;
constexpr int PIN_LCD_MOSI = 11;
constexpr int PIN_LCD_CS = 9;
constexpr int PIN_LCD_DC = 3;
constexpr int PIN_LCD_RESET = 14;
constexpr int PIN_LCD_BACKLIGHT = 46;
constexpr int PIN_TOUCH_SDA = 6;
constexpr int PIN_TOUCH_SCL = 7;
constexpr int PIN_TOUCH_INT = 5;
constexpr int PIN_TOUCH_RESET = 13;
constexpr int PIN_ENCODER_A = 45;
constexpr int PIN_ENCODER_B = 42;
constexpr int PIN_ENCODER_PUSH = 41;
constexpr int PIN_I2C_SDA = 38;
constexpr int PIN_I2C_SCL = 39;
constexpr int PIN_RGB_LED = 48;
constexpr int PIN_POWER_LED = 40;

constexpr uint8_t MCP23017_ADDRESS = 0x20;
