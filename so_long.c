/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:11:36 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/19 16:46:37 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.' && av[i + 1] == 'b' && av[i + 2] == 'e' && av[i
			+ 3] == 'r' && av[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*mapping;

	if (argc == 2)
	{
		if (!(check_ber(argv[1])))
			return (0);
		mapping = malloc(sizeof(t_game));
		if (!mapping)
			return (0);
		ft_bzero(mapping, sizeof(t_game));
		if (!(get_line_map(argv[1], mapping)))
			ft_exit_fail(mapping, mapping->map, "erreur get line\n");
		if (!check_map(mapping))
			ft_exit_fail(mapping, mapping->map, "erreur check map\n");
		init_game(mapping);
		// mlx_hook;
		// mlx_hook;
		// mlx_loop;
		ft_free_str(mapping->map);
		free(mapping);
	}
	return (0);
}
