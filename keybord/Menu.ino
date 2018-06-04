void Menu ()
{
  if (KeyMenuBuf[4] == 0 && FlagMenu == 1)
  {
    delay(10);
    MenuCounter++;
    FlagMenu = 0;
    lcd.clear();
    //        if (score1 < 9)
    //        {
    //        delay (30);
    //        lcd.setCursor(0, 0);
    //        lcd.print (0);
    //        lcd.setCursor(1, 0);
    //        lcd. print (score1);
    //        }
    //        if (score1 >9)
    //        {
    //        lcd.setCursor (0, 0);
    //        lcd.print (score1);
    //        }
  }
  if (KeyMenuBuf[4] == 1 && FlagMenu == 0)
  {
    FlagMenu = 1;

  }

  switch (MenuCounter)
  {
    case 0:
      MainMenu();
      break;

    case 1:
      delay(20);

      Menu_1();

      break;

    case 2:
      delay(20);

      if (Menu_1_counter > 0)
      {
        MenuCounter = 0;
        lcd.clear();
        Menu_1_counter = 0;
        break;
      }

      Menu_2();
      break;

    case 3:
      delay(20);

      if (Menu_2_counter > 0)
      {
        MenuCounter = 0;
        lcd.clear();
        Menu_2_counter = 0;
        break;
      }

      Menu_3();
      break;

    case 4:
      delay(20);

      if (Menu_3_counter > 0)
      {
        MenuCounter = 0;
        lcd.clear();
        Menu_3_counter = 0;
        break;
      }

      Menu_4();
      break;

    case 5:
      delay(20);

      if (Menu_4_counter > 0)
      {
        MenuCounter = 0;
        lcd.clear();
        Menu_4_counter = 0;
        break;
      }

      Menu_5();
      break;

    case 6:
      delay(20);

      if (Menu_5_counter > 0)
      {
        MenuCounter = 0;
        lcd.clear();
        Menu_5_counter = 0;
        break;
      }
      Menu_6();
      break;

    case 7:
      delay(20);

      if (Menu_6_counter > 0)
      {
        MenuCounter = 0;
        lcd.clear();
        Menu_6_counter = 0;
        break;
      }
      Menu_7();
      break;

    case 8:

      lcd.setCursor(0, 0);
      lcd.print (data);

      lcd.setCursor(9, 1);
      lcd.print (sizee);
      break;

    default:

      MenuCounter = 0;

  }
}

