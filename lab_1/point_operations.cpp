#include "point_operations.h"

int points_move (initial_points_t &initial_points, parameters_move_t &params) {
    int rc = EXIT_SUCCESS;

    if (!initial_points.points)
        rc = NULL_PTR;
    else if (initial_points.points_amount <= 0)
        rc = INCORRECT_AMOUNT_OF_POINTS;
    else
        for (int i = 0; i < initial_points.points_amount; i++) {
            point_move(initial_points.points[i], params);
        }

    return rc;
}

int point_move (point_t &point, parameters_move_t &params) {
    point.x += params.dx;
    point.y += params.dy;
    point.z += params.dz;

    return EXIT_SUCCESS;
}

int points_scale (initial_points_t &initial_points, parameters_scale_t &params) {
    int rc = EXIT_SUCCESS;

    if (!initial_points.points)
        rc = NULL_PTR;
    else if (initial_points.points_amount <= 0)
        rc = INCORRECT_AMOUNT_OF_POINTS;
    else if (fabs(params.kx) <= EPS || fabs(params.ky) <= EPS || fabs(params.kz) <= EPS)
        rc = INCORRECT_COEFFICIENT;
    else
        for (int i = 0; i < initial_points.points_amount; i++) {
            point_scale (initial_points.points[i], params);
        }

    return rc;
}

int point_scale (point_t &point, parameters_scale_t &params) {
    point.x = params.kx * (point.x) + (1 - params.kx) * params.Mx;
    point.y = params.ky * (point.y) + (1 - params.ky) * params.My;
    point.z = params.kz * (point.z) + (1 - params.kz) * params.Mz;

    return EXIT_SUCCESS;
}

int points_rotate(initial_points_t &initial_points, parameters_rotate_t &params) {
    int rc = EXIT_SUCCESS;

    if (!initial_points.points)
        rc = NULL_PTR;
    else if (initial_points.points_amount <= 0)
        rc = INCORRECT_AMOUNT_OF_POINTS;
    else
        for (int i = 0; i < initial_points.points_amount && rc == EXIT_SUCCESS; i++)
            switch (params.plane) {
            case (XY):
                point_rotate_xy(initial_points.points[i], params);
                break;
            case (XZ):
                point_rotate_xz(initial_points.points[i], params);
                break;
            case (YZ):
                point_rotate_yz(initial_points.points[i], params);
                break;
            default:
                rc = INCORRECT_ARGUMENT_FAILURE;
            }

    return rc;
}

int point_rotate_xy (point_t &point, parameters_rotate_t &params) {
    double x_initial = point.x;
    double y_initial = point.y;
    double angle = - (params.angle) * PI / 180;
    double x_center = params.x;
    double y_center = params.y;

    point.x = x_center + (x_initial - x_center) * cos(angle) + (y_initial - y_center) * sin(angle);
    point.y = x_center - (x_initial - x_center) * sin(angle) + (y_initial - y_center) * cos(angle);

    return EXIT_SUCCESS;
}

int point_rotate_xz (point_t &point,  parameters_rotate_t &params) {
    double x_initial = point.x;
    double z_initial = point.z;
    double angle = - (params.angle) * PI / 180;
    double x_center = params.x;
    double z_center = params.z;

    point.x = x_center + (x_initial - x_center) * cos(angle) + (z_initial - z_center) * sin(angle);
    point.z = x_center - (x_initial - x_center) * sin(angle) + (z_initial - z_center) * cos(angle);

    return EXIT_SUCCESS;
}

int point_rotate_yz (point_t &point, parameters_rotate_t &params) {
    double y_initial = point.y;
    double z_initial = point.z;
    double angle = - (params.angle) * PI / 180;
    double y_center = params.y;
    double z_center = params.z;

    point.y = y_center + (y_initial - y_center) * cos(angle) + (z_initial - z_center) * sin(angle);
    point.z = y_center - (y_initial - y_center) * sin(angle) + (z_initial - z_center) * cos(angle);

    return EXIT_SUCCESS;
}
