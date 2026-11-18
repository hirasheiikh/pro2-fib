#include <iostream>
#include <set> 
#include <string>
#include <vector>
using namespace std;

int main() {
    set<string> noms;
    string nom;

    // Creamos el conjunto de todos los nombres
    while (cin >> nom and nom != ".") {
        noms.insert(nom);
    }

    // Leemos el número de actividades
    int n_act;
    cin >> n_act;

    // Creamos un vector para almacenar el conteo de participaciones
    vector<int> v(noms.size(), 0);

    for (int i = 0; i < n_act; ++i) {
        // Creamos un conjunto que se inicializará constantemente
        set<string> act;

        // Llenamos el conjunto con los nombres de la actividad i
        while (cin >> nom and nom != ".") {
            act.insert(nom);
        }

        // Iteramos sobre los nombres de noms y los comparamos con los de act
        for (const string& name : noms) {
            // Extraemos el número de actividad
            int num = 0;
            for (size_t j = 1; j < name.size(); ++j) {
                if (name[j] >= '0' and name[j] <= '9') {
                    num = num * 10 + (name[j] - '0');
                }
            }
            
            if (act.find(name) != act.end()) {
                ++v[num - 1];
            }
        }
    }

    // Mostramos los resultados
    cout << "Totes les activitats:";
    for (int i = 0; i < noms.size(); ++i) {
        if (v[i] == n_act) {
            cout << ' ' << 'a' << i + 1;
        }
    }
    cout << endl;

    cout << "Cap activitat:";
    for (int i = 0; i < noms.size(); ++i) {
        if (v[i] == 0) {
            cout << ' ' << 'a' << i + 1;
        }
    }
    cout << endl;

    return 0;
}
