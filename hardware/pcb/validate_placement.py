import csv, json, math
from pathlib import Path
p=Path(__file__).parent
c=json.loads((p/'mechanical-constraints.json').read_text())
with (p/'switch-placement.csv').open() as f: a=list(csv.DictReader(f))
assert len(a)==12
assert len(set(x['reference'] for x in a))==12
assert {x['reference'] for x in a}=={f'K{i}' for i in range(1,13)}
for i,x in enumerate(a):
    r,col=divmod(i,4)
    assert x['row_net']==f'R{r+1}' and x['column_net']==f'C{col+1}'
    assert x['diode']==f'D{i+1}'
    assert 0<float(x['x_mm'])<c['board']['width_mm']
    assert 0<float(x['y_mm'])<c['board']['height_mm']
for r in range(3):
    for col in range(3):
        x0=float(a[r*4+col]['x_mm']); x1=float(a[r*4+col+1]['x_mm'])
        assert math.isclose(x1-x0,19.05,abs_tol=0.001)
for r in range(2):
    for col in range(4):
        y0=float(a[r*4+col]['y_mm']); y1=float(a[(r+1)*4+col]['y_mm'])
        assert math.isclose(y1-y0,19.05,abs_tol=0.001)
print('PASS: 12 switch locations, pitch, row/column nets, diode mapping, board bounds')
assert c['mcp23017_module']['header_row_spacing_mm'] is None
print('BLOCKED: module socket footprint needs header row spacing and hole count')
