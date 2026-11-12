# KiCad source status

Project settings file created. The actual `.kicad_sch` and `.kicad_pcb` are deliberately
not fabricated: no KiCad CLI is installed in this build environment, and the exact switch
footprint, MCP23017 package, connector order and board dimensions are not yet verified.
The logical netlist and matrix mapping are in `../schematics/` and `../bom/`.

Next: open this project in KiCad 8+, create the six hierarchical sheets, assign real
symbols/footprints from the selected libraries, run ERC/DRC, then export actual 3D views.
