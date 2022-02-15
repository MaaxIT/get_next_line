/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:16:30 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/02/15 09:21:14 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* External libraries */
# include <stdlib.h>
# include <unistd.h>

/* get_next_line_utils */
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t nbr);
char	*ft_strchr(const char *str, int ch);

/* get_next_line.c */
char	*get_next_line(int fd);
char	*check_remaind(char **remaind);
char	*remove_remaind_from_buffer(char *buffer, size_t len);
ssize_t	add_read_to_buffer(char **buffer, char *next);
char	*alloc_read_buffer(int fd);

#endif