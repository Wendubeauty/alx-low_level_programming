#include "main.h"

/**
 * main - This program copies the content of a file to another file.
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, otherwise exit with error codes
 */
int main(int argc, char **argv)
{
	int file_from, file_to, r_bytes, w_bytes;
	char buffer[1024];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from fil %s\n", argv[1]), exit(98);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);

	while ((r_bytes = read(file_from, buffer, 1024)) > 0)
	{
		w_bytes = write(file_to, buffer, r_bytes);
		if (w_bytes == -1 || w_bytes != r_bytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (r_bytes == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from fil %s\n", argv[1]), exit(98);

	if (close(file_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

	if (close(file_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

	return (0);
}

