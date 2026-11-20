#include <iostream>
#include "Estudiant.hh"
#include <vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<Estudiant> v(N);
	for(int i = 0; i < N; ++i){
		v[i].llegir();
	}
	vector<Estudiant> sortida;
	//CALCUL
	Estudiant e = v[0];
	for(int i = 1; i < N; ++i){
		if(e.consultar_DNI() == v[i].consultar_DNI()){
			if(v[i].te_nota()){
				if(e.te_nota()){
					if(v[i].consultar_nota() > e.consultar_nota()){
						e = v[i];
						//e.modificar_nota(v[i].consultar_nota());
					}
				}
				else {
					e = v[i];
					//e.afegir_nota(v[i].consultar_nota());
				}
			}
		}
		else{
			sortida.push_back(e);
			e = v[i];
		}
	}
	sortida.push_back(e);



	for(int i = 0; i < sortida.size(); ++i){
		sortida[i].escriure();
	}
}