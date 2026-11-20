#include <vector>
#include "Estudiant.hh"
using namespace std;

double arrodonir(double nota){
	return int(nota*10+ 0.5) / 10.0;
}

void arrodonir_vector(vector<Estudiant>& v){
	for(int i = 0; i < v.size(); ++i){
		if(v[i].te_nota()){
			double arr = arrodonir(v[i].consultar_nota());
			v[i].modificar_nota(arr);
		}
	}
}