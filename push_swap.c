#include "push_swap.h"

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
	if (!tokens || num_only(tokens) != 1) //check invalid chars
	{
		free_tokens(tokens);
		return (0);
	}
	return (tokens);
}

int	check_dupes(l_list* stack_a)
{
	int	cmp;
	l_list*	start;

	while(stack_a->next)
	{
		start = stack_a;
		cmp = stack_a->value;
		while (start->next)
		{
			start = start->next;
			if (cmp == start->value)
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

l_list	*push_swap(int argc, char **argv)
{
	l_list	*stack_a;
	l_list	*stack_b;
	char	**checked;
	int	i;
	int	value;
	
	checked = ft_tokenise(argc, argv);
	if (!checked || ft_checknum(checked) != 1) //check overflow
	{
		free_tokens(checked);
		return (NULL);
	}
	value = ft_atoi(checked[0]);
	stack_a = create_node(value); //initialise node
	i = 1;
	while (checked[i]) // start parsing value into nodes
	{
		value = ft_atoi(checked[i]);
		add_node(&stack_a, value);
		i++;
	}
	if (!(check_dupes(stack_a))) //check for dupes
	{
		free(stack_a);
		return (NULL);
	}
	assign_index(stack_a);
	print_list(stack_a); // checking only
	//after checking dupes, arguments are in the list with int index and int value
	//my next step is to sort by using the ranks
	radix_sort(&stack_a, &stack_b);
	return (stack_a);
}

void	radix_sort(l_list** stack_a, l_list** stack_b)
{
	
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
		if (!(push_swap(argc, argv)))
		{
			write (1, "error\n", 6);
			return (1);
		}
	}
	return (0);
}