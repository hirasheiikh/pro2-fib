#include <iostream>
#include"Barco.hh"
#include <map>
#include <set>
using namespace std;
struct inventario {
    int necesito;
    int tienes;
};
class Ciudad {
    public:
    Ciudad();
    void leer_inventario (map<int,caracteristicas>& m);
    void escribir_ciudad();
    void poner_prod(int idproducto, int unid_quiero, int unid_tengo, map<int,caracteristicas>& m, bool escribir);
    void modificar_prod( int idproducto, int unid_quiero, int unid_tengo, map<int,caracteristicas>& m, bool escribir);
    void quitar_prod( int idproducto, map<int,caracteristicas>& m);
    void consultar_prod( int idproducto);
    map<int,inventario> get_inventario();

    private:
    int pesototal;
    int volumentotal;
    map<int,inventario> i;
    static bool esta_en_invent(int id, map<int,inventario>& i);
};