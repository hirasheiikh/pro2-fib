#include "Barco.hh"


Barco:: Barco() {
    idvender = 0;
    idcomprar = 0;
    cantvender = 0;
    cantcomprar = 0;
    ciudadesvisitadas = vector<string>();
}

void Barco::modificar_barco (int idc, int cc, int idv, int cv) {
        idvender = idv;
        idcomprar = idc;
        cantvender = cv;
        cantcomprar = cc;
}
int Barco::get_idvender() {
    return idvender;
}
int Barco::get_idcomprar() {
    return idcomprar;
}
int Barco::get_cantcomprar() {
    return cantcomprar;
}
int Barco::get_cantvender() {
    return cantvender;
}
void Barco::modificar_cantcomprar(int c) {
    cantcomprar = c;
}
void Barco::modificar_cantvender(int c) {
    cantvender = c;
}
void Barco::escribir_barco() {
    cout << idcomprar << ' ' << cantcomprar << ' ' << idvender << ' ' << cantvender << endl;
    for (int i = 0; i < ciudadesvisitadas.size(); ++i) {
        cout << ciudadesvisitadas[i] << endl;
    }
}