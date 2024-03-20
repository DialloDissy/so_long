NAME = so_long

FLAG = -g -Wall -Wextra -Werror
CC = cc 
MLX = -L mlx -l mlx -I mlx -lXext -lX11 -lm -lz

SRC = so_long.c\
	parsing_map.c\
	get_next_line.c\
	get_next_line_utils.c\
	get_line_mapping.c\
	checking_map.c\
	checking_flood_fill.c\
	for_free.c\
	game.c\
	getting_map.c\
	getting_image.c\
	destroy.c\
	





OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	mv libft/libft.a .
	make -C mlx
	mv mlx/libmlx.a .
	$(CC) $(OBJ) -L. -lft -o $(NAME)  $(MLX)
	
%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<

clean:
	make -C libft clean
	make -C mlx clean
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) libft.a libmlx.a

re : fclean all

.PHONY : all clean fclean re

