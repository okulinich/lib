#include "./libmx.h"

void mx_push_back(t_list **list, void *data) {
    if(list) {
        t_list *head = *list;    //creating a copy of list head
        while(head->next)       //not to corrupt real head pointer
            head = head->next;
        t_list *new_node = mx_create_node(data);
        new_node->next = NULL;
        head->next = new_node;
    }
}
