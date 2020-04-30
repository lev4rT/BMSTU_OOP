#ifndef SCREEN_H
#define SCREEN_H


#include "scene.h"
#include "wrap_functions.h"


enum screen_errors_t{
        CREATE_SCREEN_ERROR,
        INCORRECT_SCENE_WIDTH,
        INCORRECT_SCENE_HEIGHT,
};

screen_t &init_screen();

int fill_screen_data     (screen_t &screen, scene_t &scene);
int place_screen         (scene_t &scene);
int screen_change_params (screen_t &screen, int width, int height, int distance);

#endif // SCREENE_H
