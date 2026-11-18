#include "execute.hh"

bool isDigit(char c){
    return '0' <= c and c <= '9';
}
bool isNumber(string s){
    if (int(s.size()) == 0) return false;
	for (int i = 0; i < int(s.size()); ++i)
        if (not isDigit(s[i]))
            return false;
    return true;
}
bool isLowercaseLetter(char c){
    return 'a' <= c and c <= 'z';
}
bool isVariable(string s){
    if (int(s.size()) == 0) return false;
	for (int i = 0; i < int(s.size()); ++i)
        if (not isLowercaseLetter(s[i]))
            return false;
    return true;
}
int mystoi(string s){
    istringstream mycin(s);
    int x;
    mycin >> x;
    return x;
}

int evaluate(map<string,int> &var2val, BinTree<string> t){
    int valor = 0;
    if (isNumber(t.value())) valor = mystoi(t.value());
    else if (t.value() == "*") valor = (evaluate(var2val, t.left()) * evaluate(var2val,t.right()))%10;
    else if (t.value() == "+") valor = (evaluate(var2val, t.left()) + evaluate(var2val, t.right()))%10;
    if (var2val.find(t.value()) != var2val.end())  valor = var2val[t.value()];
    return valor;
}

void execute(map<string,int> &var2val, BinTree<string> t){
    if (not t.empty()) { 
    string arrel = t.value();
        if (arrel == "=") {
            var2val[t.left().value()] = evaluate (var2val, t.right());
        }
        else if (arrel == "print") {
            cout << evaluate (var2val, t.left()) << endl;
        }
        else if (arrel == "if") {
            if (evaluate (var2val, t.left()) != 0) execute (var2val, t.right());
        }
        else if (arrel == "while") {
            while (evaluate (var2val, t.left()) != 0) execute (var2val, t.right());
        }
        else if (arrel == "list") {
            execute (var2val, t.left());
            execute (var2val, t.right());
        }
        
    }
}