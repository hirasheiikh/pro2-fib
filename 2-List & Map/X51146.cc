#include <iostream>
#include <set>
using namespace std;

int main(){
    set<string> lista_todas;
    set<string> cap_act;
    string nom;
    cin >> nom;

    while (nom != "."){
        lista_todas.insert(nom);
        cin >> nom;
    }
    cap_act = lista_todas;
    int n; // num acts
    cin >> n;
    for (int i = 0; i < n; ++i){
        set<string> participantes = lista_todas;
        while (cin >> nom and nom != "."){
            participantes.erase(nom);
            cap_act.erase(nom);
        }
        set<string>::iterator it = participantes.begin();
        while (it != participantes.end()){
            lista_todas.erase(*it);
            ++it;
        }
    }
    cout << "Totes les activitats:";
    set<string>::iterator it = lista_todas.begin();
    while (it != lista_todas.end()){
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    cout << "Cap activitat:";
    it = cap_act.begin();
    while(it != cap_act.end()){
        cout << ' ' << *it;
        ++it;
    }
    cout << endl;
}