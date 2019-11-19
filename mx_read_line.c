#include "./libmx.h"

static int check_delim(char *str, char delim) {
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] == delim)
            return i;
    return -1;
}

static void mx_strncat(char *s1, char *s2, int n) {
    int i = 0;
    for( ; s1[i] != '\0'; i++)
        ;
    mx_strncpy(&s1[i], s2, n);
}

static void write_least(char **lineptr, char *least, int *buf_size, int *total) {
    mx_strcat(*lineptr, least);
    (*buf_size) -= mx_strlen(least);
    (*total) += mx_strlen(least);
    least = NULL;
}

static void write_before_delim(char *least, int buf_size, int delim_indx, char *next_line, char **lineptr, int *total) {
    least = mx_strnew(buf_size - delim_indx - 1);
    mx_strcpy(least, &next_line[delim_indx + 1]);
    mx_strncat(*lineptr, next_line, delim_indx);
    (*total) += delim_indx;
    mx_strdel(&next_line);
}

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    int num_of_bytes = 0;
    int total = 0;
    int delim_indx = -1;
    static char *least;
    char *next_line = mx_strnew(buf_size);

    if(*lineptr && buf_size > 0) { //if args OK
        if(least) {
            write_least(lineptr, least, &buf_size, &total);
        }
        num_of_bytes = read(fd, next_line, buf_size);
        while(num_of_bytes > 0) {
            delim_indx = check_delim(next_line, delim);
            if(delim_indx == -1) { //if delim not found
                mx_strcat(*lineptr, next_line);
                mx_strdel(&next_line);
                total += num_of_bytes;
            }
            else { //if delim found
                write_before_delim(least, buf_size, delim_indx, next_line, lineptr, &total);
                return total;
            }
            next_line = mx_strnew(buf_size);
            num_of_bytes = read(fd, next_line, buf_size);
        }
        if(num_of_bytes < 0)
            return num_of_bytes;
        return total;
    }//0 - eof, -1 in case of errors
    else 
        return -2;
}
