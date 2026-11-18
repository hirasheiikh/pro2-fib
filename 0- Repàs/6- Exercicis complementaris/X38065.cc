#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string,int>m1; //name numcoins
    map<int,int>m2; // numcoins,numpeople
    string instr;

    while (cin >> instr){
        if (instr == "ADD"){
            string name;
            int numcoins;
            cin >> name >> numcoins;
            m1.insert(make_pair(name,numcoins));
            ++m2[numcoins]; // sumem numpeople
        }
        else if (instr == "DELETE"){
            string name;
            cin >> name;

            map<string,int> :: iterator it = m1.find(name);
            int n = (*it).second; // n = numcoins
            m1.erase(name);
            --m2[n]; //--numpeople de la numcoin
        }
        else if (instr == "NUMPEOPLE"){
            int numcoins;
            cin >> numcoins;
            cout << m2[numcoins] << endl;
        }
    }
}