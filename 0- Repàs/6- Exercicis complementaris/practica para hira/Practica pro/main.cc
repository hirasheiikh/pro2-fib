#include "Funciones.hh"



int main() {
    map<int,caracteristicas> m;
    agregar_productos(m);
    BinTree<string> rio;
    map<string,Ciudad> cities;
    rio = leer_rio(cities);
    Barco barco = Barco();
    int idc, idv, cc, cv;
    cin >> idc >> idv >> cc >> cv;
    barco.modificar_barco(idc,idv,cc,cv);
    string instruccion;
    cin >> instruccion;
    while (instruccion != "fin") {
        if (instruccion == "leer_rio" or instruccion == "lr"){ //1
            cities= map<string,Ciudad>();
            rio = leer_rio(cities);
        }
        if (instruccion == "leer_inventario" or instruccion == "li") { //2
            string idciudad;
            cin >> idciudad;
            if (not existeciudad(idciudad, cities)) cout << "error: no existe la ciudad" << endl;
            else {
                cities[idciudad].leer_inventario(m); 
            }
        }
        if (instruccion == "leer_inventarios" or instruccion == "ls") { //3
            string id;
            cin >> id;
            while (id != "#") {
                if (not existeciudad(id, cities)) cout << "error: no existe la ciudad" << endl;
                else {
                    cities[id].leer_inventario(m);
                }
            cin >> id;
            }
        }
        if (instruccion == "modificar_barco" or instruccion == "mb") { //4
            int idc, idv, cc, cv;
            cin >> idc >> cc >> idv >> cv;
            if (not existe_producto(m,idc) or not existe_producto(m,idv))  cout << "error: no existe el producto" << endl;
            else if (idc == idv) cout << "error: no se puede comprar y vender el mismo producto" << endl;
            else barco.modificar_barco(idc,idv,cc,cv);         
        }
        if (instruccion == "escribir_barco" or instruccion == "eb") { //5
            barco.escribir_barco();
        }
        if (instruccion == "consultar_num" or instruccion == "cn") { //6
            cout << m.size() << endl;
        }
        if (instruccion == "agregar_productos" or instruccion == "ap") { //7
            agregar_productos(m);
        }
        if (instruccion == "escribir_producto" or instruccion == "ep") { //8
            int id;
            cin >> id;
            escribir_porducto(m, id);
        }
        if (instruccion == "escribir_ciudad" or instruccion == "ec") { //9
            string id;
            cin >> id;
            if (not existeciudad(id, cities)) cout << "error: no existe la ciudad" << endl;
                else cities[id].escribir_ciudad();
        }
        if (instruccion == "poner_prod" or instruccion == "pp") { //10
            string id;
            cin >> id;
            int idproducto, unidq, unidt;
            cin >> idproducto >> unidt >> unidq;
            if (not existe_producto( m, idproducto)) cout << "error: no existe el producto" << endl;
            else if (not existeciudad(id,cities)) cout << "error: no existe la ciudad" << endl;
            else cities[id].poner_prod(idproducto, unidq, unidt,m, true);
                

        }
        if (instruccion == "modificar_prod" or instruccion == "mp") { //11
            string id;
            cin >> id;
            int idproducto, unidq, unidt;
            cin >> idproducto >> unidt >> unidq;
            if (not existe_producto( m, idproducto)) cout << "error: no existe el producto" << endl;
            else if (not existeciudad(id,cities)) cout << "error: no existe la ciudad" << endl;
            else cities[id].modificar_prod(idproducto, unidq, unidt,m, true);
        }
        if (instruccion == "quitar_prod" or instruccion == "qp") { //12
            string id;
            cin >> id;
            int idproducto;
            cin >> idproducto;
            if (not existe_producto( m, idproducto)) cout << "error: no existe el producto" << endl;
            else if (not existeciudad(id,cities)) cout << "error: no existe la ciudad" << endl;
            else cities[id].quitar_prod(idproducto,m);
        }
        if (instruccion == "consultar_prod" or instruccion == "cp") { //13
            string id;
            cin >> id;
            int idproducto;
            cin >> idproducto;
            if (not existe_producto( m, idproducto)) cout << "error: no existe el producto" << endl;
            else if (not existeciudad(id,cities)) cout << "error: no existe la ciudad" << endl;
            else  cities[id].consultar_prod(idproducto);
        }
        if (instruccion == "comerciar" or instruccion == "co") { //14
            string id1, id2;
            cin >> id1 >> id2;
            if(not existeciudad(id1, cities) or not existeciudad(id2,cities)) cout << "error: no existe la ciudad" << endl;
            comerciar(id1,id2,cities,m);
        }
        if (instruccion == "redistribuir" or instruccion == "re") { //15
            redistribuir(cities,m,rio);
        }
        if (instruccion == "hacer_viaje" or instruccion == "hv") { //16
            hacer_viaje(cities,rio,barco);
        }
        cin >> instruccion;
    }

}