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

size_t htab_bucket_count(const htab_t * t)
{
	if(t == NULL)
	{
		return -1;
	}

	return t->arr_size;
}
