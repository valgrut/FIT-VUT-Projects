# Makefile
# Autor:     Jiri Peska, FIT
# Priklad:   IJC-DU1 a),b)
# Datum:     18.03.2019
# Přeloženo: gcc version 8.3.0 (Debian 8.3.0-2)

FLAGS=-std=c11 -O2 -Wall -Wextra -pedantic -lm
CC=gcc
RM=rm -f


all: primes primes-i steg-decode

primes: primes.o eratosthenes.o error.o
	$(CC) $(FLAGS) primes.o eratosthenes.o error.o -o $@

primes.o: primes.c bit_array.h eratosthenes.h
	$(CC) $(FLAGS) -c primes.c -o $@

eratosthenes.o: eratosthenes.c bit_array.h eratosthenes.h
	$(CC) $(FLAGS) -c eratosthenes.c -o $@
	
primes-i: primes.c eratosthenes.o error.o
	$(CC) $(FLAGS) -DUSE_INLINE primes.c eratosthenes.o error.c -o $@
	
steg-decode: steg-decode.o eratosthenes.o error.o ppm.o
	$(CC) $(FLAGS) steg-decode.o eratosthenes.o error.o ppm.o -o $@

steg-decode.o: steg-decode.c eratosthenes.h error.h ppm.h
	$(CC) $(FLAGS) -c steg-decode.c -o $@

bit_array.h: error.o

error.o: error.c error.h
	$(CC) $(FLAGS) -c error.c -o $@

ppm.o: ppm.c ppm.h error.h
	$(CC) $(FLAGS) -c ppm.c -o $@

clean:
	$(RM) *.o

clean-all: 
	$(RM) *.o primes primes-i steg-decode

.PHONY: run
run: runprimes runprimes-i
	
runprimes: primes
	ulimit -s unlimited && time ./primes

runprimes-i: primes-i
	ulimit -s unlimited && time ./primes-i


