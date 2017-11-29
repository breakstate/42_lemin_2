/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:41:02 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/29 10:41:05 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		ft_freelist(t_room *room_lst)
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

/*
**===================================================================
**	ft_error()
**	takes string to be used as error message, prints and exits
*/

void		ft_errorlist(char *error, t_room *head)
{
	ft_putendl(error);
	ft_freelist(head);
	exit(-1);
}
