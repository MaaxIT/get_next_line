/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:35:08 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/01/17 09:15:27 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* get_next_line.c */
char    *get_next_line(int fd);

/* get_next_line_utils.c */
size_t	ft_strlen(char *str);
void	ft_str_bzero(char *str);
void	*ft_memmove(void *dst, const void *src, size_t size);
size_t	ft_strlcpy(char *dst, char const *src, size_t n);
char	*ft_strdup(char const *str);

/* TO DELETE */
/* TO DELETE */
/* TO DELETE */
/* TO DELETE */
/* TO DELETE */
/* TO DELETE */
/* TO DELETE */
#include "wraloc.h"

#endif
