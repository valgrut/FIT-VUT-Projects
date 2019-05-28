# File: Makefile
# Author: Jiri Peska


#-----------------------------------------------------------
#---------------------- SERVER INFO  -----------------------
LOGIN=xpeska05
SERVER_MERLIN=merlin.fit.vutbr.cz
SERVER_EVA=eva.fit.vutbr.cz
SERVER=$(SERVER_EVA)

PROJECT_DIR=test_proj/
SERVER_DIR=~/Projekty/$(PROJECT_DIR)


#-----------------------------------------------------------
#-------------------- COMPILER OPTIONS ---------------------
CC=gcc
CFLAGS=-std=c99 -I. -Wall -Wextra -pedantic

CXX=g++
CXXFLAGS=-std=c++11 -I. -pedantic -Wall -Wextra -Weffc++

POST_FLAGS=-lm
DEBUG_FLAG=-g

# Google: make auto dependency gcc mm
DEPENDENCIES= -MM *.c  #gcc umí vygenerovat cíle a závislosti pro Makefile 

#--- Options for linking and creating static or dynamic libraries ---
#OTHER_OPTIONS=-fPIC -c -shared -static -L -Wl -rpath

#--- predani tomuto makefilu dalsi makefile: ---
# make -S mySpecialMakefile    # napr. pro generovani dokumentace latex


#---------------------------------------------------------
#-------------------- MACROS FLAGS -----------------------
MACROS=#-DTEST -DDEBUG    #uncomment for activation (remove '#' before -DTEST)


#--------------------------------------------------------
#----------------------- LIB PATH -----------------------
LD_LIBRARY_PATH=.


#----------------------------------------------------------
#---------------------- BUILD PATHS -----------------------
#VPATH=doc src include
#vpath %.c src
#vpath %.h include
#vpath %.tex dox

DIRECTORIES=doc/ include/ src/ objects/ exec/
DOC_DIR=doc
INC_DIR=include
SRC_DIR=src
OBJ_DIR=objects
EXEC_DIR=exec
#EXEC_DIR=.

#----------------------------------------------------------
#--------------------- OBJECTS TO BUILD -------------------
EXECUTABLE=$(EXEC_DIR)/project

OBJS=$(OBJ_DIR)/lib.o $(OBJ_DIR)/main.o
#OBJS:=$(wildcard $(OBJ_DIR)/*.o)
DEPS:=$(wildcard $(INC_DIR)/*.h)
SRCS:=$(wildcard $(SRC_DIR)/*.{c,cpp})
#----------------------------------------------------------

.PHONY: all directories clean doc pack run upload valgrind leaks gdb deps macros list tests
all: directories $(EXECUTABLE) 

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	@echo $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@



#- v2 ----- // building via default rules without dir structure // ------
#EXECUTABLE=project
#OBJS=lib.o main.o
#OBJS:=$(wildcard *.o)

#all: $(EXECUTABLE) 

#$(EXECUTABLE): $(OBJS)
#	$(CC) $(CFLAGS) -o $@ $^

#%.o: %.c
#	$(CC) $(CFLAGS) -c $<
#--------------------------------^^----


#-----------------------------------------------------------
#------------------ TARGETS --------------------------------
directories:
	mkdir -p $(DIRECTORIES)

list:
	cat Makefile | grep PHONY

doc: 
	cd $(DOC_DIR) && doxygen Doxyfile

clean:
	rm -f *.o *.a *.so $(LOGIN).zip	$(EXECUTABLE) $(OBJ_DIR)/*.o 
	rm -f -r $(DOC_DIR)/html $(DOC_DIR)/latex

pack:
	zip -r $(LOGIN).zip $(SRC_DIR) $(INC_DIR) Makefile $(DOC_DIR)/Doxyfile

run: $(EXECUTABLE)
	@echo "Args: >$(CMD_ARGS)<"
	./$(EXECUTABLE) $(CMD_ARGS)

# Ex.: For case we want to run more executables with one "make run" call:
#run: run_exec1 runprimes-i
# Pozn.: ulimit -s unlimited changes size of system stack.
# Pozn.: time calculates time of execution
#run_exec1: exec1
#	ulimit -s unlimited && time ./exec1
#run_exec2: exec2
#	ulimit -s unlimited && time ./exec2

upload: pack
	ssh $(LOGIN)@$(SERVER) "if [ ! -d $(SERVER_DIR) ]; then mkdir $(SERVER_DIR); fi && cd $(SERVER_DIR)"
	scp $(LOGIN).zip $(LOGIN)@$(SERVER):$(SERVER_DIR)
	ssh $(LOGIN)@$(SERVER) "cd $(SERVER_DIR) && unzip $(LOGIN).zip && make"
	#scp $(LOGIN).zip $(LOGIN)@$(SERVER):$(SERVER_DIR)    #get result files from server

valgrind: $(EXECUTABLE)
	valgrind ./$(EXECUTABLE) $(CMD_ARGS)

gdb: $(EXECUTABLE)
	gdb -ex ./$(EXECUTABLE) --args $(CMD_ARGS)

leaks: $(EXECUTABLE)
	valgrind --track-origins=yes --leak-check=full --show-reachable=yes ./$(EXECUTABLE) $(CMD_ARGS)

deps:
	$(CC) -MM *.c

macros:
	$(CC) -E -dM *.c

tests:
	@echo "Spoustim testy"
