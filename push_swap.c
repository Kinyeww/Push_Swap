#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	value;


}

l_list	push_swap(int value)
{
	
}

int	valid_or_not(char *str) //handle not integer, exceed limit and duplicates
{
	int	result;
	int	i;
	int	tracker;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (2); //not integer
		if (!(ft_atoicheck(str[i])) != 1) //NEED ATOI
			return (3); //int overflow
		tracker = 0;
		while (tracker < i) //handle dupes
		{
			if (str[i] == str[tracker])
				return (4);
			tracker++;
		}
		i++;
	}
	return (1);
}

void	ft_printerror(int n)
{
	if (n == 1)
		printf("Valid argument!!");
	if (n == 2)
		printf("Error: String contains non integer");
	if (n == 3)
		printf("Error: Integer overflow");
	if (n == 4)
		printf("Error: Duplicate numbers found");
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