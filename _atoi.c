#include "shell.h"

/**
 * interactive - returns true if shell is at interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive(info_t * info)
{
	return (issatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check if character is a delimeter
 * @h: the char to check
 * @delim: the de;limiter string
 * Return: 1 if true, 0 if its false
 */
int is_delim(char h, char *delim)
{
	while (*delim)
		if (*delim++ == h)
			return (1);
	return (0);
}
/**
 * _isalpha - checkes for alphabetic character
 * @h: The character to input
 * Return: 1 if h is alphabetic, 0 if its not
 */

int _isapha(int h)
{
	if ((h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an interger
 * @p: the string to be converted
 * Return: 0 if there is no numbers in string, converted number otherwise
 */

int _atoi(char *h)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (a = 0; h[a] != '\0' && flag != 2; a++)
	{
		if (h[a] == '-')
			sign *= -1;
		if (h[a] >= '0' && h[a] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (h[a] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}

