#include "lemin.h"

/*
**	ft_free_arr()
**	frees passed in 2D array
*/
void	ft_free_arr(char **arr)//plz test
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
	}
	free(arr[i]);	
	free(arr);
}	

/*
**	ft_error()
**	takes string to be used as error message, prints and exits
*/
void	ft_error(char *error)
{
	ft_putendl(error);
	exit(-1);
}

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
