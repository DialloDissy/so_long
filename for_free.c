/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:47:08 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/19 13:56:12 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_putstr(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}
}


void	ft_free_str(char **strf)
{
	int i;
	
	i =0;
	while(strf[i])
	{
		if (strf[i])
			free(strf[i]);
		i++;
	}
	free(strf);
}

void 
ft_exit_fail(t_game *mapping, char **strf, char *str)
{
	int i;
	
	i =0;
	ft_putstr(str);
	if(strf == NULL)
	{
		free(mapping);
		exit(EXIT_FAILURE);
	}
	while(strf[i])
	{
		if (strf[i])
			free(strf[i]);
		i++;
	}
	free(strf);
	free(mapping);
	exit(EXIT_FAILURE);
	
}
	
