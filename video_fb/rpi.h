/*

Raspbery Pi BUS addreses and offsets
====================================

Ported from: https://github.com/PeterLemon/RaspberryPi/blob/master/HelloWorld/DMA/LIB/R_PI.INC
Thanks to Peter Lemon!

License (BSD-2)
===============

Copyright (c) 2013, Gusts 'gusC' Kaksis <gusts.kaksis@gmail.com>
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

  Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef __rpi_h
#define __rpi_h

// Bus Address
#define PERIPHERAL_BASE                 0x20000000 // Peripheral Base Address
#define BUS_ADDRESSES_l2CACHE_ENABLED   0x40000000 // Bus Addresses: disable_l2cache=0
#define BUS_ADDRESSES_l2CACHE_DISABLED  0xC0000000 // Bus Addresses: disable_l2cache=1

// Mailbox
#define MAIL_BASE    0xB880 // Mailbox Base Address
#define MAIL_READ       0x0 // Mailbox Read Register
#define MAIL_CONFIG    0x1C // Mailbox Config Register
#define MAIL_STATUS    0x18 // Mailbox Status Register
#define MAIL_WRITE     0x20 // Mailbox Write Register

#define MAIL_EMPTY  0x40000000 // Mailbox Status Register: Mailbox Empty (There is nothing to read from the Mailbox)
#define MAIL_FULL   0x80000000 // Mailbox Status Register: Mailbox Full  (There is no space to write into the Mailbox)

#define MAIL_POWER    0x0 // Mailbox Channel 0: Power Management Interface
#define MAIL_FB       0x1 // Mailbox Channel 1: Frame Buffer
#define MAIL_VUART    0x2 // Mailbox Channel 2: Virtual UART 
#define MAIL_VCHIQ    0x3 // Mailbox Channel 3: VCHIQ Interface
#define MAIL_LEDS     0x4 // Mailbox Channel 4: LEDs Interface
#define MAIL_BUTTONS  0x5 // Mailbox Channel 5: Buttons Interface
#define MAIL_TOUCH    0x6 // Mailbox Channel 6: Touchscreen Interface
#define MAIL_COUNT    0x7 // Mailbox Channel 7: Counter
#define MAIL_TAGS_OUT 0x8 // Mailbox Channel 8: Tags (ARM to VC)
#define MAIL_TAGS_IN  0x9 // Mailbox Channel 9: Tags (VC to ARM)

// Tags (ARM to VC)
#define Get_Firmware_Revision  0x00000001 // VideoCore: Get Firmware Revision (Response: Firmware Revision)
#define Get_Board_Model        0x00010001 // Hardware: Get Board Model (Response: Board Model)
#define Get_Board_Revision     0x00010002 // Hardware: Get Board Revision (Response: Board Revision)
#define Get_Board_MAC_Address  0x00010003 // Hardware: Get Board MAC Address (Response: MAC Address In Network Byte Order)
#define Get_Board_Serial       0x00010004 // Hardware: Get Board Serial (Response: Board Serial)
#define Get_ARM_Memory         0x00010005 // Hardware: Get ARM Memory (Response: Base Address In Bytes, Size In Bytes)
#define Get_VC_Memory          0x00010006 // Hardware: Get VC Memory (Response: Base Address In Bytes, Size In Bytes)
#define Get_Clocks             0x00010007 // Hardware: Get Clocks (Response: Parent Clock ID (0 For A Root Clock), Clock ID)
#define Get_Power_State        0x00020001 // Power: Get Power State (Response: Device ID, State)
#define Get_Timing             0x00020002 // Power: Get Timing (Response: Device ID, Enable Wait Time In Microseconds)
#define Set_Power_State        0x00028001 // Power: Set Power State (Response: Device ID, State)
#define Get_Clock_State        0x00030001 // Clocks: Get Clock State (Response: Clock ID, State)
#define Get_Clock_Rate         0x00030002 // Clocks: Get Clock Rate (Response: Clock ID, Rate In Hz)
#define Get_Voltage            0x00030003 // Voltage: Get Voltage (Response: Voltage ID, Value Offset From 1.2V In Units Of 0.025V)
#define Get_Max_Clock_Rate     0x00030004 // Clocks: Get Max Clock Rate (Response: Clock ID, Rate In Hz)
#define Get_Max_Voltage        0x00030005 // Voltage: Get Max Voltage (Response: Voltage ID, Value Offset From 1.2V In Units Of 0.025V)
#define Get_Temperature        0x00030006 // Voltage: Get Temperature (Response: Temperature ID, Value In Degrees C)
#define Get_Min_Clock_Rate     0x00030007 // Clocks: Get Min Clock Rate (Response: Clock ID, Rate In Hz)
#define Get_Min_Voltage        0x00030008 // Voltage: Get Min Voltage (Response: Voltage ID, Value Offset From 1.2V In Units Of 0.025V)
#define Get_Turbo              0x00030009 // Clocks: Get Turbo (Response: ID, Level)
#define Get_Max_Temperature    0x0003000A // Voltage: Get Max Temperature (Response: Temperature ID, Value In Degrees C)
#define Allocate_Memory        0x0003000C // Memory: Allocates Contiguous Memory On The GPU (Response: Handle)
#define Lock_Memory            0x0003000D // Memory: Lock Buffer In Place, And Return A Bus Address (Response: Bus Address)
#define Unlock_Memory          0x0003000E // Memory: Unlock Buffer (Response: Status)
#define Release_Memory         0x0003000F // Memory: Free The Memory Buffer (Response: Status)
#define Execute_Code           0x00030010 // Memory: Calls The Function At Given (Bus) Address And With Arguments Given
#define Get_EDID_Block         0x00030020 // HDMI: Read Specificed EDID Block From Attached HDMI/DVI Device (Response: Block Number, Status, EDID Block (128 Bytes))
#define Set_Clock_State        0x00038001 // Clocks: Set Clock State (Response: Clock ID, State)
#define Set_Clock_Rate         0x00038002 // Clocks: Set Clock Rate (Response: Clock ID, Rate In Hz)
#define Set_Voltage            0x00038003 // Voltage: Set Voltage (Response: Voltage ID, Value Offset From 1.2V In Units Of 0.025V)
#define Set_Turbo              0x00038009 // Clocks: Set Turbo (Response: ID, Level)
#define Allocate_Buffer        0x00040001 // Frame Buffer: Allocate Buffer (Response: Frame Buffer Base Address In Bytes, Frame Buffer Size In Bytes)
#define Blank_Screen           0x00040002 // Frame Buffer: Blank Screen (Response: State)
#define Get_Physical_Display   0x00040003 // Frame Buffer: Get Physical (Display) Width/Height (Response: Width In Pixels, Height In Pixels)
#define Get_Virtual_Buffer     0x00040004 // Frame Buffer: Get Virtual (Buffer) Width/Height (Response: Width In Pixels, Height In Pixels)
#define Get_Depth              0x00040005 // Frame Buffer: Get Depth (Response: Bits Per Pixel)
#define Get_Pixel_Order        0x00040006 // Frame Buffer: Get Pixel Order (Response: State)
#define Get_Alpha_Mode         0x00040007 // Frame Buffer: Get Alpha Mode (Response: State)
#define Get_Pitch              0x00040008 // Frame Buffer: Get Pitch (Response: Bytes Per Line)
#define Get_Virtual_Offset     0x00040009 // Frame Buffer: Get Virtual Offset (Response: X In Pixels, Y In Pixels)
#define Get_Overscan           0x0004000A // Frame Buffer: Get Overscan (Response: Top In Pixels, Bottom In Pixels, Left In Pixels, Right In Pixels)
#define Get_Palette            0x0004000B // Frame Buffer: Get Palette (Response: RGBA Palette Values (Index 0 To 255))
#define Test_Physical_Display  0x00044003 // Frame Buffer: Test Physical (Display) Width/Height (Response: Width In Pixels, Height In Pixels)
#define Test_Virtual_Buffer    0x00044004 // Frame Buffer: Test Virtual (Buffer) Width/Height (Response: Width In Pixels, Height In Pixels)
#define Test_Depth             0x00044005 // Frame Buffer: Test Depth (Response: Bits Per Pixel)
#define Test_Pixel_Order       0x00044006 // Frame Buffer: Test Pixel Order (Response: State)
#define Test_Alpha_Mode        0x00044007 // Frame Buffer: Test Alpha Mode (Response: State)
#define Test_Virtual_Offset    0x00044009 // Frame Buffer: Test Virtual Offset (Response: X In Pixels, Y In Pixels)
#define Test_Overscan          0x0004400A // Frame Buffer: Test Overscan (Response: Top In Pixels, Bottom In Pixels, Left In Pixels, Right In Pixels)
#define Test_Palette           0x0004400B // Frame Buffer: Test Palette (Response: RGBA Palette Values (Index 0 To 255))
#define Release_Buffer         0x00048001 // Frame Buffer: Release Buffer (Response: Releases And Disables The Frame Buffer)
#define Set_Physical_Display   0x00048003 // Frame Buffer: Set Physical (Display) Width/Height (Response: Width In Pixels, Height In Pixels)
#define Set_Virtual_Buffer     0x00048004 // Frame Buffer: Set Virtual (Buffer) Width/Height (Response: Width In Pixels, Height In Pixels)
#define Set_Depth              0x00048005 // Frame Buffer: Set Depth (Response: Bits Per Pixel)
#define Set_Pixel_Order        0x00048006 // Frame Buffer: Set Pixel Order (Response: State)
#define Set_Alpha_Mode         0x00048007 // Frame Buffer: Set Alpha Mode (Response: State)
#define Set_Virtual_Offset     0x00048009 // Frame Buffer: Set Virtual Offset (Response: X In Pixels, Y In Pixels)
#define Set_Overscan           0x0004800A // Frame Buffer: Set Overscan (Response: Top In Pixels, Bottom In Pixels, Left In Pixels, Right In Pixels)
#define Set_Palette            0x0004800B // Frame Buffer: Set Palette (Response: RGBA Palette Values (Index 0 To 255))
#define Get_Command_Line       0x00050001 // Config: Get Command Line (Response: ASCII Command Line String)
#define Get_DMA_Channels       0x00060001 // Shared Resource Management: Get DMA Channels (Response: Bits 0-15: DMA channels 0-15)

// Power: Unique Device ID's
#define PWR_SD_Card_ID  0x0 // SD Card
#define PWR_UART0_ID    0x1 // UART0
#define PWR_UART1_ID    0x2 // UART1
#define PWR_USB_HCD_ID  0x3 // USB HCD
#define PWR_I2C0_ID     0x4 // I2C0
#define PWR_I2C1_ID     0x5 // I2C1
#define PWR_I2C2_ID     0x6 // I2C2
#define PWR_SPI_ID      0x7 // SPI
#define PWR_CCP2TX_ID   0x8 // CCP2TX

// Clocks: Unique Clock ID's
#define CLK_EMMC_ID   0x1 // EMMC
#define CLK_UART_ID   0x2 // UART
#define CLK_ARM_ID    0x3 // ARM
#define CLK_CORE_ID   0x4 // CORE
#define CLK_V3D_ID    0x5 // V3D
#define CLK_H264_ID   0x6 // H264
#define CLK_ISP_ID    0x7 // ISP
#define CLK_SDRAM_ID  0x8 // SDRAM
#define CLK_PIXEL_ID  0x9 // PIXEL
#define CLK_PWM_ID    0xA // PWM

// Voltage: Unique Voltage ID's
#define VLT_Core_ID     0x1 // Core
#define VLT_SDRAM_C_ID  0x2 // SDRAM_C
#define VLT_SDRAM_P_ID  0x3 // SDRAM_P
#define VLT_SDRAM_I_ID  0x4 // SDRAM_I

// CM / Clock Manager
#define CM_BASE    0x101000 // Clock Manager Base Address
#define CM_GP0CTL      0x70 // Clock Manager General Purpose 0 Clock Control
#define CM_GP0DIV      0x74 // Clock Manager General Purpose 0 Clock Divisor
#define CM_GP1CTL      0x78 // Clock Manager General Purpose 1 Clock Control
#define CM_GP1DIV      0x7C // Clock Manager General Purpose 1 Clock Divisor
#define CM_GP2CTL      0x80 // Clock Manager General Purpose 2 Clock Control
#define CM_GP2DIV      0x84 // Clock Manager General Purpose 2 Clock Divisor
#define CM_PCMCTL      0x98 // Clock Manager PCM / I2S Clock Control
#define CM_PCMDIV      0x9C // Clock Manager PCM / I2S Clock Divisor
#define CM_PWMCTL      0xA0 // Clock Manager PWM Clock Control
#define CM_PWMDIV      0xA4 // Clock Manager PWM Clock Divisor

#define CM_SRC_OSCILLATOR        0x01 // Clock Control: Clock Source  Oscillator
#define CM_SRC_TESTDEBUG0        0x02 // Clock Control: Clock Source  Test Debug 0
#define CM_SRC_TESTDEBUG1        0x03 // Clock Control: Clock Source  Test Debug 1
#define CM_SRC_PLLAPER           0x04 // Clock Control: Clock Source  PLLA Per
#define CM_SRC_PLLCPER           0x05 // Clock Control: Clock Source  PLLC Per
#define CM_SRC_PLLDPER           0x06 // Clock Control: Clock Source  PLLD Per
#define CM_SRC_HDMIAUX           0x07 // Clock Control: Clock Source  HDMI Auxiliary
#define CM_SRC_GND               0x08 // Clock Control: Clock Source  GND
#define CM_ENAB                  0x10 // Clock Control: Enable The Clock Generator
#define CM_KILL                  0x20 // Clock Control: Kill The Clock Generator
#define CM_BUSY                  0x80 // Clock Control: Clock Generator Is Running
#define CM_FLIP                 0x100 // Clock Control: Invert The Clock Generator Output
#define CM_MASH_1               0x200 // Clock Control: MASH Control  1-Stage MASH (Equivalent To Non-MASH Dividers)
#define CM_MASH_2               0x400 // Clock Control: MASH Control  2-Stage MASH
#define CM_MASH_3               0x600 // Clock Control: MASH Control  3-Stage MASH
#define CM_PASSWORD        0x5A000000 // Clock Control: Password "5A"

// DMA Controller
#define DMA0_BASE   0x7000 // DMA Channel 0 Register Set
#define DMA1_BASE   0x7100 // DMA Channel 1 Register Set
#define DMA2_BASE   0x7200 // DMA Channel 2 Register Set
#define DMA3_BASE   0x7300 // DMA Channel 3 Register Set
#define DMA4_BASE   0x7400 // DMA Channel 4 Register Set
#define DMA5_BASE   0x7500 // DMA Channel 5 Register Set
#define DMA6_BASE   0x7600 // DMA Channel 6 Register Set
#define DMA7_BASE   0x7700 // DMA Channel 7 Register Set
#define DMA8_BASE   0x7800 // DMA Channel 8 Register Set
#define DMA9_BASE   0x7900 // DMA Channel 9 Register Set
#define DMA10_BASE  0x7A00 // DMA Channel 10 Register Set
#define DMA11_BASE  0x7B00 // DMA Channel 11 Register Set
#define DMA12_BASE  0x7C00 // DMA Channel 12 Register Set
#define DMA13_BASE  0x7D00 // DMA Channel 13 Register Set
#define DMA14_BASE  0x7E00 // DMA Channel 14 Register Set

#define DMA_INT_STATUS  0x7FE0 // Interrupt Status of each DMA Channel
#define DMA_ENABLE      0x7FF0 // Global Enable bits for each DMA Channel

#define DMA15_BASE  0xE05000 // DMA Channel 15 Register Set

#define DMA_CS          0x0 // DMA Channel 0..14 Control & Status
#define DMA_CONBLK_AD   0x4 // DMA Channel 0..14 Control Block Address
#define DMA_TI          0x8 // DMA Channel 0..14 CB Word 0 (Transfer Information)
#define DMA_SOURCE_AD   0xC // DMA Channel 0..14 CB Word 1 (Source Address)
#define DMA_DEST_AD    0x10 // DMA Channel 0..14 CB Word 2 (Destination Address)
#define DMA_TXFR_LEN   0x14 // DMA Channel 0..14 CB Word 3 (Transfer Length)
#define DMA_STRIDE     0x18 // DMA Channel 0..14 CB Word 4 (2D Stride)
#define DMA_NEXTCONBK  0x1C // DMA Channel 0..14 CB Word 5 (Next CB Address)
#define DMA_DEBUG      0x20 // DMA Channel 0..14 Debug

#define DMA_ACTIVE                                 0x1 // DMA Control & Status: Activate the DMA
#define DMA_END                                    0x2 // DMA Control & Status: DMA End Flag
#define DMA_INT                                    0x4 // DMA Control & Status: Interrupt Status
#define DMA_DREQ                                   0x8 // DMA Control & Status: DREQ State
#define DMA_PAUSED                                0x10 // DMA Control & Status: DMA Paused State
#define DMA_DREQ_STOPS_DMA                        0x20 // DMA Control & Status: DMA Paused by DREQ State
#define DMA_WAITING_FOR_OUTSTANDING_WRITES        0x40 // DMA Control & Status: DMA is Waiting for the Last Write to be Received
#define DMA_ERROR                                0x100 // DMA Control & Status: DMA Error
#define DMA_PRIORITY_0                             0x0 // DMA Control & Status: AXI Priority Level 0
#define DMA_PRIORITY_1                         0x10000 // DMA Control & Status: AXI Priority Level 1
#define DMA_PRIORITY_2                         0x20000 // DMA Control & Status: AXI Priority Level 2
#define DMA_PRIORITY_3                         0x30000 // DMA Control & Status: AXI Priority Level 3
#define DMA_PRIORITY_4                         0x40000 // DMA Control & Status: AXI Priority Level 4
#define DMA_PRIORITY_5                         0x50000 // DMA Control & Status: AXI Priority Level 5
#define DMA_PRIORITY_6                         0x60000 // DMA Control & Status: AXI Priority Level 6
#define DMA_PRIORITY_7                         0x70000 // DMA Control & Status: AXI Priority Level 7
#define DMA_PRIORITY_8                         0x80000 // DMA Control & Status: AXI Priority Level 8
#define DMA_PRIORITY_9                         0x90000 // DMA Control & Status: AXI Priority Level 9
#define DMA_PRIORITY_10                        0xA0000 // DMA Control & Status: AXI Priority Level 10
#define DMA_PRIORITY_11                        0xB0000 // DMA Control & Status: AXI Priority Level 11
#define DMA_PRIORITY_12                        0xC0000 // DMA Control & Status: AXI Priority Level 12
#define DMA_PRIORITY_13                        0xD0000 // DMA Control & Status: AXI Priority Level 13
#define DMA_PRIORITY_14                        0xE0000 // DMA Control & Status: AXI Priority Level 14
#define DMA_PRIORITY_15                        0xF0000 // DMA Control & Status: AXI Priority Level 15
#define DMA_PRIORITY                           0xF0000 // DMA Control & Status: AXI Priority Level
#define DMA_PANIC_PRIORITY_0                       0x0 // DMA Control & Status: AXI Panic Priority Level 0
#define DMA_PANIC_PRIORITY_1                  0x100000 // DMA Control & Status: AXI Panic Priority Level 1
#define DMA_PANIC_PRIORITY_2                  0x200000 // DMA Control & Status: AXI Panic Priority Level 2
#define DMA_PANIC_PRIORITY_3                  0x300000 // DMA Control & Status: AXI Panic Priority Level 3
#define DMA_PANIC_PRIORITY_4                  0x400000 // DMA Control & Status: AXI Panic Priority Level 4
#define DMA_PANIC_PRIORITY_5                  0x500000 // DMA Control & Status: AXI Panic Priority Level 5
#define DMA_PANIC_PRIORITY_6                  0x600000 // DMA Control & Status: AXI Panic Priority Level 6
#define DMA_PANIC_PRIORITY_7                  0x700000 // DMA Control & Status: AXI Panic Priority Level 7
#define DMA_PANIC_PRIORITY_8                  0x800000 // DMA Control & Status: AXI Panic Priority Level 8
#define DMA_PANIC_PRIORITY_9                  0x900000 // DMA Control & Status: AXI Panic Priority Level 9
#define DMA_PANIC_PRIORITY_10                 0xA00000 // DMA Control & Status: AXI Panic Priority Level 10
#define DMA_PANIC_PRIORITY_11                 0xB00000 // DMA Control & Status: AXI Panic Priority Level 11
#define DMA_PANIC_PRIORITY_12                 0xC00000 // DMA Control & Status: AXI Panic Priority Level 12
#define DMA_PANIC_PRIORITY_13                 0xD00000 // DMA Control & Status: AXI Panic Priority Level 13
#define DMA_PANIC_PRIORITY_14                 0xE00000 // DMA Control & Status: AXI Panic Priority Level 14
#define DMA_PANIC_PRIORITY_15                 0xF00000 // DMA Control & Status: AXI Panic Priority Level 14
#define DMA_PANIC_PRIORITY                    0xF00000 // DMA Control & Status: AXI Panic Priority Level
#define DMA_WAIT_FOR_OUTSTANDING_WRITES     0x10000000 // DMA Control & Status: Wait for Outstanding Writes
#define DMA_DISDEBUG                        0x20000000 // DMA Control & Status: Disable Debug Pause Signal
#define DMA_ABORT                           0x40000000 // DMA Control & Status: Abort DMA
#define DMA_RESET                           0x80000000 // DMA Control & Status: DMA Channel Reset

#define DMA_INTEN                  0x1 // DMA Transfer Information: Interrupt Enable
#define DMA_TDMODE                 0x2 // DMA Transfer Information: 2D Mode
#define DMA_WAIT_RESP              0x8 // DMA Transfer Information: Wait for a Write Response
#define DMA_DEST_INC              0x10 // DMA Transfer Information: Destination Address Increment
#define DMA_DEST_WIDTH            0x20 // DMA Transfer Information: Destination Transfer Width
#define DMA_DEST_DREQ             0x40 // DMA Transfer Information: Control Destination Writes with DREQ
#define DMA_DEST_IGNORE           0x80 // DMA Transfer Information: Ignore Writes
#define DMA_SRC_INC              0x100 // DMA Transfer Information: Source Address Increment
#define DMA_SRC_WIDTH            0x200 // DMA Transfer Information: Source Transfer Width
#define DMA_SRC_DREQ             0x400 // DMA Transfer Information: Control Source Reads with DREQ
#define DMA_SRC_IGNORE           0x800 // DMA Transfer Information: Ignore Reads
#define DMA_BURST_LENGTH_1         0x0 // DMA Transfer Information: Burst Transfer Length 1 Word
#define DMA_BURST_LENGTH_2      0x1000 // DMA Transfer Information: Burst Transfer Length 2 Words
#define DMA_BURST_LENGTH_3      0x2000 // DMA Transfer Information: Burst Transfer Length 3 Words
#define DMA_BURST_LENGTH_4      0x3000 // DMA Transfer Information: Burst Transfer Length 4 Words
#define DMA_BURST_LENGTH_5      0x4000 // DMA Transfer Information: Burst Transfer Length 5 Words
#define DMA_BURST_LENGTH_6      0x5000 // DMA Transfer Information: Burst Transfer Length 6 Words
#define DMA_BURST_LENGTH_7      0x6000 // DMA Transfer Information: Burst Transfer Length 7 Words
#define DMA_BURST_LENGTH_8      0x7000 // DMA Transfer Information: Burst Transfer Length 8 Words
#define DMA_BURST_LENGTH_9      0x8000 // DMA Transfer Information: Burst Transfer Length 9 Words
#define DMA_BURST_LENGTH_10     0x9000 // DMA Transfer Information: Burst Transfer Length 10 Words
#define DMA_BURST_LENGTH_11     0xA000 // DMA Transfer Information: Burst Transfer Length 11 Words
#define DMA_BURST_LENGTH_12     0xB000 // DMA Transfer Information: Burst Transfer Length 12 Words
#define DMA_BURST_LENGTH_13     0xC000 // DMA Transfer Information: Burst Transfer Length 13 Words
#define DMA_BURST_LENGTH_14     0xD000 // DMA Transfer Information: Burst Transfer Length 14 Words
#define DMA_BURST_LENGTH_15     0xE000 // DMA Transfer Information: Burst Transfer Length 15 Words
#define DMA_BURST_LENGTH_16     0xF000 // DMA Transfer Information: Burst Transfer Length 16 Words
#define DMA_BURST_LENGTH        0xF000 // DMA Transfer Information: Burst Transfer Length
#define DMA_PERMAP_0               0x0 // DMA Transfer Information: Peripheral Mapping Continuous Un-paced Transfer
#define DMA_PERMAP_1           0x10000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 1
#define DMA_PERMAP_2           0x20000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 2
#define DMA_PERMAP_3           0x30000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 3
#define DMA_PERMAP_4           0x40000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 4
#define DMA_PERMAP_5           0x50000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 5
#define DMA_PERMAP_6           0x60000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 6
#define DMA_PERMAP_7           0x70000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 7
#define DMA_PERMAP_8           0x80000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 8
#define DMA_PERMAP_9           0x90000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 9
#define DMA_PERMAP_10          0xA0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 10
#define DMA_PERMAP_11          0xB0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 11
#define DMA_PERMAP_12          0xC0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 12
#define DMA_PERMAP_13          0xD0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 13
#define DMA_PERMAP_14          0xE0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 14
#define DMA_PERMAP_15          0xF0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 15
#define DMA_PERMAP_16         0x100000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 16
#define DMA_PERMAP_17         0x110000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 17
#define DMA_PERMAP_18         0x120000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 18
#define DMA_PERMAP_19         0x130000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 19
#define DMA_PERMAP_20         0x140000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 20
#define DMA_PERMAP_21         0x150000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 21
#define DMA_PERMAP_22         0x160000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 22
#define DMA_PERMAP_23         0x170000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 23
#define DMA_PERMAP_24         0x180000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 24
#define DMA_PERMAP_25         0x190000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 25
#define DMA_PERMAP_26         0x1A0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 26
#define DMA_PERMAP_27         0x1B0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 27
#define DMA_PERMAP_28         0x1C0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 28
#define DMA_PERMAP_29         0x1D0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 29
#define DMA_PERMAP_30         0x1E0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 30
#define DMA_PERMAP_31         0x1F0000 // DMA Transfer Information: Peripheral Mapping Peripheral Number 31
#define DMA_PERMAP            0x1F0000 // DMA Transfer Information: Peripheral Mapping
#define DMA_WAITS_0                0x0 // DMA Transfer Information: Add No Wait Cycles
#define DMA_WAITS_1           0x200000 // DMA Transfer Information: Add 1 Wait Cycle
#define DMA_WAITS_2           0x400000 // DMA Transfer Information: Add 2 Wait Cycles
#define DMA_WAITS_3           0x600000 // DMA Transfer Information: Add 3 Wait Cycles
#define DMA_WAITS_4           0x800000 // DMA Transfer Information: Add 4 Wait Cycles
#define DMA_WAITS_5           0xA00000 // DMA Transfer Information: Add 5 Wait Cycles
#define DMA_WAITS_6           0xC00000 // DMA Transfer Information: Add 6 Wait Cycles
#define DMA_WAITS_7           0xE00000 // DMA Transfer Information: Add 7 Wait Cycles
#define DMA_WAITS_8          0x1000000 // DMA Transfer Information: Add 8 Wait Cycles
#define DMA_WAITS_9          0x1200000 // DMA Transfer Information: Add 9 Wait Cycles
#define DMA_WAITS_10         0x1400000 // DMA Transfer Information: Add 10 Wait Cycles
#define DMA_WAITS_11         0x1600000 // DMA Transfer Information: Add 11 Wait Cycles
#define DMA_WAITS_12         0x1800000 // DMA Transfer Information: Add 12 Wait Cycles
#define DMA_WAITS_13         0x1A00000 // DMA Transfer Information: Add 13 Wait Cycles
#define DMA_WAITS_14         0x1C00000 // DMA Transfer Information: Add 14 Wait Cycles
#define DMA_WAITS_15         0x1E00000 // DMA Transfer Information: Add 15 Wait Cycles
#define DMA_WAITS_16         0x2000000 // DMA Transfer Information: Add 16 Wait Cycles
#define DMA_WAITS_17         0x2200000 // DMA Transfer Information: Add 17 Wait Cycles
#define DMA_WAITS_18         0x2400000 // DMA Transfer Information: Add 18 Wait Cycles
#define DMA_WAITS_19         0x2600000 // DMA Transfer Information: Add 19 Wait Cycles
#define DMA_WAITS_20         0x2800000 // DMA Transfer Information: Add 20 Wait Cycles
#define DMA_WAITS_21         0x2A00000 // DMA Transfer Information: Add 21 Wait Cycles
#define DMA_WAITS_22         0x2C00000 // DMA Transfer Information: Add 22 Wait Cycles
#define DMA_WAITS_23         0x2E00000 // DMA Transfer Information: Add 23 Wait Cycles
#define DMA_WAITS_24         0x3000000 // DMA Transfer Information: Add 24 Wait Cycles
#define DMA_WAITS_25         0x3200000 // DMA Transfer Information: Add 25 Wait Cycles
#define DMA_WAITS_26         0x3400000 // DMA Transfer Information: Add 26 Wait Cycles
#define DMA_WAITS_27         0x3600000 // DMA Transfer Information: Add 27 Wait Cycles
#define DMA_WAITS_28         0x3800000 // DMA Transfer Information: Add 28 Wait Cycles
#define DMA_WAITS_29         0x3A00000 // DMA Transfer Information: Add 29 Wait Cycles
#define DMA_WAITS_30         0x3C00000 // DMA Transfer Information: Add 30 Wait Cycles
#define DMA_WAITS_31         0x3E00000 // DMA Transfer Information: Add 31 Wait Cycles
#define DMA_WAITS            0x3E00000 // DMA Transfer Information: Add Wait Cycles
#define DMA_NO_WIDE_BURSTS   0x4000000 // DMA Transfer Information: Don't Do Wide Writes as a 2 Beat Burst

#define DMA_XLENGTH      0xFFFF // DMA Transfer Length: Transfer Length in Bytes
#define DMA_YLENGTH  0x3FFF0000 // DMA Transfer Length: When in 2D Mode, This is the Y Transfer Length

#define DMA_S_STRIDE      0xFFFF // DMA 2D Stride: Source Stride (2D Mode)
#define DMA_D_STRIDE  0xFFFF0000 // DMA 2D Stride: Destination Stride (2D Mode)

#define DMA_READ_LAST_NOT_SET_ERROR         0x1 // DMA Debug: Read Last Not Set Error
#define DMA_FIFO_ERROR                      0x2 // DMA Debug: Fifo Error
#define DMA_READ_ERROR                      0x4 // DMA Debug: Slave Read Response Error
#define DMA_OUTSTANDING_WRITES             0xF0 // DMA Debug: DMA Outstanding Writes Counter
#define DMA_ID                           0xFF00 // DMA Debug: DMA ID
#define DMA_STATE                     0x1FF0000 // DMA Debug: DMA State Machine State
#define DMA_VERSION                   0xE000000 // DMA Debug: DMA Version
#define DMA_LITE                     0x10000000 // DMA Debug: DMA Lite

#define DMA_INT0      0x1 // DMA Interrupt Status: Interrupt Status of DMA Engine 0
#define DMA_INT1      0x2 // DMA Interrupt Status: Interrupt Status of DMA Engine 1
#define DMA_INT2      0x4 // DMA Interrupt Status: Interrupt Status of DMA Engine 2
#define DMA_INT3      0x8 // DMA Interrupt Status: Interrupt Status of DMA Engine 3
#define DMA_INT4     0x10 // DMA Interrupt Status: Interrupt Status of DMA Engine 4
#define DMA_INT5     0x20 // DMA Interrupt Status: Interrupt Status of DMA Engine 5
#define DMA_INT6     0x40 // DMA Interrupt Status: Interrupt Status of DMA Engine 6
#define DMA_INT7     0x80 // DMA Interrupt Status: Interrupt Status of DMA Engine 7
#define DMA_INT8    0x100 // DMA Interrupt Status: Interrupt Status of DMA Engine 8
#define DMA_INT9    0x200 // DMA Interrupt Status: Interrupt Status of DMA Engine 9
#define DMA_INT10   0x400 // DMA Interrupt Status: Interrupt Status of DMA Engine 10
#define DMA_INT11   0x800 // DMA Interrupt Status: Interrupt Status of DMA Engine 11
#define DMA_INT12  0x1000 // DMA Interrupt Status: Interrupt Status of DMA Engine 12
#define DMA_INT13  0x2000 // DMA Interrupt Status: Interrupt Status of DMA Engine 13
#define DMA_INT14  0x4000 // DMA Interrupt Status: Interrupt Status of DMA Engine 14
#define DMA_INT15  0x8000 // DMA Interrupt Status: Interrupt Status of DMA Engine 15

#define DMA_EN0      0x1 // DMA Enable: Enable DMA Engine 0
#define DMA_EN1      0x2 // DMA Enable: Enable DMA Engine 1
#define DMA_EN2      0x4 // DMA Enable: Enable DMA Engine 2
#define DMA_EN3      0x8 // DMA Enable: Enable DMA Engine 3
#define DMA_EN4     0x10 // DMA Enable: Enable DMA Engine 4
#define DMA_EN5     0x20 // DMA Enable: Enable DMA Engine 5
#define DMA_EN6     0x40 // DMA Enable: Enable DMA Engine 6
#define DMA_EN7     0x80 // DMA Enable: Enable DMA Engine 7
#define DMA_EN8    0x100 // DMA Enable: Enable DMA Engine 8
#define DMA_EN9    0x200 // DMA Enable: Enable DMA Engine 9
#define DMA_EN10   0x400 // DMA Enable: Enable DMA Engine 10
#define DMA_EN11   0x800 // DMA Enable: Enable DMA Engine 11
#define DMA_EN12  0x1000 // DMA Enable: Enable DMA Engine 12
#define DMA_EN13  0x2000 // DMA Enable: Enable DMA Engine 13
#define DMA_EN14  0x4000 // DMA Enable: Enable DMA Engine 14

// GPIO
#define GPIO_BASE       0x200000 // GPIO Base Address
#define GPIO_GPFSEL0         0x0 // GPIO Function Select 0
#define GPIO_GPFSEL1         0x4 // GPIO Function Select 1
#define GPIO_GPFSEL2         0x8 // GPIO Function Select 2
#define GPIO_GPFSEL3         0xC // GPIO Function Select 3
#define GPIO_GPFSEL4        0x10 // GPIO Function Select 4
#define GPIO_GPFSEL5        0x14 // GPIO Function Select 5
#define GPIO_GPSET0         0x1C // GPIO Pin Output Set 0
#define GPIO_GPSET1         0x20 // GPIO Pin Output Set 1
#define GPIO_GPCLR0         0x28 // GPIO Pin Output Clear 0
#define GPIO_GPCLR1         0x2C // GPIO Pin Output Clear 1
#define GPIO_GPLEV0         0x34 // GPIO Pin Level 0
#define GPIO_GPLEV1         0x38 // GPIO Pin Level 1
#define GPIO_GPEDS0         0x40 // GPIO Pin Event Detect Status 0
#define GPIO_GPEDS1         0x44 // GPIO Pin Event Detect Status 1
#define GPIO_GPREN0         0x4C // GPIO Pin Rising Edge Detect Enable 0
#define GPIO_GPREN1         0x50 // GPIO Pin Rising Edge Detect Enable 1
#define GPIO_GPFEN0         0x58 // GPIO Pin Falling Edge Detect Enable 0
#define GPIO_GPFEN1         0x5C // GPIO Pin Falling Edge Detect Enable 1
#define GPIO_GPHEN0         0x64 // GPIO Pin High Detect Enable 0
#define GPIO_GPHEN1         0x68 // GPIO Pin High Detect Enable 1
#define GPIO_GPLEN0         0x70 // GPIO Pin Low Detect Enable 0
#define GPIO_GPLEN1         0x74 // GPIO Pin Low Detect Enable 1
#define GPIO_GPAREN0        0x7C // GPIO Pin Async. Rising Edge Detect 0
#define GPIO_GPAREN1        0x80 // GPIO Pin Async. Rising Edge Detect 1
#define GPIO_GPAFEN0        0x88 // GPIO Pin Async. Falling Edge Detect 0
#define GPIO_GPAFEN1        0x8C // GPIO Pin Async. Falling Edge Detect 1
#define GPIO_GPPUD          0x94 // GPIO Pin Pull-up/down Enable
#define GPIO_GPPUDCLK0      0x98 // GPIO Pin Pull-up/down Enable Clock 0
#define GPIO_GPPUDCLK1      0x9C // GPIO Pin Pull-up/down Enable Clock 1
#define GPIO_TEST           0xB0 // GPIO Test

#define GPIO_FSEL0_IN    0x0 // GPIO Function Select: GPIO Pin X0 Is An Input
#define GPIO_FSEL0_OUT   0x1 // GPIO Function Select: GPIO Pin X0 Is An Output
#define GPIO_FSEL0_ALT0  0x4 // GPIO Function Select: GPIO Pin X0 Takes Alternate Function 0
#define GPIO_FSEL0_ALT1  0x5 // GPIO Function Select: GPIO Pin X0 Takes Alternate Function 1
#define GPIO_FSEL0_ALT2  0x6 // GPIO Function Select: GPIO Pin X0 Takes Alternate Function 2
#define GPIO_FSEL0_ALT3  0x7 // GPIO Function Select: GPIO Pin X0 Takes Alternate Function 3
#define GPIO_FSEL0_ALT4  0x3 // GPIO Function Select: GPIO Pin X0 Takes Alternate Function 4
#define GPIO_FSEL0_ALT5  0x2 // GPIO Function Select: GPIO Pin X0 Takes Alternate Function 5
#define GPIO_FSEL0_CLR   0x7 // GPIO Function Select: GPIO Pin X0 Clear Bits

#define GPIO_FSEL1_IN     0x0 // GPIO Function Select: GPIO Pin X1 Is An Input
#define GPIO_FSEL1_OUT    0x8 // GPIO Function Select: GPIO Pin X1 Is An Output
#define GPIO_FSEL1_ALT0  0x20 // GPIO Function Select: GPIO Pin X1 Takes Alternate Function 0
#define GPIO_FSEL1_ALT1  0x28 // GPIO Function Select: GPIO Pin X1 Takes Alternate Function 1
#define GPIO_FSEL1_ALT2  0x30 // GPIO Function Select: GPIO Pin X1 Takes Alternate Function 2
#define GPIO_FSEL1_ALT3  0x38 // GPIO Function Select: GPIO Pin X1 Takes Alternate Function 3
#define GPIO_FSEL1_ALT4  0x18 // GPIO Function Select: GPIO Pin X1 Takes Alternate Function 4
#define GPIO_FSEL1_ALT5  0x10 // GPIO Function Select: GPIO Pin X1 Takes Alternate Function 5
#define GPIO_FSEL1_CLR   0x38 // GPIO Function Select: GPIO Pin X1 Clear Bits

#define GPIO_FSEL2_IN      0x0 // GPIO Function Select: GPIO Pin X2 Is An Input
#define GPIO_FSEL2_OUT    0x40 // GPIO Function Select: GPIO Pin X2 Is An Output
#define GPIO_FSEL2_ALT0  0x100 // GPIO Function Select: GPIO Pin X2 Takes Alternate Function 0
#define GPIO_FSEL2_ALT1  0x140 // GPIO Function Select: GPIO Pin X2 Takes Alternate Function 1
#define GPIO_FSEL2_ALT2  0x180 // GPIO Function Select: GPIO Pin X2 Takes Alternate Function 2
#define GPIO_FSEL2_ALT3  0x1C0 // GPIO Function Select: GPIO Pin X2 Takes Alternate Function 3
#define GPIO_FSEL2_ALT4   0xC0 // GPIO Function Select: GPIO Pin X2 Takes Alternate Function 4
#define GPIO_FSEL2_ALT5   0x80 // GPIO Function Select: GPIO Pin X2 Takes Alternate Function 5
#define GPIO_FSEL2_CLR   0x1C0 // GPIO Function Select: GPIO Pin X2 Clear Bits

#define GPIO_FSEL3_IN      0x0 // GPIO Function Select: GPIO Pin X3 Is An Input
#define GPIO_FSEL3_OUT   0x200 // GPIO Function Select: GPIO Pin X3 Is An Output
#define GPIO_FSEL3_ALT0  0x800 // GPIO Function Select: GPIO Pin X3 Takes Alternate Function 0
#define GPIO_FSEL3_ALT1  0xA00 // GPIO Function Select: GPIO Pin X3 Takes Alternate Function 1
#define GPIO_FSEL3_ALT2  0xC00 // GPIO Function Select: GPIO Pin X3 Takes Alternate Function 2
#define GPIO_FSEL3_ALT3  0xE00 // GPIO Function Select: GPIO Pin X3 Takes Alternate Function 3
#define GPIO_FSEL3_ALT4  0x600 // GPIO Function Select: GPIO Pin X3 Takes Alternate Function 4
#define GPIO_FSEL3_ALT5  0x400 // GPIO Function Select: GPIO Pin X3 Takes Alternate Function 5
#define GPIO_FSEL3_CLR   0xE00 // GPIO Function Select: GPIO Pin X3 Clear Bits

#define GPIO_FSEL4_IN       0x0 // GPIO Function Select: GPIO Pin X4 Is An Input
#define GPIO_FSEL4_OUT   0x1000 // GPIO Function Select: GPIO Pin X4 Is An Output
#define GPIO_FSEL4_ALT0  0x4000 // GPIO Function Select: GPIO Pin X4 Takes Alternate Function 0
#define GPIO_FSEL4_ALT1  0x5000 // GPIO Function Select: GPIO Pin X4 Takes Alternate Function 1
#define GPIO_FSEL4_ALT2  0x6000 // GPIO Function Select: GPIO Pin X4 Takes Alternate Function 2
#define GPIO_FSEL4_ALT3  0x7000 // GPIO Function Select: GPIO Pin X4 Takes Alternate Function 3
#define GPIO_FSEL4_ALT4  0x3000 // GPIO Function Select: GPIO Pin X4 Takes Alternate Function 4
#define GPIO_FSEL4_ALT5  0x2000 // GPIO Function Select: GPIO Pin X4 Takes Alternate Function 5
#define GPIO_FSEL4_CLR   0x7000 // GPIO Function Select: GPIO Pin X4 Clear Bits

#define GPIO_FSEL5_IN        0x0 // GPIO Function Select: GPIO Pin X5 Is An Input
#define GPIO_FSEL5_OUT    0x8000 // GPIO Function Select: GPIO Pin X5 Is An Output
#define GPIO_FSEL5_ALT0  0x20000 // GPIO Function Select: GPIO Pin X5 Takes Alternate Function 0
#define GPIO_FSEL5_ALT1  0x28000 // GPIO Function Select: GPIO Pin X5 Takes Alternate Function 1
#define GPIO_FSEL5_ALT2  0x30000 // GPIO Function Select: GPIO Pin X5 Takes Alternate Function 2
#define GPIO_FSEL5_ALT3  0x38000 // GPIO Function Select: GPIO Pin X5 Takes Alternate Function 3
#define GPIO_FSEL5_ALT4  0x18000 // GPIO Function Select: GPIO Pin X5 Takes Alternate Function 4
#define GPIO_FSEL5_ALT5  0x10000 // GPIO Function Select: GPIO Pin X5 Takes Alternate Function 5
#define GPIO_FSEL5_CLR   0x38000 // GPIO Function Select: GPIO Pin X5 Clear Bits

#define GPIO_FSEL6_IN         0x0 // GPIO Function Select: GPIO Pin X6 Is An Input
#define GPIO_FSEL6_OUT    0x40000 // GPIO Function Select: GPIO Pin X6 Is An Output
#define GPIO_FSEL6_ALT0  0x100000 // GPIO Function Select: GPIO Pin X6 Takes Alternate Function 0
#define GPIO_FSEL6_ALT1  0x140000 // GPIO Function Select: GPIO Pin X6 Takes Alternate Function 1
#define GPIO_FSEL6_ALT2  0x180000 // GPIO Function Select: GPIO Pin X6 Takes Alternate Function 2
#define GPIO_FSEL6_ALT3  0x1C0000 // GPIO Function Select: GPIO Pin X6 Takes Alternate Function 3
#define GPIO_FSEL6_ALT4   0xC0000 // GPIO Function Select: GPIO Pin X6 Takes Alternate Function 4
#define GPIO_FSEL6_ALT5   0x80000 // GPIO Function Select: GPIO Pin X6 Takes Alternate Function 5
#define GPIO_FSEL6_CLR   0x1C0000 // GPIO Function Select: GPIO Pin X6 Clear Bits

#define GPIO_FSEL7_IN         0x0 // GPIO Function Select: GPIO Pin X7 Is An Input
#define GPIO_FSEL7_OUT   0x200000 // GPIO Function Select: GPIO Pin X7 Is An Output
#define GPIO_FSEL7_ALT0  0x800000 // GPIO Function Select: GPIO Pin X7 Takes Alternate Function 0
#define GPIO_FSEL7_ALT1  0xA00000 // GPIO Function Select: GPIO Pin X7 Takes Alternate Function 1
#define GPIO_FSEL7_ALT2  0xC00000 // GPIO Function Select: GPIO Pin X7 Takes Alternate Function 2
#define GPIO_FSEL7_ALT3  0xE00000 // GPIO Function Select: GPIO Pin X7 Takes Alternate Function 3
#define GPIO_FSEL7_ALT4  0x600000 // GPIO Function Select: GPIO Pin X7 Takes Alternate Function 4
#define GPIO_FSEL7_ALT5  0x400000 // GPIO Function Select: GPIO Pin X7 Takes Alternate Function 5
#define GPIO_FSEL7_CLR   0xE00000 // GPIO Function Select: GPIO Pin X7 Clear Bits

#define GPIO_FSEL8_IN          0x0 // GPIO Function Select: GPIO Pin X8 Is An Input
#define GPIO_FSEL8_OUT   0x1000000 // GPIO Function Select: GPIO Pin X8 Is An Output
#define GPIO_FSEL8_ALT0  0x4000000 // GPIO Function Select: GPIO Pin X8 Takes Alternate Function 0
#define GPIO_FSEL8_ALT1  0x5000000 // GPIO Function Select: GPIO Pin X8 Takes Alternate Function 1
#define GPIO_FSEL8_ALT2  0x6000000 // GPIO Function Select: GPIO Pin X8 Takes Alternate Function 2
#define GPIO_FSEL8_ALT3  0x7000000 // GPIO Function Select: GPIO Pin X8 Takes Alternate Function 3
#define GPIO_FSEL8_ALT4  0x3000000 // GPIO Function Select: GPIO Pin X8 Takes Alternate Function 4
#define GPIO_FSEL8_ALT5  0x2000000 // GPIO Function Select: GPIO Pin X8 Takes Alternate Function 5
#define GPIO_FSEL8_CLR   0x7000000 // GPIO Function Select: GPIO Pin X8 Clear Bits

#define GPIO_FSEL9_IN           0x0 // GPIO Function Select: GPIO Pin X9 Is An Input
#define GPIO_FSEL9_OUT    0x8000000 // GPIO Function Select: GPIO Pin X9 Is An Output
#define GPIO_FSEL9_ALT0  0x20000000 // GPIO Function Select: GPIO Pin X9 Takes Alternate Function 0
#define GPIO_FSEL9_ALT1  0x28000000 // GPIO Function Select: GPIO Pin X9 Takes Alternate Function 1
#define GPIO_FSEL9_ALT2  0x30000000 // GPIO Function Select: GPIO Pin X9 Takes Alternate Function 2
#define GPIO_FSEL9_ALT3  0x38000000 // GPIO Function Select: GPIO Pin X9 Takes Alternate Function 3
#define GPIO_FSEL9_ALT4  0x18000000 // GPIO Function Select: GPIO Pin X9 Takes Alternate Function 4
#define GPIO_FSEL9_ALT5  0x10000000 // GPIO Function Select: GPIO Pin X9 Takes Alternate Function 5
#define GPIO_FSEL9_CLR   0x38000000 // GPIO Function Select: GPIO Pin X9 Clear Bits

#define GPIO_0          0x1 // GPIO Pin 0: 0
#define GPIO_1          0x2 // GPIO Pin 0: 1
#define GPIO_2          0x4 // GPIO Pin 0: 2
#define GPIO_3          0x8 // GPIO Pin 0: 3
#define GPIO_4         0x10 // GPIO Pin 0: 4
#define GPIO_5         0x20 // GPIO Pin 0: 5
#define GPIO_6         0x40 // GPIO Pin 0: 6
#define GPIO_7         0x80 // GPIO Pin 0: 7
#define GPIO_8        0x100 // GPIO Pin 0: 8
#define GPIO_9        0x200 // GPIO Pin 0: 9
#define GPIO_10       0x400 // GPIO Pin 0: 10
#define GPIO_11       0x800 // GPIO Pin 0: 11
#define GPIO_12      0x1000 // GPIO Pin 0: 12
#define GPIO_13      0x2000 // GPIO Pin 0: 13
#define GPIO_14      0x4000 // GPIO Pin 0: 14
#define GPIO_15      0x8000 // GPIO Pin 0: 15
#define GPIO_16     0x10000 // GPIO Pin 0: 16
#define GPIO_17     0x20000 // GPIO Pin 0: 17
#define GPIO_18     0x40000 // GPIO Pin 0: 18
#define GPIO_19     0x80000 // GPIO Pin 0: 19
#define GPIO_20    0x100000 // GPIO Pin 0: 20
#define GPIO_21    0x200000 // GPIO Pin 0: 21
#define GPIO_22    0x400000 // GPIO Pin 0: 22
#define GPIO_23    0x800000 // GPIO Pin 0: 23
#define GPIO_24   0x1000000 // GPIO Pin 0: 24
#define GPIO_25   0x2000000 // GPIO Pin 0: 25
#define GPIO_26   0x4000000 // GPIO Pin 0: 26
#define GPIO_27   0x8000000 // GPIO Pin 0: 27
#define GPIO_28  0x10000000 // GPIO Pin 0: 28
#define GPIO_29  0x20000000 // GPIO Pin 0: 29
#define GPIO_30  0x40000000 // GPIO Pin 0: 30
#define GPIO_31  0x80000000 // GPIO Pin 0: 31

#define GPIO_32         0x1 // GPIO Pin 1: 32
#define GPIO_33         0x2 // GPIO Pin 1: 33
#define GPIO_34         0x4 // GPIO Pin 1: 34
#define GPIO_35         0x8 // GPIO Pin 1: 35
#define GPIO_36        0x10 // GPIO Pin 1: 36
#define GPIO_37        0x20 // GPIO Pin 1: 37
#define GPIO_38        0x40 // GPIO Pin 1: 38
#define GPIO_39        0x80 // GPIO Pin 1: 39
#define GPIO_40       0x100 // GPIO Pin 1: 40
#define GPIO_41       0x200 // GPIO Pin 1: 41
#define GPIO_42       0x400 // GPIO Pin 1: 42
#define GPIO_43       0x800 // GPIO Pin 1: 43
#define GPIO_44      0x1000 // GPIO Pin 1: 44
#define GPIO_45      0x2000 // GPIO Pin 1: 45
#define GPIO_46      0x4000 // GPIO Pin 1: 46
#define GPIO_47      0x8000 // GPIO Pin 1: 47
#define GPIO_48     0x10000 // GPIO Pin 1: 48
#define GPIO_49     0x20000 // GPIO Pin 1: 49
#define GPIO_50     0x40000 // GPIO Pin 1: 50
#define GPIO_51     0x80000 // GPIO Pin 1: 51
#define GPIO_52    0x100000 // GPIO Pin 1: 52
#define GPIO_53    0x200000 // GPIO Pin 1: 53

// PCM / I2S Audio Interface
#define PCM_BASE      0x203000 // PCM Base Address
#define PCM_CS_A           0x0 // PCM Control & Status
#define PCM_FIFO_A         0x4 // PCM FIFO Data
#define PCM_MODE_A         0x8 // PCM Mode
#define PCM_RXC_A          0xC // PCM Receive Configuration
#define PCM_TXC_A         0x10 // PCM Transmit Configuration
#define PCM_DREQ_A        0x14 // PCM DMA Request Level
#define PCM_INTEN_A       0x18 // PCM Interrupt Enables
#define PCM_INTSTC_A      0x1C // PCM Interrupt Status & Clear
#define PCM_GRAY          0x20 // PCM Gray Mode Control

#define PCM_EN             0x1 // PCM Control & Status: Enable the PCM Audio Interface
#define PCM_RXON           0x2 // PCM Control & Status: Enable Reception
#define PCM_TXON           0x4 // PCM Control & Status: Enable Transmission
#define PCM_TXCLR          0x8 // PCM Control & Status: Clear the TX FIFO
#define PCM_RXCLR         0x10 // PCM Control & Status: Clear the RX FIFO
#define PCM_TXTHR_0        0x0 // PCM Control & Status: Sets the TX FIFO Threshold at which point the TXW flag is Set when the TX FIFO is Empty
#define PCM_TXTHR_1       0x20 // PCM Control & Status: Sets the TX FIFO Threshold at which point the TXW flag is Set when the TX FIFO is less than Full
#define PCM_TXTHR_2       0x40 // PCM Control & Status: Sets the TX FIFO Threshold at which point the TXW flag is Set when the TX FIFO is less than Full
#define PCM_TXTHR_3       0x60 // PCM Control & Status: Sets the TX FIFO Threshold at which point the TXW flag is Set when the TX FIFO is Full but for one Sample
#define PCM_TXTHR         0x60 // PCM Control & Status: Sets the TX FIFO Threshold at which point the TXW flag is Set
#define PCM_RXTHR_0        0x0 // PCM Control & Status: Sets the RX FIFO Threshold at which point the RXR flag is Set when we have a single Sample in the RX FIFO
#define PCM_RXTHR_1       0x80 // PCM Control & Status: Sets the RX FIFO Threshold at which point the RXR flag is Set when the RX FIFO is at least Full
#define PCM_RXTHR_2      0x100 // PCM Control & Status: Sets the RX FIFO Threshold at which point the RXR flag is Set when the RX FIFO is at least Full
#define PCM_RXTHR_3      0x180 // PCM Control & Status: Sets the RX FIFO Threshold at which point the RXR flag is Set when the RX FIFO is Full
#define PCM_RXTHR        0x180 // PCM Control & Status: Sets the RX FIFO Threshold at which point the RXR flag is Set
#define PCM_DMAEN        0x200 // PCM Control & Status: DMA DREQ Enable
#define PCM_TXSYNC      0x2000 // PCM Control & Status: TX FIFO Sync
#define PCM_RXSYNC      0x4000 // PCM Control & Status: RX FIFO Sync
#define PCM_TXERR       0x8000 // PCM Control & Status: TX FIFO Error
#define PCM_RXERR      0x10000 // PCM Control & Status: RX FIFO Error
#define PCM_TXW        0x20000 // PCM Control & Status: Indicates that the TX FIFO needs Writing
#define PCM_RXR        0x40000 // PCM Control & Status: Indicates that the RX FIFO needs Reading
#define PCM_TXD        0x80000 // PCM Control & Status: Indicates that the TX FIFO can accept Data
#define PCM_RXD       0x100000 // PCM Control & Status: Indicates that the RX FIFO contains Data
#define PCM_TXE       0x200000 // PCM Control & Status: TX FIFO is Empty
#define PCM_RXF       0x400000 // PCM Control & Status: RX FIFO is Full
#define PCM_RXSEX     0x800000 // PCM Control & Status: RX Sign Extend
#define PCM_SYNC     0x1000000 // PCM Control & Status: PCM Clock Sync helper
#define PCM_STBY     0x2000000 // PCM Control & Status: RAM Standby

#define PSM_FSLEN         0x3FF // PCM Mode: Frame Sync Length
#define PSM_FLEN        0xFFC00 // PCM Mode: Frame Length
#define PCM_FSI        0x100000 // PCM Mode: Frame Sync Invert this logically inverts the Frame Sync Signal
#define PCM_FSM        0x200000 // PCM Mode: Frame Sync Mode
#define PCM_CLKI       0x400000 // PCM Mode: Clock Invert this logically inverts the PCM_CLK Signal
#define PCM_CLKM       0x800000 // PCM Mode: PCM Clock Mode
#define PCM_FTXP      0x1000000 // PCM Mode: Transmit Frame Packed Mode
#define PCM_FRXP      0x2000000 // PCM Mode: Receive Frame Packed Mode
#define PCM_PDME      0x4000000 // PCM Mode: PDM Input Mode Enable
#define PCM_PDMN      0x8000000 // PCM Mode: PDM Decimation Factor (N)
#define PCM_CLK_DIS  0x10000000 // PCM Mode: PCM Clock Disable

#define PCM_CH2WID_8          0x0 // PCM Receive & Transmit Configuration: Channel 2 Width 8 bits Wide
#define PCM_CH2WID_9          0x1 // PCM Receive & Transmit Configuration: Channel 2 Width 9 bits Wide
#define PCM_CH2WID_10         0x2 // PCM Receive & Transmit Configuration: Channel 2 Width 10 bits Wide
#define PCM_CH2WID_11         0x3 // PCM Receive & Transmit Configuration: Channel 2 Width 11 bits Wide
#define PCM_CH2WID_12         0x4 // PCM Receive & Transmit Configuration: Channel 2 Width 12 bits Wide
#define PCM_CH2WID_13         0x5 // PCM Receive & Transmit Configuration: Channel 2 Width 13 bits Wide
#define PCM_CH2WID_14         0x6 // PCM Receive & Transmit Configuration: Channel 2 Width 14 bits Wide
#define PCM_CH2WID_15         0x7 // PCM Receive & Transmit Configuration: Channel 2 Width 15 bits Wide
#define PCM_CH2WID_16         0x8 // PCM Receive & Transmit Configuration: Channel 2 Width 16 bits Wide
#define PCM_CH2WID_17         0x9 // PCM Receive & Transmit Configuration: Channel 2 Width 17 bits Wide
#define PCM_CH2WID_18         0xA // PCM Receive & Transmit Configuration: Channel 2 Width 18 bits Wide
#define PCM_CH2WID_19         0xB // PCM Receive & Transmit Configuration: Channel 2 Width 19 bits Wide
#define PCM_CH2WID_20         0xC // PCM Receive & Transmit Configuration: Channel 2 Width 20 bits Wide
#define PCM_CH2WID_21         0xD // PCM Receive & Transmit Configuration: Channel 2 Width 21 bits Wide
#define PCM_CH2WID_22         0xE // PCM Receive & Transmit Configuration: Channel 2 Width 22 bits Wide
#define PCM_CH2WID_23         0xF // PCM Receive & Transmit Configuration: Channel 2 Width 23 bits Wide
#define PCM_CH2WID            0xF // PCM Receive & Transmit Configuration: Channel 2 Width
#define PCM_CH2WID_24      0x8000 // PCM Receive & Transmit Configuration: Channel 2 Width 24 bits wide
#define PCM_CH2WID_25      0x8001 // PCM Receive & Transmit Configuration: Channel 2 Width 25 bits wide
#define PCM_CH2WID_26      0x8002 // PCM Receive & Transmit Configuration: Channel 2 Width 26 bits wide
#define PCM_CH2WID_27      0x8003 // PCM Receive & Transmit Configuration: Channel 2 Width 27 bits wide
#define PCM_CH2WID_28      0x8004 // PCM Receive & Transmit Configuration: Channel 2 Width 28 bits wide
#define PCM_CH2WID_29      0x8005 // PCM Receive & Transmit Configuration: Channel 2 Width 29 bits wide
#define PCM_CH2WID_30      0x8006 // PCM Receive & Transmit Configuration: Channel 2 Width 30 bits wide
#define PCM_CH2WID_31      0x8007 // PCM Receive & Transmit Configuration: Channel 2 Width 31 bits wide
#define PCM_CH2WID_32      0x8008 // PCM Receive & Transmit Configuration: Channel 2 Width 32 bits wide
#define PCM_CH2POS         0x3FF0 // PCM Receive & Transmit Configuration: Channel 2 Position
#define PCM_CH2EN          0x4000 // PCM Receive & Transmit Configuration: Channel 2 Enable
#define PCM_CH2WEX         0x8000 // PCM Receive & Transmit Configuration: Channel 2 Width Extension Bit
#define PCM_CH1WID_8          0x0 // PCM Receive & Transmit Configuration: Channel 1 Width 8 bits Wide
#define PCM_CH1WID_9      0x10000 // PCM Receive & Transmit Configuration: Channel 1 Width 9 bits Wide
#define PCM_CH1WID_10     0x20000 // PCM Receive & Transmit Configuration: Channel 1 Width 10 bits Wide
#define PCM_CH1WID_11     0x30000 // PCM Receive & Transmit Configuration: Channel 1 Width 11 bits Wide
#define PCM_CH1WID_12     0x40000 // PCM Receive & Transmit Configuration: Channel 1 Width 12 bits Wide
#define PCM_CH1WID_13     0x50000 // PCM Receive & Transmit Configuration: Channel 1 Width 13 bits Wide
#define PCM_CH1WID_14     0x60000 // PCM Receive & Transmit Configuration: Channel 1 Width 14 bits Wide
#define PCM_CH1WID_15     0x70000 // PCM Receive & Transmit Configuration: Channel 1 Width 15 bits Wide
#define PCM_CH1WID_16     0x80000 // PCM Receive & Transmit Configuration: Channel 1 Width 16 bits Wide
#define PCM_CH1WID_17     0x90000 // PCM Receive & Transmit Configuration: Channel 1 Width 17 bits Wide
#define PCM_CH1WID_18     0xA0000 // PCM Receive & Transmit Configuration: Channel 1 Width 18 bits Wide
#define PCM_CH1WID_19     0xB0000 // PCM Receive & Transmit Configuration: Channel 1 Width 19 bits Wide
#define PCM_CH1WID_20     0xC0000 // PCM Receive & Transmit Configuration: Channel 1 Width 20 bits Wide
#define PCM_CH1WID_21     0xD0000 // PCM Receive & Transmit Configuration: Channel 1 Width 21 bits Wide
#define PCM_CH1WID_22     0xE0000 // PCM Receive & Transmit Configuration: Channel 1 Width 22 bits Wide
#define PCM_CH1WID_23     0xF0000 // PCM Receive & Transmit Configuration: Channel 1 Width 23 bits Wide
#define PCM_CH1WID        0xF0000 // PCM Receive & Transmit Configuration: Channel 1 Width
#define PCM_CH1WID_24  0x80000000 // PCM Receive & Transmit Configuration: Channel 1 Width 24 bits wide
#define PCM_CH1WID_25  0x80010000 // PCM Receive & Transmit Configuration: Channel 1 Width 25 bits wide
#define PCM_CH1WID_26  0x80020000 // PCM Receive & Transmit Configuration: Channel 1 Width 26 bits wide
#define PCM_CH1WID_27  0x80030000 // PCM Receive & Transmit Configuration: Channel 1 Width 27 bits wide
#define PCM_CH1WID_28  0x80040000 // PCM Receive & Transmit Configuration: Channel 1 Width 28 bits wide
#define PCM_CH1WID_29  0x80050000 // PCM Receive & Transmit Configuration: Channel 1 Width 29 bits wide
#define PCM_CH1WID_30  0x80060000 // PCM Receive & Transmit Configuration: Channel 1 Width 30 bits wide
#define PCM_CH1WID_31  0x80070000 // PCM Receive & Transmit Configuration: Channel 1 Width 31 bits wide
#define PCM_CH1WID_32  0x80080000 // PCM Receive & Transmit Configuration: Channel 1 Width 32 bits wide
#define PCM_CH1POS     0x3FF00000 // PCM Receive & Transmit Configuration: Channel 1 Position
#define PCM_CH1EN      0x40000000 // PCM Receive & Transmit Configuration: Channel 1 Enable
#define PCM_CH1WEX     0x80000000 // PCM Receive & Transmit Configuration: Channel 1 Width Extension Bit

#define PCM_RX              0x7F // PCM DMA Request Level: RX Request Level
#define PCM_TX            0x7F00 // PCM DMA Request Level: TX Request Level
#define PCM_RX_PANIC    0x7F0000 // PCM DMA Request Level: RX Panic Level
#define PCM_TX_PANIC  0x7F000000 // PCM DMA Request Level: TX Panic Level

#define PCM_INT_TXW    0x1 // PCM Interrupt Enables & Interrupt Status & Clear: TX Write Interrupt Enable
#define PCM_INT_RXR    0x2 // PCM Interrupt Enables & Interrupt Status & Clear: RX Read Interrupt Enable
#define PCM_INT_TXERR  0x4 // PCM Interrupt Enables & Interrupt Status & Clear: TX Error Interrupt
#define PCM_INT_RXERR  0x8 // PCM Interrupt Enables & Interrupt Status & Clear: RX Error Interrupt

#define PCM_GRAY_EN           0x1 // PCM Gray Mode Control: Enable GRAY Mode
#define PCM_GRAY_CLR          0x2 // PCM Gray Mode Control: Clear the GRAY Mode Logic
#define PCM_GRAY_FLUSH        0x4 // PCM Gray Mode Control: Flush the RX Buffer into the RX FIFO
#define PCM_RXLEVEL         0x3F0 // PCM Gray Mode Control: The Current Fill Level of the RX Buffer
#define PCM_FLUSHED        0xFC00 // PCM Gray Mode Control: The Number of Bits that were Flushed into the RX FIFO
#define PCM_RXFIFOLEVEL  0x3F0000 // PCM Gray Mode Control: The Current Level of the RX FIFO

// PWM / Pulse Width Modulator Interface
#define PWM_BASE  0x20C000 // PWM Base Address
#define PWM_CTL        0x0 // PWM Control
#define PWM_STA        0x4 // PWM Status
#define PWM_DMAC       0x8 // PWM DMA Configuration
#define PWM_RNG1      0x10 // PWM Channel 1 Range
#define PWM_DAT1      0x14 // PWM Channel 1 Data
#define PWM_FIF1      0x18 // PWM FIFO Input
#define PWM_RNG2      0x20 // PWM Channel 2 Range
#define PWM_DAT2      0x24 // PWM Channel 2 Data

#define PWM_PWEN1     0x1 // PWM Control: Channel 1 Enable
#define PWM_MODE1     0x2 // PWM Control: Channel 1 Mode
#define PWM_RPTL1     0x4 // PWM Control: Channel 1 Repeat Last Data
#define PWM_SBIT1     0x8 // PWM Control: Channel 1 Silence Bit
#define PWM_POLA1    0x10 // PWM Control: Channel 1 Polarity
#define PWM_USEF1    0x20 // PWM Control: Channel 1 Use Fifo
#define PWM_CLRF1    0x40 // PWM Control: Clear Fifo
#define PWM_MSEN1    0x80 // PWM Control: Channel 1 M/S Enable
#define PWM_PWEN2   0x100 // PWM Control: Channel 2 Enable
#define PWM_MODE2   0x200 // PWM Control: Channel 2 Mode
#define PWM_RPTL2   0x400 // PWM Control: Channel 2 Repeat Last Data
#define PWM_SBIT2   0x800 // PWM Control: Channel 2 Silence Bit
#define PWM_POLA2  0x1000 // PWM Control: Channel 2 Polarity
#define PWM_USEF2  0x2000 // PWM Control: Channel 2 Use Fifo
#define PWM_MSEN2  0x8000 // PWM Control: Channel 2 M/S Enable

#define PWM_FULL1     0x1 // PWM Status: Fifo Full Flag
#define PWM_EMPT1     0x2 // PWM Status: Fifo Empty Flag
#define PWM_WERR1     0x4 // PWM Status: Fifo Write Error Flag
#define PWM_RERR1     0x8 // PWM Status: Fifo Read Error Flag
#define PWM_GAPO1    0x10 // PWM Status: Channel 1 Gap Occurred Flag
#define PWM_GAPO2    0x20 // PWM Status: Channel 2 Gap Occurred Flag
#define PWM_GAPO3    0x40 // PWM Status: Channel 3 Gap Occurred Flag
#define PWM_GAPO4    0x80 // PWM Status: Channel 4 Gap Occurred Flag
#define PWM_BERR    0x100 // PWM Status: Bus Error Flag
#define PWM_STA1    0x200 // PWM Status: Channel 1 State
#define PWM_STA2    0x400 // PWM Status: Channel 2 State
#define PWM_STA3    0x800 // PWM Status: Channel 3 State
#define PWM_STA4   0x1000 // PWM Status: Channel 4 State

#define PWM_ENAB  0x80000000 // PWM DMA Configuration: DMA Enable

#endif
