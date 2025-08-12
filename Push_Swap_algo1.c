#include "push_swap.h"

void	ra(l_list *stack_a)
{
    l_list  *first_node;
    l_list  *last_node;

    if (!stack_a || !stack_a->head || !stack_a->head->next)
        return;
    first_node = stack_a->head;
    last_node = find_last_node(stack_a->head);
    /*rotation*/
    stack_a->head = first_node->next;
    last_node-> = first_node
    first_node->next = NULL;
}

void	rra

void	rb

void	rrb

void	pa