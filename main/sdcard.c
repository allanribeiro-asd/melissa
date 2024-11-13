#include "sdcard.h"

#define FORMAT_IF_MOUNT_FAILED 1

FILE * write_file(const char * file, const char * fmt, ...)
{
	static const char *TAG = "open_file()";


	FILE * f = NULL;

	#if defined(USE_SDCARD) && USE_SDCARD != 0
		f = fopen(file, "a");

		if(f != NULL)
		{
			mdprintf("%s: File opened\n", TAG, file);

			// Initialize the va_list to handle the variable arguments
			va_list args;
			va_start(args, fmt);

			fprintf(f, fmt, args);
			fclose(f);

			va_end(args);

			mdprintf("%s: File written\n", TAG);
		}
		else
		{
			mdprintf("%s: Error opening file\n", TAG);
		}
	#else
		mdprintf("%s: SDCARD is disabled", TAG);
	#endif

	return f;
}

err_t sdcard_init(void)
{
	static const char *TAG = "sdcard_init()";

	err_t error = ERR_OK;

	#if defined(USE_SDCARD) && USE_SDCARD != 0

		mdprintf("%s: Initializing\n", TAG);

		// If format_if_mount_failed true, SD is formated in case mounting fails.
		esp_vfs_fat_sdmmc_mount_config_t mount_config =
		{
			#ifdef FORMAT_IF_MOUNT_FAILED
				.format_if_mount_failed = true,
			#else
				.format_if_mount_failed = false,
			#endif // FORMAT_IF_MOUNT_FAILED
			.max_files = 10,
			.allocation_unit_size = 16 * 1024
		};
		sdmmc_card_t *card;
		const char mount_point[] = MOUNT_POINT;

		// Note: esp_vfs_fat_sdmmc/sdspi_mount is all-in-one convenience functions.
		mdprintf("%s: Using SPI peripheral\n", TAG);

		sdmmc_host_t host = SDSPI_HOST_DEFAULT();

		#if DEVICE == WROOM
			//host.max_freq_khz = 10000;
		#endif

		spi_bus_config_t bus_cfg = {
			.mosi_io_num = SDCARD_MOSI_PIN,
			.miso_io_num = SDCARD_MISO_PIN,
			.sclk_io_num = SDCARD_CLK_PIN,
			.quadwp_io_num = -1,
			.quadhd_io_num = -1,
			.max_transfer_sz = 4000,
		};
		int ret = spi_bus_initialize(host.slot, &bus_cfg, SDSPI_DEFAULT_DMA);
		if (ret != ESP_OK) {
			meprintf("%s: Failed to initialize bus\n", TAG);
			return ret;
		}

		// This initializes the slot without card detect (CD) and write protect (WP) signals.
		// Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
		sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
		slot_config.gpio_cs = SDCARD_CS_PIN;
		slot_config.host_id = host.slot;

		mdprintf("%s: Mounting filesystem\n", TAG);
		error = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);

		if (error != ESP_OK)
		{
			meprintf("%s: Failed to mount.\nTo format on fail, set FORMAT_IF_MOUNT_FAILED.\n", TAG);
			meprintf("%s: Make sure SD card lines have pull-up resistors in place.\n", TAG);
		}

		mdprintf("%s: Filesystem mounted\n", TAG);

		// Card has been initialized, print its properties
		if(error)
		{
			meprintf("%s: Exit error code is %d\n", TAG, error);
		}
		else
		{
			sdmmc_card_print_info(stdout, card);
			open_file(SDCARD_TEST_FILENAME);
			open_file(SDCARD_TEST_FILENAME);
		}

	#endif

	return error;
}

