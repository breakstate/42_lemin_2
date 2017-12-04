/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:38:55 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/29 11:21:50 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	5/5
**
**	int		ft_isvalidmove();
**	void	ft_free_arr();
**	void	ft_error();
**	int		ft_iscomment();
**	int		ft_isnumber();
*/

/*
**===================================================================
**	ft_isvalidmove()
**	verifies if move from src to dst is valid given conditions
*/

int			ft_isvalidmove(t_room *dest, t_room *src)
{
	if (dest->W < src->W && (dest->POP == 0 || dest->type == END)
	&& src->moved == 0 && src->POP > 0)
		return (1);
	return (0);
}

/*
**===================================================================
**	ft_free_arr()
**	frees passed in 2D array
*/

void		ft_freearr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}

/*
**===================================================================
**	ft_error()
**	takes string to be used as error message, prints and exits
*/

void		ft_error(char *error)
{
	ft_putendl(error);
	exit(-1);
}

/*
**===================================================================
**	ft_iscomment()
**	takes a string and checks if is comment or not
*/

int			ft_iscomment(char *str)
{
	if (ft_strlen(str) > 0 && ft_strchr(str, '#') != NULL &&
	ft_strcmp("##start", str) != 0 && ft_strcmp("##end", str) != 0
	&& ft_strchr(str, '#'))
	{
		return (1);
	}
	return (0);
}

/*
**===================================================================
**	ft_isnumber()
**	takes string and checks if valid number
**	uses ptrarith so test
*/

int			ft_isnumber(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
