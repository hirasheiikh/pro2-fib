/**
 * @file Bici.hh
 * @brief Especificació de la classe Bici
 */
#ifndef BICI_HH
#define BICI_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <list>
using namespace std;
#endif

/**
 * @class Bici
 * @brief Conté la informació corresponent a cada bici i
 * els viatges que realitza.
 */
class Bici {

private:
    list<pair<string,string>> viatges; //Crea una llista buida on es guardaran els viatges de la bici.
    string est; //És l'estació de la bici

public:
    //Constructores
    /**
     * @brief Constructora per defecte
     * \pre cert
     * \post El resultat és una <em>Bici</em> buida.
     * \coste Constant
     */
    Bici();

    //Modificadores
    /**
     * @brief Modificadora que afegeix un viatge nou a la bici
     * \pre Si l'estació no existeix, si la bici no existeix
     * si la bici no hi cap o si <em>ide_inicial</em> i <em>ide_final</em> 
     * son iguals es produeix un missatge d'error pel canal estàndar de sortida
     * \post El paràmatre implícit passa a tenir un nou viatge.
     * \coste Logarítmic
     */
    void nou_viatge(string ide_inicial, string ide_final);

     /**
     * @brief Modificadora que assigna una estació a la bici
     * \pre cert
     * \post El paràmetre implícit passa a tenir el valor de ide.
     * \coste Constant
     */
    void assignar_estacio_actual(string ide);
    
    //Consultores
    /**
     * @brief Consultora de l'estació en la que es troba la bici
     * \pre cert
     * \post El resultat és l'identificador de l'estació del paràmetre implícit.
     * \coste Constant
     */
    string consultar_estacio() const;

    //Lectura/escriptura
    /**
     * @brief Escriptora que diu tots els viatges fets per la bici
     * \pre cert
     * \post S'han escrit tots els viatges del paràmetre implícit al canal estàndard de sortida.
     * \coste Lineal
     */
    void escriu_viatges();

   
};
#endif