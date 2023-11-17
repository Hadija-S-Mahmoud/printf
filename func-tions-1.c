#include "main.h"
/********** PRINTING AN UNSIGNED NUMBER **********/

/**
 * pr_unsd - Function that prints an unsigned number
 * @t: A list of arguments
 * @buffr: Array of buffer to handle print
 * @flags: calculating the active flags
 * @width:width specifier
 * @precision: specifying the precision
 * @size: specification forsize
 * Return: Number of characters printed
 */
int pr_unsd(va_list t, char buffr[], int flags,
int width, int precision, int size)
{
	int g = B_SIZE - 2;
	unsigned long int nom = va_arg(t, unsigned long int);

	nom = cvt_sz_unsd(nom, size);

	if (nom == 0)
		buffr[g--] = '0';
	buffr[B_SIZE - 1] = '\0';

	while (nom > 0)
	{
		buffr[g--] = (nom % 10) + '0';
		nom /= 10;
	}

	g++;

	return (wrt_unsd(0, g, buffr, flags, width, precision, size));


}

/********** PRINTING AN UNSIGNED NUMBER THAT IS OCTAL **********/

/**
 * pr_octs - Function that prints an unsigned number that is octal
 * @t: A list of arguments
 * @buffr: Array of buffer
 * @flags: calculating the active flags
 * @width:width specifier
 * @precision: specifying the precision
 * @size: specification for size
 * Return: Number of characters printed
 */
int pr_octs(va_list t, char buffr[],
int flags, int width, int precision, int size)
{
	int v = B_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);
	unsigned long int int_num = num;

	UNUSD(width);

	num = cvt_sz_unsd(num, size);

	if (num == 0)
		buffr[v--] = '0';

	buffr[B_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffr[v--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_H && int_num != 0)
		buffr[v--] = '0';

	v++;
	return (wrt_unsd(0, v, buffr, flags, width, precision, size));

}

/*********** PRINT AN UNSIGNED NUMBER THAT IS IN HEXADECIMAL **********/

/**
 *pr_hexd - Function printing an unsigned number that is in hexadecimal
 * @t: A list of arguments
 * @buffr: Array of buffer
 * @flags: calculating the active flags
 * @width:width specifier
 * @precision: specifying the precision
 * @size: specification for size
 * Return: Number of characters printed
 */
int pr_hexd(va_list t, char buffr[],
int flags, int width, int precision, int size)
{
	return (pr_hex(t, "0123456789abcdef", buffr, flags,
'x', width, precision, size));
}

/***** PRINTING AN UNSIGNED NUMBER THAT IS IN UPPER HEXADECIMAL *****/

/**
 * pr_hexu - Function that prints an unsigned number
 * that is in upper hexadecimal
 * @t: A list of arguments
 * @buffr: Array of buffer
 * @flags: calculating the active flags
 * @width:width specifier
 * @precision: specifying the precision
 * @size: specification for size
 * Return: Number of characters printed
 */
int pr_hexu(va_list t, char buffr[],
int flags, int width, int precision, int size)
{
	return (pr_hex(t, "0123456789ABCDEF", buffr,
flags, 'X', width, precision, size));
}

/**** PRINTING HEXADECIMAL NUMBER IN LOWER OR UPPER NOTATION ****/

/**
 *pr_hex - Function that prints a hexadecimal number in
 *`lower and upper notation
 * @t: A list of arguments
 * @mp_to: Array of values to map the number to
 * @buffr: Array of buffer
 * @flags: calculating the active flags
 * @flg_ch: calculating the active flags
 * @width:width specifier
 * @precision: specifying the precision
 * @size: specification for size
 * Return: Number of characters printed
 */
int pr_hex(va_list t, char mp_to[], char buffr[],
int flags, char flg_ch, int width, int precision, int size)
{
	int u = B_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);
	unsigned long int i_num = num;

	UNUSD(width);

	num = cvt_sz_unsd(num, size);

	if (num == 0)
		buffr[u--] = '0';

	buffr[B_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffr[u--] = mp_to[num % 16];
		num /= 16;
	}

	if (flags & F_H && i_num != 0)
	{
		buffr[u--] = flg_ch;
		buffr[u--] = '0';
	}

	u++;
	return (wrt_unsd(0, u, buffr, flags, width, precision, size));

}
