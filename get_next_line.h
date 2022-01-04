#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char const *src, size_t n);
void	ft_bzero(void *str, size_t size);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcat(char *dst, char const *src, size_t nbr);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
