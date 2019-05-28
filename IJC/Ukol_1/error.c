/*
 * error.c
 * Autor:     Jiri Peska, FIT
 * Priklad:   IJC-DU1 a)
 * Datum:     14.03.2019
 * Prelozeno: gcc version 8.3.0 (Debian 8.3.0-2)
 * Funkce slouzici pro vypis chybovych hlaseni
 */

#include "error.h"

/*
 * Funkce tiskne na stderr chybove hlaseni
 */
void warning_msg(const char *fmt, ...) 
{
    va_list arg;
    va_start(arg, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, arg);
    va_end(arg);
}

/*
 * Funkce tiskne na stderr chybove hlaseni a ukonci program
 */
void error_exit(const char *fmt, ...) 
{
    va_list arg;
    va_start(arg, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, arg);
    va_end(arg);
    exit(1);
}
