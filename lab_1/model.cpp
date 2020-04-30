#include "model.h"

model_t init_model() {
    static model_t model;

    init_model_initial_points(model.points_xyz);
    init_model_links(model.links);
    init_model_projected_points(model.points_xy);

    return model;
}

int init_model_initial_points(initial_points_t &initial_points) {
    initial_points.points = nullptr;
    initial_points.points_amount = 0;

    return EXIT_SUCCESS;
}

int init_model_projected_points(projected_points_t &projected_points) {
    projected_points.points = nullptr;
    projected_points.points_amount = 0;

    return EXIT_SUCCESS;
}

int init_model_links(links_t &links) {
    links.links = nullptr;
    links.links_amount = 0;

    return EXIT_SUCCESS;
}


int init_model_fields(model_t &model) {
    init_model_initial_points(model.points_xyz);
    init_model_projected_points(model.points_xy);
    init_model_links(model.links);

    return EXIT_SUCCESS;
}

int model_check(model_t model) {
    if (model_initial_points_check(model.points_xyz) ||
        model_links_check(model.links))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int model_projected_points_check(projected_points_t &projected_points) {
    int rc = EXIT_SUCCESS;

    if (projected_points.points == nullptr)
        rc = INCORRECT_MODEL;
    else if (projected_points.points_amount == 0)
        rc = INCORRECT_MODEL;

    return rc;
}

int model_initial_points_check(initial_points_t &initial_points) {
    int rc = EXIT_SUCCESS;

    if (initial_points.points == nullptr)
        rc = INCORRECT_MODEL;
    else if (initial_points.points_amount == 0)
        rc = INCORRECT_MODEL;

    return rc;
}

int model_links_check(links_t &links) {
    int rc = EXIT_SUCCESS;

    if (links.links== nullptr)
        rc = INCORRECT_MODEL;
    else if (links.links_amount == 0)
        rc = INCORRECT_MODEL;

    return rc;
}

