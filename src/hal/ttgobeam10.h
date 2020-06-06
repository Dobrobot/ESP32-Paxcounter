// clang-format off
// upload_speed 921600
// board ttgo-t-beam

#ifndef _TTGOBEAM_H
#define _TTGOBEAM_H

#include <stdint.h>

/* 
Hardware related definitions for TTGO T-Beam board
for T-Beam versions T22_V10 + T22_V11
pinouts taken from https://github.com/lewisxhe/TTGO-T-Beam

/// Button functions: ///
Power, short press -> set device on (toggles display while device is on)
Power, long press -> set device off
User, short press -> flip display page 
User, long press -> send LORA message
Reset -> reset device
*/

//#define HAS_DISPLAY 1
#define MY_DISPLAY_SDA SDA
#define MY_DISPLAY_SCL SCL
#define MY_DISPLAY_RST NOT_A_PIN
//#define MY_DISPLAY_FLIP  1 // use if display is rotated

#define HAS_LORA 1       // comment out if device shall not send data via LoRa
#define CFG_sx1276_radio 1 // HPD13A LoRa SoC
#define HAS_BUTTON GPIO_NUM_38 // middle on board button
#define HAS_LED NOT_A_PIN

// power management settings
#define HAS_PMU 1 // has AXP192 chip
#define PMU_INT GPIO_NUM_35 // battery interrupt
#define PMU_CHG_CURRENT AXP1XX_CHARGE_CUR_1000MA // battery charge current
// possible values (mA):
// 100/190/280/360/450/550/630/700/780/880/960/1000/1080/1160/1240/1320
#define PMU_CHG_CUTOFF AXP202_TARGET_VOL_4_2V // battery charge cutoff
// possible values (V):
// 4_1/4_15/4_2/4_36

// GPS settings
#define HAS_GPS 1 // use on board GPS
#define GPS_SERIAL 9600, SERIAL_8N1, GPIO_NUM_34, GPIO_NUM_12 // UBlox NEO 6M
#define GPS_INT GPIO_NUM_37 // 30ns accurary timepulse generated by NEO 6M Pin #3

// enable only if device has these sensors, otherwise comment these lines
// BME680 sensor on I2C bus
//#define HAS_BME 1 // Enable BME sensors in general
//#define HAS_BME680 SDA, SCL
//#define BME680_ADDR BME680_I2C_ADDR_PRIMARY // !! connect SDIO of BME680 to GND !!

// user defined sensors (if connected)
//#define HAS_SENSORS 1 // comment out if device has user defined sensors

//#define DISABLE_BROWNOUT 1 // comment out if you want to keep brownout feature

#endif

/*

// T-Beam V10 has on board power management by AXP192 PMU chip:
//
// DCDC1 0.7-3.5V @ 1200mA -> OLED
// DCDC3 0.7-3.5V @ 700mA -> ESP32 (keep this on!)
// LDO1 30mA -> GPS Backup
// LDO2 200mA -> LORA
// LDO3 200mA -> GPS

// Wiring for I2C OLED display:
//
// Signal     Header   OLED
// 3V3         7       VCC
// GND         8       GND
// IO22(SCL)   9       SCL
// IO21(SDA)   10      SDA
//

*/
