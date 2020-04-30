#ifndef POINT_CDIO_H
#define POINT_CDIO_H

#include "file.h"

enum points_read_errors {
    INCORRECT_AMOUNT_OF_POINTS,
    READ_POINTS_FAILURE,
    READ_POINT_FAILURE,
    INCORRECT_ARGUMENT_FAILURE,
};

typedef struct {
    double x;
    double y;
    double z;
} point_t;


typedef struct {
    double x;
    double y;
} point_xy_t;

int read_amount_of_points (int &points_xyz_amount, int &points_xy_amount, FILE *f);

int points_xy_allocate  (point_xy_t *&point, int points_amount);
int points_xyz_allocate (point_t    *&point, int points_amount);

int points_xyz_read (point_t *points, FILE *f, int points_amount);
int point_xyz_read  (point_t &point,  FILE *f);

int points_xy_free  (point_xy_t *point);
int points_xyz_free (point_t    *point);

#endif // POINT_CDIO_H
