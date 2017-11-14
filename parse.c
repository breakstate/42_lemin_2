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
		ft_putendl("ERROR");//error, incorrect file format
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
		ft_putendl("ERROR");//error, invalid number of ants
	}
	num_ants = ft_atoi(line);
	free(line);
	return (num_ants);
}