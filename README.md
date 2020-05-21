#libmx

There is more than 60 functions, some basic functions from standard C library (strdup, realloc etc.) and additional functions (strjoin, create_list etc.) that make using C more comfortable.

To compile them all and use as a library: 
1. `gcc -c *.c`                 - *creating object files*
2. `ar rcs libmx.a *.o`         - *creating static library*
3. `gcc your_file.c libmx.a`    - *compiling your file with this lib*
