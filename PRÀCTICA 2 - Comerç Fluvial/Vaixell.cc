/**
 * @file Vaixell.cc
 * @brief
 */
#include "Vaixell.hh"

Vaixell::Vaixell(){
}
    
void Vaixell::afegir_viaje(string ultima_ciutat){
    ruta.insert(ruta.end(),ultima_ciutat);
}
    
void Vaixell::modificar_barco(int idprod_c, int unitats_c,int idprod_v, int unitats_v){
    idprod_comprar = idprod_c;
    unitats_comprar = unitats_c;
    idprod_vendre = idprod_v;                                 
    unitats_vendre = unitats_v;
}
void Vaixell::inicialitzar_vaixell(){
    cin >> idprod_comprar >> unitats_comprar >> idprod_vendre >> unitats_vendre;
}


void Vaixell::escribir_barco(){
    cout << idprod_comprar << ' ' << unitats_comprar << ' ' << idprod_vendre << ' ' << unitats_vendre << endl;
     list<string>::iterator it = ruta.begin(); //cout ultimes ciutats(ruta)
     while (it!=ruta.end()){
        cout << *it << endl;
        ++it;
     }
}

int Vaixell::consultar_quantitat_comprar(){
    return unitats_comprar;
}

int Vaixell::consultar_quantitat_vendre(){
    return unitats_vendre;
}

int Vaixell::consultar_idp_comprar(){
    return idprod_comprar;
}

int Vaixell::consultar_idp_vendre(){
    return idprod_vendre;
}


