#! /bin/bash

zip ijcdu.zip *

scp ijcdu.zip xpeska05@merlin.fit.vutbr.cz:~/Projekty/IJC_new/

#scp -v proj1.tex Makefile xpeska05@eva.fit.vutbr.cz:~/Projekty/ITY/

rm ijcdu.zip

