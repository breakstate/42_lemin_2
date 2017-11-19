#include "lemin.h"

/*
**	
**
**
*/

/*
**
*/
void	ft_setweight(t_room room_lst, t_room head)
{

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
		if (room_lst->type == NRML)
			ft_setweight(room_lst, head);
		room_lst = room_lst->next;
	}
	//set weight of start node
}