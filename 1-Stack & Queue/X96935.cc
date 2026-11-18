#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    stack<int> p;

    for (int i = 0; i < n/2; ++i){
        cin >> x;
        p.push(x);
    }

    if (n%2 != 0) cin >> x;
    bool palindrome = true;
    while (palindrome and not p.empty()) {
        cin >> x;
        if (x != p.top()) palindrome = false;
        p.pop();
    }
    if (palindrome) cout << "SI" << endl;
    else cout << "NO" << endl;
}