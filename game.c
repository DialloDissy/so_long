/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:43:46 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/20 13:28:25 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int on_destroy(t_game*mapping)
// {
// 	mlx_destroy_window(mapping->mlx, mapping->window);
// 	mlx_destroy_display(mapping->mlx);
// 	free(mapping->mlx);
// 	exit(0);
// 	return (0);
// }


int on_keypress(int keysym, t_game *mapping)
{
	(void)mapping;
	printf("Pressed key: %d\n", keysym);
	return (0);
}


void init_game(t_game *mapping)
{
    mapping->mlx = mlx_init();
    mapping->window = mlx_new_window(mapping->mlx,mapping->map_length *64, mapping->map_heigth * 64, "so_long");
    if(!mapping->window)
        free(mapping->mlx);
    get_images(mapping);
    lauching_img(mapping);
    mlx_key_hook(mapping->window, on_keypress, mapping );
    mlx_loop(mapping->mlx);
    
    // mlx_destroy_window(mapping->mlx, mapping->window);
    // mlx_destroy_display(mapping->mlx);
    // mlx_hook(mapping->window, a, KeyReleaseMask, &on_keypress, mapping);
    
    free(mapping->mlx);
}