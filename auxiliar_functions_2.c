#include "holberton.h"

/**
  *_calloc - function allocates memory for an array of
  *@nmemb: number of spaces to
  *@size: The size of every space
  *
  *
  *Return: pointer destiny cp src
  **/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p =  NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (0);
	p = malloc(nmemb * size);
	if (!p)
		return (0);
	for (i = 0; i < (nmemb * size); i++)
		p[i] = 0;

	return (p);
}


/**
  * fix_token - solved fix tokens of path
  *@token: token receved
  *
  *Return: pointer solved
  **/
void fix_token(char *token)
{
	ssize_t size = length(token);
	int i = 0;
	char *change = malloc(BUFSIZ);

	if (change == NULL)
		return;
	_strcpy(change, token);
	for (i = 0; (i < (size - 1)); i++)
		token[i] = change[i];

	token[i] = '\0';
	free(change);
}

/**
  *chek_isatty- check if input is with pathline or keyboard
  *@check_line: value change with function isatty
  *print- prompt line
  *Return: nothing
  **/
void chek_isatty(int check_line)
{
	check_line = isatty(STDIN_FILENO);
	if (check_line == 1) /*check input */
		prompt();
}
