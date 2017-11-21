#include "lemin.h"

/*
**	
**
**
*/

/*
**
*/
void	ft_setweight(t_room *room_lst, t_room *head)
{
	//if already set or weight is smaller, dont do anything
	//weight = w
	//split 


	//you're at a specific room
	//you go through the entire list looking for a room that is linked to the current room
	//once found set that room's weight to w+1;
}

/*
**
*/
void	ft_weight(t_room *room_lst)
{
	t_room	*head;

	head = room_lst;
	while (room_lst)
	{
		if (room_lst->type == END)
			ft_setweight(room_lst, head);
		room_lst = room_lst->next;
	}
	//set weight of start node
}