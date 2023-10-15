#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1


/**
 * struct fmt - Struct op
 * @fmt: The format.
 * @fn: The func associated.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The func  associated.
 */

typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int ha_print(const char *fmt, int *i, va_list list,
		char buffer[], int flags, int width);

/**get flags**/
int g_flags(const char *format, int *i);

/**width**/
int g_width(const char *format, int *i, va_list list);

/**handler**/
int ha_write_char(char c, char buffer[], int flags,
		int width);
int write_nums(int is_positive, int ind, char buffer[],
int flags, int width);
int write_num(int ind, char bff[], int flags,
int width);
int write_ptr(char buffer[], int ind, int width,
int flags);
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width);

/**utils**/
int printable(char);
int hexa(char, char[], int);
int is_digit(char);
long int conv_sz_nums(long int num, int size);
long int conv_sz_unsgnd(unsigned long int num, int size);

#endif
