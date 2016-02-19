/*
===================================================================================
Program for Seven Segment Display - 2 Digits countdown
===================================================================================

* works with both Common Cathode and Common Anode
* Based on the type of Display you are using comment out the other type
    i.e. if your display is Common Cathode,
    comment all the Common Anode codings
    and vice versa

* Pin Configuration

       __a__
      /    /
   f /    / b
    /__g_/
    /    / 
 e /    /c
  /____/   o h
    d

    a ~ h -> IO2 ~ IO9
    common pins IO10, IO11
    
===================================================================================
(copywrite) © Poornamith
the PAH inv
created: 16-02-2016
revised: 19-02-2016
www.poornamith.azurewebsites.net
===================================================================================
*/


unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

//digits
short dig0 = 0, dig1 = 0;


void setup() {

  /* https://www.arduino.cc/en/Reference/PortManipulation */
  //Port D as output
  DDRD = DDRD | 0b11111100;  // this is safer as it sets pins 2 to 7 as outputs
  // without changing the value of pins 0 & 1, which are RX & TX
  //Port B as Output except 10, 11 as Input
  
  //IF COMMON ANODE
  //DDRB = 0b00000011;

  //IF COMMON CATHODE
  DDRB = 0b00001111;

  //Enable Pull Ups if COMMON CATHODE (else Enable if its not working in  realtime)
  //digitalWrite(10, HIGH);
  //digitalWrite(11, HIGH);

}

void loop() {

    /*  Human eyes can't detect a delay under 20ms
   *  so we display one SSD for 10ms and other for 10ms.
   */
   
   //get the current number of milliseconds since the Arduino board began running the current program.
   //used to make a loop  progamatically
  currentMillis = millis();

  //loop: counts upto 99 
  for (int i = 0; i < 100; i++) {

    //this is a loop of delay(1000);
    previousMillis = millis() + 1000;
    while ( currentMillis <= previousMillis) {
      currentMillis = millis();

      //divide the number in to two parts
      dig1 = i % 10;
      dig0 = i / 10;
      
      //displayDigitCA(dig0);
      displayDigitCC(dig1);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      delay(10);

      //displayDigitCA(dig1);
      displayDigitCC(dig0);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      delay(10);
    }
  }

}

void displayDigitCA(short num) {
  switch (num) {
    case 0:
      PORTD = 0b00000000;
      PORTB = 0b00000011;
      break;
    case 1:
      PORTD = 0b11100100;
      PORTB = 0b00000011;
      break;
    case 2:
      PORTD = 0b10010000;
      PORTB = 0b00000010;
      break;
    case 3:
      PORTD = 0b11000000;
      PORTB = 0b00000010;
      break;
    case 4:
      PORTD = 0b01100100;
      PORTB = 0b00000010;
      break;
    case 5:
      PORTD = 0b01001000;
      PORTB = 0b00000010;
      break;
    case 6:
      PORTD = 0b0001000;
      PORTB = 0b00000010;
      break;
    case 7:
      PORTD = 0b11100000;
      PORTB = 0b00000011;
      break;
    case 8:
      PORTD = 0b00000000;
      PORTB = 0b00000010;
      break;
    case 9:
      PORTD = 0b01000000;
      PORTB = 0b00000010;
      break;
    //for dot pin
    default:
      PORTD = 0b11111100;
      PORTB = 0b00000001;
      break;
  }
}

void displayDigitCC(short num) {
  //in CC the bits should be inverted. so use ~ operator to invert the whole set.
  switch (num) {
    case 0:
      PORTD = ~0b00000000;
      PORTB = ~0b00000011;
      break;
    case 1:
      PORTD = ~0b11100100;
      PORTB = ~0b00000011;
      break;
    case 2:
      PORTD = ~0b10010000;
      PORTB = ~0b00000010;
      break;
    case 3:
      PORTD = ~0b11000000;
      PORTB = ~0b00000010;
      break;
    case 4:
      PORTD = ~0b01100100;
      PORTB = ~0b00000010;
      break;
    case 5:
      PORTD = ~0b01001000;
      PORTB = ~0b00000010;
      break;
    case 6:
      PORTD = ~0b0001000;
      PORTB = ~0b00000010;
      break;
    case 7:
      PORTD = ~0b11100000;
      PORTB = ~0b00000011;
      break;
    case 8:
      PORTD = ~0b00000000;
      PORTB = ~0b00000010;
      break;
    case 9:
      PORTD = ~0b01000000;
      PORTB = ~0b00000010;
      break;
    //for dot pin
    default:
      PORTD = 0b11111100;
      PORTB = 0b00000001;
      break;
  }
}

