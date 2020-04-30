#include "file.h"

int file_open(FILE *&file, char *filename) {
    if (file)
        return NOT_NULL_PTR;

    file = fopen(filename, "rt");

    if (file)
        return EXIT_SUCCESS;
    else
        return ACCES_DENIED;
}
