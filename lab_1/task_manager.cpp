#include "task_manager.h"

int task_manager(metadata_t &metadata, scene_t &scene) {
    int rc;
    static model_t model = init_model();

    switch (metadata.option) {
    case INIT:
        rc = place_screen(scene); // no screen variable - OK!
        break;
    case LOAD:
        rc = model_load(model, metadata.filename);
        break;
    case MOVE:
        rc = model_move(model, metadata.parameters_move);
        break;
    case SCALE:
        rc = model_scale(model, metadata.parameters_scale);
        break;
    case ROTATE:
        rc = model_rotate(model, metadata.parameters_rotate);
        break;
    case DRAW:
        rc = model_draw(model, scene);
        break;
    case DELETE:
        rc = model_delete(model, scene);
        break;
    default:
        rc = WRONG_COMMAND;
        break;
    }
    return rc;
}

