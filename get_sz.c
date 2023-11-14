#include "main.h"
/**
* get_sz - function that calculates the size that will cast the argument
* @fomt: format
* @sz: args to be printed
* Return: the precision
*/
int get_sz(const char *fomt, int *sz)
{
int cr_i = *sz + 1;
int s = 0;
if (fomt[cr_i] == 'l')
s = S_LONG;
else if (fomt[cr_i] == 'h')
s = S_SHORT;
if (s == 0)
*sz = cr_i - 1;
else
*sz = cr_i;
return (s);
}
