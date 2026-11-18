#include "Funciones.hh"


BinTree<string>leer_rio(map<string,Ciudad>& cities){
    string s;
    cin >> s;
    if (s == "#") return BinTree<string>();
    cities.insert(make_pair(s, Ciudad()));
    return BinTree<string>(s, leer_rio(cities),leer_rio(cities));
}


bool existeciudad(string id, map<string,Ciudad>& cities) {
    map<string,Ciudad>:: iterator it = cities.begin();
    it = cities.find(id);
    return (it != cities.end());
}

void comerciar(string id1, string id2, map<string,Ciudad>& cities, map<int,caracteristicas>& m) {
    map<int,inventario> c1 = cities[id1].get_inventario();
    map<int,inventario> c2 = cities[id2].get_inventario();
    map<int,inventario>::iterator itc1 = c1.begin();
    map<int,inventario>::iterator itc2 = c2.begin();
    while (itc1 != c1.end() and itc2 != c2.end()) { 
        if (itc1->first < itc2->first) {
            // El producto itc1->first está ausente en c2
            ++itc1;
        } else if (itc1->first > itc2->first) {
            // El producto itc2->first está ausente en c1
            ++itc2;
        }
        else {
          int sobra1 = (itc1->second.tienes)-(itc1->second.necesito);
          int sobra2 = (itc2->second.tienes)-(itc2->second.necesito);
          if(sobra1 < 0 and sobra2 > 0) {
            cities[id1].modificar_prod(itc1->first, itc1->second.necesito, (itc1->second.tienes + sobra2),m,false);
            cities[id2].modificar_prod(itc2->first, itc2->second.necesito, (itc2->second.tienes - sobra2),m,false);
          }
          else if (sobra2 < 0 and sobra1 > 0) {
            cities[id1].modificar_prod(itc1->first, itc1->second.necesito, (itc1->second.tienes - sobra1),m,false);
            cities[id2].modificar_prod(itc2->first, itc2->second.necesito, (itc2->second.tienes + sobra1),m,false);
          }
          itc1++;
          itc2++;
        }
    }
}
void redistribuir(map<string,Ciudad>& cities, map<int,caracteristicas>& m, BinTree<string>& rio) {
    if(not (rio.left().empty() and rio.right().empty())) { 
        BinTree<string> left = rio.left();
        BinTree<string> right = rio.right();
        comerciar(rio.value(), left.value(),cities,m);
        comerciar(rio.value(), right.value(),cities,m);
        redistribuir(cities, m, left);
        redistribuir(cities, m,right);
    }
    else if (not rio.left().empty() and rio.right().empty()) {
        BinTree<string> left = rio.left();
        comerciar(rio.value(), left.value(),cities,m);
        redistribuir(cities, m, left);
    }
    else if (rio.left().empty() and not rio.right().empty()) {
        BinTree<string> right = rio.right();
        comerciar(rio.value(), right.value(),cities,m);
        redistribuir(cities, m, right);
    }
}
void hacer_viaje(map<string,Ciudad>& cities, BinTree<string>& rio, Barco& barco) {
    queue<string> recorrido;
    int n = buscar_max(recorrido,cities,rio,barco);
    cout << n << endl;
    while (recorrido.size() != 1) {
        string c = recorrido.front();
        if (barco.get_cantcomprar() > 0 and (cities[c].get_inventario()[barco.get_idvender()].tienes - cities[c].get_inventario()[barco.get_idvender()].necesito)>0 and ((cities[c].get_inventario().tienes-invcomprar.necesito)<=0 or barco.get_cantvender() <=0)) {
        n= invvender.tienes-invvender.necesito;
    }
    if (barco.get_cantvender() > 0 and (invcomprar.tienes-invcomprar.necesito)>0 and ((invvender.tienes-invvender.necesito)<=0 or barco.get_cantcomprar() <=0)) {
        n= invcomprar.tienes-invcomprar.necesito;
    }
    if (barco.get_cantvender() > 0 and barco.get_cantcomprar() > 0 and (invvender.tienes-invvender.necesito)>0 and (invcomprar.tienes-invcomprar.necesito)>0) {
        n= invvender.tienes-invvender.necesito + invcomprar.tienes-invcomprar.necesito;
    }
    }
}

int buscar_max(queue<string>& recorrido,map<string,Ciudad>& cities, BinTree<string>& rio, Barco& barco) {
    if(rio.empty()) return 0;
    int n= cosasaintercambiar(cities[rio.value()].get_inventario()[barco.get_idcomprar()], cities[rio.value()].get_inventario()[barco.get_idvender()], barco);
    int nizq = -1, nder=-1;
    if(not rio.left().empty()) { 
        BinTree<string> left = rio.left();
        nizq =buscar_max(recorrido, cities, left, barco);
    }
    if (not rio.right().empty()) {
        BinTree<string> right = rio.right();
        nder = buscar_max(recorrido, cities, right, barco);
    }
    
    if (nder > nizq) {
        recorrido.push(rio.right().value());
        return n+nder;
    }
    if (nizq > -1 and not (rio.left().empty())) recorrido.push(rio.left().value());
    return n + nizq;
}


int cosasaintercambiar(inventario& invcomprar, inventario& invvender, Barco& barco) {
    int n = 0;
    if (barco.get_cantcomprar() > 0 and (invvender.tienes-invvender.necesito)>0 and ((invcomprar.tienes-invcomprar.necesito)<=0 or barco.get_cantvender() <=0)) {
        n= invvender.tienes-invvender.necesito;
    }
    if (barco.get_cantvender() > 0 and (invcomprar.tienes-invcomprar.necesito)>0 and ((invvender.tienes-invvender.necesito)<=0 or barco.get_cantcomprar() <=0)) {
        n= invcomprar.tienes-invcomprar.necesito;
    }
    if (barco.get_cantvender() > 0 and barco.get_cantcomprar() > 0 and (invvender.tienes-invvender.necesito)>0 and (invcomprar.tienes-invcomprar.necesito)>0) {
        n= invvender.tienes-invvender.necesito + invcomprar.tienes-invcomprar.necesito;
    }
    return n;
}








/*
Ciudad busquedaciudad(BinTree<Ciudad>& rio, string id) { //NO SE SI AL PASAR POR REFERENCIA EL BINTREE PORQUE NO PUEDO HACER EL DE LA IZQUIERDA O EL DE LA DERECHA
    if (rio.empty()) return Ciudad();
    Ciudad c = rio.value();
    if (not (c.get_id() == id)) {
        BinTree<Ciudad> left = rio.left();
        c = busquedaciudad(left, id);
        if (c.get_id() != id) {
            BinTree<Ciudad> right = rio.right();
            c = busquedaciudad(right, id);
        }
    }
    return c;
 }
 */
