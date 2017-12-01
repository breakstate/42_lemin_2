/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:35:02 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/29 10:36:07 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
**	4/5
**
**	int		ft_countants();
**	void	ft_nodehandler();
**	void	ft_linkhandler();
**	int		ft_read();
*/

/*
**===================================================================
**	count_ants()
**	gets number of ants from file
*/

int			ft_countants(void)
{
	char	*line;
	int		num_ants;

	line = NULL;
	if (get_next_line(0, &line) < 1)
		ft_error("Error: invalid filedescriptor.");
	while (ft_iscomment(line))
	{
		ft_putendl(line);
		free(line);
		line = NULL;
		get_next_line(0, &line);
	}
	if (ft_atoi(line) < 1)
	{
		free(line);
		ft_putendl("Error: invalid number of ants.");
		exit(-1);
	}
	num_ants = ft_atoi(line);
	free(line);
	return (num_ants);
}

/*
**===================================================================
**	ft_nodehandler()
**	nodes sent here to be added to list
*/

void		ft_nodehandler(t_room **room_lst, char *line, int num_ants)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		get_next_line(0, &line);
		ft_lstaddf(room_lst, line, STRT, num_ants);
		ft_putendl(line);
		free(line);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		get_next_line(0, &line);
		ft_lstaddb(room_lst, line, END, num_ants);
		ft_putendl(line);
		free(line);
	}
	else if (ft_strlen(line) > 0)
	{
		ft_lstaddb(room_lst, line, NRML, num_ants);
	}
	else
	{
		free(line);
		ft_errorlist("Error: empty line.", *room_lst);
	}
}

/*
**===================================================================
**	ft_linkhandler()
**	links sent here to be added to nodes
*/

void		ft_linkhandler(t_room **room_lst, char *line)
{
	char	**str_arr;
	int		str_count;

	str_arr = ft_strsplitn(line, '-', &str_count);
	if (str_count != 2)
	{
		free(line);
		ft_freearr(str_arr);
		ft_errorlist("Error: link format error.", *room_lst);
	}
	ft_addlink(*room_lst, str_arr[0], str_arr[1]);
	ft_addlink(*room_lst, str_arr[1], str_arr[0]);
	ft_freearr(str_arr);
	str_arr = NULL;
}

/*
**	ft_ifcomment()
**	handles comments and protects against memory over runs
*/

void		ft_ifcomment(char **line, int *ret)
{
	free(*line);
	if ((*ret = get_next_line(0, line)) > 0)
	{
		ft_putendl(*line);		
	}
}

/*
**===================================================================
**	read()
**	parses rest of file after number of ants
*/

int			ft_read(t_room **room_lst, int num_ants)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_putendl(line);
		while (ft_iscomment(line) && ret > 0)
		{
			ft_ifcomment(&line, &ret);
		}
		if (!ft_strchr(line, '-'))
			ft_nodehandler(room_lst, line, num_ants);
		else
			ft_linkhandler(room_lst, line);
		free(line);
	}
	if (ret == -1)
	{
		free(line);
		ft_error("Error: get_next_line failed");
	}
	return (1);
}
