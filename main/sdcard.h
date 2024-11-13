#ifndef SDCARD_H
	#define SDCARD_H

	#include <string.h>
	#include <sys/unistd.h>
	#include <sys/stat.h>

	#include "errors.h"
	#include "config.h"
	#include "debug.h"

	#include "esp_vfs_fat.h"
	#include "sdmmc_cmd.h"

	#if defined(USE_SDCARD) && USE_SDCARD != 0

		#pragma message "Using sdcard"

		#define SDCARD_TEST_FILENAME MOUNT_POINT"/TST.TXT"

		#ifndef SDCARD_MISO_PIN
			#error "SDCARD_MISO_PIN not defined"
		#endif
		#ifndef SDCARD_MOSI_PIN
			#error "SDCARD_MOSI_PIN not defined"
		#endif
		#ifndef SDCARD_CLK_PIN
			#error "SDCARD_CLK_PIN not defined"
		#endif
		#ifndef SDCARD_CS_PIN
			#error "SDCARD_CS_PIN not defined"
		#endif

	#else // defined(USE_SDCARD) && USE_SDCARD != 0

		#pragma message "Not using sdcard"

	#endif // defined(USE_SDCARD) && USE_SDCARD != 0

	FILE * open_file(const char * file);
	err_t sdcard_init(void);

#endif
