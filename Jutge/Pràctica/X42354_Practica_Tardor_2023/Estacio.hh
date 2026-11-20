/**
 * @file Estacio.hh
 * @brief Especificació de la classe Estacio
 */
#ifndef ESTACIO_HH
#define ESTACIO_HH

#ifndef NO_DIAGRAM
#include <set>
#endif

#include "Bici.hh"


/**
 * @class Estacio
 * @brief Conté les bicis que hi ha a una estació
 */
class Estacio {

private:
    set<string> Bicis; //IDs de las bicis
    int places_lliures_estacio, capacitat; //Indiquen el nombre de places lliures d'una estació i la seva capacitat.

public:

    //Constructores
    /**
     * @brief Constructora per defecte
     * \pre cert
     * \post El resultat és una <em>Estacio</em> buida
     * \coste Constant
     */
    Estacio();

    /**
     * @brief Constructora amb valors concrets
     * \pre cert
     * \post El resultat és una estació amb els seus paràmetres implícits inicialitzats
     * \coste Constant
     */
    Estacio(int n);

    //Modificadores
    /**
     * @brief Modificadora que afegeix una bici a una estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post S'ha afegit una bici al paràmetre implícit.
     * \coste Logarítmic
     */
    void afegir_bici(string idb);

    /**
     * @brief Modificadora que dona de baixa una bici d'una estació
     * \pre La bici <em>idb</em> ha d'existir.
     * \post S'ha eliminat una bici del paràmetre implícit.
     * \coste Logarítmic
     */
    void borrar_bici(string idb);

    /**
     * @brief Modificadora que canvia la capacitat d'una estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post S'ha modificat la capacitat de l'estació.
     * \coste Constant
     */
    void modifica_capacitat(int x);

    //Consultores
    /**
     * @brief Consultora i escriptora que indica quines bicis té una estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post S'han escrit pel canal estàndar de sortida totes les bicis de l'estació
     * \coste Lineal
     */
    void bicis_estacio() const;

    /**
     * @brief Consultora que indica si una estació està plena
     * \pre El paràmetre implícit està inicialitzat.
     * \post El resultat indica si caben més bicis a l'estació.
     * \coste Constant
     */
    bool caben_bicis() const;

    /**
     * @brief Consultora que indica el nombre de places lliures a una estació.
     * \pre El paràmetre implícit està inicialitzat.
     * \post El resultat és les places lliures de l'estació.
     * \coste Constant
     */
    int pl_estacio() const;

    /**
     * @brief Consultora que indica el nombre de bicis d'una estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post El resultat és el nombre de bicis de l'estació.
     * \coste Constant
     */
    int nombre_bicis() const;

    /**
     * @brief Consultora que indica la bici amb menor identificador de tota l'estació
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post El resultat és el menor identificador de tota l'estació
     * \coste Constant
     */
    string consultar_bici() const;
};
#endif