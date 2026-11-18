#include <map>
#include <list>
#include <iostream>
using namespace std;

void freq (map<string,int> m){
    char c;
    string s;
    while (cin >> c >> s){
        if (c == 'a'){
            map<string,int>::iterator it = m.find(s);
            if (it != m.end()) (*it).second = (*it).second + 1;
            else m.insert(make_pair(s,1));
        }
        else if (c == 'f'){
            map<string,int>::iterator it = m.find(s);
            if (it != m.end()) cout << (*it).second << endl;
            else cout << 0 << endl;
        }
    }
}
int main(){
    map<string,int> m;
    freq(m);
}