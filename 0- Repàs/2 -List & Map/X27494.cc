#include <iostream>
#include <list>
using namespace std;


int recalculate(const list<int>& l,int e){
    int num = *l.begin();
    for (list<int>::const_iterator it = ++l.begin(); it != l.end(); ++it) if ((*it)*e > num*e) num = *it;
    return num;
}

int main(){
    int c,n,min,max;
    min = max = 0;
    double suma = 0;
    cin >> c >> n;
    list<int> l;
    while (c != 0){
        if (c == -1){
            if (l.empty()){
                l.insert(l.end(), n);
                min = max = suma = n;
            }
            else{
                l.insert(l.end(), n);
                if (n < min) min = n;
                if (n > max) max = n;
                suma += n;
            }
        }
        else if (c == -2){
            list<int>::iterator it = l.begin();
            while (it != l.end() and *it != n) ++it;
            if (it != l.end()){
                l.erase(it);
                suma -= n;
            }
            if (not l.empty()){
                if (n == max) max = recalculate(l, 1);
                if (n == min) min = recalculate(l, -1);
            }
        }
        if (l.empty()) cout << 0 << endl;
        else cout << min << ' ' << max << ' ' << suma/l.size() << endl;
        cin >> c >> n;
    }
}

