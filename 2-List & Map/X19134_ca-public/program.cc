#include <iostream>
#include "LlistaIOParInt.hh"

int main() {
    list<ParInt> l;
    LlegirLlistaParInt(l);
    int n,count,sum;
    count = sum = 0;
    cin >> n;
    list<ParInt>::iterator it = l.begin();
    while (it != l.end()) {
        if (it->primer() == n) {
            ++count;
            sum += it->segon(); //(*it).segon();
        }
        ++it;
    }
    cout << n << " " << count << " " << sum << endl; 
}