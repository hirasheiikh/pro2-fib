#include "Estudiant.hh"
#include <vector>
 
/* Pre: cert */
/* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
 a la decima mes propera */
 void arrodonir_vector(vector<Estudiant>& v){
     bool te = true;
     int count = 0;
    for (int i = 0; i < v.size(); ++i){
        if (v[i].te_nota) v[i].modificar_nota(int(v[i].consultar_nota()*10+0.5)/10.0);
    }
 }

// 9.55 - 9 = 0.55 -- > 9.55 + 0.05 = 9.6
// 8.46 - 8 = 0.46 --> 0.46 + 0.05 = 0.51 * 10 --> 5.1 --> int (8.46) + double (int (5.1)/10)
//851 / 
