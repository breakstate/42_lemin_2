#include "lemin.h"

/*
**	ft_iscomment()
**	takes a string and checks if is comment or not
*/
int		ft_iscomment(char *str)
{
	if (ft_strlen(str) > 0 && str[0] == '#' && str[1] != '#')
		return (1);
	return (0); 
}

/*
**	ft_isnumber()
**	takes string and checks if valid number
**	uses ptrarith so test
*/
int		ft_isnumber(char *str)
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
