#include "./libmx.h"

void mx_print_num(char *arr, int sign) {
    for (int i = 9; i >= 0; i--) {
            if (sign == -1 && i == 9)
                mx_printchar('-');
            if (arr[i] >= '0' && arr[i] <= '9')
                mx_printchar(arr[i]);
    }
}
