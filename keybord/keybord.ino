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
String buf;
String cip = "AT+CIPSEND=0,"; // стандартная команда из АТ прошивки для передачи сообщения
String command; // эта переменная содержит в себе переменную СIP плюс размер структуры size
int sizee; // эта переменная мсодержит в себе размер структуры

// переменные для счета
int Period = 0;
int FlagPeriodPlus = 0;
int FlagPeriodMinus = 0;
int OldPeriod= 0;


int Menu_1_counter = 0;

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

//  delay (500); //настройка TCP сервера
//  Serial.println("AT+CIPMODE=0");
//  delay (1000);
//  Serial.println("AT+CIPMUX=1");
//  delay (1000);
//  Serial.println("AT+CIPSERVER=1,8888");
//  delay (1000);
}

void loop() {

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

}

