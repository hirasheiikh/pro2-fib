#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string nom_io;
    cin.ignore();
    vector<queue<string>>cues(n);

    for (int i = 0; i < n; ++i){
        string line;
        getline(cin,line); // nos permite obtener múltiples caracteres de la entrada del usuario.
        stringstream ss(line);
        while(ss >> nom_io){ // anem fent cin dels noms per omplir la línia
            cues[i].push(nom_io); //omplim cua
        }
    }
    cout << "SORTIDES" << endl << "--------" << endl;
    while (cin >> nom_io){
        if (nom_io == "SURT"){
            int m;
            cin >> m;
            if ((m >= 1 and m <= n) and (not cues[m - 1].empty())){
                cout << cues[m - 1].front() << endl;
                cues[m - 1].pop();
            }
        }   
        else if (nom_io == "ENTRA"){
            string nom; 
            cin >> nom;
            int m;
            cin >> m;
            if (m >= 1 and m <= n) cues[m - 1].push(nom);
        }
    }

    cout << endl << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    for (int i = 1; i <= n; ++i){
        cout << "cua " << i << ':';
        while (not cues[i - 1].empty()){
            cout << ' ' << cues[i - 1].front();
            cues[i - 1].pop();
        }
        cout << endl;
    }
}
    