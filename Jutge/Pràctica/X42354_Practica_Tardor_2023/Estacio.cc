/**
 * @file Conj_estacions.cc
 * @brief
 */
#include "Estacio.hh"
using namespace std;
    
Estacio::Estacio(){
        
}

Estacio::Estacio(int n){
    capacitat = n;
    places_lliures_estacio = n;
}

void Estacio::afegir_bici(string idb){
    Bicis.insert(idb);
    --places_lliures_estacio;
}

void Estacio::borrar_bici(string idb){
    Bicis.erase(idb);
    ++places_lliures_estacio;
}

void Estacio::modifica_capacitat(int x){
    places_lliures_estacio += x - capacitat;
    capacitat = x;
}

void Estacio::bicis_estacio() const{
    set<string>::iterator it = Bicis.begin();
    while (it != Bicis.end()) {
        cout << *it << endl;
        ++it;
    }
}

bool Estacio::caben_bicis() const{
    if (places_lliures_estacio == 0) return false;
    return true;
}
    
int Estacio::pl_estacio() const{
    return places_lliures_estacio;
}

int Estacio::nombre_bicis() const{
    return capacitat - places_lliures_estacio;
}

string Estacio::consultar_bici() const {
    set<string>::const_iterator it = Bicis.begin();
    return (*it);
}