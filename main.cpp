#include "linked_list.h"
#include <stdio.h>

#define MAX 10

int main(int argc, char* argv[])
{
    PNODE p_head = nullptr;

    for (int i = 1; i <= MAX; i++) p_head = add_element_to_list(p_head, i);
    print_list(p_head);
    int count = get_size_list(p_head);
    printf("Count: %d\n", count);
    const PNODE pa = get_element_from_list(p_head, 5);
    printf("\nValue on 5 index: %d\n\n", pa->data);

    p_head = delete_element_from_list(p_head, 0);
    print_list(p_head);
    count = get_size_list(p_head);
    printf("Count after delete on 0 index: %d\n", count);

    p_head = delete_element_from_list(p_head, 8);
    print_list(p_head);
    count = get_size_list(p_head);
    printf("Count after delete on 8 index: %d\n", count);

    p_head = delete_element_from_list(p_head, 4);
    print_list(p_head);
    count = get_size_list(p_head);
    printf("Count after delete on 4 index: %d\n", count);

    p_head = clear_list(p_head);
    count = get_size_list(p_head);
    printf("\nCount after clear: %d\n", count);

    return 0;
}