/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   2
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#include "htab.h"
#include "private.h"

void htab_clear(htab_t *t) 
{
	struct htab_item *tmp = NULL;
	struct htab_item *current = NULL;
	
	for(unsigned int i = 0; i < t->arr_size; i++) 
	{
		//pokud je dany index prazdny, tak prejdeme k dalsi iteraci
		if(t->array[i] == NULL) 
			continue;
		
		current = t->array[i];
		t->array[i] = NULL;
		
		while(current != NULL) 
		{
			//ulozim si ukazatel na dalsi prvek
			tmp = current->next;
						
			//provedeme dealokaci
			free(current->key);
			free(current);
	
			//prejdeme na dalsi prvek
			current = tmp;
		}
	}
	
	t->size = 0;
	
	return;	
}
