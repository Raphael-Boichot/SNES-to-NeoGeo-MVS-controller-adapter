## Wiring

### SNES → Arduino

| 1 2 3 4 | 5 6 7 )

| Pin | Signal | Arduino |
|---:|--------|---------|
| 1 | +5V | +5V |
| 2 | Clock | A0 |
| 3 | Latch | A1 |
| 4 | Serial | A2 |
| 7 | GND | GND |

### Arduino → DB15 (Front View)

1(GND)                8(+5V)

| o o o o o o o o |
 
 \ o o o o o o o /
  
9                     15

| DB15 | Signal | Arduino |
|----:|--------|---------|
| 1 | GND | GND |
| 8 | +5V | +5V |
| 3 | Select | D2 |
| 11 | Start | D3 |
| 15 | Up | D4 |
| 7 | Down | D5 |
| 14 | Left | D6 |
| 6 | Right | D7 |
| 13 | A | D8 |
| 5 | B | D9 |
| 12 | C | D10 |
| 4 | D | D11 |

