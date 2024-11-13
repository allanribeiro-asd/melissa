#ifndef UTILS_H
	#define UTILS_H

	#define WROOM 1
	#define LORA32 2

	#define CHK_NULL(ptr) { if(ptr == NULL){ free(ptr); return; } }
	#define CHK_BME (defined(BMP_0) || defined(BMP_1)) && (BMP_0 != 0 || BMP_1 != 0)
	#define CHK_SHT (defined(SHT_0) || defined(SHT_1)) && (SHT_0 != 0 || SHT_1 != 0)
	#define CHK_B20 defined(B20) && B20 != 0

#endif
