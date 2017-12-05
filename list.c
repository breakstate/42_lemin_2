/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:58:44 by bmoodley          #+#    #+#             */
/*   Updated: 2017/12/05 08:42:39 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	4/5
**
**	t_room	*ft_newroom();
**	void	ft_lstaddf();
**	void	ft_lstaddb();
**	void	ft_addlink();
*/

/*
**===================================================================
**	ft_newroom()
**	mallocs and initializes a new room struct node
*/

t_room		*ft_newroom(char **split, int type, int num_ants)
{
	t_room	*new;

	if ((new = (t_room *)malloc(sizeof(t_room))) == NULL)
	{
		ft_error("Error: malloc error.");
	}
	new->num_ants = num_ants;
	new->id = ft_strdup(split[0]);
	new->type = type;
	new->weight = -1;
	new->populated = FALSE;
	new->links = ft_strnew(0);
	new->moved = FALSE;
	new->next = NULL;
	new->end_count = 0;
	return (new);
}

/*
**===================================================================
**	ft_lstaddf()
**	adds node to front of list
*/

void		ft_lstaddf(t_room **room_lst, char *line, int type, int ants)
{
	t_room	*temp;
	t_room	*start;
	int		split_num;
	char	**split;

	split = ft_strsplitn(line, ' ', &split_num);
	if (split_num != 3)
	{
		ft_freearr(split);
		ft_errorlist("Error: room format error.", *room_lst);
	}
	if (*room_lst)
	{
		temp = *room_lst;
		start = ft_newroom(split, type, ants);
		start->next = temp;
		*room_lst = start;
	}
	else
		*room_lst = ft_newroom(split, type, ants);
	ft_freearr(split);
}

/*
**===================================================================
**	ft_lstaddb()
**	adds node to back of list
*/

void		ft_lstaddb(t_room **room_lst, char *line, int type, int ants)
{
	t_room	*current;
	int		split_num;
	char	**split;

	split = ft_strsplitn(line, ' ', &split_num);
	if (split_num != 3)
	{
		ft_freearr(split);
		ft_errorlist("Error: input format error.", *room_lst);
	}
	current = *room_lst;
	if (*room_lst)
	{
		while (current->next)
			current = current->next;
		current->next = ft_newroom(split, type, ants);
	}
	else
		*room_lst = ft_newroom(split, type, ants);
	ft_freearr(split);
}

/*
**===================================================================
**	ft_addlink()
**	adds link string to room node
*/

void		ft_addlink(t_room *room_lst, char *l1, char *l2)
{
	int		found;
	char	*tmp;

	found = FALSE;
	while (room_lst)
	{
		if (ft_strcmp(room_lst->id, l1) == 0)
		{
			found = TRUE;
			tmp = ft_strdup(l2);
			room_lst->links = ft_strjoinf(room_lst->links, tmp);
			room_lst->links = ft_strjoinf(room_lst->links, ";");
			free(tmp);
		}
		room_lst = room_lst->next;
	}
	if (found == FALSE)
	{
		ft_error("Error: link error");
		ft_freelist(room_lst);
		exit(-1);
	}
}
