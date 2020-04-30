#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

typedef struct {
        int width;
        int height;
        int distance;
} screen_t;

typedef struct {
        QGraphicsScene *&canvas;
        screen_t        &screen;
} scene_t;

int scene_clear(scene_t &scene);

#endif // SCENE_H
