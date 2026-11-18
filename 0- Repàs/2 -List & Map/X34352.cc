#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string,int> out;
    char c;
    string nom;
    while (cin >> c >> nom){
        if (c == 'a') ++out[nom];
        else cout << out[nom] << endl;
    }
}