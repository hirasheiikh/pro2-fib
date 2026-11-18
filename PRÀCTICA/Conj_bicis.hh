/**
 * @file Conj_bicis.hh
 * @brief Especificació de la classe Conj_bicis
 */
#ifndef CONJ_BICIS_HH
#define CONJ_BICIS_HH

#include "Bici.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif

/**
 * @class Conj_bicis
 * @brief Conté l'informació de totes les bicis.
 */
class Conj_bicis {

private:
    map<string,Bici> conj_bicis; //mapa que conté identificadors de bicis
                                 //juntament amb els seus viatges

public:
    //Constructores
    /**
     * @brief Constructora per defecte
     * \pre cert
     * \post El resultat és el <em>Conj_bicis</em> buit 
     * \coste Constant
     */
    Conj_bicis();

    //Modificadores
    /**
     * @brief Modificadora que determina l'estació actual d'una bici
     * \pre Un identificador d'una bici ja existent.
     * \post El paràmetre implícit passa a tenir el valor de ide.
     * \coste Logarítmic
     */
    void assignar_estacio_actual(string idb, string ide);

    /**
     * @brief Modificadora que afegeix una bici del conjunt a una estació
     * \pre Si l'estació no existeix, si la bici ja hi és a
     * l'estació o si la bici no cap s'imprimeix un missatge d'error 
     * \post S'ha afegit una bici al paràmetre implícit.
     * \coste Logarítmic
     */
    void afegir_bici(string idb, string ide);
    
    /**
     * @brief Modificadora que afegeix un viatge a una bici del conjunt
     * \pre Un identificador d'una bici ja existent.
     * \post S'ha afegit un viatge al paràmetre implícit.
     * \coste Logarítmic
     */
    void nou_viatge(string ide_inicial, string ide_final, string idb);

    /**
     * @brief Modificadora que dona de baixa una bici del conjunt
     * \pre Un identificador d'una bici ja existent, si la bici no existeix imprimeix un missatge d'error.
     * \post S'ha eliminat la bici del paràmetre implícit.
     * \coste Logarítmic
     */
    void borrar_bici(string idb);

    //Consultores
    /**
     * @brief Consultora que indica si existeix una bici al conjunt
     * \pre El paràmetre implícit està inicialitzat.
     * \post El resultat indica si existeix o no la bici al conjunt.
     * \coste Logarítmic
     */
    bool existeix_bici(string idb) const;

    /**
     * @brief Consultora que indica a quina estació es troba una bici del conjunt
     * \pre El paràmetre implícit està inicialitzat.
     * \post El resultat és l'identificador de l'estació a la que es troba la bici.
     * \coste Logarítmic
     */
    string estacio_bici(string idb);

    //Lectura/escriptura
    /**
     * @brief Escriptora que diu tots els viatges fets per una bici del conjunt
     * \pre El paràmetre implícit està inicialitzat.
     * \post S'han escrit tots els viatges del paràmetre implícit al canal estàndard de sortida.
     * \coste Lineal
     */
    void escriu_viatges(string idb);

};
#endif