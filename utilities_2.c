#include "lemin.h"

/*
**	1/5
**
**	ft_free_list();
*/

/*
**===================================================================
**	ft_free_list();
**	frees linked list
*/

void	ft_freelist(t_room *room_lst)
{
	t_room	*temp;

	while (room_lst)
	{
		temp = room_lst->next;
		free(room_lst->id);
		free(room_lst->links);
		free(room_lst);
		room_lst = temp;
	}
}