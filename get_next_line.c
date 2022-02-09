/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:34:51 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/02/02 13:50:54 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

// -1 -> return NULL
// 0 -> continue
// 1 -> tmp
ssize_t uno(char *remaind, char **str, char **tmp)
{
    size_t i;
    
    if (!str || !remaind || !tmp)
        return (-1);

    if (ft_strlen(remaind) > 0)
    {
        *str = ft_strdup(remaind);
        if (!*str)
            return (-1);
        ft_bzero(remaind, ft_strlen(remaind) + 1);
        i = 0;
        while (str[i] && *str[i])
        {
            if (*str[i] == '\n')
            {
                *tmp = malloc(i + 2);
                if (!*tmp)
                    return (-1);
                ft_strlcpy(*tmp, *str, i + 2);
                ft_strlcpy(remaind, *str + i + 1, BUFFER_SIZE);
                free(*str);
                return (1);
            }
            i++;
        }
    }
    else
    {
        *str = malloc(1);
        if (!*str)
            return (-1);
        ft_bzero(*str, 1);
    }

    return (0);

}

// -1 = NULL
// 0 = continue
// 1 = tmp
ssize_t  dos(char *remaind, char **buffer, char **str, char **tmp)
{
    size_t  i;

    if (!str || !remaind || !tmp || !buffer)
        return (-1);

    i = 0;
    while (buffer[i] && *buffer[i])
    {
        if (*buffer[i] == '\n')
        {
            *tmp = malloc(ft_strlen(*str) + i + 2);
            if (!*tmp) {
                free(*buffer);
                return (-1);
            }
            ft_strlcpy(*tmp, *str, -1);
            free(*str);
            ft_strlcpy(*tmp + ft_strlen(*tmp), *buffer, i + 2);
            ft_strlcpy(remaind, *buffer + i + 1, -1);
            free(*buffer);
            return (1);
        }
        i++;
    }
    return (0);
}

/*
get_next_line
- Purpose: Get the next line of a file everytime we call it
*/
char    *get_next_line(int fd)
{
    static char remaind[BUFFER_SIZE];
    char        *buffer = NULL;
    char        *str = NULL;
    char        *tmp = NULL;
    ssize_t     i;
    ssize_t     result;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    result = uno(remaind, &str, &tmp);
    if (result == -1)
        return (NULL);
    else if (result == 1)
        return (tmp);

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    ft_bzero(buffer, BUFFER_SIZE + 1);

    result = read(fd, buffer, BUFFER_SIZE);
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

        i = dos(remaind, &buffer, &str, &tmp);
        if (i == -1)
            return (NULL);
        else if (i == 1)
            return (tmp);

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
