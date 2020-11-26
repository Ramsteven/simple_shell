#include "holberton.h"
/**
  * handler - change the process for ctrl c.
  * @num: status of the wait.
  */
void handler(int num __attribute__((unused)))
{
	write(STDOUT_FILENO, "\nkatydav$", 9);
}
/**
  * prompt - show the prompt for the fake terminal.
  */
void prompt(void)
{
	ssize_t line_read = 0, nwrite = 0;
	char *line = "katydav$";

	line_read = length(line);
	nwrite = write(STDOUT_FILENO, line, line_read);
	if (nwrite == -1)
		exit(EXIT_FAILURE);
}
/**
  * check_stat - check for the if the pathname exist in the env path.
  * @array: get the input characters from the terminal.
  * @nread: the length of the characters from the array.
  * @buffer: the buffer that contain the line of getline.
  * @stat_status: the status pass to the exit.
  */
void check_stat(char **array, ssize_t nread, char  *buffer, int *stat_status)
{
	pid_t pid = 0;
	struct stat st;
	int status = 0, str_cpm = 0;
	static int counter_procces;
	char *cont_array = array[0];

	counter_procces++;
	if (stat(array[0], &st) == 0)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error: ");
			*stat_status = 1;
		}
		if (pid == 0)
			execve(array[0], array, environ);
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				*stat_status = WEXITSTATUS(status);
		}
	}
	else
	{
		*stat_status = 127;
		str_cpm = _strcmp(array[0], "exit");
		if (str_cpm == 0)
		{
			free(buffer);
			free(array);
			exit(*stat_status);
		}
		manage_error(cont_array, nread, counter_procces);
	}
}
/**
  * check_get_line - check for the if the pathname exist in the env path.
  * @array: get the input characters from the terminal.
  * @stat_status: the status pass to the exit.
  * Return: the nread when is -1.
  */
ssize_t check_get_line(char **array, int *stat_status)
{
	char *buffer = NULL, *token = NULL;
	int i = 0, check_line = 0;
	size_t bytes = 0;
	struct stat st;
	ssize_t nread = 0, resta = 0;
	const char *delim = " ";
	bool x = true;

	chek_isatty(check_line);
	while ((nread = getline(&buffer, &bytes, stdin)) != -1)
	{ i = 0;
		token = strtok(buffer, delim);
		for (; token != NULL; i++)
		{
			array[i] = token;
			token = strtok(NULL, delim);
		}
		fix_token(array[i - 1]);
		array[i] = NULL;
		if (length(array[i - 1]) == 0 && i >= 2)
			array[i - 1] = NULL;
		if (array[0][0] == '/')
			x = true;
		if ((array[0][0] != '/') && (length(array[0]) > 0))
		{
			x = false;
			resta = (length(array[0]));
			array[0] = _which(array);
			nread += (length(array[0]) + 1) - resta;
		}
		check_stat(array, nread, buffer, stat_status);
		if (x == false && stat(array[0], &st) == 0)
			free(array[0]);
		chek_isatty(check_line);
	}
	write(STDOUT_FILENO, "\n", 1);
	if (nread == -1)
		free(buffer);
	free(array);
	return (nread);
}
