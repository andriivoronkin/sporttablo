/*menu of sporttablo
  by Voronkin Andrii
  andriivoronkin@gmail.com*/

#include <SPI.h> //библиотека spi//
#include <LiquidCrystal.h> //библиотека для LCD//

const uint8_t Rs = 23, En = 22, Rw = 6, d0 = A0, d1 = A1, d2 = A2, d3 = A3, d4 = A4, d5 = A5, d6 = A6, d7 = A7; /* выходы LCDRS = 23 /E = 22 / rw = 6*/
uint8_t led = 4; // пин питания подстветки дисплея
LiquidCrystal lcd(Rs, Rw, En, d0, d1, d2, d3, d4, d5, d6, d7);
//keyboard
uint8_t clockPin = 9; //PB1 = D9
uint8_t dataPin = 5; //data PD5 =D5
const uint8_t slaveSelectPin = 10; /*PB2 = D10 int latchPin = 10;// пин, управляющий защёлкой (SS в терминах SPI) */

//хранятся значения кнопок
uint8_t key_buff [8];
uint8_t KeyMenuBuf [8];

//Кнопки меню
uint8_t MenuCounter = 0;
uint8_t FlagMenu = 0;
//int score1 = 0;
//int oldscore = -1;

// команда для ESP
// установки для передачи по TCP
String cip = "AT+CIPSEND=0,"; // стандартная команда из АТ прошивки для передачи сообщения
String command; // эта переменная содержит в себе переменную СIP плюс размер структуры size
uint8_t sizee; // эта переменная мсодержит в себе размер структуры
char buffer [49];
char End = '$';
uint8_t a = 0;


long previousMillis = 0;
const long interval = 3000;
long currentMillis = 0;


// переменные для счета
uint8_t Period = 0;
uint8_t FlagPeriodPlus = 0;
uint8_t FlagPeriodMinus = 0;
// переменные для таймаута
uint8_t LeftTimeout = 0;
uint8_t RightTimeout = 0;
uint8_t FlagTimeoutLeftPlus = 0;
uint8_t FlagTimeoutLeftMinus = 0;
uint8_t FlagTimeoutRightPlus = 0;
uint8_t FlagTimeoutRightMinus = 0;
//переменные для партий
uint8_t LeftPart1 = 0;
uint8_t RightPart1 = 0;
uint8_t FlagPart1LeftPlus = 0;
uint8_t FlagPart1LeftMinus = 0;
uint8_t FlagPart1RightPlus = 0;
uint8_t FlagPart1RightMinus = 0;
//*****//
uint8_t LeftPart2 = 0;
uint8_t RightPart2 = 0;
uint8_t FlagPart2LeftPlus = 0;
uint8_t FlagPart2LeftMinus = 0;
uint8_t FlagPart2RightPlus = 0;
uint8_t FlagPart2RightMinus = 0;
//*****//
uint8_t LeftPart3 = 0;
uint8_t RightPart3 = 0;
uint8_t FlagPart3LeftPlus = 0;
uint8_t FlagPart3LeftMinus = 0;
uint8_t FlagPart3RightPlus = 0;
uint8_t FlagPart3RightMinus = 0;
//*****//
uint8_t LeftPart4 = 0;
uint8_t RightPart4 = 0;
uint8_t FlagPart4LeftPlus = 0;
uint8_t FlagPart4LeftMinus = 0;
uint8_t FlagPart4RightPlus = 0;
uint8_t FlagPart4RightMinus = 0;
//таймер
uint8_t Minute = 0;
uint8_t FlagMinutePlus = 0;
uint8_t FlagMinuteMinus = 0;
uint8_t Sec = 0;


uint8_t Menu_1_counter = 0;
uint8_t Menu_2_counter = 0;
uint8_t Menu_3_counter = 0;
uint8_t Menu_4_counter = 0;
uint8_t Menu_5_counter = 0;
uint8_t Menu_6_counter = 0;
uint8_t Menu_7_counter = 0;

void setup()
{
  Serial.begin(9600); // стартуем сериал ESP

  lcd.begin(16, 2); // стартуем LCD
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode (slaveSelectPin, OUTPUT);
  SPI.begin();
  digitalWrite(slaveSelectPin, HIGH);//    digitalWrite(slaveSelectPin, LOW); // выбор ведомого - нашего регистра, необходимо перевести в 1
  //      SPI.transfer(0); // очищаем содержимое регистра
  //  MainMenu ();
  Serial.println("ATE1");
  delay (500); //настройка TCP сервера
  Serial.println("AT+CIPMODE=0");
  delay (1000);
  Serial.println("AT+CIPMUX=1");
  delay (1000);
  Serial.println("AT+CIPSERVER=1,8888");
  delay (1000);
}

void loop() {
  //  sizee = sizeof (tabl);



  static uint8_t val = 1; // эта переменная нужнатолько для передачи по SPI
  uint8_t keyb1 = 0; // здесь хранится байт от левой клавиатуры
  uint8_t keyb2 = 0; // здесь хранится байт от правой клавиатуры

  digitalWrite(slaveSelectPin, LOW);
  digitalWrite(slaveSelectPin, HIGH);
  keyb1 = SPI.transfer(val);
  delay(10);
  keyb2 = SPI.transfer(val);


  // смотреть состояние кнопок
  //  lcd.setCursor(2, 0);
  //  lcd.print(keyb1, BIN);
  //  lcd.setCursor(2, 1);
  //  lcd.print(keyb2, BIN);
  //  delay (2000);
  // lcd.clear ();

  //************************
  //score 1
  //вычитываем состояние левых кнопок
  for (int k = 0; k < 8; k++)
  {
    KeyMenuBuf[k] = bitRead(keyb1, k);
  }

  //вычитываем состояние левых кнопок
  for (int n = 0; n < 8; n++)
  {
    key_buff[n] = bitRead(keyb2, n);
  }


  // эта функция задает меню
  //  key1();
  //  key2();
  Menu ();
  


  currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

sprintf (buffer, "%3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d %c", Period, LeftTimeout, RightTimeout, LeftPart1, RightPart1, LeftPart2, RightPart2, LeftPart3, RightPart3, LeftPart4, RightPart4, Minute, '$');
a = 0;
int i = 0;
while (buffer[i] != '\0')
{
  i++;
  a++;
}

    delay(10);
    sizee = 49;
    command = cip + sizee;

    
    Serial.println(command);
    delay (100);
    Serial.println(buffer);

  }
}


