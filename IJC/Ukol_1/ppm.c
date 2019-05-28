/*
 * ppm.c
 * Autor:     Jiri Peska, FIT
 * Priklad:   IJC-DU1 a)
 * Datum:     18.03.2019
 * Prelozeno: gcc version 8.3.0 (Debian 8.3.0-2)
 * Funkce slouzici pro nacteni dat a pro jejich zapis
 */

#include "ppm.h"

struct ppm * ppm_read(const char * filename) {
    FILE *obr = fopen(filename, "rb");
    if(obr == NULL) {
        warning_msg("Nepovedlo se otevrit soubor %s pro zapis", filename);
        return NULL;
    }

    char ppmformat[2];
    int x;
    int y;
    int color;
    fscanf(obr, "%s %d %d %d", ppmformat, &x, &y, &color);
    fgetc(obr);
    //printf("Test: PPM format: %s / x: %d / y: %d / color: %d\n", ppmformat, x, y, color);
    
    if(ppmformat[0] != 'P' || ppmformat[1] != '6')
    {
        warning_msg("Neočekávaný formát.");
    	return NULL;
    }

    unsigned int datasize = 3 * x * y * sizeof(char);

    struct ppm *image_data = (struct ppm*) malloc(sizeof(struct ppm) + datasize);
    if(image_data == NULL) 
    {
        warning_msg("Nepovedlo se pridelit pamet.");
        return NULL;
    }

    image_data->xsize = x;
    image_data->ysize = y;

    fread(&image_data->data, sizeof(char), datasize, obr);

    fclose(obr);
    return image_data;
}

int ppm_write(struct ppm *p, const char * filename) {
    FILE *obr = fopen(filename, "wb");
    if(obr == NULL) {
        warning_msg("Nepovedlo se otevrit soubor %s pro zapis", filename);
        return -1;
    }

    int datasize = 3 * p->xsize * p->ysize;

    fprintf(obr, "P6\n%d %d\n255\n", p->xsize, p->ysize);
    fwrite(&p, sizeof(char), datasize, obr);

    fclose(obr);
    return 0;
}
