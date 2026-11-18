#include "Producto.hh"


    bool  existe_producto(map<int,caracteristicas>& m, int id) {
        map<int,caracteristicas>::iterator it = m.begin();
        it = m.find(id);
        return (it != m.end());
    }

    void agregar_productos(map<int,caracteristicas>& m) {
        int n;
        cin >> n;
        int num;
        if (m.empty()) num = 1;
        else { 
        map<int,caracteristicas>::iterator it = m.end();
        --it;
        num = (it->first) + 1;
        }
        
        for (int i = 0; i < n; ++i) {
            caracteristicas c;
            cin >> c.peso >> c.volumen;
            m.insert(make_pair(num, c));
            ++num;
        }
        
    }
    void  escribir_porducto(map<int,caracteristicas>& m,int id) {
        if (not existe_producto(m,id)) cout << "error: no existe el producto" << endl;
        else {
            cout << id << ' ' <<m[id].peso << ' ' << m[id].volumen << endl; 
        }
    }
    
