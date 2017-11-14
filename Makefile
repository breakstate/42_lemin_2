NAME = lemin

SRC = main.c \
		parse.c \
		utilities.c

FLAGS = -Wall -Werror -Wextra -g 

LIBFT = -L ./libft.libft.a -lft 

INCLUDES = -I lemin.h

all: $(NAME)

$(NAME):
	make -C ./libft 
	gcc -o $(NAME) $(SRC) $(LIBFT) $(INCLUDES)

clean: 
	rm -f $(NAME)

fclean: clean

re: fclean all