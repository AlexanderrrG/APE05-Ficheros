#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class LectorEstudiantes {
public:
    void leerArchivo() {
        ifstream archivo("estudiantes.txt");
        if (!archivo.is_open()) { cout << "No se puede abrir el archivo.\n"; return; }
        string linea; int contador = 0; float suma = 0;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string cedula, nombre, carrera, prom;
            getline(ss, cedula, ','); getline(ss, nombre, ',');
            getline(ss, carrera, ','); getline(ss, prom, ',');
            cout << cedula << " | " << nombre << " | " << carrera << " | " << prom << "\n";
            suma += stof(prom); contador++;
        }
        archivo.close();
        cout << "\nTotal: " << contador << "\n";
        if (contador > 0) cout << "Promedio general: " << suma / contador << "\n";
    }
};

int main() { LectorEstudiantes l; l.leerArchivo(); return 0; }