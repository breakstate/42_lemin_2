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
	printf("preweight\n");
	ft_weight(room_lst, num_ants);
	ft_print_list(room_lst);
	while (ft_move_ant(room_lst, room_lst))
		ft_print_list(room_lst);	
	return (0);
}