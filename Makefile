NAME = lemin

SRC = main.c \
		parse.c \
		utilities.c \
		list.c

FLAGS = -Wall -Werror -Wextra -g 

LIBFT = -L ./libft -lft 

INCLUDES = -I lemin.h

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft 
	gcc -o $(NAME) $(SRC) $(LIBFT)

clean: 
	rm -f $(NAME)
	$(MAKE) clean -C ./libft

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all