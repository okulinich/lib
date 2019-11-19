#include "./libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int res = 0;
    char *next_part = (char *)&str[0];

    if(!(str && sub))
        res = -1;
    else {
        while((next_part = mx_strstr(next_part, sub)) != NULL) {
            next_part++;
            res++;
        }
    }
    return res;
}
