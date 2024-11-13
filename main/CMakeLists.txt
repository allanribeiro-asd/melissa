idf_component_register(SRCS "melissa.c" "sdcard.c" "debug.c"
                    INCLUDE_DIRS "."
					REQUIRES esp-idf-bmx280
					REQUIRES sht30
					REQUIRES fatfs
					REQUIRES esp32-ds18b20  
					REQUIRES esp32-owb

)
