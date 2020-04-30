#include "model_read.h"

int model_read(model_t &model, char *filename) {
    int rc = EXIT_SUCCESS;
    FILE *f = nullptr;
    init_model_fields(model);

    if (file_open(f, filename)) {
        rc = FILE_OPEN_FAILURE;
    }
    // Разбить: Считвание точек.
    // Считали точки - считываем рёбра
    // Не считали рёбра - освобождаем память под точки - OK
    else if (model_read_points(model.points_xyz, model.points_xy, f)) {
        rc = POINTS_READING_FAILURE;
    }
    else if (model_read_links(model.links, f)) {
        model_initial_points_free(model.points_xyz);
        rc = LINKS_READING_FAILURE;
    }

    fclose(f);
    return rc;
}

int model_read_points(initial_points_t &points_xyz, projected_points_t &points_xy, FILE *f) {
    int rc = EXIT_SUCCESS;

    if (read_amount_of_points(points_xyz.points_amount, points_xy.points_amount, f))
        rc = AMOUNT_OF_POINTS_READING_FAILURE;
    else if (model_initial_points_allocate(points_xyz))
        rc = ALLOCATION_ERROR;
    else if (model_initial_points_read(points_xyz, f)) {
        model_initial_points_free(points_xyz);
        rc = READ_POINTS_FAILURE;
    }
    return rc;
}

int model_read_links(links_t &model_links, FILE *f) {
    int rc = EXIT_SUCCESS;

    if (read_amount_of_links(model_links.links_amount, f)) {
        rc = AMOUNT_OF_LINKS_READING_FAILURE;
    }
    else if (model_links_allocate(model_links)) {
        rc = ALLOCATION_ERROR;
    }
    else if (read_links(model_links.links, model_links.links_amount, f)) {
        model_links_free(model_links);
        rc = READ_LINKS_FAILURE;
    }

    return rc;
}
