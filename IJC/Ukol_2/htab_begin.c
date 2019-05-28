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

htab_iterator_t htab_begin(const htab_t * t)
{
	htab_iterator_t new_iterator;
	new_iterator.t = t;
	new_iterator.ptr = NULL;
	
	if(t == NULL)
	{
		new_iterator.idx = -1;
		return new_iterator;
	}

	size_t arr_idx = 0;
	while(t->array[arr_idx] == NULL)
	{
		arr_idx++;
		if(arr_idx == htab_bucket_count(t))
		{
			new_iterator.idx = htab_bucket_count(t);
			return new_iterator;
		}
	}
	
	new_iterator.ptr = t->array[arr_idx];
	new_iterator.idx = arr_idx;
	return new_iterator;
}
