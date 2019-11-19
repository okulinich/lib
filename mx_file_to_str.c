#include "./libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    char *str;
    int size = 0;
    char buf = 'a';

    if (fd > 0) {
        while(read(fd, &buf, 1) > 0)
            size++;
        close(fd);
        str = mx_strnew(size);
        fd = open(file, O_RDONLY);
        for(int i = 0; read(fd, &buf, 1) > 0; i++)
            str[i] = buf;
        close(fd);
        return str;
    }
    return NULL;
}
