#include "main.h"

/**
 * _isupper - checks for uppercase characters
 * @x: The character to be checked
 * Return: 1 if character is uppercase, 0 otherwise
 */

int _isupper(int x)
{

	if (x >= 65 && x <= 90)
	{
		return (1);
	}
	return (0);
}
