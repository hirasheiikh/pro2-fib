#include "Ciudad.hh"

bool Ciudad:: esta_en_invent(int id, map<int,inventario>& i) {
    map<int,inventario>:: iterator it = i.begin();
    it = i.find(id);
    return (it != i.end());
}
Ciudad::Ciudad() {
    pesototal = 0;
    volumentotal = 0;
    i = map<int,inventario>();
}
void Ciudad::leer_inventario(map<int,caracteristicas>& m) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int idproducto, unid_quiero, unid_tengo;
        cin >> idproducto >> unid_tengo >> unid_quiero;
        poner_prod(idproducto, unid_quiero, unid_tengo, m, false);
    }
}

void Ciudad::escribir_ciudad() {
    map<int,inventario>::iterator it = i.begin();
    while (it != i.end()) {
        cout << it->first <<' ' << it->second.tienes << ' '<<it->second.necesito << endl;
        ++it;
    }
    cout << pesototal << ' ' <<volumentotal <<endl;
}
void Ciudad::poner_prod(int idproducto, int unid_quiero, int unid_tengo, map<int,caracteristicas>& m, bool escribir) {
    if (esta_en_invent(idproducto, i)) cout << "error: la ciudad ya tiene el producto" << endl;
    else {
        inventario inv;
        inv.necesito = unid_quiero;
        inv.tienes = unid_tengo;
        i.insert(make_pair(idproducto, inv));
        pesototal += m[idproducto].peso*unid_tengo;
        volumentotal += m[idproducto].volumen*unid_tengo;
        if (escribir) cout << pesototal << ' ' << volumentotal << endl;
    } 
}
void Ciudad::modificar_prod(int idproducto, int unid_quiero, int unid_tengo,map<int,caracteristicas>& m, bool escribir) {
    if( not esta_en_invent(idproducto, i)) cout << "error: la ciudad no tiene el producto" << endl;
    else {
        pesototal -= m[idproducto].peso*i[idproducto].tienes;
        volumentotal -= m[idproducto].volumen*i[idproducto].tienes;
        inventario inv;
        inv.necesito = unid_quiero;
        inv.tienes = unid_tengo;
        i[idproducto] = inv;
        pesototal += m[idproducto].peso*unid_tengo;
        volumentotal += m[idproducto].volumen*unid_tengo;
        if (escribir) cout << pesototal << ' ' << volumentotal << endl;
    }
}

void Ciudad::quitar_prod(int idproducto, map<int,caracteristicas>& m) {
    if( not esta_en_invent(idproducto, i)) cout << "error: la ciudad no tiene el producto" << endl;
    else {
        pesototal -= m[idproducto].peso*i[idproducto].tienes;
        volumentotal -= m[idproducto].volumen*i[idproducto].tienes;
        i.erase(idproducto);
        cout << pesototal << ' ' << volumentotal << endl;
    }
}
void Ciudad::consultar_prod(int idproducto) {
    if( not esta_en_invent(idproducto, i)) cout << "error: la ciudad no tiene el producto" << endl;
    else {
        cout << i[idproducto].tienes << ' ' << i[idproducto].necesito << endl;
    }
}
map<int,inventario> Ciudad::get_inventario(){
    return i;
}
 