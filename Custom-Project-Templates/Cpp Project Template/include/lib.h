/**
 * @file lib.h
 *
 * @brief Knihovna funkci k projektu
 * @author Jiri Peska (xpeska05)
 */

#ifndef LIB
#define LIB

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//extern const int maxCount = 255; /**< Maximalni hodnota, ktera jde ulozit na 8 bitu */

/**
 * Funkce vypisujici chybu 
 * @todo Rozsirit moznosti vypisu chyby
 * 
 * @return void
 */
void printError();

/**
 * Funkce pro soucet dvou cisel predanych parametrem 
 * 
 * @param x Prvni cislo
 * @param y Druhe cislo
 * @return Vraci soucet cisel x a y predanych parametrem
 */
int addNumbers(int x, int y);

#endif
