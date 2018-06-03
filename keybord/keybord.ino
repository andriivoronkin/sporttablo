/*menu of sporttablo
  by Voronkin Andrii
  andriivoronkin@gmail.com*/

#include <SPI.h> //библиотека spi//
#include <LiquidCrystal.h> //библиотека для LCD//

const int Rs = 23, En = 22, Rw = 6, d0 = A0, d1 = A1, d2 = A2, d3 = A3, d4 = A4, d5 = A5, d6 = A6, d7 = A7; /* выходы LCDRS = 23 /E = 22 / rw = 6*/
int led = 4; // пин питания подстветки дисплея
LiquidCrystal lcd(Rs, Rw, En, d0, d1, d2, d3, d4, d5, d6, d7);
//keyboard 
int clockPin = 9; //PB1 = D9
int dataPin = 5; //data PD5 =D5
const int slaveSelectPin = 10; /*PB2 = D10 int latchPin = 10;// пин, управляющий защёлкой (SS в терминах SPI) */

//хранятся значения кнопок
int key_buff [8];
int KeyMenuBuf [8];

//Кнопки меню
int MenuCounter = 0;
int FlagMenu = 0;
//int score1 = 0;
//int oldscore = -1;

// команда для ESP
// установки для передачи по TCP
String cip = "AT+CIPSEND=0,"; // стандартная команда из АТ прошивки для передачи сообщения
String command; // эта переменная содержит в себе переменную СIP плюс размер структуры size
int sizee; // эта переменная мсодержит в себе размер структуры
String data;
char buffer[8];
char probel = ' ';

long previousMillis = 0;
const long interval = 2000;
long currentMillis = 0;


// переменные для счета
int Period = 0;
int FlagPeriodPlus = 0;
int FlagPeriodMinus = 0;
// переменные для таймаута
int LeftTimeout = 0;
int RightTimeout = 0;
int FlagTimeoutLeftPlus = 0;
int FlagTimeoutLeftMinus = 0;
int FlagTimeoutRightPlus = 0;
int FlagTimeoutRightMinus = 0;
//переменные для партий
int LeftPart1 = 0;
int RightPart1 = 0;
int FlagPart1LeftPlus = 0;
int FlagPart1LeftMinus = 0;
int FlagPart1RightPlus = 0;
int FlagPart1RightMinus = 0;
//*****//
int LeftPart2 = 0;
int RightPart2 = 0;
int FlagPart2LeftPlus = 0;
int FlagPart2LeftMinus = 0;
int FlagPart2RightPlus = 0;
int FlagPart2RightMinus = 0;
//*****//
int LeftPart3 = 0;
int RightPart3 = 0;
int FlagPart3LeftPlus = 0;
int FlagPart3LeftMinus = 0;
int FlagPart3RightPlus = 0;
int FlagPart3RightMinus = 0;
//*****//
int LeftPart4 = 0;
int RightPart4 = 0;
int FlagPart4LeftPlus = 0;
int FlagPart4LeftMinus = 0;
int FlagPart4RightPlus = 0;
int FlagPart4RightMinus = 0;
//таймер
int Minute = 0;
int FlagMinutePlus = 0;
int FlagMinuteMinus = 0;
int Sec = 0;


int Menu_1_counter = 0;
int Menu_2_counter = 0;
int Menu_3_counter = 0;
int Menu_4_counter = 0;
int Menu_5_counter = 0;
int Menu_6_counter = 0;
int Menu_7_counter = 0;

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
  data = "";  
  data = data + Period;
  data = data + " ";
  data = data + LeftTimeout;
  data = data + " ";
  data = data + RightTimeout;
  data = data + " ";
  data = data + Minute;
  data = data + "$";
  data = data + "\r\n";
  sizee = sizeof (data);

 
  delay(10);
  command = cip + sizee;
  
  Serial.println(command);
  delay (100);
  Serial.print(data);

  }
}


