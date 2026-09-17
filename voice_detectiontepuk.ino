const int soundPin = 2;

const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;

bool lampState = false;

unsigned long lastClap = 0;
const unsigned long debounceClap = 500;

void setup() {
  Serial.begin(9600);

  pinMode(soundPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  matikanLampu();

  Serial.println("LAMPU TEPUK READY");
  Serial.println("Tepuk 1x = NYALA");
  Serial.println("Tepuk lagi = MATI");
}

void loop() {

  int soundValue = digitalRead(soundPin);

  // Umumnya sensor sound aktif LOW
  if (soundValue == LOW) {

    // Mencegah satu tepukan terbaca berkali-kali
    if (millis() - lastClap > debounceClap) {

      lampState = !lampState;

      if (lampState == true) {
        nyalakanLampu();
        Serial.println("TEPUK TERDETEKSI -> LAMPU NYALA");
      }
      else {
        matikanLampu();
        Serial.println("TEPUK TERDETEKSI -> LAMPU MATI");
      }

      lastClap = millis();
    }
  }
}

void nyalakanLampu() {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
}

void matikanLampu() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}