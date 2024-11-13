#ifndef ERRORS_H
	#include "stdint.h"

	typedef uint8_t err_t;

	// Error codes
	#define ERR_OK ESP_OK
	#define ERR_SDCARD 1
	#define ERR_BMP_0 2
	#define ERR_SHT_0 3
	#define ERR_BMP_1 4
	#define ERR_SHT_1 5
	#define ERR_READ 6
	#define ERR_NULL_PTR 7

	#ifndef USE_SDCARD
		#define ERR_NO_SDLIB 20
	#endif



#endif
