#include "./libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (arr && s) {
        int left = 0;
        int right = size - 1;
        int m = 0;
        int res = 0;
        *count = 0;

        while(left <= right) {
            m = (left + right) / 2;
            (*count)++;
            res = mx_strcmp(arr[m], s);
            if (res == 0)
                return m;
            if (res > 0)
                right = m - 1;    
            else
                left = m + 1;
        }
        *count = 0;
        return -1;
    }
    else {
        *count = 0;
        return -1;
    }
}
