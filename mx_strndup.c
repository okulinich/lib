#include "./libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *res = NULL;
    char *s2 = (char *)malloc(n + 1);
    if(s2) {
        res = mx_strncpy(s2, s1, n);
        res[n] = '\0';
    }
    else
        res = NULL;
    return res;
}
