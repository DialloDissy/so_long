/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidiallo <sidiallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:11:36 by sidiallo          #+#    #+#             */
/*   Updated: 2024/03/13 18:26:27 by sidiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"




int check_ber(char *av)
{
    int i ;

    i = 0;
    while(av[i])
    {
        if(av[i] == '.' && av[i+1] == 'b' && av[i +2] == 'e' && av[i + 3] == 'r' && av[i + 4] == '\0')
            return(1);
        i++;
    }
    return(0);
}


int main(int argc, char **argv)
{
    t_game  *mapping;
    
    
    if(argc == 2)
    {
        mapping = malloc(sizeof(t_game));
        if(!mapping)
            return(0);
        if(!(check_ber(argv[1])))
        {
            printf("bad\n");
            return(0);
        }
        get_line_map(argv[1],mapping);
        check_map(mapping);
 
        // if(!ft_pars_map(argv[1]), )
        // // printf("nice\n");
        // // fd = open("map.ber",O_RDWR );
        // // while ((line = get_next_line(fd)) != NULL)
        // // {
        // //     printf("Line : %s", line);
        // //     free(line);
        // // }
        // // close(fd);
        
        
    }
    return(0);
}
