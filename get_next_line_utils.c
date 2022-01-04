#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

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

void	ft_bzero(void *str, size_t size)
{
	char	*str_cpy;
	size_t	i;

	i = 0;
	str_cpy = str;
	while (i < size)
		str_cpy[i++] = '\0';
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*final;

	if (!s1 || !s2)
		return ((char *)0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	final = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!final)
		return ((char *)0);
	ft_strlcpy(final, s1, s1_len + 1);
	ft_strlcat(final, s2, s1_len + s2_len + 1);
	return (final);
}
