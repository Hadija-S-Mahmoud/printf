#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#define UNUSD(x) (void)(x)
#define B_SIZE 1024
/* Flags */
#define F_Z 4
#define F_S 16
#define F_H 8
#define F_P 2
#define F_M 1
/* Size */
#define S_L 2
#define S_S 1
/**
* struct fomt - struct operator
* @fomt: the format
* @fun: the function to be executed
*/
struct fomt
{
char fomt;
int (*fun)(va_list, char[], int, int, int, int);
};
/**
* typdef struct fomt fomt_f - struct operator
* @fomt: the format
* @fomt_f: the function to be executed
*/
typedef struct fomt fomt_f;
int _printf(const char *format, ...);
int hdle_prnt(const char *fomt, int *h, va_list l,
char buffr[], int flags, int width, int precision, int size);
/********** FUNCTIONS USED **********/
/* Specifiers handlers */
int get_flgs(const char *fomt, int *f);
int get_wdth(const char *fomt, int *w, va_list l);
int get_prcsn(const char *fomt, int *p, va_list l);
int get_sz(const char *fomt, int *sz);
/* Those that print numbers */
int pr_int(va_list t, char buffr[], int flags,
int width, int precision, int size);
int pr_binr(va_list t, char buffr[], int flags,
int width, int precision, int size);
int pr_unsd(va_list t, char buffr[], int flags,
int width, int precision, int size);
int pr_octs(va_list t, char buffr[], int flags,
int width, int precision, int size);
int pr_hexd(va_list t, char buffr[], int flags,
int width, int precision, int size);
int pr_hexu(va_list t, char buffr[], int flags,
int width, int precision, int size);
int pr_hex(va_list t, char mp_to[], char buffr[], int flags,
char flg_ch, int width, int precision, int size);
/* Printing characters and strings */
int pr_ch(va_list t, char buffr[], int flags,
int width, int precision, int size);
int pr_str(va_list t, char buffr[], int flags,
int width, int precision, int size);
int pr_pct(va_list t, char buffr[], int flags,
int width, int precision, int size);
/* Printing to a string in rot 13 */
int pr_rot(va_list t, char buffr[], int flags,
int width, int precisin, int size);
/* Handling the width */
int wrt_unsd(int is_negt, int inx, char buffr[],
int flags, int width, int precision, int size);
int wrt_nom(int inx, char buffr[], int flags, int width,
int precision, int lgt, char pd, char ect_char);
int wrt_pot(char buffr[], int inx, int lgt, int width,
int flags, char pd, char ext_char, int pd_st);
int wrt_nmbr(int is_post, int inx, char buffr[],
int flags, int width, int precision, int size);
int hdle_wrt(char wr, char buffr[], int flags,
int width, int precision, int size);
/* Printing strings in reverse */
int pr_revs(va_list t, char buffr[], int flags,
int width, int precicion, int size);
/* Printing chars that are non-printable */
int pr_nprt(va_list t, char buffr[], int flags,
int width, int precision, int size);
/* Printing memory address */
int pr_pot(va_list t, char buffr[], int flags,
int width, int precision, int size);
/* UTILS */
int is_dgt(char);
int apnd_hex(char, char[], int);
int is_prntble(char);
long int cvt_sz_unsd(unsigned long int num, int size);
long int cvt_sz_num(long int num, int size);
#endif
