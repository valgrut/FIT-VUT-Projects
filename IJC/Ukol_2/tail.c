/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   1a 
 * Datum:     22.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LEN_ALLOC 1000 //pocet radku , pro ktery alokuji prostor
#define MAX_LEN 510    // maximalni delka radku 
#define PRINT_N 10     // Vychozi: 10; Kolik radku od konce vytisknout

//zjisti, kolik poslednich radku chceme vytisknout
int get_n(int argc, char *argv[]);

//zjisti, jestli budeme brat vstup ze stdin nebo ze souboru
FILE *get_input(int argc, char *argv[]);

//alokuje pamet pro buffer
char **alloc_line_array(int lines);

//Naplni buffer radkama ze souboru
int fill_buffer(char **buffer, FILE *f);

//Vytiskne vsechny nactene radky
void print_buffer(char **buffer, int lines);

//vytiskne poslednich n radku z bufferu
void print_tail(char **buffer, int lines, int n);

//uvolni alokovanou pamet
void free_buffer(char **buffer, int lines);

int main(int argc, char *argv[]) 
{
	char **buffer = NULL;
	FILE *soubor = NULL;
	int len = 0; 

	int to_print = get_n(argc, argv);       	
	if(to_print == -1) 
	{
		fprintf(stderr, "Chyba: Chybny argument\n");
		return 1;	
	}
	
	soubor = get_input(argc, argv);
	if(soubor == NULL) 
	{
		fprintf(stderr, "Chyba: Nelze otevřít soubor\n");
		return 1;
	}
	
	buffer = alloc_line_array(LEN_ALLOC);
	if(buffer == NULL)
	{
		fprintf(stderr, "Chyba: Alokace se nezdarila.\n");
		return 1;
	}

	len = fill_buffer(buffer, soubor);
	//print_buffer(buffer, len);
	print_tail(buffer, len, to_print);
	free_buffer(buffer, LEN_ALLOC);
	
	return 0;
}

int get_n(int argc, char *argv[]) 
{
	if(argc == 1) 
	{
		return PRINT_N;
	}
	
	if(argc == 2) 
	{
		if(argv[1][0] != '-') 
		{
			return PRINT_N;	
		}
		
		if(argv[1][0] == '-' && argv[1][1] == 'n') 
		{
			return -1;
		}
			
	}

	if(argc == 3 || argc == 4) 
	{
		if(argv[1][0] == '-' && argv[1][1] == 'n') 
		{
			return atol(argv[2]);
		}	
	}

	return PRINT_N;
}

FILE *get_input(int argc, char *argv[]) 
{
	FILE *soubor = NULL;
	
	if(argc == 1) 
	{
		return stdin;
	}
	
	//soubor
	if(argc == 2) 
	{
		if(argv[1][0] != '-') {
			soubor = fopen(argv[1], "r");
			return soubor;	
		}
		
		if(argv[1][0] == '-' && argv[1][1] == 'n') 
		{
			return NULL;
		}
			
	}

	//-n x
	if(argc == 3) 
	{
		if(argv[1][0] == '-' && argv[1][1] == 'n') 
		{
			return stdin;
		}	
	}

	//-n x soubor
	if(argc == 4) 
	{
		if(argv[1][0] == '-' && argv[1][1] == 'n') 
		{
			soubor = fopen(argv[3], "r");
			return soubor;
		}
	}
	return stdin;
}

char **alloc_line_array(int lines) 
{	
	char **buffer = (char **) malloc(lines*sizeof(char*));
	
	if(buffer == NULL) 
	{
		printf("chyba pri alokaci\n"); 
		return NULL;
	}
	
	for(int i = 0; i < lines; i++) 
	{
		buffer[i] = (char*) malloc(MAX_LEN*sizeof(char));
	}	
	return buffer;
}

int fill_buffer(char **buffer, FILE *f) 
{
	int i = 0;
	int count = 0;
	int c;
	int err = 0;
	while((c=fgetc(f)) != EOF) 
	{
		if(i >= MAX_LEN) 
		{
			if(err == 0) 
			{
				fprintf(stderr, "Warning: Zkraceni radku delsiho nez je povolena mez.\n");
				err = 1;
			}
			buffer[count][i] = '\n'; 
			if(c == '\n') 
			{
				count++;
				i = 0;
			}
		} 
		else 
		{
			buffer[count][i] = (char)c; 
			if(c == '\n') 
			{
				buffer[count][i] = (char)c; 
				count++;
				i = 0;
				continue;
			}
			i++;
		}
	}	
	return count;
}

void print_buffer(char **buffer, int lines) 
{
	for(int i = 0; i < lines; i++) 
	{
		//printf("buffer[%d] %s", i, buffer[i]);
		printf("%s", buffer[i]);
	}	
}

void print_tail(char **buffer, int lines, int n) 
{
	int idx = 0;
	if(lines > n) 
	{
		idx = lines - n;
	} 
	else 
	{
		idx = 0; 
	}
	for(int i = idx; i < lines; i++) 
	{
		printf("%s", buffer[i]);
	}	
}

void free_buffer(char **buffer, int lines) 
{
	for(int i = 0; i < lines; i++) 
	{
		free(buffer[i]);
	}
	free(buffer);
}
