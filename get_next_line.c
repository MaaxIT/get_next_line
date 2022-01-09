/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeharpr <mpeharpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:34:51 by mpeharpr          #+#    #+#             */
/*   Updated: 2022/01/06 16:49:52 by mpeharpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
get_next_line
- Purpose: Get the next line of a file everytime we call it
*/
char    *get_next_line(int fd)
{
    static char remainder[BUFFER_SIZE];
    char        buffer[BUFFER_SIZE];
    char        *save;
    char        *result;
    long        i;

    i = 0;
    save = NULL;
    result = NULL;
    
    while (remainder[i])
    {
        if (remainder[i] == '\n') {
            result = malloc(i + 1);
            ft_strlcpy(result, remainder, i + 1);
            ft_strlcpy(remainder, remainder + i + 1, -1);
            ft_str_bzero(remainder + i + 1);
            return (result);
        }
        i++;
    }

    i = read(fd, buffer, BUFFER_SIZE);
    if (i <= 0)
        return (NULL);

    save = malloc(ft_strlen(remainder) + 1);
    ft_strlcpy(save, remainder, -1);

    i = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
        {
            result = malloc(ft_strlen(save) + i + 1);
            ft_strlcpy(result, save, -1);
            ft_strlcpy(result + ft_strlen(result), buffer, -1);
            free(save); 
            ft_str_bzero(remainder);
            ft_strlcpy(remainder, buffer + i + 1, -1);
            ft_str_bzero(buffer);
            return (result);
        }
        if (!buffer[i + 1])
        {
            save = ft_stradd(save, buffer);
            ft_str_bzero(buffer);
            i = read(fd, buffer, BUFFER_SIZE);
            if (i < 0)
            {
                free(save);
                return (NULL);
            }
            else if (i == 0)
            {
                result = ft_stradd(save, buffer);
                free(save);
                return (result);
            }
            i = 0;
            break ;
        }
        i++;
    }
    return (NULL);
}