/**
 * @file Conj_ciutats.hh
 * @brief Especificació de la classe Conj_ciutats
 */
#ifndef CONJ_CIUTATS_HH
#define CONJ_CIUTATS_HH


#ifndef NO_DIAGRAM
#include <map>
#include "BinTree.hh"
#endif

#include "Ciutat.hh"
#include "Vaixell.hh"
#include "Conj_productes.hh"

/**
 * @class Conj_ciutats
 * @brief Conté totes les ciutats del Comerci fluvial
 */
class Conj_ciutats {
    private:
    struct Informacio_Ciutat{
        string idc;
        int compra;
        int venta;

    };
    map<string,Ciutat> conj_ciutats; // string = idc, Ciutat = productes i quantitats que es necessiten i es tenen de cada.
    BinTree<string> idcs; // Crea un arbre buit on es guardaran les ciutats.
    int buscar_ruta_max(const BinTree<string>& idcs, Vaixell& v,int& profunditat_ultima, int profunditat_actual, int comprades_actual, int venudes_actual,string& ultima_ciutat, list<Informacio_Ciutat>& cami);
    void inicialitzar_arbre(BinTree<string> &ciutats); //Inicialitza l'arbre de les ciutats
    void redistribuir_rec(const Conj_productes& conj_productes,BinTree<string>& idcs); //Funció immersiva que va desde la desembocadura del riu fins als naixements comerciant.
    void viatge(list<Informacio_Ciutat> &cami, Vaixell &v);
    public:
    //Constructores
    /**
     * @brief Constructora per defecte
     * \pre cert
     * \post El resultat és el <em>Conj_ciutats</em> buit
     * \coste Constant
     */
    Conj_ciutats();

  //Modificadores
    

    /**
     * @brief Modificadora que posa un producte de l'conj_productes a una ciutat.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'ha posat un nou producte a una ciutat.
     *\coste Constant
     */
    void poner_prod(string idc, int idp, int unitats_te, int unitats_necessita, int pes, int volum, const Conj_productes& conj_productes);

    /**
     * @brief Modificadora que canvia el pes i el volum d'un producte d'una ciutat.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'ha modificat un producte d'una ciutat.
     *\coste Constant
     */ 
    void modificar_prod(string idc, int idp, int unitats_te, int unitats_necessita, int pes, int volum, const Conj_productes& conj_productes);

    /**
     * @brief Modificadora que treu un producte de l'conj_productes d'una ciutat.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'ha eliminat un producte d'una ciutat.
     *\coste Constant
     */
    void quitar_prod(string idc, int idp, const Conj_productes& conj_productes, int pes, int volum);

    //Consultores
    /**
     * @brief Consultora i escriptora que indica quantes unitats d'un producte vol i necessita una ciutat.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'ha posat un nou producte a una ciutat.
     *\coste Lineal
     */
    void consultar_prod(string idc, int idp);


    /**
     * @brief Funció que comercia entre dues ciutats amb un mateix producte amb ajuda d'una funció immersiva.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post S'han canviat les unitats a comprar i vendre d'ambdues ciutats.
     * \coste Quasilineal
     */
    void comerciar(string idc1, string idc2, const Conj_productes& conj_productes);

    /**
     * @brief Funció que fa que la ciutat de la desembocadura negocii amb les ciutats riu adalt a mà dreta i esquerra successivament.
     * \pre Els paràmetre implícit ha d'estar inicialitzat.
     * \post S'han canviat les unitats a comprar i vendre de totes les ciutats amb les quals s'ha negociat.
     * \coste Quasilineal
     */
    void redistribuir(const Conj_productes& conj_productes);


    /**
     * @brief Modificadora que comprova quina és la millor ruta per fer el viatge.
     * \pre Els paràmetres implícits han d'estar inicialitzats.
     * \post S'ha escollit la millor ruta.
     * \coste 
     */
    int hacer_viaje(Vaixell& v, const Conj_productes& conj_productes);

     /**
     * @brief Modificadora que inicialitza les ciutats del conjunt
     * \pre cert
     * \post S'han guardat les ciutats al paràmetre implícit.
     * \coste Constant
     */

    void inicialitzar_ciutats();

    /**
     * @brief Modificadora que afegeix ciutats al conjunt.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     * \post S'ha afegit una nova ciutat.
     *\coste Constant
     */
    void afegir_ciutat(string idc);

    /**
     * @brief Modificadora que treu una ciutats del conjunt.
     * \pre cert
     *\post S'ha eliminat una ciutat del conjunt.
     *\coste Constant
     */
    void borrar_ciutat(string idc);

    /**
     * @brief Consultora que comprova si existeix ciutat al conjunt.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'ha indicat si existeix o no la ciutat.
     *\coste Lineal
     */
    bool existeix_ciutat(string idc) const;

    /**
     * @brief Consultora que comprova si existeix un producte a l'conj_productes de la ciutat.
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'ha indicat si existeix o no el producte.
     *\coste Lineal
     */
    bool existeix_producte_ciutat(string idc, int idp) const;

    //Lectura/escriptura
    /**
     * @brief Lectora que indica quants productes té una ciutat i el pes i el volum de cada. 
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'han llegit els productes.
     *\coste Lineal
     */
    void leer_inventario(string idc,Conj_productes &conj_productes);
    
    /**
     * @brief Lectora que indica quants productes tenen totes les ciutats del conjunt. 
     * \pre cert
     *\post S'han llegit els conj_productess.
     *\coste Lineal
     */
    void leer_inventarios(Conj_productes &conj_productes);

     /**
     * @brief Lectora que indica l'estructura de la cuenca. 
     * \pre el paràmetre implícit ha d'estar inicialitzat.
     *\post S'han llegit les ciutats de la cuenca.
     *\coste Lineal
     */
    void leer_rio();

    /**
     * @brief Escriptora que indica quants productes i el seu pes i volum total 
     * \pre El paràmetre implícit ha d'estar inicialitzat.
     *\post S'han escrit els conj_productess i el pes i volum totals.
     *\coste Lineal
     */
    void escribir_ciudad(string idc);
    


 
};
#endif