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

htab_t *htab_move(size_t n, htab_t *from)
{
	htab_t *new_table = htab_init(n);
	if(new_table == NULL)
	{
		return NULL;
	}

	// vytvoreni zaznamu podle prvni tabulky
	htab_iterator_t print_iter = htab_begin(from);
	htab_iterator_t iter_end = htab_end(from);
	
	while(print_iter.idx != iter_end.idx)
	{
		htab_iterator_t new_item = htab_lookup_add(new_table, htab_iterator_get_key(print_iter));
		htab_iterator_set_value(new_item, htab_iterator_get_value(print_iter));

		print_iter = htab_iterator_next(print_iter);
	}

	new_table->size = from->size;

	htab_clear(from);

	return new_table;
}
