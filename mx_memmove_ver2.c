#include "./libmx.h"

void *mx_memmove_ver2(void *dst, const void *src, size_t len) {
    byte *dst_ptr = (byte *) dst;
    byte *src_ptr = (byte *) src;

    if(check_overlap(dst_ptr, src_ptr, len)) {
        for(size_t i = len - 1; i >= 0; i--)
            dst_ptr[i] = src_ptr[i];
    }
    else
    {
        for(size_t i = 0; i < len; i++)
            dst_ptr[i] = src_ptr[i];
    }
    return dst;
}
