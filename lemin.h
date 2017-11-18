#ifndef _LEMIN_H_
# define _LEMIN_H_

# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include <stdio.h>//debug

# define NRML 0
# define STRT 1
# define END 2

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
int		ft_countants(void);

int		ft_read(t_room **room_lst);

/*
**	utilities.c
*/
int		ft_iscomment(char *str);
int		ft_isnumber(char *str);
void	ft_error(char *error);

#endif

/*
**	NOTES:
**
**	normal = 0, start = 1, end = 2
**
**	
*/