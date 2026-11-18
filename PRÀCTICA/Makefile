OPCIONS =-D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -fno-extended-identifiers -Wno-sign-compare -std=c++11

program.exe: program.o Bici.o Conj_bicis.o Estacio.o Conj_estacions.o
	g++ -o program.exe program.o Bici.o Conj_bicis.o Estacio.o Conj_estacions.o

Bici.o:  Bici.cc Bici.hh
	g++ -c Bici.cc $(OPCIONS)

Conj_bicis.o:  Conj_bicis.cc Conj_bicis.hh
	g++ -c Conj_bicis.cc $(OPCIONS)

Estacio.o:  Estacio.cc Estacio.hh
	g++ -c Estacio.cc $(OPCIONS)

Conj_estacions.o:  Conj_estacions.cc Conj_estacions.hh
	g++ -c Conj_estacions.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe

practica.tar:
	tar -cvf practica.tar justificacio.pdf Conj_estacions.hh Estacio.hh Conj_bicis.hh Bici.hh Conj_estacions.cc Estacio.cc Conj_bicis.cc Bici.cc program.cc html.zip Makefile