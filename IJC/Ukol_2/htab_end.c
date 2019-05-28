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

htab_iterator_t htab_end(const htab_t * t)
{
	htab_iterator_t new_iterator;
	new_iterator.t = t;
	new_iterator.ptr = NULL;
	new_iterator.idx = htab_bucket_count(t);
	return new_iterator;
}
