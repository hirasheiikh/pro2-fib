#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> c;
    int n;
    double min,max;
    cin >> n;
    c.push(n);
    min = max = n;
    double mitjana = (min + max)/2;
    cout << "min " << min << "; " << "max " << max << "; " << "media "<< mitjana << endl;
    while (cin >> n){
        if (n >= -1000 and n <= 1000){
             c.push(n);
             if (n <= min) min = n;
             else if (n >= max) max = n;
             mitjana = (min + max)/2;
             cout << "min " << min << "; " << "max " << max << "; " << "media "<< mitjana << endl;
        }
        else if (n == -1001 and not c.empty()){
            if (min == c.front()) min = 1000;
            else if (max == c.front()) max = -1000;
            c.pop();
            queue<int> c2 = c;
            for (int i = 0; i < c.size(); ++i){
                if (c2.front() <= min) min = c2.front();
                else if (c2.front() >= max) max = c2.front();
                mitjana = (min + max)/2;
                c2.pop();
            }
            cout << "min " << min << "; " << "max " << max << "; " << "media "<< mitjana << endl;
            if (c.empty()){
                cout << 0 << endl;
                min = max = mitjana = 0;
            }
        }
        else if (n == -1001 and c.empty()){
            cout << 0 << endl;
            min = max = mitjana = 0;
        }
    
    }

}