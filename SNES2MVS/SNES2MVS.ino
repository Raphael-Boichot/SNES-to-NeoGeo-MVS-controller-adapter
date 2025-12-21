/*
  SNES Controller -> Neo-Geo MVS
  Original concept: Anthony Burkholder (2016) and Robin Edwards (2018)
  Optimized & extended with bitmask mapping
  SNES button order: B, Y, Select, Start, Up, Down, Left, Right, A, X, L, R
*/

// SNES interface pins
constexpr uint8_t DATA_CLOCK  = A0;
constexpr uint8_t DATA_LATCH  = A1;
constexpr uint8_t DATA_SERIAL = A2;

// Neo-Geo MVS logical bits
enum MVSBits : uint8_t {
  MVS_UP = 0,
  MVS_DOWN,
  MVS_LEFT,
  MVS_RIGHT,
  MVS_A,
  MVS_B,
  MVS_C,
  MVS_D,
  MVS_START,
  MVS_SELECT,
  MVS_COUNT
};

// Logical → Arduino pin map
constexpr uint8_t mvsPins[MVS_COUNT] = {
  4,  // UP
  5,  // DOWN
  6,  // LEFT
  7,  // RIGHT
  8,  // A
  9,  // B
  10, // C
  11, // D
  3,  // START
  2   // SELECT / COIN
};

constexpr uint8_t PIN_LED = LED_BUILTIN;

// SNES → MVS bitmask table
// SNES order: B,Y,Sel,Start,U,D,L,R,A,X,L,R
constexpr uint16_t snesToMVS[12] = {
  (1 << MVS_B),       // B
  (1 << MVS_C),       // Y -> C
  (1 << MVS_SELECT), // Select
  (1 << MVS_START),  // Start
  (1 << MVS_UP),     // Up
  (1 << MVS_DOWN),   // Down
  (1 << MVS_LEFT),   // Left
  (1 << MVS_RIGHT),  // Right
  (1 << MVS_A),      // A
  (1 << MVS_D),      // X -> D
  0,                 // L (unused)
  0                  // R (unused)
};

void setup()
{
  pinMode(DATA_CLOCK, OUTPUT);
  pinMode(DATA_LATCH, OUTPUT);
  pinMode(DATA_SERIAL, INPUT_PULLUP);
  digitalWrite(DATA_CLOCK, HIGH);
  digitalWrite(DATA_LATCH, LOW);
  for (uint8_t i = 0; i < MVS_COUNT; i++) {
    pinMode(mvsPins[i], INPUT); // Hi-Z by default
  }
  pinMode(PIN_LED, OUTPUT);
}

// Read SNES controller
uint16_t readSNES()
{
  uint16_t buttons = 0;
  digitalWrite(DATA_LATCH, HIGH);  // Latch
  delayMicroseconds(12);
  digitalWrite(DATA_LATCH, LOW);
  delayMicroseconds(6);
  for (uint8_t i = 0; i < 16; i++) {  // Shift 16 bits
    digitalWrite(DATA_CLOCK, LOW);
    delayMicroseconds(6);
    if (i < 12 && digitalRead(DATA_SERIAL) == LOW) {
      buttons |= (1 << i);
    }
    digitalWrite(DATA_CLOCK, HIGH);
    delayMicroseconds(6);
  }
  return buttons;
}

// Build Neo-Geo state
uint16_t buildMVSState(uint16_t snesButtons)
{
  uint16_t mvsState = 0;
  for (uint8_t i = 0; i < 12; i++) {
    if (snesButtons & (1 << i)) {
      mvsState |= snesToMVS[i];
    }
  }
  return mvsState;
}

// Drive Neo-Geo outputs
void writeMVS(uint16_t mvsState)
{
  for (uint8_t i = 0; i < MVS_COUNT; i++) {
    uint8_t pin = mvsPins[i];
    if (mvsState & (1 << i)) {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);  // Active LOW
    } else {
      pinMode(pin, INPUT);    // Hi-Z
    }
  }
}

// Main loop
void loop()
{
  uint16_t snesButtons = readSNES();
  uint16_t mvsState    = buildMVSState(snesButtons);
  writeMVS(mvsState);
  digitalWrite(PIN_LED, (mvsState & (1 << MVS_SELECT)) ? HIGH : LOW);  // Coin / Select LED
  delay(5);
}
