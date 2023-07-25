#include "shell.h"
/**
 * _getline- reads input from stream
 * @line: pointer to char
 * @len: pointer to size_t
 * @stream: pointer to FILE
 *
 * Return: ssize_t length of inp inputuser
 */
ssize_t _getline(char **line, size_t *len, FILE *stream)
{
	size_t n = 0, i = *len;
	char c, *buf = *line, *tmp;

	if (line == NULL || len == NULL || stream == NULL)
		return (-1);
	i = 120;
	buf = malloc(i * sizeof(char));
	while (fread(&c, sizeof(char), 1, stream) > 0 && c != EOF)
	{
		if (n > i - 1)
		{i = i * 2;
			tmp = realloc(buf, i * sizeof(char));
			buf = tmp; }
		buf[n] = c;
		n++;
		if (c == '\n')
		{
			if (n > i - 1)
			{
				i = i * 2;
				tmp = realloc(buf, i * sizeof(char));
				buf = tmp;
			}
			break;
		}
	}
	if (n == 0)
	{	buf[0] = '\0';
		*line = buf;
		*len = i;
		return (-1); }

	buf[n] = '\0';
	*line = buf;
	*len = i;
	return (n); }
