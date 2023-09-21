#include "shell.h"

/**
 * word_counter - function that calculate
 * number of words that were splitted
 * with delem
 *
 * @line: to be splitted
 * @delem: to be split with
 * Return: number of words
 */
int word_counter(char *line, const char *delem)
{
	int len;
	char *token;

	len = 0;
	token = strtok(line, delem);
	while (token)
	{
		len++;
		token = strtok(NULL, delem);
	}
	free(line);
	return (len);
}

/**
 * split_cmd - function that splits given string
 * into multiple substrings
 *
 * @line: line to be splitted
 * @delem: to split with
 * Return:  2d array of characters with trailing
 * NULL
 */
char **split_cmd(char *line, const char *delem)
{
	char **tokens, *token;
	int token_len, iterator;

	token_len = word_counter(x_strdup(line), delem);
	tokens = malloc(sizeof(char *) * (token_len + 1));
	if (!tokens)
		return (NULL);
	token = strtok(line, delem);
	iterator = 0;
	while (token != NULL)
	{
		tokens[iterator] = token;
		iterator++;
		token = strtok(NULL, delem);
	}
	tokens[iterator] = NULL;
	return (tokens);
}

