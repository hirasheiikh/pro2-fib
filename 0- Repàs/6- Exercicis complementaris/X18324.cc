#include <stack>
#include <iostream>
#include <sstream>
using namespace std;

/*
int main(){

    string expr;
    while(cin >> expr){
        stack<char> p;
        int pos = 0;
        int contador = 0;
        bool correcte = true;
        while(pos < expr.size() and correcte){
            if(expr[pos] == '(' or expr[pos] == '['){
                p.push(expr[pos]);
            }
            else{
                if(p.empty()) correcte = false;
                else if(expr[pos] == ')' and p.top() != '(') correcte = false;
                else if(expr[pos] == ']' and p.top() != '[') correcte = false;
                else{
                    p.pop();
                    contador += 2;
                }
            }
            ++pos;
        }
        cout << contador << endl; 
    }
}*/

int main(){
	string s;
	while(cin >> s){
		stack<char> p;
		int res = 0;
		int i = 0;
		bool correcto = true;
		while(i < s.length() and correcto){
			if(s[i] == '(' or s[i] == '[') {
                if(p.empty()) res = i;
                p.push(s[i]);
            }
			else {
				if(not p.empty()){
					if(s[i] == ')' and p.top() == '(') p.pop();
					else if(s[i] == ']' and p.top() == '[') p.pop();
                    else correcto = false;
				}
				else {
					correcto = false;
					res = i;
				}
			}
			++i;
		}
		// ([])([][]
		if(correcto and p.empty()) res = s.length();
		cout << res << endl;
	}
}
