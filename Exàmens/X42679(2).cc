#include <iostream>
#include <list>
using namespace std;

int main() {
    string p;
    list <pair <int, int>> l;
    pair <int, int> m (0,0);
    while (cin >> p) {
        int n;
        if (p == "max_equal_left") {
            if (not l.empty()) {
                m = *l.begin();
                cout << m.second << endl;
            }
            else cout << 0 << endl;
        }
        else if (p == "max_equal_right") {
            if (not l.empty()) {
                m = *l.rbegin();
                cout << m.second << endl;
            }
            else cout << 0 << endl;
        }
        else if (p == "push_front") {
            cin >> n;
            if (not l.empty()){
                    m = *l.begin();
                    if (n == m.first) {
                        ++m.second;
                        *l.begin() = m;
                    }
                    else {
                    m = make_pair(n,1);
                    l.push_front(m);
                }
            }
            else {
                m = make_pair(n,1);
                l.push_front(m);
            }
        }

        else if (p == "push_back") {
            cin >> n;
            if (not l.empty()){
                    m = *l.rbegin();
                    if (n == m.first) {
                        ++m.second;
                        *l.rbegin() = m;
                    }
                    else {
                    m = make_pair(n,1);
                    l.push_back(m);
                }
            }
            else {
                m = make_pair(n,1);
                l.push_back(m);
            }
        }

        else if (p == "pop_back") {
            if (not l.empty()) {
                m = *l.rbegin();
                if (m.second > 1) {
                    --m.second;
                    *l.rbegin() = m;
                }
                else if (m.second == 1) {
                    l.pop_back();
                }
            }
            else cout << "error" << endl;
        }
        else {
            if (not l.empty()) {
                m = *l.begin();
                if (m.second > 1) {
                    --m.second;
                    *l.begin() = m;
                }
                else {
                    l.pop_front();
                }
            }
            else cout << "error" << endl;
        }

    }
}
