
#define LED_PINRed 7
#define LED_PINYel 6
#define LED_PINGre 5
#define BUTTON_PIN 2

byte lastButtonState;
byte ledState = 0;  // This will hold the state (0=Red, 1=Yellow, 2=Green)

void setup() {
  pinMode(LED_PINRed, OUTPUT);
  pinMode(LED_PINYel, OUTPUT);
  pinMode(LED_PINGre, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lastButtonState = digitalRead(BUTTON_PIN);
  
  // Initialize all LEDs to LOW (off)
  digitalWrite(LED_PINRed, LOW);
  digitalWrite(LED_PINYel, LOW);
  digitalWrite(LED_PINGre, LOW);
}

void loop() {
  byte buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState != lastButtonState) {
    lastButtonState = buttonState;
    if (buttonState == LOW) {
      // Cycle through LEDs
      ledState++;
      if (ledState > 2) {
        ledState = 0;  // Reset to Red after Green
      }

      // Turn off all LEDs
      digitalWrite(LED_PINRed, LOW);
      digitalWrite(LED_PINYel, LOW);
      digitalWrite(LED_PINGre, LOW);

      // Turn on the selected LED
      if (ledState == 0) {
        digitalWrite(LED_PINRed, HIGH); // Red
      } else if (ledState == 1) {
        digitalWrite(LED_PINYel, HIGH); // Yellow
      } else if (ledState == 2) {
        digitalWrite(LED_PINGre, HIGH); // Green
      }
    }
  }
}

