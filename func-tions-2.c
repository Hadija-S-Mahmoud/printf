#include "main.h"
/********** PRINTING A POINTER **********/

/**
 * pr_pot - Function that prints the value of a pointer
 * @t:list of arguments
 * @buffr: array of buffer
 * @flags: calculating the flags that are active
 * @width: width specifier
 * @precision: specifying the precision
 * @size:specification for size
 * Return: Number of characters printed.
 */
int pr_pot(va_list t, char buffr, int flags, int width, int precision)
{
	char ext_char = 0, pd = '';
	int inx = B_SIZE - 2, lgt = 2, pd_st = 1;
	unsigned long num_ads;
	char mp_to = "0123456789abcdef";
	void *ads = va_arg(t, void *);

	UNUSD(width);
	UNUSD(size);

	if (ads == NULL)
		return (write(1, "(nil)", 5));
	buffr[B_SIZE - 1] = '\0';
	UNUSD(precision);

	num_ads = (unsigned long)ads;

	while (num_ads > 0)
	{
		buffr[inx--] = mo_to[num_ads % 16];
		num_ads /= 16;
		lgt++
	}

	if ((flags & F_Z) && !(flags & F_M))
		pd = '0';
	if (flags & F_P)
		ext_char = '+', lgt++;
	else if (flags & F_S)
		ext_chart = '', lgt++;

	inx++;

	return (wrt_pot(buffr, inx, lgt, width, flags, pd, ext_char, pd_st));
}

/*********** PRINTING NON-PRINTABLE CHARACTERS **********/

/**
 * pr_nprt - Function that prints ascii codes in hex or non-printable characters
 * @t:list of arguments
 * @buffr: array of buffer
 * @flags: calculating the flags that are active
 * @width: width specifier
 * @precision: specifying the precision
 * @size:specification for size
 * Return: Number of characters printed.
 */
int pr_nprt(va_list t, char buffr, int flags, int width, int precision, int size)
{
	int y = 0, offs = 0;
	char *strg = va_arg(t, char *);

	UNUSD(flags);
	UNUSD(width);
	UNUSD(precision);
	UNUSD(size);

	if (strg == NULL)
		return (write(1, "(null)", 6));
	while (strg[y] != '\0')
	{
		if (is_prntble(strg[y]))
			buffr[y + offs] = strg[y];
		else
			offs += apnd_hex(strg[y], buffr, y + offs);

		y++;
	}

	buffr[y + offs] = '\0';

	return (write(1, buffr, y + offs));
}

/********** PRINTING IN REVERSE **********/

/**
 * pr_revs - Functions that prints a string in reverse
 * @t:list of arguments
 * @buffr: array of buffer
 * @flags: calculating the flags that are active
 * @width: width specifier
 * @precision: specifying the precision
 * @size:specification for size
 * Return: Number of characters printed.
 */
int pr_revs(va_list t, char buffr, int flags, int width, int precision, int size)
{
	char *strg;
	int i, cnt = 0;

	UNUSD(buffr);
	UNUSD(flags);
	UNUSD(width);
	UNUSD(size);

	strg = va_arg(t, char *);

	if (strg == NULL)
	{
		UNUSD(precision);

		strg = ("null");
	}
	for (i = 0; strg[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char l = strg[i];

		write(1, &l, 1);
		cnt++;
	}
	retur n(cnt);
}

/********** PRINTING A STRING IN ROT **********/

/**
 * pr_rot - Function that prints a string in rot 13
 * @t:list of arguments
 * @buffr: array of buffer
 * @flags: calculating the flags that are active
 * @width: width specifier
 * @precision: specifying the precision
 * @size:specification for size
 * Return: Number of characters printed.
 */
int pr_rot(va_list t, char buffr, int flags, int width, int precision, int size)
{
	char x;
	char *strg;
	unsigned int m, n;
	int cnt = 0;
	char in = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strg = va_arg(t, char *);
	UNUSD(buffr);
	UNUSD(flags);
	UNUSD(width);
	UNUSD(precision);
	UNUSD(size);

	if (strg == NULL)
		strg = "(AHYY)";
	for (m = 0; strg[m]; m++)
	{
		for (n = 0; in[n]; n++)
		{
			if (in[n] == strg[m])
			{
				x = out[n];
				write(1, &x, 1);
				cnt++;
				break;
			}
		}
		if (!n[n])
		{
			x = strg[m];
			write(1, &x, 1);
			cnt++
		}
	}
	return (cnt);
}





























