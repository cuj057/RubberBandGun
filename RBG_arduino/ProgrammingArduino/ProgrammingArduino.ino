// Author: Mark Olson 2020-09-03

// Rubber Band Gun - https://github.com/Mark-MDO47/RubberBandGun
// RBG - A high-tech imagining of the rubber band gun

// The purpose of ProgrammingArduino.ino is to program the Bluetooth module to auto-connect
//     to a specific set of bluetooth speakers, headphones, etc.  Once this is done, the list will be retained
//     by the Bluetooth module and the Programming Arduino can be disconnected.
// NOTE: at the moment this is just a copy of BlueToothTesting.ino with different comments;
//       it is not yet ready for use.

// When running the sketch, you can select steps in any order as follows:
//     1. Scan for Bluetooth receiver devices (such as speaker, headphones, etc.)
//     2. Display stored auto-connect Bluetooth receiver devices
//     3. Add one auto-connect Bluetooth receiver devices to storage
//     4. Delete all auto-connect Bluetooth receiver devices from storage
// You can have up to 10 auto-connect Bluetooth receiver devices in storage
// The Bluetoth module will connect to the first device it finds in order
//
// To gather necessary information about your Bluetooth receiver device, select option 1
// To add a device to the auto-connect storage, select option 2 and enter the necessary information

//////////////////////////////////////////////////////////////////////////////////////
// To do this programming:
//   Connect Programming Arduino (see below)
//
//   On Rubber Band Gun (RBG)
//     Power on RBG
//   On separate programming Arduino (using +5V interfaces)
//     Connect programming Arduino to USB for PC running the Arduino software
//     Upload the sketch from this file into the programming Arduino
//     Open Serial Monitor by selecting menu "Tools" -> "Serial Monitor" and follow instructions
//        After each selected step, wait for the string "*** KCX_BT_EMITTER PROGRAMMING COMPLETE ***
//     Disconnect programming Arduino from USB for PC running the Arduino software
//
//   Disconnect Programming Arduino (see below)
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// To connect Programming Arduino
//   On Rubber Band Gun (RBG)
//     Power off RBG
//     Remove the clear cover on the handle of the RBG
//     Inside the handle, find the female jumper connectors for the KCX_BT_EMITTER chip (near front of handle)
//          label      color of wire
//          GND        BLACK
//          2 RX       GREEN
//          9 TX       YELLOW
//   On separate programming Arduino (using +5V interfaces)
//     Power off programming Arduino
//     Connect jumper wires with male ends as follows
//          Pin      color of wire
//          GND        BLACK
//          2 RX       GREEN  (Arduino TX)
//          9 TX       YELLOW (Arduino RX)
//     Connect the programming Arduino jumper wires to the RBG jumper wires using color as the guide.
//     Edit this sketch with MAC address(es) and name(s) of your Bluetooth speakers, headphones, etc.
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// To disconnect Programming Arduino
//   Ensure that programming Arduino is disconnected from USB for PC running the Arduino software
//   On Rubber Band Gun (RBG)
//     Power off RBG
//   On separate programming Arduino (using +5V interfaces)
//     Disconnect the programming Arduino jumper wires from the RBG jumper wires
//   On Rubber Band Gun (RBG)
//     Store the jumper connectors safely in the handle and attach the clear cover on the handle of the RBG
//////////////////////////////////////////////////////////////////////////////////////




#include "Arduino.h"
#include "SoftwareSerial.h"                  // to talk to KCX_BT_EMITTER without using up debug serial port

// NOTE that Serial.read() from Arduino serial monitor will have a 0x0A (newline) after the characters typed in
//    This must be removed before sending to the Bluetooth module - it would cause the command to be rejected

// The KCX_BT_EMITTER (and some information on it) can be found here
//     https://www.aliexpress.com/item/33058710334.html

// Here is a list of commands and the responses I have seen. This list is based on the following plus my experimentation
//     https://item.taobao.com/item.htm?spm=a21wu.12321156-tw.0.0.7e76d1c7xEOcFZ&id=570274835710
//     https://www.electro-tech-online.com/threads/kcx_bt_emitter-low-cost-bluetooth-bt-audio-module.158156/
// < 1>: Test Command
// Description: test communication is normal
//   AT+
//     OK+
// < 2>: system reset
// Description: RESET
//   AT+REST
//     OK+
//     REST
//     POWER ON
// < 3>: query software version
// Description: Check the software version; my devices show V1.1
//   AT+GMR
//     OK+
//     KCX_BTEMITTER_Vx.x
// < 4>: query connection status
// Description: search for Bluetooth connection status; x=0: no connection, x=1 connected
//   AT+STATUS
//     OK+
//     STATUS:x
// < 5>: specify MAC address connection
// Description: connect to the MAC address link (here shows the device connecting to the MAC-0xf44efdecd39d )
// NOTE: hex string must be EXACTLY 12 characters; add leading zeros if needed
//   AT+CONADD=0xf44efdecd39d
//     OK+
//     CON:0xf44efdecd39d
//     CONNECTED
// < 6>: disconnect
// Description: disconnect the current bluetooth connection
//   Send : AT+DISCON
//     OK+DISCON
//     DISCONNECT
// < 7>: Scan for any visible Bluetooth devices
// Description: search Bluetooth receive device, cycle search and list ? Blue tooth device information found
//   AT+SCAN
//     OK+SCAN
//     New Devices:1
//     MacAdd:0xf44efdecd39d
//     Name:Bluetooth Audio
//     ALL Devices=1
// < 8>: add the Bluetooth device MAC address to internal list of MAC addresses for auto-connection
// Description: with this command-set, a total of 10 MAC address records can be attached to 10 devices in a sequence.
// Set the memory. When the module is started , it will search the MAC address of the device and the MAC address of the recording area.
// The address is automatically connected to any one of the MAC addresses of the recording area, and is not connected when the address is not consistent, so as to achieve the specified MAC address connection.
// When 10 recording spaces are empty , MAC address filtering is not performed ( by default, this area is empty in the factory).
//   AT+ADDLINKADD=0xf44efdecd39d
//     OK+
//     ADDLINKADD
//     VM_MacAdd 1 =0xf44efdecd39d
// < 9>: associate the Bluetooth device name with internal list of MAC addresses for auto-connection
// Description: with this command setting, specifying the blue tooth name connection, a total of 10 blue tooth names can be added, and 10 devices can be recorded sequentially on the chip.
// Memory. When the module is started, it will search the blue tooth name of the device and the blue tooth name of the recording area.
// The blue tooth name is automatically associated with any of the blue tooth names in the recording area , and is not associated with any of the blue tooth names in the recording area , so as to achieve the specified blue tooth name connection function . When 10
// When all the recording spaces are empty , the blue tooth name is not filtered ( by default, this area is empty in the factory).
//   AT+ADDLINKNAME=S1 Pro MDO
//     OK+ADDLINKNAME
//     VM_Name 0 =S1 Pro MDO
// <10>: query the auto-connect memory area
// Description: sending this command returns all information recorded in the automatically reconnect MAC and device name memory.
//   AT+VMLINK?
//     OK+VMLINK
//     BT_ADD_NUM=1
//     BT_NAME_NUM=1
//     Last_Add=0xf44efdecd39d
//     VM_MacAdd0=0xf44efdecd39d
//     VM_Name0=S1 Pro MDO
// <11>: delete all records in the auto-connect memory
//   AT+DELVMLINK
//     Delete_Vmlink

#define DPIN_BLUESRL_RX   9  // serial in  - talk to Bluetooth module (KCX_BT_EMITTER) - connect to GREEN wire
#define DPIN_BLUESRL_TX   2  // serial out  - talk to Bluetooth module (KCX_BT_EMITTER) - connect to YELLOW wire

SoftwareSerial myBlueSerial(DPIN_BLUESRL_RX, DPIN_BLUESRL_TX); // to talk to Bluetooth 

#define NUMWAIT  3000 // loopcount waiting for response from Bluetooth module

#define NUMOF(a) (sizeof((a)) / sizeof(*(a)))

char inBytes[100];
char const * cmd_AT          = "AT+";
char const * cmd_REST        = "AT+REST";
char const * cmd_GMR         = "AT+GMR";
char const * cmd_STATUS      = "AT+STATUS";
char const * cmd_DISCON      = "AT+DISCON";
char const * cmd_SCAN        = "AT+SCAN";
char const * cmd_ADDLINKADD  = "AT+ADDLINKADD=0x"; // NOTE: must be exactly 12 characters for hex string
char const * cmd_ADDLINKNAME = "AT+ADDLINKNAME=";
char const * cmd_VMLINK      = "AT+VMLINK?";
char const * cmd_DELVMLINK   = "AT+DELVMLINK";

char const * cmdsScan[]     = {cmd_AT, cmd_SCAN};
char const * cmdsDispRAM[]  = {cmd_AT, cmd_VMLINK};
char const * cmdsAddRAM1[]  = {cmd_AT, cmd_DISCON, cmd_VMLINK};
char const * cmdsAddRAM2[]  = {cmd_ADDLINKADD, cmd_ADDLINKNAME}; // must build these in RAM
char const * cmdsAddRAM3[]  = {cmd_VMLINK};
char const * cmdsClearRAM[] = {cmd_AT, cmd_REST, cmd_DISCON, cmd_DELVMLINK, cmd_VMLINK};

unsigned int reportBlueCom();
void sendBlueCmd( char * cmd );
void processCommand(uint8_t theChoice);
uint8_t getSerial_uint8_t();

void setup() {

  Serial.begin(115200);         // this is for general debug
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println();
  Serial.println("Bluetooth testing init...\n");

  myBlueSerial.begin(9600); // this is control for Bluetooth module (KCX_BT_EMITTER)

}  // end setup()

void loop() {
  static uint8_t menuPrinted = 0;

  if (0 == menuPrinted) {
    menuPrinted = 1;
    Serial.println("");
    Serial.println("   1 - Scan for Bluetooth receiver devices (such as speaker, headphones, etc.)");
    Serial.println("   2 - Display stored auto-connect Bluetooth receiver devices");
    Serial.println("   3 - Add one auto-connect Bluetooth receiver device to storage");
    Serial.println("   4 - Delete all auto-connect Bluetooth receiver devices from storage");
    Serial.print("--> ");
  }

  if (Serial.available()) {
    uint8_t myChoice = 0;

    menuPrinted = 0;
    myChoice = getSerial_uint8_t();
    if ((0 == myChoice) || (myChoice > 4)) {
      Serial.println("ERROR - choice must be 1 through 4");
    } else {
      processCommand(myChoice);
    }
  }

  // testEcho();

} // end loop()

uint8_t getSerial_uint8_t() {
  getSerial_chars();
  return(uint8_t (inBytes[0]-'0'));
}

// no code to flag input over-run
// stores zero-terminated string in inBytes
uint8_t getSerial_chars() {
  static unsigned char mychar;
  static unsigned int idx = 0;
  static unsigned int odx = 0;

  while (Serial.available()) {
    mychar = Serial.read();
    if (((int) mychar) >= 0x20) { // if it is space or higher
      if (NUMOF(inBytes) <= (idx+2)) {
        inBytes[idx++] = mychar;
      }
      delay(5);
    } else {
      inBytes[idx++] = 0;
      delay(5);
      while (Serial.available()) {
        mychar = Serial.read();
        delay(5);
      }
      break;
    }
  } // end try to read input to the end of line

  return(idx);
}

void processCommand(uint8_t theChoice) {
  switch (theChoice) {
    case 1: // 1 - Scan for Bluetooth receiver devices (such as speaker, headphones, etc.)");
      testCmds(cmdsScan, (uint8_t) NUMOF(cmdsScan));
      break;
    case 2: // 2 - Display stored auto-connect Bluetooth receiver devices");
      testCmds(cmdsDispRAM, (uint8_t) NUMOF(cmdsDispRAM));
      break;
    case 3: // 3 - Add one auto-connect Bluetooth receiver device to storage");
      testCmds(cmdsAddRAM1, (uint8_t) NUMOF(cmdsAddRAM1));
      testCmds(cmdsAddRAM2, (uint8_t) NUMOF(cmdsAddRAM2)); FIXME - need to do this part
      testCmds(cmdsAddRAM3, (uint8_t) NUMOF(cmdsAddRAM3));
      break;
    case 4: // 4 - Delete all auto-connect Bluetooth receiver devices from storage");
      testCmds(cmdsClearRAM, (uint8_t) NUMOF(cmdsClearRAM));
      break;
  }
} // end processCommand()

void testEcho() {

  static char eolBytes[10];
  static unsigned char mychar;
  static unsigned int idx = 0;
  static unsigned int odx = 0;
  static unsigned int edx = 0;
  int loopIdx;

  while (Serial.available()) {
    mychar = Serial.read(); // this side is faster
    if (((int) mychar) >= 0x20) { // if it is space or higher
      inBytes[idx++] = mychar;
      delay(5);
    } else {
      eolBytes[edx++] = mychar;
      delay(5);
      while (Serial.available()) {
        mychar = Serial.read(); // this side is faster
        eolBytes[edx++] = mychar;
        delay(5);
      }
      break;
    }
  } // end try to read input to the end of line

  if (idx > 0) { // if anything to send to Bluetooth chip
    // display the input
    for (odx = 0; odx < idx; odx++) {
      Serial.print("char 0x");
      Serial.print((int) inBytes[odx], HEX);
      Serial.print(" ");
      Serial.println(inBytes[odx]);
      // printf("\neol char 0x%02X %c\n", (int) inBytes[odx], inBytes[odx]);
    }
    for (odx = 0; odx < edx; odx++) {
      Serial.print("\neol char 0x");
      Serial.println((int) eolBytes[odx], HEX);
      // printf("\neol char 0x%02X\n", (int) eolBytes[odx]);
    }
    // send input (without EOL) to Bluetooth module
    inBytes[idx] = 0;
    sendBlueCmd(inBytes);
    // Clean up
    idx = edx = 0;
  } else { // just display what there is if anything
    if (myBlueSerial.available()) {
      reportBlueCom();
    }
  }
  
} // end test1()

void testCmds(const char * cmdArray[], const uint8_t numCmds) {

  for (int cmdIdx = 0; cmdIdx < numCmds; cmdIdx += 1) {
    Serial.println("");
    Serial.print("--CMD ");
    Serial.print(cmdIdx);
    Serial.print(" ");
    Serial.println(cmdArray[cmdIdx]);
    sendBlueCmd((char *) cmdArray[cmdIdx]);
  }

  delay(100);

}

unsigned int reportBlueCom() {

  unsigned int idx = 0;
  unsigned int odx = 0;

  while (myBlueSerial.available()) {
    inBytes[idx++] = myBlueSerial.read();
  }
  if (idx > 0) {
    odx = 0;
    for (odx = 0; odx < idx; odx += 1) {
      Serial.print(inBytes[odx]);
    }
  } // if anything received from Bluetooth chip
  return(idx);
} // end reportBlueCom

void sendBlueCmd( char * cmd ) {
  int loopIdx;
  // Serial.println(cmd); // send this before sending to device
  myBlueSerial.print(cmd);
  for (loopIdx = 0; loopIdx < NUMWAIT; loopIdx += 1) {
    reportBlueCom();
    delay(5);
  }
} // end sendBlueCmd
