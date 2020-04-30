#include "model_cdio.h"

int model_initial_points_allocate(initial_points_t &points_xyz) {
    if (points_xyz.points_amount <= 0)
        return INCORRECT_POINTS_AMOUNT;

    if (points_xyz_allocate(points_xyz.points, points_xyz.points_amount))
        return ALLOCATION_ERROR;

    return EXIT_SUCCESS;
}

int model_projected_points_allocate(projected_points_t &points_xy) {
    if (points_xy.points_amount <= 0)
        return INCORRECT_POINTS_AMOUNT;

    if (points_xy_allocate(points_xy.points, points_xy.points_amount))
        return ALLOCATION_ERROR;

    return EXIT_SUCCESS;
}

int model_links_allocate (links_t &links) {
    if (links.links_amount <= 0)
        return INCORRECT_POINTS_AMOUNT;

    if (links.links)
        return NOT_INITIALIZED_FIELD;

    links.links = (link_t *)(malloc(sizeof (link_t) * links.links_amount));
    if (!links.links)
        return ALLOCATION_ERROR;

    return EXIT_SUCCESS;
}

int model_initial_points_read(initial_points_t &points_xyz, FILE *f) {
    int rc = EXIT_SUCCESS;

    if (points_xyz.points_amount <= 0)
        rc = INCORRECT_POINTS_AMOUNT;
    else if (!f || !points_xyz.points)
        rc = NULL_PTR;
    else
        for (int i = 0; i < points_xyz.points_amount && rc == EXIT_SUCCESS; i++)
            if (point_xyz_read(*(points_xyz.points + i), f))
                rc= READ_POINTS_FAILURE;

    return rc;
}

int model_links_read(links_t &links, FILE *f) {
    int rc = EXIT_SUCCESS;
    if (links.links_amount <= 0)
        rc = INCORRECT_POINTS_AMOUNT;

    if (!f || !links.links)
        rc = NULL_PTR;

    for (int i = 0; i < links.links_amount && rc == EXIT_SUCCESS; i++)
        if (read_link(links.links + i, f)) {
            rc = READ_LINKS_FAILURE;
        }

    return rc;
}


int model_initial_points_free(initial_points_t &points_xyz) {
    int rc = EXIT_SUCCESS;

    if (!points_xyz.points)
        rc = NULL_PTR;
    else
        free(points_xyz.points);

    return rc;
}

int model_projected_points_free(projected_points_t &points_xy) {
    int rc = EXIT_SUCCESS;

    if (!points_xy.points)
        rc = NULL_PTR;
    else {
        free(points_xy.points);
        points_xy.points = nullptr;
    }

    return rc;
}

int model_links_free(links_t &model_links) {
    int rc = EXIT_SUCCESS;
    if (!model_links.links)
        rc = NULL_PTR;
    else
        free(model_links.links);

    return rc;
}

int model_delete(model_t model) {
    int rc = EXIT_SUCCESS;
    if (model_initial_points_free(model.points_xyz))
        rc = NULL_PTR;
    else if (model_projected_points_free(model.points_xy))
        rc = NULL_PTR;
    else if (model_links_free (model.links))
        rc = NULL_PTR;

    return rc;
}

int model_delete(model_t model, scene_t &scene) {
    int rc = EXIT_SUCCESS;
    if (model_initial_points_free(model.points_xyz))
        rc = NULL_PTR;
    else if (model_projected_points_free(model.points_xy))
        rc = NULL_PTR;
    else if (model_links_free (model.links))
        rc = NULL_PTR;

    scene_clear(scene);

    return rc;
}
