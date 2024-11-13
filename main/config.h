#ifndef CONFIG_H
	#define CONFIG_H
	#define DEVICE LORA32 // Which esp are we using

	#define USE_DEBUG 1 // Switch debug

	#ifdef DEBUG_LEVEL // Use non default debug level
		#undef DEBUG_LEVEL
	#endif
	#define DEBUG_LEVEL DEBUG // Desired debug level [0-4]

	#define BLINK_GPIO BOARD_LED_0

	#define CONFIG_CONNECTION_TIMEOUT 5

	#define I2C 1

	#define USE_SDCARD 1
	#define MOUNT_POINT "/sdcard"
	#define TEST_SDCARD 1

	#define DISABLE_STDOUT_BUFFERING 1 // Disable stdout buffer to prevent errors

	#define BMP_0 0
	#define BMP_0_FILENAME MOUNT_POINT"/BM0.TXT"

	#define BMP_1 0
	#define BMP_1_FILENAME MOUNT_POINT"/BM1.TXT"

	#define SHT_0 0
	#define SHT_0_FILENAME MOUNT_POINT"/SH0.TXT"

	#define SHT_1 0
	#define SHT_1_FILENAME MOUNT_POINT"/SH1.TXT"

	#define B20 1
	#define B20_0_FILENAME MOUNT_POUNT"/B20.TXT"
	#define B20_1_FILENAME MOUNT_POUNT"/B21.TXT"

	#if defined(DEVICE)
		#if DEVICE == WROOM
			#include "wroom_config.h"
		#elif DEVICE == LORA32
			#include "lora32_config.h"
		#endif
	#else
		#error "DEVICE not defined. DEVICE must be either WROOM or LORA32"
	#endif

#endif
