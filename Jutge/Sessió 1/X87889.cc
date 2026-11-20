#include <iostream>
using namespace std;

// Pre: n >= 1
// Post: Retorna 1-2+3-4+...+(-1)^(n+1)*n
int simpleAlternatedSum(int n) {
    if (n%2 == 0 and n != 0) return simpleAlternatedSum(n-1)-n;
    else if(n%2 != 0 and n != 0) return simpleAlternatedSum(n-1)+n;
    else return 0;
}

// Adapt the call to 'function_name' and the way it is called to your case.
int main()  {
    int n;
    while (cin >> n)
        cout << simpleAlternatedSum(n) << endl;
}
