/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:58:44 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/23 16:00:17 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	5/5
**
**	t_room	*ft_newroom();
**	void	ft_lstaddf();
**	void	ft_lstaddb();
**	void	ft_addlink();
**	void	ft_print_list(); debug
*/

/*
**===================================================================
**	ft_newroom()
**	mallocs and initializes a new room struct node
*/

t_room		*ft_newroom(char *line, int type)
{
	t_room	*new;
	char	**split;
	int		split_num;

	new = (t_room *)malloc(sizeof(t_room));
	split = ft_strsplitn(line, ' ', &split_num);
	//if (!= 3) error
	new->id = ft_strdup(split[0]);
	new->type = type;
	new->weight = -1;
	new->populated = FALSE;
	new->links = ft_strnew(0);
	new->moved = FALSE;
	new->next = NULL;
	ft_freearr(split);
	return (new);
}

/*
**===================================================================
**	ft_lstaddf()
**	adds node to front of list
*/

void	ft_lstaddf(t_room **room_lst, char *line, int type)
{
	t_room *temp;
	t_room *start;

	if (*room_lst)
	{
		temp = *room_lst;
		start = ft_newroom(line, type);
		start->next = temp;
		*room_lst = start;
	}
	else
		*room_lst = ft_newroom(line, type);
	//add error + free code
}

/*
**===================================================================
**	ft_lstaddb()
**	adds node to back of list
*/

void	ft_lstaddb(t_room **room_lst, char *line, int type)
{
	t_room *current;

	current = *room_lst;
	if (*room_lst)
	{
		while (current->next)
			current = current->next;
		current->next = ft_newroom(line, type);
	}
	else
		*room_lst = ft_newroom(line, type);
	//add error + free code
}

/*
**===================================================================
**	ft_addlink()
**	adds link string to room node
*/

void	ft_addlink(t_room *room_lst, char *l1, char *l2)
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
			room_lst->links = ft_strjoinf(room_lst->links, tmp);//fix strjoinf
			room_lst->links = ft_strjoinf(room_lst->links, ";");//fix strjoinf
			free(tmp);
		}
		room_lst = room_lst->next;
	}
	if (found == FALSE)
	{
		ft_error("Error: link error");
	}
}

/*	
**===================================================================
**	ft_print_list()
**	prints list designated by head for debugging purposes
*/

void	ft_print_list(t_room *head)//for debugging purposes
{
	char *type;

	//printf("\n***LIST***:\n");
	while (head)
	{
		if (head->type == STRT)
			type = "STRT";
		else if (head->type == END)
			type = "END";
		else 
			type = "NRML";
		//printf("node id: [%s] | type:[%s] | weight: [%d] | pop = [%d] | links: [%s]\n", head->id, type, head->weight, head->pop, head->links);
		head = head->next;
	}
	//printf("\ndone\n");
}
