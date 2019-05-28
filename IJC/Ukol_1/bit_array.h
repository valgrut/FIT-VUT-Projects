/*
 * bit_array.h
 * Autor:     Jiri Peska, FIT
 * Priklad:   IJC-DU1 a)
 * Datum:     13.03.2019
 * Prelozeno: gcc version 8.3.0 (Debian 8.3.0-2)
 * Makra slouzici pro praci s bitovym polem
 */

#include "error.h"
#include <limits.h>
#include <stdlib.h>
#include <assert.h>

/*
 * Typ bitoveho pole
 */
typedef unsigned long bit_array_t[];

#define LONG (sizeof(unsigned long) * CHAR_BIT)


//static_assert(((long long)(ULONG_MAX - velikost + sizeof(unsigned long)*8)), "Byla překročena maximální velikost pole.");
//static_assert(5000*5000*3*8, "Byla překročena maximální velikost pole.");
#define bit_array_create(jmeno_pole,velikost) \
	unsigned long jmeno_pole[(velikost/CHAR_BIT) + sizeof(unsigned long)]; \
	memset(jmeno_pole, 0, (velikost/CHAR_BIT)*sizeof(unsigned long)); \
	jmeno_pole[0] = ((velikost)+sizeof(unsigned long)*CHAR_BIT)


//assert(!((long long)(ULONG_MAX - velikost + sizeof(unsigned long)*CHAR_BIT) < 0));
//assert(((long long)(ULONG_MAX - velikost + sizeof(unsigned long)*CHAR_BIT) < 0LL));
#define bit_array_alloc(jmeno_pole,velikost) \
	unsigned long * jmeno_pole = (unsigned long *) calloc((velikost/CHAR_BIT) + sizeof(unsigned long), sizeof(unsigned long)); \
	if(jmeno_pole == NULL) fprintf(stderr, "bit_array_alloc: Chyba alokace paměti\n"); \
	else jmeno_pole[0] = ((velikost)+sizeof(unsigned long)*CHAR_BIT)


#define bit_array_free(jmeno_pole) \
	free(jmeno_pole);


#ifndef USE_INLINE
#define bit_array_size(jmeno_pole) \
	(jmeno_pole[0] - (sizeof(unsigned long)*CHAR_BIT))


#define bit_array_setbit(jmeno_pole,index,hodnota) \
	if((unsigned long)index >= bit_array_size(jmeno_pole)) { \
		error_exit("bit_array_setbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bit_array_size(jmeno_pole)); } \
if(hodnota == 0) {\
	jmeno_pole[(index + LONG) / LONG] &= ~(1UL << (index % (LONG))); \
} else {\
	jmeno_pole[(index + LONG) / LONG] |= (1UL << (index % (LONG)));} 


#define bit_array_getbit(jmeno_pole,index) \
	((unsigned long)index >= ((unsigned long)bit_array_size(jmeno_pole))) \
	? (error_exit("bit_array_getbit: Index %lu mimo rozsah 0..%lu\n",(unsigned long)index, (unsigned long)(bit_array_size(jmeno_pole))), 0 ) : \
	((jmeno_pole[(index + LONG) / LONG] & (1UL << (index % LONG))) != 0)

#endif



#ifdef USE_INLINE
/*
 * Inline verze maker
 */
static inline unsigned long bit_array_size(bit_array_t jmeno_pole);
static inline unsigned long bit_array_getbit(bit_array_t jmeno_pole, unsigned long index);
static inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, int hodnota);

static inline unsigned long bit_array_size(bit_array_t jmeno_pole) 
{
	return jmeno_pole[0];
}

static inline unsigned long bit_array_getbit(bit_array_t jmeno_pole, unsigned long index) 
{
	if(index > bit_array_size(jmeno_pole))
		error_exit("bit_array_getbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bit_array_size(jmeno_pole));

	return ((jmeno_pole[(index + LONG) / LONG] & (1UL << (index % LONG))) != 0);
}

static inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, int hodnota) 
{
	if(index > bit_array_size(jmeno_pole))
		error_exit("bit_array_setbit: Index %lu mimo rozsah 0..%lu", (unsigned long)index, (unsigned long)bit_array_size(jmeno_pole));

	if(hodnota == 0) 
	{
		jmeno_pole[(index + LONG) / LONG] &= ~(1UL << (index % (LONG)));
	} 
	else 
	{
		jmeno_pole[(index + LONG) / LONG] |= (1UL << (index % (LONG)));
	} 
}

#endif // USE_INLINE
