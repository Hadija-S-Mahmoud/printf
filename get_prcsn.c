#include "main.h"
/**
* get_prcsn - function that calculates the precision for the printing
* @p: list
* @l: list
* @fomt: the formatted strimg
* Return: the precision
*/
int get_prcsn(const char *fomt, int *p, va_list l)
{
int cr_i = *p + 1;
int prcsn = -1;
if (fomt[cr_i] != '.')
return (prcsn);
prcsn = 0;
for (cr_i += 1; fomt[cr_i] != '\0'; cr_i++)
{
if (is_dgt(fomt[cr_i]))
{
prcsn *= 10;
prcsn += fomt[cr_i] - '\0';
}
else if (fomt[cr_i] == '*')
{
cr_i++;
prcsn = va_arg(l, int);
break;
}
else
break;
}
*p = cr_i - 1;
return (prcsn);
}
