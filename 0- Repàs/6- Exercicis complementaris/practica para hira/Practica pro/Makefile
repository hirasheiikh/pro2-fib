OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o Barco.o Producto.o Ciudad.o Funciones.o
	g++ -o program.exe main.o Barco.o Producto.o Ciudad.o Funciones.o

Producto.o:  Producto.cc Producto.hh 
	g++ -c Producto.cc $(OPCIONS)
Barco.o:  Barco.cc Barco.hh Producto.hh
	g++ -c Barco.cc $(OPCIONS)
Ciudad.o:  Ciudad.cc Ciudad.hh Barco.hh
	g++ -c Ciudad.cc $(OPCIONS)
Funciones.o:  Funciones.cc Funciones.hh BinTree.hh Ciudad.hh 
	g++ -c Funciones.cc $(OPCIONS)
main.o: main.cc Funciones.hh 
	g++ -c main.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe

