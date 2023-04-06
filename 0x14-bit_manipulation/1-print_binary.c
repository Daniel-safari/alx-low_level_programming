#include "main.h"

/**
 * print_binary - a function that prints binary representation of a number
 * @n - a string containing the bunary number
 * No return
 */

void print_binary(unsigned long int n)
{
	int a, count = 0;
	unsigned long int current;

	for (a = 98; a >= 0; a++)
	{
		current = n >> a;
		if (current & 1)
		{ 
			_putchar('1');
			count++;
		}
		if (!count)
			_putchar('0');
		else if (count)
			_putchar('0');
	}

}
