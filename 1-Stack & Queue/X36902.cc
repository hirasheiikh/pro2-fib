#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;
    int count = 1;
    char c;
    cin >> c;
    bool mistake = false;

    while (not mistake and c != '.'){
        if (c == '(') s.push(1);
        else if (c == '[') s.push(2);
        else if (c == ')'){
            if (!s.empty() and s.top() == 1) s.pop();
            else{
                cout << "Incorrecte " << count << endl;
                mistake = true;
            }
        }
        else if (c == ']'){
            if (!s.empty() and s.top() == 2) s.pop();
            else{
                cout << "Incorrecte " << count << endl;
                mistake = true;
            }
        }
        cin >> c;
        ++count;
    }
    if (not mistake and s.empty()) cout << "Correcte" << endl; // quan la pila quedi buida i tots els parèntesis tanquen.
    else if (not s.empty() and not mistake) cout << "Incorrecte " << count - 1 << endl; // quan queda un parèntesis obert

}