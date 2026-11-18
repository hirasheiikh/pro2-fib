#include <iostream>
#include <queue>
#include <sstream> // serveix per inserir/extreure contingut d'un string com si ho fessim amb un cin o un cout
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string nom_io;
    cin.ignore();

    vector<queue<string>>cues(n); //vector de cues d'strings (n és el nombre de cues = tamany del vector)

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
            int cua;
            cin >> cua;
            if ((cua >= 1 and cua <= n) and (!cues[cua - 1].empty())){
                cout << cues[cua - 1].front() << endl;
                cues[cua-1].pop();
            }
        }
        else if (nom_io == "ENTRA"){
            string nom;
            int cua;
            cin >> nom >> cua;
            if (cua >= 1 and cua <= n) cues[cua - 1].push(nom);
        }
    }
    cout << endl << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    for (int i = 1; i <= n; ++i){
        cout << "cua " << i << ':';
        while (!cues[i-1].empty()){
            cout << ' ' << cues[i-1].front();
            cues[i - 1].pop();
        }
        cout << endl;
    }

}
