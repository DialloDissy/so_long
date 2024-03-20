/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:12:18 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/20 13:39:49 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "fcntl.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct
{
	void	*floor;
	void	*collect;
	void	*wall;
	void	*exit;
	
}			t_img;

typedef struct
{
	int		pos_x;
	int		pos_y;
	int		map_heigth;
	int		map_length;
	int		count_p;
	int		count_e;
	int		count_c;
	int		step;
	char	**map;
	void	*mlx;
	void	*window;
	t_img	img;

}			t_game;

char		*ft_strchr_gnl(char *str, int c);
char		*ft_strjoin_gnl(char *s1, char *s2);
size_t		ft_strlen_gnl(char *s);
char		*get_next_line(int fd);
char		*get_line(char *str);
char		*read_line(int fd, char *save);
char		*misssave(char *save);
int			check_ber(char *av);
// void		get_line_map(char *argv, t_game *mapping);
int			get_line_map(char *argv, t_game *mapping);
char		*double_backslash(char *str, t_game *mapping);
int			check_ber(char *av);
int			check_map(t_game *map);
int			check_content(t_game *mapping);
// void		check_count(t_game *mapping, char *map);
void		check_count(t_game *mapping, char *map, char i);
int			check_rectangle(t_game *mapping);
int			len_double_tab(t_game *mapping);
int			check_flood_fill(t_game *mapping);
char		**get_copy_map(char **copy, t_game *mapping);
void		flood_fill(t_game *mapping, int x, int y, char **copy);
void		ft_free_str(char **strf);
void		ft_putstr(char *str);
void		ft_exit_fail(t_game *mapping, char **strf, char *str);
void		init_game(t_game *mapping);
void		get_images(t_game *mapping);
void		take_image(t_game *mapping, char *path, void **img_ptr);
void		put_image_window(t_game *mapping, char c, int x, int y);
void		lauching_img(t_game *mapping);

#endif
