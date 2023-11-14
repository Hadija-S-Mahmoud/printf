#include "main.h"
/**
* get_wdth - function that get the width for printing
* @fomt: string that is formatted
* @w: the argument list to be printed
* @l: the list of arguments
* Return: the width for printing
*/
int get_wdth(const char *fomt, int *w, va_list l)
{
int wdth = 0;
int cr_i;
for (cr_i = *w + 1; fomt[cr_1] != '\0'; cr_i++)
{
if (is_dgt(fomt[cr_i]))
{
wdth *= 10;
wdth += fomt[cr_i] - '0';
}
else if (fomt[cr_i] == '*')
{
cr_i++;
wdth = va_arg(l, int);
break;
}
else
break;
}
*w = cr_i - 1;
return (wdth);
}
