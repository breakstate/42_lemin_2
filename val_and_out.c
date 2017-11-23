#include "lemin.h"

/*
**	2/5
**
**	ft_startend();
*/

/*
**===================================================================
**	ft_startend()
**	checks if start and end node exist and are not duplicates
*/

int		ft_startend(t_room *head)
{
	t_room	*current;
	int		strt;
	int		end;

	strt = 0;
	end = 0;
	current = head;
	while (current)
	{
		if (current->type == STRT)
			strt++;
		if (current->type == END)
			end++;
		current = current->next;
	}
	if (strt != 1 && end != 1)
	{
		ft_freelist(head);
		ft_error("Error: incorrect amount of start/end rooms.");
		exit(-1);
	}
	return (1);
}