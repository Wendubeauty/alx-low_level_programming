#include "main.h"

/**
 * create_file - Creates a file with the specified content
 * @filename: Name of the file to create
 * @text_content: Content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int file, bytesWritten, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (file == -1)
		return (-1);

	if (text_content != NULL)
	{
		bytesWritten = write(file, text_content, length);
		if (bytesWritten == -1 || bytesWritten != length)
		{
			close(file);
			return (-1);
		}
	}

	close(file);
	return (1);
}

