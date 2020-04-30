#include "wrap_functions.h"

// В обёрточных ф-ия может быть 2 точки или ->
int draw_link(point_xy_t &p1, point_xy_t &p2, scene_t &scene)
{
    scene.canvas->addLine(p1.x, p1.y, p2.x, p2.y);
    return EXIT_SUCCESS;
}

int get_scene_height(int &height, scene_t &scene)
{
    height = static_cast<int>(scene.canvas->height());
    return EXIT_SUCCESS;
}


int get_scene_width(int &width, scene_t &scene)
{
    width = static_cast<int>(scene.canvas->width());
    return EXIT_SUCCESS;
}

int get_screen_distance(int &distance, screen_t &screen) {
    distance = screen.distance;
    return EXIT_SUCCESS;
}

int scene_clear(scene_t &scene) {
    scene.canvas->clear();
    return EXIT_SUCCESS;
}
