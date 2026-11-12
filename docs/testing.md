# Test plan and results

No physical hardware test has been performed as part of generating this project pack.

## Required tests

- [ ] Confirm DHR55146D connector pin order from Elecrow's schematic.
- [ ] Confirm 3-pin switch pin spacing and case dimensions.
- [ ] Confirm MCP23017 package and footprint.
- [ ] Check 3.3 V rail and I2C pull-up resistance.
- [ ] I2C scan finds MCP23017 at 0x20.
- [ ] Press each of K1–K12 and confirm exactly one matrix coordinate.
- [ ] Test two-key and multi-key combinations.
- [ ] Run KiCad ERC with zero unexplained errors.
- [ ] Run KiCad DRC with zero unapproved violations.
- [ ] Inspect the PCB in KiCad 3D viewer.
- [ ] Compile firmware with the pinned dependencies.
- [ ] Test display, touch and encoder separately.
- [ ] Test MQTT/HTTP/IR only with compatible target devices.

## Current result

Status: NOT TESTED. No ERC, DRC, compilation, 3D-view or hardware pass is claimed.
