#ifndef POINT_OPERATIONS_H
#define POINT_OPERATIONS_H


#include <math.h>
#include "point_cdio.h"
#include "file.h"
#include "meta.h"
#include "model.h"


#define PI 3.14159265359
#define EPS 1e-3

enum point_operations_error {
    INCORRECT_COEFFICIENT,
};

int points_move  (initial_points_t &points_xyz, parameters_move_t &params);
int point_move   (point_t &point, parameters_move_t &params);


int points_scale (initial_points_t &points_xyz, parameters_scale_t &params);
int point_scale  (point_t &point, parameters_scale_t &params);

int points_rotate   (initial_points_t &points_xyz, parameters_rotate_t &params);
int point_rotate_xy (point_t &point, parameters_rotate_t &params);
int point_rotate_xz (point_t &point, parameters_rotate_t &params);
int point_rotate_yz (point_t &point, parameters_rotate_t &params);


#endif // POINT_OPERATIONS_H
