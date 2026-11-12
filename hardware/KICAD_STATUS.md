# KiCad implementation status

The source-of-truth net mapping is in `bom/key_matrix.csv` and `docs/wiring.md`.

The uploaded starter pack did not contain KiCad source files. This build pack therefore
does not pretend to contain a finished schematic or routed PCB. The `kicad/` directory
is reserved for the actual KiCad project files once the exact switch footprint, MCP23017
package, connector pin order and board dimensions are confirmed.

A blank or decorative `.kicad_pcb` would be misleading, so no fabricated PCB layout
is included. Install KiCad 8 or later to perform the actual ERC/DRC and 3D checks.
