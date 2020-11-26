#include "holberton.h"
/**
  *_strcpy_which_path - function that copies a string.
  *@dest: destination string
  *@src: string to be copied
  *Return: return copied string
  **/
char *_strcpy_which_path(char *dest, char *src)
{
	char *cc = dest;
	int i = 5;

	while (src[i])
	{
		*dest++ = src[i];
		i++;
	}
	*dest = 0;
	return (cc);
}

/**
  * function_token_which - tokenitation of variable path when del :
  *@dest: pointer destiny
  *@pathDivision: gives string
  *Return: pointer destiny cp src
  **/
void function_token_which(char *dest, char **pathDivision)
{
	char *token = NULL;
	int i = 0;
	const char *delim = ":";

	token = strtok(dest, delim);

	while (token != NULL)
	{
		pathDivision[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	fix_token(pathDivision[i - 1]);
	pathDivision[i] = NULL;
}

/**
  * _which - evaluated all path posibles for excute one program
  *@array: array of all variable path
  *
  *Return: path found otherwise the array[0]
  **/
char *_which(char **array)
{
	char **pathDivision = NULL;
	char *path = "PATH=", *dest = NULL, *thisEnv = NULL, *concat = NULL;
	int i = 0, j = 0;
	struct stat st;

	for (j = 0; environ[j] != 0; j++)
	{
		thisEnv = environ[j];
		for (i = 0; *(path + i) && *(thisEnv + i) == *(path + i); i++)
			if (i == 4)
				path = thisEnv;
	}
	dest = malloc(length(path + 1));

	if (dest == NULL)
		return (NULL);
	_strcpy_which_path(dest, path);
	pathDivision = malloc(length(dest + 1));
	if (pathDivision == NULL)
		return (NULL);
	function_token_which(dest, pathDivision);
	concat = malloc(BUFSIZ);
	if (concat == NULL)
		return (NULL);

	for (j = 0;  pathDivision[j] != NULL ; j++)
	{
		_strcpy(concat, pathDivision[j]);
		_strcat(concat, "/");
		_strcat(concat, array[0]);
		if (stat(concat, &st) == 0)
			break;
	}
	free(dest);
	free(pathDivision);
	if (stat(concat, &st) == 0)
		return (concat);

	free(concat);
	return (array[0]);
}
