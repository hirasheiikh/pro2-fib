/**
 * @file Ciutat.cc
 * @brief
 */
#include "Ciutat.hh"
using namespace std;

Ciutat::Ciutat(){
    pes_total = 0;
    volum_total = 0;
}
void Ciutat::poner_prod(int idp, int unitats_te, int unitats_necessita, int pes, int volum, const Conj_productes &conj_productes, bool escriure){
    Producte_Inventari pi;
    pi.unitats_necessita = unitats_necessita;
    pi.unitats_te = unitats_te;
    Productes[idp] = pi;
    conj_productes.consultar_pes_volum(pes, volum,idp);
    for (int i = 0; i < unitats_te; ++i){
        pes_total += pes; 
        volum_total += volum;
    }
     if (escriure) cout << pes_total << ' ' << volum_total << endl;

   
}
void Ciutat::modificar_prod(int idp, int unitats_te, int unitats_necessita, int pes, int volum, const Conj_productes &conj_productes, bool escriure){
    map<int,Producte_Inventari>::iterator it;
    it = Productes.find(idp);
    quitar_prod(idp,pes,volum,conj_productes,false);
    Producte_Inventari pi; // inicialitzem amb les dades anteriors;
    pi.unitats_necessita = unitats_necessita;
    pi.unitats_te = unitats_te;
    Productes[idp] = pi;
    pes_total += pes*unitats_te;
    volum_total += volum*unitats_te; 
    if (escriure) cout << pes_total << ' ' << volum_total << endl;
}

void Ciutat::quitar_prod(int idp, int pes, int volum, const Conj_productes &conj_productes, bool escriure){
    map<int, Producte_Inventari>::const_iterator it;
    it = Productes.find(idp);
    conj_productes.consultar_pes_volum(pes, volum,idp);
    pes_total -= pes*it->second.unitats_te;
    volum_total -= volum*it->second.unitats_te;
    Productes.erase(it);
    if (escriure) cout << pes_total << ' ' << volum_total << endl;
}

void Ciutat::consultar_prod(int idp){
    map<int, Producte_Inventari>::const_iterator it;
    it = Productes.find(idp);
    cout << it->second.unitats_te << ' ' << it->second.unitats_necessita << endl;
}

bool Ciutat::existeix_producte(int idp) const{
    map<int, Producte_Inventari>::const_iterator it;
    it = Productes.find(idp);
    if (it == Productes.end()) return false;
    return true;
}

void Ciutat::leer_inventario(Conj_productes &conj_productes){
    pes_total = 0;
    volum_total = 0;
    Productes.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int idp, unitats_te, unitats_necessita,pes,volum;
        cin >> idp >> unitats_te >> unitats_necessita;
        conj_productes.consultar_pes_volum(pes,volum,idp);
        poner_prod(idp, unitats_te, unitats_necessita, pes, volum, conj_productes, false);
    }
}

void Ciutat::escribir_ciudad(){
    map<int, Producte_Inventari>::const_iterator it = Productes.begin();
    while (it != Productes.end()){
        cout << it->first << ' ' << it->second.unitats_te << ' ' << it->second.unitats_necessita << endl;
        ++it;
    }
    cout << pes_total << ' ' << volum_total << endl;

}
void Ciutat::comerciar(Ciutat& c2, const Conj_productes& conj_productes){
    int pes = 0;
    int volum = 0;
    //conj_productes.consultar_pes_volum(pes,volum,idp);
    map<int,Producte_Inventari>::iterator itc1 = Productes.begin();
    map<int,Producte_Inventari>::iterator itc2 = c2.Productes.begin();
    while (itc1 != Productes.end() and itc2 != c2.Productes.end()) { 
        if (itc1->first < itc2->first) { // El producte itc1->first no està a itc2 
            ++itc1;
        } 
        else if (itc1->first > itc2->first) { // El producte itc2->first no està a itc1
            ++itc2;
        }
        else {
          int u_sobren1 = (itc1->second.unitats_te)-(itc1->second.unitats_necessita);
          int u_sobren2 = (itc2->second.unitats_te)-(itc2->second.unitats_necessita);
          if(u_sobren1 < 0 and u_sobren2 > 0) { //c2 a c1
            int unitats_passar = u_sobren2;
            if((itc1->second.unitats_te) + unitats_passar > (itc1->second.unitats_necessita)) 
                unitats_passar = (itc1->second.unitats_necessita) - (itc1->second.unitats_te); 
            modificar_prod(itc1->first,  (itc1->second.unitats_te + unitats_passar), itc1->second.unitats_necessita, pes,volum,conj_productes,false);
            c2.modificar_prod(itc2->first, (itc2->second.unitats_te - unitats_passar), itc2->second.unitats_necessita,pes,volum,conj_productes,false);
          }
          else if (u_sobren2 < 0 and u_sobren1 > 0) { //c1 a c2 
            int unitats_passar = u_sobren1;
            if((itc2->second.unitats_te) + unitats_passar > (itc2->second.unitats_necessita)) 
                unitats_passar = (itc2->second.unitats_necessita) - (itc2->second.unitats_te); 
            modificar_prod(itc1->first, (itc1->second.unitats_te - unitats_passar),itc1->second.unitats_necessita,pes,volum,conj_productes,false);
            c2.modificar_prod(itc2->first, (itc2->second.unitats_te + unitats_passar),itc2->second.unitats_necessita,pes,volum,conj_productes,false);
          }
          ++itc1;
          ++itc2;
        }
    }
}


pair<int,int> Ciutat::productes_a_intercanviar(int idprod_comprar, int idprod_vendre, int max_comprar, int max_vendre){  //viaje() és igual pero amb una altra implementació 
     map<int,Producte_Inventari>::const_iterator itv = Productes.find(idprod_vendre); 
     map<int,Producte_Inventari>::const_iterator itc = Productes.find(idprod_comprar); 
    pair<int,int> intercanvi(0,0);
    int sobra = itc->second.unitats_te-itc->second.unitats_necessita;
    if(sobra > 0){
        intercanvi.first = sobra;
        if(max_comprar < sobra) intercanvi.first = max_comprar;

    }
    int falta = itv->second.unitats_necessita-itc->second.unitats_te;
    if(falta > 0){
        intercanvi.second = falta;
        if(max_vendre < falta) intercanvi.second = max_vendre;

    }
    return intercanvi;
    

}

pair<int,int> Ciutat::modificar_inventari(int idprod_cv, int vaixell_compra, int vaixell_ven){
    map<int,Producte_Inventari>::iterator it = Productes.find(idprod_cv);
    pair<int,int> total(0,0);
    total.first += it->second.unitats_te - vaixell_compra;
    total.second += it->second.unitats_necessita + vaixell_ven;
    return total;
}
