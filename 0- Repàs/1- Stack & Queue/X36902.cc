#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    char c;
    cin >> c;
    int count = 1;
    bool mistake = false;
    while (not mistake and c != '.'){
        if (c == '('){
            s.push(1);
        }
        else if (c == '['){
            s.push(2);
        }
        else if (c == ']'){
            if (not s.empty() and s.top() == 2) s.pop();
            else{
                cout << "Incorrecte " << count << endl;
                mistake = true;
            }
        }
        else {
            if (not s.empty() and s.top() == 1) s.pop();
            else{
                cout << "Incorrecte " << count << endl;
                mistake = true;
            }
        }
        cin >> c;
        ++count;
    }
    if (s.empty() and not mistake) cout << "Correcte" << endl;
    else if (not s.empty() and not mistake) cout << "Incorrecte " << count - 1 << endl;
}