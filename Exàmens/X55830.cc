#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string action;
    int x;
    int result = 0;
    map<int,int> m;

    while(cin >> action){
        if (action == "add"){
            cin >> x;
            ++m[x];
            result += x;
        }
        else if (action == "occurrences") {
            cin >> x;
            if (m.find(x) != m.end()) cout << m[x] << endl;
            else cout << 0 << endl;
        }
        else if (m.empty()) cout << 0 << endl;
        else if (action == "max") cout << m.rbegin()->first << endl;
        else if (action == "min") cout << m.begin()->first << endl;
        else if (action == "sum") cout << result << endl;
        else {
            cin >> x;
            if (m[x] > 1) --m[x];
            else m.erase(x);
            result -= x;
        }
        
    }

}