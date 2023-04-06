#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - a funtion that converts binary number to unsigned int
 * @b - a string that is containing the binary number to convert
 * Return: the number that has been converted
 */

unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int d_v = 0;

	for (a = 0; b[a]; a++)
	{
		if (b[a] < '0' || b[a] > '1')
			return (0);
		d_v = 2 * d_v + (b[a] - '0');
	}
	return (d_v);
}

