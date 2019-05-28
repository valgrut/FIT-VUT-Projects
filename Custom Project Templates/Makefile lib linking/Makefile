# Jmeno: Jiri Peska
# Login: xpeska05
# Datum: 24.4.2019
# IJC PROJ2 Makefile

CC=gcc
CPP=g++
CFLAGS=-std=c99 -Wall -Wextra -pedantic

LIBHTAB_STATIC=htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o htab_bucket_count.o htab_clear.o htab_free.o htab_begin.o htab_end.o htab_iterator_next.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_set_value.o 
LIBHTAB_DYNAMIC=htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o htab_bucket_count.o htab_clear.o htab_free.o htab_begin.o htab_end.o htab_iterator_next.o htab_iterator_get_key.o htab_iterator_get_value.o htab_iterator_set_value.o 

LD_LIBRARY_PATH=.

MACRO=
#uncomment for use.
#MACROS=-DTEST

all: wordcount tail tail2 wordcount-dynamic
#dynamic: wordcount-dynamic

tail: tail.o
	$(CC) $(CFLAGS) tail.o -o tail
tail.o: tail.c
	$(CC) $(CFLAGS) -c tail.c 

tail2: tail2.o
	$(CPP) -std=c++11 -pedantic -Wall -Wextra tail2.o -o tail2
tail2.o: tail2.cc
	$(CPP) -std=c++11 -pedantic -Wall -Wextra -c tail2.cc


#------------- Static build -----------------
wordcount: wordcount.o io.o libhtab.a
	$(CC) $(CFLAGS) $(MACROS) -static wordcount.o io.o libhtab.a -o wordcount

wordcount.o: wordcount.c
	$(CC) $(CFLAGS) $(MACROS) -c -fPIC wordcount.c -o wordcount.o


#----------- Dynamic build --------------
wordcount-dynamic: wordcount.o io.o libhtab.so
	$(CC) $(CFLAGS) $(MACROS) -L$(LD_LIBRARY_PATH) -Wl,-rpath=$(LD_LIBRARY_PATH) wordcount.o io.o libhtab.so -o wordcount-dynamic libhtab.so


#----------- static lib --------------
libhtab.a: $(LIBHTAB_STATIC)
	ar crs libhtab.a $(LIBHTAB_STATIC)

#----------- dynamic lib --------------
libhtab.so: $(LIBHTAB_DYNAMIC) 	
	$(CC) -shared -fPIC $(LIBHTAB_DYNAMIC) -o libhtab.so -L$(LD_LIBRARY_PATH)

#------------ Objects -----------------
io.o: io.c io.h
	$(CC) $(CFLAGS) -c -fPIC io.c -o io.o

htab_hash_function.o: htab_hash_function.c
	$(CC) $(CFLAGS) -c -fPIC htab_hash_function.c 

htab_init.o: htab_init.c
	$(CC) $(CFLAGS) -c -fPIC htab_init.c

htab_lookup_add.o: htab_lookup_add.c
	$(CC) $(CFLAGS) -c -fPIC htab_lookup_add.c 

htab_clear.o: htab_clear.c
	$(CC) $(CFLAGS) -c -fPIC htab_clear.c 

htab_size.o: htab_size.c
	$(CC) $(CFLAGS) -c -fPIC htab_size.c 

htab_bucket_count.o: htab_bucket_count.c
	$(CC) $(CFLAGS) -c -fPIC htab_bucket_count.c 

htab_free.o: htab_free.c
	$(CC) $(CFLAGS) -c -fPIC htab_free.c 

htab_end.o: htab_end.c
	$(CC) $(CFLAGS) -c -fPIC htab_end.c 

htab_begin.o: htab_begin.c
	$(CC) $(CFLAGS) -c -fPIC htab_begin.c 

htab_iterator_get_key.o: htab_iterator_get_key.c
	$(CC) $(CFLAGS) -c -fPIC htab_iterator_get_key.c 

htab_iterator_get_value.o: htab_iterator_get_value.c
	$(CC) $(CFLAGS) -c -fPIC htab_iterator_get_value.c 

htab_iterator_set_value.o: htab_iterator_set_value.c
	$(CC) $(CFLAGS) -c -fPIC htab_iterator_set_value.c 

htab_iterator_next.o: htab_iterator_next.c
	$(CC) $(CFLAGS) -c -fPIC htab_iterator_next.c 

htab_move.o: htab_move.c
	$(CC) $(CFLAGS) -c -fPIC htab_move.c 

clean:
	rm -f *.o *.a *.so tail tail2 wordcount wordcount-dynamic

pack:
	zip xpeska05.zip *.c *.cc *.h Makefile
