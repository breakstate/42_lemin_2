#include "libft.h"

char	*ft_strjoinf(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		dst = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (dst == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			dst[i + j] = s2[j];
			j++;
		}
		dst[i + j] = '\0';
		free(s1);
		return (dst);
	}
	return (NULL);
}