/**
 * @file Conj_estacions.cc
 * @brief
 */
#include "Conj_bicis.hh"

Conj_bicis::Conj_bicis(){}

void Conj_bicis::assignar_estacio_actual(string idb, string ide) {
    conj_bicis[idb].assignar_estacio_actual(ide);
}

void Conj_bicis::afegir_bici(string idb, string ide){
    Bici bici;
    bici.assignar_estacio_actual(ide);
    conj_bicis.insert(make_pair(idb, bici));
}

void Conj_bicis::nou_viatge(string ide_inicial, string ide_final, string idb){
    conj_bicis[idb].nou_viatge(ide_inicial, ide_final);
}

void Conj_bicis::borrar_bici(string idb){
    conj_bicis.erase(idb);
}

bool Conj_bicis::existeix_bici(string idb) const{
    map<string, Bici>::const_iterator it;
    it = conj_bicis.find(idb);
    if (it == conj_bicis.end()) return false;
    return true;
}

string Conj_bicis::estacio_bici(string idb) {
    return conj_bicis[idb].consultar_estacio();
}

void Conj_bicis::escriu_viatges(string idb) {
    conj_bicis[idb].escriu_viatges();
}

