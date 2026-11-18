#include <iostream>
#include <list>
#include <map>
using namespace std;

int main(){
    map<string,int> matches;
    char c;
    string s;
    while (cin >> c >> s){
        if (c == 'a') ++matches[s];
        else cout << matches[s] << endl;
    }
}