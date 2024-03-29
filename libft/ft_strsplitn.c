/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoodley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:13:12 by bmoodley          #+#    #+#             */
/*   Updated: 2017/12/04 15:34:52 by bmoodley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
**	Remember to free each element in calling function
**	s_str[i] in loop as well as s_str after loop
*/

static char		*ft_trim(const char *s, char c)
{
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] && s[i] == c)
	{
		i++;
	}
	if ((s[i] == '\0'))
		return (0);
	while (s[len - 1] == c && len - 1 >= 0)
	{
		len--;
	}
	return (ft_strsub(s, i, len - i));
}

static char		*word_length(char *s, char c, int word)
{
	int		i;
	int		start;
	int		word_count;
	char	*str;

	start = 0;
	word_count = 0;
	i = 1;
	if (s[0] != c)
		word_count++;
	while (word_count < word)
	{
		if (s[i] != c && s[i - 1] == c)
		{
			word_count++;
			start = i;
		}
		i++;
	}
	while (s[i] != c && s[i] != '\0')
		i++;
	str = (ft_strsub(s, start, i - start));
	return (str);
}

static int		count_words(const char *s, char c)
{
	int		i;
	int		count;

	if (s[0] == '\0')
		return (0);
	i = 1;
	count = 0;
	if (s[0] != c)
		count++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char			**ft_strsplitn(char const *s, char c, int *n)
{
	int		i;
	char	**strsplit;
	char	*trimmed_str;
	char	*word;

	i = 0;
	*n = count_words(s, c);
	if (*n == 0 || s[0] == '\0')
		trimmed_str = 0;
	else
		trimmed_str = ft_trim(s, c);
	strsplit = (char **)ft_memalloc(sizeof(char *) * *n + 1);
	if (strsplit == NULL)
		return (NULL);
	while (i < *n)
	{
		word = word_length(trimmed_str, c, i + 1);
		strsplit[i] = word;
		i++;
	}
	strsplit[i] = 0;
	free(trimmed_str);
	return (strsplit);
}
