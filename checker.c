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
// {-42 42 3}
char	**ft_tokenize(char	**token)
{
	
}

void	many_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		valid_or_not(argv[i])
		i++;
	}
}

/*ft_split = "3 4 5"
			 "6 7 8"
			 "10"
			 "11"
			 "\0"*/

int	num_only(char **str) //handle not integer
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
			return (2);
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (2);
			j++;
		}
		i++;
	}
	return (1);
}
