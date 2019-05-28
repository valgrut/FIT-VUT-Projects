/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   1
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#include <stdio.h>
#include <ctype.h>
#include "io.h"

int get_word(char *s, int max, FILE *f) 
{
	int read_char;
	int string_index = 0;
	int last_char = 0;
	int min_max = max - 1;	
	
	while((read_char=fgetc(f)) != EOF && !isspace(read_char)) 
	{
		//if(c == '\n') return -1;
		if(string_index < min_max) 
		{
			s[string_index] = read_char;
			last_char++;
		}	
		string_index++;
		
	}

	if(read_char == EOF) return read_char;
	if(string_index == 0) return 0;
	
	// na konec je nutne dat znak konce retezce
	s[last_char] = '\0';

	return string_index;
} 
