/*
 * primes.c
 * Autor:     Jiri Peska, FIT
 * Priklad:   IJC-DU1 a)
 * Datum:     17.03.2019
 * Prelozeno: gcc version 8.3.0 (Debian 8.3.0-2)
 * Funkce vypise poslednich 10 prvocisel ze zadaneho rozsahu
 */

#include "eratosthenes.h"

#define STROP 123000000L
#define PRVOCISEL 10

int main()
{
    bit_array_alloc(pole, STROP);
    //bit_array_create(pole, STROP);

    Eratosthenes(pole);

    int opacnePoradiPrvocisla = 0;
    unsigned long reverse[PRVOCISEL];
    int pocetVypsanychPrvocisel = 0;

    for(unsigned long bit = STROP-1; bit >= 2; bit--) 
    {
        if(bit_array_getbit(pole, bit) == 0) 
	{
            pocetVypsanychPrvocisel++;
            if(pocetVypsanychPrvocisel <= PRVOCISEL) 
	    {
                reverse[opacnePoradiPrvocisla] = bit;
                opacnePoradiPrvocisla++;
            } 
	    else 
	    {
                break;
            }
        }

    }

    bit_array_free(pole);

    for(int i = PRVOCISEL-1; i >= 0; i--)
    {
        printf("%lu \n", reverse[i]);
    }

    return 0;
}
