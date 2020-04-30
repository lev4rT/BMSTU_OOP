#ifndef MODEL_LOAD_H
#define MODEL_LOAD_H


#include <stdio.h>
#include <stdlib.h>
#include "model_read.h"
#include "model.h"
#include "model_cdio.h"


enum model_load_error_t{
    MODEL_LOAD_FAILURE,
};

int model_update(model_t &target, model_t &source);
int model_load  (model_t &model,  char    *filename);

#endif // MODEL_LOAD_H
