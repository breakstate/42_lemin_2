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
	ft_startend(room_lst);
	printf("after ft_startend\n");
	ft_weight(room_lst, num_ants);
	printf("after weight\n");
	
	ft_print_list(room_lst);

	if (num_ants > 0)	
		ft_moveall(room_lst, num_ants);
	else
		printf("you're running low on ants.\n");
	return (0);
	ft_freelist(room_lst);
}