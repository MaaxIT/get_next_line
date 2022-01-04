#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE];
	char		*buffer;
	char		*response;
	size_t		next_char;
	int			result;

	buffer = ft_calloc(BUFFER_SIZE + ft_strlen(remainder) + 1, 1);
	if (!buffer)
		return (NULL);
	result = read(fd, buffer, BUFFER_SIZE);
	if (result <= 0)
		return (NULL);
	response = ft_strjoin(remainder, buffer);
	if (!response)
		return (NULL);
	ft_strlcpy(buffer, response, -1);
	free(response);


	next_char = 0;
	while (buffer[next_char])
	{
		if (buffer[next_char] == '\n')
		{
			next_char++;
			break;
		}
		next_char++;
	}

	if (next_char > 0)
	{
		response = ft_calloc(next_char + 1, 1);
		if (!response)
			return (NULL);

		ft_strlcat(remainder, buffer + next_char, -1);
		ft_strlcpy(response, buffer, next_char + 1);
	}
	free(buffer);
	return (response);
}
