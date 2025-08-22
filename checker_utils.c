int	ft_counter(const char *s, char c)
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

int	is_split(const char *s, char c, char **str, size_t *filled)
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

#include "stdlib.h"
#include "unistd.h"

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n')
			i++;
	}
	return (count);
}

void	copy_words(char *tab, char *str, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
		tab[j++] = str[start++];
	tab[j] = '\0';
}

int	find_next_word(char *str, int *start, int *end)
{
	int	i;

	i = *end;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n'))
		i++;
	*start = i;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	*end = i;
	return (*start < *end);
}

int	ft_fill_words(char **tab, char *str)
{
	int	i;
	int	word;
	int	start;
	int	end;

	i = 0;
	word = 0;
	start = 0;
	end = 0;
	while (find_next_word(str, &start, &end))
	{
		tab[word] = malloc((end - start + 1) * sizeof(char));
		if (tab[word] == NULL)
		{
			i = 0;
			while (i < word)
				free(tab[i++]);
			free(tab);
			return (0);
		}
		copy_words(tab[word], str, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_split(char *str)
{
	char	**out;
	int		size;

	size = count_words(str);
	out = malloc((sizeof(char *) * (size + 1)));
	if (!out)
		return (NULL);
	if (!ft_fill_words(out, str))
	{
		free(out);
		return (NULL);
	}
	return (out);
}