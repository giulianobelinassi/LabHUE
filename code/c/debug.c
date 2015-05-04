#include <stdio.h>
#include <stdarg.h>
#include "debug.h"

void debug_message(const char* format, ...)
{
	static FILE* fd = NULL;

	va_list arglist;
	va_start(arglist, format);

	if (!fd)
		fd = fopen("logfile.txt", "w");
		
	vfprintf(fd, format, arglist);

	
	va_end(arglist);
}


