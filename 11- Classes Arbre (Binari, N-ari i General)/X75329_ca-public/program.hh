#include "ArbIOint.hh"
#include "Arbre.hh"


  int i_freq(const node_arbre* node, const T& x) const{
    if (node == NULL) return 0;
    int count = 0;
    if (node->info == x) ++count;
    count += i_freq(node->segE, x);
    count += i_freq(node->segD, x);
    return count;
  }

 int freq(const T& x) const{
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
  return i_freq(primer_node,x);
 }