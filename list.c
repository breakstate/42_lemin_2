#include "lemin.h"

t_room	*ft_newroom(char *line, int type)
{
	t_room	*new;
	char 	**split;
	int		split_num;

	new = (t_room *)malloc(sizeof(t_room));
	split = ft_strsplitn(line, ' ', &split_num);
	//if (!= 3) error
	new->id = ft_strdup(split[0]);
	new->type = type;
	new->weight = -1;
	new->populated = 0;
	new->links = ft_strnew(0);
	new->moved = 0;
	new->prev = "";
	new->next = NULL;
}

void	ft_lstaddf(t_room **room_lst, char *line, int type)
{
	t_room *temp;
	t_room *start;

	if (*room_lst)
	{
		temp = *room_lst;
		start = ft_newroom(line, type);
		start->next = temp;
		*room_lst = start;
	}
	else
		*room_lst = ft_newroom(line, type);
	//add error + free code
}

void	ft_lstaddb(t_room **room_lst, char *line, int type)
{
	t_room *current;

	current = *room_lst;
	if (*room_lst)
	{
		while (current->next)
			current = current->next;
		current->next = ft_newroom(line, type);
	}
	else
		*room_lst = ft_newroom(line, type);
	//add error + free code
}

void	ft_addlink(t_room **room_lst, char *l1, char *l2)
{

}

//ft_swaplinks;