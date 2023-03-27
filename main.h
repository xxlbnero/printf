#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>	/* printf, etc*/
#include <limits.h>	/* INT_MAX, etc */
#include <stdlib.h>	/* malloc() */
#include <unistd.h>	/* write() */
#include <stdarg.h>	/* variadic function */


int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size);
int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c);
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);


#endif /* MAIN_H */


