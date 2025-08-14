#ifndef CONVERSION_H
#define CONVERSION_H

#define convert(str, func) (func(str))

static inline const char* skip_whitespace(const char* str);
static inline const char* check_sign(const char* str, char* neg);

static inline char to_byte(const char* str);
static inline short to_short(const char* str);
static inline int to_int(const char* str);
static inline long to_long(const char* str);
static inline long long to_long_long(const char* str);
static inline unsigned char to_ubyte(const char* str);
static inline unsigned short to_ushort(const char* str);
static inline unsigned int to_uint(const char* str);
static inline unsigned long to_ulong(const char* str);
static inline unsigned long long to_ulong_long(const char* str);

float to_float(const char* str);
double to_double(const char* str);

#endif
