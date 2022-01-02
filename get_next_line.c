#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	line;
	int			cur_line;
	char		*content;
	char		*final;
	size_t		i;
	size_t		index;

	if (fd < 0)
		return (NULL);
	content = malloc(sizeof(char) * BUFFER_SIZE);
	final = malloc(sizeof(char) * BUFFER_SIZE);
	if (!content)
		return (NULL);
	read(fd, content, BUFFER_SIZE);

	i = 0;
	cur_line = 0;
	index = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			cur_line++;
		if (cur_line == line)
		{
			final[index] = content[i];
			index++;
		}
		else if (cur_line > line)
			break ;
		i++;
	}
	final[index] = '\0';
	line++;
	free(content);
	return (final);
}

#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*res;

	fd = open("test", O_RDONLY);
	res = get_next_line(fd);
	printf("\n%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	res = get_next_line(fd);
	printf("%s\n", res);
	free(res);
	return (0);
}
