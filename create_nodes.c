l_list	create_node(int value)
{
	l_list	*new_node;

	new_node = (l_list*)malloc(sizeof(l_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->nextNode = NULL;
	return (new_node);
}

void	add_node(l_list *list, int value)
{
	l_list *last;
	l_list	*new;

	if (*list == NULL)
		return ;
	new = create_node(value);
	last = find_last_node(list);
	last->nextNode = new;
	return ;
}

void	print_list(l_list *list)
{
	int	i;

	i = 0;
	while (*list != NULL)
	{
		printf("%d. ->%d \n", list->index, list->value);
		list = list->nextNode;
	}
	printf("NULL");
}