/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_flood_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:51:55 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/19 11:17:15 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



char **get_copy_map(char ** copy, t_game *mapping)
{
    
    int i;

    i = 0;
    copy = (char**)malloc(sizeof(char*) * (mapping->map_heigth + 1));
    if(!copy)
        return(NULL);
      printf("copie de la mapping\n\n");  
    while( i < mapping->map_heigth )
    {
        copy[i] = ft_strdup(mapping->map[i]);
        printf("%s\n", copy[i]);
        i++;
    }
    copy[i] = NULL;

    return(copy);
    
}

void	flood_fill(t_game *mapping, int x, int y, char **copy)
{
	if (x >= mapping->map_length || y >= mapping->map_heigth || copy[y][x] == 'F')
		return ;
	if (copy[y][x] == '1')
		return ;
	if (copy[y][x] == 'E')
	{
		copy[y][x] = 'F';
		return ;
	}
	copy[y][x] = 'F';
	flood_fill(mapping, x + 1, y, copy);
	flood_fill(mapping, x - 1, y, copy);
	flood_fill(mapping, x, y + 1, copy);
	flood_fill(mapping, x, y - 1, copy);
	return ;
}





int check_flood_fill(t_game *mapping)
{
    char **copy;
    int i;
    int j;
    
    i =0;
    copy = NULL;
    copy = get_copy_map(copy,mapping);
    flood_fill(mapping,mapping->pos_x,mapping->pos_y,copy);
    printf("\napres  le remplissage\n");
    while(i < mapping->map_heigth)
    {
        j = 0;
        while(j < mapping->map_length)
        {
            if(copy[i][j] == 'C' || copy[i][j] == 'E')
            {
                ft_free_str(copy);              
                return(0); 
            }
            j++;
        }
        printf("%s\n", copy[i]);
        i++;
    }
    ft_free_str(copy);
    return(1);
}

