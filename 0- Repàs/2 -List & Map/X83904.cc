#include <iostream>
#include <set>
using namespace std;

int main(){
    set<string> jugadors;
    string jugador;
    cin >> jugador;
    while (jugador != "."){
        jugadors.insert(jugador);
        cin >> jugador;
    }
    int nact;
    cin >> nact;
    set<string> totes = jugadors;
    set<string> cap = jugadors;
    for (int i = 0; i < nact; ++i){
        set<string> act;
        cin >> jugador;
        while (jugador != "."){
            act.insert(jugador);
            cin >> jugador;
        }
        set<string>::iterator it = jugadors.begin();
        while (it != jugadors.end()){
            if (act.find(*it) != act.end()) cap.erase(*it) ;
            else if (act.find(*it) == act.end()) totes.erase(*it);
            ++it;
        }
    }
    cout << "Totes les activitats:";
    set<string>::iterator it1 = totes.begin();
    while (it1 != totes.end()){
        cout << ' ' << *it1;
        ++it1;
    } 
    cout << endl << "Cap activitat:";
    set<string>::iterator it2 = cap.begin();
    while (it2 != cap.end()){
        cout << ' ' << *it2;
        ++it2;
    }
    cout << endl;
}