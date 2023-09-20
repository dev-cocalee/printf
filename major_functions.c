#include "main.h"

/**
 * print_int - converts argument number to int, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_int(va_list args, int flags)
{
long int number = va_arg(args, long int);
int count = 0, temp, len, i;
char *buf;

if (number < 0)
{write(1, "-", 1), count++;
number = -number; }

temp = number, len = 0;

temp = flags, flags = number, temp = number;

if (number == 0)
write(1, "0", 1), count++;

while (temp > 0)
{temp /= 10, len++; }

buf = (char *)malloc(len);
if (buf == NULL)
return (0);

for (i = len - 1; i >= 0; i--)
{buf[i] = number % 10 + '0';
number /= 10; }
write(1, buf, len);
count += len;

free(buf);
return (count);
}

/**
 * print_uint - converts argument number to uint, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return:  number of characters written to stdout
*/
int print_uint(va_list args, int flags)
{
unsigned int number = va_arg(args, unsigned int);
int count = 0, index = 0, i;
char *buf = malloc(32); /*Maximum 32-bit decimal representation*/

if (buf == NULL)
return (0);

if (number == 0)
{
write(1, "0", 1);
return (1);
}

while (number > 0)
{
buf[index++] = number % 10 + '0';
number /= 10;
}
if (flags == 0)
i = 1;

for (i = index - 1; i >= 0; i--)
{
write(1, &buf[i], 1);
count++;
}

free(buf);
return (count);
}


/**
 * print_octal - converts argument number to octal, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_octal(va_list args, int flags)
{
unsigned int number = va_arg(args, unsigned int);
int count = 0, index = 0, i;
char *buf = malloc(32);
if (buf == NULL)
return (0);

if (flags & FLAG_HASH)
write(1, "0", 1);

if (number == 0)
{
write(1, "0", 1);
return (1);
}

while (number > 0)
{
buf[index++] = number % 8 + '0';
number /= 8;
}

for (i = index - 1; i >= 0; i--)
{
write(1, &buf[i], 1);
count++;
}

free(buf);
return (count);
}

/**
 * print_hex - converts argument number to hex, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_hex(va_list args, int flags)
{
unsigned int number = va_arg(args, unsigned int);
int count = 0, index = 0, i = 0;
char hexDigits[] = "0123456789abcdef";
char *buf = malloc(32);

if (buf == NULL)
return (0);

if (flags & FLAG_HASH)
write(1, "0x", 2);

if (number == 0)
{
write(1, "0", 1);
return (1);
}

while (number > 0)
{
buf[index++] = hexDigits[number % 16];
number /= 16;
}

for (i = index - 1; i >= 0; i--)
{
write(1, &buf[i], 1);
count++;
}

free(buf);
return (count);
}

/**
 * print_HEX - converts argument number to HEX, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_HEX(va_list args, int flags)
{
unsigned int number = va_arg(args, unsigned int);
int count = 0, index = 0, i;
char hexDigits[] = "0123456789ABCDEF";
char *buf = malloc(32);

if (buf == NULL)
return (0);

if (flags & FLAG_HASH)
write(1, "0X", 2);

if (number == 0)
{
write(1, "0", 1);
return (1);
}

while (number > 0)
{
buf[index++] = hexDigits[number % 16];
number /= 16;
}

for (i = index - 1; i >= 0; i--)
{
write(1, &buf[i], 1);
count++;
}

free(buf);
return (count);
}
