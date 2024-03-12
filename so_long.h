/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:12:18 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/12 18:55:58 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "unistd.h"
#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 100
#endif 



char	*ft_strchr_gnl(char *str, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
size_t	ft_strlen_gnl(char *s);
char	*get_next_line(int fd);
char	*get_line(char *str);
char	*read_line(int fd, char *save);
char	*misssave(char *save);
int check_ber(char *av);



#endif
