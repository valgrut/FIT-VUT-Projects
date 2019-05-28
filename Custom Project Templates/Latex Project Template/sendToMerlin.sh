#! /bin/bash

FILES="proj4.tex ref.bib Makefile"
LOGIN="xpeska05"
VERBOSE=""

if [ "$1" == "-v" ]; then
	VERBOSE="-v"
fi

echo "Zkousim odeslat soubory pres server merlin."
#scp ${VERBOSE} ${FILES} ${LOGIN}@merlin.fit.vutbr.cz:~/Projekty/ITY/
scp ${VERBOSE} ${FILES} ${LOGIN}@eva.fit.vutbr.cz:~/Projekty/ITY/


if [ $? == 1 ]; then
	echo "Zkousim odeslat soubory pres server eva."
	scp ${VERBOSE} ${FILES} ${LOGIN}@eva.fit.vutbr.cz:~/Projekty/ITY/
	#scp -v Makefile xpeska05@eva.fit.vutbr.cz:~/Projekty/ITY/
else
	echo "Odeslani uspesne dokonceno."
	#exit
fi

if [ $? -eq 1 ]; then
	echo "Soubor se nepodarilo odeslat."
	exit
else
	echo "Provadim make clean && make"
	ssh -t ${LOGIN}@eva.fit.vutbr.cz 'cd ~/Projekty/ITY/ && make clean && make'
	exit
fi
