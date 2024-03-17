/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:12:18 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/14 13:57:08 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct
{
	int		map_heigth;
	int		map_length;
	int		count_p;
	int		count_e;
	int		count_c;
	int		step;
	char	**map;
	void	*mlx;
	void	*window;

}			t_game;

char		*ft_strchr_gnl(char *str, int c);
char		*ft_strjoin_gnl(char *s1, char *s2);
size_t		ft_strlen_gnl(char *s);
char		*get_next_line(int fd);
char		*get_line(char *str);
char		*read_line(int fd, char *save);
char		*misssave(char *save);
int			check_ber(char *av);
void		get_line_map(char *argv, t_game *mapping);
char		*double_backslash(char *str);
int			check_ber(char *av);
int			check_map(t_game *map);
int			check_content(t_game *mapping);
void		check_count(t_game *mapping, char *map);
int			check_rectangle(t_game *mapping);
int len_double_tab(t_game *mapping);

#endif
