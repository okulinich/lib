#include "./libmx.h"

int mx_list_size(t_list *list) {
    if (list) {
        t_list *head = list;
        int size = 1;
        while(head->next){
            head = head->next;
            size++;
        }
        return size;
    }
    else
        return 0;
}
