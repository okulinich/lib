#include "./libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (!s1 && !s2)
        return NULL;
    if(!s1 || !s2) //returning another string if one doesn't exst
        return !s1 ? mx_strcpy(mx_strnew(mx_strlen(s2)), s2) : 
                    mx_strcpy(mx_strnew(mx_strlen(s1)), s1);
    else {
        char *res_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        mx_strcpy(res_str, s1);
        mx_strcpy(&res_str[mx_strlen(s1)], s2);
        return res_str;
    }
}
