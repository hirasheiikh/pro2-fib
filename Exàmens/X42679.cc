#include <iostream>
#include <list>
using namespace std;

int main(){
    list<pair<int,int>> l;
    string s;

    while (cin >> s){
        if (s == "push_front") {
            int n;
            cin >> n;
            if (not l.empty()){
                if (n == l.begin()->first) ++l.begin()->second;
                else l.insert(l.begin(),make_pair(n,1));
            }
            else l.insert(l.end(),make_pair(n,1));
        }
        else if (s == "push_back") {
            int n;
            cin >> n;
            if (not l.empty()){
                list<pair<int,int>>::iterator it = l.end();
                --it;
                if (n == it->first) it->second = it->second + 1;
                else l.insert(l.end(),make_pair(n,1));
            }
            else l.insert(l.end(), make_pair(n,1));
        }
        else if (s == "pop_front") {
            if (not l.empty()){
                list<pair<int,int>>::iterator it = l.begin();
                if (it->second > 1){
                    l.erase(it)->first;
                    it->second = it->second - 1;
               }
                else {
                    list<pair<int,int>>::iterator it = l.begin();
                    l.erase(it);
                    }
            }
            else cout << "error" << endl;
        }
        else if (s == "pop_back") {
            if (not l.empty()){
               list<pair<int,int>>::iterator it = l.end();
               --it;
               if (it->second > 1){
                    l.erase(it)->first;
                    it->second = it->second - 1;
               }
                else {
                    list<pair<int,int>>::iterator it = l.end();
                    --it;
                    l.erase(it);
                    }
            }
            else cout << "error" << endl;
        }
        else if (s == "max_equal_left"){
            if(not l.empty()) cout << l.begin()->second << endl;
            else cout << "0" << endl;

        }
        else if (s == "max_equal_right"){
            list<pair<int,int>>::iterator it = l.end();
            --it;
            if(not l.empty()) cout << it->second << endl;
            else cout << "0" << endl;

        }
    }

}