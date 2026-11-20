T max_suma_cami() const
/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */
{
    return suma_aux(primer_node);
}

T suma_aux(node_arbre *node) const{
    //if (node != NULL){
        T sumaE = node->info;
        T sumaD = node->info;
        if (node->segE != NULL) sumaE+= suma_aux(node->segE);
        if (node->segD != NULL) sumaD+= suma_aux(node->segD);
        if (sumaE > sumaD) return sumaE;
        else return sumaD;
    //}
    //return 0;
}
