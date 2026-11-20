/**
 * @file Conj_estacions.hh
 * @brief Especificació de la classe Conj_estacions
 */
#ifndef CONJ_ESTACIONS_HH
#define CONJ_ESTACIONS_HH

#include "Estacio.hh"
#include "Conj_bicis.hh"

#ifndef NO_DIAGRAM
#include <map>
#include "BinTree.hh"
#endif

/**
 * @class Conj_estacions
 * @brief Conté totes les estacions del Bicing Bifurcat
 */
class Conj_estacions {

private:
    map<string,Estacio> conj_estacions; // string = ide, Estacio = bicis de l'estació
    BinTree<string> t; // Crea un arbre buit on es guardaran les estacions
    int lliures_totals; //Indica el nombre de places lliures totals del conjunt d'estacions.
    void inicialitzar_arbre(BinTree<string> &estacions); //Inicialitza l'arbre de les estacions
    void i_subir_bici(const BinTree<string>& a, Conj_bicis& b); //Funció immersiva que comprova si es poden pujar les bicis a estacions superiors
    void i_asignar_estacion(const BinTree<string>& t, string& ide, double& coef, int& num_est, int& pl_est); //Funció immersiva que assigna una estació del conjunt a una bici
    void subir_bicis_fills(string idpare, string ideq, string idd, Conj_bicis& b); //Funció immersiva i recursiva que puja les bicis a estacions superiors

public:

    //Constructores
    /**
     * @brief Constructora per defecte
     * \pre cert
     * \post El resultat és el <em>Conj_estacions</em> buit
     * \coste Constant
     */
    Conj_estacions();

    //Modificadores
    /**
     * @brief Modificadora que afegeix una bici a una estació
     * \pre Si l'estació no existeix, si la bici ja hi és a
     * l'estació o si la bici no cap s'imprimeix un missatge d'error
     * \post S'ha donat d'alta una bici al paràmetre implícit.
     * \coste Logarítmic
     */
    void alta_bici(string idb, string ide);

    /**
     * @brief Modificadora que dona de baixa una bici
     * \pre Si la bici no existeix imprimeix un missatge d'error
     * \post S'ha eliminat una bici del paràmetre implícit.
     * \coste Logarítmic
     */
    void eliminar_bici(string idb, string ide);

    /**
     * @brief Modificadora que mou una bici d'una estació a una altra
     * \pre Si la bici no cap a l'estació destí, si la bici o l'estació
     * no existeixen o si l'estació destí es igual a la d'origen, s'imprimeix
     * un missatge d'error.
     * \post S'ha mogut una bici des de <em>ide_inicial</em> a <em>ide_final</em>.
     * \coste Logarítmic
     */
    void moure_bici(string ide_inicial, string ide_final, string idb);

    /**
     * @brief Modificadora que canvia la capacitat d'una estació
     * \pre Si l'estació no existeix o si l'enter es un nombre
     * menor a la quantitat de bicis actuals a l'estació, imprimeix
     * un missatge d'error
     * \post S'ha modificat la capacitat d'una estació del paràmetre implícit.
     * \coste Logarítmic
     */
    void modifica_capacitat(string ide, int x);

    /**
     * @brief Modificadora que inicialitza les estacions del conjunt
     * \pre El paràmetre implícit está inicialitzat.
     * \post S'han guardat les estacions al paràmetre implícit.
     * \coste Constant
     */
    void inicialitzar_estacions();

  //Consultores
    /**
     * @brief Consultora que indica si existeix una estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post El resultat indica si l'estació <em>ide</em> existeix o no.
     * \coste Logarítmic
     */
    bool existeix_estacio(string ide) const;

    /**
     * @brief Consultora que indica si caben bicis a una estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post El resultat diu si queden places lliures a l'estació <em>ide</em>.
     * \coste Logarítmic
     */
    bool caben_bicis(string ide) const;

     /**
     * @brief Consultora que indica quines bicis té una estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post S'han escrit pel canal de sortida totes les bicis contenides a <em>ide</em>.
     * \coste Logarítmic
     */
    void bicis_estacio(string ide) const;
    
    /**
     * @brief Consultora que indica el nombre de bicis d'una estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post El resultat és el nombre de bicis de l'estació <em>ide</em>.
     * \coste Logarítmic
     */
    int nombre_bicis(string ide) const;

    /**
     * @brief Consultora que indica el nombre de places lliures total de totes les estacions
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post El resultat és el nombre de places lliures totals.
     * \coste Constant
     */
    int places_lliures_totals() const;
    
    /**
     * @brief Funció que puja bicis al conjunt d'estacions amb ajuda d'una funció immersiva.
     * \pre Els paràmetre implícit ha d'estar inicialitzat.
     * \post S'han pujat totes les bicis possibles a estacions superiors.
     * \coste Quasilineal
     */
    
    void subir_bicis(Conj_bicis& b);

    /**
     * @brief Funció que assigna estacions del conjunt a bicis amb ajuda d'una funció immersiva.
     * \pre El paràmetre implícit ha d'estar inicialitzat. 
     * Si la bici existeix o si no cap en cap estació es produeix un missatge d'error.
     * \post S'ha assignat una estació a la bici <em>idb</em>
     * \coste Quasilineal
     */
    void asignar_estacion(string idb, Conj_bicis& b);

};
#endif