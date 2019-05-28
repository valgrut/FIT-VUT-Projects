/*
 * Jmeno:     Jiri Peska
 * Login:     xpeska05
 * Fakulta:   FIT VUT Brno
 * Priklad:   2
 * Datum:     24.4.2019
 * Prekladac: gcc version 8.3.0 (Debian 8.3.0-2)
 */

#include <stdint.h>

unsigned int htab_hash_function(const char *str) {
          uint32_t h=0;
          const unsigned char *p;
          for(p=(const unsigned char*)str; *p!='\0'; p++)
              h = 65599*h + *p;
          return h;
}
