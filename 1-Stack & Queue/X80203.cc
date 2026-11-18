#include <iostream>
#include <stack>
#include  <string>
using namespace std;

int main(){
    string s;
    stack<int> pila;
    
    while(cin >> s){
        int count = 1;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '('){
                pila.push(count);
                cout << s[i] << pila.top();
                ++count;
            }
            else if (s[i] == ')'){
                cout << s[i] << pila.top();
                pila.pop();
            }
        }
        cout << endl;


    }
}