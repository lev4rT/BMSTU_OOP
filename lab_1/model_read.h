#ifndef MODEL_READ_H
#define MODEL_READ_H


#include "model.h"
#include "point_cdio.h"
#include "file.h"
#include "links_read.h"
#include "model_cdio.h"

enum model_read_errors_t {
    FILE_OPEN_FAILURE,
    AMOUNT_OF_POINTS_READING_FAILURE,
    AMOUNT_OF_LINKS_READING_FAILURE,
    ALLOCATION_ERROR,
    POINTS_READING_FAILURE,
    LINKS_READING_FAILURE,
};


int model_read(model_t &model_buff, char *filename);
int model_read_points(initial_points_t &points_xyz, projected_points_t &points_xy, FILE *f);
int model_read_links(links_t &model_links, FILE *f);

#endif // MODEL_READ_H
