#include "shell.h"

/**
 * x_strdup - function that duplicate
 * given string
 *
 * @str: string to be duplicated
 * Return: duplicated string
 */
char *x_strdup(const char *str)
{
	int len, iterator;
	char *newstr;

	if (!str)
		return (NULL);
	iterator = 0;
	len = x_strlen(str);
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	iterator = 0;
	while (str[iterator] != '\0')
	{
		newstr[iterator] = str[iterator];
		iterator++;
	}
	newstr[iterator] = '\0';
	return (newstr);
}

