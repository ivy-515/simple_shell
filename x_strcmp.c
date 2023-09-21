/**
 * x_strcmp - function that compares two
 * strings
 *
 * @s1: first string
 * @s2: second string
 * Return: zero when two strings are equal
 */
int x_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

