#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>

enum file_errors_t {
    NULL_PTR,
    NOT_NULL_PTR,
    DOESNT_EXIST,
    ACCES_DENIED,
};

int file_open(FILE *&f, char* file_name);

#endif // FILE_H
