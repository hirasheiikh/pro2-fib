/**
 * @file program.cc
 * @brief Mòdul principal de <em>Comerç fluvial</em>
 * @mainpage Pràctica de PRO2
 * Aquesta pràctica de PRO2 consisteix en realitzar un sistema 
 * d'un comerç fluvial amb les seves respectives ciutats i afluents. 
 * Cal tenir en compte factors com poden ser per exemple els viatges 
 * de la barca entre les ciutats o la capacitat de l'inventari de cada ciutat (tant la manca com l'excés de cada producte). 
 * Per portar control d'això i molt més s'han fet servir les següents classes:
 *      Ciutat,
 *      Conj_ciutats,
 *      Conj_cuenca_fluvial i
 *      Riu_Afluents.
 */

//g++ -o program.exe *.cc 
//./program.exe
#include "Conj_ciutats.hh"
//#include "Conj_productes.hh"
//#include "Vaixell.hh"
//#include "Ciutat.hh"
using namespace std;

/**
 * @brief Execució del codi principal de la pràctica
 */
int main(){
    //cout << "abans de declarar" << endl;
    Conj_ciutats ciutats;
    Vaixell vaixell;
    Conj_productes productes; 
    Conj_ciutats rio;
    //cout << "inici" << endl; // FINS AQUÍ BÉ
    productes.inicialitzar_conj_productes();
    //cout << "productes" << endl;
    ciutats.inicialitzar_ciutats();
    //cout << "ciutats" << endl;
    vaixell.inicialitzar_vaixell();
    //cout << "vaixell" << endl;
    
    string inst;
    while (cin >> inst and inst != "fi"){
        if (inst == "leer_rio" or inst == "lr"){
            cout << "#" << inst << ' ' << endl;
            ciutats.leer_rio();   // ciutats.leer_rio();   
        }
        else if (inst == "leer_inventario" or inst == "li"){
            string idc;
            cin >> idc;
            cout << "#" << inst << ' ' << idc << endl;
            if (not ciutats.existeix_ciutat(idc)) cout << "error: no existe la ciudad" << endl;
            else{
                ciutats.leer_inventario(idc,productes); // cridar a inventari
            }
        }
        else if (inst == "leer_inventarios" or inst == "ls"){
            cout << "#" << inst << endl;
            ciutats.leer_inventarios(productes);
        }
        else if (inst == "modificar_barco" or inst == "mb"){
            int idprod_comprar, unitats_comprar, idprod_vendre, unitats_vendre;
            cin >> idprod_comprar >> unitats_comprar >> idprod_vendre >> unitats_vendre;
            cout << "#" << inst << endl; //CANVIAR A TOT ARREU
            if (not productes.existeix_producte(idprod_comprar)) cout << "error: no existe el producto" << endl;
            else{
                if (not productes.existeix_producte(idprod_vendre)) cout << endl << "error: no existe el producto" << endl;
                else if (idprod_comprar == idprod_vendre) cout << "error: no se puede comprar y vender el mismo producto" << endl;
                else{
                    vaixell.modificar_barco(idprod_comprar, unitats_comprar,idprod_vendre, unitats_vendre);
                }
            }
        }
        else if (inst == "escribir_barco" or inst == "eb"){
            cout  << "#" << inst << endl;
            vaixell.escribir_barco();
        } 
        else if (inst == "consultar_num" or inst == "cn"){
            cout << "#" << inst << endl;
            cout << productes.num_productes() << endl;

        }
        else if (inst == "agregar_productos" or inst == "ap"){
            cout << "#" << inst << ' ';
            productes.agregar_productos();
        }
        else if (inst == "escribir_producto" or inst == "ep"){
            int idp;
            cin >> idp;
            cout << "#" << inst << ' ' << idp << endl;
            if (not productes.existeix_producte(idp)) cout << "error: no existe el producto" << endl;
            else productes.escribir_producto(idp);
        }
        else if (inst == "escribir_ciudad" or inst == "ec"){
            string idc;
            cin >> idc;
            cout << "#" << inst << ' ' << idc << endl;
            if (not ciutats.existeix_ciutat(idc)) cout << "error: no existe la ciudad" << endl;
            else ciutats.escribir_ciudad(idc);
        }
        else if (inst == "poner_prod" or inst == "pp"){
            string idc;
            int idp,unitats_te, unitats_necessita,pes,volum;
            cin >> idc >> idp >> unitats_te >> unitats_necessita;
            cout << "#" << inst << ' ' << idc << ' ' << idp << endl;
            if (not productes.existeix_producte(idp)) cout << "error: no existe el producto" << endl;
            else{
                if (not ciutats.existeix_ciutat(idc)) cout << "error: no existe la ciudad" << endl;
                else{
                    if (ciutats.existeix_producte_ciutat(idc,idp)) cout << "error: la ciudad ya tiene el producto" << endl; //AFEGIR AL .cc
                    else{
                        productes.consultar_pes_volum(pes, volum, idp);
                        ciutats.poner_prod(idc,idp,unitats_te, unitats_necessita, pes, volum, productes); //pes i volum
                    }
                }
            }
        }
        else if (inst == "modificar_prod" or inst == "mp"){
            string idc;
            int idp,unitats_te, unitats_necessita,pes,volum;
            cin >> idc >> idp >> unitats_te >> unitats_necessita;
            cout << "#" << inst << ' ' << idc << ' ' << idp << endl;
            if (not productes.existeix_producte(idp)) cout << "error: no existe el producto" << endl;
            else{
                if (not ciutats.existeix_ciutat(idc)) cout << "error: no existe la ciudad" << endl;
                else{
                    if (not ciutats.existeix_producte_ciutat(idc,idp)) cout << "error: la ciudad no tiene el producto" << endl; //AFEGIR AL .cc
                    else{
                        productes.consultar_pes_volum(pes, volum, idp);
                        ciutats.modificar_prod(idc,idp,unitats_te, unitats_necessita, pes, volum, productes); //pes i volum
                    }
                }
            }
        }
        else if (inst == "quitar_prod" or inst == "qp"){
            string idc;
            int idp, pes, volum;
            cin >> idc >> idp;
            cout << "#" << inst << ' ' << idc << ' ' << idp << endl;
            if (not productes.existeix_producte(idp)) cout << "error: no existe el producto" << endl;
            else{
                if (not ciutats.existeix_ciutat(idc)) cout << "error: no existe la ciudad"<< endl ;
                else{
                    if (not ciutats.existeix_producte_ciutat(idc, idp)) cout << "error: la ciudad no tiene el producto"<< endl ; //AFEGIR AL .cc
                    else{
                        productes.consultar_pes_volum(pes, volum, idp);
                        ciutats.quitar_prod(idc, idp, productes, pes, volum);
                    }
                }
            }
        }
        else if (inst == "consultar_prod" or inst == "cp"){
            string idc;
            int idp;
            cin >> idc >> idp;
            cout << "#" << inst << ' ' << idc << ' ' << idp << endl;
            if (not productes.existeix_producte(idp)) cout << "error: no existe el producto" << endl ;
            else{
                if (not ciutats.existeix_ciutat(idc)) cout << "error: no existe la ciudad"<< endl ;
                else{
                    if (not ciutats.existeix_producte_ciutat(idc,idp)) cout << "error: la ciudad no tiene el producto" << endl ; 
                    else ciutats.consultar_prod(idc,idp);
                }
            }
        }
        else if (inst == "comerciar" or inst == "co"){
            string idc1, idc2;
            cin >> idc1 >> idc2;
            cout << "#" << inst << ' ' << idc1 << ' ' << idc2 << ' ' << endl;
            if (not ciutats.existeix_ciutat(idc1)) cout << "error: no existe la ciudad" << endl;
            else{
                if (not ciutats.existeix_ciutat(idc2)) cout << "error: no existe la ciudad" << endl;
                else ciutats.comerciar(idc1, idc2, productes);
            }
        }
        else if (inst == "redistribuir" or inst == "re"){
            cout << "#" << inst << endl;
            ciutats.redistribuir(productes);
        }
        else if (inst == "hacer_viaje" or inst == "hv"){
            cout << "#" << inst << endl;
            int suma_comprat_venut = ciutats.hacer_viaje(vaixell,productes);
            cout << suma_comprat_venut << endl;
        }
        else if (inst == "//") getline(cin,inst);   
    }
    
}