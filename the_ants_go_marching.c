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

void	ft_resetmoved(t_room *head)
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

void	ft_move_all(t_room *head)
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
	while (end_node->populated != 1)
	{
		ft_move_cycle(head);
	}
}

/*
**===================================================================
**	ft_move_cycle()
**	middle level loop, calls single move function until all possible single moves made
*/

void	ft_move_cycle(t_room *head)
{
	t_room *c;
	int		moved;

	ft_resetmoved(head);
	moved = 0;
	c = head;
	while (c)
	{
		if (c->populated && c->moved == FALSE)
		{
			moved += ft_move_ant(c, head);
		}
		c = c->next;
		if (moved)
		{
			moved = 0;
			c = head;
		}
	}
	printf("end cycle\n\n");
}

/*
**===================================================================
**	ft_ifvalidmove()
**	outsources the following code for line reasons if ft_isvalid returns true
*/

void	ft_ifvalidmove(t_room *h, t_room *r, int *moved)
{
	h->pop = r->pop;
	if (r->type == STRT)
		r->pop--;
	else
		r->pop = 0;
	if (h->type == NRML)
	{	
		h->moved = TRUE;
	}
	h->prev = r->id;
	*moved = TRUE;
}

/*
**===================================================================
**	ft_move_ant()
**	receives populated room and head of list
**	moves single ant to valid room
**	(split over two functions)
*/

int		ft_move_ant(t_room *r, t_room *h)
{
	char	**split;
	int		moved;
	int		i;

	moved = FALSE;
	i = -1;
	split = ft_strsplit(r->links, ';');
	while (h && !moved)
	{
		while (split[++i] && !moved)
		{
			if (ft_strequ(split[i], h->id))
			{
				if (ft_isvalidmove(h, r))//h->w < r->w && (h->pop == FALSE || h->type == END))//&& h->id != r->prev
				{
					ft_ifvalidmove(h, r, &moved);
					printf("ant[%d] moved from room[%s] to room[%s]\n", h->pop, r->id, h->id);
				}
			}
		}
		i = -1;
		h = h->next;
	}
	ft_free_arr(split);
	return (moved);
}