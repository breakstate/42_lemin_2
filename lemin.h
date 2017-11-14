#ifndef _LEMIN_H_
# define _LEMIN_H_

# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include <stdio.h>//debug

typedef struct		s_room
{
	char			*id;
	char			*prev;
	int				type;
	int				x;
	int				y;
	int				weight;
	int				populated;
	char			*links;
	int				moved;
	struct s_room	*next;
}					t_room;

/*
**	parse.c
*/
int		ft_count_ants(void);

/*
**	utilities.c
*/
int		ft_iscomment(char *str);
int		ft_isnumber(char *str);

#endif