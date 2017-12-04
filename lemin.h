/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:48:12 by bmoodley          #+#    #+#             */
/*   Updated: 2017/12/04 14:48:16 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

# define NRML 0
# define STRT 1
# define END 2
# define TRUE 1
# define FALSE 0
# define UNSET -1
# define POP populated
# define W weight

typedef struct	s_r
{
	int			num_ants;
	char		*id;
	int			type;
	int			x;
	int			y;
	int			weight;
	int			populated;
	char		*links;
	int			moved;
	int			end_count;
	struct s_r	*next;
}				t_room;

/*
**	the_ants_go_marching.c
*/
void			ft_resetmoved(t_room *head);
void			ft_moveall(t_room *head, int num_ants);
void			ft_movecycle(t_room *head, int *cycle);
void			ft_ifvalidmove(t_room *h, t_room *r, int *moved);
int				ft_moveant(t_room *c, t_room *h);

/*
**	weight.c
*/
void			ft_weight(t_room *room_lst, int num_ants);
void			ft_setweight(t_room *room, t_room *head, int w);

/*
**	parse.c
*/
int				ft_countants(void);
void			ft_nodehandler(t_room **room_lst, char *line, int num_ants);
void			ft_linkhandler(t_room **room_lst, char *line);
void			ft_ifcomment(char **line, int *ret);
int				ft_read(t_room **room_lst, int num_ants);

/*
**	parse_2.c
*/
void			ft_nhhelper(t_room **room_lst, char *line);

/*
**	utilities.c
*/
int				ft_isvalidmove(t_room *dest, t_room *src);
void			ft_freearr(char **arr);
void			ft_error(char *error);
int				ft_iscomment(char *str);
int				ft_isnumber(char *str);

/*
**	utilities_2.c
*/
void			ft_freelist(t_room *room_lst);
void			ft_errorlist(char *error, t_room *head);

/*
**	list.c
*/
t_room			*ft_newroom(char **split, int type, int num_ants);
void			ft_lstaddf(t_room **room_lst, char *line, int type, int ants);
void			ft_lstaddb(t_room **room_lst, char *line, int type, int ants);
void			ft_addlink(t_room *room_lst, char *l1, char *l2);

/*
**	val_and_out.c
*/
int				ft_startend(t_room *room_lst);
void			ft_printant(t_room *dest, t_room *src);

#endif

/*
**	NOTES:
**	normal = 0, start = 1, end = 2
*/
