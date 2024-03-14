/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:37:38 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/14 14:27:40 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void check_count(t_game *mapping,char *map)
{
    int i;
    
    i = 0;
    while(map[i])
    {
        if( map[i] == 'P')
            mapping->count_p++;
        if( map[i] == 'E')
            mapping->count_e++;
        if( map[i] == 'C')
            mapping->count_c++;
        i++;      
    }   
}

int check_content(t_game *mapping)
{
    int i;
    i = 0;
    while(mapping->map[i])
    {
        check_count(mapping, mapping->map[i]);
        i++;
    }
    if(mapping->count_c == 1 && mapping->count_e == 1 & mapping->count_p == 1)
        return(1);
    return(0);
}

int check_rectangle(t_game *mapping)
{
    int i;
    int j;
    int standard;
    
    i = 0;
    standard = ft_strlen(&mapping->map[0][0]);
    while(mapping->map[i])
    {
        j = 0;
        while(mapping->map[i][j])
        {
            mapping->map_length++;
            j++;
        }
        if(standard != mapping->map_length)
            return(0);
        mapping->map_length = 0 ;
        i++;
    }
    return(1);
    
}
int check_close(t_game *mapping)
{
    int i;
    int j;
    int last_word;
    int last_str;

    i = 0;
    last_word = len_double_tab(mapping);
    while(mapping->map[0][i] && mapping->map[last_word - 1][i])
    {
        if(mapping->map[0][i] != '1')
            return(0);
        if(mapping->map[last_word - 1][i] != '1')
            return(0);
        i++;
    }
    j = 1;
    while(mapping->map[j] != mapping->map[last_word - 1])
    {
        i = 0;
        last_str = ft_strlen(mapping->map[j]);
        if(mapping->map[j][0] != '1')
            return(0);
        if()
        i++;
        j++;
    }
    return(1);
}


int check_map(t_game *mapping)
{
    if(!(check_content(mapping)))
        printf("\nprobleme de content\n");
    else 
        printf("\nnice check content\n");
    
    if(!(check_rectangle(mapping)))
        printf("probleme de rectangle\n");
    else
        printf("nice check rectangle\n");
    
    if(!(check_close(mapping)))
        printf("probleme de map close\n");
    else
        printf("nice check close\n");
    
    // if(!(check_flood_fill(mapping))) 

    return(1);
    
}
