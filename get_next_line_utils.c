/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:16:12 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/02/11 22:56:44 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	total;
	size_t	i;

	total = count * size;
	result = malloc(total);
	if (!result)
		return (NULL);
	i = 0;
	while (i < total)
		result[i++] = '\0';
	return (result);
}

char	*ft_strdup(const char *str)
{
	size_t siz;
	char *copy;
	siz = strlen(str) + 1;
	if ((copy = malloc(siz)) == NULL)
		return(NULL);
	(void)memcpy(copy, str, siz);
	return(copy);
}

size_t	ft_strlcat(char *dst, const char *src, size_t nbr)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (nbr >= dst_len)
	{
		dst += dst_len;
		nbr -= dst_len;
		i = 0;
		while (src[i] && i < (nbr - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (dst_len + src_len);
	}
	else
		return (nbr + src_len);
	return (0);
}

char	*ft_strchr(const char *str, int ch)
{
	int				i;
	unsigned char	search;

	i = 0;
	search = (unsigned char)ch;
	while (str[i])
	{
		if (str[i] == search)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == search)
		return ((char *)&str[i]);
	return (NULL);
}
