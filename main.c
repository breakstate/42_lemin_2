/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:57:14 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/23 15:58:18 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(void)
{
	t_room	*room_lst;
	int		num_ants;

	room_lst = NULL;
	if ((num_ants = ft_countants()) < 1)
		return (-1);
	ft_putnbr_endl(num_ants);
	ft_read(&room_lst);
	ft_startend(room_lst);
	ft_weight(room_lst, num_ants);
	ft_putendl("");
	if (num_ants > 0)
		ft_moveall(room_lst, num_ants);
	else
		ft_putstr("Error: you're running low on ants.\n");
	ft_freelist(room_lst);
	return (0);
}
