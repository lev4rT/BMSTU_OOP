#ifndef WRAP_FUNCTIONS_H
#define WRAP_FUNCTIONS_H


#include "model.h"
#include "scene.h"
#include "screen.h"


int draw_link(point_xy_t &p1, point_xy_t &p2, scene_t &scene);

int get_scene_width     (int &width,    scene_t &scene);
int get_scene_height    (int &height,   scene_t &scene);
int get_screen_distance (int &distance, screen_t &screen);

#endif // WRAP_FUNCTIONS_H
