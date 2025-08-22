#include "push_swap.h"

void	assign_index(l_list *stack_a)
{
	l_list	*current;
	l_list	*compare;
	int		rank;

	current = stack_a;
	while (current)
	{
		rank = 0;
		compare = stack_a;
		while (compare)
		{
			if (current->value > compare->value)
				rank++;
			compare = compare->nextNode;
		}
		current->index = rank;
		current = current->nextNode;
	}
}

int	push_swap(char **argv)
{
	l_list	**stack_a;
	l_list	**stack_b;

	
}

void    free_tokens(char **arr)
{
    int i;

    if (!arr)
        return;
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}


char**	ft_tokenise(int argc, char **argv)
{
	char	**tokens;
	char	*joined;
	int	i;

	i = 1;
	joined = NULL;
	tokens = NULL;
	while (i < argc)
	{
		joined = ft_strjoin_space(joined, argv[i]);
		i++;
	}
	tokens = ft_split(joined, ' ');
	free (joined);
	if (!num_only(tokens) || !tokens)
	{
		free_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}

char	*ft_combine(size_t len1, size_t len2, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*temp;

	temp = malloc(sizeof(char) * (len1 + len2 + 1 + 1));
	i = 0;
	while (i < len1)
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	temp[i] = ' ';
	i++;
	while (j < len2)
	{
		temp[i + j] = s2[j];
		j++;
	}
	temp[len1 + len2 + 1] = '\0';
	return (temp);
}

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	str = ft_combine(len1, len2, s1, s2);
	return (str);
}

int	main(int argc, char **argv)
{
	char	**token;

	if (argc < 2)
	{
		write(1, "Error: Not enough arguments\n", 28);
		return (1);
	}
	else
		ft_tokenise(argc, argv);
	return (0);
}