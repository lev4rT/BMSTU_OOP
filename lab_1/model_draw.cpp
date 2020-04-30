#include "model_draw.h"

int model_draw(model_t &model, scene_t &scene) {
    // rc = ... ! - OK
    int rc = EXIT_SUCCESS;

    if (model_check(model))
        rc = INCORRECT_MODEL;
    else if (model_projected_points_allocate(model.points_xy) || scene_clear(scene))
        rc = ALLOCATION_ERROR;
    else if (get_projected_points(model.points_xy, model.points_xyz, scene.screen))
        rc = CANNOT_GET_PROJECTION;
    else
        rc = draw_links(model.points_xy, model.links, scene);

    model_projected_points_free(model.points_xy); // free из блоков - OK
    return rc;
}

int get_projected_points(projected_points_t &points_xy, initial_points_t &points_xyz, screen_t screen) {
    int rc = EXIT_SUCCESS;
    if (model_projected_points_check(points_xy) ||
        model_initial_points_check(points_xyz))
            rc = INCORRECT_MODEL;
    else
        for (int i = 0; i < points_xyz.points_amount; i++)
            get_projected_point(points_xy.points[i], points_xyz.points[i], screen.distance);
    return rc;
}

int get_projected_point(point_xy_t &point_xy, point_t point_xyz, double k) {
    point_xy.x = k * (point_xyz.x) / (point_xyz.z + k);
    point_xy.y = -k * (point_xyz.y) / (point_xyz.z + k);

    return EXIT_SUCCESS;
}

int draw_links(projected_points_t &projected, links_t &model_links, scene_t &scene) {
    int rc = EXIT_SUCCESS;

    for(int i = 0; i < model_links.links_amount && rc == EXIT_SUCCESS; i++) {
        int start = get_link_start_point(model_links.links[i]);  // Доступ к полю поля. Так делать не нужно!
        int end   = get_link_end_point(model_links.links[i]);   // Только одна . или ->
        if (draw_link(projected.points[start], projected.points[end], scene)) // canvas На более низком уровне(функция-обёртка) - ОК
            rc = EXIT_FAILURE;
    }

    return rc;
}

