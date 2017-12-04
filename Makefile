NAME = lemin

SRC = main.c \
		parse.c \
		parse_2.c \
		utilities.c \
		utilities_2.c \
		list.c \
		val_and_out.c \
		weight.c \
		the_ants_go_marching.c

FLAGS = -Wall -Werror -Wextra -g 

LIBFT = -L ./libft -lft 

INCLUDES = -I lemin.h

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft 
	gcc -g -o $(NAME) $(SRC) $(LIBFT)

clean: 
	rm -f $(NAME)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all