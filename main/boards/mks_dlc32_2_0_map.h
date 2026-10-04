/*
  mks_dlc32_2_0_map.h - Board map file for MKS DLC32 v2.0 / v2.1 (Minilathe Configuration)
  Part of grblHAL
*/

#if VFD_SPINDLE
#error "Board BOARD_MKS_DLC32_V2P0 does not have support for VFD spindle."
#endif

#include "use_i2s_out.h"

#define BOARD_NAME "MKS DLC32 2.x (Lathe)"
#define BOARD_URL "https://github.com/makerbase-mks/MKS-DLC32"

#define AUX_CONTROLS_OUT

#ifdef ADD_SERIAL1
#define SERIAL1_PORT
#define UART1_RX_PIN        GPIO_NUM_18
#define UART1_TX_PIN        GPIO_NUM_19
#endif

#if SDCARD_ENABLE

// Pin mapping when using SPI mode.
#define SPI_MISO_PIN        GPIO_NUM_12
#define SPI_MOSI_PIN        GPIO_NUM_13
#define SPI_SCK_PIN         GPIO_NUM_14
#define SD_CS_PIN           GPIO_NUM_15
#define SD_DETECT_PIN       GPIO_NUM_39

#endif // SDCARD_ENABLE

#define I2S_OUT_BCK         GPIO_NUM_16
#define I2S_OUT_WS          GPIO_NUM_17
#define I2S_OUT_DATA        GPIO_NUM_21

// --- Axis Motor Pins ---
#define X_STEP_PIN          I2SO(1)
#define X_DIRECTION_PIN     I2SO(2)
#define X_LIMIT_PIN         GPIO_NUM_36

#define Y_STEP_PIN          I2SO(5)
#define Y_DIRECTION_PIN     I2SO(6)
#define Y_LIMIT_PIN         GPIO_NUM_35 // Reused for Spindle Pulse / RPM Sensor

#define Z_STEP_PIN          I2SO(3)
#define Z_DIRECTION_PIN     I2SO(4)
#define Z_LIMIT_PIN         GPIO_NUM_34

#define STEPPERS_ENABLE_PIN I2SO(0)

#if N_ABC_MOTORS >= 1
#error "Board BOARD_MKS_DLC32_V2P0 does not have support for ABC Motors"
#endif

// --- Auxiliary Output Definitions ---
#define AUXOUTPUT0_PIN          GPIO_NUM_25 // EXP_1,7
#if PWM_SERVO_ENABLE || (SPINDLE_ENABLE & ((1<<SPINDLE_PWM2)|(1<<SPINDLE_PWM2_NODIR)))
#define AUXOUTPUT0_PWM_PIN      GPIO_NUM_26 // EXP_1,5
#else
#define AUXOUTPUT1_PIN          GPIO_NUM_26 // EXP_1,5
#endif
#define AUXOUTPUT2_PIN          GPIO_NUM_27 // Spindle Enable Signal / Relay
#define AUXOUTPUT3_PIN          GPIO_NUM_32 // Spindle PWM Signal Output
#define AUXOUTPUT4_PIN          GPIO_NUM_5  // EXP_1,3

// --- Spindle Pin Definitions ---
// Spindle PWM -> GPIO 32 (Spindle Header / LC)
// Spindle Enable -> GPIO 27 (Laser/Relay Header)
// Spindle Direction -> GPIO 26 (AUX Output 1 / EXP_1,5)
#define SPINDLE_PWM_PIN         AUXOUTPUT3_PIN
#define SPINDLE_ENABLE_PIN      AUXOUTPUT2_PIN
#define SPINDLE_DIRECTION_PIN   AUXOUTPUT1_PIN

// --- Spindle Pulse / RPM Index Sensor ---
#define SPINDLE_PULSE_PIN       Y_LIMIT_PIN // GPIO 35

// --- Coolant Pin Definitions ---
#if COOLANT_ENABLE & COOLANT_FLOOD
#define COOLANT_FLOOD_PIN   AUXOUTPUT4_PIN
#endif
#if COOLANT_ENABLE & COOLANT_MIST
#define COOLANT_MIST_PIN    I2SO(7)     // Beeper
#endif

// --- Auxiliary Input & Probe Definitions ---
#define AUXINPUT0_PIN       GPIO_NUM_33 // EXP_1,8
#define AUXINPUT1_PIN       GPIO_NUM_22 // Dedicated Probe Pin (SCL / Probe Header)
#if !I2C_ENABLE
#define AUXINPUT2_PIN       GPIO_NUM_4  // Cycle start (I2C_SCL Header)
#endif

// Define user control input pins
#if (CONTROL_ENABLE & CONTROL_CYCLE_START) && defined(AUXINPUT2_PIN)
#define CYCLE_START_PIN         AUXINPUT2_PIN
#endif

// Define probe switch input pin
#if PROBE_ENABLE && !defined(PROBE_PIN)
#define PROBE_PIN           AUXINPUT1_PIN // GPIO 22
#endif

#if I2C_ENABLE
// Define I2C port/pins
#define I2C_PORT            I2C_NUM_1
#define I2C_SDA             GPIO_NUM_0
#define I2C_SCL             GPIO_NUM_4
#define I2C_CLOCK           100000
#endif

#if MPG_ENABLE == 1
#define MPG_MODE_PIN            AUXINPUT0_PIN
#endif