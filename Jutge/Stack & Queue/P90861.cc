#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string nom_io;
    cin.ignore();
    vector<queue<string>> cues(n);

    for (int i = 0; i < n; ++i){
        string line;
        getline(cin,line);
        stringstream ss(line);
        while (ss >> nom_io){
            cues[i].push(nom_io);
        }
    }
    string s;
    int num; 
    cout << "SORTIDES" << endl << "--------" << endl;
    while (cin >> s){
        if (s == "SURT"){
            cin >> num;
            if ((num >= 1 and num <= n) and not cues[num-1].empty()){
                cout << cues[num-1].front() << endl;
                cues[num-1].pop();
            }
        }
        else if (s == "ENTRA"){
            string nom;
            cin >> nom >> num;
            if (num >= 1 and num <= n) cues[num-1].push(nom);
        }
    }
    cout << endl << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
    for (int i = 1; i <= n; ++i){
        cout << "cua " << i << ':';
        while(not cues[i-1].empty()){
            cout << ' ' << cues[i-1].front();
            cues[i-1].pop();
        }
        cout << endl;
    }
}