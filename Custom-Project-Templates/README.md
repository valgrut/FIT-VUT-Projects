# FIT-VUT-Projects
Repo containing my school projects source code.
# scripty - sendToServer.sh getFromServer.sh lze zkopirovat odsud a upravit je podle potreb prislusneho projektu (C, python, ...)

Definice maker:
	#define makro_prikaz do{ prikazy... }while(0) 

https://en.wikipedia.org/wiki/Finite-state_machine

C programming notes:
	http://www.eskimo.com/~scs/cclass/notes/top.html

Flexible array member in a structure in C:
	https://www.geeksforgeeks.org/flexible-array-members-structure-c/

Poznámky: Programovat se naučíte nejlépe praxí - pište si krátké programy
Tip1: Jak zjistit předdefinovaná makra: gcc -E -dM empty.c
Tip2: Překlad s ladicími informacemi: gcc -g program.c
Tip3: Profiling: perf (nebo gcc -pg program.c; ./a.out; gprof)
Tip4: #define makro_prikaz do{ prikazy... }while(0)
Tip5: Automatické generování závislostí pro make: gcc -MM *.c > dep
Tip6: Výpis po fázi preprocessing: gcc -E -P src.c
Tip7: Kontrola odkazů: gcc -fsanitize=address program.c
Tip8: Výpis zapnutých optimalizací: gcc -Q -O2 --help=optimizers
Tip9: Vypnutí ASLR: setarch `uname -m` -R ./program
TipA: Zabudování LD_LIBRARY_PATH=. do programu: gcc -Wl,-rpath,. 

Makefile:
Automatické proměnné

Cíl
$@

První závislost
$<

Všechny závislosti novější než cíl
$?

Všechny závislosti bez duplicit
$^

Všechny závislosti vč. duplicit
$+

Jména složek
$(@D) $(<D) $(^D) $(+D)   

Jména souborů
$(@F) $(<F) $(^F) $(+F)   

Implicitni pravidla v Makefile:
%.o: %.c
	$(CC) $(CFLAGS) -c $<

