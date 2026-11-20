/**
 * @file Conj_estacions.cc
 * @brief
 */
#include "Conj_estacions.hh"

Conj_estacions::Conj_estacions(){
   lliures_totals = 0;
}

void Conj_estacions::alta_bici(string idb, string ide){
   map<string,Estacio>::iterator it;
    it = conj_estacions.find(ide);
    (*it).second.afegir_bici(idb);
    --lliures_totals;
}

void Conj_estacions::eliminar_bici(string idb, string ide){
   map<string,Estacio>::iterator it;
   it = conj_estacions.find(ide);
   (*it).second.borrar_bici(idb);
   ++lliures_totals;
}

void Conj_estacions::moure_bici(string ide_inicial, string ide_final, string idb){
   map<string,Estacio>::iterator it;
   map<string,Estacio>::iterator it2;
   it = conj_estacions.find(ide_inicial);
   it2 = conj_estacions.find(ide_final);
   (*it2).second.afegir_bici(idb);
   (*it).second.borrar_bici(idb);
}

void Conj_estacions::modifica_capacitat(string ide, int x){
   map<string,Estacio>::iterator it = conj_estacions.find(ide);
   int cap_antiga = it->second.pl_estacio() + it->second.nombre_bicis();
   lliures_totals += -cap_antiga + x;
   it->second.modifica_capacitat(x);
}

void Conj_estacions::inicialitzar_estacions(){
   inicialitzar_arbre(t);
}

bool Conj_estacions::existeix_estacio(string ide) const{
   map<string, Estacio>:: const_iterator it = conj_estacions.begin();
   it = conj_estacions.find(ide);
   if (it == conj_estacions.end()) return false;
   else return true;
}

bool Conj_estacions::caben_bicis(string ide) const{
   if((*conj_estacions.find(ide)).second.caben_bicis()) return true;
   return false;
}

void Conj_estacions::bicis_estacio(string ide) const{
   conj_estacions.find(ide)->second.bicis_estacio();
}

int Conj_estacions::nombre_bicis(string ide) const{
   return (*conj_estacions.find(ide)).second.nombre_bicis();
}

int Conj_estacions::places_lliures_totals() const{
   return lliures_totals;
}

void Conj_estacions::subir_bicis(Conj_bicis& b) {
   i_subir_bici(t,b);
}

void Conj_estacions::asignar_estacion(string idb, Conj_bicis& bicis) {
    int pl_estacio, num_est;
    double desocupacio = 0.0;
    string ide;
    i_asignar_estacion(t, ide, desocupacio, num_est, pl_estacio);
    alta_bici(idb, ide);
    bicis.afegir_bici(idb,ide);
    
}

void Conj_estacions::inicialitzar_arbre(BinTree<string> &estacions){
   string ide;
   cin >> ide;
   if (ide != "#"){
      int n;
      cin >> n;
      Estacio e(n);
      lliures_totals += n;
      conj_estacions.insert(make_pair(ide, e));
      BinTree<string> esq,dret;
      inicialitzar_arbre(esq);
      inicialitzar_arbre(dret);
      estacions = BinTree<string> (ide, esq, dret);

      }

   }
   
void Conj_estacions::subir_bicis_fills(string idpare, string ideq, string idd, Conj_bicis& b){
   map<string,Estacio>::iterator ita = conj_estacions.find(idpare);
   map<string,Estacio>::iterator itd = conj_estacions.find(idd);
   map<string,Estacio>::iterator iteq = conj_estacions.find(ideq);
      
   while ((*ita).second.caben_bicis() and ((*iteq).second.nombre_bicis() > 0  or (*itd).second.nombre_bicis() > 0)){ //espai en el pare i existeix algun fill (esq o dret)
         
      if ((*iteq).second.nombre_bicis() > (*itd).second.nombre_bicis()){
         string idb = (*iteq).second.consultar_bici();
         eliminar_bici(idb, ideq);
         alta_bici(idb,idpare);
         b.assignar_estacio_actual(idb,idpare);
      }
      else if ((*itd).second.nombre_bicis() > (*iteq).second.nombre_bicis()){
         string idb = (*itd).second.consultar_bici();
         eliminar_bici(idb, idd);
         alta_bici(idb, idpare);
         b.assignar_estacio_actual(idb,idpare);
      }
      else {
         string idb_eq = (*iteq).second.consultar_bici();
         string idb_d = (*itd).second.consultar_bici();
         if ((idb_eq) < (idb_d)) {
            string idb = (*iteq).second.consultar_bici();
            eliminar_bici(idb, ideq);
            alta_bici(idb, idpare);
            b.assignar_estacio_actual(idb,idpare);
         } 
         else {
            string idb = (*itd).second.consultar_bici();
            eliminar_bici(idb, idd);
            alta_bici(idb, idpare);
            b.assignar_estacio_actual(idb,idpare);
         } 
      }
   }
}

void Conj_estacions::i_subir_bici(const BinTree<string>& a, Conj_bicis& b) {
   if(not a.left().empty() and not a.right().empty()){

      subir_bicis_fills(a.value(),a.left().value(),a.right().value(),b);
      
      i_subir_bici(a.left(), b);
      i_subir_bici(a.right(), b);
   }
}

void Conj_estacions::i_asignar_estacion(const BinTree<string>& t, string& ide, double& coef, int& num_est, int& pl_est) {
    if (t.left().empty() and t.right().empty()) {
        pl_est = conj_estacions[t.value()].pl_estacio();
        num_est = 1;
        if ((coef < pl_est or (coef == pl_est and ide > t.value()))) {
            coef = pl_est;
            ide = t.value();
        }
    }
    else {
        int num_est_esq, num_est_dre, lliures_esq, lliures_dre;
        i_asignar_estacion(t.left(), ide, coef, num_est_esq, lliures_esq);
        i_asignar_estacion(t.right(), ide, coef, num_est_dre, lliures_dre);
        pl_est = lliures_esq + lliures_dre + conj_estacions[t.value()].pl_estacio();
        num_est = num_est_esq + num_est_dre + 1;
        double coef2 = double(pl_est)/double(num_est);
        if ((coef < coef2 or (coef == coef2 and ide > t.value())) and conj_estacions[t.value()].pl_estacio() > 0) {
            coef = coef2;
            ide = t.value();
        }
    }
}