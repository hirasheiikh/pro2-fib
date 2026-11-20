#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <stack<string>> biblio(n);
    int op;
    string llibre;
    int estante, llib_retirar;
    cin >> op;
    while (op != -4){
        if (op == -1){
            cin >> llibre >> estante;
            biblio[estante - 1].push(llibre);
        }
        else if (op == -2){
            cin >> llib_retirar >> estante;
            for (int i = 0; i < llib_retirar; ++i) biblio[estante - 1].pop();   
        }
        else if (op == -3) {
            cin >> estante;
            stack<string> s = biblio[estante - 1];
            cout << "Pila de la categoria " << estante << endl;
            while(not s.empty()){
                cout << s.top() << endl;
                s.pop();
            }
            cout << endl;
        }
        cin >> op;
    }
}