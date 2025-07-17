#ifndef CONVERSION_H
#define CONVERSION_H

#define convert(str, func) (func(str))

static inline const char* skip_whitespace(const char* str);
static inline const char* check_sign(const char* str, char* neg);

char to_byte(const char* str);
short to_short(const char* str);
int to_int(const char* str);
long to_long(const char* str);
long long to_long_long(const char* str);
unsigned char to_ubyte(const char* str);
unsigned short to_ushort(const char* str);
unsigned int to_uint(const char* str);
unsigned long to_ulong(const char* str);
unsigned long long to_ulong_long(const char* str);

float to_float(const char* str);
double to_double(const char* str);

#endif
