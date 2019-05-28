/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   2
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */


#include "htab.h"
#include "private.h"

const char * htab_iterator_get_key(htab_iterator_t it) 
{
	if(it.ptr != NULL)
		return it.ptr->key;

	return NULL;
}
