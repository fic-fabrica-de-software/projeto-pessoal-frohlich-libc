#include "conversion.h"

static inline const char* skip_whitespace(const char* str) {
	const char* str_p = str;
loop:
	if (*str_p == 0x20 || *str_p == 0x09) {
		str_p++;
		goto loop;
	}

	return str_p;
}

static inline const char* check_sign(const char* str, char* neg) {
	const char* str_p = str;
	*neg = 0;
	
	if (*str_p == 0x2d) {
		*neg = 1;
		str_p++;
	} else if (*str_p == 0x2b) {
		str_p++;
	}
	
	return str_p;
}

char to_byte(const char* str) {
	const char* str_p = skip_whitespace(str);
	char x = 0;
	char neg;
	
	str_p = check_sign(str_p, &neg);
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return neg ? -x : x;
}

short to_short(const char* str) {
	const char* str_p = skip_whitespace(str);
	short x = 0;
	char neg;
	
	str_p = check_sign(str_p, &neg);
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return neg ? -x : x;
}

int to_int(const char* str) {
	const char* str_p = skip_whitespace(str);
	int x = 0;
	char neg;
	
	str_p = check_sign(str_p, &neg);
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return neg ? -x : x;
}

long to_long(const char* str) {
	const char* str_p = skip_whitespace(str);
	long x = 0;
	char neg;
	
	str_p = check_sign(str_p, &neg);
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return neg ? -x : x;
}

long long to_long_long(const char* str) {
	const char* str_p = skip_whitespace(str);
	long long x = 0;
	char neg;
	
	str_p = check_sign(str_p, &neg);
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return neg ? -x : x;
}

unsigned char to_ubyte(const char* str) {
	const char* str_p = skip_whitespace(str);
	unsigned char x = 0;
	
	if (*str_p == 0x2B) {
		str_p++;
	}
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return x;
}

unsigned short to_ushort(const char* str) {
	const char* str_p = skip_whitespace(str);
	unsigned short x = 0;
	
	if (*str_p == 0x2B) {
		str_p++;
	}
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return x;
}

unsigned int to_uint(const char* str) {
	const char* str_p = skip_whitespace(str);
	unsigned int x = 0;
	
	if (*str_p == 0x2B) {
		str_p++;
	}
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return x;
}

unsigned long to_ulong(const char* str) {
	const char* str_p = skip_whitespace(str);
	unsigned long x = 0;
	
	if (*str_p == 0x2B) {
		str_p++;
	}
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return x;
}

unsigned long long to_ulong_long(const char* str) {
	const char* str_p = skip_whitespace(str);
	unsigned long long x = 0;
	
	if (*str_p == 0x2B) {
		str_p++;
	}
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		x = x * 10 + (*str_p - 0x30);
		str_p++;
		goto loop;
	}

	return x;
}

float to_float(const char* str) {
	const char* str_p = skip_whitespace(str);
	float x = 0.0;
	float frac = 0.0;
	float div = 1.0;
	char neg;
	char in_frac = 0;
	
	str_p = check_sign(str_p, &neg);
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		if (in_frac) {
			div = div * 10.0;
			frac = frac * 10.0 + (*str_p - 0x30);
		} else {
			x = x * 10.0 + (*str_p - 0x30);
		}
		str_p++;
		goto loop;
	} else if (*str_p == 0x2E && !in_frac) {
		in_frac = 1;
		str_p++;
		goto loop;
	}

	x = x + frac / div;
	return neg ? -x : x;
}

double to_double(const char* str) {
	const char* str_p = skip_whitespace(str);
	double x = 0.0;
	double frac = 0.0;
	double div = 1.0;
	char neg;
	char in_frac = 0;
	
	str_p = check_sign(str_p, &neg);
	
loop:
	if (*str_p >= 0x30 && *str_p <= 0x39) {
		if (in_frac) {
			div = div * 10.0;
			frac = frac * 10.0 + (*str_p - 0x30);
		} else {
			x = x * 10.0 + (*str_p - 0x30);
		}
		str_p++;
		goto loop;
	} else if (*str_p == 0x2E && !in_frac) {
		in_frac = 1;
		str_p++;
		goto loop;
	}

	x = x + frac / div;
	return neg ? -x : x;
}

void* convert(const char* str, void* (*f)(const char*)) {
	return f(str);
}
