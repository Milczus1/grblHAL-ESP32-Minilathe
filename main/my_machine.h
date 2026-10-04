/*
  my_machine.h - Configuration for MKS DLC32 v2.1 Minilathe Setup
  Part of grblHAL
*/

#ifndef _MY_MACHINE_H_
#define _MY_MACHINE_H_

// --- Select Target Board ---
#define BOARD_MKS_DLC32_V2P0                // Enables MKS DLC32 v2.0 / v2.1

// --- ESP32 USB CDC Configuration ---
#if CONFIG_IDF_TARGET_ESP32S3
#define USB_SERIAL_CDC          0
#endif

// --- Network & Web Interface Options ---
#define WEBUI_ENABLE            3 // Enable ESP3D-WEBUI plugin
#define WIFI_ENABLE             1 // Enable Wi-Fi connection
#define SDCARD_ENABLE           1 // Enable SD Card support for G-code execution

#if WIFI_ENABLE || ETHERNET_ENABLE || WEBUI_ENABLE
#define TELNET_ENABLE         1
#if SDCARD_ENABLE || WEBUI_ENABLE
#define FTP_ENABLE            1
#endif

// Fix for unquoted hostname macro from PlatformIO command line flags:
#ifdef NETWORK_STA_HOSTNAME
#undef NETWORK_STA_HOSTNAME
#endif
#define NETWORK_STA_HOSTNAME    "grblHAL_lathe"

#endif

// --- Control Signals & Lathe Features ---
#define PROBE_ENABLE            1 // Enables Touch Probe input

#endif // _MY_MACHINE_H_