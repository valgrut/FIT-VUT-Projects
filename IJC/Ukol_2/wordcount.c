/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   2
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "io.h"
#include "private.h"

/*
 * Vzhledem k informacim na zminene webove strance volim prvocislo 12289.
 * viz. http://planetmath.org/goodhashtableprimes
 * 
 * Pozn.: Po vyzkouseni "make" na serveru merlin, se objevila chyba s nedostatkem mista na zarizeni. Nepovedlo se mi problem vyresit a pres chybu se dostat. 
 * Na serveru eva ale vse funguje tak, jak se ocekava.
 */

#define TABSIZE 12289
#define MAXLEN 127 

int main() 
{
	htab_t * hash_table = htab_init(TABSIZE);
	if(hash_table == NULL)
	{
		fprintf(stderr,"Inicializace tabulky se nezdarila\n");
		return 1;
	}

	char read_string[MAXLEN+1]; // +1
	int length;
	int error_printed = 0;
	while((length = get_word(read_string, MAXLEN, stdin)) != EOF)
	{
		if(length != EOF && length ==0) 
			continue;
		
		htab_iterator_t new_iter = htab_lookup_add(hash_table, read_string);
		htab_iterator_set_value(new_iter, htab_iterator_get_value(new_iter) + 1);
		
		if(length > 127 && error_printed == 0) 
		{
			fprintf(stderr, "Byla prekrocena povolena delka slova %d znaku, nasledujici budou zkracena\n", MAXLEN);
			error_printed = 1;
		}
	}

#ifdef TEST
	htab_t *move_table = htab_move(TABSIZE, hash_table);
	htab_t *tmp_table = hash_table;
	hash_table = move_table;
#endif	

	// inicializujeme iteratory
	htab_iterator_t print_iter = htab_begin(hash_table);
	htab_iterator_t iter_end = htab_end(hash_table);
	
	while(print_iter.idx != iter_end.idx)
	{
		printf("%s: %d\n", htab_iterator_get_key(print_iter), htab_iterator_get_value(print_iter));
		print_iter = htab_iterator_next(print_iter);
	}

	free(hash_table);

#ifdef TEST
	free(tmp_table);
#endif

	return 0;
}
