#include "links_read.h"

int read_amount_of_links(int &links_amount, FILE *f) {
    int rc = EXIT_SUCCESS;
    if (fscanf(f, "%d", &links_amount) != 1 || links_amount <= 0)
        rc = INCORRECT_AMOUNT_OF_LINKS;

    return rc;
}

int read_link(link_t *link, FILE *f) {
    int rc = EXIT_SUCCESS;
    if (fscanf(f, "%d %d", &(link->num_point_start), &(link->num_point_end)) != 2)
        rc = READ_LINK_FAILURE;

    return rc;
}

int read_links(link_t *links, int links_amount, FILE *f) {
    int rc = EXIT_SUCCESS;

    if (links_amount <= 0)
        rc = INCORRECT_AMOUNT_OF_LINKS;
    else if (!f)
        rc = NULL_PTR;
    else
        for (int i = 0; i < links_amount && rc == EXIT_SUCCESS; i++)
            if (read_link(links + i, f)) {
                rc = READ_LINKS_FAILURE;
            }

    return rc;
}

