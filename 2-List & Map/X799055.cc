#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string,int> m;
    char c;
    string s;
    while (cin >> c >> s){
        map<string, int>::const_iterator it = m.find(s);
        if (c == 'f'){
            if (it == m.end()) cout << 0 << endl;
            else cout << (*it).second << endl;
        }
        else if (c == 'e'){
            if (it != m.end()){
                if ((*it).second == 1) m.erase(it);
                else m[s] = (*it).second - 1;
            }
        }
        else if (c == 'a'){
            if (it == m.end()) m.insert(make_pair(s,1));
            else m[s] = (*it).second + 1;
        }
    }
}