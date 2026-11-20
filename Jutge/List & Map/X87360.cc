#include <iostream>
#include <list>
using namespace std;

/* Pre: uno = U */
 /* Post: uno pasa a ser la interseccion de U y dos */
void inter(list<int>& uno, const list<int>& dos){
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();
    while (it1 != uno.end()){
        if (it2 == dos.end() or *it1 < *it2) it1 = uno.erase(it1);
        else if (*it1 == *it2){
            ++it1;
            ++it2;
        }
        else ++it2;
    }
}
void llegir(list<int>& l){
    int n, x;
    cin >> n; // tamany llista
    for (int i = 0; i < n; ++i){
        cin >> x;
        l.insert(l.end(),x);
    }
}
void escriure(const list<int>& l){
    list<int>::const_iterator it = l.begin();
    while (it != l.end()){
        cout << *it << ' ';
        ++it;
    }
    cout << endl;
}


/*
int main(){
    list<int> l1,l2;
    llegir(l1);
    llegir(l2);
    inter(l1, l2);
    cout << "INTERSECCIO: ";
    escriure(l1);
}
*/