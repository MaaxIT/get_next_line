#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	line;
	char		*content;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	content = malloc(sizeof(char) * BUFFER_SIZE);
	read(fd, content, BUFFER_SIZE);

	size_t	i = 0;
	int cur_line = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			cur_line++;
		if (cur_line == line)
			printf("%c", content[i]);
		else if (cur_line > line)
			break ;
		i++;
	}
	line++;
	printf("\n");
	free(content);
	return (NULL);
}

#include <fcntl.h>
int	main(void)
{
	int		fd;

	fd = open("test", O_RDONLY);
	printf("\n");
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	printf("\n");
	return (0);
}
