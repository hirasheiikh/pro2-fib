#include <iostream>
#include "CuaIOParInt.hh"
using namespace std;

int main(){
    queue<ParInt> ori, c1,c2;
    llegirCuaParInt(ori);

    //CALCULAR DISTRIBUCIÓ
    int t1 = 0;
    int t2 = 0;

    while (not ori.empty()){
        if (t1 <= t2){
            //c1
            c1.push(ori.front());
            t1 += ori.front().segon();
        }
        else{
            //c2
            c2.push(ori.front());
            t2 += ori.front().segon();
        }
        ori.pop();
   }

    escriureCuaParInt(c1);
    cout << endl;
    escriureCuaParInt(c2);


}