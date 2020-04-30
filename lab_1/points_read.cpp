#include "points_read.h"

int read_amount_of_points(int &points_amount, FILE *f) {
    if (fscanf(f, "%d", &points_amount) != 1 || points_amount <= 0)
        return INCORRECT_AMOUNT_OF_POINTS;

    return EXIT_SUCCESS;
}

int read_point(point_t *pos, FILE *f) {
    if (fscanf(f,
               "%lf %lf %lf",
               &(pos->x), &(pos->y), &(pos->z)) != 3)
        return READ_POINT_FAILURE;

    return EXIT_SUCCESS;
}

int read_points(point_t *points, int points_amount, FILE *f) {
    if (points_amount <= 0)
        return INCORRECT_AMOUNT_OF_POINTS;

    if (!f)
        return NULL_PTR;

    for (int i = 0; i < points_amount; i++)
        if (read_point(points + i, f)) {
            return READ_POINTS_FAILURE;
        }

    return EXIT_SUCCESS;
}
