#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX stdout
 * @filename: pointer to the naame of the file
 * @letters - the number of letters the function should read and print
 * Return: If it is NULL or it fails - 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;

	char *buffer *;

	if (filename == NULL)
		return (0);

	*buffer = malloc(sizeof(char) * letters);
	if (*buffer == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(a, *buffer, letters);
	w = write(STDOUT_FILENO, *buffer, b);

	if (o == 1 || r == -1 || w == -1 || w != r)
	{
		free(*buffer);
		return (o);
	}
	free(*buffer);
	close(o);

	return (w);
}

