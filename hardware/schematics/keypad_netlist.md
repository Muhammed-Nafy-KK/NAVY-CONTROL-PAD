# Keypad electrical netlist (logical)

Each key is a separate series branch:

`Column net -> diode ANODE -> diode CATHODE/stripe -> switch terminal 1 -> switch terminal 2 -> Row net`

The diode stripe faces the row side. Do not connect the diode cathodes directly together;
each diode cathode only connects to its own switch terminal.

## Column nets
- C1 / GPA4: D1.A, D5.A, D9.A
- C2 / GPA5: D2.A, D6.A, D10.A
- C3 / GPA6: D3.A, D7.A, D11.A
- C4 / GPA7: D4.A, D8.A, D12.A

## Per-key series branches
- C1 -> D1.A; D1.K -> K1.1; K1.2 -> R1 / GPA0
- C2 -> D2.A; D2.K -> K2.1; K2.2 -> R1 / GPA0
- C3 -> D3.A; D3.K -> K3.1; K3.2 -> R1 / GPA0
- C4 -> D4.A; D4.K -> K4.1; K4.2 -> R1 / GPA0
- C1 -> D5.A; D5.K -> K5.1; K5.2 -> R2 / GPA1
- C2 -> D6.A; D6.K -> K6.1; K6.2 -> R2 / GPA1
- C3 -> D7.A; D7.K -> K7.1; K7.2 -> R2 / GPA1
- C4 -> D8.A; D8.K -> K8.1; K8.2 -> R2 / GPA1
- C1 -> D9.A; D9.K -> K9.1; K9.2 -> R3 / GPA2
- C2 -> D10.A; D10.K -> K10.1; K10.2 -> R3 / GPA2
- C3 -> D11.A; D11.K -> K11.1; K11.2 -> R3 / GPA2
- C4 -> D12.A; D12.K -> K12.1; K12.2 -> R3 / GPA2

The third switch pin on a 3-pin MX-style switch is a mechanical locating post and is
not an electrical contact on common MX-compatible switches. Confirm against the actual
switch before footprint use.

This is a logical netlist description, not a KiCad ERC-checked schematic.
