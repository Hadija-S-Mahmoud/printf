#include "main.h"
/**
* is_prntble - A function that does an evaluation check to check
* is a char is printable
* @d: A character that is checked in the evaluation
* Return: 1 if d is printable and 0 if it's not
*/
int is_prntble(char d)
{
if (d >= 32 && d < 127)
return (1);
return (0);
}
/**
* apnd_hex - A function that appends ascii in
* hexadecimal code to the buffer
* @buffr: An array of characters
* @inx: the index at whuch the appending begins
* @ascii_c: the ascii code
* Return: Always 3
*/
int apnd_hex(char ascii_c, char buffr[], int inx)
{
char mp_to[] = "0123456789ABCDEF";
if (ascii_c < 0)
ascii_c *= -1;
buffr[inx++] = '\\';
buffr[inx++] = 'x';
buffr[inx++] = mp_to[ascii_c / 16];
buffr[inx] = mp_to[ascii_c % 16];
return (3);
}
/**
*is_dgt - Function that verifies whether
* a character is a digit
* @d: The character to be evaluated
* Return: 1 if d is a digit, 0 if it's not
*/
int is_dgt(char d)
{
if (d >= '0' && d < '9')
return (1);
return (0);
}
/**
* cvt_sz_num - Function that casts a number to
* a size that is specified
* @num: The number to be casted
* @size: The number that is showing
* the type that is to be casted
* Return: The casted value of num
*/
long int cvt_sz_num(long int num, int size)
{
if (size == S_L)
return (num);
else if (size == S_S)
return ((short)num);
return ((int)num);
}
/**
* cvt_sz_unsd - Function that casts a number
* to a specified size
* @num: The number to be casted
* @size: the number showing thr type to be casted
* Return: The casted value of num
*/
long int cvt_sz_unsd(unsigned long int num, int size)
{
if (size == S_L)
return (num);
else if (size == S_S)
return ((unsigned short)num);
return ((unsigned int)num);
}
