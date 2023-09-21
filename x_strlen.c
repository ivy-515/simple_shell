
/**
 * x_strlen - function that counts
 * number of character in a given
 * string
 *
 * @str: string
 * Return: integer
 */
int x_strlen(const char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

