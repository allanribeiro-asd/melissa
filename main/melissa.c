/* System libraries */
#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <esp_log.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/* User libraries */
#include "errors.h"
#include "config.h"
#include "debug.h"
#include "utils.h"

#include "sdcard.h"

err_t main_init(void)
{
	const char * TAG = "main_init()";

	err_t error = ERR_OK;

	mdprintf("%s: Initializing\n", TAG);

	mdprintf("%s: ...\n", TAG);
	sleep(1);
	mdprintf("%s: ..\n", TAG);
	sleep(1);
	mdprintf("%s: .\n", TAG);
	sleep(1);

	#if defined(DISABLE_STDOUT_BUFFERING) && DISABLE_STDOUT_BUFFERING != 0
		#pragma message "STDOUT buffer is off."
		 setvbuf(stdout, NULL, _IONBF, 0); // Disable stdout buffering
	#endif


	// Type init here
	//
	mdprintf("%s: Exit error code is %d\n", *TAG, error);

	return error;
}

err_t main_deinit(void)
{
	const char * TAG = "main_deinit()";

	err_t error = ERR_OK;

	mdprintf("%s: Exiting\n", TAG);

	mdprintf("%s: ...\n", TAG);
	sleep(1);
	mdprintf("%s: ..\n", TAG);
	sleep(1);
	mdprintf("%s: .\n", TAG);
	sleep(1);

	// Type init here
	mdprintf("%s: Exit error code is %d\n", *TAG, error);

	return error;
}

void app_main()
{
	static const char *TAG = "app_main()";

	err_t error = ERR_OK;

	mdprintf("%s: Intializing\n", TAG);

	// Initialization
	main_init();
	sdcard_init();
	//sensors_init();
	//bluetooth_init();
	//serial_init();


	// TODO: discover how to put ESP in sleep mode
	
	mdprintf("%s: Exit error code is %d\n", TAG, error);

	main_deinit();
}
