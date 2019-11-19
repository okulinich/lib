#include "./libmx.h"

static int partition(char **arr, int left, int right, int *swaps) {
    char *pivot = arr[right];
    int i = left;
    char *temp = NULL;

    for(int j = left; j < right; j++) {
        if(mx_strlen(arr[j]) <= mx_strlen(pivot)) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            (*swaps)++;
        }
    }
    temp = arr[right];
    arr[right] = arr[i];
    arr[i] = temp;

    return i;
}

int mx_quicksort(char **arr, int left, int right) {
    int p = 0;
    static int swaps;

    if(!arr)
        return -1;
    
    if (left < right) {
        p = partition(arr, left, right, &swaps);
        mx_quicksort(arr, left, p - 1);
        mx_quicksort(arr, p + 1, right);
    }
    return swaps;
}
