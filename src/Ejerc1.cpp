#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Estudiante {
private:
    string cedula, nombre, carrera;
    float promedio;
public:
    Estudiante(string c, string n, string ca, float p)
        : cedula(c), nombre(n), carrera(ca), promedio(p) {}

    void guardar() {
        ofstream archivo("estudiantes.txt", ios::app);
        if (archivo.is_open()) {
            archivo << cedula << "," << nombre << ","
                    << carrera << "," << promedio << "\n";
            archivo.close();
            cout << "Estudiante registrado correctamente.\n";
        } else {
            cout << "Error al abrir el archivo.\n";
        }
    }
};

int main() {
    string cedula, nombre, carrera;
    float promedio;
    cout << "Cedula: ";   cin >> cedula;
    cin.ignore();
    cout << "Nombre: ";   getline(cin, nombre);
    cout << "Carrera: ";  getline(cin, carrera);
    cout << "Promedio: "; cin >> promedio;
    Estudiante est(cedula, nombre, carrera, promedio);
    est.guardar();
    return 0;
}