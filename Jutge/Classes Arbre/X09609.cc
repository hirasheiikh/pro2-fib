void sub_arrel(Arbre& asub, const T& x)
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */

{
    int dist_min = -1;
    subarbre(asub,primer_node,x,0,dist_min);
}

void subarbre(Arbre& asub, node_arbre *node, const T& x, int dist, int&dist_min){
    if (node != NULL){
        ++dist;
        if (node->info == x and (dist_min == -1 or dist<dist_min)){
            dist_min = dist;
            asub.primer_node = copia_node_arbre(node);
        }
        subarbre(asub,node->segE,x,dist,dist_min);
        subarbre(asub,node->segD,x,dist,dist_min);
    }

}