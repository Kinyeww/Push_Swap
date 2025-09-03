#include "push_swap.h"

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

int	num_only(char **str) //handle not integer, like "--1" "w" "-" ""
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (str[i][j] == '\0')
			return (0);
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
