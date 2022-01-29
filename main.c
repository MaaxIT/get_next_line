#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*res = NULL;
	int		fd;
	size_t	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);

    i = 0;
	while (1)
	{
		res = get_next_line(fd);
		printf("%zu: |%s|\n", i, res);
		if (!res)
			break;
		free(res);
		i++;
	}
	return (0);
}