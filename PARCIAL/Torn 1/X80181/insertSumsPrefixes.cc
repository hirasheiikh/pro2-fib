#include "insertSumsPrefixes.hh"

void insertSumsPrefixes(list<int> &l) {
    list<int>:: iterator it = l.begin();
    int sum = 0;
    while (it != l.end()) {
        sum += *it;
        ++it;
        l.insert(it,sum);
    }
}

