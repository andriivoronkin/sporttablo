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
  if (key_buff[4] == 0 && FlagPeriodPlus == 0)
  {
    delay(10);
    lcd.clear();
    Period++;
    Menu_1_counter++;
    FlagPeriodPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[4] == 1 && FlagPeriodPlus == 1)
  {
    FlagPeriodPlus = 0;
  }
  // счет левый-

  if (key_buff[5] == 0 && FlagPeriodMinus == 0)
  {
    delay(10);
    lcd.clear();
    Period--;
    Menu_1_counter++;
    FlagPeriodMinus = 1 ;
  }

  if (key_buff[5] == 1 && FlagPeriodMinus == 1)
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
  if (key_buff[4] == 0 && FlagTimeoutLeftPlus == 0)
  {
    delay(10);
    lcd.clear();
    LeftTimeout++;
    Menu_2_counter++;
    FlagTimeoutLeftPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[4] == 1 && FlagTimeoutLeftPlus == 1)
  {
    FlagTimeoutLeftPlus = 0;
  }
  // счет левый-

  if (key_buff[5] == 0 && FlagTimeoutLeftMinus == 0)
  {
    delay(10);
    lcd.clear();
    LeftTimeout--;
    Menu_2_counter++;
    FlagTimeoutLeftMinus = 1 ;
  }

  if (key_buff[5] == 1 && FlagTimeoutLeftMinus == 1)
  {
    FlagTimeoutLeftMinus = 0;
  }

  //**********************************************************
  if (key_buff[1] == 0 && FlagTimeoutRightPlus == 0)
  {
    delay(10);
    lcd.clear();
    RightTimeout++;
    Menu_2_counter++;
    FlagTimeoutRightPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[1] == 1 && FlagTimeoutRightPlus == 1)
  {
    FlagTimeoutRightPlus = 0;
  }
  // счет левый-

  if (key_buff[2] == 0 && FlagTimeoutRightMinus == 0)
  {
    delay(10);
    lcd.clear();
    RightTimeout--;
    Menu_2_counter++;
    FlagTimeoutRightMinus = 1 ;
  }

  if (key_buff[2] == 1 && FlagTimeoutRightMinus == 1)
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
  if (key_buff[4] == 0 && FlagPart1LeftPlus == 0)
  {
    lcd.clear();
    LeftPart1++;
    Menu_3_counter++;
    FlagPart1LeftPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[4] == 1 && FlagPart1LeftPlus == 1)
  {
    FlagPart1LeftPlus = 0;
  }
  // счет левый-


  if (key_buff[5] == 0 && FlagPart1LeftMinus == 0)
  {
    lcd.clear();
    LeftPart1--;
    Menu_3_counter++;
    FlagPart1LeftMinus = 1 ;
  }

  if (key_buff[5] == 1 && FlagPart1LeftMinus == 1)
  {
    FlagPart1LeftMinus = 0;
  }

  //**********************************************************
  if (key_buff[1] == 0 && FlagPart1RightPlus == 0)
  {
    lcd.clear();
    RightPart1++;
    Menu_3_counter++;
    FlagPart1RightPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[1] == 1 && FlagPart1RightPlus == 1)
  {
    FlagPart1RightPlus = 0;
  }
  // счет левый-

  if (key_buff[2] == 0 && FlagPart1RightMinus == 0)
  {
    lcd.clear();
    RightPart1--;
    Menu_3_counter++;
    FlagPart1RightMinus = 1 ;
  }

  if (key_buff[2] == 1 && FlagPart1RightMinus == 1)
  {
    FlagPart1RightMinus = 0;
  }

  if (LeftPart1 < 10)
  {
    lcd.setCursor(2, 0);
    lcd.print (LeftPart1);
  }
  if (LeftPart1 >= 10)
  {
    lcd.setCursor(1, 0);
    lcd.print (LeftPart1);
  }

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
  if (key_buff[4] == 0 && FlagPart2LeftPlus == 0)
  {
    lcd.clear();
    LeftPart2++;
    Menu_4_counter++;
    FlagPart2LeftPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[4] == 1 && FlagPart2LeftPlus == 1)
  {
    FlagPart2LeftPlus = 0;
  }
  // счет левый-

  if (key_buff[5] == 0 && FlagPart2LeftMinus == 0)
  {
    lcd.clear();
    LeftPart2--;
    Menu_4_counter++;
    FlagPart2LeftMinus = 1 ;
  }

  if (key_buff[5] == 1 && FlagPart2LeftMinus == 1)
  {
    FlagPart2LeftMinus = 0;
  }

  //**********************************************************
  if (key_buff[1] == 0 && FlagPart2RightPlus == 0)
  {
    lcd.clear();
    RightPart2++;
    Menu_4_counter++;
    FlagPart2RightPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[1] == 1 && FlagPart2RightPlus == 1)
  {
    FlagPart2RightPlus = 0;
  }
  // счет левый-

  if (key_buff[2] == 0 && FlagPart2RightMinus == 0)
  {
    lcd.clear();
    RightPart2--;
    Menu_4_counter++;
    FlagPart2RightMinus = 1 ;
  }

  if (key_buff[2] == 1 && FlagPart2RightMinus == 1)
  {
    FlagPart2RightMinus = 0;
  }

  if (LeftPart2 < 10)
  {
    lcd.setCursor(2, 0);
    lcd.print (LeftPart2);
  }
  if (LeftPart2 >= 10)
  {
    lcd.setCursor(1, 0);
    lcd.print (LeftPart2);
  }

  lcd.setCursor(3, 0);
  lcd.print ("-\250APT\245\261"); //250 П \245 И \261 Я
  lcd.setCursor(10, 0);
  lcd.print ("2-");
  lcd.setCursor(12, 0);
  lcd.print (RightPart2);

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

  if (key_buff[4] == 0 && FlagPart3LeftPlus == 0)
  {
    lcd.clear();
    LeftPart3++;
    Menu_5_counter++;
    FlagPart3LeftPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[4] == 1 && FlagPart3LeftPlus == 1)
  {
    FlagPart3LeftPlus = 0;
  }
  // счет левый-

  if (key_buff[5] == 0 && FlagPart3LeftMinus == 0)
  {
    lcd.clear();
    LeftPart3--;
    Menu_5_counter++;
    FlagPart3LeftMinus = 1 ;
  }

  if (key_buff[5] == 1 && FlagPart3LeftMinus == 1)
  {
    FlagPart3LeftMinus = 0;
  }

  //**********************************************************
  if (key_buff[1] == 0 && FlagPart3RightPlus == 0)
  {
    lcd.clear();
    RightPart3++;
    Menu_5_counter++;
    FlagPart3RightPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[1] == 1 && FlagPart3RightPlus == 1)
  {
    FlagPart3RightPlus = 0;
  }
  // счет левый-

  if (key_buff[2] == 0 && FlagPart3RightMinus == 0)
  {
    lcd.clear();
    RightPart3--;
    Menu_5_counter++;
    FlagPart3RightMinus = 1 ;
  }

  if (key_buff[2] == 1 && FlagPart3RightMinus == 1)
  {
    FlagPart3RightMinus = 0;
  }

  if (LeftPart3 < 10)
  {
    lcd.setCursor(2, 0);
    lcd.print (LeftPart3);
  }
  if (LeftPart3 >= 10)
  {
    lcd.setCursor(1, 0);
    lcd.print (LeftPart3);
  }

  lcd.setCursor(3, 0);
  lcd.print ("-\250APT\245\261"); //250 П \245 И \261 Я
  lcd.setCursor(10, 0);
  lcd.print ("3-");
  lcd.setCursor(12, 0);
  lcd.print (RightPart3);

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
  if (key_buff[4] == 0 && FlagPart4LeftPlus == 0)
  {
    lcd.clear();
    LeftPart4++;
    Menu_6_counter++;
    FlagPart4LeftPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[4] == 1 && FlagPart4LeftPlus == 1)
  {
    FlagPart4LeftPlus = 0;
  }
  // счет левый-

  if (key_buff[5] == 0 && FlagPart4LeftMinus == 0)
  {
    lcd.clear();
    LeftPart4--;
    Menu_6_counter++;
    FlagPart4LeftMinus = 1 ;
  }

  if (key_buff[5] == 1 && FlagPart4LeftMinus == 1)
  {
    FlagPart4LeftMinus = 0;
  }

  //**********************************************************
  if (key_buff[1] == 0 && FlagPart4RightPlus == 0)
  {
    lcd.clear();
    RightPart4++;
    Menu_6_counter++;
    FlagPart2RightPlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[1] == 1 && FlagPart4RightPlus == 1)
  {
    FlagPart4RightPlus = 0;
  }
  // счет левый-


  if (key_buff[2] == 0 && FlagPart4RightMinus == 0)
  {
    lcd.clear();
    RightPart4--;
    Menu_6_counter++;
    FlagPart4RightMinus = 1 ;
  }

  if (key_buff[2] == 1 && FlagPart4RightMinus == 1)
  {
    FlagPart4RightMinus = 0;
  }

  if (LeftPart4 < 10)
  {
    lcd.setCursor(2, 0);
    lcd.print (LeftPart4);
  }
  if (LeftPart4 >= 10)
  {
    lcd.setCursor(1, 0);
    lcd.print (LeftPart4);
  }

  lcd.setCursor(3, 0);
  lcd.print ("-\250APT\245\261"); //250 П \245 И \261 Я
  lcd.setCursor(10, 0);
  lcd.print ("4-");
  lcd.setCursor(12, 0);
  lcd.print (RightPart4);

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

  if (key_buff[4] == 0 && FlagMinutePlus == 0)
  {
    delay(10);
    lcd.clear();
    Minute++;
    Menu_7_counter++;
    FlagMinutePlus = 1;  //это нужно для того что бы с каждым нажатием кнопки происходило только одно действие плюс защита от "дребезга"  100%
  }

  if (key_buff[4] == 1 && FlagMinutePlus == 1)
  {
    FlagMinutePlus = 0;
  }
  // счет левый-

  if (key_buff[5] == 0 && FlagMinuteMinus == 0)
  {
    delay(10);
    lcd.clear();
    Minute--;
    Menu_7_counter++;
    FlagMinuteMinus = 1 ;
  }

  if (key_buff[5] == 1 && FlagMinuteMinus == 1)
  {
    FlagMinuteMinus = 0;
  }



  lcd.setCursor(1, 0);
  lcd.print ("TA\246MEP-");

  if (Minute < 10)
  {
    lcd.setCursor(9, 0);
    lcd.print (Minute);
  } else  {
    lcd.setCursor(8, 0);
    lcd.print (Minute);
  }


  lcd.setCursor(10, 0);
  lcd.print (":");

  lcd.setCursor(11, 0);
  lcd.print (Sec);
  lcd.setCursor(12, 0);
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

