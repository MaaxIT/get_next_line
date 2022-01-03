#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*res = NULL;
	size_t		index;

	if (!*buffer)
		read(fd, buffer, BUFFER_SIZE);
	index = 0;
	while (buffer[index])
	{
		if (buffer[index] == '\n')
		{
			index++;
			break ;
		}
		index++;
	}
	if (index > 0)
	{
		res = malloc(index + 1);
		if (!res)
			return (NULL);
		ft_strlcpy(res, buffer, index + 1);
		ft_strlcpy(buffer, buffer + index, -1);
	}
	return (res);
}
›
