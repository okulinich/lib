#include "./libmx.h"

bool mx_isspace(char c) {
    if(c == '\n' || c == '\t' || c == ' ' ||
       c == '\f' || c == '\r' || c == '\v')
        return true;
    return false;
}
