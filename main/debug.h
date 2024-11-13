#ifndef DEBUG_H
	#define DEBUG_H

	#include <stdio.h>
	#include <stdarg.h>

	#include "config.h"

	#define NONE    0  // Print nothing
	#define ERROR   1  // Print errors
	#define WARNING 2  // Print warnings
	#define INFO    3  // Print interesting infos
	#define DEBUG   4  // Print debug info

	#if (defined(USE_DEBUG) && USE_DEBUG != 0)
		#pragma message("DEBUG is on")

		#ifndef DEBUG_LEVEL
			#define DEBUG_LEVEL ERROR  // Default debug level
		#endif // DEBUG_LEVEL

		#pragma message "Current debug level is"

	#else // USE_DEBUG
		#pragma message "DEBUG is off"
	#endif

	// Define empty macros when debug is off
	int mdprintf(const char *fmt, ...);
	int meprintf(const char *fmt, ...);
	int mwprintf(const char *fmt, ...);
	int miprintf(const char *fmt, ...);
#endif // DEBUG_H

