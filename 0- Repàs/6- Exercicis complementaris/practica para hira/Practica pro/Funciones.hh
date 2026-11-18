#include<iostream>
#include"BinTree.hh"
#include"Ciudad.hh"
#include<string>
#include<queue>
using namespace std;
 

BinTree<string> leer_rio(map<string,Ciudad>& cities);
bool existeciudad (string id, map<string,Ciudad>& cities);
void comerciar(string id1, string id2, map<string,Ciudad>& cities, map<int,caracteristicas>& m);
void redistribuir(map<string,Ciudad>& cities, map<int,caracteristicas>& m, BinTree<string>& rio);
void hacer_viaje(map<string,Ciudad>& cities, BinTree<string>& rio, Barco& barco);
int buscar_max(queue<string>& recorrido,map<string,Ciudad>& cities, BinTree<string>& rio, Barco& barco);
int cosasaintercambiar(inventario& invcomprar, inventario& invvender, Barco& barco);
 //Ciudad busquedaciudad(BinTree<Ciudad>& rio, string id) ;