#include "./libmx.h"

bool check_overlap(unsigned char *dest, unsigned char *source, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if(&dest[0] == &source[i]) {
            return true;
        }
    }
    return false;
}
