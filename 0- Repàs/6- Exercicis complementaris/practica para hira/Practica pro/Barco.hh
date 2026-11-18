#include <iostream>
#include <vector>
#include "Producto.hh"
using namespace std;

class Barco {
    
    public:

    Barco();

    void modificar_barco (int idc, int idv, int cc, int cv);
    void escribir_barco();
    int get_idvender();
    int get_idcomprar();
    int get_cantcomprar();
    int get_cantvender();
    
    
    
    
    private:
    int idvender;
    int idcomprar;
    int cantcomprar;
    int cantvender;
    vector<string> ciudadesvisitadas;
    void modificar_cantcomprar(int c);
    void modificar_cantvender(int c) ;
};