#include "main.h"
/********** WRITE HANDLER **********/
/**
* hdle_wrt - Function that prints a string
* @wr: the character types
* @buffr: an array of buffer
* @width: width specifier
* @precision: precision specifier
* @flags: calculates the flags that are active
* @size: specification for size
* Return: the number of characters printed
*/
int hdle_wrt(char wr, char buffr[], int flags,
int width, int precision, int size)
{
int p = 0;
char pd = ' ';
UNUSD(precision);
UNUSD(size);
if (flags & F_Z)
pd = '0';
buffr[p++] = wr;
buffr[p] = '0';
if (width > 1)
{
buffr[B_SIZE - 1] = '\0';
for (p = 0; p < width - 1; p++)
buffr[B_SIZE - p - 2] = pd;
if (flags & F_M)
return (write(1, &buffr[0], 1) +
write(1, &buffr[B_SIZE - p - 1], width - 1));
else
return (write(1, &buffr[B_SIZE - p - 1], width - 1) +
write(1, &buffr[0], 1));
}
return (write(1, &buffr[0], 1));
}
/********** WRITING NUMBERS **********/
/**
* wrt_nmbr - Function that prints a string
* @is_negt: A list of the arguments
* @inx: the character types
* @buffr: array of bufffer
* @flags: calculating the flags tthat are active
* @precision: precision specifier
* @width: width specifier
* @size: specification for size
* Return: Number oof characters printed
*/
int wrt_nmbr(int is_negt, int inx, char buffr[],
int flags, int width, int precision, int size)
{
int lgt = B_SIZE - inx - 1;
char pd = ' ';
char ext_ch = 0;
UNUSD(size);
if ((flags & F_Z) && !(flags & F_M))
pd = '0';
if (is_negt)
ext_ch = '-';
else if (flags & F_P)
ext_ch = '+';
else if (flags & F_S)
ext_ch = ' ';
return (wrt_nom(inx, buffr, flags, width,
precision, lgt, pd, ext_ch));
}
/**
* wrt_nom - function that writes a number using a buffer
* @ext_char: an extra character
* @pd: The padding vcharacter
* @lgt: the length of the number
* @inx: the index at which the number begins on buffer
* @buffr: the buffer
* @flags: the flags
* @width: width specification
* @precision: the precision specifier
* Return: the number of printed characters
*/
int wrt_nom(int inx, char buffr[], int flags, int width,
int precision, int lgt, char pd, char ext_char)
{
int b = 1, pd_st = 1;
if (precision == 0 && inx == B_SIZE - 2 && buffr[inx] == '0'
&& width == 0)
return (0);
if (precision == 0 && inx == B_SIZE - 2 && buffr[inx] == '0')
buffr[inx] = pd = ' ';
if (precision > 0 && precision < lgt)
pd = ' ';
while (precision > lgt)
buffr[--inx] = '0', lgt++;
if (ext_char != 0)
lgt++;
if (width > lgt)
{
for (b = 1; b < width - lgt + 1; b++)
buffr[b] = pd;
buffr[b] = '\0';
if (flags & F_M && pd == ' ')
{
if (ext_char)
buffr[--inx] = ext_char;
return (write(1, &buffr[inx], lgt) + write(1, &buffr[1], b - 1));
}
else if (!(flags & F_M) && pd == ' ')
{
if (ext_char)
buffr[--inx] = ext_char;
return (write(1, &buffr[1], b - 1) + write(1, &buffr[inx], lgt));
}
else if (!(flags & F_M) && pd == '0')
{
if (ext_char)
buffr[--pd_st] = ext_char;
return (write(1, &buffr[pd_st], b - pd_st) +
write(1, &buffr[inx], lgt - (1 - pd_st)));
}
}
if (ext_char)
buffr[inx] = ext_char;
return (write(1, &buffr[inx], lgt));
}
/**
* wrt_unsd - Function that writes an unsigned number
* @is_negt: The number indicating if negative
* @buffr: the array of characters
* @inx: the index at which the number
* begins in the buffer
* @flags: flags
* @size: specification for size
* @precision: precision specifier
* @width: the width specifier
*
* @Return: the number of written characters
*/
int wrt_unsd(int is_negt, int inx, char buffr[], int flags,
int width, int precision, int size)
{
int lgt = B_SIZE - inx - 1;
int e = 0;
char pd = ' ';
UNUSD(is_negt);
UNUSD(size);
if (precision == 0 && inx == B_SIZE - 2 && buffr[inx] == '0')
return (0);
if (precision > 0 && precision < lgt)
pd = ' ';
while (precision > lgt)
{
buffr[--inx] = '0';
lgt++;
}
if ((flags & F_Z) && !(flags & F_M))
pd = '0';
if (width > lgt)
{
for (e = 0; e < width - lgt; e++)
buffr[e] = pd;
buffr[e] = '\0';
if (flags & F_M)
return (write(1, &buffr[inx], lgt) + write(1, &buffr[0], e));
}
else
{
return (write(1, &buffr[0], e) + write(1, &buffr[inx], lgt));
}
return (write(1, &buffr[inx], lgt));
}
/**
* wrt_pot - function that writes a memory address
* @pd_st: the index at which padding begins
* @ext_char: an extra character
* @pd: a character that represents the padding
* @flags: flags
* @width: the width specifier
* @lgt: the length of the number
* @inx: the index at which the number begins in the buffer
* @buffr: an array of characters
* @Return: number of written characters
*/
int wrt_pot(char buffr[], int inx, int lgt, int width,
int flags, char pd, char ext_char, int pd_st)
{
int o;
if (width > lgt)
{
for (o = 3; o < width - lgt + 3; o++)
buffr[o] = pd;
buffr[o] = '\0';
if (flags & F_M && pd == ' ')/* Assign exta character to buffer's left */
{
buffr[--inx] = 'x';
buffr[--inx] = '0';
if (ext_char)
buffr[--inx] = ext_char;
return (write(1, &buffr[inx], lgt) + write(1, &buffr[3], o - 3));
}
else if (!(flags & F_M) && pd == ' ')
{
buffr[--inx] = 'x';
buffr[--inx] = '0';
if (ext_char)
buffr[--inx] = ext_char;
return (write(1, &buffr[3], o - 3) + write(1, &buffr[inx], lgt));
}
else if (!(flags & F_M) && pd == '0')
{
if (ext_char)
buffr[--pd_st] = ext_char;
buffr[1] = '0';
buffr [2] = 'x';
return (write(1, &buffr[pd_st], o - pd_st) +
write(1, &buffr[inx], lgt - (1 - pd_st) - 2));
}
}
buffr[--inx] = 'x';
buffr[--inx] = '0';
if (ext_char)
buffr[--inx] = ext_char;
return (write(1, &buffr[inx], B_SIZE - inx - 1));
}
