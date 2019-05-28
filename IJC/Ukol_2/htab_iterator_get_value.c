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

int htab_iterator_get_value(htab_iterator_t it)
{
	if(it.ptr != NULL)
		return it.ptr->data;
	
	return -1;
}
