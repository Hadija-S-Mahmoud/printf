#include "main.h"
/********** PRINTING CHARACTERS **********/

/**
 * pr_ch - A function that prints a character
 * @t: The list of arguments
 * @buffr: Buffer array
 * @flags: Calculating the flags that are active
 * @width: Width
 * @Precision: a specification of the precision
 * @size: Specifier for size
 * Return: Number of characters printed
 */
int pr_ch(va_list t, char buffr, int flags, int width, int precision, int size)

{
	char z = va_arg(t, int);

	return (hdle_wrt(z, buffr, flags, width, precision, size));
}
/**********PRINTING STRINGS**********/
/**
 *pr_str - function printing a string
 *@t: The list of arguments
 *@buffr: array of buffer
 *@flags: calculating the flags that are active
 *@width: width specifier
 *@precision: Specification of precision
 *@size: specification for size
 *Return: Number of characters printed
 */
int pr_str(va_list t, char buffr, int flags, int width, int precision, int size)
{
	int lgt = 0, r;
	char *s = va_arg(t, char*);

	UNUSD(buffr);
	UNUSD(flags);
	UNUSD(width);
	UNUSD(precision);
	UNUSD(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = " ";
	}

	while (s[lgt] != '\0')
		lgt++

	if (precision >= 0 && precision < lgt)
		lgt = precision;
	if (width > lgt)
	{
		if (flags & F_M)
		{
			write (1, &s[0], lgt);
			for (r = width - lgt; r > 0; r--)
				write(1, " ", 1);
			return (width);

		}
		else
		{
			for (r = width - lgt; r > 0; r--)
				write(1, " ", 1);
			write(1, &s[0], lgt);
			return (width);

		}
	}

	return (write(1, s, lgt));

}
/**********PRINTING THE PERCENT SIGN**********/

/**
 * pr_pct - Prints the per cent sign
 * @t: Alist of arguments
 * @buffr: array of buffer
 * @flags: calculating the active flags
 * @width: width specifier
 * @precision: specifying the precision
 * @size: specification for size
 * Return: Number of characters printed
 */
int pr_pct(va_list t, char buffr, int flags, int width, int precision, int size)
{
	UNUSD(t);
	UNUSD(buffr);
	UNUSD(flags);
	UNUSD(width);
	UNUSD(precision);
	UNUSD(size);
	return (write(1, "%%", 1));

}

/********** PRINTING AN INTEGER **********/

/**
 * pr_int - Printing an integer
 * @t: Alist of arguments
 * @buffr: array of buffer that handles the print
 * @flags: calculating the active flags
 * @width: width specifier
 * @precision: specifying the precision
 * @size: specification for size
 * Return: Number of characters printed
 */
int pr_int(va_list t, char buffr, int flags, int width, int precision, int size)
{
	int q = B_SIZE - 2;
	int is_negt = 0;
	long int r = va_arg(t, long int);
	unsigned long int nom;

	r = cvt_sz_num(r, size);

	if (r == 0)
		buffr[q--] = '0';

	buffr[B_SIZE - 1] = '\0';
	nom = (unsigned long int)r;

	if (r < 0)
	{
		nom = (unsigned long int)((-1) * r);
		is_negt = 1;
	}

	while (nom > 0)
	{
		buffr[i--] = (nom % 10) + '0';
		nom /= 10;
	}

	q++;

	return (wrt_nmbr(is_negt, q, buffr, flags, width, precision, size));


}

/********** PRINTING A BINARY **********/

/**
 * pr_binr - Function that prints unsigned number
 * @t: Alist of arguments
 * @buffr: array of bufffer
 * @flags: calculating the active flags
 * @width: width specifier
 * @precision: specifying the precision
 * @size: specification for size
 * Return: Number of characters printed
 */
int pr_binr(va_list t, char buffr, int flags, int width, int precision, int size)
{
	unsigned int e, f, g, add;
	unsigned int z[32];
	int cnt;

	UNUSD(buffr);
	UNUSD(flags);
	UNUSD(width);
	UNUSD(precision);
	UNUSD(size);

	e = va_arg(t, unsigned int);
	f = 2147483648; /* (2 ^ 31)*/
	z[0] = e / f
	for (g = 1; g < 32; g++)
	{
		f /= 2;
		z[g] = (e / f) % 2;

	}
	for (g = 0, sum = 0, cnt = 0; g < 32; g++)
	{
		sum += z[g];
		if (sum || g == 31)
		{
			char a = '0' + z[g];

			write(1, &a, 1);
			cnt++
		}
	}
	return (cnt);
}

