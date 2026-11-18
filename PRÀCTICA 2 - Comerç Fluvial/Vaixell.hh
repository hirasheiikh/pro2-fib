/**
 * @file Vaixell.hh
 * @brief Especificació de la classe Vaixell
 */
#ifndef VAIXELL_HH
#define VAIXELL_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
using namespace std;
#endif

/**
 * @class Vaixell
 * @brief Conté la informació corresponent dels productes a comprar i vendre crea la ruta que farà el vaixell.
 */
class Vaixell {

private:
    int idprod_comprar;
    int unitats_comprar;
    int idprod_vendre;
    int unitats_vendre;
    list<string> ruta;

public:
    //Constructores
    /**
     * @brief Constructora per defecte
     * \pre cert
     *\post El resultat és el <em>Vaixell</em> buit
     *\coste Constant
     */
    Vaixell(); 
    
    /**
     * @brief Constructora per defecte
     * \pre cert
     *\post El resultat és el <em>Ruta</em> buida
     *\coste Constant
     */
    void afegir_viaje(string ultima_ciutat);
    
    //Lectura/escriptura
    /**
     * @brief Lectora que garantitza que les unitats del producte a vendre i del producte a comprar no son negatives i una és >0.
     * \pre cert
     *\post El resultat és el <em>Vaixell</em> buit
     *\coste Constant
     */
    void modificar_barco(int idprod_c, int unitats_c,int idprod_v, int unitats_v);
    /**
     * @brief Modificadora que prepara el vaixell amb els productes a comprar i  vendre.
     * \pre cert
     *\post S'ha inicialitzat el vaixell.
     *\coste Constant
     */
    void inicialitzar_vaixell();


    /**
     * @brief Escriptora
     * \pre cert
     *\post Escriu els ID's dels productes a comprar i vendre, les seves unitats i l'última ciutat visitada
            dels viatges fets pel vaixell en ordre cronològic.
     *\coste Constant
     */
    void escribir_barco();


    int consultar_quantitat_comprar();

    int consultar_quantitat_vendre();

    int consultar_idp_comprar();

    int consultar_idp_vendre();

};
#endif