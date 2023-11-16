#include "main.h"
/**
* hdle_prnt - Function that prints arguments according to their type
* @fomt: Format
* @l: arguments list
* @h: index
* @buffr: array of the buffer that handles the print
* @flags: calculation of the flags that are active
* @width: specifier for width
* @precision: specifier for precision
* @size: the specifier for size
* Return: 1 or 2;
*/
int hdle_prnt(const char *fomt, int *h, va_list l, char buffr[],
int flags, int width, int precision, int size)
{
int k, uk_l = 0, pr_chs = -1;
fomt_f fomt_types[] = {
{'c', pr_ch}, {'s', pr_str}, {'%', pr_pct}, {'i', pr_int},
{'d', pr_int}, {'b', pr_binr}, {'u', pr_unsd}, {'o', pr_octs},
{'x', pr_hexd}, {'X', pr_hexu}, {'p', pr_pot}, {'S', pr_nprt},
{'r', pr_revs}, {'R', pr_rot}, {'\0', NULL}
};
for (k = 0; fomt_types[k].fomt != '\0'; k++)
if (fomt[*h] == fomt_types[k].fomt)
return (fomt_types[k].fun(l, buffr, flags, width, precision, size));
if (fomt_types[k].fomt == '\0')
{
if (fomt[*h] == '\0')
return (-1);
uk_l += write(1, "%%", 1);
if (fomt[*h - 1] == ' ')
uk_l += write(1, " ", 1);
else if (width)
{
--(*h);
while (fomt[*h] != ' ' && fomt[*h] != '%')
--(*h);
if (fomt[*h] == ' ')
--(*h);
return (1);
}
uk_l += write(1, &fomt[*h], 1);
return (uk_l);
}
return (pr_chs);
}
