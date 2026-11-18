#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    map<string,set<string>> alumnes;
    map<string,set<string>> assignatures;
    string comanda, nom_alumne, nom_assignatura;
    while(cin >> comanda){
        if(comanda == "ENROLL"){
            cin >> nom_alumne >> nom_assignatura;
            
            map<string,set<string>>::iterator ita = alumnes.find(nom_alumne);
            if(ita != alumnes.end()){ //l'alumne ja està matriculat a alguna assig (ja el tenim al map alumnes)
                (*ita).second.insert(nom_assignatura);
            }
            else{ //l'alumne no esta
                set<string> assigs;
                assigs.insert(nom_assignatura);
                alumnes.insert(make_pair(nom_alumne,assigs));
            }
            //alumnes[nom_alumne].insert(nom_assignatura);
            
            map<string,set<string>>::iterator itass = assignatures.find(nom_assignatura);
            if(itass != assignatures.end()){ //l'assignatura ja està
                (*itass).second.insert(nom_alumne);
            }
            else{ //l'alumne no esta
                set<string> salumnes;
                salumnes.insert(nom_alumne);
                assignatures.insert(make_pair(nom_assignatura,salumnes));
            }
            //assignatures[nom_assignatura].insert(nom_alumne);
            
        }
        else if(comanda == "QUIT"){
            cin >> nom_alumne >> nom_assignatura;
            map<string,set<string>>::iterator ita = alumnes.find(nom_alumne);
            //set<string>::iterator its_assig = (*ita).second.find(nom_assignatura);
            (*ita).second.erase(nom_assignatura);

            map<string,set<string>>::iterator itass = assignatures.find(nom_assignatura);
            (*itass).second.erase(nom_alumne);
            
        }
        else if(comanda == "SUBJECTSOFSTUDENT"){
            cin >> nom_alumne;
            map<string,set<string>>::const_iterator ita = alumnes.find(nom_alumne);
            if(ita != alumnes.end()){
                set<string>::const_iterator its = (*ita).second.begin();
                while(its != (*ita).second.end()){
                    if(its != (*ita).second.begin()) cout << " ";
                    cout << *its;
                    ++its;
                }
            }
            cout << endl;
        }
        else if(comanda == "STUDENTSOFSUBJECT"){
            cin >> nom_assignatura;
            map<string,set<string>>::const_iterator itass = assignatures.find(nom_assignatura);
            if(itass != assignatures.end()){
                set<string>::const_iterator its = (*itass).second.begin();
                while(its != (*itass).second.end()){
                    if(its != (*itass).second.begin()) cout << " ";
                    cout << *its;
                    ++its;
                }

            }
            cout << endl;
            
        }
    }
}