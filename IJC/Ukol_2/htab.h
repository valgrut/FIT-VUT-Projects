/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   2
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#ifndef __HTABLE_H__
#define __HTABLE_H__
#include <string.h> // size_t
#include <stdbool.h> // bool
#include <stdlib.h>


struct htab; // neúplná deklarace struktury - uživatel nevidí obsah
typedef struct htab htab_t; // typedef podle zadání

// iterátor do tabulky:
struct htab_item; // neúplná deklarace struktury

typedef struct htab_iterator 
{
	struct htab_item *ptr; // ukazatel na položku
	const htab_t *t; // ve které tabulce
	int idx; // ve kterém seznamu tabulky (TODO: optimalizovat?)
} htab_iterator_t; // typedef podle zadání

// rozptylovací (hash) funkce
unsigned int htab_hash_function(const char *str);

htab_t *htab_init(size_t n);
htab_t *htab_move(size_t n, htab_t *from);
size_t htab_size(const htab_t * t); // počet záznamů v tabulce
size_t htab_bucket_count(const htab_t * t); // velikost pole

htab_iterator_t htab_lookup_add(htab_t * t, const char *key);
htab_iterator_t htab_begin(const htab_t * t);
htab_iterator_t htab_end(const htab_t * t);
htab_iterator_t htab_iterator_next(htab_iterator_t it);

inline bool htab_iterator_valid(htab_iterator_t it) { return it.ptr!=NULL; }
inline bool htab_iterator_equal(htab_iterator_t it1, htab_iterator_t it2) {
	return it1.ptr==it2.ptr && it1.t == it2.t;
}

const char * htab_iterator_get_key(htab_iterator_t it);
int htab_iterator_get_value(htab_iterator_t it);
int htab_iterator_set_value(htab_iterator_t it, int val);

void htab_clear(htab_t * t);
void htab_free(htab_t * t);
#endif // __HTABLE_H__
