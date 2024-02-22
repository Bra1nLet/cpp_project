#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _tagNode {
    int data;
    _tagNode *next;
} NODE, *PNODE;

PNODE add_element_to_list(PNODE head, int data);
int get_size_list(const PNODE head);
const PNODE get_element_from_list(const PNODE head, int index);
PNODE delete_element_from_list(PNODE head, int index);
PNODE clear_list(PNODE head);
void print_list(const PNODE head);

#endif