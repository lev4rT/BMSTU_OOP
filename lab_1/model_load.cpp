#include "model_load.h"

int model_update(model_t &target, model_t &source) {
    model_delete(target);
    target = source;

    return EXIT_SUCCESS;
}

int model_load(model_t &model, char *filename) {
    int rc = EXIT_SUCCESS;
    model_t model_buff;

    if (model_read(model_buff, filename))
        rc = MODEL_LOAD_FAILURE;
    else
        model_update(model, model_buff);

    return rc;
}
