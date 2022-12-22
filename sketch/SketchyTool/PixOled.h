//PixOled.h //  190316  Nouv référence 
//dans pp #include "PixOled.h"    SetupPixOled();
// Gencar, text et dot
// NumOled pour OledPix fonctions  Dec9999 BigDec
// Ping.h pour fonctions raq et ball

//  dans pp #include "OledPix.h"   SetupOledPix();
//===============
#include <avr/pgmspace.h>
const uint8_t taNum[] PROGMEM = {
  0x00,0x00,0x00,0x00, 0x00,0xc0,0xde,0x00, // space ! 
  0x03,0x00,0x03,0x00, 0x74,0x2f,0x74,0x2f, // " #
  0x2c,0x49,0xff,0x39, 0x43,0x33,0x6c,0x63, // $ %
  0x6e,0x59,0x19,0x26, 0x00,0x05,0x03,0x00, // & '
  0x1c,0x22,0x41,0x00, 0x00,0x41,0x22,0x1c, // ( )
  0x2a,0x1c,0x1c,0x2a, 0x08,0x3e,0x08,0x08, // * +
  0x00,0xa0,0x60,0x00, 0x08,0x08,0x08,0x08, // , -
  0x00,0xc0,0xc0,0x00, 0x03,0x0c,0x30,0xc0, // . / 
  0x3e,0x41,0x41,0x3e, 0x04,0x02,0x7f,0x00, // 0 1
  0x62,0x51,0x49,0x46, 0x22,0x41,0x49,0x36, // 2 3
  0x1c,0x12,0x79,0x10, 0x2f,0x49,0x49,0x31, // 4 5
  0x36,0x49,0x49,0x31, 0x41,0x31,0x0d,0x03, // 6 7
  0x36,0x49,0x49,0x36, 0x46,0x49,0x49,0x3e, // 8 9
  0x00,0x36,0x36,0x00, 0x00,0xd6,0x76,0x00, // : ;
  0x08,0x14,0x22,0x41, 0x24,0x24,0x24,0x24, // < = 
  0x41,0x22,0x14,0x08, 0x02,0xc1,0xd9,0x06}; // > ?
const uint8_t taMaj[] PROGMEM = {
  0x39,0x48,0x71,0x41,0x3e, 0x7e,0x11,0x11,0x11,0x7e, // @ A   
  0x7f,0x49,0x49,0x49,0x36, 0x3e,0x41,0x41,0x41,0x22, // B C
  0x7f,0x41,0x41,0x41,0x3e, 0x7f,0x49,0x49,0x41,0x41, // D,E
  0x7f,0x09,0x09,0x01,0x01, // F
  0x3e,0x41,0x49,0x49,0x3a, 0x7f,0x08,0x08,0x08,0x7f, // G,H
  0x00,0x00,0x7f,0x00,0x00, 0x21,0x41,0x41,0x41,0x3f, // I,J
  0x7f,0x08,0x14,0x22,0x41, 0x7f,0x40,0x40,0x40,0x40, // K,L
  0x7f,0x02,0x04,0x02,0x7f, 0x7f,0x04,0x08,0x10,0x7f, // M,N
  0x3e,0x41,0x41,0x41,0x3e, 0x7f,0x11,0x11,0x11,0x0e, // O,P
  0x3e,0x41,0x49,0x51,0x7e, 0x7f,0x09,0x11,0x29,0x46, // Q,R
  0x46,0x49,0x49,0x49,0x32, 0x01,0x01,0x7f,0x01,0x01, // S,T
  0x3f,0x40,0x40,0x40,0x3f, 0x07,0x18,0x60,0x18,0x07, // U,V
  0x1f,0x60,0x1e,0x60,0x1f, 0x63,0x14,0x08,0x14,0x63, // W,X
  0x07,0x04,0x78,0x04,0x07, 0x61,0x51,0x49,0x45,0x43, // Y,Z
  0x00,0x7f,0x41,0x41,0x00, 0x03,0x06,0x1c,0x30,0x60, /* [ \ */
  0x00,0x41,0x41,0x7f,0x00, 0x04,0x02,0x01,0x02,0x04, // ] ^
  0x80,0x80,0x80,0x80,0x80}; // _
  
const uint8_t taMin [] PROGMEM = {
  0x00,0x03,0x06,0x00, 0x20,0x54,0x54,0x78, // ` a 0x38,0x44,0x44,0x7C,
  0x7f,0x44,0x44,0x38, 0x38,0x44,0x44,0x28, // b c
  0x38,0x44,0x44,0x7f, 0x38,0x54,0x54,0x58, // d e
  0x00,0xfe,0x09,0x08, 0x98,0xa4,0xa4,0x78, // f g
  0x7f,0x04,0x04,0x78, 0x00,0x7d,0x00,0x00, // h i
  0x40,0x80,0x80,0x7d, 0x7e,0x10,0x28,0x44, // j k
  0x00,0x3f,0x40,0x00, 0x7c,0x08,0x08,0x7c, // l m
  0x7c,0x04,0x04,0x78, 0x38,0x44,0x44,0x38, // n o
  0xfc,0x24,0x24,0x18, 0x38,0x44,0x44,0xf8, // p q
  0x7c,0x04,0x04,0x08, 0x48,0x54,0x54,0x24, // r s
  0x00,0x3f,0x44,0x04, 0x3c,0x40,0x40,0x7c, // t u
  0x1c,0x60,0x60,0x1c, 0x5c,0x20,0x20,0x5c, // v w
  0x64,0x18,0x18,0x64, 0x04,0x08,0x78,0x04, // x y
  0x64,0x54,0x4C,0x44, 0x08,0x08,0x36,0x41, // z {
  0x00,0x00,0xff,0x00, 0x41,0x36,0x08,0x08, // | }
  0x10,0x20,0x10,0x20, 0xff,0xff,0xff,0xff}; // ~ del
const uint8_t squar[] PROGMEM ={0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff};
const uint8_t smile[] PROGMEM = {0x3c,0x42,0x95,0xa5,0xa1,0xa1, 0xa5,0x95,0x42,0x3c};
const uint8_t sad  [] PROGMEM = {0x3c,0x42,0xc5,0xa5,0xa1,0xa1, 0xa5,0xc5,0x42,0x3c};
const uint8_t didel[] PROGMEM = {0x82,0xf2,0xfe,0xfe,0x8e,0x82,0xc2,0x3c,0x00, \
                              0xc0,0xf8,0xfd,0x3d,0x0d,0x00, \
                              0x82,0xf2,0xfe,0xfe,0x8e,0x82,0xc2,0x3c,0x00, \
                              0xc0,0xf8,0xfe,0xfe,0x96,0x92,0x82,0x02,0x00, \
                              0xc0,0xf8,0xfe,0xfe,0x86,0x80,0x80,0x80,0x80 };

//xxxxxxxxxxxxxxxxxxxxxx

// Initialisation et fonctions de base
void  Clear();
byte taInitOled[]={ 0xae, 0xd5, 0x80, 0xa8, 63, \
        0xD3, 0x0, 0x40, 0x8d, 0x14, 0x20, 0x00, 0xa1, \
        0xc8, 0xDA, 0x12, 0x81, 0xcf, 0xd9, 0xf1, 0xdb, \
        0x40, 0xa4, 0xa6, 0x2e, 0xaf };
void  WrStaData () {  
  Start(); Write (Adr); Write(0x40);
}
void  SetupPixOled () { 
  for (byte i=0; i<sizeof (taInitOled); i++) { 
    Start(); Write (Adr); Write(0);
    Write (taInitOled[i]); Stop();
    WrStaData(); Stop();     
  }
  Clear();
}

void  WrStaCom () {  
  Start(); Write (Adr); Write(0);
}
void  Cmd (byte cc) {  
  WrStaCom (); Write (cc); Stop();
}
byte taIniTr[]={Adr,0,0x21,0x0,0x7f,0x22,0x0,0x7F};
void  IniTransfert () {  
  for (byte i=0; i<sizeof (taIniTr); i++) { 
    WrStaCom ();
    Write (taIniTr[i]); Stop();
  } 
}
byte saveLi,saveCol;
void  SetLine (int8_t cc) { 
  saveLi=cc;
  cc--; if(cc<0) {cc=7;} 
  WrStaCom (); Write (0x22);
  Write (cc); Write (7); Stop();
}
void  SetCol (byte cc) {  
  WrStaCom (); Write (0x21);
  Write (cc); Write (127); Stop();
  saveCol=cc;
}
void  LiCol (byte li,byte co) { 
  SetLine (li); SetCol (co);
//  ptMap = (128*saveLi)+saveCol;
}
void  Clear() {  //nn<128x8=1024
    IniTransfert();
    WrStaData(); 
    for (int i=0; i<1024; i++) {  Write (0); }
    Stop();
}
#define  Sprite(tt) \
  WrStaData(); \
  for (byte i=0; i<sizeof tt; i++) { \
  Write (pgm_read_byte(&tt[i])); } Stop()
#define MySprite(tt) \
  WrStaData(); \
  for (byte i=0; i<sizeof tt; i++) { \
  Write (tt[i]); } Write(0); Stop();
   
//xxxxxxxxxxxxxxxxxxxxxxxxxx

void DoubleH () {Cmd (0xda);Cmd (0x02);}
void SimpleH () {Cmd (0xda);Cmd (0x12);}

void Car(char cc) {
  cc&=0x7F; 
  switch (cc/32) {
    case 0:
    //   if(cc=13) {SetLine(saveLi+1);SetCol(0);} // saut de ligne
	   //else Error();
       break;
    case 1:  // codes 32-
      Start(); Write (Adr); Write (0x40);
      for (byte i=0; i<4; i++)
      { Write (pgm_read_byte(&taNum[((cc-32)*4)+i])); }
      Write (0); Stop(); 
          break;
     case 2:  // codes 64-
      Start(); Write (Adr); Write (0x40);
      for (byte i=0; i<5; i++)
      { Write (pgm_read_byte(&taMaj[((cc-64)*5)+i])); }
      Write (0); Stop();
          break;
    case 3:  //codes 96-
      Start(); Write (Adr); Write (0x40);
      for (byte i=0; i<4; i++)
      { Write (pgm_read_byte(&taMin[((cc-96)*4)+i])); }
      Write (0); Stop();
          break;
  }  // end switch
}
void Text(const char str[]) {
   for (byte i=0; i< strlen(str); i++) {
      Car(str[i]);
   }
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//\prog: "OledGraPix.h" 170426
void Dot(byte xx,byte yy) {  // yy 0-64 --> 0-7
      LiCol(yy/8,xx);
      WrStaData (); Write (1<<yy%8); Stop();
}
//ddot  2points superposés si (yy/8!=7)
// si =7 il faut agit sur le bit0 de la ligne suiv si !=7
void DDot(byte xx,byte yy) {  // yy0-64 --> 0-7
 byte tmp=(1<<yy%8);
 if (yy%8!=7) tmp+=(1<<(yy%8+1));
       LiCol(yy/8,xx);
      WrStaData (); Write (tmp); Stop();
}

void Hline (byte yy) {
  for (byte i=0; i<128; i++) { Dot(i,yy); }
}
void Vline (byte xx) {
  for (byte i=0; i<8; i++) { 
    LiCol (i,xx); 
    WrStaData (); Write (0xFF); Stop();
  } 
}  
#define vLine Vline
#define hLine Hline

