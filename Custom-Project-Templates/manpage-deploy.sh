#! /usr/bin/bash
NAME=testmanpage
install -g 0 -o 0 -m 0644 ${NAME}.1 /usr/local/man/man8/
gzip /usr/local/man/man8/${NAME}.1
