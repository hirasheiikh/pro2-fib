static T suma_aux(const node_arbre* node){
    T sumaE = 0;
    T sumaD = 0;
    if (node == NULL) return 0;
    else{
        sumaE = node->info;
        sumaD = node->info;
        sumaE += suma_aux(node->segE);
        sumaD += suma_aux(node->segD);
        if (sumaD < sumaE) return sumaE;
        else return sumaD;

    }

}

T max_suma_cami() const {
/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
    return suma_aux(primer_node);
}