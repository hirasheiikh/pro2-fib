void arb_sumes(Arbre<int> &asum) const
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
{
    asum.primer_node = suma(primer_node);
}

node_arbre* suma(node_arbre *node) const{
    if (node != NULL){
        node_arbre* nou = new node_arbre;
        nou->info = node->info;

        if (node->segE != NULL){
            nou->segE = suma(node->segE);
            nou->info += nou->segE->info;
        }
        if (node->segD != NULL){
            nou->segD = suma(node->segD);
            nou->info += nou->segD->info;
        }
        return nou;
    }
    return NULL;

}