#include "lemin.h"

int		main(void)
{
	t_room	*room_lst;
	int		num_ants;

	room_lst = NULL;
	if ((num_ants = ft_countants()) < 1)
		return (-1);
	printf("num_ants main = %d\n", num_ants);//debug
	ft_read(&room_lst);
	ft_weight(room_lst, num_ants);
	//ft_validate()
	num_ants = 23;//debug and testing
	if (num_ants > 0)	
		ft_moveall(room_lst);
	else
		printf("you're running low on ants.\n");
	return (0);
	ft_freelist(room_lst);
}