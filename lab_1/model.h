#ifndef MODEL_H
#define MODEL_H


#include "point_cdio.h"
#include "link.h"


enum model_errors {
    INCORRECT_MODEL,
};

typedef struct {
    int      points_amount;
    point_xy_t *points;
} projected_points_t;

typedef struct {
    int      links_amount;
    link_t  *links;
} links_t;

typedef struct {
    point_t *points;
    int points_amount;
} initial_points_t;

typedef struct {
    projected_points_t points_xy;
    initial_points_t points_xyz;
    links_t  links;
} model_t;


model_t init_model        ();
int     init_model_fields (model_t &model);
int     model_check       (model_t  model);

int init_model_initial_points(initial_points_t &initial_points);
int init_model_projected_points(projected_points_t &projected_points);
int init_model_links(links_t &links);

int model_projected_points_check(projected_points_t &projected_points);
int model_initial_points_check(initial_points_t &initial_points);
int model_links_check(links_t &projected_points);

#endif // MODEL_H
