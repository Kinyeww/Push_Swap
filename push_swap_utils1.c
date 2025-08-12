#include "push_swap.h"

l_list  *find_last_node(l_list *head)
{
    if (!head)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}