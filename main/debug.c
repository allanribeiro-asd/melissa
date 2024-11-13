#define USE_DEBUG 1
#include "debug.h"

int meprintf(const char *restrict fmt, ...)
{
	#if (defined(USE_DEBUG) && USE_DEBUG != 0) && DEBUG_LEVEL >= ERROR
		va_list args;
		va_start (args, fmt);

		// Call the standard printf function with the variable arguments
		return fprintf(stdout, fmt, args);
	#else
		return 0;
	#endif
}

int mdprintf(const char *fmt, ...)
{
	#if (defined(USE_DEBUG) && USE_DEBUG != 0) && (DEBUG_LEVEL >= DEBUG)
		va_list args;
		va_start (args, fmt);

		// Call the standard printf function with the variable arguments
		return fprintf(stdout, fmt, args);
	#else
		return 0;
	#endif
}

int mwprintf(const char *fmt, ...)
{
	#if (defined(USE_DEBUG) && USE_DEBUG != 0) && DEBUG_LEVEL >= WARNING
		va_list args;
		va_start (args, fmt);

		// Call the standard printf function with the variable arguments
		return fprintf(stdout, fmt, args);
	#else
		return 0;
	#endif
}

int miprintf(const char *fmt, ...)
{
	#if (defined(USE_DEBUG) && USE_DEBUG != 0) && (DEBUG_LEVEL >= INFO)
		va_list args;
		va_start (args, fmt);

		// Call the standard printf function with the variable arguments
		return fprintf(stdout, fmt, args);
	#else
		return 0;
	#endif
}
