#include "./libmx.h"

void mx_str_reverse(char *s) {
    if (s) {
        int size = mx_strlen(s);
        for(int i = 0; i <= size / 2; i++)
            mx_swap_char(&s[i], &s[--size]);
    }
}
