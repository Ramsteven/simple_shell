#include "holberton.h"
/**
  * main - manage main loop for the shell.
  * @ac: amount of characters received
  * @av: double pointer whith each word writed in the shell
  * Return: 0
  **/

int main(int ac, char **av)
{
	ssize_t nread = 0;
	int stat_status = 0, check_line = 0;
	char **array = NULL;

/*	environ = NULL;*/
	array = malloc(BUFSIZ);
	if (array == NULL)
		return (0);
	/*signal */
	signal(SIGINT, handler);
		while (ac == 1)
		{
			chek_isatty(check_line);
			nread = check_get_line(array, &stat_status, av[0]);
			if (nread == -1)
			{
				break;
			}
		}
	return (stat_status);
}
