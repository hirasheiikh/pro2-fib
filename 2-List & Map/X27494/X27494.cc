#include<iostream>
#include <list>
using namespace std;

int main(){
    list<double> l;
    int c;
    double n,min,max,suma,media;
    min = max = suma = media = 0;
    bool acabar = false;
    cin >> c >> n;
    while (not acabar){
        if (c == -1){
            if (l.empty()){
                l.insert(l.end(),n);
                min = max = media = n;
                cout << min << ' ' << max << ' ' << media << endl;
            }
            else{
                l.insert(l.end(),n);
                if (n < min) min = n;
                else if (n > max) max = n;

                list<double>::iterator it = l.begin();
                while (it != l.end()){
                    suma += *it;
                    ++it;
                }
                media = suma/l.size();
                cout << min << ' ' << max << ' ' << media << endl;
            }
        }
        else if (c == -2){
            list<double>::iterator it = l.begin();
            while (it != l.end()){
                if (*it == n) l.erase(it);
                else ++it;
            }
            if (not l.empty()){
                it = l.begin();
                while (it != l.end()){
                        suma += *it;
                        ++it;
                }
                media = suma/l.size();
                cout << min << ' ' << max << ' ' << media << endl;
            }
            else cout << 0 << endl;
        }
        else if (c == 0 and n == 0) acabar = true;
        cin >> c >> n;
    }
}