/* Wiring Guide */
//Serial MP3 Player A     |  Arduino UNO R3//
//              RX              |   6
//              TX              |   2
//              VCC            |   5V
//              GND            |   GND

int amountStart = 2;
int amountComing = 2;
int amountObstacle = 2;
int amountTableEdge = 2;
int amountImLost = 2;
int amountRandomPhrase = 1;
int amountDelivery = 2;

static int8_t Send_buf[6] = {0} ;

const long interval = 5000;
unsigned long prevPlay = 0;

int16_t getRandom(int amount)
{
    randomSeed(analogRead(0));
    return byte(random(1,amount+1));
}

boolean checkIfPlay()
{
    delay(100);
    unsigned long currentPlay = millis();
    
    if (currentPlay - prevPlay >= interval || prevPlay <= 5000) 
    {
        prevPlay = currentPlay;
        return true;
    }
    return false;
}

void playStart()
{
    if(checkIfPlay())
    {
        playFolderFile(0x0100 + getRandom(amountStart));
    }
}
void playCommandRecieved()
{
    if(checkIfPlay())
    {
        playFolderFile(0x0200 + getRandom(amountComing));
    }
}

void playObstacleInFront()
{
    if(checkIfPlay())
    {
        playFolderFile(0x0300 + getRandom(amountObstacle));
    }
}

void playTableEdge()
{
    if(checkIfPlay())
    {
        playFolderFile(0X0400 + getRandom(amountTableEdge));
    }
}

void playImLost() 
{
    if(checkIfPlay())
    {
        playFolderFile(0X0500 + getRandom(amountImLost));
    }
}

void playRandomPhrase()
{
    if(checkIfPlay())
    {
        playFolderFile(0X0600 + getRandom(amountRandomPhrase));
    }
}

void playDelivery() 
{
    if(checkIfPlay())
    {
        playFolderFile(0X0700 + getRandom(amountDelivery));
    }
}

void playSound(int16_t dat)
{
    mp3_6bytes(CMD_PLAY_W_INDEX, dat); 

}

void setVolume(int8_t vol)
{
  mp3_5bytes(CMD_SET_VOLUME, vol);
}

void playFolderFile(int16_t dat) //SKREVER AT EIRIK
{
  mp3_6bytes(CMD_PLAY_FILE_NAME, dat);
}

void sendCommand(int8_t command, int16_t dat = 0)
{
  delay(20);
  if((command == CMD_PLAY_W_VOL)||(command == CMD_SET_PLAY_MODE))
  {
    return; 
  }
  else if(command < 0x40)
  { 
    mp3_5bytes(command, dat);
  }
  else if(command < 0x50)
  { 
    mp3_6bytes(command, dat);
  }
  else return;
 
}

void mp3_5bytes(int8_t command, uint8_t dat)
{
  Send_buf[0] = 0x7e; //starting byte
  Send_buf[1] = 0x03; //the number of bytes of the command without starting byte and ending byte
  Send_buf[2] = command; 
  Send_buf[3] = dat; //
  Send_buf[4] = 0xef; //
  sendBytes(5);
}

void mp3_6bytes(int8_t command, int16_t dat)    
{
  Send_buf[0] = 0x7e; //starting byte
  Send_buf[1] = 0x04; //the number of bytes of the command without starting byte and ending byte
  Send_buf[2] = command; 
  Send_buf[3] = (int8_t)(dat >> 8);//datah
  Send_buf[4] = (int8_t)(dat); //datal
  Send_buf[5] = 0xef; //
  sendBytes(6);
}

void sendBytes(uint8_t nbytes)
{
  for(uint8_t i=0; i < nbytes; i++)//
  {
    myMP3.write(Send_buf[i]);
  }
}


