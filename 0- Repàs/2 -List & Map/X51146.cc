#include<set>
#include<iostream>
using namespace std;

int main(){
    set<string> llista_totes;
    set<string> llista_cap;
    string nom;
    cin >> nom;
    while (nom != "."){
        llista_totes.insert(nom);
        cin >> nom;
    }
    llista_cap = llista_totes;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        set<string>  participants = llista_totes;
        while (cin >> nom and nom != "."){
            participants.erase(nom);
            llista_cap.erase(nom);
        }
        set<string>::iterator it = participants.begin();
        while (it != participants.end()){
            llista_totes.erase(*it);
            ++it;
        }
    }
    cout << "Totes les activitats:";
    set<string>::iterator it = llista_totes.begin();
    while (it != llista_totes.end()){
        cout << " " << *it;
        ++it;
    }
    cout << endl;
    cout << "Cap activitat:";
    it = llista_cap.begin();
    while(it != llista_cap.end()){
        cout << ' ' << *it;
        ++it;
    }
    cout << endl;
}