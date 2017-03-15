/* Wiring Guide */
//Serial MP3 Player A     |  Arduino UNO R3//
//              RX              |   2
//              TX              |   6
//              VCC            |   5V
//              GND            |   GND

/*
 * Burde sette opp mappe for:
 * startup 
 * coming
 * obstacle
 * table edge
 * im lost
 * random phrase
 * 
*/
static int8_t Send_buf[6] = {0} ;

const long interval = 5000;
unsigned long prevPlay = 0;

void playCommandRecieved()
{
    playFile(0X0001);
}

void playFreePassage()
{
  playFile(0X0001);
}

void playObstacleInFront()
{
  playFile(0X0002);
}

void playTableEdge()
{
    //Play correct file.
    //The question is whether we should use one play function with a paramater or not.
}

void playImLost() 
{
    //Play correct file
}

void playRandomPhrase()
{
    //Play correct file
}

void playFile(int16_t dat) //SKREVER AT EIRIK
{
  unsigned long currentPlay = millis();

  if (currentPlay - prevPlay >= interval || prevPlay <= 5000) 
  {
    prevPlay = currentPlay;
    mp3_6bytes(CMD_PLAY_W_INDEX, dat); 
  }
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
    return;
  else if(command < 0x10) 
  {
  mp3Basic(command);
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

void mp3Basic(int8_t command)
{
  Send_buf[0] = 0x7e; //starting byte
  Send_buf[1] = 0x02; //the number of bytes of the command without starting byte and ending byte
  Send_buf[2] = command; 
  Send_buf[3] = 0xef; //
  sendBytes(4);
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
    myMP3.write(Send_buf[i]) ;
  }
}


