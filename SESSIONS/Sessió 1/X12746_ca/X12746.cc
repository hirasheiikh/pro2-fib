#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int tam = 0;
    int ninfront = 0;
    string command;
    map<int, int> m;
    map<int, int>::iterator it;

    while (cin >> command) {
        if (command == "v.push_back(") {
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ");"
            m.insert(make_pair(tam - ninfront, val));
            ++tam;
        } 
        else if (command == "v.push_front(") {
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ");"
            ++ninfront;
            m.insert(make_pair(-ninfront, val));
            ++tam;
        } 
        else if (command == "v.pop_front();") {
            int posm = - ninfront;
            it = m.find(posm);
            if (it != m.end())
                m.erase(it);
            --ninfront;
            --tam;
        } 
        else if (command == "v.pop_back();") {
            int posv = tam - 1;
            int posm = posv - ninfront;
            it = m.find(posm);
            if (it != m.end())
                m.erase(it);
            --tam;
        }
        else if (command == "v.resize(") {
            int newsize;
            cin >> newsize;
            string ending;
            cin >> ending; // Això consumeix el ");"
            if (newsize > tam) {
                tam = newsize;
            } else {
                if(not m.empty()){
                    it = m.end();
                    --it;
                    int last = newsize - 1 - ninfront;
                    while (it != m.begin() and it->first > last) {
                        it = m.erase(it);
                        --it;
                    }
                    if(it == m.begin() and it->first > last) m.erase(it);
                }
                tam = newsize;
            } 
        }
        else if (command == "cout<<v[") {
            int index;
            cin >> index;
            string ending;
            cin >> ending; // Això consumeix el "];"
            int posm = index - ninfront;
            it = m.find(posm);
            if (it != m.end()) cout << it->second;
            else cout << 0;
            cout << endl;
        } 
        else if (command == "cout<<v;") {
            it = m.begin();
            for (int i = 0; i < tam; ++i){
                int pos = i - ninfront;
                map<int,int>::iterator it = m.find(pos);
                if (it != m.end()){
                    if (i > 0) cout << ',' << it-> second;
                    else cout << it-> second;
                }
                else if (i > 0) cout << ',' << 0;
                else cout << 0;
            }
            cout << endl;
        } 
        else if (command == "v[") {
            int index;
            cin >> index;
            string mid;
            cin >> mid; // Això consumeix el "]="
            int val;
            cin >> val;
            string ending;
            cin >> ending; // Això consumeix el ";"
            int posm = index - ninfront;
            it = m.find(posm);
            if (it != m.end())
                it->second = val;
            else 
                m.insert(make_pair(posm,val));
        } 
        else if (command == "//") {
            string comment;
            getline(cin, comment);
            cout << "//" << comment << endl;
        } 
        else {
            cout << "Wrong command '" << command << "'" << endl;
            string discard;
            getline(cin, discard);
        }
    }
}
