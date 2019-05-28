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
#include <stdio.h>

htab_iterator_t htab_iterator_next(htab_iterator_t it)
{
	
	//printf("iterator_next: current idx: %d\n", it.idx);

	htab_iterator_t new_iterator;
	new_iterator.t = it.t;
	new_iterator.idx = it.idx;
	
	if(it.ptr->next != NULL)
	{
		//printf("next neni prazdny\n");
		new_iterator.ptr = it.ptr->next;
		return new_iterator;
	}
	else
	{
		//printf("next je prazdne, hledame dalsi list\n");

		size_t arr_index = it.idx + 1;
		while(arr_index < htab_bucket_count(it.t))
		//while(it.t->array[arr_index] == NULL)
		{
			//printf("arr_index: %d\n", arr_index);
			if(it.t->array[arr_index] != NULL)
			{
				//printf("aktualni list neni NULL\n");
				new_iterator.idx = arr_index;
				new_iterator.ptr = it.t->array[arr_index];
				return new_iterator;
			}

			arr_index++;
		}
		return htab_end(it.t);	
	}

	return new_iterator;
}
