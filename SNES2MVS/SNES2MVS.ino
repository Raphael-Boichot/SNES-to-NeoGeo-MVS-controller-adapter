/*
  SNES Controller -> Neo-Geo MVS Adapter
  Features: 
  - L/R Shoulder Buttons = Rapid Fire (Turbo)
  - Built-in LED flashes on any button press/turbo pulse
  - SNES Button Order: B, Y, Select, Start, Up, Down, Left, Right, A, X, L, R
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

// Mapping: Logical Bit -> Arduino Digital Pin
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

// SNES -> MVS bitmask table
// SNES order: B, Y, Sel, Start, U, D, L, R, A, X, L, R
constexpr uint16_t snesToMVS[12] = {
  (1 << MVS_B),      // B
  (1 << MVS_C),      // Y -> C
  (1 << MVS_SELECT), // Select
  (1 << MVS_START),  // Start
  (1 << MVS_UP),     // Up
  (1 << MVS_DOWN),   // Down
  (1 << MVS_LEFT),   // Left
  (1 << MVS_RIGHT),  // Right
  (1 << MVS_A),      // A
  (1 << MVS_D),      // X -> D
  0,                 // L (Handled via Turbo logic)
  0                  // R (Handled via Turbo logic)
};

void setup() {
  pinMode(DATA_CLOCK, OUTPUT);
  pinMode(DATA_LATCH, OUTPUT);
  pinMode(DATA_SERIAL, INPUT_PULLUP);
  
  digitalWrite(DATA_CLOCK, HIGH);
  digitalWrite(DATA_LATCH, LOW);

  for (uint8_t i = 0; i < MVS_COUNT; i++) {
    pinMode(mvsPins[i], INPUT); // Start in High-Z (Released)
  }
  
  pinMode(PIN_LED, OUTPUT);
}

// Read raw 16-bit data from SNES controller
uint16_t readSNES() {
  uint16_t buttons = 0;
  digitalWrite(DATA_LATCH, HIGH);
  delayMicroseconds(12);
  digitalWrite(DATA_LATCH, LOW);
  delayMicroseconds(6);

  for (uint8_t i = 0; i < 16; i++) {
    digitalWrite(DATA_CLOCK, LOW);
    delayMicroseconds(6);
    
    // SNES sends data as logic LOW when pressed
    if (i < 12 && digitalRead(DATA_SERIAL) == LOW) {
      buttons |= (1 << i);
    }
    
    digitalWrite(DATA_CLOCK, HIGH);
    delayMicroseconds(6);
  }
  return buttons;
}

// Translate SNES input to Neo-Geo state with Turbo processing
uint16_t buildMVSState(uint16_t snesButtons) {
  uint16_t mvsState = 0;

  // 1. Process standard static mapping
  for (uint8_t i = 0; i < 12; i++) {
    if (snesButtons & (1 << i)) {
      mvsState |= snesToMVS[i];
    }
  }

  // 2. Process Turbo logic for L and R
  // Toggles every 50ms (approx 10Hz)
  bool turboPulse = (millis() / 50) % 2; 

  if (turboPulse) {
    if (snesButtons & (1 << 10)) mvsState |= (1 << MVS_B); // L -> Turbo B
    if (snesButtons & (1 << 11)) mvsState |= (1 << MVS_A); // R -> Turbo A
  }

  return mvsState;
}

// Apply the state to physical pins (Sink current to GND if active)
void writeMVS(uint16_t mvsState) {
  for (uint8_t i = 0; i < MVS_COUNT; i++) {
    uint8_t pin = mvsPins[i];
    if (mvsState & (1 << i)) {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);  // Active LOW
    } else {
      pinMode(pin, INPUT);     // High Impedance (Released)
    }
  }
}

void loop() {
  uint16_t snesButtons = readSNES();
  uint16_t mvsState    = buildMVSState(snesButtons);
  
  writeMVS(mvsState);

  // LED logic: Lights up if any Neo-Geo input is being pulled LOW
  // This will flash automatically when Turbo is active.
  digitalWrite(PIN_LED, (mvsState > 0) ? HIGH : LOW);

  delay(5); // Small delay for stability
}