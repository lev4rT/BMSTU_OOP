#include "link.h"

int get_link_start_point(link_t link) {
    return link.num_point_start;
}

int get_link_end_point(link_t link) {
    return link.num_point_end;
}
