#include "./libmx.h"

void mx_pop_back(t_list **list) {
    if (list) {
        t_list *head = *list;
        while(head->next->next)
            head = head->next;
        free(head->next);
        head->next = NULL;
    }
}
