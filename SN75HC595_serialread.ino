
     
int latchPin = 8;  //Pin connected to ST_CP(pin 12) of 74HC595
int clockPin = 11; //Pin connected to SH_CP(pin 11) of 74HC595
int dataPin = 12;  //Pin connected to DS(pin 14) of 74HC595

int arraya[] = {0b11111100,0b01100000,0b1101101}; 
byte leds = 0;
byte i = 0;     
byte incomingByte = 0;   // for incoming serial data
    void setup()
    {
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
     //updateShiftRegister(2);
    }
     
    void loop()
    
    
    {
      
       /*  check if data has been sent from the computer: */
  if (Serial.available()) {
    /* read the most recent byte */
    incomingByte = Serial.read();
    incomingByte =incomingByte - '0';
    /*ECHO the value that was read, back to the serial port. */
    Serial.println(incomingByte);
    
    if (0 >= incomingByte <= 255){
        updateShiftRegister(incomingByte);

    /*leds = 0;
    updateShiftRegister();
    delay(500);
    for (int i = 0; i <= 8; i++)
    {
    bitSet(leds, i);
    updateShiftRegister();
    */
    /*i= i<<1;
    
 
    updateShiftRegister(i);
    
    }
    
    }
  
*/}}}
    
     
    void updateShiftRegister(byte leds)
    {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, leds);
    digitalWrite(latchPin, HIGH);
    delay(200);
    
    }
