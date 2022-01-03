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

#endif
