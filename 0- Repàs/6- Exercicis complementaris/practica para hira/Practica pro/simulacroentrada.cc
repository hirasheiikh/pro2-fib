#include "Funciones.hh"
#include <iostream>
#include "BinTree"
#include <set>
using namespace std;

 BinTree<string> leer_rio (set<string>& cities){
    string s;
    cin >> s;
    if (s == "#") return BinTree<string>();
    else {
        cities.insert(s);
        return BinTree<string>(c, leer_rio(cities),leer_rio(cities));
    }
 }
int main(){
int n; 
cin >> n;
set<string> cities;
BinTree<string> prueba= leer_rio(cities);
cout << prueba << endl;

}