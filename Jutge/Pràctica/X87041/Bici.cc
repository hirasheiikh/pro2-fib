/**
 * @file Conj_estacions.cc
 * @brief
 */
#include "Bici.hh"

Bici::Bici(){}

void Bici::nou_viatge(string ide_inicial, string ide_final){
    pair<string,string> nou(ide_inicial,ide_final);
    viatges.insert(viatges.end(), nou);
    est = ide_final;
}

void Bici::assignar_estacio_actual(string ide){
    est = ide;
}

string Bici::consultar_estacio() const {
    return est;
}

void Bici::escriu_viatges(){
    list<pair<string,string>>::iterator it = viatges.begin();
    while (it != viatges.end()) {
        cout << it->first << ' ' << it->second << endl;
        ++it;
    }
}

