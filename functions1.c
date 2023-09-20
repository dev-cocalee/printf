#include "main.h"

/**
 * print_pointer - prints pointers
 * @args: variadic list
 * @flags: helps with needs
 * Return: len
*/
int print_pointer(va_list args, int flags)
{
uintptr_t ptr = (uintptr_t)va_arg(args, void*);
int len = 0;

/*don't forget about this*/
if (flags == 0)
len += 1;
write(1, "0x", 2);
len += 2;
len += print_hex_size_t(ptr);

return (len - 1);
}

/**
 * print_hex_size_t - to be used in the print hex function
 * @value: some value
 * Return: integer len
*/
int print_hex_size_t(uintptr_t value)
{
int len = 0, i = 0;
char hexDigits[] = "0123456789abcdef";
char *buf = malloc(17); /*For 64-bit address, adjust as needed*/

for ( ; i < 16; i++)
{
buf[16 - i] = hexDigits[(value >> (i * 4)) & 0xF];
}
buf[16] = '\0';

for (i = 0; i < 16; i++)
{
write(1, &buf[i], 1);
len++;
}
return (len);
}

/**
 * is_flag - hecks if argument is a flag
 * @c: char to be checked
 * Return: 0
*/
int is_flag(char c)
{
return (c == ' ' || c == '+' || c == '#');
}

/**
 * get_red_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_red_flags(const char *format, int *i)
{
int j, rand, flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {FLAG_PLUS, FLAG_SPACE, FLAG_HASH, FLAG_MINUS,
FLAG_ZERO, 0};

for (rand = *i + 1; format[rand] != '\0'; rand++)
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
if (format[rand] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}

if (FLAGS_CH[j] == 0)
break;
}

*i = rand - 1;

return (flags);
}

/**
 * handle_green_flags - handles flags
 * @format: format string
 * @start: the beginning, lol
 * @end: the end
 * Return: flags don't mind the green and red flags thng
*/
int handle_green_flags(const char *format, int start, int end)
{
int flags, i = start;
i = end, i = start;

flags = get_flags(format, &i);

/*Combine the flags using bitwise OR*/
if (flags & FLAG_HASH)
{flags |= FLAG_HASH; }
if (flags & FLAG_PLUS)
{flags |= FLAG_PLUS; }
if (flags & FLAG_SPACE)
{flags |= FLAG_SPACE; }

return (flags);
}

