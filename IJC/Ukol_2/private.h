/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   2
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#include "htab.h"

struct htab
{
	unsigned int size;
        unsigned int arr_size;
	struct htab_item **array;
};

struct htab_item {
	char *key;
	int data;
	struct htab_item *next;
};


