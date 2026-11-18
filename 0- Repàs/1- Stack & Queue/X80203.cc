#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    stack<int> p;
    while (cin >> s){
        int count = 1;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '('){
                p.push(count);
                cout << "(" << count;
                ++count;
            }
            else if (s[i] == ')'){
                cout << ")" << p.top();
                p.pop(); 
            }
        }
        cout << endl;
    }
}