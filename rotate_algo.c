#include "push_swap.h"

void	ra(l_list **stack_a) a b c d e \0 to b c d e a \0 
{
	l_list	*first_node;
	l_list	*last_node;

	if (!(*stack_a) || !(*stack_a)->nextNode)
		return ;
	first_node = *stack_a;
	last_node = find_last_node(stack_a);
	*stack_a = first_node->nextNode;
	first_node->nextNode = NULL;
	last_node->nextNode = first_node;
	write (1, "ra\n", 3);
}

void	rra(l_list **stack_a)a b c d\0 e a \0 to e a b c d \0 
{
	l_list	*secondlast_node;
	l_list	*last_node;

	if (!(*stack_a) || !(*stack_a)->nextNode)
		return ;
	secondlast_node = (*stack_a);
	while (secondlast_node->nextNode->nextNode)
		secondlast_node = secondlast_node->nextNode
	last_node = secondlast_node->nextNode;
	secondlast_node->NULL;
	last_node->nextNode = *stack_a;
	*stack_a = last_node;
	write (1, "rra\n", 4);
}

void	rb(l_list **stack_b)
{
	l_list	*first_node;
	l_list	*last_node;

	first_node = *stack_b;
	last_node = find_last_node(stack_b);
	*stack_b = first_node->nextNode;
	first_node->nextNode = NULL;
	last_node->nextNode = first_node;
	write (1, "rb\n", 3);
}

void	rrb
{
	l_list	*secondlast_node;
	l_list	*last_node;

	if (!(*stack_b) || !(*stack_b)->nextNode)
		return ;
	secondlast_node = (*stack_b);
	while (secondlast_node->nextNode->nextNode)
		secondlast_node = secondlast_node->nextNode
	last_node = secondlast_node->nextNode;
	secondlast_node->NULL;
	last_node->nextNode = *stack_b;
	*stack_b = last_node;
	write (1, "rrb\n", 4);
}

void	rr // ra + rb