#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Agenda {
public:
    void agregar(string nombre, string tel, string correo) {
        ofstream f("agenda.txt", ios::app);
        if (f.is_open()) { f << nombre << "," << tel << "," << correo << "\n"; f.close(); }
        cout << "Contacto agregado.\n";
    }
    void buscar(string busq) {
        ifstream f("agenda.txt"); string linea; bool ok = false;
        while (getline(f, linea)) {
            stringstream ss(linea); string n, t, c;
            getline(ss,n,','); getline(ss,t,','); getline(ss,c,',');
            if (n == busq) { cout << n << " | " << t << " | " << c << "\n"; ok = true; }
        }
        if (!ok) cout << "Contacto no encontrado.\n";
    }
    void mostrarTodos() {
        ifstream f("agenda.txt"); string l;
        cout << "--- Contactos ---\n";
        while (getline(f, l)) cout << l << "\n";
    }
};

int main() {
    Agenda ag; int op;
    do {
        cout << "\n1-Agregar 2-Buscar 3-Mostrar 4-Salir: "; cin >> op; cin.ignore();
        if (op==1) { string n,t,c;
            cout<<"Nombre: "; getline(cin,n); cout<<"Telefono: "; getline(cin,t); cout<<"Correo: "; getline(cin,c);
            ag.agregar(n,t,c);
        } else if (op==2) { string b; cout<<"Buscar: "; getline(cin,b); ag.buscar(b); }
        else if (op==3) ag.mostrarTodos();
    } while (op!=4);
    return 0;
}