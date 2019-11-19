#include "./libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new;
    
    if(!ptr) {
        new = malloc(size);
        if(!new)
            return NULL;
    }
    else {
        if(malloc_size(ptr) < size) {
            new = malloc(size);
            if(!new)
                return NULL;
            else
            {
                mx_memcpy(new, ptr, malloc_size(ptr));
                free(ptr);
            }
        }
        else if (size > 0)  {
            new = malloc(size);
            mx_memcpy(new, ptr, size);
            free(ptr);
        }
        else {
            free(ptr);
            return NULL;
        }
    }
    return new;
}
