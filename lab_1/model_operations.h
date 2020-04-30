#ifndef MODEL_OPERATIONS_H
#define MODEL_OPERATIONS_H


#include "model.h"
#include "meta.h"
#include "point_operations.h"

enum model_operations_errors {
    MODEL_MOVE_ERROR,
    MODEL_SCALE_ERROR,
    MODEL_ROTATE_ERROR,
};


int model_move   (model_t &model, parameters_move_t &params);
int model_scale  (model_t &model, parameters_scale_t &params);
int model_rotate (model_t &model, parameters_rotate_t &params);

#endif // MODEL_OPERATIONS_H
