// Add or remove includes
#include <iostream>
#include <string>

using namespace std;

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j){
    for (int k = 0; k < s.size(); ++k){ //aloha 1 3
        if (k == i and i <= j and j >= i){ 
            char aux = s[j]; // aux = h
            s[j] = s[i]; // alola
            s[i] = aux; //ahola
            reverseSubstring(s, i + 1, j - 1);
        }
    }

}

// Adapt the call to 'function_name' and the way it is called to your case.
int main()  {
    string s;
    int i, j;
    while (cin >> s >> i >> j) {
        reverseSubstring(s, i, j);
        cout << s << endl;
    }
}
