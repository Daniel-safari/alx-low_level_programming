#include "main.h"
#include <stdlib.h>
#include <stdio.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocates 1024 bytes for a buffer
 * @file: the name of file buffer is storing chars for
 * Return: pointer to the newly allocated buffer
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Cant write to %s\n", file);
		exit(99);
	}
	return (buffer);
}

/**
 * close_file - closes the descriptors
 * @fd: the file descriptor to be closed 
 */

void close_file(int fd)
{
	int c;
	
	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO,"Error: Cant close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of a file to another file
 * @argc: the number of argument supplied to the program
 * @argv: an array of pointers to the arguments
 * Return: 0 on success
 *
 * Description: If the argument count is incorrect - exit code 97
                If file_from does not exist or cant be read - exit code 98
		If file_to cant be created or written to - exit code 99
		If file_to or file_from cant be closed - exit code 100
 */

int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,"Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do{
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Cant read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		w = write(to, buffer, r);

		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Cant write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	}
	while (r > 0);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}

