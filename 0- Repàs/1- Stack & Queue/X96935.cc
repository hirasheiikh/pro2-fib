#include <stack>
#include <iostream>
using namespace std;

int main(){
    int n, x; // 4 
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n/2; ++i){
        cin >> x; // 20 10
        s.push(x);
    }
    if (n%2 != 0) cin >> x;
    bool palindrom = true;
    while (palindrom and not s.empty()){
        cin >> x; // 20
        if (x != s.top()) palindrom = false;
        s.pop(); // 10
    } 
    if (palindrom) cout << "SI" << endl;
    else cout << "NO" << endl;

}