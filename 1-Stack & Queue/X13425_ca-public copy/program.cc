#include "CuaIOParInt.hh"

int main(){
    queue<ParInt> c;
    queue<ParInt> c1;
    queue<ParInt> c2;
    int t1, t2;
    t1 = t2 = 0;
    llegirCuaParInt(c);
    
    while (not c.empty()){
        if (t1 <= t2){
            c1.push(c.front());
            t1 += c.front().segon();
        }
        else{
            c2.push(c.front());
            t2 += c.front().segon();
        }
        c.pop();
    }
    escriureCuaParInt(c1);
    cout << endl;
    escriureCuaParInt(c2);
}