#ifndef LINK_H
#define LINK_H


#include <stdlib.h>
#include <stdio.h>
#include "file.h"


typedef struct {
    int num_point_start;
    int num_point_end;
} link_t;

int get_link_start_point(link_t);
int get_link_end_point(link_t);

#endif // LINK_H
