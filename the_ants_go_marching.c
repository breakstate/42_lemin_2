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
	int		cycle;

	cycle = 0;
	current = head;
	while (current)
	{
		if (current->type == END)
			end_node = current;
		current = current->next;
	}
	while (end_node->end_count != num_ants)
	{
		ft_movecycle(head, &cycle);
	}
	ft_putstr("\nCompleted in [");
	ft_putnbr(cycle);
	ft_putstr("] cycles\n");
}

/*
**===================================================================
**	ft_move_cycle()
**	middle level loop,
**	calls single move function until all possible single moves made
*/

void		ft_movecycle(t_room *head, int *cycle)
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
	(*cycle)++;
}

/*
**===================================================================
**	ft_ifvalidmove()
**	outsources the following code for line reasons if ft_isvalid returns true
*/

void		ft_ifvalidmove(t_room *h, t_room *r, int *moved)
{
	h->end_count += (h->type == END) ? 1 : 0;
	if (r->type == STRT)
	{
		h->pop = r->num_ants - (r->pop - 1);
		r->pop--;
	}
	else
	{
		h->pop = r->pop;
		r->pop = 0;
		r->moved = FALSE;
	}
	h->moved += (h->type == NRML) ? 1 : 0;
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

int			ft_moveant(t_room *c, t_room *h)
{
	char	**split;
	int		moved;
	int		i;

	moved = FALSE;
	i = -1;
	split = ft_strsplit(c->links, ';');
	while (h && !moved)
	{
		while (split[++i] && !moved)
		{
			if (ft_strequ(split[i], h->id))
			{
				if (ft_isvalidmove(h, c))
				{
					ft_ifvalidmove(h, c, &moved);
					ft_printant(h, c);
				}
			}
		}
		i = -1;
		h = h->next;
	}
	ft_freearr(split);
	return (moved);
}
