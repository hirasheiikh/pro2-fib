/**
 * @file program.cc
 * @brief Mòdul principal de <em>Bicing Bifurcado</em>
 * @mainpage Pràctica de PRO2
 * Aquesta pràctica de PRO2 consisteix en realitzar un sistema 
 * de Bicing Bifurcat amb les seves corresponents estacions i bicis. 
 * Cal tenir en compte factors com poden ser per exemple els viatges 
 * de les bicis o la capacitat de les estacions. Per portar control d'això i 
 * molt més s'han fet servir les següents classes:
 *      Bici,
 *      Conj_bicis,
 *      Conj_estacions i
 *      Estacio.
 */
#include "Conj_bicis.hh"
#include "Estacio.hh"
#include "Conj_estacions.hh"
using namespace std;

/**
 * @brief Execució del codi principal de la pràctica
 */
int main () {
    Conj_estacions estacions;
    Conj_bicis b;
    estacions.inicialitzar_estacions();
    string inst;

    while (cin >> inst and inst != "fi") {
        string idb, ide;
        if (inst == "alta_bici" or inst == "ab") {
            cin >> idb >> ide;
            cout << "#ab " << idb << ' ' << ide << endl; 
    
            if (b.existeix_bici(idb)) cout << "error: la bici ya existe" << endl;
            else if (not estacions.existeix_estacio(ide)) cout << "error: la estacion no existe" << endl;
            else if (not estacions.caben_bicis(ide)) cout << "error: la bici no cabe" << endl;
            else {
                b.afegir_bici(idb,ide);
                estacions.alta_bici(idb,ide);
            }
        }

        else if (inst == "baja_bici" or inst == "bb") {
            cin >> idb;
            cout << "#bb " << idb << endl;
            if (not b.existeix_bici(idb)) cout << "error: la bici no existe" << endl;
            else {
                estacions.eliminar_bici(idb, b.estacio_bici(idb));
                b.borrar_bici(idb);
            }
        }

        else if (inst == "estacion_bici" or inst == "eb") {
            cin >> idb;
            cout << "#eb " << idb << endl;
            if (not b.existeix_bici(idb)) cout << "error: la bici no existe" << endl;
            else cout << b.estacio_bici(idb) << endl;
        }

        else if (inst == "viajes_bici" or inst == "vb") {
            cin >> idb;
            cout << "#vb " << idb << endl;
            if (not b.existeix_bici(idb)) cout << "error: la bici no existe" << endl;
            else b.escriu_viatges(idb);
        }

        else if (inst == "mover_bici" or inst == "mb") {
            cin >> idb >> ide;
            cout << "#mb " << idb << ' ' << ide << endl;
            if (not estacions.existeix_estacio(ide)) cout << "error: la estacion no existe" << endl;
            else if (not b.existeix_bici(idb)) cout << "error: la bici no existe" << endl;
            else if (b.estacio_bici(idb) == ide) cout << "error: la bici ya esta en el sitio" << endl;
            else if (not estacions.caben_bicis(ide)) cout << "error: la bici no cabe" << endl;
            else {
                estacions.moure_bici(b.estacio_bici(idb),ide,idb);
                b.nou_viatge(b.estacio_bici(idb),ide,idb);
            }
        }

        else if (inst == "bicis_estacion" or inst == "be") {
            cin >> ide;
            cout << "#be " << ide << endl;
            if (not estacions.existeix_estacio(ide)) cout << "error: la estacion no existe" << endl;
            else estacions.bicis_estacio(ide);
        }

        else if (inst == "modificar_capacidad" or inst == "mc") {
            cin >> ide;
            int x;
            cin >> x;
            cout << "#mc " << ide << " " << x << endl;
            if (not estacions.existeix_estacio(ide)) cout << "error: la estacion no existe" << endl;
            else if (estacions.nombre_bicis(ide) > x) cout << "error: capacidad insuficiente" << endl;
            else estacions.modifica_capacitat(ide,x);
        }

        else if (inst == "plazas_libres" or inst == "pl") {
            cout << "#pl" << endl;
            cout << estacions.places_lliures_totals() << endl;
        }

        else if (inst == "subir_bicis" or inst == "sb") {
            cout << "#sb" << endl;
            estacions.subir_bicis(b);
        }

        else if (inst == "asignar_estacion" or inst == "ae") {
            cin >> idb;
            cout << "#ae " << idb << endl;
            if (b.existeix_bici(idb)) cout << "error: la bici ya existe" << endl;
            else if (estacions.places_lliures_totals() == 0) cout << "error: no hay plazas libres" << endl;
            else {
                estacions.asignar_estacion(idb,b);
                cout << b.estacio_bici(idb) << endl;
            }
        }
    }
}