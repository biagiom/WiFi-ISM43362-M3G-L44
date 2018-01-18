/**
  ******************************************************************************
  * @file    WiFiST.h
  * @author  Wi6labs
  * @brief   WiFi API header.
  ******************************************************************************
--------------------------------------------------------------------------

              j]_                   .___
._________    ]0Mm                .=]MM]=
M]MM]MM]M]1  jMM]P               d]-' NM]i
-~-~   4MM1  d]M]1              d]'   jM]'
       j]MT .]M]01       d],  .M]'    d]#
       d]M1 jM4M]1  .,  d]MM  d]I    .]M'
       ]0]  M/j]0(  d]L NM]f d]P     jM-
       M]M .]I]0M  _]MMi -' .]M'
       M]0 jM MM]  jM-M>   .]M/
       ]0F MT ]M]  M>      d]M1        .,
      j0MT.]' M]M j]1 .mm .]MM ._d]_,   J,
      jM]1jM  ]01 =] .]M/ jM]Fd]M]MM]   .'
      j]M1#T .M]1.]1 jM]' M]0M/^ "M]MT  j         .",    .__,  _,-_
      jMM\]' J]01jM  M]M .]0]P    ]0]1  i         1 1   .'  j .'  "1
      j]MJ]  jM]1]P .]M1 jMMP     MM]1  I        J  t   1   j J    '
      =M]dT  jM]q0' dM]  M]MT     ]MM  j        j   j  j    J 1
      ]M]M`  j]0j#  ]MF  ]M]'    .M]P  J       .'   j  J  .J  4_,
      M]0M   =MM]1 .M]'  MM]     jM](  1       r    j  1  --,   "!
      ]0MT   ]M]M  jM@   ]M]     M]P  j       J     j j     4     1
      MM]'   M]0P  j]1  .M]M    j]M'  J      j'     ",?     j     1
     _]M]    M]0`  jM1 .MNMM,  .]M'   1     .'       11     1    j'
     jM]1   jM]@   j]L_]'?M]M__MP'    \     J        1G    J    .'
     j]0(   jM]1   "M]P'  "N]M/-      "L__J L________'?L__- *__,'
     "-'    "--

----------------------------------------------------------------------------

Copyright (c) <2017>, <Wi6labs>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the wi6labs nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL WI6LABS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


-----------------------------------------------------------------------------*/
#ifndef WiFiST_H
#define WiFiST_H

#include "wifi_drv.h"
#include "spi_drv.h"
#include "IPAddress.h"
#include "wl_definitions.h"
#include "WiFiClientST.h"

class WiFiClass {

private:
uint8_t wifi_status;
void init();

public:

  // WiFi device with SPI
  WiFiClass(SPIClass *SPIx, uint8_t cs, uint8_t spiIRQ, uint8_t reset, uint8_t wakeup);
  // WiFi device with UART
  WiFiClass(HardwareSerial *UARTx, uint8_t reset, uint8_t wakeup);
  // WiFi device with USB
  WiFiClass(uint8_t tx, uint8_t rx, uint8_t reset, uint8_t wakeup);

  int begin(char* ssid);
  int begin(char* ssid, uint8_t key_idx, const char* key);
  int begin(char* ssid, const char *passphrase);
  void disconnect(void);
  uint8_t status();
  char* firmwareVersion();
  IPAddress localIP();
  uint8_t* macAddress(uint8_t* mac);
  IPAddress subnetMask();
  IPAddress gatewayIP();
  char* SSID();
  char*	SSID(uint8_t networkItem);
  uint8_t* BSSID(uint8_t* bssid);
  int32_t RSSI();
  int32_t RSSI(uint8_t networkItem);
  uint8_t encryptionType();
  uint8_t	encryptionType(uint8_t networkItem);
  void setMac(uint8_t* macAddress);
  int8_t scanNetworks();
  static uint8_t getSocket();
  int hostByName(const char* aHostname, IPAddress aResult);
};

extern WiFiDrvClass *DrvWiFi;

#endif //WiFiST_H

/******************* (C) COPYRIGHT 2017 Wi6labs ***********END OF FILE********/
