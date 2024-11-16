#include "get_next_line.h"

char *ft_read(char *str, int fd)
{
	int	read_len;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(str, '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[read_len] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (str);
}
char *get_next_line(int fd)
{
	static char *str;
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		read(fd, str, BUFFER_SIZE);
		i++;
	}
	return (str);
}