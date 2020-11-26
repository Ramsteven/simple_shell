#include "holberton.h"
/**
  * manage_err - check for the if the pathname exist in the env path.
  * @cont_array: the array for count.
  * @nread: the length of the characters from the array.
  * @count_procces: count the number of times that stat is execute.
  * @av: get the arguments from the first line of the terminal.
  */
void manage_err(char *cont_array, ssize_t nread, int count_procces, char *av)
{
	char *mensag = NULL;
	char strnum[11];
	int length_strum = 0, length_array = 0, mes_length = 0, length_av = 0;

	_itoa(count_procces, strnum);
	length_strum = length(strnum);
	length_array = length(cont_array);
	length_av = length(av);
	mes_length = length_strum + length_array + length_av + 52;
	mensag = _calloc(mes_length, sizeof(char));

	if (mensag == NULL)
		return;
	if (nread != 1)
	{
		_strcat(mensag, av);
		_strcat(mensag, ": ");
		_strcat(mensag, strnum);
		_strcat(mensag, ": ");
		_strcat(mensag, cont_array);
		_strcat(mensag, ": ");
		_strcat(mensag, "not found\n");
		write(STDOUT_FILENO, mensag, mes_length);
	}
	free(mensag);
}
