#include "shell.h"

/**
 * x_strcat - function that takes two
 * strings and concatenate them
 *
 * @dest: destination string that will
 * recieve characters
 * @src: source of the characters
 * Return: (dest)
 */
char *x_strcat(char *dest, char *src)
{
	int len1, iter;

	len1 = x_strlen(dest);
	iter = 0;

	while (src[iter])
	{
		dest[len1 + iter] = src[iter];
		iter++;
	}
	dest[len1 + iter] = 0;
	return (dest);
}

