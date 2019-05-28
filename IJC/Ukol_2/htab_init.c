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

htab_t *htab_init(size_t n) 
{
	htab_t *table = (htab_t*) malloc(sizeof(htab_t)); 
	if(table == NULL)
	{	
		return NULL;
	}
	
	table->size = 0;
	table->arr_size = n;
	
	table->array = (struct htab_item**) malloc(table->arr_size * sizeof(struct htab_item*));
	if(table->array == NULL) 
	{
		return NULL;
	}

	for(unsigned int i = 0; i < table->arr_size; i++) {
		table->array[i] = NULL;	
	}
	
	return table;
}
