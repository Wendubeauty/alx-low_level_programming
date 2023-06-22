#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: Name of the file
 * @text_content: Text content to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file, bytesWritten, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	while (text_content[length])
		length++;

	file = open(filename, O_WRONLY | O_APPEND);
	if (file == -1)
		return (-1);

	bytesWritten = write(file, text_content, length);
	if (bytesWritten == -1 || bytesWritten != length)
	{
		close(file);
		return (-1);
	}

	close(file);
	return (1);
}

