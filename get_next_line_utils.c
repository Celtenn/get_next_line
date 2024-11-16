#include <stdlib.h>


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char *ft_strjoin(const char *str, const char *nbr)
{
	int	p;
	int	i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(ft_strlen(str) + ft_strlen(nbr));
	while (str[i])
	{
		arr[p] = str[i];
		i++;
		p++;
	}
	i = 0;
	while (nbr[i])
	{
		arr[p + i] = nbr[i];
		i++;
	}
	arr[p + i] = '\0';
	return (arr);
}
