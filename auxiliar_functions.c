#include "holberton.h"
/**
  * _strcmp - concatenates two strings.
  * @a: dest.
  * @b: source.
  * Return: the result of the compare.
  */
int _strcmp(char *a, char *b)
{
	while ((*a) && (*a == *b))
	{
		++a;
		++b;
	}
	return ((int)(unsigned char)(*a) - (int)(unsigned char)(*b));
}
/**
  * _strcpy - copy two strings.
  * @dest: dest.
  * @src: source.
  * Return: the new pointer whit the value.
  */
char *_strcpy(char *dest, char *src)
{
	char *cc = dest;
	int i = 0;

	while (src[i])
	{
		*dest++ = src[i];
		i++;
	}
	*dest = 0;
	return (cc);
}
/**
  * *_strcat - copy two strings.
  * @dest: dest.
  * @src: source.
  * Return: the new pointer whit the value.
  */
char *_strcat(char *dest, char *src)
{
	int size, index;

	size = 0;

	while (dest[size] != 0)
		size++;
	for (index = 0; src[index] != 0; index++)
		dest[size + index] = src[index];
	dest[size + index] = 0;

	return (dest);
}
/**
  * length - copy two strings.
  * @size: dest.
  * Return: the size of the array of characters.
  */
ssize_t length(char *size)
{
	ssize_t index = 0;

	for (; size[index] != '\0'; index++)
		;

	return (index);
}
/**
  *_itoa - copy two strings.
  * @num: the number to convert.
  * @strnum: the array that alloc the number in char.
  * Return: the new pointer whit the value.
  */
char *_itoa(int num, char *strnum)
{
	int copy_num = num, i, j, div = 1;

	for (i = 0; copy_num != 0; i++)
		copy_num /= 10;
	j = i;

	while (i != 0)
	{
		div *= 10;
		i--;
	}
	div /= 10;
	for (i = 0; i < j; i++)
	{
		strnum[i] = (num / div) + '0';
		num %= div;
		div /= 10;
	}
	strnum[i] = '\0';

	return (strnum);
}
