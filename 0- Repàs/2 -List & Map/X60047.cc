#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    string s;
    int n;
    list<int> l;
    while (cin >> s){
        if (s == "push_front"){
            cin >> n;
            l.insert(l.begin(),n);
        }
        else if (s == "push_back"){
            cin >> n;
            l.insert(l.end(),n);
        }
        else if (s == "pop_front"){
            list<int>::const_iterator it = l.begin();
            if (not l.empty()) l.erase(it);
            else cout << "error" << endl;
        }
        else if (s == "pop_back"){
            list<int>::const_iterator it  = l.end();
            --it;
            if (not l.empty()) l.erase(it);
            else cout << "error" << endl;
        }
        else if (s == "get_mid_value") {
            if (l.size()%2 == 0) cout << "error" << endl;
            else{
                list<int>:iterator it = l.begin();
                int i = 0;
                while (i < l.size()/2){
                    ++it;
                    ++i;
                }
                cout << *it << endl;
            }
        }
    }

}