 void MainMenu ()
 {
  lcd.setCursor(1, 0);
  lcd.print ("00-C\253ET-00");//\253 - Ч -cчет-
//  lcd.setCursor(3, 0);
//  lcd.print ("-");
//  lcd.setCursor(4, 0);
//  lcd.print ("C");
//  lcd.setCursor(5, 0);
//  lcd.write(byte(0));
//  lcd.setCursor(6, 0);
//  lcd.print ("\253"); 
//  lcd.setCursor(7, 0);
//  lcd.print ("T");
//  lcd.setCursor(8, 0);
//  lcd.print ("-");
//  lcd.setCursor(9, 0);
//  lcd.print ("00");
  //lcd.print ("-cчет-");
  //lcd.print ("-cчет-");
  lcd.setCursor(12, 0);
  lcd.print ("T-");
  lcd.setCursor(14, 0);
  lcd.print ("0");
  
  lcd.setCursor(1, 1);
  lcd.print ("0");
  lcd.setCursor(2, 1);
  lcd.print ("-");
  lcd.setCursor(3, 1);
  lcd.print ("\252"); //Ф
//  lcd.print ("ф");
  lcd.setCursor(4, 1);
  lcd.print ("O");
  lcd.setCursor(5, 1);
  lcd.print ("\247"); //Л
//  lcd.print ("Л");
  lcd.setCursor(6, 1);
  lcd.print ("-");
  lcd.setCursor(7, 1);
  lcd.print ("0");
  lcd.setCursor(10, 1);
  lcd.print ("0");
  lcd.setCursor (10, 1);
  lcd.print ("00");
  lcd.setCursor (12, 1);
  lcd.print (":");
  lcd.setCursor (13, 1);
  lcd.print ("00");
 }



void Menu_1 ()
{
 
  //счет левый+
    if (key_buff[4] == 0&&FlagPeriodPlus ==0)
    {
    delay(10);
    lcd.clear();
    Period++;
    Menu_1_counter++;
    FlagPeriodPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
    }    
   
   if (key_buff[4] == 1&&FlagPeriodPlus ==1)
  {
    FlagPeriodPlus = 0;
  }
  // счет левый-


  if (key_buff[5] == 0&&FlagPeriodMinus == 0)
  {
    delay(10);
    lcd.clear();
    Period--;
    Menu_1_counter++;
    FlagPeriodMinus = 1 ;
  }


  if (key_buff[5] == 1&&FlagPeriodMinus ==1)
  {
    FlagPeriodMinus = 0;
  }
  
  
  lcd.setCursor(1, 0);
  lcd.print ("\250EP\245O\340-"); // ПЕРИОД- 245 - И 340 -Д
  lcd.setCursor(8, 0);
  lcd.print (Period);

  lcd.setCursor(1, 1);
  lcd.print ("X");
  lcd.setCursor(2, 1);
  lcd.print ("X");
  lcd.setCursor(3, 1);
  lcd.write("X"); 
  lcd.setCursor(4, 1);
  lcd.print ("X");
  lcd.setCursor(5, 1);

//  lcd.print ("Л");
  
  lcd.setCursor(10, 1);
//  lcd.print (U);
//  lcd.setCursor (11, 1);
//  lcd.print ("=");
//  lcd.setCursor (12, 1);
//  lcd.print ("00");
//  
//  
//  
//  
 }
 
  void Menu_2 ()
 {
   if (key_buff[4] == 0&&FlagTimeoutLeftPlus ==0)
    {
    delay(10);
    lcd.clear();
    LeftTimeout++;
    Menu_2_counter++;
    FlagTimeoutLeftPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
    }    
   
   if (key_buff[4] == 1&&FlagTimeoutLeftPlus ==1)
  {
    FlagTimeoutLeftPlus = 0;
  }
  // счет левый-


  if (key_buff[5] == 0&&FlagTimeoutLeftMinus == 0)
  {
    delay(10);
    lcd.clear();
    LeftTimeout--;
    Menu_2_counter++;
    FlagTimeoutLeftMinus = 1 ;
  }


  if (key_buff[5] == 1&&FlagTimeoutLeftMinus ==1)
  {
    FlagTimeoutLeftMinus = 0;
  }
   
  //**********************************************************
 if (key_buff[1] == 0&&FlagTimeoutRightPlus ==0)
    {
    delay(10);
    lcd.clear();
    RightTimeout++;
    Menu_2_counter++;
    FlagTimeoutRightPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
    }    
   
   if (key_buff[1] == 1&&FlagTimeoutRightPlus ==1)
  {
    FlagTimeoutRightPlus = 0;
  }
  // счет левый-


  if (key_buff[2] == 0&&FlagTimeoutRightMinus == 0)
  {
    delay(10);
    lcd.clear();
    RightTimeout--;
    Menu_2_counter++;
    FlagTimeoutRightMinus = 1 ;
  }


  if (key_buff[2] == 1&&FlagTimeoutRightMinus ==1)
  {
    FlagTimeoutRightMinus = 0;
  } 
   
  lcd.setCursor(1, 0);
  lcd.print (LeftTimeout);
  lcd.setCursor(2, 0);
  lcd.print ("-TA\246MA\251T-");
  lcd.setCursor(11, 0);
  lcd.print (RightTimeout);
  lcd.setCursor(1, 1);
  lcd.print ("X");
  lcd.setCursor(2, 1);
  lcd.print ("X");
  lcd.setCursor(3, 1);
  lcd.write("X"); 
  lcd.setCursor(4, 1);
  lcd.print ("X");
  lcd.setCursor(5, 1);
  lcd.write("X"); 
//  lcd.print ("Л");

  lcd.setCursor(10, 1);
  lcd.print ("U");
  lcd.setCursor (11, 1);
  lcd.print ("=");
  lcd.setCursor (12, 1);
  lcd.print ("00");
 }
 
  void Menu_3 ()
 {
  
   if (key_buff[4] == 0&&FlagPart1LeftPlus ==0)
    {
    lcd.clear();
    LeftPart1++;
    Menu_3_counter++;
    FlagPart1LeftPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
    }    
   
   if (key_buff[4] == 1&&FlagPart1LeftPlus ==1)
  {
    FlagPart1LeftPlus = 0;
  }
  // счет левый-


  if (key_buff[5] == 0&&FlagPart1LeftMinus == 0)
  {
    lcd.clear();
    LeftPart1--;
    Menu_3_counter++;
    FlagPart1LeftMinus = 1 ;
  }


  if (key_buff[5] == 1&&FlagPart1LeftMinus ==1)
  {
    FlagPart1LeftMinus = 0;
  }
   
  //**********************************************************
 if (key_buff[6] == 0&&FlagPart1RightPlus ==0)
    {
    lcd.clear();
    RightPart1++;
    Menu_3_counter++;
    FlagPart1RightPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
    }    
   
   if (key_buff[6] == 1&&FlagPart1RightPlus ==1)
  {
    FlagPart1RightPlus = 0;
  }
  // счет левый-


  if (key_buff[7] == 0&&FlagPart1RightMinus == 0)
  {
    lcd.clear();
    RightPart1--;
    Menu_3_counter++;
    FlagPart1RightMinus = 1 ;
  }


  if (key_buff[7] == 1&&FlagPart1RightMinus ==1)
  {
    FlagPart1RightMinus = 0;
  }    
   
   
   
   
   
   

  lcd.setCursor(2, 0);
  lcd.print (LeftPart1);
  lcd.setCursor(3, 0);
  lcd.print ("-\250APT\245\261"); //250 П \245 И \261 Я


  lcd.setCursor(10, 0);
  lcd.print ("1-");
  lcd.setCursor(12, 0);
  lcd.print (RightPart1);

  lcd.setCursor(1, 1);
  lcd.print ("X");
  lcd.setCursor(2, 1);
  lcd.print ("X");
  lcd.setCursor(3, 1);
  lcd.write("X"); 
  lcd.setCursor(4, 1);
  lcd.print ("X");
  lcd.setCursor(5, 1);
  lcd.write("X"); 
//  lcd.print ("Л");
  
  lcd.setCursor(10, 1);
  lcd.print ("U");
  lcd.setCursor (11, 1);
  lcd.print ("=");
  lcd.setCursor (12, 1);
  lcd.print ("00");
 }
 
  void Menu_4 ()
 {
  
  lcd.setCursor(1, 0);
  lcd.print ("0");
  lcd.setCursor(2, 0);
  lcd.print ("0");
  lcd.setCursor(3, 0);
  lcd.print ("-");
  lcd.setCursor(4, 0);
  lcd.write("\250");
  lcd.setCursor(5, 0);
  lcd.print ("A");
  lcd.setCursor(6, 0);
  lcd.print ("P");
  lcd.setCursor(7, 0);
  lcd.print ("T");
  lcd.setCursor(8, 0);
  lcd.print ("\245");
  lcd.setCursor(9, 0);
  lcd.print ("\261");
  lcd.setCursor(10, 0);
  lcd.print ("2");
  lcd.setCursor(11, 0);
  lcd.print ("-");
  lcd.setCursor(12, 0);
  lcd.print ("0");
  lcd.setCursor(13, 0);
  lcd.print ("0");
  lcd.setCursor(1, 1);
  lcd.print ("X");
  lcd.setCursor(2, 1);
  lcd.print ("X");
  lcd.setCursor(3, 1);
  lcd.write("X"); 
  lcd.setCursor(4, 1);
  lcd.print ("X");
  lcd.setCursor(5, 1);
  lcd.write("X"); 
//  lcd.print ("Л");
  
  lcd.setCursor(10, 1);
  lcd.print ("U");
  lcd.setCursor (11, 1);
  lcd.print ("=");
  lcd.setCursor (12, 1);
  lcd.print ("00");
 }
 
  void Menu_5 ()
 {

  lcd.setCursor(1, 0);
  lcd.print ("0");
  lcd.setCursor(2, 0);
  lcd.print ("0");
  lcd.setCursor(3, 0);
  lcd.print ("-");
  lcd.setCursor(4, 0);
  lcd.write("\250");
  lcd.setCursor(5, 0);
  lcd.print ("A");
  lcd.setCursor(6, 0);
  lcd.print ("P");
  lcd.setCursor(7, 0);
  lcd.print ("T");
  lcd.setCursor(8, 0);
  lcd.print ("\245");
  lcd.setCursor(9, 0);
  lcd.print ("\261");
  lcd.setCursor(10, 0);
  lcd.print ("3");
  lcd.setCursor(11, 0);
  lcd.print ("-");
  lcd.setCursor(12, 0);
  lcd.print ("0");
  lcd.setCursor(13, 0);
  lcd.print ("0");
  lcd.setCursor(1, 1);
  lcd.print ("X");
  lcd.setCursor(2, 1);
  lcd.print ("X");
  lcd.setCursor(3, 1);
  lcd.write("X"); 
  lcd.setCursor(4, 1);
  lcd.print ("X");
  lcd.setCursor(5, 1);
  lcd.write("X"); 
//  lcd.print ("Л");
  
  lcd.setCursor(10, 1);
  lcd.print ("U");
  lcd.setCursor (11, 1);
  lcd.print ("=");
  lcd.setCursor (12, 1);
  lcd.print ("00");
 }
 
  void Menu_6 ()
 {

  lcd.setCursor(1, 0);
  lcd.print ("0");
  lcd.setCursor(2, 0);
  lcd.print ("0");
  lcd.setCursor(3, 0);
  lcd.print ("-");
  lcd.setCursor(4, 0);
  lcd.write("\250");
  lcd.setCursor(5, 0);
  lcd.print ("A");
  lcd.setCursor(6, 0);
  lcd.print ("P");
  lcd.setCursor(7, 0);
  lcd.print ("T");
  lcd.setCursor(8, 0);
  lcd.print ("\245");
  lcd.setCursor(9, 0);
  lcd.print ("\261");
  lcd.setCursor(10, 0);
  lcd.print ("4");
  lcd.setCursor(11, 0);
  lcd.print ("-");
  lcd.setCursor(12, 0);
  lcd.print ("0");
  lcd.setCursor(13, 0);
  lcd.print ("0");
  lcd.setCursor(1, 1);
  lcd.print ("X");
  lcd.setCursor(2, 1);
  lcd.print ("X");
  lcd.setCursor(3, 1);
  lcd.write("X"); 
  lcd.setCursor(4, 1);
  lcd.print ("X");
  lcd.setCursor(5, 1);
  lcd.write("X"); 
//  lcd.print ("Л");
  
  lcd.setCursor(10, 1);
  lcd.print ("U");
  lcd.setCursor (11, 1);
  lcd.print ("=");
  lcd.setCursor (12, 1);
  lcd.print ("00");
 }
 
  void Menu_7 ()
 {

  lcd.setCursor(1, 0);
  lcd.print ("T");
  lcd.setCursor(2, 0);
  lcd.print ("A");
  lcd.setCursor(3, 0);
  lcd.print ("\246");
  lcd.setCursor(4, 0);
  lcd.write("M");
  lcd.setCursor(5, 0);
  lcd.print ("E");
  lcd.setCursor(6, 0);
  lcd.print ("P");
  lcd.setCursor(7, 0);
  lcd.print ("-");
  lcd.setCursor(8, 0);
  lcd.print ("0");
  lcd.setCursor(9, 0);
  lcd.print ("0");
  lcd.setCursor(10, 0);
  lcd.print ("0");
  
  lcd.setCursor(1, 1);
  lcd.print ("Y");
  lcd.setCursor(2, 1);
  lcd.print ("Y");
  lcd.setCursor(3, 1);
  lcd.write("Y"); 
  lcd.setCursor(4, 1);
  lcd.print ("Y");
  lcd.setCursor(5, 1);
  lcd.write("Y"); 
//  lcd.print ("Л");
  
  lcd.setCursor(10, 1);
  lcd.print ("U");
  lcd.setCursor (11, 1);
  lcd.print ("=");
  lcd.setCursor (12, 1);
  lcd.print ("00");
 }
 
