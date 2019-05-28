/*
 * steg_decode.c
 * Autor:     Jiri Peska, FIT
 * Priklad:   IJC-DU1 a)
 * Datum:     18.03.2019
 * Prelozeno: gcc version 8.3.0 (Debian 8.3.0-2)
 * Dekoduje z PPM obrazku zpravu
 */

#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ppm.h"
#include "eratosthenes.h"

#define LIMIT 5000*5000*3
#define MESSAGE_MAX 500

void decode_ppm_msg(const char filename[]) 
{
	struct ppm *image_data = ppm_read(filename);
	if(image_data == NULL) 
	{
		error_exit("Nastala chyba pri alokaci\n");	
	} 

	unsigned long current_size = (3 * image_data->xsize * image_data->ysize);
	if(current_size > LIMIT) 
	{
		free(image_data);
		error_exit("Byla prekrocena maximalni povolena velikost.\n");
	}

	bit_array_alloc(pole, current_size * CHAR_BIT);
	//bit_array_create(pole, current_size * CHAR_BIT); 
	Eratosthenes(pole);

	char message[MESSAGE_MAX] = {0}; // pevna velikost pole pro zpravu neni vhodna, ale pro ramec ukolu snad bude dostacujici
	int message_index = 0;
	unsigned bit_position = 0;
	
	// zprava zacina na 19. prvocislelnem bytu
	for(unsigned long byte = 19; byte < current_size; byte++)
	{
		// pokud je aktualni byte podle eratosthena prvociselny
		if(bit_array_getbit(pole, byte) == 0)
		{
			// vezmu LSB a zapisu ho na pozici "bit_position" v aktivnim prvku pole.
			if((image_data->data[byte] & 1))
			{
				message[message_index] |= (1 << (bit_position));
			}
			
			// mame 8. bit znaku, takze mame dalsi kompletni znak zpravy
			if(bit_position == 7)
			{	
				// dosli jsme na konec zpravy
				if(message[message_index] == '\0')
				{
					break;
				}

				// jsme za zpravou, ale nebyla ukoncena znakem '\0'
				/*
				if( ! isprint(message[message_index]) && ! isspace(message[message_index]))
				{
					bits(message[message_index]);
					printf("%c %d\n", message[message_index], message_index);
					//error_exit("Zpráva nebyla korektně ukončena nulovým znakem.");
				}
				*/
				if(message_index == MESSAGE_MAX-1)
				{
					error_exit("Zpráva nebyla korektně ukončena nulovým znakem.");
				}

				message_index++;
				bit_position = 0;
				continue;
			}
			else
			{
				bit_position++;
			}
		}
	}

	fprintf(stdout, "%s\n", message);

	bit_array_free(pole);
	free((void *)image_data);
	image_data = NULL;
}

int main(int argc, char *argv[]) 
{
	if(argc != 2) 
	{
		error_exit("Neocekavany pocet argumentu.\n");
	}

	decode_ppm_msg(argv[1]);

	return 0;
}
