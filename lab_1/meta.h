#ifndef META_H
#define META_H


enum options_t{
    INIT,
    MOVE,
    SCALE,
    ROTATE,
    LOAD,
    DRAW,
    DELETE,
    WRONG_COMMAND,
};

enum rotate_plane {
    XY,
    XZ,
    YZ,
};

// MOVE PARAMETERS
typedef struct {
    double dx;
    double dy;
    double dz;
} parameters_move_t;


// ROTATE PARAMETERS
typedef struct {
    double x;
    double y;
    double z;
    double angle;
    int    plane;
} parameters_rotate_t;

// SCALE PARAMETERS
typedef struct {
    double Mx;
    double My;
    double Mz;
    double kx;
    double ky;
    double kz;
} parameters_scale_t;



typedef struct {
        options_t option;
        char *filename;
        parameters_move_t parameters_move;
        parameters_rotate_t parameters_rotate;
        parameters_scale_t parameters_scale;
} metadata_t;

#endif // META_H
