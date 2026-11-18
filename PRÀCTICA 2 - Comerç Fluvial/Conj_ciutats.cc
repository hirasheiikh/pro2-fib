/**
 * @file Conj_ciutats.cc
 * @brief
 */
#include "Conj_ciutats.hh"

Conj_ciutats::Conj_ciutats(){
}

void Conj_ciutats::poner_prod(string idc, int idp, int unitats_te, int unitats_necessita, int pes, int volum, const Conj_productes& conj_productes){
    map<string, Ciutat>::iterator it = conj_ciutats.find(idc);
    conj_productes.consultar_pes_volum(pes,volum,idp);
    it->second.poner_prod(idp,unitats_te,unitats_necessita,pes,volum,conj_productes,true);
}

void Conj_ciutats::modificar_prod(string idc, int idp, int unitats_te, int unitats_necessita,int pes, int volum, const Conj_productes& conj_productes){
    map<string, Ciutat>::iterator it = conj_ciutats.find(idc);
    conj_productes.consultar_pes_volum(pes,volum,idp);
    it->second.modificar_prod(idp,unitats_te,unitats_necessita,pes,volum,conj_productes,true);
}
void Conj_ciutats::quitar_prod(string idc, int idp, const Conj_productes& conj_productes, int pes, int volum){
    map<string, Ciutat>::iterator it = conj_ciutats.find(idc);
    conj_productes.consultar_pes_volum(pes,volum,idp);
    it->second.quitar_prod(idp,pes,volum,conj_productes,true);
}
void Conj_ciutats::consultar_prod(string idc, int idp){
    map<string, Ciutat>::iterator it = conj_ciutats.find(idc);
    it->second.consultar_prod(idp);
}

void Conj_ciutats::comerciar(string idc1, string idc2, const Conj_productes& conj_productes){
    map<string,Ciutat>::iterator it1 = conj_ciutats.find(idc1);
    map<string,Ciutat>::iterator it2 = conj_ciutats.find(idc2);
    it1->second.comerciar(it2->second,conj_productes);
}
void Conj_ciutats::redistribuir(const Conj_productes& conj_productes){
    redistribuir_rec(conj_productes,idcs);
}
void Conj_ciutats::redistribuir_rec(const Conj_productes& conj_productes,BinTree<string>& idcs){
    if(not (idcs.left().empty() and idcs.right().empty())) { 
        BinTree<string> esq = idcs.left();
        BinTree<string> dreta = idcs.right();
        comerciar(idcs.value(), esq.value(),conj_productes);
        comerciar(idcs.value(), dreta.value(),conj_productes);
        redistribuir_rec(conj_productes, esq);
        redistribuir_rec(conj_productes,dreta);
    }
}
int Conj_ciutats::hacer_viaje(Vaixell& v, const Conj_productes& conj_productes){ //const Conj_productes& conj_productes
    int profunditat_ultima;
    int profunditat_actual = 0;
    int comprades_actual = 0;
    int venudes_actual = 0;
    string ultima_ciutat;
    list<Informacio_Ciutat> cami;
    int suma_comprat_venut = buscar_ruta_max(idcs,v,profunditat_ultima,profunditat_actual,comprades_actual,venudes_actual,ultima_ciutat,cami);
    v.afegir_viaje(ultima_ciutat);
    viatge(cami,v);
    return suma_comprat_venut;
}
void Conj_ciutats::viatge(list<Informacio_Ciutat> &cami, Vaixell &v){
    list<Informacio_Ciutat>::iterator it = cami.begin();
    while (it != cami.end()){
        Informacio_Ciutat info = *it;
        map<string,Ciutat>::iterator itc = conj_ciutats.find(info.idc);
        itc->second.modificar_inventari(v.consultar_idp_comprar(),info.compra, info.venta);
        itc->second.modificar_inventari(v.consultar_idp_vendre(),info.compra, info.venta);
    }
}
int Conj_ciutats::buscar_ruta_max(const BinTree<string>& idcs, Vaixell& v,int& profunditat_ultima, int profunditat_actual, int comprades_actual, int venudes_actual,string& ultima_ciutat, list<Informacio_Ciutat>& cami){
    if (idcs.empty()) return 0;
    string idc = idcs.value(); 
    map<string,Ciutat>::iterator it = conj_ciutats.find(idc);
    profunditat_ultima = -1;
    int max_compra = v.consultar_quantitat_comprar()-comprades_actual;
    int max_venta = v.consultar_quantitat_vendre()-venudes_actual;
    pair<int,int> quantitats = it->second.productes_a_intercanviar(v.consultar_idp_comprar(), v.consultar_idp_vendre(),max_compra,max_venta);
    if(quantitats.first != 0 or quantitats.second != 0) {
        Informacio_Ciutat info;
        info.idc = idc;
        info.compra = quantitats.first;
        info.venta = quantitats.second;
        cami.push_back(info);
        profunditat_ultima = profunditat_actual;
        ultima_ciutat = idc;

    }

    if (not idcs.left().empty()) { 
        BinTree<string> left = idcs.left();
        BinTree<string> right = idcs.right();
        int prof_esq,prof_dre;
        string ultima_ciutat_esq, ultima_ciutat_dre;
        list<Informacio_Ciutat> cami_esq, cami_dre;
        //busquem ruta amb el fill esq
        int quantitat_esq = buscar_ruta_max(left, v, prof_esq, profunditat_actual+1,comprades_actual+quantitats.first,venudes_actual+quantitats.second,ultima_ciutat_esq,cami_esq);
        //busquem ruta amb el fill dret
        int quantitat_dre = buscar_ruta_max(right, v, prof_dre, profunditat_actual+1,comprades_actual+ quantitats.first,venudes_actual+quantitats.second,ultima_ciutat_dre,cami_dre);
        if(quantitat_esq == 0 and quantitat_dre == 0 and (quantitats.first + quantitats.second) != 0) {
            profunditat_ultima = profunditat_actual;
            ultima_ciutat = idc;
        }
        if (quantitat_dre > quantitat_esq) {
            //cas si ruta dreta ven i compra més que ruta esquerra
            cami = cami_dre;
            return quantitats.first + quantitats.second + quantitat_dre;
        }
        else if (quantitat_dre < quantitat_esq){
            //cas si la ruta esquerra compra i ven més que la dreta o venen la mateixa quantitat (retornem la ruta esq)
            cami = cami_esq;
            return quantitats.first + quantitats.second + quantitat_esq;
        
        }
        else if(prof_esq != -1 and prof_dre != -1){
            if(prof_esq <= prof_dre){
                cami = cami_esq;
                return quantitats.first + quantitats.second + quantitat_esq;
            }
            else{
                cami = cami_esq;
                return quantitats.first + quantitats.second + quantitat_esq;
            }
        }
        else if(prof_esq == -1 and prof_dre != -1){
            cami = cami_dre;
            return quantitats.first + quantitats.second + quantitat_dre;
        }
        
        else {
            cami = cami_esq;
            return quantitats.first + quantitats.second + quantitat_esq;
        }
    }
    return 0;
}

void Conj_ciutats::inicialitzar_ciutats(){
    inicialitzar_arbre(idcs);
}

void Conj_ciutats::afegir_ciutat(string idc){
    Ciutat ciutat;
    conj_ciutats.insert(make_pair(idc, ciutat));
}

void Conj_ciutats::borrar_ciutat(string idc){
    conj_ciutats.erase(idc);
}

bool Conj_ciutats::existeix_ciutat(string idc) const{
    map<string, Ciutat>::const_iterator it;
    it = conj_ciutats.find(idc);
    if (it == conj_ciutats.end()) return false;
    return true;
}

bool Conj_ciutats::existeix_producte_ciutat(string idc, int idp) const{
    map<string, Ciutat>::const_iterator it = conj_ciutats.find(idc);
    if (it->second.existeix_producte(idp)) return true;
    else return false;
}

void Conj_ciutats::leer_inventario(string idc, Conj_productes &conj_productes){
    map<string, Ciutat>::iterator it = conj_ciutats.find(idc);
    it->second.leer_inventario(conj_productes);

} 
    
void Conj_ciutats::leer_inventarios(Conj_productes &conj_productes){
    string idc;
    while (cin >> idc and idc != "#"){
        leer_inventario(idc, conj_productes);
    }

}

void Conj_ciutats::leer_rio(){
    //idcs = BinTree<int>();
    conj_ciutats.clear();
    inicialitzar_arbre(idcs);
}

void Conj_ciutats::escribir_ciudad(string idc){
    map<string, Ciutat>::iterator it;
    it = conj_ciutats.find(idc);
    it->second.escribir_ciudad();
}

void Conj_ciutats::inicialitzar_arbre(BinTree<string> &idcs){
    string idc;
    cin >> idc;
    if (idc != "#"){
            Ciutat c;
            conj_ciutats.insert(make_pair(idc, c));
            BinTree<string> esq,dret;
            inicialitzar_arbre(esq);
            inicialitzar_arbre(dret);
            idcs = BinTree<string> (idc, esq, dret);

    }
}

