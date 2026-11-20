#include <vector>
#include "Estudiant.hh"
#include <iostream>
using namespace std;


int main(){
    int M,N,S;
    cin >> M >> N >> S;
    vector<bool> seleccionades(N,false);
    int x;
    for (int i = 0; i < S; ++i){
        cin >> x;
        seleccionades[x-1] = true;
    }
    int dni;
    double nota;
    for (int i = 0; i < M; ++i){
        double suma = 0;
        cin >> dni;
        for (int j = 0; j < N; ++j){
            cin >> nota;
            if (seleccionades[j]){
                suma += nota;
            }
        }
        Estudiant e(dni);
        double mitjana = suma/double(S);
        e.afegir_nota(mitjana);
        e.escriure();
    }

}