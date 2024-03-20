/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:43:56 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/20 13:38:33 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void    take_image(t_game *mapping, char *path,void **img_ptr)
{
    int height;
    int widht;

    height = 0;
    widht = 0;
    
    *img_ptr = mlx_xpm_file_to_image(mapping->mlx, path, &widht,&height);
    if(*img_ptr == NULL)
    {
        printf("fail to laoding image\n");
        //fonction pour close game
    }
}


void put_image_window(t_game *map, char c, int x, int y)
{
    if(c == '0')
    mlx_put_image_to_window(map->mlx, map->window, map->img.floor,x *64,y *64);
    
    
}



void    lauching_img(t_game *mapping)
{
    int	x;
	int	y;

	y = 0;
	while (mapping->map[y])
	{
		x = 0;
		while (mapping->map[y][x])
		{
			put_image_window(mapping, mapping->map[y][x], x, y);
			x++;
		}
		y++;
	}
}





void get_images(t_game *mapping)
{
    // remplissge de tout les icones, floor, collectible,player,spawn, wall,enemy
    take_image(mapping, "image/Floor.xpm",(void **)&mapping->img.floor);
//     put_image(mapping, "image/Floor.xpm",(void **)&mapping->img.floor);
//     put_image(mapping, "image/Floor.xpm",(void **)&mapping->img.floor);
}