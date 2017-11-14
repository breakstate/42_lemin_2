#include "lemin.h"

int		main(void)
{
	t_room	room_lst;
	int		num_ants;

	if ((num_ants = ft_count_ants()) < 1)
		return (-1);
	printf("num_ants main = %d\n", num_ants);//debug
	ft_read(&room_lst);
	return (0);
}