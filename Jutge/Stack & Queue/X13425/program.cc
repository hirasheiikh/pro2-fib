#include "CuaIOParInt.hh"

int main(){
    queue<ParInt> c;
    queue<ParInt> c1;
    queue<ParInt> c2;

    llegirCuaParInt(c);
    int t1 = 0;
    int t2 = 0;

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