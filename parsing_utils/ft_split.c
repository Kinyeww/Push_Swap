#include "push_swap.h"

static int	ft_counter(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	is_split(const char *s, char c, char **str, size_t *filled)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (*s && *s != c)
			{
				s++;
				len++;
			}
			str[i] = ft_substr(s - len, 0, len);
			if (!str[i])
				return (0);
			(*filled)++;
			i++;
		}
	}
	str[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	filled;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!str)
		return (NULL);
	filled = 0;
	if (!is_split(s, c, str, &filled))
	{
		while (filled > 0)
			free(str[--filled]);
		free(str);
		return (NULL);
	}
	return (str);
}
