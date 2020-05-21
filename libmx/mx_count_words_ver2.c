#include "./libmx.h"

int mx_count_words_ver2(const char *str) {
    int res = -1;
    int flag = 0;
    int i;
    if (str) {
        int len = mx_strlen(str);
        res = 0;
        for (i = 0; mx_isspace(str[i]); i++)
            continue; // skiping whitespaces at the beginning
        for( ; i <= len; i++) {
            if ((mx_isspace(str[i]) || str[i] == '\0') && flag == 1) {//if we were inside the word
                flag = 0;//out of the word
                res++;
            }
            else if (!mx_isspace(str[i]))
                flag = 1;//in the word
        }
    }
    return res;
}
