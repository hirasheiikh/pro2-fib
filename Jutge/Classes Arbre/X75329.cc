int freq(const T& x) const
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
{
    return i_freq(primer_node,x);
}

int i_freq (node_arbre *node, const T& x) const{
    int count = 0;
    if (node != NULL){
        if (node->info == x) ++count;
        count += i_freq(node->segE,x);
        count += i_freq(node->segD,x);
    }
    return count;
}