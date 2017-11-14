/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 10:04:05 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/09 13:59:30 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	//if little is empty, return big
	//search big for first character of little
	//when found, step through both to see if whole of little is present
	//if end of big is reached before we find an instance of little, return NULL.
	//if little is present return pointer to first char of little within big
	
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (little[0] != '\0')
	{
		while (big[i++])
		{
			if (big[i] == little[j])
			{
				while (big[i + j] == little[j])
				{
					j++;
					if (little[j] == '\0')
						return ((char *)&big[i]);
				}
				j = 0;
			}
		}
	}
	else
		return ((char *)big);
	return (NULL);
}

int		main()
{
	char *big = "The quick brown fox jumps over the lazy dog.";
	char *little = "g.asd";

	printf("my result = %s.\n", ft_strstr(big, little));
	printf("system result = %s.\n", strstr(big, little));
	return (0);
}
