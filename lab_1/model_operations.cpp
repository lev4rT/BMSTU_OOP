#include "model_operations.h"

int model_move(model_t &model, parameters_move_t &params) {
    int rc = EXIT_SUCCESS;

    if (model_check(model))
        rc = INCORRECT_MODEL;
    else if (points_move(model.points_xyz, params))
        rc = MODEL_MOVE_ERROR;

    return rc;
}

int model_scale(model_t &model, parameters_scale_t &params) {
    int rc = EXIT_SUCCESS;

    // Структурировать данные! - OK
    if (model_check(model))
        rc = INCORRECT_MODEL;
    else if (points_scale(model.points_xyz, params))
        rc = MODEL_SCALE_ERROR;

    return rc;
}

int model_rotate(model_t &model, parameters_rotate_t &params) {
    int rc = EXIT_SUCCESS;

    // Структурировать данные! - OK
    if (model_check(model))
        rc = INCORRECT_MODEL;
    else if (points_rotate(model.points_xyz, params))
        rc = MODEL_ROTATE_ERROR;

    return rc;
}
