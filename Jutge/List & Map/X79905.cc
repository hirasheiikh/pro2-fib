#include <map>
#include <iostream>
using namespace std;

int main(){
    map<string,int> m;
    char c;
    string s;
    while (cin >> c >> s){
        if (c == 'a') ++m[s];
        else if (c == 'f') cout << m[s] << endl;
        else{
            if (m[s] > 0) --m[s];
        }
    }

}