/**
 * @file Conj_productes.hh
 * @brief Especificació de la classe Inventari
 */
#ifndef CONJ_PRODUCTES_HH
#define CONJ_PRODUCTES_HH


#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

/**
 * @class Conj_productes
 * @brief Conté l'informació de tots els productes.
 */
class Conj_productes {

private:
    struct Producte{
        int pes;
        int volum;
    };
    map<int,Producte> conj_productes; //mapa que conté el pes i el volum de cada producte, 
                              //essent la posició + 1 on es troba aquesta informació 
                              //l'ID del producte al qual li correspon.

public:
    //Constructores
    /**
     * @brief Constructora per defecte
     * \pre cert
     * \post El resultat és el <em>Conj_productes</em> buit
     * \coste Constant
     */
    Conj_productes();

    //Modificadores
    /**
     * @brief Modificadora que afegeix productes a l'inventari.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post S'ha afegit un nou producte.
     *\coste Constant
     */
    void agregar_productos();

   
    //Consultores

    /**
     * @brief Consultora que indica el nombre de productes.
     * \pre cert.
     *\post S'ha imprimit el nombre de productes.
     *\coste Lineal
     */

    int num_productes() const;

    /**
     * @brief Consultora que comprova si existeix un producte al conjunt.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'ha indicat si existeix o no el producte.
     *\coste Lineal
     */
    bool existeix_producte(int idp) const;

    void inicialitzar_conj_productes();
    
    void consultar_pes_volum(int& pes, int& volum, int idp) const;
    
    //Lectura/escriptura
    /**
     * @brief Escriptora que escriu el pes i el volum d'un producte. 
     * \pre cert
     *\post S'han escrit el pes i el volum del producte.
     *\coste Lineal
     */
    void escribir_producto(int idp) const;



};
#endif