#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// This line defines a new data type called 'node'
typedef struct node
{
    // It stores the data inside this node (like 7, 21, etc.)
    int value;
    int index;
    // This is a pointer to another 'struct node'
    struct node *nextNode;    
// So from now on, instead of typing 'struct node', we can just write 'l_list'
} l_list;