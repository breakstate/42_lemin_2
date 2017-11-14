/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 12:56:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/09/05 15:02:58 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include "includes/libft.h"

static	void	new_malloc(char *buf, char **new, int pos, int i)
{
	char		*temp;
	char		*temp2;

	if (*new == NULL)
	{
		if (buf[pos] != '\0')
			*new = ft_strsub(buf, pos, i);
	}
	else
	{
		temp2 = ft_strsub(buf, pos, i);
		temp = ft_strdup(*new);
		free(*new);
		*new = ft_strjoin(temp, temp2);
		free(temp);
		free(temp2);
	}
}

static int		buf_parse(char *buf, char **new, int *pos, char **line)
{
	int			i;

	i = *pos;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			new_malloc(buf, new, *pos, i - *pos);
			*pos = i + 1;
			*line = *new;
			return (1);
		}
		i++;
	}
	new_malloc(buf, new, *pos, i - *pos);
	*pos = -1;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static int	r = -2;
	static char	buf[BUFF_SIZE + 1];
	static int	pos = -1;
	char		*new;

	new = NULL;
	while (42)
	{
		if (pos == -1)
		{
			ft_bzero(buf, BUFF_SIZE + 1);
			r = read(fd, buf, BUFF_SIZE);
			pos = 0;
		}
		if (r == 0 || r == -1)
		{
			if (new == NULL)
				return (r);
			*line = new;
			return (1);
		}
		else if (buf_parse(buf, &new, &pos, line))
			return (1);
	}
}
