#include "../push_swap.h"

void	push_to_a(l_list** stack_b, l_list** stack_a) // b to a
{
    l_list* head_b;

    if (*stack_b == NULL)
        return ;
    head_b = *stack_b;
    *stack_b = (*stackgit _b)->nextNode;
    head_b->nextNode = *stack_a;
    *stack_a = head_b;
}

void	push_to_b(l_list** stack_a, l_list** stack_b)
{
    l_list* head_a;

    if (*stack_a == NULL)
        return ;
    head_a = *stack_a;
    *stack_a = (*stack_a)->nextNode;
    head_a->nextNode = *stack_b;
    *stack_b = head_a; 
}
