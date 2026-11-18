#include "mergeIntoFirstList.hh"


void mergeIntoFirstList(list<int> &l1, list<int> l2){
    list<int>:: iterator it = l1.begin();
    list<int>:: const_iterator it2 = l2.begin();
    while (it != l1.end() and it2 != l2.end()){
        if (*it >= *it2){
            l1.insert(it, *it2);
            if (*it == *it2) ++it;
            ++it2;
        }
        else ++it;
    }
    while (it2 != l2.end()){
        l1.insert(it, *it2);
        ++it2;
    }
}
