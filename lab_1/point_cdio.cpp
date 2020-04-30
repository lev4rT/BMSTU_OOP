#include "point_cdio.h"


int read_amount_of_points(int &points_xyz_amount, int &points_xy_amount, FILE *f) {
    int rc = EXIT_SUCCESS;
    if (fscanf(f, "%d", &points_xyz_amount) != 1 || !(points_xy_amount = points_xyz_amount))
        rc = INCORRECT_AMOUNT_OF_POINTS;

    return EXIT_SUCCESS;
}

int points_xy_allocate(point_xy_t *&points, int points_amount) {
    int rc = EXIT_SUCCESS;
    if (points_amount <= 0)
        rc = INCORRECT_AMOUNT_OF_POINTS;
    else if (points)
        rc = NULL_PTR;
    else if (!(points = (point_xy_t *)(malloc(sizeof(point_xy_t) * points_amount))))
        rc = NULL_PTR;

    return EXIT_SUCCESS;
}


int points_xyz_allocate(point_t *&points, int points_amount) {
    int rc = EXIT_SUCCESS;
    if (points_amount <= 0)
        rc = INCORRECT_AMOUNT_OF_POINTS;
    else if (points)
        rc = NULL_PTR;
    else if (!(points = (point_t *)(malloc(sizeof(point_t) * points_amount))))
        rc = NULL_PTR;

    return EXIT_SUCCESS;
}

int points_xyz_read(point_t *points, FILE *f, int points_amount) {
    int rc = EXIT_SUCCESS;

    if (points_amount <= 0)
        rc = INCORRECT_AMOUNT_OF_POINTS;

    else if (!f)
        rc = NULL_PTR;
    else
        for (int i = 0; i < points_amount && rc == EXIT_SUCCESS; i++)
            if (point_xyz_read(*(points + i), f))
                rc = READ_POINTS_FAILURE;  // Одна точка выход из подпрограммы!

    return rc;
}

int point_xyz_read(point_t &point,  FILE *f) {
    int rc = EXIT_SUCCESS;

    if (fscanf(f, "%lf %lf %lf", &(point.x), &(point.y), &(point.z)) != 3)
        rc = READ_POINT_FAILURE;

    return rc;
}

int points_xy_free(point_xy_t *points) {
    int rc = EXIT_SUCCESS;

    if (!points)
        rc = EXIT_FAILURE;
    else
        free(points);

    return rc;
}


int points_xyz_free(point_xy_t *points) {
    int rc = EXIT_SUCCESS;

    if (!points)
        rc = EXIT_FAILURE;
    else
        free(points);

    return rc;
}
