#include <iostream>
#include <queue>
using namespace std;

void min_max (queue<int> c, int &max, int &min){
    min = max = c.front();
    c.pop();
    while (not c.empty()){
        if (c.front() < min) min = c.front();
        else if (c.front() > max) max = c.front();
        c.pop();
    }
}

int main(){
    queue<int> c;
    int n, max, min;
    double suma = 0;
    cin >> n;
    min = max = n;
    while (n >= -1001 and n <= 1000){
        if (n != -1001){
            if (n < min) min = n;
            if (n > max) max = n;
            suma += n;
            c.push(n);
        }
        else if (not c.empty()){
            int num_previ = c.front();
            suma -= num_previ;
            c.pop();
            if (!c.empty() and (min == num_previ or max == num_previ)) min_max(c, max, min);
        }
        if (c.empty()){
            min = 1001; // per quan fem c.push(n) n sigui sempre < que el min
            max = -1001; // el mateix pero amb el max
            suma = 0;
            cout << 0;
        }
        else cout << "min " << min << "; max " << max << "; media " << suma/c.size();
        cout << endl;
        cin >> n;
    }

}