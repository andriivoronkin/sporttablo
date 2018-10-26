void SpiSend (uint8_t value)
{
  Serial.println("1 bite");
  int lastNumber = 0;
  int firstNumber = 0;
  int temporal = 0;
  int secondNumber = 0;

  for (int i = 0; i < 4; i++)
  {
    SPI.transfer(voidNumber);
    latch();
  }
  
  if (value < 10)
  {
    SPI.transfer(out_symbol[value]);
    latch();
  }

  if (value >= 10 && value < 100)
  {
    lastNumber = value%10;
    firstNumber = value/10;
    SPI.transfer (out_symbol[lastNumber]);
    latch();
    SPI.transfer (out_symbol[firstNumber]);
    latch();
  }
  
    if (value >= 100)
  {
    firstNumber = value/100;
    temporal = value%100;
    secondNumber = temporal/10;
    lastNumber = temporal%10;
    SPI.transfer (out_symbol[lastNumber]);
    latch();
    SPI.transfer (out_symbol[secondNumber]);
    latch();
    SPI.transfer (out_symbol[firstNumber]);
    latch();
    
  }
}

