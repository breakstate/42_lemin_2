#include "lemin.h"

/*
**
**
*/

/*
**===================================================================
**	ft_nhhelper();
**	handles cases besides ##start or ##end
*/

void	ft_nhhelper(t_room **room_lst, char *line)
{
	//printf("ft_nhhelper: line = [%s]\n", line);
	if (ft_strchr(line, '#') != NULL)
	{
		free(line);
		ft_putendl(line);
	}
	else if (ft_strlen(line) < 1)
	{
		free(line);
		ft_errorlist("Error: empty line.", *room_lst);
	}
	else
		ft_lstaddb(room_lst, line, NRML, 0);
}