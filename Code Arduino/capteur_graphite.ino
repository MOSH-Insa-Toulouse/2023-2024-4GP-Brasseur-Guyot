#include <SoftwareSerial.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>


// Bluetooth

#define rxPin 7
#define txPin 8
#define baudrate 9600
SoftwareSerial mySerial(rxPin, txPin);

int i = 0;

// Digital potentiometre

#define MCP_NOP 0b00000000
#define MCP_WRITE 0b00010001
#define MCP_SHTDWN 0b00100001

const int ssMCPin = 10;

void SPIWrite(uint8_t cmd, uint8_t data, uint8_t ssPin) // SPI write the command and data to the MCP IC connected to the ssPin
{
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0)); //https://www.arduino.cc/en/Reference/SPISettings
  
  digitalWrite(ssPin, LOW); // SS pin low to select chip
  
  SPI.transfer(cmd);        // Send command code
  SPI.transfer(data);       // Send associated value
  
  digitalWrite(ssPin, HIGH);// SS pin high to de-select chip
  SPI.endTransaction();
}

int resInit = 127;

// OLED screen

#define nombreDePixelsEnLargeur 128         // Taille de l'écran OLED, en pixel, au niveau de sa largeur
#define nombreDePixelsEnHauteur 64          // Taille de l'écran OLED, en pixel, au niveau de sa hauteur
#define brocheResetOLED         -1          // Reset de l'OLED partagé avec l'Arduino (d'où la valeur à -1, et non un numéro de pin)
#define adresseI2CecranOLED     0x3C        // Adresse de "mon" écran OLED sur le bus i2c (généralement égal à 0x3C ou 0x3D)

Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);

// encoder 

#define encoder0PinA  2  //CLK Output A Do not use other pin for clock as we are using interrupt
#define encoder0PinB  4  //DT Output B

volatile unsigned int encoder0Pos = 0;

void doEncoder() {
  if (digitalRead(encoder0PinB)==HIGH) {
    encoder0Pos++;
  } else {
    encoder0Pos--;
  }
}

// encoder debouncing
long lastDebounceTime = 0; // the last time the output pin was toggled
long debounceDelay = 200; // the debounce time; increase if the output flickers

int reading;
int encoderState;
int lastEncoderState = 0;


void setup() {
  // def pins Bluetooth
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  Serial.begin(9600);
  mySerial.begin(9600);
  
  // def pins sensors
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  // def pins Digipot
  pinMode (ssMCPin, OUTPUT); //select pin output
  digitalWrite(ssMCPin, HIGH); //SPI chip disabled
  SPI.begin();
  SPIWrite(MCP_WRITE, resInit, ssMCPin);

  // OLED screen init
  if(!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
  {
    while(1);
  }                               // Arrêt du programme (boucle infinie) si échec d'initialisation

  ecranOLED.clearDisplay();                   // Effaçage de l'intégralité du buffer
  ecranOLED.setTextSize(1);                   // Taille des caractères
  ecranOLED.setCursor(0, 0);

  for(byte numeroDeLigne=1; numeroDeLigne<=8; numeroDeLigne++) {
      ecranOLED.setTextColor(SSD1306_WHITE);                  // Affichage du texte en "blanc" (avec la couleur principale, en fait, car l'écran monochrome peut être coloré)
      ecranOLED.print("coucou ");
  }
  ecranOLED.display();

  //def pins encoder
  pinMode(encoder0PinA, INPUT); 
  digitalWrite(encoder0PinA, HIGH);       // turn on pullup resistor

  pinMode(encoder0PinB, INPUT); 
  digitalWrite(encoder0PinB, HIGH);       // turn on pullup resistor

  attachInterrupt(0, doEncoder, RISING); // encoder pin on interrupt 0 - pin2

}

void loop() 
{   
  // main code

  float valCap;
  float valFlex;

  int resDigipot;

  String fullString;

  valCap = analogRead(A0)*5.0/1024;
  valFlex = analogRead(A1)*5.0/1024;
  
  encoderState = encoder0Pos;

  if (encoderState >= 128)
  {
    encoder0Pos = 127;
    encoderState = 127;
  }
  if (encoderState <= -127)
  {
    encoder0Pos = -126;
    encoderState = -126;
  }
  /*if (reading != lastEncoderState) {
    lastDebounceTime = millis(); // reset the debouncing timer
  }
  if ((millis() - lastDebounceTime) > debounceDelay)
  { // whatever the reading is at, it's been there for longer than the debounce delay, so take it as the actual current state:
    encoderState = reading;
  }
  lastEncoderState = reading; // save the reading. Next time through the loop, it'll be the lastButtonState*/
  
  

  resDigipot = encoderState + 127;


  SPIWrite(MCP_WRITE, resDigipot, ssMCPin);
  
  // monitor display
  /*Serial.print("Capteur : ");
  Serial.println(valCap);
  Serial.print("Flex : ");
  Serial.println(valFlex);
  Serial.print("R2 : ");
  Serial.println(resDigipot);
  Serial.println("");*/

  i++;
  if (i == 10) i = 0;
  if(i==9) {
    // Bluetooth display
    fullString += String(valCap);
    fullString += ";";
    fullString += String(valFlex);
    fullString += ";";
    fullString += String(resDigipot*100000/256);
    fullString += ";";
    mySerial.println(fullString);
  }

  

  // screen display
  ecranOLED.clearDisplay();
  ecranOLED.setTextSize(1);
  ecranOLED.setCursor(0, 0);
  ecranOLED.print("Capteur : ");
  ecranOLED.println(valCap);
  ecranOLED.print("Flex : ");
  ecranOLED.println(valFlex);
  ecranOLED.print("R2 : ");
  ecranOLED.println(resDigipot*100000/256);
  ecranOLED.display();
  
  delay(50);
}
