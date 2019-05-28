#! /bin/bash

VERBOSE=""
LOGIN="xpeska05"

if [ "$1" == "-v" ]; then
	VERBOSE="-v"
fi

#scp -v xpeska05@merlin.fit.vutbr.cz:~/Projekty/ITY/dokument.pdf .
scp ${VERBOSE} ${LOGIN}@eva.fit.vutbr.cz:~/Projekty/ITY/proj4.pdf .
