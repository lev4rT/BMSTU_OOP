#include "screen.h"

int place_screen(scene_t &scene) {
    int rc = EXIT_SUCCESS;
    scene.screen = init_screen();
    if (fill_screen_data(scene.screen, scene))
        rc = CREATE_SCREEN_ERROR;

    return EXIT_SUCCESS;
}

int fill_screen_data(screen_t &screen, scene_t &scene) {
    int rc = EXIT_SUCCESS;
    int width_buff    = 0;
    int height_buff   = 0;
    int distance_buff = 0;

    get_scene_width(width_buff, scene);
    get_scene_height(height_buff, scene);
    get_screen_distance(distance_buff, screen);

    if (distance_buff <= 0)
        rc = INCORRECT_SCENE_WIDTH;
    else if (width_buff    <= 0)
        rc = INCORRECT_SCENE_WIDTH;
    else if (height_buff   <= 0)
        rc = INCORRECT_SCENE_HEIGHT;
    else
        screen_change_params(screen, width_buff, height_buff, distance_buff);

    return rc;
}

int screen_change_params(screen_t &screen, int width, int height, int distance) {
    screen.width = width;
    screen.height = height;
    screen.distance = distance;

    return EXIT_SUCCESS;
}

screen_t &init_screen() {
    static screen_t screen;

    screen.width = 0;
    screen.height = 0;
    screen.distance = 100;


    return screen;
}
