/*
 * error.h
 * Autor:     Jiri Peska, FIT
 * Priklad:   IJC-DU1 b)
 * Datum:     14.03.2019
 * Prelozeno: gcc version 8.3.0 (Debian 8.3.0-2)
 * Funkce slouzici pro vypis chybovych hlaseni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);
