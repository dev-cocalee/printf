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

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    _printf("Unknown:[%r]\n");
    return (0);
}
