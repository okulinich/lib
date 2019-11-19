#include "./libmx.h"

int mx_count_spaces(const char *str) {
    int res = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(mx_isspace(str[i]))
            res++;
    }
    return res;
}
