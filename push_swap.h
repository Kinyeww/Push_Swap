#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// This line defines a new data type called 'struct node'
typedef struct node
{
    // This is an integer variable named 'value'
    // It stores the data inside this node (like 7, 21, etc.)
    int value;
    // This is a pointer to another 'struct node'
    // It links to the next node in the list (or NULL if it's the last one)
    struct node *nextNode;    
// This gives it a shortcut name 'l_list'
// So from now on, instead of typing 'struct node', we can just write 'l_list'
} l_list;