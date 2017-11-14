#include "lemin.h"

/*
**	count_ants()
**	gets number of ants from file
*/
int		ft_count_ants(void)
{
	char	*line;
	int		num_ants;

	line = NULL;
	if (get_next_line(0, &line) < 1)
		ft_putendl("ERROR1");//error, incorrect file format
	while (ft_iscomment(line))
	{
		ft_putendl(line);
		free(line);
		line = NULL;
		get_next_line(0, &line);
	}
	if (!ft_isnumber(line) || ft_atoi(line) < 1)
	{
		free(line);
		ft_putendl("ERROR2");//error, invalid number of ants
		return (-1);
	}
	num_ants = ft_atoi(line);
	free(line);
	return (num_ants);
}

/*
**	read()
**	parses rest of file after number of ants
*/
int		ft_read(t_room **room_lst)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		//print
		while (ft_iscomment(line))
		{
			free(line);
			get_next_line(0, &line);
			//print
		}
		if (!ft_strchr(line, '-'))
		{
			//ft_newnode
		}
		else
		{
			//ft_newlink
		}
		//free(line)
	}
	//if gnl == -1 return -1?
	free(line);
	return (1);
}