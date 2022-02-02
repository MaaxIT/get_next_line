/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:35:03 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/02/02 13:45:25 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ft_strlen
- Purpose: Calculate the length of a string until a '\0' is found
- From: libft42 (mine)
*/
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

/*
ft_bzero
- Purpose: Loop through size bytes of ptr and set them to '\0'
- From: libft42 - ft_bzero (mine)
*/
void	ft_bzero(void *str, size_t size)
{
	char	*str_cpy;
	size_t	i;

	i = 0;
	str_cpy = str;
	while (i < size)
		str_cpy[i++] = '\0';
}

/*
ft_strlcpy
- Purpose: Copy string src to dst up to n-1 bytes, and add a '\0' character after it
- From: libft42 (mine)
*/
size_t	ft_strlcpy(char *dst, char const *src, size_t n)
{
	size_t	i;
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen((char *)src);
	if (!dst || n == 0)
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

/*
ft_strdup
- Purpose: Allocate a string and forward str into it.
- From: libft42 (mine)
*/
char	*ft_strdup(char const *str)
{
	size_t	i;
	size_t	str_len;
	char	*ptr;

	if (!str)
		return (NULL);
	str_len = ft_strlen((char *)str);
	ptr = malloc((str_len + 1) * sizeof(char));
	if (!ptr)
		return ((char *)0);
	i = 0;
	while (i < str_len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
