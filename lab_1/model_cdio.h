#ifndef MODEL_CDIO_H
#define MODEL_CDIO_H


#include "model.h"
#include "point_cdio.h"
#include "file.h"
#include "links_read.h"
#include "point_cdio.h"
#include "model_read.h"
#include "scene.h"
#include <stdlib.h>
#include <stdio.h>


enum model_cdio_errors {
    INCORRECT_POINTS_AMOUNT,
    NOT_INITIALIZED_FIELD,
};

//int model_points_allocate (point_t *&points, int points_amount);
//int model_links_allocate  (link_t *&links,   int links_amount);
int model_initial_points_allocate(initial_points_t &points_xyz);
int model_projected_points_allocate(projected_points_t &points_xy);
int model_links_allocate  (links_t &links);

//int model_points_read (point_t *points, FILE *f, int links_amount);
//int model_links_read  (link_t  *links,  FILE *f, int links_amount);
int model_initial_points_read(initial_points_t &points_xyzm, FILE *f);
int model_projected_points_read(projected_points_t &points_xy, FILE *f);
int model_links_read  (links_t &links);

int model_initial_points_free(initial_points_t &points_xyz);
int model_projected_points_free(projected_points_t &points_xy);
int model_links_free  (links_t &links);

int model_delete      (model_t model);
int model_delete      (model_t model, scene_t &scene);


#endif // MODEL_CDIO_H
