#include "lemin.h"

/*
**
**
**
*/

void	ft_resetmoved(t_room *head)
{
	while (head)
	{
		head->moved = FALSE;
		head = head->next;
	}
}

void	ft_cycle(t_room *head)
{

	//bubble sort flags
	//end cycle when all possible moves made
	//then go again.
}


/*
**	ft_move_ant()
**	receives populated room and head of list
**	moves ant to valid room linked to current room
**	returns true if move occured else false
*/

int		ft_move_ant(t_room *r, t_room *h)
{
	//assuming the room is populated
	char	**split;
	int		moved;
	int		i;

	moved = FALSE;
	i = 0;
	split = ft_strsplit(r->links, ';');
	while (h && !moved)
	{
		//printf("big while | head->id = [%s]\n", h->id);//debug
		while (split[i] && !moved)
		{
			//printf("little while | split[%d] = [%s]\n", i, split[i]);//debug
			if (ft_strequ(split[i], h->id))
			{
				//printf("big if\n");//debug
				if (h->w < r->w && h->pop == FALSE)
				{
					h->pop = r->pop;
					if (r->type == STRT)
						r->pop--;
					else
						r->pop = 0;
					h->moved = TRUE;
					h->prev = r->id;
					moved = TRUE;
					printf("ant[%d] moved from room[%s] to room[%s]\n", h->pop, r->id, h->id);
				}
			}
			i++;
		}
		i = 0;
		h = h->next;
	}
	ft_free_arr(split);
	return (moved);

	//receives a specific room to see if populated (unless this check happend before)
	//check all links of all nodes where a link = current node
	//moves to appropriate node

	//find unmoved ant
	//check if ant can make a valid move
	//move if yes, next ant if no. 
}