void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
    asum.primer_node = suma(primer_node);
}

node_arbreNari* suma(node_arbreNari* node) const{
    if (node != NULL){
        node_arbreNari *nou = new node_arbreNari;
        nou->info = node->info;
        int ari = node->seg.size();
        nou->seg = vector<node_arbreNari*>(ari);
        for (int i = 0; i < ari; ++i){
            if (node->seg[i] != NULL){
                nou->seg[i] = suma(node->seg[i]);
                nou->info += nou->seg[i]->info;
            }
        }
        return nou;
    }
    return NULL;

}