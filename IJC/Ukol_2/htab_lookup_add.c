/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   2
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#include <stdio.h>
#include "htab.h"
#include "private.h"


#define debug 0
#undef debug //pro err vypisy zakomentovat

#ifdef debug
#define PRINT(string) fprintf(stderr, "%s\n", string)
#else
#define PRINT(string)
#endif

htab_iterator_t htab_lookup_add(htab_t *t, const char *key) 
{
	//fprintf(stdout, "htab_lookup_add: key: %s\n", key);
	
	// kostrukce iteratoru
	htab_iterator_t new_iterator;
	new_iterator.ptr = NULL;
	new_iterator.t = t;
	new_iterator.idx = 0;

	if(t == NULL) 
	{
		return new_iterator;
	}
	unsigned int hash_index = htab_hash_function(key) % t->arr_size;
	struct htab_item *candidate = t->array[hash_index];

	// prazdny list na indexu
	if(candidate == NULL)
	{
		struct htab_item *new_item = (struct htab_item*) malloc(sizeof(struct htab_item));	
		if(new_item == NULL) 
		{
			return new_iterator;
		}

		//printf("%s  %d\n",key, strlen(key));
		new_item->key = (char*) malloc((strlen(key)+1) * sizeof(char)); //TODO +1???
		if(new_item->key == NULL) 
		{
			return new_iterator;
		}

		// inicializace new_item hodnotami
		strncpy(new_item->key, key, strlen(key)); // TODO urcite +1  ???
		new_item->key[strlen(key)] = '\0';

		new_item->data = 0;
		new_item->next = NULL;
		
		candidate = new_item;
		t->array[hash_index] = new_item;

		// inicializace iteratoru
		new_iterator.idx = hash_index;
		new_iterator.ptr = new_item;

		t->size++;
		return new_iterator;
	}

	/* tento index neni prazdny,takze musime iterovat skrze nej */
	struct htab_item *last = NULL;
	struct htab_item *last_next = candidate; // NULL
	while(last_next != NULL) 
	{
		PRINT(">>Iterujeme listem, dokud na tomto indexu nenajdeme key.");
		//Je-li v aktualni polozce hledany key:
		if(strcmp(last_next->key, key) == 0)
		{
			PRINT(">>Retezce se rovnaji - vracim iterator\n");

			new_iterator.ptr = last_next;
			new_iterator.t = t;
			new_iterator.idx = hash_index;
			return new_iterator;
		}
		PRINT(">>Nenasli jsme shodu, takze jdeme k dalsimu itemu");

		//ulozime si aktualni ukazatel na posledni prvek abysme >neztratili poslední prvek<
		last = last_next;

		//nastavime dalsi ukazatel
		last_next = last_next->next;
	}

	PRINT(">>dosli jsme v listu nakonec ale key to neni, takze ho vytvorime");
	// nenasli jsme KEY, vytvorime na konci listu novy prvek
	struct htab_item *new_item = (struct htab_item*) malloc(sizeof(struct htab_item));	
	if(new_item == NULL) 
	{
		return new_iterator;
	}

	new_item->key = (char*) malloc((strlen(key)+1) * sizeof(char)); //TODO +1???
	if(new_item->key == NULL) 
	{
		return new_iterator;
	}

	strncpy(new_item->key, key, strlen(key)); // TODO urcite +1  ???
	new_item->key[strlen(key)] = '\0';
	
	new_item->data = 0;
	new_item->next = NULL;
	last->next = new_item; // pripojeni k seznamu
	
	new_iterator.t	 = t;
	new_iterator.idx = hash_index;
	new_iterator.ptr = new_item;
	
	t->size++;
	return new_iterator;
}
