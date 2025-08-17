#include "push_swap.h"

void	ra(l_list *stack_a)
{
	l_list  *first_node;
	l_list  *last_node;

	if (!stack_a || !stack_a->head || !stack_a->head->nextNode)
		return;
	first_node = stack_a->head;
	last_node = find_last_node(stack_a->head);
	stack_a->head = first_node->nextNode;
	last_node->nextNode = first_node;
	first_node->nextNode = NULL;
	write (1, "ra\n", 3);
}

void	rra(l_list *stack_a)
{

}

void	rb(l_list *stack_b)
{
	l_list  *first_node;
	l_list	*last_node;

	if (!stack_b || !stack_b->head || !stack_b->nextNode)
		return ;
	first_node = stack_b->head;
	last_node = find_last_node(stack_b->head);
	stack_b->head = first_node->nextNode;
	last_node->nextNode = first_node;
	first_node->nextNode = NULL;
	write(1, "rb\n", 3);
}

void	rrb

void	pa