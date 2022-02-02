/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:34:51 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/02/02 13:46:18 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
get_next_line
- Purpose: Get the next line of a file everytime we call it
*/
char    *get_next_line(int fd)
{
    static char remaind[BUFFER_SIZE];
    char *buffer = NULL;
    char *str = NULL;
    char *tmp = NULL;
    size_t i;

    if (fd < 0 || BUFFER_SIZE <= 0) {
        return (NULL);
    }

    if (ft_strlen(remaind) > 0)
    {

        str = ft_strdup(remaind);
        if (!str)
            return (NULL);
        ft_bzero(remaind, ft_strlen(remaind) + 1);

        i = 0;
        while (str[i])
        {
            if (str[i] == '\n')
            {
                tmp = malloc(i + 2);
                if (!tmp)
                    return (NULL);
                ft_strlcpy(tmp, str, i + 2);
                ft_strlcpy(remaind, str + i + 1, BUFFER_SIZE);
                free(str);
                return (tmp);
            }
            i++;
        }

    }
    else
    {
        str = malloc(1);
        if (!str) {
            return (NULL);
        }
        str[0] = '\0';
    }

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    ft_bzero(buffer, BUFFER_SIZE + 1);

    ssize_t result = read(fd, buffer, BUFFER_SIZE);
    while (result >= 0)
    {
        if (result == 0) {
            if (*str) {
                free(buffer);
                return (str);
            }
            else
                break ;
        }
        buffer[result] = '\0';
        i = 0;
        while (buffer[i])
        {
            if (buffer[i] == '\n')
            {
                tmp = malloc(ft_strlen(str) + i + 2);
                if (!tmp) {
                    free(buffer);
                    return (NULL);
                }
                ft_strlcpy(tmp, str, -1);
                free(str);
                ft_strlcpy(tmp + ft_strlen(tmp), buffer, i + 2);
                ft_strlcpy(remaind, buffer + i + 1, -1);
                free(buffer);
                return (tmp);
            }
            i++;
        }
        // if we didnt find, backup for the next read
        tmp = ft_strdup(str);
        free(str);
        str = malloc(ft_strlen(tmp) + ft_strlen(buffer) + 1);
        if (!str)
        {
            free(buffer);
            free(tmp);
            return (NULL);
        }
        ft_strlcpy(str, tmp, -1);
        free(tmp);
        ft_strlcpy(str + ft_strlen(str), buffer, -1);
        result = read(fd, buffer, BUFFER_SIZE);
    }

    free(str);
    free(buffer);
    return (NULL);
}
