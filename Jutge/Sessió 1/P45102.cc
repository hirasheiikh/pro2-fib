#include<iostream>
using namespace std;

int operacio(){
    char c,p,s;
    cin >> c;
    
    if (c == '('){
        int a = operacio();
        cin >> s;
        int b = operacio();
        cin >> p;
        if (s == '+') return a + b;
        else if (s == '-') return a - b;
        return a*b;
    }
    else return c - '0';
}

int main(){
    cout << operacio() << endl;
}