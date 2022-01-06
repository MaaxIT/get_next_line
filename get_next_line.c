/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:34:51 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/01/06 16:49:52 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	remaind[BUFFER_SIZE + 1];
	char		*buffer;
	char		*res;
	int			index;

	buffer = ft_calloc(BUFFER_SIZE + ft_strlen(remaind) + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (ft_strlen(remaind) == 0)
	{
		index = read(fd, buffer, BUFFER_SIZE);
		if (index <= 0)
		{
			free(buffer);
			return (NULL);
		}
	}
	ft_strlcat(buffer, remaind, -1);
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
	if (index <= 0)
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc(index + 1, sizeof(char));
	ft_strlcpy(res, buffer, index + 1);
	ft_strlcpy(remaind, buffer + index, -1);
	free(buffer);
	return (res);
}
