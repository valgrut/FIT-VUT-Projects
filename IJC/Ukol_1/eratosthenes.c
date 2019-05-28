/*
 * eratosthenes.c
 * Autor:     Jiri Peska, FIT
 * Priklad:   IJC-DU1 a)
 * Datum:     14.03.2019
 * Prelozeno: gcc version 8.3.0 (Debian 8.3.0-2)
 * Funkce pro nalezeni provocisel v danem rozsahu
 */

#include "eratosthenes.h"

/*
 * Eratosthenovo sito pro nalezeni prvocisel
 */
void Eratosthenes(bit_array_t pole) {
	unsigned long velikost_pole = bit_array_size(pole);
	unsigned long max = sqrt(velikost_pole);
	
	bit_array_setbit(pole, 0, 1);
	bit_array_setbit(pole, 1, 1);

	//for(int i = 0; i < 100; i++){printf("%d",bit_array_getbit(pole, i));}
	//newline;
	
	for(unsigned long bit = 2; bit <= max; bit++) 
	{
		if(bit_array_getbit(pole, bit) == 0) 
		{
			for(unsigned long j = bit * bit; j < velikost_pole; j += bit) 
			{
				bit_array_setbit(pole, j, 1);
				//printf("skrtam bit: %lu\n", j);
			}
		}
	}
}

