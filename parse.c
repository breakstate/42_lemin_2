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
int		ft_countants(void)
{
	char	*line;
	int		num_ants;

	line = NULL;
	if (get_next_line(0, &line) < 1)
		ft_putendl("ERROR1");//does not free or exit
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
**===================================================================
**	ft_nodehandler()
**	nodes sent here to be added to list
*/
void	ft_nodehandler(t_room **room_lst, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		get_next_line(0, &line);
		//printf("ft_lstaddf\n");//debug		
		ft_lstaddf(room_lst, line, STRT);
		printf("line = %s\n", line);//debug
		//print
		free(line);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		get_next_line(0, &line);
		//printf("ft_lstaddb\n");//debug
		ft_lstaddb(room_lst, line, END);
		printf("line = %s\n", line);//debug		
		//print
		free(line);
	}
	else 
	{
		//printf("ft_lstaddb other\n");//debug
		ft_lstaddb(room_lst, line, NRML);
	}
}

/*
**===================================================================
**	ft_linkhandler()
**	links sent here to be added to nodes
*/
void	ft_linkhandler(t_room **room_lst, char *line)
{
	char	**str_arr;
	int		str_count;

	str_arr = ft_strsplitn(line, '-', &str_count);
	if (str_count != 2)
		ft_error("Error: Format error");
	//check_str_arr;
	//printf("ft_addlink1 [%s]\n", line);//debug
	ft_addlink(*room_lst, str_arr[0], str_arr[1]);
	ft_addlink(*room_lst, str_arr[1], str_arr[0]);
	//printf("swap links\n");//debug
	//ft_swaplinks;
	//printf("ft_addlink2\n");//debug	<---
	//ft_addlink(room_lst, str_arr);
	//free_arr
}

/*
**===================================================================
**	read()
**	parses rest of file after number of ants
*/
int		ft_read(t_room **room_lst)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		//print
		while (ft_iscomment(line))
		{
			free(line);
			get_next_line(0, &line);
			//print
		}
		if (!ft_strchr(line, '-'))
			ft_nodehandler(room_lst, line);
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