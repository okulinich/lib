#include "./libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *tr_str = NULL;

    if (!str)
        return NULL;
    int spaces = mx_count_spaces(str);
    int words = mx_count_words_ver2(str);
    int new_size = mx_strlen(str) - spaces + words - 1;
    tr_str = mx_strnew(new_size);
    for(int i = 0, j = 0; str[i] != '\0'; i++) {
        if(mx_isspace(str[i])) //skiping space symbols
            continue;
        else {
            while(!mx_isspace(str[i])) {
                tr_str[j++] = str[i++];
            } //copying not space symbs
            tr_str[j++] = ' '; //separating words with space
        }
    }
    tr_str[new_size] = '\0'; //deleting extra space at the end
    return tr_str;
}
