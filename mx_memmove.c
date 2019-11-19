#include "./libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    byte *dst_ptr = (byte *) dst;
    byte *src_ptr = (byte *) src;
    //a temporary array to hold data of src
    byte *temp = (byte *)malloc(len);

    mx_memcpy(temp, src_ptr, len);
    mx_memcpy(dst_ptr, temp, len);
    free(temp);
    return dst;
}
