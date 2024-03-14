/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_mapping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:00:33 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/14 13:56:56 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char    *double_backslash(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] == '\n' && str[i+1] == '\n')
            exit(EXIT_FAILURE);
        i++;
    }
    return(str);
}

int len_double_tab(t_game *mapping)
{
    int i;
    
    i = 0;
    while(mapping->map[i])
        i++;
    return(i);
}



void  get_line_map(char *argv,t_game *mapping)
{
    int fd;
    char *line;
    char *long_line;
    int i = 0;
    
    fd = open(argv, O_RDONLY);
    long_line = ft_strdup(get_next_line(fd));
    while ((line = get_next_line(fd)) != NULL)
        long_line = ft_strjoin_gnl(long_line,line);
    double_backslash(long_line);
    mapping->map = ft_split(long_line, '\n');

    while(mapping->map[i])
    {
        printf(" %s", mapping->map[i]);
        i++;
    }
    
    close(fd);     
}


