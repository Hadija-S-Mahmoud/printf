include "main.h"
/**
* get_flgs - function that calculates the flags that are active
* @f: param
* fomt: format
* Return: flags from the function
*/
int get_flgs(const char *fomt, int *f)
{
/* - + 0 # ' ' */
/* 1 2 4 8 16 */
int o, cr_i;
int flgs = 0;
const char FLGS_C[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLGS_A[] = {F_MINUS, F_PLUS, F_HASH, F_SPACE, F_ZERO, 0};
for (cr_i = *f + 1; fomt[cr_i] != '\0'; cr_i++)
{
for (o = 0; FLGS_C[o] != '\0'; o++)
if (fomt[cr_i] == FLGS_C[o])
{
flags |= FLGS_A[o];
break;
}
if (FLGS_C[o] == 0)
break;
}
*f = cr_i - 1;
return (flags);
}
