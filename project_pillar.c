#include "main.h"

/**
 * spot - spots appropriate function for each specifier
 * @c: specifier to spot a function for
 * Return: correct funtion for the specifier if it's present....else NULL
*/
int (*spec(char c))(va_list args, int flags)
{
int i = 0;
converter_t converter[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'d', print_int},
{'i', print_int},
{'b', print_binary},
{'u', print_uint},
{'o', print_octal},
{'x', print_hex},
{'X', print_HEX},
{'S', print_S},
{'p', print_pointer},
{'R', print_rot13},
{'r', print_reverse},
{'\0', NULL}};

for (i = 0; converter[i].format != '\0'; i++)
{
if (converter[i].format == c)
return (converter[i].function); }

return (0);
}
