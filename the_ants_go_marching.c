/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_ants_go_marching.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:36:50 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/29 10:38:26 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	5/5
**
**	void	ft_resetmoved();
**	void	ft_move_all();
**	void	ft_move_cycle();
**	void	ft_ifvalidmove();
**	int		ft_move_ant();
*/

/*
**===================================================================
**	ft_resetmoved()
**	resets all ->moved values to 0
*/

void		ft_resetmoved(t_room *head)
{
	while (head)
	{
		head->moved = FALSE;
		head = head->next;
	}
}

/*
**===================================================================
**	ft_move_all()
**	highest level loop, calls cycle function until ultimate end cond
*/

void		ft_moveall(t_room *head, int num_ants)
{
	t_room	*end_node;
	t_room	*current;

	current = head;
	while (current)
	{
		if (current->type == END)
			end_node = current;
		current = current->next;
	}
	while (end_node->populated != num_ants)
	{
		ft_movecycle(head);
	}
}

/*
**===================================================================
**	ft_move_cycle()
**	middle level loop,
**	calls single move function until all possible single moves made
*/

void		ft_movecycle(t_room *head)
{
	t_room	*c;
	int		moved;

	ft_resetmoved(head);
	moved = 0;
	c = head;
	while (c)
	{
		if (c->populated && c->moved == FALSE)
		{
			moved += ft_moveant(c, head);
		}
		c = c->next;
		if (moved)
		{
			moved = 0;
			c = head;
		}
	}
	ft_putstr("\n");
	ft_print_list(head);
}

/*
**===================================================================
**	ft_ifvalidmove()
**	outsources the following code for line reasons if ft_isvalid returns true
*/

void		ft_ifvalidmove(t_room *h, t_room *r, int *moved)
{
	if (h->type != END)
		h->pop = r->pop;
	else
		h->pop++;
	if (r->type == STRT)
		r->pop--;
	else
	{
		r->pop = 0;
		r->moved = FALSE;
	}
	if (h->type == NRML)
	{
		h->moved = TRUE;
	}
	*moved = TRUE;
}

/*
**===================================================================
**	ft_move_ant()
**	receives populated room and head of list
**	moves single ant to valid room
**	(split over two functions)
**	h is dest, r is src
*/

int			ft_moveant(t_room *r, t_room *h)
{
	char	**split;
	int		moved;
	int		i;
	t_room	*debug;

	debug = h;
	printf("moveant\n");//debug
	moved = FALSE;
	i = -1;
	split = ft_strsplit(r->links, ';');
	while (h && moved == FALSE)
	{
		while (split[++i] && moved == FALSE)
		{
			if (ft_strequ(split[i], h->id))
			{
				if (ft_isvalidmove(h, r))
				{
					ft_ifvalidmove(h, r, &moved);
					if (moved == TRUE)
						ft_printant(h, r);
					ft_print_list(debug);
				}
			}
		}
		//printf("moved ant [%d] from room[%s] to room[%s]\n", h->pop, r->id, h->id);//debug;
		i = -1;
		h = h->next;
	}
	ft_freearr(split);
	return (moved);
}
