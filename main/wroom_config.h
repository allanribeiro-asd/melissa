#ifndef WROOM_CONFIG_H
	#define WROOM_CONFIG_H

	#define BOARD_LED_0 GPIO_NUM_2

	// SDCARD pins. Remember to disconnect 13 when uploading
	#define SDCARD_MISO_PIN GPIO_NUM_12
	#define SDCARD_MOSI_PIN GPIO_NUM_13
	#define SDCARD_CLK_PIN GPIO_NUM_14
	#define SDCARD_CS_PIN GPIO_NUM_15

	#define I2C_SDA_PIN GPIO_NUM_21
	#define I2C_SCL_PIN GPIO_NUM_22

	#define B20_DATA_PIN GPIO_NUM_4
	
#endif
