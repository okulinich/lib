#include "./libmx.h"

static int check_delim(char *str, char delim) {
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] == delim)
            return i;
    return -1;
}

static void w_strncat(char *s1, char *s2, int n) {
    int i = 0;
    for( ; s1[i] != '\0'; i++)
        ;
    mx_strncpy(&s1[i], s2, n);
}

static bool write_least(char **lineptr, char **least, int *total, int delim) {
    int del_indx = check_delim(*least, delim);
    char *least_copy = NULL;

    if (del_indx == -1) {
        mx_strcpy(*lineptr, *least);
        (*total) += mx_strlen(*least);
        mx_strdel(least);
        *least = NULL;
        return true;
    }
    else {
        least_copy = mx_strdup(&(*least)[del_indx + 1]);
        mx_strncpy(*lineptr, *least, del_indx);
        mx_strdel(&(*least));
        *least = mx_strdup(least_copy);
        mx_strdel(&least_copy);
        (*total) += del_indx;
        return false;
    }
}

static void write_before_delim(char **least, size_t buf_size, int delim_indx, char *next_line, char **lineptr, int *total) {
    *least = mx_strnew(buf_size - delim_indx - 1);
    mx_strcpy(*least, &next_line[delim_indx + 1]);
    w_strncat(*lineptr, next_line, delim_indx);
    (*total) += delim_indx;
    mx_strdel(&next_line);
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    int num_of_bytes = 0;
    int total = 0;
    int delim_indx = -1;
    static char *least;
    char *next_line = NULL;

    if(lineptr && buf_size > 0) { //if args OK
        if(malloc_size(least) > 0) {
            for(int i = 0; (*lineptr)[i] != '\0'; i++)
                (*lineptr)[i] = '\0';
            if(!write_least(lineptr, &least, &total, delim))
                return total;
        }
        next_line = mx_strnew(buf_size);
        num_of_bytes = read(fd, next_line, buf_size);
        while(num_of_bytes > 0) {
            delim_indx = check_delim(next_line, delim);
            if(delim_indx == -1) { //if delim not found
                mx_strcat(*lineptr, next_line);
                mx_strdel(&next_line);
                total += num_of_bytes;
            }
            else { //if delim found
                write_before_delim(&least, buf_size, delim_indx, next_line, lineptr, &total);
                return total;
            }
            next_line = mx_strnew(buf_size);
            num_of_bytes = read(fd, next_line, buf_size);
        }
        if(num_of_bytes <= 0) {
            mx_strdel(&next_line);
            return num_of_bytes;
        }//0 - eof, -1 in case of errors
        return total;
    }
    else 
        return -2;
}
