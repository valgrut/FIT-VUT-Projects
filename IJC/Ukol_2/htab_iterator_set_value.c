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

int htab_iterator_set_value(htab_iterator_t it, int val)
{
	if(it.ptr != NULL)
		it.ptr->data = val;

	return it.ptr->data;	
}
