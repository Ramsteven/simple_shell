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


void find_path (char **array, ssize_t *nread, bool *x)
{
	int resta = 0;

	if (array[0][0] == '/')
		*x = true;
	if ((array[0][0] != '/') && (length(array[0]) > 0))
	{
		*x = false;
		resta = (length(array[0]));
		array[0] = _which(array);
		*nread += (length(array[0]) + 1) - resta;
	}
}

bool call_built_in(char **array, int *stat_status, char *buffer)
{
	int compare_env = 5;
	int compare_exit = 5;


	compare_exit =_strcmp(array[0], "exit");

	if (compare_exit == 0)
	{

		*stat_status = 127;
		free(buffer);
		free(array);
		exit(*stat_status);
	}

	compare_env =_strcmp(array[0], "env");

	if(compare_env == 0)
	{
		int size_variable = 0;
		int i = 0;


	while(environ[i] != NULL)
		{

			size_variable = length(environ[i]);
			write(STDOUT_FILENO,environ[i],size_variable);
			write(STDOUT_FILENO,"\n",1);
			i++;
		}

	}
	else
		return (false);

	return (true);
}