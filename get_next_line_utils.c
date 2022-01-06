/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:35:03 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/01/06 16:31:39 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Calculate the length of the string */
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/* Make each byte of the char a \0 character */
void	ft_bzero(void *str, size_t size)
{
	char	*str_cpy;
	size_t	i;

	i = 0;
	str_cpy = str;
	while (i < size)
		str_cpy[i++] = '\0';
}

/* Allocate memory and bzero everything */
void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	total;

	total = count * size;
	result = malloc(total);
	if (!result)
		return ((void *)0);
	ft_bzero(result, total);
	return (result);
}

/* Copy a source string into a dest string up to n bytes */
size_t	ft_strlcpy(char *dst, char const *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	if (!dst || !src || n == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (n - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/* Concatenate two strings */
size_t	ft_strlcat(char *dst, char const *src, size_t nbr)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (nbr >= dst_len)
	{
		dst += dst_len;
		nbr -= dst_len;
		ft_strlcpy(dst, src, nbr);
		return (dst_len + src_len);
	}
	else
		return (nbr + src_len);
	return (0);
}
