/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:43:06 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/29 10:43:07 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	links = ft_strsplitn(room->links, ';', &n);
	room = head;
	while (room)
	{
		i = -1;
		while (links[++i])
			if (ft_strequ(links[i], room->id))
				ft_setweight(room, head, w + 1);
		room = room->next;
	}
	ft_freearr(links);
}

/*
**===================================================================
**	ft_weight()
**	sends end room as starting point to ft_setweight, as well as head of list
**	as well as initial weight of end (0)
**	set start weight used to be 1000
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
	if (head->weight == -1 && head->type == STRT)
	{
		ft_freelist(head);
		ft_error("Error: There is no viable path.");
	}
	if (head->type == STRT)
	{
		head->populated = num_ants;
	}
	else
	{
		ft_freelist(room_lst);
		ft_error("Error: No start node.");
	}
}
