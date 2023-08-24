#include "main.h"

/**
 * _strcpy - copy string
 * @source: source to copy
 * @dest: destination
 */
void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 * _strlen - length of string
 * @string: - string to count
 *
 * Return: length of string
 */
int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strcmp - compare two string
 * @first: first str
 * @second: second str
 *
 * Return: 0 or 1
 */
int _strcmp(char *first, char *second)
{
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	return (first[i] - second[i]);
}

/**
 * _strcat - concatenate two strings
 * @destination: destination
 * @source: source
 *
 * Return: destination
 */
char *_strcat(char *destination, char *source)
{
	char *new_string = NULL;
	int len_dest = _strlen(destination);
	int len_source = _strlen(source);

	new_string = malloc(sizeof(*new_string) * (len_dest + len_source + 1));
	_strcpy(destination, new_string);
	_strcpy(source, new_string + len_dest);
	new_string[len_dest + len_source] = '\0';
	return (new_string);
}

/**
 * _strspn - returns the len of initial sub string
 * @str1: - string 1
 * @str2: - string 2
 *
 * Return: len of sub string
 */
int _strspn(char *str1, char *str2)
{
	int i = 0;
	int match = 0;

	while (str1[i] != '\0')
	{
		if (_strchr(str2, str1[i]) == NULL)
			break;
		match++;
		i++;
	}
	return (match);
}

