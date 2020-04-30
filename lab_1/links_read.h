#ifndef LINKS_READ_H
#define LINKS_READ_H


#include "link.h"
#include "model.h"

enum links_read_errors {
    INCORRECT_AMOUNT_OF_LINKS,
    READ_LINK_FAILURE,
    READ_LINKS_FAILURE,
};


int read_links          (link_t *links, int links_amount, FILE *f);
int read_link           (link_t *link,         FILE *f);
int read_amount_of_links(int    &links_amount, FILE *f);


#endif // LINKS_READ_H
