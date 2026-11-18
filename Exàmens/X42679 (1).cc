#include <iostream>
#include <list>
#include <string>
using namespace std;

int max_equal_left(list<int>& l) {
    if (!l.empty()) {
        list<int>::iterator it = l.begin();
        list<int>::iterator it2 = l.begin();
        int c = 1;
        ++it2;
        int x = *it; //x = list[0]
        int y = *it2; //y = list[1]
        while (x == y) 
        {
            ++c;
            ++it2;
            y = *it2;
        }
        return c;
    }
    else
        return 0;
}

int max_equal_right(list<int>& l) {
    if (!l.empty())
    {
        list<int>::iterator it = l.end();
        list<int>::iterator it2 = l.end();
        int c = 1;
        --it;
        --it2;
        --it2;
        int x = *it; //x = list[l.end-1]
        int y = *it2; //y = list[l.end-2]
        while (x == y) 
        {
            ++c; //
            --it2;
            y = *it2; //y = list[1]     
        }
        return c;
    }
    else
        return 0;
    
}

int main() {
    list<int> l;
    string s;
    int x;
    while (cin >> s){
        if (s == "pop_front"){
            if (l.empty()) cout << "error" << endl;
            else l.erase(l.begin());
        }
        else if (s == "pop_back"){
            if (!l.empty()) { // Només si la llista no està buida, eliminem l'element posterior
                list<int>::iterator t = l.end();
                --t;
                l.erase(t);
            }
        }
        else if (s == "push_front"){
            cin >> x;
            l.insert(l.begin(),x);
        }
        else if (s == "push_back"){
            cin >> x;
            l.insert(l.end(), x);
        }
        else if (s == "max_equal_left") cout << max_equal_left(l) << endl;
        else cout << max_equal_right(l) << endl;
    }
}