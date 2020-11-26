#include "holberton.h"
/**
  * manage_error - check for the if the pathname exist in the env path.
  * @cont_array: the array for count.
  * @nread: the length of the characters from the array.
  * @counter_procces: count the number of times that stat is execute.
  */
void manage_error(char *cont_array, ssize_t nread, int counter_procces)
{
	char *mensag = NULL;
	char strnum[11];
	int length_strum = 0, length_array = 0, mes_length = 0;

	_itoa(counter_procces, strnum);
	length_strum = length(strnum);
	length_array = length(cont_array);
	mes_length = length_strum + length_array + 50;
	mensag = _calloc(mes_length, sizeof(char));

	if (mensag == NULL)
		return;
	if (nread != 1)
	{
		_strcat(mensag, strnum);
		_strcat(mensag, ": ");
		_strcat(mensag, cont_array);
		_strcat(mensag, ": ");
		_strcat(mensag, "not found\n");
		write(STDOUT_FILENO, mensag, mes_length);
	}
	free(mensag);
}
