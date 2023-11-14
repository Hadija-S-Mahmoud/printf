#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#define UNUSED(x) (void)(x)
#define B_SIZE 1024
/*Flags*/
#define F_ZERO 4
#define F_SPACE 16
#define F_HASH 8
#define F_PLUS 2
#define F_MINUS 1
/*Sizes*/
#define S_LONG 2
#define S_SHORT 1
/**
* struct fomt - struct operator
* @fomt: the format
* @fun: the function to be executed
*/
struct fomt
{
char fomt;
int (*z)(va_list, char[], int, int, int, int);
};
int _printf(const char *format, ...);
void buffer_printer(char buffr[], int *buff);
int hdle_prnt(const char *format, ...);
/*Specifiers handlers*/
int get_flgs(const char *format, int *s);
int get_wdth(const char *format, int *s, va_list list);
int get_prcsn(const char *format, int *s, va_list list);
int get_sz(const char *format, int *s);
#endif
