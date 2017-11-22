#ifndef _LEMIN_H_
# define _LEMIN_H_

# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include <stdio.h>//debug

# define NRML 0
# define STRT 1
# define END 2
# define TRUE 1
# define FALSE 0
# define UNSET -1
# define pop populated
# define w weight

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
**	the_ants_go_marching.c
*/
void	ft_resetmoved(t_room *head);
void	ft_moveall(t_room *head);
void	ft_movecycle(t_room *head, int *num_cycles);
void	ft_ifvalidmove(t_room *h, t_room *r, int *moved);
int		ft_moveant(t_room *r, t_room *h);

/*
**	weight.c
*/
void	ft_weight(t_room *room_lst, int num_ants);
void	ft_setweight(t_room *room, t_room *head, int w);

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
int		ft_isvalidmove(t_room *dest, t_room *src);
void	ft_freearr(char **arr);
void	ft_error(char *error);
int		ft_iscomment(char *str);
int		ft_isnumber(char *str);

/*
**	utilities_2.c
*/
void	ft_freelist(t_room *room_lst);

/*
**	list.c
*/
t_room	*ft_newroom(char *line, int type);
void	ft_lstaddf(t_room **room_lst, char *line, int type);
void	ft_lstaddb(t_room **room_lst, char *line, int type);
void	ft_addlink(t_room *room_lst, char *l1, char *l2);
void	ft_print_list(t_room *head);//debug


#endif

/*
**	NOTES:
**
**	normal = 0, start = 1, end = 2
**
**	
*/