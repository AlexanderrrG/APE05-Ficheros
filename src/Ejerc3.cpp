#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Producto {
private:
    string codigo, nombre; int cantidad; float precio;
public:
    Producto(string co, string n, int ca, float p)
        : codigo(co), nombre(n), cantidad(ca), precio(p) {}

    void guardar() {
        float valor = cantidad * precio;
        ofstream f("inventario.txt", ios::app);
        if (f.is_open()) {
            f << codigo << "," << nombre << "," << cantidad << "," << precio << "," << valor << "\n";
            f.close();
            cout << "Guardado. Valor del producto: $" << valor << "\n";
        }
    }

    void calcularValorTotal() {
        ifstream f("inventario.txt");
        string linea; float total = 0;
        while (getline(f, linea)) {
            stringstream ss(linea); string campo; int i = 0;
            while (getline(ss, campo, ',')) { if (i == 4) total += stof(campo); i++; }
        }
        cout << "Valor total inventario: $" << total << "\n";
    }
};

int main() {
    string codigo, nombre; int cantidad; float precio;
    cout << "Codigo: "; cin >> codigo; cin.ignore();
    cout << "Nombre: "; getline(cin, nombre);
    cout << "Cantidad: "; cin >> cantidad;
    cout << "Precio: "; cin >> precio;
    Producto p(codigo, nombre, cantidad, precio);
    p.guardar(); p.calcularValorTotal();
    return 0;
}