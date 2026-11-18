#include <iostream> 
#include <stack>
#include <vector>
#include <string>
using namespace std;

// n piles/categories
void treure_llibres(stack<string>& p, int q){
    for (int i = 0; i < q; ++i){
        p.pop();
    }
}

void escriure_llibres(stack<string> p, int idc){
    cout << "Pila de la categoria " << idc << endl;
    while (not p.empty()){
        cout << p.top() << endl;
        p.pop();
    }
    cout << endl;
}
int main(){
    int ncat;
    cin >> ncat;
    vector<stack<string>> v(ncat);
    int op;
    cin >> op;
    while (op != -4){
        if (op == -1){
            string nom;
            int idc;
            cin >> nom >> idc;
            v[idc-1].push(nom);

        }
        else if (op == -2){
            int q, idc;
            cin >> q >> idc;
            treure_llibres(v[idc-1],q);
        }
        else if (op == -3){
            int idc;
            cin >> idc;
            escriure_llibres(v[idc-1],idc);
        }
        cin >> op;
    }

}