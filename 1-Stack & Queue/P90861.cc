#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin.ignore();

    vector<queue<string>>cues(n);

    for (int i = 0; i < n; ++i){
        string line;
        getline(cin,line);
        stringstream ss(line);
        while (ss >> x){
            cues[i].push(x);
        }
    }
    cout  << "SORTIDES" << endl << "--------" << endl;
    while (cin >> x){
        if (x == "SURT"){
            int cua;
            cin >> cua;
            if ((cua >= 1 and cua <= n) and (!cues[cua - 1].empty())){
                cout << cues[cua-1].front() << endl;
                cues[cua-1].pop();
            }
        }
        else if (x == "ENTRA"){
            string nom;
            int cua;
            cin >> nom >> cua;
            if (cua >= 1 and cua <= n) cues[cua-1].push(nom);
        }
    }
    cout << endl << "CONTINGUTS FINALS"  << endl << "-----------------" << endl;
    for (int i = 1; i <= n; ++i){
        cout << "cua " << i << ':';
        while (!cues[i-1].empty()){
            cout << ' ' << cues[i-1].front();
            cues[i-1].pop();
        }
        cout << endl;
    }

}