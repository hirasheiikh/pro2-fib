#include <string>
#include <list>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    while (cin >> s){
        int count = 0;
        stack<char> p;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '(' or s[i] == '[') p.push(s[i]);
            else{
                if (not p.empty()){
                    if ((s[i] == ')' and p.top() != '(') or (s[i] == ']' and p.top() != '[')) ++count;
                    p.pop();
                }
            }
        }
        cout << count << endl;
    }
}
