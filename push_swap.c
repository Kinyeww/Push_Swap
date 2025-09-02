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

int	ft_checknum(char **arr) // convert all checked strings into integer and check no dupes and no overflow
{// check overflows and then store into linked list and only check for dupes
	int	i;
	int	j;
	long	num;

	i = 0;
	while (arr[i])
	{
		num = ft_atoi(arr[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
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
	if (!num_only(tokens) != 1 || !tokens) //check invalid chars
	{
		free_tokens(tokens);
		return (0);
	}
	return (tokens);
}

l_list	push_swap(int argc, char **argv)
{
	l_list	*stack_a;
	l_list	*stack_b;
	char	**checked;
	int	i;
	int	value;
	
	checked = ft_tokenise(argc, argv);
	if (!checked || ft_checknum(argc, argv) != 1)
	{
		free_tokens(checked);
		return (NULL);
	}
	value = ft_atoi(checked[0]);
	stack_a = (create_node(value));
	i = 1;
	while (checked[i])
	{
		value = ft_atoi(checked[i]);
		add_node(&stack_a, value);
		i++;
	}
	stack_a = assign_index(stack_a);
	print_list(stack_a);
	return (stack_a);
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
	{
		push_swap(argc, argv);
		return (1);
	return (0);
}