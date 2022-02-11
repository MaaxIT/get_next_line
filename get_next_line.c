/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:16:17 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/02/11 23:51:20 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_read_buffer(int fd)
{
	char		*buffer;
	ssize_t		res;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	res = read(fd, buffer, BUFFER_SIZE);
	if (res <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

ssize_t	add_read_to_buffer(char **buffer, char *next)
{
	char	*tmp;
	size_t	new_size;

	tmp = NULL;
	new_size = ft_strlen(next);
	if (*buffer)
	{
		new_size += ft_strlen(*buffer);
		tmp = ft_strdup(*buffer);
		free(*buffer);
	}
	*buffer = ft_calloc(new_size + 1, sizeof(char));
	if (tmp)
	{
		ft_strlcat(*buffer, tmp, -1);
		free(tmp);
	}
	if (!*buffer)
		return (-1);
	ft_strlcat(*buffer, next, -1);
	free(next);
	return (0);
}

char	*remove_remaind_from_buffer(char *buffer, size_t len)
{
	char	*new;
	size_t	total;

	if (!buffer)
		return (NULL);
	total = ft_strlen(buffer) + 1 - len;
	new = ft_calloc(total, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcat(new, buffer, total);
	free(buffer);
	return (new);
}

char	*check_remaind(char **remaind)
{
	char	*found;
	char	*buffer;
	char	*cpy;

	found = NULL;
	buffer = NULL;
	cpy = ft_strdup(*remaind);
	if (!cpy)
		return (NULL);
	found = strchr(cpy, '\n');
	if (found)
	{
		buffer = remove_remaind_from_buffer(*remaind, ft_strlen(found) - 1);
		if (ft_strlen(buffer) == 0)
		{
			free(buffer);
			buffer = NULL;
		}
		if (ft_strlen(found + 1) > 0)
			*remaind = ft_strdup(found + 1);
		free(cpy);
		return (buffer);
	}
	if (*remaind && **remaind)
		free(*remaind);
	*remaind = cpy;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remaind = NULL;
	char		*buffer;
	char		*next;
	char		*found;
	ssize_t		i;

	buffer = NULL;
	next = NULL;
	found = NULL;
	if (remaind)
	{
		found = check_remaind(&remaind);
		if (found)
			return (found);
		else
		{
			if (ft_strlen(remaind) > 0)
			{
				buffer = ft_strdup(remaind);
				if (!buffer)
					return (NULL);
			}
			free(remaind);
		}
	}
	found = NULL;
	while (1)
	{
		next = alloc_read_buffer(fd);
		if (!next)
			break ;
		i = add_read_to_buffer(&buffer, next);
		if (i == -1)
			return (NULL);
		found = ft_strchr(buffer, '\n');

		// printf("\033[0;31m");
		// printf("-----\nBEFORE :\nBUFFER=|%s|\nREMAIND=|%s|\nFOUND=|%s|\n======== END ========\n\n", buffer, remaind, found);
		// printf("\033[0m");

		if (found)
		{
			if (ft_strlen(found + 1) > 0)
				remaind = ft_strdup(found + 1);
			buffer = remove_remaind_from_buffer(buffer, ft_strlen(found) - 1);
			break ;
		}
	}
	// printf("\033[0;31m");
	// printf("-----\nAfter :\nBUFFER=|%s|\nREMAIND=|%s|\nFOUND=|%s|\n======== END ========\n\n", buffer, remaind, found);
	// printf("\033[0m");
	return (buffer);
}
