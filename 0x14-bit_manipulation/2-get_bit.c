#include "main.h"

/**
 * get_bit - returns the value of abit at an index in a decimal number
 * @n: number to search
 * @index: index of a bit
 * Return: bit value
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;


	return (bit_value);
}
