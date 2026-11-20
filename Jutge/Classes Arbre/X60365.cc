bool buscar(const T& x) const
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
{
    return trobat(primer_node, x);
}

bool trobat(node_arbreGen* node, const T&x)const{
    if (node != NULL){
        if (node->info == x) return true;
        else{
            node_arbreGen* n = new node_arbreGen;
            n->info = node->info;
            int ari = node->seg.size();
            n->seg = vector<node_arbreGen*>(ari);
            for (int i = 0; i < ari; ++i) {
                if(node->seg[i]->info == x) return true;
            }
            return false;
        }
    }
    return false;
}