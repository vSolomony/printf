#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/*The Size*/
#define S_SHORT 1
#define S_LONG 2
/*The Flag*/
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define F_MINUS 1
#define F_PLUS 2
/**
 * struct frmt - struct
 * @frmt: form
 * @fun: fun
 */
struct frmt
{
	char frmt;
	int (*fun)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct frmt frmt_t - struct
 * @frmt: form
 * @frmt_t: fun
 */
typedef struct frmt frmt_t;

int hdle_prnt(const char *frmt, int *i,
va_list list, int precision, int flags, int size, char buffer[], int width);

/********** ALLLLL FUNCTIOOOOONS ***********/
/*fun of char and str*/
int prnt_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* fun of num */
int prnt_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_octa(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_hexadec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_hexaup(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prnt_hexa(va_list types, char mp_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
/* fun of non prnt char */
int prnt_non_prntable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* fun of mem adds. */
int prnt_ptr(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* fun of other spec. */
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
/* fun of rev */
int prnt_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* fun of rev rot 13 */
int prnt_rot13str(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* fun of width */
int wt_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int handle_wt_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int wt_ptr(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int wt_number(int is_post, int ind, char buffer[],
	int flags, int width, int precision, int size);
int wt_unsgnd(int is_negt, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/* utilitsss. */
int is_digt(char);
int is_prntable(char);
int app_hexa_code(char, char[], int);

long int conv_size_unsgnd(unsigned long int num, int size);
long int conv_size_number(long int num, int size);

#endif
