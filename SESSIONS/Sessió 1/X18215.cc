#include <iostream>
#include <vector>
#include <string>
using namespace std;

void borrar_n(vector<char>& v2, int n){
    while (n > 0){
        v2.pop_back(); //v2: v= // v2: v // v2.size() = 1 // Li(n)v, v2.size() = 6;
        --n;
    }
}
int main(){
    string s;
    while(cin >> s){ // v=n;i(n)v=n;i((n)*n)v=n;i(n)v=n;ev=n;v=n;
        vector<char> v2; //Lv=n;
        int i = 0;
        while (i < s.size()){ 
            bool acabar  = false;
            v2.push_back(s[i]);  // v2: v=n; // i = 2 // v2: Li(n)v=n; // i = 11
            while (not acabar and i < s.size()){ //bool
                acabar = false;
                /*cout << "while: ";
                for (int i = 0; i < v2.size(); ++i) cout << v2[i];
                cout << endl;*/
                int j = v2.size() - 1; /// j = 2 // j = 7
                if (v2[j] == 'n' or (v2[j] == 'v' and (i == s.size()-1 or s[i + 1] != '='))) {
                    v2[j] = 'E'; // v2[2] == n --> v2[2] == E, v2: v=E // Li(n)v=E
                }
                else if(j-3 >= 0 and v2[j] == ';' and v2[j-1] == 'E' and v2[j-2] == '=' and v2[j-3] == 'v'){
                    //v=E; -> I
                    borrar_n(v2,3);
                    v2[j-3] = 'I';
                }
                else if (v2[j] == 'E'){
                    if (j-2 >= 0 and v2[j - 1] == '*' and v2[j - 2] == 'E'){
                        //E*E -> E
                        borrar_n(v2,2);
                    }
                    else if (j-2 >= 0 and v2[j - 1] == '+' and v2[j - 2] == 'E' and (i == s.size()-1 or s[i+1] != '*')){
                        //E+E -> E
                        borrar_n(v2,2);
                    }
                    else if (j-2 >= 0 and v2[j - 1] == '<' and v2[j - 2] == 'E' and (i == s.size()-1 or (s[i+1] != '*' and s[i+1] != '+'))){
                        //E<E -> E
                        borrar_n(v2,2);
                    }
                    else acabar = true;
                    
                }
                else if(j-3 >= 0 and v2[j] == ')' and v2[j-1] == 'E' and v2[j-2] == '(' and v2[j-3] != 'i' and v2[j-3] != 'w'){
                    //(E) -> E
                    borrar_n(v2,2);
                    v2[j-2] = 'E';
                }
                //!!!!!!!!!!!!!!!!!!!!
                else if (v2[j] == 'I'){  //v[5] == 'I' --> Li(n)I
                    if (j-4 >= 0 and v2[j - 1] == ')' and v2[j - 2] == 'E' and v2[j - 3] == '(' and v2[j - 4] == 'i' and (i == s.size()-1 or (s[i+1] != 'e'))){
                        //i(E)I -> I
                        borrar_n(v2,4);
                        v2[j-4] = 'I';
                    }
                    else if (j-6 >= 0 and v2[j - 1] == 'e' and v2[j - 2] == 'I' and v2[j - 3] == ')' and v2[j - 4] == 'E' and v2[j - 5] == '(' and v2[j - 6] == 'i'){
                        //i(E)IeI -> I
                        borrar_n(v2,6);
                        v2[j-6] = 'I';
                    }
                    else if (j-4 >= 0 and v2[j - 1] == ')' and v2[j - 2] == 'E' and v2[j - 3] == '(' and v2[j - 4] == 'w'){
                        //w(E)I -> I
                        borrar_n(v2,4);
                        v2[j-4] = 'I';
    
                    }
                    else if (j-1 >= 0 and v2[j - 1] == 'L'){
                        v2.pop_back(); // queda la L només
                    }
                    else if ( j == 0 or (v2[j - 1] != ')' and v2[j - 1] != 'L')){
                        v2[j] = 'L';  //v2[0] == L // v2: L

                    } 
                    else acabar = true;
                }
                else if (j-2 >= 0 and v2[j] == '}' and v2[j - 1] == 'L' and v2[j - 2] == '{'){
                    //{L}->I 
                    borrar_n(v2,2);
                    v2[j-2] = 'I';
                }
                else if (v2.size() == 1 and v2[0] == 'L' and i == s.size() - 1) v2[j] = 'P'; // nada
                else acabar = true;
                j = v2.size() - 1;

            }
            ++i;// i = 4 // 12
        } 
        for (int i = 0; i < v2.size(); ++i) cout << v2[i];
        cout << endl;
    }
}