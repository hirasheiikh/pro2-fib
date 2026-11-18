#include "removeAll.hh"


BT removeAll(const string &extension, const BT &t){
    BT left, right;
    if (not t.empty()){
        if (t.right().empty() and t.left().empty()){
            if(t.value().substr(t.value().size()-extension.size()) == extension) return BT();
        }
        else{
            if (not t.left().empty()) left = removeAll(extension, t.left());
            if (not t.right().empty()) right = removeAll(extension, t.right());
        }
    }
    return BT(t.value(), left,right);
}