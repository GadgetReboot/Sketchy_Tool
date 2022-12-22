/*
   Sketchy Tool - I2C interface to pass data to another project
                  for on the fly variable tweaking

   Hardware: ATTiny 1604
             I2C (bit banged) 128x64 OLED display
             Rotary Encoder with button for setting variable values
             I2C bus (hardware serial) to send variable data to target project

             Pinout
             OLED SCL = PA3  bit banged
             OLED SDA = PA2  bit banged
             Rotary Encoder Input A = PA4
             Rotary Encoder Input B = PA5
             Rotary Encoder Switch  = PA6
             External SCL = PB0
             External SDA = PB1

   Tested with Arduino IDE 1.8.13
               MegaTinyCore board file 2.5.10
               button debounce library https://github.com/e-tinkers/button
               rotary encoder library  https://github.com/mathertel/RotaryEncoder

   Gadget Reboot
   https://www.youtube.com/gadgetreboot

*/

// OLED and bit banged I2C bus controller
#include "Bb7654Oled.h"
#include "PixOled.h"
#include "TerOled.h"

// I2C hardware serial bus
#include <Wire.h>

// button debounce and rotary encoder interface
#include <button.h>
#include <RotaryEncoder.h>

const byte slaveAddr = 0x42;   // I2C address for slave (other project board to send data to)

// rotary encoder inputs
const byte encA  = 0;          // rotary encoder input A  PA4
const byte encB  = 1;          // rotary encoder input B  PA5
const byte encSW = 2;          // rotary encoder switch   PA6

// setup a RotaryEncoder for 4 steps with a latch on the input state 3
RotaryEncoder encoder(encA, encB, RotaryEncoder::LatchMode::FOUR3);

// debounce encoder switch
Button encSW_db;

void setup() {

  // init OLED with bit banged I2C
  SetupBb7654Oled();
  SetupPixOled();
  DoubleH();
  Clear();

  // print header text on OLED
  LiCol(0, 0); Text("Click to send data");

  // init hardware serial I2C communications as master
  Wire.begin();

  // configure encoder pins as inputs
  pinMode(encA, INPUT_PULLUP);
  pinMode(encB, INPUT_PULLUP);
  pinMode(encSW, INPUT_PULLUP);

  // debounce encoder switch
  encSW_db.begin(encSW);

}

void loop() {
  static byte tweakData = 0;                       // data to send over I2C
  static int encoderPos = 0;                       // track encoder position

  encoder.tick();                                  // perform encoder operations

  // check if encoder has moved
  int newEncoderPos = encoder.getPosition();
  if (encoderPos != newEncoderPos) {
    if ((int)(encoder.getDirection()) > 0) {       // encoder rotated clockwise
      if (tweakData < 255) {
        tweakData++;                               // increment tweak data
      }
    }
    else if ((int)(encoder.getDirection()) == 0) { // encoder rotated counter-clockwise
      if (tweakData > 0) {
        tweakData--;                               // decrement tweak data
      }
    }
    encoderPos = newEncoderPos;                    // update encoder position
  }

  LiCol(1, 0);                                     // print tweak data on OLED
  Dec8(tweakData);

  if (encSW_db.debounce()) {                       // send tweak data to I2C slave when button is pressed
    sendI2CData(tweakData);                        
    LiCol(2, 0);  Text("Last Sent:");
    Dec8(tweakData);
  }
}

// send data to I2C slave
void sendI2CData(byte value) {
  Wire.beginTransmission(slaveAddr);
  Wire.write(value);
  Wire.endTransmission();
}


// Reference examples for other OLED commands
//  LiCol(1,0);Bin8(36); Hex16(0x1234); Dec16(19999);
//  LiCol(2,0);Bin16(variableName);
//  LiCol(7,0);Text("done");
