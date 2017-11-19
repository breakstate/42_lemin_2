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
void	ft_nodehandler(t_room **room_lst, char *line);
void	ft_linkhandler(t_room **room_lst, char *line);
int		ft_read(t_room **room_lst);

/*
**	utilities.c
*/
void	ft_free_arr(char **arr);
void	ft_error(char *error);
int		ft_iscomment(char *str);
int		ft_isnumber(char *str);

/*
**	list.c
*/
t_room	*ft_newroom(char *line, int type);
void	ft_lstaddf(t_room **room_lst, char *line, int type);
void	ft_lstaddb(t_room **room_lst, char *line, int type);
void	ft_addlink(t_room **room_lst, char *l1, char *l2);
void	ft_print_list(t_room *head);//debug




#endif

/*
**	NOTES:
**
**	normal = 0, start = 1, end = 2
**
**	
*/