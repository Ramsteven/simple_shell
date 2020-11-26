#include "holberton.h"
/**
  * main - manage main loop for the shell.
  * Return: 0;
  **/
int main(void)
{
	ssize_t nread = 0;
	int stat_status = 0;
	char **array = NULL;

	array = malloc(BUFSIZ);
	if (array == NULL)
		return (0);
	/*signal */
	signal(SIGINT, handler);

	while (1)
	{
		nread = check_get_line(array, &stat_status);
		if (nread == -1)
		{
			break;
		}
	}
	exit(stat_status);
	return (0);
}
