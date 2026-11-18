#include "BinTree.hh"
#include "utils.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors binaris +,-,*,/.
//       Les operacions no produeixen errors d'overflow,
//       però poden produïr error de divisió per 0.
// Post: Si l'avaluació de l'expressió representada per t no produeix errors de divisió per 0, 
//       llavors 'result' val l'avaluació d'aquesta expressió i 'error' val 'false'.
//       En cas contrari, 'error' val 'true', i el valor de 'result' és irrellevant.
void evaluate(BinTree<string> t, int &result, bool &error) {
    if (isNumber(t.value())) {
        result = mystoi(t.value());
        error = false;
    }
    else {
        int result_esq = 0;
        evaluate(t.left(),result_esq,error);
        if (not error) {
            int result_dret = 0;
            evaluate(t.right(),result_dret,error);

            if (t.value() == "-") result = result_esq-result_dret;
            else if (t.value() == "+") result = result_esq+result_dret;
            else if (t.value() == "*") result = result_esq*result_dret;
            else if (t.value() == "/" and result_right != 0) result = result_esq/result_dret;
            else error = true;
        }
    }
}