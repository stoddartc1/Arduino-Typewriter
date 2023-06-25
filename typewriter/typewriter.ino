//bool testArr[] = {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int bankOne[] = {2, 3, 5, 8, 17, 11, 13, 15, 18, 20};
int bankTwo[] = {1, 4, 9, 6, 7, 10, 12, 14, 16, 19};

//int bankOne[] = {2, 3, 5, 8, 11, 13, 15, 17, 18, 20};

//void printChar(char);
 
//int bankTwo[] = {1, 4, 6, 7, 9, 10, 12, 14, 16, 19};
const int dataPin = 13;
const int outputEnable = 12;
const int clockPin = 10;
const int latchPin = 11;
//int one = 0;
//int two = 0;
bool isCaps = false;
char prev = 0;

const int printDelay = 25;
const int doubleCharDelay = 68; //when the same key needs to be typed twice, we need an extra delay. type writter tries to prevent accidental double types

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(outputEnable, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  Serial.begin(9600);
  digitalWrite(outputEnable, HIGH);
  //writeString("\n");
}


void loop() {

  printSerial();

}

void printSerial()
{
  String input = "";
  char inByte = 0;

  while (Serial.available() > 0 || input.length() > 0)
  {
    while (Serial.available() > 0)
    {
      inByte = Serial.read();
      input += inByte;
    }
    printChar(input[0]);
    input = input.substring(1);
  }
}

void writeToShiftRegister(bool arr[], int len) {
  digitalWrite(latchPin, 0);
  digitalWrite(outputEnable, HIGH);


  for (int i = 0; i < len; i++) {
    digitalWrite(dataPin, arr[i]);

    digitalWrite(clockPin, 1);
    digitalWrite(clockPin, 0);

  }
  digitalWrite(latchPin, 1);
  digitalWrite(latchPin, 0);
  digitalWrite(outputEnable, LOW);
  delay(printDelay);
  digitalWrite(outputEnable, HIGH);
  delay(printDelay);
}

void printChar(char c) {
  if (c == prev) {
    delay(doubleCharDelay);
  }
  prev = c;
  c = tolower(c);
  switch (c) {
    case 'a':
      bridge(5, 4);
      break;
    case 'b':
      bridge(8, 2);
      break;
    case 'c':
      bridge(9, 4);
      break;
    case 'd':
      bridge(6, 2);
      break;
    case 'e':
      bridge(4, 1);
      break;
    case 'f':
      bridge(5, 2);
      break;
    case 'g':
      bridge(5, 1);
      break;
    case 'h':
      bridge(6, 1);
      break;
    case 'i':
      bridge(3, 7);
      break;
    case 'j':
      bridge(6, 3);
      break;
    case 'k':
      bridge(5, 3);
      break;
    case 'l':
      bridge(5, 7);
      break;
    case 'm':
      bridge(9, 3);
      break;
    case 'n':
      bridge(9, 2);
      break;
    case 'o':
      bridge(3, 8);
      break;
    case 'p':
      bridge(4, 8);
      break;
    case 'q':
      bridge(3, 2);
      break;
    case 'r':
      bridge(3, 1);
      break;
    case 's':
      bridge(6, 4);
      break;
    case 't':
      bridge(3, 3);
      break;
    case 'u':
      bridge(4, 7);
      break;
    case 'v':
      bridge(8, 4);
      break;
    case 'w':
      bridge(4, 2);
      break;
    case 'x':
      bridge(9, 8);
      break;
    case 'y':
      bridge(4, 3);
      break;
    case 'z':
      bridge(8, 8);
      break;
    case ' ':
      bridge(10, 4);
      break;
    case '\n':
      bridge(5, 9);
      break;
    case '1':
      bridge(1, 1);
      break;
    case '!':
      shift(true);
      bridge(1, 1);
      shift(false);
      break;
    case '2':
      bridge(2, 1);
      break;
    case '@':
      shift(true);
      bridge(2, 1);
      shift(false);
      break;
    case '3':
      bridge(2, 3);
      break;
    case '#':
      shift(true);
      bridge(2, 3);
      shift(false);
      break;
    case '4':
      bridge(1, 3);
      break;
    case '$':
      shift(true);
      bridge(1, 3);
      shift(false);
      break;
    case '5':
      bridge(1, 4);
      break;
    case '%':
      shift(true);
      bridge(1, 4);
      shift(false);
      break;
    case '6':
      bridge(2, 4);
      break;
    case '7':
      bridge(2, 7);
      break;
    case '&':
      shift(true);
      bridge(2, 7);
      shift(false);
      break;
    case '8':
      bridge(1, 7);
      break;
    case '*':
      shift(true);
      bridge(1, 7);
      shift(false);
      break;
    case '9':
      bridge(1, 8);
      break;
    case '(':
      shift(true);
      bridge(1, 8);
      shift(false);
      break;
    case '0':
      bridge(2, 8);
      break;
    case ')':
      shift(true);
      bridge(2, 8);
      shift(false);
      break;
    case '=':
      bridge(1, 9);
      break;
    case '+':
      shift(true);
      bridge(1, 9);
      shift(false);
      break;
    case '-':
      bridge(2, 9);
      break;
    case '_':
      shift(true);
      bridge(2, 9);
      shift(false);
      break;
    case '/':
      bridge(3, 9);
      break;
    case '\'':
      bridge(4, 9);
      break;
    case ';':
      bridge(6, 7);
      break;
    case ':':
      shift(true);
      bridge(6, 7);
      shift(false);
      break;
    case ',':
      bridge(8, 3);
      break;
    case '\r':
      //bridge(8, 3);
      break;
    case '.':
      bridge(8, 7);
      break;
    default:
      bridge(9, 7);
      break;
  }
}
/*void printCurr() {
  bool printTest[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  if (two == 10) {
    two = 0;
    one += 1;
  }
  printTest[24 - bankOne[one]] = 1;
  printTest[24 - bankTwo[two]] = 1;
  Serial.println(one);
  Serial.println(two);
  two += 1;
  writeToShiftRegister(printTest, 24);
}*/

void bridge(int o, int t) {
  bool printTest[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  o--;
  t--;

  printTest[24 - bankOne[o]] = 1;
  printTest[24 - bankTwo[t]] = 1;
  writeToShiftRegister(printTest, 24);
}

void shift(bool on) {
  isCaps = on;
  if (on) {
    bridge(5, 8);
  } else {
    bridge(8, 9);
  }
}

