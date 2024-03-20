/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_mapping.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:00:33 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/19 14:39:19 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*double_backslash(char *str, t_game *mapping)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			ft_exit_fail(mapping, mapping->map,"error some backslashs\n");
		}	
		i++;
	}
	return (str);
}

int	len_double_tab(t_game *mapping)
{
	int	i;

	i = 0;
	while (mapping->map[i])
		i++;
	return (i);
}

int	get_line_map(char *argv, t_game *mapping)
{
	int		fd;
	char	*line;
	char	*long_line;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0); // voir si c'est bien freeable
	long_line = get_next_line(fd);
	while ((line = get_next_line(fd)) != NULL)
	{
		long_line = ft_strjoin_gnl(long_line, line);
		free(line);
	}
    free(line);
	if(!long_line)
		ft_exit_fail(mapping,mapping->map,"error line\n");
	double_backslash(long_line, mapping);
	mapping->map = ft_split(long_line, '\n');
	free(long_line);
	while (mapping->map[i])
	{
		printf("%s\n", mapping->map[i]);
		mapping->map_heigth++;
		i++;
	}
	close(fd);
	return (1);
}

