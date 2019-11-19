#include "./libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int size = 0;
    char *res;
    char hex[] = {'0', '1', '2', '3', '4',
                  '5', '6', '7', '8', '9',
                  'a', 'b', 'c', 'd', 'e', 'f'};
    int nbr_copy = nbr;

    if(nbr == 0) {
        res = (char *)malloc(2);
        res[0] = '0';
        return res;
    }
    else {
        while(nbr_copy > 0) {
            size++;
            nbr_copy /= 16;
        }
        printf("size - %i\n", size);
        res = (char *)malloc(size + 1);
        while(nbr > 0) {
            res[--size] = hex[nbr % 16];
            nbr /= 16;
        }
        return res;
    }
}
