#include "lemin.h"

/*
**	2/5
**
**	void	ft_weight();
**	void	ft_setweight();
*/

/*
**===================================================================
**	ft_setweight()
**	recursively traverses list of rooms, setting weights, starting from END
** w is initial weight of END (0)
*/

void	ft_setweight(t_room *room, t_room *head, int w)
{
	char	**links;
	int		n;
	int		i;

	if (room->weight != UNSET && room->weight <= w)
		return ;
	room->weight = w;
	links = ft_strsplitn(room->links, ';', &n);//note: doesn't change per room (only has links of room received as arg)
	room = head;
	while (room)
	{
		i = -1;
		while (links[++i])
			if (ft_strequ(links[i], room->id))
				ft_setweight(room, head, w + 1);
		room = room->next;
	}
	ft_free_arr(links);
}

/*
**===================================================================
**	ft_weight()
**	sends end room as starting point to ft_setweight, as well as head of list
**	as well as initial weight of end (0)
*/

void	ft_weight(t_room *room_lst, int num_ants)
{
	t_room	*head;

	head = room_lst;
	while (room_lst)
	{
		if (room_lst->type == END)
			ft_setweight(room_lst, head, 0);
		room_lst = room_lst->next;
	}
	head->weight = num_ants;//alternatively set to like infinity
	head->populated = num_ants;//set to num_ants to assign from file
}