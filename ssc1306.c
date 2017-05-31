

// Commands
#define SSD1306_SETCONTRAST               0x81
#define SSD1306_DISPLAYALLON_RESUME       0xA4
#define SSD1306_DISPLAYALLON              0xA5
#define SSD1306_NORMALDISPLAY             0xA6
#define SSD1306_INVERTDISPLAY             0xA7
#define SSD1306_DISPLAYOFF                0xAE
#define SSD1306_DISPLAYON                 0xAF
#define SSD1306_SETDISPLAYOFFSET          0xD3
#define SSD1306_SETCOMPINS                0xDA
#define SSD1306_SETVCOMDETECT             0xDB
#define SSD1306_SETDISPLAYCLOCKDIV        0xD5
#define SSD1306_SETPRECHARGE              0xD9
#define SSD1306_SETMULTIPLEX              0xA8
#define SSD1306_SETLOWCOLUMN              0x00
#define SSD1306_SETHIGHCOLUMN             0x10
#define SSD1306_SETSTARTLINE              0x40
#define SSD1306_MEMORYMODE                0x20
#define SSD1306_COMSCANINC                0xC0
#define SSD1306_COMSCANDEC                0xC8
#define SSD1306_SEGREMAP                  0xA0
#define SSD1306_CHARGEPUMP                0x8D
#define SSD1306_EXTERNALVCC               0x1
#define SSD1306_INTERNALVCC               0x2
#define SSD1306_SWITCHCAPVCC              0x2
ssc1306_init(){
  // Init sequence taken from datasheet for UG-2864HSWEG01 (128x64 OLED module)
      ssd1306SendCommand(SSD1306_DISPLAYOFF);                // 0xAE
      ssd1306SendCommand(SSD1306_SETDISPLAYCLOCKDIV);        // 0xD5
      ssd1306SendCommand(0x80);                              // 0x80 the suggested ratio
      ssd1306SendCommand(SSD1306_SETMULTIPLEX);              // 0xA8
      ssd1306SendCommand(0x3F);                              // 0x3F   63
      ssd1306SendCommand(SSD1306_SETDISPLAYOFFSET);          // 0xD3
      ssd1306SendCommand(0x0);                               // 0x00  no offset
      ssd1306SendCommand(SSD1306_SETSTARTLINE | 0x0);        // 0x40 line #0
      ssd1306SendCommand(SSD1306_CHARGEPUMP);                // 0x8D
      if (vccstate == SSD1306_EXTERNALVCC) 
        { ssd1306SendCommand(0x10); }
      else 
        { ssd1306SendCommand(0x14); }                        // 0x14
      ssd1306SendCommand(SSD1306_MEMORYMODE);                // 0x20
      ssd1306SendCommand(0x00);                              // 0x0 act like ks0108
      ssd1306SendCommand(SSD1306_SEGREMAP | 0x1);            // 0xA1
      ssd1306SendCommand(SSD1306_COMSCANDEC);                // 0xC8
      ssd1306SendCommand(SSD1306_SETCOMPINS);                // 0xDA
      ssd1306SendCommand(0x12);                              // 0x12
      ssd1306SendCommand(SSD1306_SETCONTRAST);               // 0x81
      if (vccstate == SSD1306_EXTERNALVCC) 
        { ssd1306SendCommand(0x9F); }
      else 
        { ssd1306SendCommand(0xCF); }                        // 0xCF
      ssd1306SendCommand(SSD1306_SETPRECHARGE);              // 0xD9
      if (vccstate == SSD1306_EXTERNALVCC) 
        { ssd1306SendCommand(0x22); }
      else 
        { ssd1306SendCommand(0xF1); }                        // 0xF1
      ssd1306SendCommand(SSD1306_SETVCOMDETECT);             // 0xDB
      ssd1306SendCommand(0x40);                              // 0x40
      ssd1306SendCommand(SSD1306_DISPLAYALLON_RESUME);       // 0xA4
      ssd1306SendCommand(SSD1306_NORMALDISPLAY);             // 0xA6
      ssd1306SendCommand(SSD1306_DISPLAYON);                 // 0xAF
}
