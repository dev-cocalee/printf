#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @str: argument string.
 * Return: integer length of str
 */
int _strlen(char *str)
{
size_t count = 0;

while (str[count])
count++;

return (count);
}

/**
 * _strcpy - Copies a src string to a dest buffer.
 * @dest: destination buffer
 * @src: source strig
 * Return: A pointer to the dest buffer.
 */
char *_strcpy(char *dest, const char *src)
{
char *p = dest; /*p serves as the pointer*/

while (*src != '\0')
{
*p = *src;
src++, p++;
}

*p = '\0';
return (dest);
}

/**
 * is_valid_specifier - Check if a character is a valid specifier.
 * @character: A character from a format string.
 * Return: 0 if not a specifier, a non-zero value if it is.
 */
int is_valid_specifier(char character)
{
return (character == 'X' || character == 'u' || character == 'p'
|| character == 'i' || character == 'o' || character == 'S' ||
character == 'r' || character == 'R' || character == 's'
|| character == 'd' || character == 'c' || character == 'x'
|| character == 'b');
}
