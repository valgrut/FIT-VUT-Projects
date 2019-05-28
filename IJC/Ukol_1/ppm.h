/*
 * ppm.h
 * Autor:     Jiri Peska, FIT
 * Priklad:   IJC-DU1 a)
 * Datum:     18.03.2019
 * Prelozeno: gcc version 8.3.0 (Debian 8.3.0-2)
 * Funkce slouzici pro nacteni dat a pro jejich zapis
 */

#include <stdio.h>
#include <math.h>
#include "error.h"

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[]; // RGB bajty, celkem 3*xsize*ysize
};

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);
int ppm_write(struct ppm *p, const char * filename);

