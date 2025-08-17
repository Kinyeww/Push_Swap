#include "push_swap.h"

void	assign_index(l_list *stack_a)
{
	l_list	*current;
	l_list	*compare;
	int			rank;

	current = stack_a;
	while (current)
	{
		rank = 0;
		compare = stack_a;
		while (compare)
		{
			if (current->value > compare->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}

int	main(int argc,char **argv)
{
	int i;
	int	result;

	if (argc < 2)
	{
		write(1, "Error: Not enough arguments\n", 28);
		return (1);
	}
	i = 1;
	ft_printerror(valid_or_not(argv[i]));
	while (i < argc)
	{
		i++;
	}
	return (0);
}