#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP23X17.h>
#include "pins.h"

Adafruit_MCP23X17 mcp;

// MCP23017 pin numbers are GPA0..GPA7 = 0..7.
// Rows: GPA0..GPA2. Columns: GPA4..GPA7.
constexpr uint8_t ROW_PINS[3] = {0, 1, 2};
constexpr uint8_t COL_PINS[4] = {4, 5, 6, 7};
constexpr uint32_t DEBOUNCE_MS = 20;

bool stableState[3][4] = {};
bool lastRaw[3][4] = {};
uint32_t changedAt[3][4] = {};

static void setRowHighZ(uint8_t row) {
  // Input mode is high impedance. Disable row pull-up.
  mcp.pinMode(ROW_PINS[row], INPUT);
  mcp.pullUp(ROW_PINS[row], LOW);
}

static void scanMatrix() {
  for (uint8_t r = 0; r < 3; ++r) setRowHighZ(r);

  for (uint8_t c = 0; c < 4; ++c) {
    mcp.pinMode(COL_PINS[c], INPUT);
    mcp.pullUp(COL_PINS[c], HIGH);
  }

  for (uint8_t r = 0; r < 3; ++r) {
    // With diode anode at column and cathode at row, current flows
    // from a pulled-up column through a pressed key into the LOW row.
    mcp.pinMode(ROW_PINS[r], OUTPUT);
    mcp.digitalWrite(ROW_PINS[r], LOW);
    delayMicroseconds(150);

    for (uint8_t c = 0; c < 4; ++c) {
      const bool rawPressed = (mcp.digitalRead(COL_PINS[c]) == LOW);
      if (rawPressed != lastRaw[r][c]) {
        lastRaw[r][c] = rawPressed;
        changedAt[r][c] = millis();
      }
      if ((millis() - changedAt[r][c]) >= DEBOUNCE_MS &&
          stableState[r][c] != rawPressed) {
        stableState[r][c] = rawPressed;
        Serial.printf("K%u %s\n", r * 4 + c + 1,
                      rawPressed ? "PRESSED" : "RELEASED");
      }
    }
    setRowHighZ(r);
  }
}

void setup() {
  Serial.begin(115200);
  delay(300);
  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);

  if (!mcp.begin_I2C(MCP23017_ADDRESS, &Wire)) {
    Serial.println("ERROR: MCP23017 not found at 0x20");
    while (true) delay(1000);
  }

  for (uint8_t r = 0; r < 3; ++r) setRowHighZ(r);
  for (uint8_t c = 0; c < 4; ++c) {
    mcp.pinMode(COL_PINS[c], INPUT);
    mcp.pullUp(COL_PINS[c], HIGH);
  }
  Serial.println("NAVY CONTROL PAD matrix test ready.");
  Serial.println("Expected diode direction: column anode -> row cathode/stripe.");
}

void loop() {
  scanMatrix();
  delay(2);
}
