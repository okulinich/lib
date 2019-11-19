#include "./libmx.h"

void mx_print_unicode(wchar_t c) {
    char cc[5];

    if (c<0x80) {
        cc[0] = (c>>0 & 0x7F) | 0x00;
        cc[1] = '\0';
        cc[2] = '\0';
        cc[3] = '\0';
        cc[4] = '\0';
    }
    else if (c<0x0800) {
        cc[0] = (c>>6  & 0x1F) | 0xC0;
        cc[1] = (c>>0  & 0x3F) | 0x80;
        cc[2] = '\0';
        cc[3] = '\0';
        cc[4] = '\0';
    }
    else if (c<0x010000) {
        cc[0] = (c>>12 & 0x0F) | 0xE0;
        cc[1] = (c>>6  & 0x3F) | 0x80;
        cc[2] = (c>>0  & 0x3F) | 0x80;
        cc[3] = '\0'; 
        cc[4] = '\0'; 
    }
    else if (c<0x110000) {
        cc[0] = (c>>18 & 0x07) | 0xF0;
        cc[1] = (c>>12 & 0x3F) | 0x80;
        cc[2] = (c>>6  & 0x3F) | 0x80;
        cc[3] = (c>>0  & 0x3F) | 0x80;
        cc[4] = '\0';   
    }
    
    write(1, cc, mx_strlen(cc));
}
