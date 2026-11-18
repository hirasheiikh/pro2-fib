OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: Vaixell.o Conj_productes.o Ciutat.o Conj_ciutats.o program.o
	g++ -o program.exe Vaixell.o Conj_productes.o Ciutat.o Conj_ciutats.o program.o

Barco.o: Vaixell.cc Vaixell.hh
	g++ -c Vaixell.cc $(OPCIONS)

Cjt_producte.o: Conj_productes.cc Conj_productes.hh
	g++ -c Conj_productes.cc $(OPCIONS)

Ciutat.o: Ciutat.cc Ciutat.hh
	g++ -c Ciutat.cc $(OPCIONS)

Cjt_ciutats.o: Conj_ciutats.cc Conj_ciutats.hh
	g++ -c Conj_ciutats.cc $(OPCIONS)

program.o: program.cc 
	g++ -c program.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe *.tar

tar:
	tar cvf practica.tar program.cc Barco.cc Barco.hh Cjt_Cjt_ciutats.cc Cjt_producte.hh Ciutat.cc Ciutat.hh Cjt_ciutats.cc Cjt_ciutats.hh BinTree.hh Makefile
