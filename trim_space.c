#include "shell.h"
/**
 * get_length - function that returns
 * length of given string excluding duplicated spaces
 *
 * @buffer: to return it's length without duplicate
 * @end: the end of the line
 * Return: length
 */
size_t get_length(char *buffer, size_t end)
{
	size_t start, len;
	int space;

	start = 0;
	space = 0;
	len = 0;
	while (start < end)
	{
		if ((buffer[start] == ' ' ||
			 buffer[start] == '\t') &&
			!space)
		{
			len++;
			space = 1;
		}
		else if (buffer[start] != ' ' &&
				 buffer[start] != '\t')
		{
			space = 0;
			len++;
		}
		start++;
	}
	return (len);
}

/**
 * get_newline - function returns
 * line after removing it's duplicated space
 *
 * @buffer: line to check against
 * @end: the end of the string exculding last spaces
 * Return: new string
 */
char *get_newline(char *buffer, size_t end)
{
	size_t start, i;
	int space;
	char *newline;

	start = 0;
	space = 0;
	i = 0;
	newline = malloc(sizeof(char) *
					 (get_length(buffer, end + 1) + 1));
	if (!newline)
		return (NULL);
	while (start <= end)
	{
		if ((buffer[start] == ' ' ||
			 buffer[start] == '\t') &&
			!space)
		{
			newline[i] = ' ';
			i++;
			space = 1;
		}
		else if (buffer[start] != ' ' &&
				 buffer[start] != '\t')
		{
			space = 0;
			newline[i] = buffer[start];
			i++;
		}
		start++;
	}
	newline[i] = 0;
	return (newline);
}

/**
 * trim_space - function that returns new line
 * with space removed from it
 *
 * @buffer: to check against
 * Return: newline without space duplicates
 */
char *trim_space(char *buffer)
{
	size_t left, right;
	char *s;

	left = 0;
	right = x_strlen(buffer);
	if (!right)
	{
		s = malloc(sizeof(char));
		*s = 0;
		return (s);
	}
	right -= 1;
	while (buffer[left] == ' ' || buffer[left] == '\t')
		left++;
	while (right > left &&
		   (buffer[right] == ' ' || buffer[right] == '\t'))
		right--;
	if (left > right)
	{
		s = malloc(sizeof(char));
		*s = 0;
		return (s);
	}
	return (get_newline(buffer + left, right - left));
}
