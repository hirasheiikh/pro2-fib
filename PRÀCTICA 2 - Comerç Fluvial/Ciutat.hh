/**
 * @file Ciutat.hh
 * @brief Especificació de la classe Ciutat
 */
#ifndef CIUTAT_HH
#define CIUTAT_HH


#ifndef NO_DIAGRAM
#include<iostream>
#include <map>
using namespace std;
#endif

#include "Conj_productes.hh"
//#include "Vaixell.hh" //?????


/**
 * @class Ciutat
 * @brief Conté l'inventari amb els productes que hi ha a una ciutat.
 */
class Ciutat {

private:
    struct Producte_Inventari{
        int unitats_te;
        int unitats_necessita;
    };
    
    map<int,Producte_Inventari> Productes; //mapa que conté les unitats que necessita la ciutat i les que en té, 
                             //les posicions + 1 són els IDs dels productes.
    int pes_total, volum_total ; //Indiquen el pes i el volum total dels productes que conté la ciutat.

public:
   /* struct Producte_Inventari{
        int unitats_te;
        int unitats_necessita;
    };*/

    //Constructores
    /**
     * @brief Constructora per defecte
     * \pre cert
     *\post El resultat és una <em>Ciutat</em> buida.
     *\coste Constant
     */
    Ciutat();

    //Modificadores
    
    /**
     * @brief Modificadora que posa un producte de l'inventari a una ciutat.
     * \pre El paràmetre implícit ha d'estar inicialitzat
     *\post S'ha posat un nou producte a una ciutat.
     *\coste Constant
     */
    void poner_prod(int idp, int unitats_te, int unitats_necessita, int pes, int volum, const Conj_productes &conj_productes, bool escriure);

    /**
     * @brief Modificadora que canvia el pes i el volum d'un producte d'una ciutat.
     * \pre cert
     *\post S'ha modificat un producte d'una ciutat.
     *\coste Constant
     */ 
    void modificar_prod(int idp, int unitats_te, int unitats_necessita, int pes, int volum, const Conj_productes &conj_productes, bool escriure);

    /**
     * @brief Modificadora que treu un producte de l'inventari d'una ciutat.
     * \pre cert
     *\post S'ha eliminat un producte d'una ciutat.
     *\coste Constant
     */
    void quitar_prod(int idp, int pes, int volum, const Conj_productes &conj_productes, bool escriure);
    
    /**
     * @brief Modificadora que guarda els productes a l'inventari de la ciutat.
     * \pre cert
     *\post S'ha eliminat un producte d'una ciutat.
     *\coste Constant
     */
    //void inicialitzar_ciutat(Conj_productes &conj_productes, int idp, int pes, int volum, int unitats_te, int unitats_necessita);

    void comerciar(Ciutat& c2, const Conj_productes& conj_productes);
    //Consultores
    /**
     * @brief Consultora i escriptora que indica quantes unitats d'un producte vol i necessita una ciutat.
     * \pre cert
     *\post S'han imprimit les unitats.
     *\coste Lineal
     */
    void consultar_prod(int idp);

    /**
     * @brief Consultora que comprova si existeix un producte a l'inventari de la ciutat.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'ha indicat si existeix o no el producte.
     *\coste Lineal
     */
    bool existeix_producte(int idp) const;

    //Lectura/escriptura
    /**
     * @brief Lectora que indica quants productes té una ciutat i el pes i el volum de cada. 
     * \pre cert
     *\post S'han llegit els productes.
     *\coste Lineal
     */
    void leer_inventario(Conj_productes &conj_productes);

    /**
     * @brief Escriptora que indica quants productes i el seu pes i volum total 
     * \pre cert
     *\post S'han escrit els inventaris i el pes i volum totals.
     *\coste Lineal
     */
    void escribir_ciudad();
    pair<int,int> productes_a_intercanviar(int idprod_comprar, int idprod_vendre, int max_comprar, int max_vendre);
    
    //void viaje(Vaixell& v, int &max);

    pair<int,int> modificar_inventari(int idprod_v, int vaixell_compra, int vaixell_ven);
    
};
#endif