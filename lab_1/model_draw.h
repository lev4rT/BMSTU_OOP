#ifndef MODEL_DRAW_H
#define MODEL_DRAW_H


#include "model.h"
#include "screen.h"
#include "model_cdio.h"
#include "link.h"
#include "point_cdio.h"
#include "wrap_functions.h"


enum model_draw_errors {
    CANNOT_GET_PROJECTION
};

int model_draw(model_t &model, scene_t &scene);

int get_projected_points(projected_points_t &points_xy, initial_points_t &points_xyz, screen_t screen);
int get_projected_point  (point_xy_t &point_xy,  point_t point_xyz, double   k);
int draw_links(projected_points_t &projected, links_t &links, scene_t &scene);


#endif // MODEL_DRAW_H
