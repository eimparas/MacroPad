//----libraries---
#include <Keypad.h>
#include <Keyboard.h>

//----pin definitions---
#define HANDBRAKE 7

#define START 2
#define IGNITION 3


#define LED_CIRC 15
#define STRT_LED_PIN 6
#define HANDBRAKE_LED_PIN 5
#define LED_1 4

//-----constants----
const byte ROWS = 4; //five rows
const byte COLS = 5; //five columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'A','B','C','D','E'},
  {'F','G','H','I','J'},
  {'K','L','M','N','O'},
  {'T','S','R','0','0'},

};
byte rowPins[ROWS] = { A3, A2, A1, A0 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = { 14, 16, 10, 9, 8 }; //connect to the column pinouts of the keypad

//--virables--
bool flg = false;
bool onflg = false;
bool HBonflg = false;
bool HBflg = false;

//----objects---
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
    Serial.begin(9600);//serial comms for debug   
    Keyboard.begin();
    pinMode(START, INPUT_PULLUP);
    pinMode(IGNITION, INPUT_PULLUP);
    pinMode(HANDBRAKE, INPUT_PULLUP);
    pinMode(LED_1, OUTPUT);
    pinMode(STRT_LED_PIN, OUTPUT);
    pinMode(HANDBRAKE_LED_PIN, OUTPUT);
}

void loop() {
    char customKey = customKeypad.getKey();

    //code for matrix
    switch (customKey) {
    case 'A':

        Serial.println("A");
        Keyboard.print("A");
        break;
    case 'B':

        Serial.println("B");
        Keyboard.print('B');
        break;
    case 'C':
        Serial.println("C");
        Keyboard.print('C');
        break;
    case 'D':
        Serial.println("D");
        Keyboard.print('D');
        break;
    case 'E':
        Serial.println("E");
        Keyboard.print('E');
        break;
    case 'F':
        Serial.println("F");
        Keyboard.print('F');
        break;
    case 'G':
        Serial.println("G");
        Keyboard.print('G');
        break;
    case 'H':
        Serial.println("H");
        Keyboard.print('H');
        break;
    case 'I':
        Serial.println("I");
        Keyboard.print('I');
        break;
    case 'J':
        Serial.println("J");
        Keyboard.print('J');
        break;
    case 'K':
        Serial.println("K");
        Keyboard.print('K');
        break;
    case 'L':
        Serial.println("L");
        Keyboard.print('L');
        break;
    case 'M':
        Serial.println("M");
        Keyboard.print('M');
        break;
    case 'N':
        Serial.println("N");
        Keyboard.print('N');
        break;
    case 'O':
        Serial.println("O");
        Keyboard.print('O');
        break;
    case 'P':
        Serial.println("P");
        Keyboard.print('P');
        break;
    case 'Q':
        Serial.println("Q");
        Keyboard.print('Q');
        break;
    case 'R':
        Serial.println("R");
        Keyboard.print('R');
        break;
    case 'T':
        Serial.println("T");
        Keyboard.print("T");
        break;
    case 'S':
        Serial.println("S");
        Keyboard.print("S");
        break;
    }
    //code for matrix


      //code for handbrake 
    bool hbrk = digitalRead(HANDBRAKE);


    if (hbrk == 0 && HBflg == false) {
        HBflg = true;
        Serial.println("HBK");
        Keyboard.print("Q");
        HBonflg = true;
    }

    if (hbrk == 1) {
        HBflg = false;
        if (HBonflg == true) {
            HBonflg = false;
            Keyboard.print("Q");
        }
    }
    //code for handbrake 



    //---code for key------
    bool strt = digitalRead(START);
    bool ign = digitalRead(IGNITION);

    if (strt == 0 && flg == false) {
        flg = true;
        Serial.println(strt);
        Keyboard.print("V");
        onflg = true;
    }

    if (strt == true) {
        flg = false;
        if (onflg == true) {
            onflg = false;
            Keyboard.print("V");
        }

    }

    if (ign == 0) {
        Serial.println("ign");
        Keyboard.print("Z");
    }
    //---code for key------

    //----code for leds------
    bool startLEDstatus = !strt;//strt is avtive low , leds are active high    
    bool ign_Reversed = !ign;

    digitalWrite(STRT_LED_PIN, startLEDstatus);//this could be onflg
    digitalWrite(HANDBRAKE_LED_PIN, HBonflg);//on when hand brake is set
    digitalWrite(LED_1, ign_Reversed);
    //----code for leds------

    delay(100);
}