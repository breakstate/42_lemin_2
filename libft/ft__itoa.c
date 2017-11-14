/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:53:24 by bmoodley          #+#    #+#             */
/*   Updated: 2017/11/09 15:49:21 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*int abs(int	n)
{
	float num;

	num = n;
	if (num < 0)
	{
		num = -num;
	}
	if 

}*/

char	*count_digits(int	n)
{
	int 	count;
	long	num;
	char	*str;
	int		sign;

	num = n;
	count = 2;
	if (num < 0)
	{
		sign = -1;
		count++;
		num = -num;
	}
	while ((num / 10) > 0)
	{
		num = num/10;
		count++;
	}
	str = ft_memalloc(count);
	printf("count = %d\n", count);
	return (str);
}

char *itoa(int n)
{
	long	div;
	int		mod;
	char	*str;
	int		i;

	i = 0;
	str  = count_digits(n);
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	itoa(atoi(argv[1]));
	return (0);
}
