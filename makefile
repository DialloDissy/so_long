NAME = so_long

FLAG = -g -Wall -Wextra -Werror
CC = cc 

SRC = so_long.c\
	parsing_map.c\
	get_next_line.c\
	get_next_line_utils.c\
	




OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	mv libft/libft.a .
	$(CC) $(OBJ) -L. -lft -o $(NAME)
	
%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) libft.a

re : fclean all

.PHONY : all clean fclean re

