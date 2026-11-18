/**
 * @file Conj_productes.cc
 * @brief
 */
#include "Conj_productes.hh"

Conj_productes::Conj_productes(){
    
}

void Conj_productes::agregar_productos(){
    int n; //num productes nous
    cin >> n;
    cout << n << endl;
    int ini_id = conj_productes.size()+1;
    for (int i = 0; i < n; ++i){
        Producte p;
        cin >> p.pes >> p.volum;
        conj_productes.insert(make_pair(ini_id+i,p));
    }
}
int Conj_productes::num_productes() const{
    return conj_productes.size();
}
bool Conj_productes::existeix_producte(int idp) const{
    map<int, Producte>::const_iterator it;
    it = conj_productes.find(idp);
    if (it == conj_productes.end()) return false;
    return true;
}
void Conj_productes::inicialitzar_conj_productes(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        Producte p;
        cin >> p.pes >> p.volum;
        conj_productes.insert(make_pair(i+1,p));
    }
}

void Conj_productes::consultar_pes_volum(int& pes, int& volum, int idp) const{
    map<int,Producte>::const_iterator it;
    it = conj_productes.find(idp);
    pes = it->second.pes;
    volum = it->second.volum;
}

void Conj_productes::escribir_producto(int idp) const{
    map<int,Producte>::const_iterator it;
    it = conj_productes.find(idp);
    cout << idp << ' ' << it->second.pes << ' ' << it->second.volum << endl;
}



