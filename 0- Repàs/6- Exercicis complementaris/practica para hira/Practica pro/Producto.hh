#include <iostream>
#include <map>
using namespace std;

struct caracteristicas {
        int peso;
        int volumen;
    };



    bool existe_producto(map<int,caracteristicas>& m, int id);
    void agregar_productos(map<int,caracteristicas>& m);
    void escribir_porducto(map<int,caracteristicas>& m, int id);
   




