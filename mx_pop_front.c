#include "./libmx.h"

void mx_pop_front(t_list **list) {
    if (list) {
        t_list *head = *list;
        if((*list)->next)
            (*list) = (*list)->next;
        free(head);
        head = NULL;
    }
}
