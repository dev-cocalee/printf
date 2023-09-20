#include "main.h"

/**
 * _printf - custom printf
 * @format: variadic argument
 * Return: number of characters printed to stdout
*/
int _printf(const char *format, ...)
{
va_list args;
int counter = 0, i, flags = 0, start, end;
int (*spec_ptr)(va_list, int);

va_start(args, format);
if (format == NULL)
return (0);
for (i = 0; format && format[i]; i++)
{
if (format[i] == '%')
{
if (format[i + 1] == '\0')
continue;
start = i + 1, end = start;
while (format[end] && is_flag(format[end]))
end++;
flags = handle_green_flags(format, start, end);
spec_ptr = spec(format[i + 1]);
if (spec_ptr != NULL)
counter += spec_ptr(args, flags), i++;
else
{write(1, &format[i], 1), counter++; }}
else
write(1, &format[i], 1), counter++;
}
va_end(args);
return (counter); }
