#include "main.h"
void buffer_printer(char buffr[], int *buff);
/**
* _printf - This is a function that produces output according to a format
* @format: a character string composed of zero or more directives
* Return: the number of characters printed (excluding the null byte
* used to end output to strings)
*/
int _printf(const char *format, ...)
{
int s, pr = 0, pr_chs = 0;
int flags, width, precision, size, buff = 0;
va_list list;
char buffr[B_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (s = 0; format && format[s] != '\0'; s++)
{
if (format[s] != '%')
{
buffr[buff++] = format[s];
if (buff == B_SIZE)
buffer_printer(buffr, &buff);
/*write(1, &format[s], 1)*/
pr_chs++;
}
else
{
buffer_printer(buffr, &buff);
flags = get_flgs(format, &s);
width = get_wdth(format, &s, list);
precision = get_prcsn(format, &s, list);
size = get_sz(format, &s);
pr = hdle_prnt(format, &s, list, buffr,
flags, width, precision, size);
if (pr == -1)
return (-1);
pr_chs += pr;
}
}
buffer_printer(buffr, &buff);
va_end(list);
return (pr_chs);
}
/**
* buffer_printer - function that prints what's in the buffer if available
* @buffr: Array
* @buff: where to add the next char, length
*/
void buffer_printer(char buffr[], int *buff)
{
if (*buff > 0)
write(1, &buffr[0], *buff);
*buff = 0;
}
